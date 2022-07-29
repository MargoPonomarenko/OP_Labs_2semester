#pragma once
#include "TTriangle.h"
class Right :   //клас-нащадок "Прямокутні трикутники"
    public TTriangle
{
private:
	double angle1;

public:
	Right(Coordinates point1, Coordinates point2, int side1);

	TriangleType getType() override {
		return TriangleType::RIGHT;
	}

	double CalculateArea() override;   //метод для обчислення площі
	double CalculatePerimeter() override;
	string info() override;
};

