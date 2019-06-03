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

int test2() {
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
	mat = src.clone();
	//cout << mat << endl;

	cout << cols << "," << rows << "," << channels;

	imshow("mat", mat);
	waitKey(0);
	return 0;
}

int test3() {
	//  imread ��ȡһ��ͼƬ  Mat(ͼƬ)  
	Mat src = imread("C:/Users/tck/Downloads/desk_002.jpg");

	//�����ȡ�����漰�������µ����ݣ�
	Mat srcROI = src(Rect(20, 20, 500, 500));

	//���ı�ԭͼ
	Mat dstROI = srcROI.clone();


	int rows = dstROI.rows;
	int cols = dstROI.cols;
	//��������
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			//��ȡ���� at Vec3b������
			int b = dstROI.at<Vec3b>(i, j)[0];
			int g = dstROI.at<Vec3b>(i, j)[1];
			int r = dstROI.at<Vec3b>(i, j)[2];

			//�޸�����(��ƬЧ��)
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
	//  imread ��ȡһ��ͼƬ  Mat(ͼƬ)  
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
				//��ȡ���� at Vec3b������
				int b = gray.at<Vec3b>(i, j)[0];
				int g = gray.at<Vec3b>(i, j)[1];
				int r = gray.at<Vec3b>(i, j)[2];

				//�޸�����(��ƬЧ��)
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
//ͼƬ�ĺϳ�
int test5() {
	//  imread ��ȡһ��ͼƬ  Mat(ͼƬ)  
	Mat src = imread("C:/Users/tck/Downloads/desk_002.jpg");
	Mat logo = imread("C:/Users/tck/Downloads/yys_download_url_2.png");

	//����ͼƬ��СҪһ��
	Mat dst;
	//�ǳ���Ӳ�����ص�ֱ�����
	//add(src, logo, dst);
	//dst(x) = saturate_cast(src(x)*alpha+logo(x)*beta+gamma)
	//addWeighted(src,0.5,logo,0.5,0.0,dst);

	Mat srcROI = src(Rect(0, 0, logo.cols, logo.rows));
	//�����ʺϼ�ˮӡ��ֻ�ʺ�ͼƬ���
	addWeighted(srcROI, 0.8, logo, 0.8, 0.0, srcROI);

	imshow("src", src);
	waitKey(0);
	return 0;
}
//���Ͷ� ���� �Աȶ�
int test7() {
	//  imread ��ȡһ��ͼƬ  Mat(ͼƬ)  
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
				//��ȡ���� at Vec3b������
				int b = src.at<Vec3b>(i, j)[0];
				int g = src.at<Vec3b>(i, j)[1];
				int r = src.at<Vec3b>(i, j)[2];

				//�޸�����(��ƬЧ��)
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

//inline �������� ����define����ʱ�滻
//���� define ��û���ϸ���
//inlineʹ�ó��� ���漰���ڸ��ӵĺ���
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
	//  imread ��ȡһ��ͼƬ  Mat(ͼƬ)  
	Mat src = imread("C:/Users/tck/Downloads/desk_002.jpg");

	//������
	line(src, Point(100, 100), Point(200, 200),Scalar(255,0,0),2, LINE_8);
	//����
	rectangle(src, Point(300, 300), Point(400, 400), Scalar(0, 0, 255), 2, LINE_8);

	//��Բ
	//��һ������ ��Բ�����ĵ�
	//���������� 
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

	//Բ��
	circle(src,
		Point(src.cols / 2, src.rows / 2),
		src.rows / 4,
		Scalar(255, 255, 0),
		2,
		LINE_AA
	);

	//���
	/*CV_EXPORTS void fillPoly(Mat & img, const Point * *pts,
		const int* npts, int ncontours,
		const Scalar & color, int lineType = LINE_8, int shift = 0,
		Point offset = Point());*/
	//fillPoly();

	//����
	//putText();

	imshow("src", src);
	waitKey(0);

	return 0;
}