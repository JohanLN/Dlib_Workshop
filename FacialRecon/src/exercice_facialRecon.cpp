#include <dlib/dnn.h>
#include <dlib/gui_widgets.h>
#include <dlib/clustering.h>
#include <dlib/string.h>
#include <dlib/image_io.h>
#include <dlib/image_processing/frontal_face_detector.h>
#include <dlib/image_processing/render_face_detections.h>
#include <fstream>
#include <iostream>

using namespace dlib;
using namespace std;

/* ICI ON RETROUVE TOUT UN GROUPE DE TEMPLATE QUI VONT PERMETTRE DE DESERIALISER LE MODEL DE RECONNAISSANCE FACIALE POUR POUVOIR L'UTILISER */

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

/* SAVEFACE FUNCTION SAVE THE FACE_DESCRIPTION OF THE SUBJECT  */

void saveFace(std::vector<matrix<float,0,1>> face_descriptors) {

	/* pour enregistrer les visages on va simplement ecrire leur face descriptor dans un fichier */
	
}

/* DETECTFACE FUNCTION MAKES THE DETECTION FROM THE SAVED SUBJECT  */

void detectFace(std::vector<matrix<float,0,1>> face_descriptors, matrix<rgb_pixel> &img, std::vector<rectangle> face) {

	/* detection des visages le point fort du projet */

}

/* MAIN FUNCTION  */

int main(int argc, char** argv) try
{
	/* message d'erreur si les paramêtres ne sont pas suffisant */
    if (argc != 3)
    {
        std::cout << "Il vous manque une image a donner en paramètre par exemple : ./facialRecon --save ../faces/../faces/philippe.loctaux.jpg pour sauvegarder un visage ou \n ./facialRecon --detect ../faces/bald_guys.jpg pour lancer la detection à partir du visage sauvegardé" << std::endl;
        return 84;
    }

    std::cout << "Press enter to continue !" << std::endl;
    cin.get();
}
catch (std::exception& e)
{
    cout << e.what() << endl;
}
