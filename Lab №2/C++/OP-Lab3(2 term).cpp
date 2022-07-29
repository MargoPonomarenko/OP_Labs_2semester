//Розробити клас "Поїзд", який характеризується номером поїзда, пунктом призначення, часом його відправлення у форматі (ГГ-ХХ).
//Створити масив об`єктів даного класу. Визначити поїзди (їх номери), які відправляються з вокзалу у заданий період часу (діапазон годин).

#include <iostream>
#include <vector>
#include "Train.h"

using namespace std;

Train** createArray(int size);
void outputArray(Train** trainStation, int size);
vector <int> trainInRange(Train** trainStation, string range, int size);
bool inRange(string time, string range);

int main()
{
	int trainCount;
	string range;
	cout << "Input amount of trains: ";
	cin >> trainCount;
	Train** trainStation = createArray(trainCount);
	outputArray(trainStation, trainCount);

	cout <<endl<< "Input hour range in format HH-HH : ";
	cin >> range;
	auto trainNumbers = trainInRange(trainStation, range, trainCount);

	cout << endl << "Train with number will departure in given period: ";
	for (auto number:trainNumbers)
	{
		cout << number << " ";
	}
}

Train** createArray(int size)   //створення масиву об'єктів класу
{
	Train** array = new Train* [size];
	for (size_t i = 0; i < size; i++)
	{
		int number;
		cout << "Input train number: ";
		cin >> number;
		string destination;
		cout << "Input destination point: ";
		cin >> destination;
		string time;
		cout << "Input departure time in format 'HH-MM': ";
		cin >> time;
		array[i] = new Train(number, destination, time);
	}
	return array;
}

void outputArray(Train** trainStation, int size) {   //виведення масиву
	for (size_t i = 0; i < size; i++)
	{
		cout << trainStation[i]->GetNumber() << " | " << trainStation[i]->GetDestination() << " | " << trainStation[i]->GetTime() << endl;
	}
}

vector<int> trainInRange(Train** trainStation, string range, int size)
{
	vector<int> trainNumbers;
	for (size_t i = 0; i < size; i++)
	{
		if (inRange(trainStation[i]->GetTime(), range)) {
			trainNumbers.push_back(trainStation[i]->GetNumber());
		}
	}
	return trainNumbers;
}

bool inRange(string time, string range)
{
	int hours = stoi(time.substr(0, 2));
	int startHours = stoi(range.substr(0, 2));
	int endHours = stoi(range.substr(3));
	cout << hours << " = departure hour; " << startHours << " = start hour range; " << endHours <<" = end hour range" << endl;
	return hours >= startHours && hours < endHours;
}
