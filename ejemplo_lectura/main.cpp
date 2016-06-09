
#include <pylon/PylonIncludes.h>
#include "baslercamera.h"

using namespace cv;
using namespace Pylon;
using namespace std;

int main(int argc, char* argv[]) {
    argc; argv;
    namedWindow("Imagen",WINDOW_AUTOSIZE);

    baslerCamera camara;
    camara.init();
    camara.exposure(15000.0);
    camara.saturation(2.0);

	
    while(true) {
        Mat img;
        if(camara.takePicture(img)){
            imshow("Imagen", img);
            waitKey(3);
        }
	}
}
