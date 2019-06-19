#include "CarPlateLocation.h"

CarPlateLocation::CarPlateLocation() {

}

CarPlateLocation::~CarPlateLocation() {

}

void CarPlateLocation::location(Mat mat, Mat& dst) {
	////预处理 ：去噪 让车牌区域更加突出
	Mat blur;
	//1、高斯模糊（平滑） （1、为了后续操作 2、降噪 ）
	GaussianBlur(src, blur, Size(5, 5), 0);
}