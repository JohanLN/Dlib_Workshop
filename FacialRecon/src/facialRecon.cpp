#include <dlib/dnn.h>
#include <dlib/gui_widgets.h>
#include <dlib/clustering.h>
#include <dlib/string.h>
#include <dlib/image_io.h>
#include <dlib/image_processing/frontal_face_detector.h>
#include <fstream>
#include <iostream>

#include <dlib/opencv.h>
#include <opencv2/highgui/highgui.hpp>
#include <dlib/image_processing/render_face_detections.h>
#include <dlib/image_processing.h>
#include <dlib/gui_widgets.h>

using namespace dlib;
using namespace std;

template <template <int,template<typename>class,int,typename> class block, int N, template<typename>class BN, typename SUBNET>
using residual = add_prev1<block<N,BN,1,tag1<SUBNET>>>;

template <template <int,template<typename>class,int,typename> class block, int N, template<typename>class BN, typename SUBNET>
using residual_down = add_prev2<avg_pool<2,2,2,2,skip1<tag2<block<N,BN,2,tag1<SUBNET>>>>>>;

template <int N, template <typename> class BN, int stride, typename SUBNET> 
using block  = BN<con<N,3,3,1,1,relu<BN<con<N,3,3,stride,stride,SUBNET>>>>>;

template <int N, typename SUBNET> using ares      = relu<residual<block,N,affine,SUBNET>>;
template <int N, typename SUBNET> using ares_down = relu<residual_down<block,N,affine,SUBNET>>;

template <typename SUBNET> using alevel0 = ares_down<256,SUBNET>;
template <typename SUBNET> using alevel1 = ares<256,ares<256,ares_down<256,SUBNET>>>;
template <typename SUBNET> using alevel2 = ares<128,ares<128,ares_down<128,SUBNET>>>;
template <typename SUBNET> using alevel3 = ares<64,ares<64,ares<64,ares_down<64,SUBNET>>>>;
template <typename SUBNET> using alevel4 = ares<32,ares<32,ares<32,SUBNET>>>;

using anet_type = loss_metric<fc_no_bias<128,avg_pool_everything<
                            alevel0<
                            alevel1<
                            alevel2<
                            alevel3<
                            alevel4<
                            max_pool<3,3,2,2,relu<affine<con<32,7,7,2,2,
                            input_rgb_image_sized<150>
                            >>>>>>>>>>>>;

void saveFace(char *subject) {
    std::cout << subject << std::endl;
    frontal_face_detector detector = get_frontal_face_detector();
    shape_predictor sp;
    deserialize("Ressources/shape_predictor_68_face_landmarks.dat") >> sp;
    anet_type net;
    deserialize("Ressources/dlib_face_recognition_resnet_model_v1.dat") >> net;

    matrix<rgb_pixel> img;
    load_image(img, subject);

    std::vector<matrix<rgb_pixel>> faces;

    std::vector<rectangle> face;
    for (int count = 0; count < detector(img).size(); count++)
    {
        face = detector(img);
        auto shape = sp(img, face[count]);
        matrix<rgb_pixel> face_chip;
        extract_image_chip(img, get_face_chip_details(shape,150,0.25), face_chip);
        faces.push_back(move(face_chip));
    }

    if (faces.size() == 0)
    {
        cout << "Aucun visage humain sur cette photo" << endl;
        exit(84);
    }

    std::vector<matrix<float,0,1>> face_descriptors = net(faces);

    ofstream myfile;
    myfile.open("Ressources/test.txt");
    for (int i = 0; i < face_descriptors[0].size(); i++) {
        myfile << face_descriptors[0](i) << "\n";
    }
    myfile.close();
    std::cout << "face_descriptor saved in file test.txt" << std::endl;
}

matrix<float,0,1> getFace() {
    matrix<float,0,1> datas;
    datas.set_size(128);
    string line;
    ifstream myfile;
    myfile.open("Ressources/test.txt");
    float num;
    int count = 0;
    while (myfile) {
        myfile >> num;
        datas(count) = num;
        count++;
    }
    return datas;
}

void webcamView(std::string target) {

    float acuracy;

    frontal_face_detector detector = get_frontal_face_detector();
    shape_predictor sp;
    deserialize("Ressources/shape_predictor_68_face_landmarks.dat") >> sp;
    anet_type net;
    deserialize("Ressources/dlib_face_recognition_resnet_model_v1.dat") >> net;

    matrix<float,0,1> datas = getFace();

	cv::VideoCapture cap(0);
	if (!cap.isOpened())
        {
            cerr << "Impossible d'ouvrir la caméra" << endl;
            exit (84);
        }
    image_window win;

    int test = 20;
    int nb_faces = 0;
    std::vector<matrix<float,0,1>> face_descriptors;

    while(!win.is_closed())
    {
        cv::Mat temp;
        if (!cap.read(temp))
        {
            break;
        }
        cv_image<bgr_pixel> cimg(temp);

        std::vector<rectangle> face = detector(cimg);
        std::vector<matrix<rgb_pixel>> faces;
        std::vector<full_object_detection> shapes;
       for (unsigned long i = 0; i < face.size(); ++i) {
            auto shape = sp(cimg, face[i]);
            matrix<rgb_pixel> face_chip;
            extract_image_chip(cimg, get_face_chip_details(shape,150,0.25), face_chip);
            faces.push_back(move(face_chip));
            win.add_overlay(image_window::overlay_rect(face[i], rgb_pixel(255,0,0)));
        }

        if (test == 20 || (face.size() != 0 && face.size() != nb_faces)) {
            face_descriptors = net(faces);
            test = 0;
        }
    
        win.clear_overlay();
        win.set_image(cimg);

        if (face.size() != 0) { 
            for (size_t j = 0; j < face_descriptors.size(); ++j)
            {
                if ((acuracy = 1 - length(datas-face_descriptors[j])) > 0.4) {
                    win.clear_overlay();
                    win.set_image(cimg);
                    win.add_overlay(image_window::overlay_rect(face[j], rgb_pixel(255,0,0), target));
                }
                else {
                    win.clear_overlay();
                    win.set_image(cimg);
                    win.add_overlay(image_window::overlay_rect(face[j], rgb_pixel(255,0,0), "Not recognize"));
                }
                std::cout << "\nThe face of the subject correspond at " << (acuracy*100) << "\n" << std::endl;
            }
        }
        std::cout << test << std::endl;
        test++;
        nb_faces = face.size();
    }
}

int main(int argc, char** argv)
{
    std::string target;

    if (argc > 1) {
        if (strcmp(argv[1],"--save") == 0)
            saveFace(argv[2]);
    }
    std::cout << "Enter the name of the target : " << std::endl;
    std::cin >> target;
    webcamView(target);
}