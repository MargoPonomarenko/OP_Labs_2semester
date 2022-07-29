//Визначити клас "Точка", який задається координатами точки на площині. Реалізувати для нього декілька конструкторів, геттери, 
//метод визначення квадранта системи координат (його номера), в якому знаходиться дана точка. Перевантажити оператори: префіксний "++" - 
//для збільшення х-координати точки на 1, постфіксний "++" - для збільшення у-координати точки на 1, "-" - для визначення відстані 
//між двома точками. Створити три точки (Т1, Т2, Т3), використовуючи різні конструктори. Інкрементувати х-координату точки Т1 і 
//у-координату точки Т2. Визначити відстань між отриманими точками Т1 і Т2. Зясувати, якому квадранту належить точка Т3.

#include <iostream>
#include "Point.h"
using namespace std;

int main()
{
    Point first; //створення першої точки Т1
    cout << "1-x coordinate: " << first.GetXPoint() << endl << "1-y coordinate: " << first.GetYPoint() << endl;

    int a;
    int b;
    cout << "Input x for second point: ";
    cin >> a;
    cout << "Input y for second point: ";
    cin >> b;
    Point second(a, b); //створення другої точки Т2
    cout << "2-x coordinate: " << second.GetXPoint() << endl << "2-y coordinate: " << second.GetYPoint() << endl;

    Point third = second; //копіювальна ініціалізація, створення точки Т3
    cout << "3-x coordinate: " << third.GetXPoint() << endl << "3-y coordinate: " << third.GetYPoint() << endl;

    ++first;
    cout << endl << "Incremented x-coordinate of T1: " << first.GetXPoint();

    second++;
    cout << endl << "Incremented y-coordinate of T2: " << second.GetYPoint();

    double distanceBetween = first - second;
    cout << endl << "Distance between T1 and T2 = " << distanceBetween;

    cout << endl  << "Point T3 is located in the: " << third.FindQuadrant() << " quadrant" << endl;

}

