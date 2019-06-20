// HelloOpenCVInCmake.cpp: 定义应用程序的入口点。
//

#include "HelloOpenCVInCmake.h"

#define LBP 
/**
 * 原始lbp：应该是3x3的src（先不管3x3）
 * src: 原图
 * dst: 计算出的lbp图谱
 *
*/
void processLBP(Mat src, Mat& dst) {
	// 循环处理图像数据
	for (int i = 1; i < src.rows - 1; i++) {
		for (int j = 1; j < src.cols - 1; j++) {
			uchar lbp = 0;
			//原图的像素(灰度值)
			uchar center = src.at<uchar>(i, j);
			//取出对应 高、宽位置的像素 与 中心点位置进行比较
			//src.at<uchar>(i - 1, j - 1) 取出位置的灰度值
			//左上角  
			if (src.at<uchar>(i - 1, j - 1) > center) { lbp += 1 << 7; }
			//当前的上面一个
			if (src.at<uchar>(i - 1, j) > center) { lbp += 1 << 6; }
			//右上角
			if (src.at<uchar>(i - 1, j + 1) > center) { lbp += 1 << 5; }
			if (src.at<uchar>(i, j + 1) > center) { lbp += 1 << 4; }
			if (src.at<uchar>(i + 1, j + 1) > center) { lbp += 1 << 3; }
			if (src.at<uchar>(i + 1, j) > center) { lbp += 1 << 2; }
			if (src.at<uchar>(i + 1, j - 1) > center) { lbp += 1 << 1; }
			if (src.at<uchar>(i, j - 1) > center) { lbp += 1 << 0; }
			dst.at<uchar>(i - 1, j - 1) = lbp;
		}
	}
}

int main()
{
<<<<<<< HEAD
	//分类器
	CascadeClassifier classifiter;
	//加载模型
	if(!classifiter.load("D:/Program Files (x86)/opencv/OpenCV-android-sdk/sdk/etc/lbpcascades/lbpcascade_frontalface.xml")){
	return -1;
	}
=======
#ifdef LBP
	//读取一张图片
	Mat img = imread("C:/Users/tck88/Desktop/微信图片_20190617235511.png");
	cv::cvtColor(img, img, COLOR_BGR2GRAY);
	imshow("src", img);
	//计算lbp图谱 高(行)、宽(列)
	Mat lbp = Mat(img.rows - 2, img.cols - 2, CV_8UC1);
	processLBP(img, lbp);
	imshow("lbp", lbp);
	waitKey();
	return 0;
#else

	/**
	*   显示摄像头的图像
	*/
	//智能指针
	Ptr<CascadeClassifier> classifier = makePtr<CascadeClassifier>("D:/Program Files (x86)/opencv/OpenCV-android-sdk/sdk/etc/lbpcascades/lbpcascade_frontalface.xml");
	//创建一个跟踪适配器
	Ptr<CascadeDetectorAdapter> mainDetector = makePtr<CascadeDetectorAdapter>(classifier);

	Ptr<CascadeClassifier> classifier1 = makePtr<CascadeClassifier>("D:/Program Files (x86)/opencv/OpenCV-android-sdk/sdk/etc/lbpcascades/lbpcascade_frontalface.xml");
	//创建一个跟踪适配器
	Ptr<CascadeDetectorAdapter> trackingDetector = makePtr<CascadeDetectorAdapter>(classifier1);

	//拿去用的跟踪器
	DetectionBasedTracker::Parameters DetectorParams;
	Ptr<DetectionBasedTracker> tracker = makePtr<DetectionBasedTracker>(mainDetector, trackingDetector, DetectorParams);
	//开启跟踪器
	tracker->run();
>>>>>>> 126a5829e0de2fbc8c7366d1b4e98870691517e6

	VideoCapture capture(0);
	Mat img;
	Mat gray;
	while (1)
	{
		capture >> img;
<<<<<<< HEAD
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
=======
		// img的 颜色空间是 BGR，不像现在，早期的计算机中主流是bgr，而不是rgb
		cvtColor(img, gray, COLOR_BGR2GRAY);
		//增强对比度 (直方图均衡)
		equalizeHist(gray, gray);
		std::vector<Rect> faces;
		//定位人脸 N个
		tracker->process(gray);
		tracker->getObjects(faces);

		for (Rect face : faces) {
			//画矩形
			//分别指定 bgra
			rectangle(img, face, Scalar(255, 0, 255));
		}
		imshow("摄像头", img);
		//延迟10ms 如果10s内你没有输入 空格 
		waitKey(30);
>>>>>>> 126a5829e0de2fbc8c7366d1b4e98870691517e6
	}

	tracker->stop();
	return 0;
#endif
}
