
class Box {

	double wi;
public:
	double length;
	double breadth;
	double height;
	//³ÉÔ±º¯Êý
	double getVolume(void);
	void setLength(double len);
	void setBreadth(double bre);
	void setHeight(double hei);
};

double Box::getVolume(void)
{
	return length * breadth * height;
}

void Box::setLength(double len)
{
	length = len;
}

void Box::setBreadth(double bre)
{
	breadth = bre;
}

void Box::setHeight(double hei)
{
	height = hei;
}
