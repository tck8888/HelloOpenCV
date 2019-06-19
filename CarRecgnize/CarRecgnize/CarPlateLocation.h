#ifndef CarPlateLocation_H
#define CarPlateLocation_H
#include <opencv2/opencv.hpp>
#include <vector>
using namespace cv;

class CarPlateLocation
{
public:
	CarPlateLocation();
	~CarPlateLocation();

	//1、要定位的图片 2、引用类型 作为定位结果
	void location(Mat src, Mat& dst);
private:
	//int verifySizes(RotatedRect rotatedRect);
	//void tortuosity(Mat src, vector<RotatedRect>& rects, vector<Mat>& dst_plates);
	//void safeRect(Mat src, RotatedRect rect, Rect2f& dst_rect);
	//void rotation(Mat src, Mat& dst, Size rect_size, Point2f center, double angle);
};

#endif // !CarPlateRecgnize_H
