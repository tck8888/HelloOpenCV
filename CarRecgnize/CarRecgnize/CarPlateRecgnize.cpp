#include "CarPlateRecgnize.h"

CarPlateRecgnize::CarPlateRecgnize() {
	plateLocation = new CarPlateLocation();
}

CarPlateRecgnize::~CarPlateRecgnize() {
	if (!plateLocation) {
		delete plateLocation;
		plateLocation = 0;
	}
}
string CarPlateRecgnize::plateRecgnize(Mat src) {
	Mat plate;
	//¶¨Î»
	plateLocation->location(src, plate);
	return string("1234");
}
