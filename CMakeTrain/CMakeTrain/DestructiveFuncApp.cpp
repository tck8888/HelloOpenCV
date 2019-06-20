#include <iostream>
using namespace std;
//析构函数
class DestructiveFuncApp {

public:
	void setLength(double len);
	double getLength(void);
	DestructiveFuncApp();//构造函数
	~DestructiveFuncApp();//析构函数
private:
	double length;
};

void DestructiveFuncApp::setLength(double len)
{
	length = len;
}

double DestructiveFuncApp::getLength(void)
{
	return length;
}

DestructiveFuncApp::DestructiveFuncApp(void)
{
	cout << "Object is being created" << endl;
}

DestructiveFuncApp::~DestructiveFuncApp()
{
	 cout << "Object is being deleted" << endl;
	 cout << "类的析构函数是类的一种特殊的成员函数，它会在每次删除所创建的对象时执行,析构函数的名称与类的名称是完全相同的，只是在前面加了个波浪号（~）作为前缀，它不会返回任何值，也不能带有任何参数。析构函数有助于在跳出程序（比如关闭文件、释放内存等）前释放资源。" << endl;
}
