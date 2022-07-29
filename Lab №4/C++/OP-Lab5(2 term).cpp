//Створити клас TTriangle, який містить координати вершин і методи обчислення його площі та периметру. 
//На основі цього класу створити класи-нащадки, які представляють рівносторонні, прямокутні та рівнобедрені трикутники. 
//Створити певну кількість трикутників кожного виду, щоб їх сумарна кількість дорівнювала n. 
//Для рівносторонніх та прямокутних трикутників обчислити суму їх площ, а для рівнобедрених - суму всіх периметрів.

#include <iostream>
#include <vector>
#include <string>
#include "Equilateral.h"
#include "Right.h"
#include "Isosceles.h"

using namespace std;

void createEquilateral(vector<TTriangle*> &triangls, int count); //функції для створення трикутників кожного виду
void createRight(vector<TTriangle*>& triangls, int count);
void createIsosceles(vector<TTriangle*>& triangls, int count);
//void createTriangle(vector<TTriangle*>& triangls, int count);
//

int input(string message);

int main()
{
	setlocale(LC_CTYPE, "ukr");
	int n;
	cout << "Input number of triangles: ";
	cin >> n;
	vector<TTriangle*> triangls;

	for (size_t i = 0; i < 4; i++)
	{
		switch (i) {
			case 0:
				createEquilateral(triangls, n / 3);   //створення трикутників певних видів
				break;
			case 1:
				createRight(triangls, n / 3);
				break;
			case 2:
				createIsosceles(triangls, n / 3 + n % 3);
				break;
			/*case 3:
				createTriangle(triangls, n / 4 + n % 4);
				break;*/
		}
	}

	double areaSyma = 0;
	double perimeterSyma = 0;
	for (auto triangle:triangls)  
	{
		switch (triangle->getType()) {
			case TriangleType::EQUILATERAL:
			case TriangleType::RIGHT :
				areaSyma += triangle->CalculateArea();   //підрахунок суми площ
				cout << triangle->info();   //виведення данних про трикутник
				break;
			case TriangleType::ISOSCELES:
				perimeterSyma += triangle->CalculatePerimeter();   //підрахунок суми периметрів
				cout << triangle->info();
				break;
			default:
				cout << (int)(triangle->getType());
		}
	} 
	cout << endl << "Сума площ = "<< areaSyma << endl;
	cout << "Сума периметрiв = " << perimeterSyma << endl;
}

void createEquilateral(vector<TTriangle*> &triangls, int count) {
	for (size_t i = 0; i < count; i++)
	{
		cout << "Створення рiвностороннього трикутника..." << endl;
		int x1 = input("x1 = ");
		int y1 = input("y1 = ");
		int x2 = input("x2 = ");
		int y2 = input("y2 = ");
		Coordinates c1(x1, y1);
		Coordinates c2(x2, y2);
		triangls.push_back(new Equilateral(c1, c2));
	}
}

void createRight(vector<TTriangle*>& triangls, int count) {
	for (size_t i = 0; i < count; i++)
	{
		cout << "Створення прямокутного трикутника..." << endl;
		int x1 = input("x1 = ");
		int y1 = input("y1 = ");
		int x2 = input("x2 = ");
		int y2 = input("y2 = ");
		int side = input("side = ");
		Coordinates c1(x1, y1);
		Coordinates c2(x2, y2);
		triangls.push_back(new Right(c1, c2, side));
	}
}

void createIsosceles(vector<TTriangle*>& triangls, int count) {
	for (size_t i = 0; i < count; i++)
	{
		cout << "Створення рiвнобедренного трикутника..." << endl;
		int x1 = input("x1 = ");
		int y1 = input("y1 = ");
		int x2 = input("x2 = ");
		int y2 = input("y2 = ");
		int angle = input("angle = ");
		Coordinates c1(x1, y1);
		Coordinates c2(x2, y2);
		triangls.push_back(new Isosceles(c1, c2, angle));
	}
}

//void createTriangle(vector<TTriangle*>& triangls, int count)
//{
//	for (size_t i = 0; i < count; i++)
//	{
//		int x1 = input("x1 = ");
//		int y1 = input("y1 = ");
//		int x2 = input("x2 = ");
//		int y2 = input("y2 = ");
//		int side = input("side = ");
//		int angle = input("angle = ");
//		Coordinates c1(x1, y1);
//		Coordinates c2(x2, y2);
//		triangls.push_back(new TTriangle(c1, c2, side, angle));
//	}
//}

int input(string message)   //функція для отримання даних від користувача
{
	cout << message<<": ";
	string data;
	cin >> data;
	return stoi(data);
}
