#ifndef BASLERCAMERA_H
#define BASLERCAMERA_H

#include <opencv2/opencv.hpp>
#include <pylon/PylonIncludes.h>

class baslerCamera {
	public:
        void init();
        void exposure(double _exposure);
        void saturation(double _saturation);
        bool takePicture(cv::Mat &_frame);

	private:
        Pylon::CInstantCamera *mCamera;
};

#endif // BASLERCAMERA_H
