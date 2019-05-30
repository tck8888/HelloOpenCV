//����opencv  https://github.com/opencv/opencv/releases
//opencv-x.x.x-android-sdk.zip opencv-x.x.x-vc14_vc15.exe
//��תopencv-x.x.x-vc14_vc15.exe
//windows����opencv�Ļ������� D:\Program Files (x86)\opencv\opencv\build\x64\vc14\bin
//vs����Ϊ����Ϊx64
//vs���ð���Ŀ¼   ����-->xxx����-->VC++Ŀ¼-->����Ŀ¼		D:\Program Files (x86)\opencv\opencv\build\include
//vs���ÿ�Ŀ¼	����-->xxx����-->VC++Ŀ¼-->��Ŀ¼	D:\Program Files (x86)\opencv\opencv\build\x64\vc14\lib
//vs����������	����-->xxx����-->������-->����-->���-->����������  ���opencv_world346d.lib λ����D:\Program Files (x86)\opencv\opencv\build\x64\vc14\lib

#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
void main() {
	//  imread ��ȡһ��ͼƬ  Mat(ͼƬ)  
	Mat src = imread("C:/Users/tck/Downloads/desk_004.png");
	//Mat dst;
	//bitmapĬ�ϵ���RGB matĬ��BGR
	//cvtColor(src, dst, COLOR_BGR2GRAY);
	//д���ļ�
	//imwrite("C:/Users/tck/Downloads/gray.png", dst);
	// ��ʾͼƬ
	//imshow("test pic", dst);

	//��cols ��rows ��ɫͨ��channels   3 һ�����ص� 3��ɫͨ��������������Ϣ  BGR        
	printf("%d,%d,%d", src.rows, src.cols, src.channels());
	//��ɫת�Ҷ� ��ÿ�����ص� B G R  ��ֵ��� �� F = 0.11R + 0.59G + 0.30B
	for (int i = 0; i < src.rows; i++) {
		// ��ô������ Bitmap ����Java Bitmap ���أ�JNI�ײ��������ָ�� ԭ���ÿһ�����ص���д���
			// src.ptr<u32>(i);
			// 8 16 32
			// ��ȡ��ǰ�е��׵�ַ��ָ�룩
		uchar* start_pixels = src.ptr<uchar>(i);

		for (int j = 0; j < src.cols; j++) {
			uchar b = start_pixels[0];
			uchar g = start_pixels[1];
			uchar r = start_pixels[2];

			// ��ʽ���� f =  0.11R + 0.59G + 0.30B   gery ���255 ������������ܻᳬ�� 255
			// uchar gery = 0.11f*r + 0.59f*g + 0.30f*b;

			uchar b_w = (b + g + r) / 3 > 125 ? 255 : 0;
			// 0-255  �� ���� 255 �ͱ�� 255 �����С�� 0 �ͱ�� 0 
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

	// Android �˾� ������ Bitmap 

	waitKey(0);
}