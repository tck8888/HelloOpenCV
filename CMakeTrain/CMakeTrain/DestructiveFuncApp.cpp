#include <iostream>
using namespace std;
//��������
class DestructiveFuncApp {

public:
	void setLength(double len);
	double getLength(void);
	DestructiveFuncApp();//���캯��
	~DestructiveFuncApp();//��������
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
	 cout << "����������������һ������ĳ�Ա������������ÿ��ɾ���������Ķ���ʱִ��,���������������������������ȫ��ͬ�ģ�ֻ����ǰ����˸����˺ţ�~����Ϊǰ׺�������᷵���κ�ֵ��Ҳ���ܴ����κβ����������������������������򣨱���ر��ļ����ͷ��ڴ�ȣ�ǰ�ͷ���Դ��" << endl;
}
