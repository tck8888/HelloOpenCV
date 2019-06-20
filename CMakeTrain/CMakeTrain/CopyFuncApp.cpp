#include <iostream>
using namespace std;
//析构函数
class CopyFuncApp {

public:
	double getLength(void);
	CopyFuncApp(int len);//构造函数
	~CopyFuncApp();//析构函数
	CopyFuncApp(const CopyFuncApp& obj);//拷贝函数
private:
	int* ptr;
};


double CopyFuncApp::getLength(void)
{
	return *ptr;
}

CopyFuncApp::CopyFuncApp(int len)
{
	cout << "调用构造函数" << endl;
	ptr = new int;
	*ptr = len;
}

CopyFuncApp::CopyFuncApp(const CopyFuncApp& obj)
{
	cout << "调用拷贝构造函数并为指针 ptr 分配内存" << endl;
	ptr = new int;
	*ptr = *obj.ptr; // 拷贝值
}

CopyFuncApp::~CopyFuncApp()
{
	cout << "释放内存" << endl;
	delete ptr;
}

void display(CopyFuncApp obj) {
	cout << "line 大小 : " << obj.getLength() << endl;
}
