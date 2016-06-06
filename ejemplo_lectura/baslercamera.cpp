#include "baslercamera.h"
#include <pylon/PylonIncludes.h>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;
using namespace Pylon;
using namespace std;

//---------------------------------------------------------------------------------------------------------------------
void baslerCamera::init() {
    // Automagically call PylonInitialize and PylonTerminate to ensure
	// the pylon runtime system is initialized during the lifetime of this object.
	Pylon::PylonAutoInitTerm autoInitTerm;
	mCamera.Open();
	mCamera.StartGrabbing();
	cout << "Using device " << mCamera.GetDeviceInfo().GetModelName() << endl;

}

//---------------------------------------------------------------------------------------------------------------------
void baslerCamera::exposure(double _exposure) {
 
}

//---------------------------------------------------------------------------------------------------------------------
void baslerCamera::saturation(double _exposure) {
 
}

//---------------------------------------------------------------------------------------------------------------------
Mat baslerCamera::takePicture() {
	CGrabResultPtr ptrGrabResult;

	// Pylon image holder.
	CPylonImage image;
	CImageFormatConverter fc;
	fc.OutputPixelFormat = PixelType_RGB8packed;
	
	// Get image size
	GenApi::CIntegerPtr width(mCamera.GetNodeMap().GetNode("Width"));
	GenApi::CIntegerPtr height(mCamera.GetNodeMap().GetNode("Height"));
	
	Mat cv_img;
	
	// Try to take a picture
	mCamera.RetrieveResult( 5000, ptrGrabResult, TimeoutHandling_ThrowException);
	if (ptrGrabResult->GrabSucceeded())	{	// If frame taken.
		fc.Convert(image, ptrGrabResult);
		cv_img = cv::Mat(ptrGrabResult->GetHeight(),     ptrGrabResult->GetWidth(), CV_8UC3,(uint8_t*)image.GetBuffer());
		cvtColor(cv_img,cv_img,CV_RGB2BGR);
	}
	
	return cv_img;
}
