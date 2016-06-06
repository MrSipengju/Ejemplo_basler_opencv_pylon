#include "baslercamera.h"
#include <pylon/PylonIncludes.h>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"


using namespace cv;
using namespace Pylon;
using namespace std;


void baslerCamera::init(void)
{
    // Automagically call PylonInitialize and PylonTerminate to ensure
        // the pylon runtime system is initialized during the lifetime of this object.
        Pylon::PylonAutoInitTerm autoInitTerm;


        CGrabResultPtr ptrGrabResult;
        //int exitCode = 0;

        cout << "Using device " << camera.GetDeviceInfo().GetModelName() << endl;
        camera.Open();
        GenApi::CIntegerPtr width(camera.GetNodeMap().GetNode("Width"));
        GenApi::CIntegerPtr height(camera.GetNodeMap().GetNode("Height"));
        Mat cv_img(width->GetValue(), height->GetValue(), CV_8UC3);

        camera.StartGrabbing();

}

Mat baslerCamera::takePicture(void)
{

            CPylonImage image;
            CImageFormatConverter fc;
            fc.OutputPixelFormat = PixelType_RGB8packed;


                camera.RetrieveResult( 5000, ptrGrabResult, TimeoutHandling_ThrowException);
                if (ptrGrabResult->GrabSucceeded())
                {
                        fc.Convert(image, ptrGrabResult);
                        cv_img = cv::Mat(ptrGrabResult->GetHeight(),     ptrGrabResult->GetWidth(), CV_8UC3,(uint8_t*)image.GetBuffer());
                        cvtColor(cv_img,cv_img,CV_RGB2BGR);
                        return cv_img;
                        //imshow("CV_Image",cv_img);
                        //waitKey(1);
                }




        // Comment the following two lines to disable waiting on exit
        cerr << endl << "Press Enter to exit." << endl;
        while( cin.get() != '\n');
}
