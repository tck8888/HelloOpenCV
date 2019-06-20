// HelloOpenCVInCmake.cpp: 定义应用程序的入口点。
//

#include "HelloOpenCVInCmake.h"
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;
int main()
{
	//分类器
	CascadeClassifier classifiter;
	//加载模型
	if(!classifiter.load("D:/Program Files (x86)/opencv/OpenCV-android-sdk/sdk/etc/lbpcascades/lbpcascade_frontalface.xml")){
	return -1;
	}

	VideoCapture capture(0);
	Mat img;
	Mat gray;
	while (1)
	{
		capture >> img;
		//img的颜色空间是BGR
		//灰度图
		cvtColor(img, gray, COLOR_BGR2GRAY);
		//增强对比度（直方图均衡）
		imshow("摄像头1", gray);
		equalizeHist(gray, gray);
		std::vector<Rect> faces;
		//定位人脸
		classifiter.detectMultiScale(gray, faces);
		for (auto face: faces)
		{
			//画矩形
			rectangle(img, face, Scalar(255, 0, 255));
		}
		imshow("摄像头2", gray);
		waitKey(10);
	}
	return 0;
}
