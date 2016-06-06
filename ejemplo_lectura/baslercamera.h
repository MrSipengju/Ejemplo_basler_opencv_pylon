#ifndef BASLERCAMERA_H
#define BASLERCAMERA_H
#include "opencv2/opencv.hpp"
#include <pylon/PylonIncludes.h>

class baslerCamera
{
public:
    void Exposure(double _exposure);
    void Saturation(double _saturation);
    cv::Mat takePicture(void);
    Pylon::CInstantCamera camera();
    void init(void);


private:

};

#endif // BASLERCAMERA_H
