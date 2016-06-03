#ifndef BASLERCAMERA_H
#define BASLERCAMERA_H
#include "opencv2/opencv.hpp"

class baslerCamera
{
public:
    void Exposure(double _exposure);
    void Saturation(double _saturation);
    cv::Mat takePicture(void);
private:
    //sdkBaslerCamera mBaslerCamera;
};

#endif // BASLERCAMERA_H
