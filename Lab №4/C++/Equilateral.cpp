#include <sstream>
#include "Equilateral.h"

Equilateral::Equilateral(Coordinates point1, Coordinates point2):
	TTriangle(point1, point2, point1.distanceTo(point2), 60)
{
	side3 = round(point1.distanceTo(point2) * 100) / 100;
	side1 = side2 = side3;
	angle = 60;
}

double Equilateral::CalculatePerimeter()
{
	return 0.0;
}

double Equilateral::CalculateArea() {
	return round((pow(side3, 2) * sqrt(3)) / 4 * 100) / 100;
}

string Equilateral::info()   //виведення данних про трикутник
{
	stringstream output;
	output << endl << "Данi про рiвностороннiй трикутник:" << endl;
	int i = 1;
	for (auto point:coordinates)
	{
		output << "x" << i << " = " << point.x << "; y" << i << " = " << point.y << endl;
		i++;
	}
	output << "side1 = side2 = side3 = " << side3 << endl << "angle = " << angle << endl << "Площа трикутника = " << CalculateArea() << endl;
	return output.str();
}
