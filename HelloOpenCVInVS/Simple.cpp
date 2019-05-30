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
void main() {
	//  imread 读取一张图片  Mat(图片)  
	Mat src = imread("C:/Users/tck/Downloads/desk_004.png");
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
			// uchar gery = 0.11f*r + 0.59f*g + 0.30f*b;

			uchar b_w = (b + g + r) / 3 > 125 ? 255 : 0;
			// 0-255  ， 大于 255 就变成 255 ，如果小于 0 就变成 0 
			start_pixels[0] = saturate_cast<uchar>(b_w);
			start_pixels[1] = saturate_cast<uchar>(b_w);
			start_pixels[2] = saturate_cast<uchar>(b_w);

			/*start_pixels[0] = saturate_cast<uchar>(1.2f*b);
			start_pixels[1] = saturate_cast<uchar>(1.2f*g);
			start_pixels[2] = saturate_cast<uchar>(1.2f*r);*/

			start_pixels += 3;
		}
	}
	imwrite("C:/Users/tck/Downloads/test2.png", src);
	imshow("test pic", src);

	// Android 滤镜 ，矩阵 Bitmap 

	waitKey(0);
}