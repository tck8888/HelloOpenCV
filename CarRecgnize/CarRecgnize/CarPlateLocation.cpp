#include "CarPlateLocation.h"

CarPlateLocation::CarPlateLocation() {

}

CarPlateLocation::~CarPlateLocation() {

}

void CarPlateLocation::location(Mat mat, Mat& dst) {
	////Ԥ���� ��ȥ�� �ó����������ͻ��
	Mat blur;
	//1����˹ģ����ƽ���� ��1��Ϊ�˺������� 2������ ��
	GaussianBlur(src, blur, Size(5, 5), 0);
}