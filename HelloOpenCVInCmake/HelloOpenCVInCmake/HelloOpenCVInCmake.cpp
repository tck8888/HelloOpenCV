// HelloOpenCVInCmake.cpp: 定义应用程序的入口点。
//

#include "HelloOpenCVInCmake.h"
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;
int main()
{
	VideoCapture capture(0);
	Mat img;
	while (1)
	{
		capture >> img;
		imshow("摄像头", img);
		waitKey(10);
	}
	return 0;
}
