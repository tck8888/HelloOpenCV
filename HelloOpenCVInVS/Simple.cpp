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
	Mat src = imread("C:/Users/tck/Downloads/yys_download_url_2.png");
	// ��ʾͼƬ
	imshow("test pic", src);

	// Android �˾� ������ Bitmap 

	waitKey(0);
}