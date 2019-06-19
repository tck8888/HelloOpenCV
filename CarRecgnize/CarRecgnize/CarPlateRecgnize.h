#ifndef CarPlateRecgnize_H
#define CarPlateRecgnize_H
#include "CarPlateLocation.h"
#include <string>

using namespace std;

class CarPlateRecgnize
{
public:
	CarPlateRecgnize();
	~CarPlateRecgnize();

	string plateRecgnize(Mat src);
private:
	CarPlateLocation* plateLocation = 0;
};

#endif // !CarPlateRecgnize_H
