//Створити текстовий файл. Кожен парний рядок вихідного файлу переписати в перший новий текстовий файл, 
//кожен непарний - у другий. У файлі з парними рядками змінити рядки таким чином,
//щоб слова кожного рядка були лексично впорядковані за алфавітом. Вивести вміст вихідного і створених файлів.

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string createFile();
vector<string> loadFile(const string& fileName);
vector<string> extract(vector<string> data, int pair = 1);
void saveFile(const vector<string> data, const string& fileName);
void sortLine(vector<string>& data);
void printFile(const string& fileName);
const string firstFileName = "firstFile.txt";
const string secondFileName = "secondFile.txt";
vector<string> split(const string& line, char splitter = ' ');
string toString(const vector<string>& data);

int main() {
	string baseFileName = createFile();
	vector<string> baseFileData = loadFile(baseFileName);
	vector<string> firstFileData = extract(baseFileData, 2);
	sortLine(firstFileData);
	saveFile(firstFileData, firstFileName);
	vector<string> secondFileData = extract(baseFileData);
	saveFile(secondFileData, secondFileName);
	cout << "Inputed data:"<<endl;
	printFile(baseFileName);
	cout << "Sorted pair lines:" << endl;
	printFile(firstFileName);
	cout << "Unpaired lines:" << endl;
	printFile(secondFileName);
}

string createFile() //створення основного файлу
{
	string fileName;
	ofstream file;
	cout << "Enter file name: "; 
	getline(cin, fileName); 
	file.open(fileName);
	if (!file.is_open()) { 
		cout << "Error creating file";
		return "";
	}
	cout << "Enter file data: \n";
	string line;
	do {
		getline(cin, line); 
		if (line != "") {
			file << line + "\n";
		}

	} while (line != "");
	file.close(); 
	return fileName;
}

vector<string> loadFile(const string& fileName) //завантаження данних з основного файлу, для подальшого використання
{
	string dataLine;
	vector<string> data;
	ifstream file;
	file.open(fileName);
	if (!file.is_open()) {
		cout << "Error opening file";
		return data;
	}
	while (!file.eof()) {
		getline(file, dataLine);
		if (!file.eof()) data.push_back(dataLine);
	}
	return data;
}

vector<string> extract(vector<string> data, int pair) 
{
	vector<string> temp;
	for (size_t i = 0; i < data.size(); i++)
	{
		if (pair == 2) { //виділення парних рядків
			if (i % 2 != 0) { 
				temp.push_back(data.at(i));
			}
		}
		else if (pair == 1) { //виділення непарних рядків
			if (i % 2 == 0) { 
				temp.push_back(data.at(i));
			}
		}
	}
	return temp;
}

void sortLine(vector<string>& data) //сортування парних рядків
{
	for (size_t i = 0; i < data.size(); i++) {
		auto v = split(data.at(i), ' ');
		sort(v.begin(), v.end());
		data[i] = toString(v);
	}
}

void saveFile(const vector<string> data, const string& fileName) //збереження данних у відповідний файл
{
	ofstream file;
	file.open(fileName);
	if (!file.is_open()) {
		cout << "Error creating file";
		return ;
	}
	string line;
	for(auto line:data) {
		file << line + "\n";
	}
	file.close();
}

void printFile(const string& fileName) //виведення данних з файлу
{
	vector<string> baseFileData = loadFile(fileName);
	for (auto line : baseFileData) {
		cout << line + "\n";
	}
	cout << "\n";
}

vector<string> split(const string& line, char splitter) //функція, що розділяє рядок по словах
{
	vector<string> temp;
	string tempLine = "";
	if (line.length() == 0) {
		return temp;
	}
	for (auto ch : line) {
		if (ch == splitter) {
			temp.push_back(tempLine);
			tempLine = "";
		}
		else {
			tempLine += ch;
		}
	}
	temp.push_back(tempLine);
	return temp;
}

string toString(const vector<string>& data) //приймає відсортований вектор зі словами, повертає рядок з'єднаних слів через пробіл
{
	string tempLine = "";
	for (auto line : data) {
		tempLine += line + " ";
	}
	tempLine.pop_back();
	return tempLine;
}



