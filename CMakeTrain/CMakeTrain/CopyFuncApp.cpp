#include <iostream>
using namespace std;
//��������
class CopyFuncApp {

public:
	double getLength(void);
	CopyFuncApp(int len);//���캯��
	~CopyFuncApp();//��������
	CopyFuncApp(const CopyFuncApp& obj);//��������
private:
	int* ptr;
};


double CopyFuncApp::getLength(void)
{
	return *ptr;
}

CopyFuncApp::CopyFuncApp(int len)
{
	cout << "���ù��캯��" << endl;
	ptr = new int;
	*ptr = len;
}

CopyFuncApp::CopyFuncApp(const CopyFuncApp& obj)
{
	cout << "���ÿ������캯����Ϊָ�� ptr �����ڴ�" << endl;
	ptr = new int;
	*ptr = *obj.ptr; // ����ֵ
}

CopyFuncApp::~CopyFuncApp()
{
	cout << "�ͷ��ڴ�" << endl;
	delete ptr;
}

void display(CopyFuncApp obj) {
	cout << "line ��С : " << obj.getLength() << endl;
}
