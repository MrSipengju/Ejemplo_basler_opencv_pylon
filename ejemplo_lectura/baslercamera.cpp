#include "baslercamera.h"
#include <pylon/PylonIncludes.h>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <pylon/usb/BaslerUsbInstantCamera.h>



typedef Pylon::CBaslerUsbInstantCamera Camera_t;

using namespace cv;
using namespace Pylon;
using namespace std;

//---------------------------------------------------------------------------------------------------------------------
void baslerCamera::init() {
    // Before using any pylon methods, the pylon runtime must be initialized.
    PylonInitialize();

    // Automagically call PylonInitialize and PylonTerminate to ensure
	// the pylon runtime system is initialized during the lifetime of this object.

    mCamera = new Camera_t(CTlFactory::GetInstance().CreateFirstDevice());

    Pylon::PylonAutoInitTerm autoInitTerm;
    mCamera->Open();
    mCamera->StartGrabbing();
    cout << "Using device " << mCamera->GetDeviceInfo().GetModelName() << endl;

}

//---------------------------------------------------------------------------------------------------------------------
void baslerCamera::exposure(double _exposure) {
    mCamera->ExposureAuto.SetValue(ExposureAuto_Off);
    mCamera->GainAuto.SetValue(GainAuto_Continuous);
    mCamera->ExposureTime.SetValue(_exposure);

}

//---------------------------------------------------------------------------------------------------------------------
void baslerCamera::saturation(double _saturation) {
    //mCamera->BslSaturationValue.SetValue(_saturation);
}

//---------------------------------------------------------------------------------------------------------------------
bool baslerCamera::takePicture(cv::Mat &_frame) {
	CGrabResultPtr ptrGrabResult;

	// Pylon image holder.
	CPylonImage image;
	CImageFormatConverter fc;
	fc.OutputPixelFormat = PixelType_RGB8packed;

	Mat cv_img;
	
	// Try to take a picture
    //std::cout << "Trying to tale a picture" << std::endl;
    mCamera->RetrieveResult( 5000, ptrGrabResult, TimeoutHandling_ThrowException);
	if (ptrGrabResult->GrabSucceeded())	{	// If frame taken.
        //std::cout << "Took picture" << std::endl;
		fc.Convert(image, ptrGrabResult);
		cv_img = cv::Mat(ptrGrabResult->GetHeight(),     ptrGrabResult->GetWidth(), CV_8UC3,(uint8_t*)image.GetBuffer());
        cvtColor(cv_img,_frame,CV_RGB2BGR);
        return true;
    }else{
        return false;
    }
}
