// HelloOpenCVInCmake.h: 标准系统包含文件的包含文件
// 或项目特定的包含文件。

#pragma once

#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
class CascadeDetectorAdapter : public DetectionBasedTracker::IDetector
{
public:
	CascadeDetectorAdapter(cv::Ptr<cv::CascadeClassifier> detector) :
		IDetector(),
		Detector(detector) {

		CV_Assert(detector);
	}

	void detect(const cv::Mat& Image, std::vector<cv::Rect>& objects)
	{

		Detector->detectMultiScale(Image, objects, scaleFactor, minNeighbours, 0, minObjSize, maxObjSize);

	}

	virtual ~CascadeDetectorAdapter()
	{

	}

private:
	CascadeDetectorAdapter();
	cv::Ptr<cv::CascadeClassifier> Detector;
};


// TODO: 在此处引用程序需要的其他标头。
