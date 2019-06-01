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
using namespace std;

void test() {
	//  imread ��ȡһ��ͼƬ  Mat(ͼƬ)  
	Mat src = imread("C:/Users/tck/Downloads/desk_002.jpg");
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
			 /*uchar gery = 0.11f*r + 0.59f*g + 0.30f*b;
			 start_pixels[0] = gery;
			 start_pixels[1] = gery;
			 start_pixels[2] = gery;*/

			 /*//��ƬЧ��
			 start_pixels[0] = 255-b;
			 start_pixels[1] = 255 - g;
			 start_pixels[2] = 255 - r;*/

			 /*// 0-255  �� ���� 255 �ͱ�� 255 �����С�� 0 �ͱ�� 0
			 start_pixels[0] = saturate_cast<uchar>(1.2f * b);
			 start_pixels[1] = saturate_cast<uchar>(1.2f * g);
			 start_pixels[2] = saturate_cast<uchar>(1.2f * r);*/

			 //�ڰ�
			uchar b_w = (b + g + r) / 3 > 125 ? 255 : 0;
			start_pixels[0] = saturate_cast<uchar>(b_w);
			start_pixels[1] = saturate_cast<uchar>(b_w);
			start_pixels[2] = saturate_cast<uchar>(b_w);



			start_pixels += 3;
		}
	}
	imwrite("C:/Users/tck/Downloads/test2.jpg", src);
	imshow("test pic", src);

	// Android �˾� ������ Bitmap 

	waitKey(0);
}
int main() {
	//  imread ��ȡһ��ͼƬ  Mat(ͼƬ)  
	Mat src = imread("C:/Users/tck/Downloads/desk_002.jpg");
	/*//�ж��ļ��Ƿ��ȡ��ȷ
	if (src.empty()) {
		return -1;
	}*/

	//ͷָ��
	if (!src.data) {//src.data==NULL
		return -1;
	}

	int cols = src.cols;
	int rows = src.rows;
	int channels = src.channels();
	//���� rows �� cols
	//CV_8UC1 һ����ɫͨ����0-255��
	//CV_8UC2 ������ɫͨ�� 16λ RGB565
	//CV_8UC3 ������ɫͨ�� 24λ
	//CV_8UC4 �ĸ���ɫͨ�� 32λ RGB8888
	//ƥ��Bitmap ��ɫͨ��  RGB565  RGB8888

	//Scalar ָ����ɫ
	//��һ��Ϊ�߶� �ڶ���Ϊ���
	//Mat mat(10, 10, CV_8UC1,Scalar(200));

	//Size ��һ��Ϊ��� �ڶ���Ϊ�߶�
	//Mat mat(Size(10,10), CV_8UC1, Scalar(200));

	//Mat test(Size(8, 8), CV_8UC3, Scalar(255,66,255));//BGR
	//�������캯�� ���´������
	//Mat mat(src);
	//Mat mat =src;
	Mat mat;
	//��ȥcopy����
	//src.copyTo(mat);
	mat =src.clone();
	//cout << mat << endl;

	cout << cols << "," << rows << "," << channels;

	imshow("mat", mat);
	waitKey(0);
	return 0;
}