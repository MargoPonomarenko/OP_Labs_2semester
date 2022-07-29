#pragma once
#include <math.h>
using namespace std;

class Point {
private:
    int x;
    int y;

public:
    Point() { //конструктор за замовчуванням
        x = 0;
        y = 0;
    }

    Point(int xCoordinate, int yCoordinate) {  //конструктор з параметрами
        x = xCoordinate;
        y = yCoordinate;
    }

    int GetXPoint() { return x; }
    int GetYPoint() { return y; }

    int FindQuadrant() { //метод для визначення квадранта точки
        if (x >= 0 && y >= 0) {
            return 1;
        }
        if (x < 0 && y >= 0) {
            return 2;
        }
        if (x < 0 && y < 0) {
            return 3;
        }
        if (x >= 0 && y < 0) {
            return 4;
        }
    }

    Point& operator++() { //перевантаження префіксного "++" для збільшення х-координати точки на 1
        ++x;
        return *this; //повернення розіменованого покажчика
    }

    Point& operator++(int coordinate) { //перевантаження постфіксного "++" для збільшення у-координати точки на 1
        ++y;
        return *this;
    }

    double operator-(const Point& other) { //перевантаження оператора "-" для визначення відстані між двома точками
        double distance = sqrt(pow((other.x - this->x), 2) + pow((other.y - this->y), 2));
        return distance;
    }
};
