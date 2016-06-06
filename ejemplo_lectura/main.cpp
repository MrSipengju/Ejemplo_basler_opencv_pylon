
#include <pylon/PylonIncludes.h>
#include "baslercamera.h"

using namespace cv;
using namespace Pylon;
using namespace std;

int main(int argc, char* argv[]) {
    namedWindow("Imagen",WINDOW_AUTOSIZE);

    baslerCamera camara;
    camara.Exposure(2.0);
    camara.Saturation(2.0);	
	camara.init();
	
    while(true) {
		Mat img=camara.takePicture();
		if(img.rows != 0){
			imshow("Imagen", img);
		}
	}
}
