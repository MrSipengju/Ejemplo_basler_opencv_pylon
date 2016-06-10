#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <pylon/PylonIncludes.h>
#include "baslercamera.h"


#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>

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
    //Mat imag;
    //camara.takePicture(imag);
    ///stringstream a;
    //const string video_basler("video.mp4");

    //cv::VideoWriter gVideoWriter;
    //gVideoWriter.open(video_basler,CV_FOURCC('M','J','P','G'),20,imag.size(),true);
    ///int counter = 0;
    while(true) {
        Mat img;
        if(camara.takePicture(img)){
            imshow("Imagen", img);
            ///counter++;
            ///a<<"img_"<<counter<<".jpg";
            ///std::string name = "img_" + boost::to_string(counter++) + ".jpg";
            ///cv::imwrite(a.str(),img);
            waitKey(3);
            //gVideoWriter << img;
        }
	}

}
