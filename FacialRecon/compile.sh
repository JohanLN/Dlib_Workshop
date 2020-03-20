DIR="build/"

if [ ! -d  "$DIR" ]; then
    mkdir build/
fi
cd build/ && cmake .. && cmake --build . --config Release && cd ../

mv build/facialRecon ./
