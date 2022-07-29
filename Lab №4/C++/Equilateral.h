#pragma once
#include "TTriangle.h"
class Equilateral :   //клас-нащадок "Рівносторонні трикутники"
    public TTriangle
{

public:
    Equilateral(Coordinates point1, Coordinates point2);

    TriangleType getType() override {
        return TriangleType::EQUILATERAL;
    }

    double CalculateArea() override;   //метод для обчислення площі
    double CalculatePerimeter() override;
    string info() override;
};

