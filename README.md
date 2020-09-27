## opencv开发环境 Windows10 Visual Studio 2019

#### opencv Github地址  

    https://github.com/opencv/opencv/releases
    
#### 下载opencv

    opencv-x.x.x-android-sdk.zip 
    opencv-x.x.x-vc14_vc15.exe

#### 安转

    opencv-x.x.x-vc14_vc15.exe

#### windows配置opencv的环境变量 

    D:\Program Files (x86)\opencv\opencv\build\x64\vc14\bin

#### vs配置为运行为x64

#### vs配置包含目录  

    调试-->xxx属性-->VC++目录-->包含目录		
    D:\Program Files (x86)\opencv\opencv\build\include
    
#### vs配置库目录	

    调试-->xxx属性-->VC++目录-->库目录	
    D:\Program Files (x86)\opencv\opencv\build\x64\vc14\lib
    
#### vs配置链接器	

    调试-->xxx属性-->链接器-->输入-->添加-->附加依赖项  添加opencv_world346d.lib 位置在
    D:\Program Files (x86)\opencv\opencv\build\x64\vc14\lib

#### 测试程序

```
#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
void main() {
	//  imread 读取一张图片  Mat(图片)  
	Mat src = imread("C:/Users/tck/Downloads/yys_download_url_2.png");
	// 显示图片
	imshow("yys_test pic", src);

	// Android 滤镜 ，矩阵 Bitmap 

	waitKey(0);
}
```

## opencv开发环境 Windows10 Android Studio

#### opencv Github地址  

    https://github.com/opencv/opencv/releases
    
#### 下载opencv

    opencv-x.x.x-android-sdk.zip 
    opencv-x.x.x-vc14_vc15.exe

#### 解压

    opencv-x.x.x-android-sdk.zip 

#### copy下面目录下的所有文件到android工程下的cpp目录

    D:\BaiduNetdiskDownload\opencv\OpenCV-android-sdk\sdk\native\jni\include

#### copy 下面目录下的libopencv_java3.so文件到android工程下的libs目录

    D:\BaiduNetdiskDownload\opencv\OpenCV-android-sdk\sdk\native\libs
    
#### 配置cmake

