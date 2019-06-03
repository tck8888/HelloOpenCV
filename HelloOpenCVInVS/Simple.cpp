//下载opencv  https://github.com/opencv/opencv/releases
//opencv-x.x.x-android-sdk.zip opencv-x.x.x-vc14_vc15.exe
//安转opencv-x.x.x-vc14_vc15.exe
//windows配置opencv的环境变量 D:\Program Files (x86)\opencv\opencv\build\x64\vc14\bin
//vs配置为运行为x64
//vs配置包含目录   调试-->xxx属性-->VC++目录-->包含目录		D:\Program Files (x86)\opencv\opencv\build\include
//vs配置库目录	调试-->xxx属性-->VC++目录-->库目录	D:\Program Files (x86)\opencv\opencv\build\x64\vc14\lib
//vs配置链接器	调试-->xxx属性-->链接器-->输入-->添加-->附加依赖项  添加opencv_world346d.lib 位置在D:\Program Files (x86)\opencv\opencv\build\x64\vc14\lib

#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

void test() {
	//  imread 读取一张图片  Mat(图片)  
	Mat src = imread("C:/Users/tck/Downloads/desk_002.jpg");
	//Mat dst;
	//bitmap默认的是RGB mat默认BGR
	//cvtColor(src, dst, COLOR_BGR2GRAY);
	//写入文件
	//imwrite("C:/Users/tck/Downloads/gray.png", dst);
	// 显示图片
	//imshow("test pic", dst);

	//宽cols 高rows 颜色通道channels   3 一个像素点 3颜色通道，包含三个信息  BGR        
	printf("%d,%d,%d", src.rows, src.cols, src.channels());
	//彩色转灰度 ，每个像素点 B G R  的值相等 ， F = 0.11R + 0.59G + 0.30B
	for (int i = 0; i < src.rows; i++) {
		// 怎么拿像素 Bitmap 矩阵，Java Bitmap 像素，JNI底层操作像素指针 原理对每一个像素点进行处理
			// src.ptr<u32>(i);
			// 8 16 32
			// 读取当前行的首地址（指针）
		uchar* start_pixels = src.ptr<uchar>(i);

		for (int j = 0; j < src.cols; j++) {
			uchar b = start_pixels[0];
			uchar g = start_pixels[1];
			uchar r = start_pixels[2];

			// 公式计算 f =  0.11R + 0.59G + 0.30B   gery 最大255 ，其他处理可能会超过 255
			 /*uchar gery = 0.11f*r + 0.59f*g + 0.30f*b;
			 start_pixels[0] = gery;
			 start_pixels[1] = gery;
			 start_pixels[2] = gery;*/

			 /*//底片效果
			 start_pixels[0] = 255-b;
			 start_pixels[1] = 255 - g;
			 start_pixels[2] = 255 - r;*/

			 /*// 0-255  ， 大于 255 就变成 255 ，如果小于 0 就变成 0
			 start_pixels[0] = saturate_cast<uchar>(1.2f * b);
			 start_pixels[1] = saturate_cast<uchar>(1.2f * g);
			 start_pixels[2] = saturate_cast<uchar>(1.2f * r);*/

			 //黑白
			uchar b_w = (b + g + r) / 3 > 125 ? 255 : 0;
			start_pixels[0] = saturate_cast<uchar>(b_w);
			start_pixels[1] = saturate_cast<uchar>(b_w);
			start_pixels[2] = saturate_cast<uchar>(b_w);



			start_pixels += 3;
		}
	}
	imwrite("C:/Users/tck/Downloads/test2.jpg", src);
	imshow("test pic", src);

	// Android 滤镜 ，矩阵 Bitmap 

	waitKey(0);
}

int test2() {
	//  imread 读取一张图片  Mat(图片)  
	Mat src = imread("C:/Users/tck/Downloads/desk_002.jpg");
	/*//判断文件是否读取正确
	if (src.empty()) {
		return -1;
	}*/

	//头指针
	if (!src.data) {//src.data==NULL
		return -1;
	}

	int cols = src.cols;
	int rows = src.rows;
	int channels = src.channels();
	//创建 rows 高 cols
	//CV_8UC1 一个颜色通道（0-255）
	//CV_8UC2 二个颜色通道 16位 RGB565
	//CV_8UC3 三个颜色通道 24位
	//CV_8UC4 四个颜色通道 32位 RGB8888
	//匹配Bitmap 颜色通道  RGB565  RGB8888

	//Scalar 指定颜色
	//第一个为高度 第二个为宽度
	//Mat mat(10, 10, CV_8UC1,Scalar(200));

	//Size 第一个为宽度 第二个为高度
	//Mat mat(Size(10,10), CV_8UC1, Scalar(200));

	//Mat test(Size(8, 8), CV_8UC3, Scalar(255,66,255));//BGR
	//拷贝构造函数 不会拷贝内容
	//Mat mat(src);
	//Mat mat =src;
	Mat mat;
	//会去copy内容
	//src.copyTo(mat);
	mat = src.clone();
	//cout << mat << endl;

	cout << cols << "," << rows << "," << channels;

	imshow("mat", mat);
	waitKey(0);
	return 0;
}

