#include <sstream>
#include "TTriangle.h"

TTriangle::TTriangle(Coordinates point1, Coordinates point2, int side1,  int angle)
{
	coordinates.push_back(point1);
	coordinates.push_back(point2);
	double x3 = 0.0;
	double y3 = 0.0;
	double side3 = point1.distanceTo(point2);
	double side2 = sqrt(pow(side1, 2) + pow(side3, 2) - 2 * side1 * side3 * cos((angle * 3.14) / 180));

	double k = (pow(side3, 2) + pow(side2, 2) - pow(side1, 2)) / (2 * side3);   //обчислення координат третьої вершини
	double h = sqrt(pow(side2, 2) - pow(k, 2));
	if (angle <= 90) {
		x3 = round((point1.x + (k / side3) * (point2.x - point1.x) - (h / side3) * (point2.y - point1.y)) * 100) / 100;
		y3 = round((point1.y + (k / side3) * (point2.y - point1.y) + (h / side3) * (point2.x - point1.x)) * 100) / 100;
	}
	else {
		x3 = round((point1.x + (k / side3) * (point2.x - point1.x) + (h / side3) * (point2.y - point1.y)) * 100) / 100;
		y3 = round((point1.y + (k / side3) * (point2.y - point1.y) - (h / side3) * (point2.x - point1.x)) * 100) / 100;
	}
	Coordinates point3(x3, y3);
	coordinates.push_back(point3);
}

//string TTriangle::info()
//{
//	stringstream output;
//	int i = 1;
//	for (auto point:coordinates)
//	{
//		output << "x" << i << " = " << point.x << "; y" << i << " = " << point.y << endl;
//	}
//	output << "side1 = ";
//	return output.str();
//}
