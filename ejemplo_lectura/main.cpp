// Grab.cpp
/*
Note: Before getting started, Basler recommends reading the Programmer's Guide topic
in the pylon C++ API documentation that gets installed with pylon.
If you are upgrading to a higher major version of pylon, Basler also
strongly recommends reading the Migration topic in the pylon C++ API documentation.

This sample illustrates how to grab and process images using the CInstantCamera class.
The images are grabbed and processed asynchronously, i.e.,
while the application is processing a buffer, the acquisition of the next buffer is done
in parallel.

The CInstantCamera class uses a pool of buffers to retrieve image data
from the camera device. Once a buffer is filled and ready,
the buffer can be retrieved from the camera object for processing. The buffer
and additional image data are collected in a grab result. The grab result is
held by a smart pointer after retrieval. The buffer is automatically reused
when explicitly released or when the smart pointer object is destroyed.
*/

#include <pylon/PylonIncludes.h>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include "baslercamera.h"

using namespace cv;
using namespace Pylon;
using namespace std;

// Number of images to be grabbed.
//static const uint32_t c_countOfImagesToGrab = 100;

int main(int argc, char* argv[])
{
    Mat img;
    namedWindow("Imagen",WINDOW_AUTOSIZE);

    baslerCamera camara;
    camara.Exposure(2.0);
    camara.Saturation(2.0);
    img=camara.takePicture();


    while(camera.IsGrabbing())
    {
        camara.init();
    }
}