int test3() {
	//  imread 读取一张图片  Mat(图片)  
	Mat src = imread("C:/Users/tck/Downloads/desk_002.jpg");

	//区域截取（不涉及及创建新的内容）
	Mat srcROI = src(Rect(20, 20, 500, 500));

	//不改变原图
	Mat dstROI = srcROI.clone();


	int rows = dstROI.rows;
	int cols = dstROI.cols;
	//内联函数
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			//获取像素 at Vec3b个参数
			int b = dstROI.at<Vec3b>(i, j)[0];
			int g = dstROI.at<Vec3b>(i, j)[1];
			int r = dstROI.at<Vec3b>(i, j)[2];

			//修改像素(底片效果)
			dstROI.at<Vec3b>(i, j)[0] = 255 - b;
			dstROI.at<Vec3b>(i, j)[1] = 255 - g;
			dstROI.at<Vec3b>(i, j)[2] = 255 - r;
		}
	}

	imshow("src", src);
	waitKey(0);
	return 0;
}

int test4() {
	//  imread 读取一张图片  Mat(图片)  
	Mat src = imread("C:/Users/tck/Downloads/desk_002.jpg");

	Mat gray;
	cvtColor(src, gray, COLOR_BGR2GRAY);
	int cols = gray.cols;
	int rows = gray.rows;
	int channels = gray.channels();
	cout << cols << "," << rows << "," << channels;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (channels == 3) {
				//获取像素 at Vec3b个参数
				int b = gray.at<Vec3b>(i, j)[0];
				int g = gray.at<Vec3b>(i, j)[1];
				int r = gray.at<Vec3b>(i, j)[2];

				//修改像素(底片效果)
				gray.at<Vec3b>(i, j)[0] = 255 - b;
				gray.at<Vec3b>(i, j)[1] = 255 - g;
				gray.at<Vec3b>(i, j)[2] = 255 - r;
			}
			else if (channels == 1) {
				uchar b = gray.at<uchar>(i, j);
				gray.at<uchar>(i, j) = 255 - b;
			}

		}
	}

	imshow("gray", gray);
	waitKey(0);
	return 0;
}
//图片的合成
int test5() {
	//  imread 读取一张图片  Mat(图片)  
	Mat src = imread("C:/Users/tck/Downloads/desk_002.jpg");
	Mat logo = imread("C:/Users/tck/Downloads/yys_download_url_2.png");

	//两张图片大小要一致
	Mat dst;
	//非常生硬，像素点直接相加
	//add(src, logo, dst);
	//dst(x) = saturate_cast(src(x)*alpha+logo(x)*beta+gamma)
	//addWeighted(src,0.5,logo,0.5,0.0,dst);

	Mat srcROI = src(Rect(0, 0, logo.cols, logo.rows));
	//并不适合加水印，只适合图片混合
	addWeighted(srcROI, 0.8, logo, 0.8, 0.0, srcROI);

	imshow("src", src);
	waitKey(0);
	return 0;
}
//饱和度 亮度 对比度
int test7() {
	//  imread 读取一张图片  Mat(图片)  
	Mat src = imread("C:/Users/tck/Downloads/desk_002.jpg");

	int cols = src.cols;
	int rows = src.rows;
	int channels = src.channels();
	cout << cols << "," << rows << "," << channels;

	int alpha = 1;
	int beta = 50;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (channels == 3) {
				//获取像素 at Vec3b个参数
				int b = src.at<Vec3b>(i, j)[0];
				int g = src.at<Vec3b>(i, j)[1];
				int r = src.at<Vec3b>(i, j)[2];

				//修改像素(底片效果)
				src.at<Vec3b>(i, j)[0] = saturate_cast<uchar>(b * alpha + beta);
				src.at<Vec3b>(i, j)[1] = saturate_cast<uchar>(g * alpha + beta);
				src.at<Vec3b>(i, j)[2] = saturate_cast<uchar>(r * alpha + beta);
			}
		}
	}

	imshow("src", src);
	waitKey(0);
	return 0;
}

//inline 内联函数 类似define编译时替换
//区别 define 并没有严格检测
//inline使用场景 不涉及过于复杂的函数
inline int max(int a, int b) {
	return a > b ? a : b;
}
int tes8() {
	int m1 = MAX(1, 2);
	int max2 = max(5, 9);
	cout << "max=" << m1 << endl;
	return 0;
}
//
#define MAX(a,b) a>b?a:b

int main() {
	//  imread 读取一张图片  Mat(图片)  
	Mat src = imread("C:/Users/tck/Downloads/desk_002.jpg");

	//绘制线
	line(src, Point(100, 100), Point(200, 200),Scalar(255,0,0),2, LINE_8);
	//矩形
	rectangle(src, Point(300, 300), Point(400, 400), Scalar(0, 0, 255), 2, LINE_8);

	//椭圆
	//第一个参数 椭圆的中心点
	//第三个参数 
	ellipse(
		src,
		Point(src.cols/2, src.rows/2),
		Size(src.cols / 8, src.rows / 4),
		180,
		0,
		360,
		Scalar(0, 255, 255),
		1
		);

	//圆形
	circle(src,
		Point(src.cols / 2, src.rows / 2),
		src.rows / 4,
		Scalar(255, 255, 0),
		2,
		LINE_AA
	);

	//填充
	/*CV_EXPORTS void fillPoly(Mat & img, const Point * *pts,
		const int* npts, int ncontours,
		const Scalar & color, int lineType = LINE_8, int shift = 0,
		Point offset = Point());*/
	//fillPoly();

	//文字
	//putText();

	imshow("src", src);
	waitKey(0);

	return 0;
}