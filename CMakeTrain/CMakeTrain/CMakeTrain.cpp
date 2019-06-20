// CMakeTrain.cpp: 定义应用程序的入口点。
//

#include "CMakeTrain.h"
#include "Box.cpp"
#include "DestructiveFuncApp.cpp"
#include "CopyFuncApp.cpp"
using namespace std;

void pointDemo() {
	int var;
	int* ptr;
	int** pptr;

	var = 3000;
	// 获取 var 的地址
	ptr = &var;
	// 使用运算符 & 获取 ptr 的地址
	pptr = &ptr;
	cout << "var 值为 :" << var << endl;
	cout << "*ptr 值为:" << *ptr << endl;
	cout << "**pptr 值为:" << **pptr << endl;
	cout << "var 地址为 :" << &var << endl;
	cout << "ptr=&var 值为var的地址:" << ptr << endl;
	cout << "ptr地址为:" << &ptr << endl;
	cout << "*pptr=ptr=&var  值为var的地址:" << *pptr << endl;
	cout << "pptr 地址为:" << &pptr << endl;
}
int main()
{
	/*Box box;
	double volume = 0.0;
	box.height = 19;
	box.setBreadth(3);
	box.setHeight(4);
	box.setLength(5);
	volume = box.getVolume();
	cout << "box1的体积" << volume << endl;*/

	//DestructiveFuncApp dfApp;
	//dfApp.setLength(6.0);
	//cout << "Length of line : " << dfApp.getLength() << endl;

	//CopyFuncApp copyfunc(10);
	//display(copyfunc);

	pointDemo();
	return 0;
}
