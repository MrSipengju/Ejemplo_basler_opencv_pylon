#ifndef BASLERCAMERA_H
#define BASLERCAMERA_H

#include <opencv2/opencv.hpp>
#include <pylon/PylonIncludes.h>
#include <pylon/usb/BaslerUsbInstantCamera.h>

typedef Pylon::CBaslerUsbInstantCamera Camera_t;
using namespace Basler_UsbCameraParams;
typedef Camera_t::GrabResultPtr_t GrabResultPtr_t;

class baslerCamera {
	public:
        void init();
        void exposure(double _exposure);
        void saturation(double _saturation);
        bool takePicture(cv::Mat &_frame);

	private:
        Camera_t *mCamera;
};

#endif // BASLERCAMERA_H
