#pragma once
#include "TTriangle.h"
class Isosceles :   //клас-нащадок "Рівнобедренні трикутники"
    public TTriangle
{
private:
    double angle1;

public:
    Isosceles(Coordinates point1, Coordinates point2, int angle);

    TriangleType getType() override {
        return TriangleType::ISOSCELES;
    }
    
    double CalculatePerimeter() override;
    double CalculateArea() override;
    string info() override;
};

