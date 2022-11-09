#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

class Node
{
private:
	int value;
	int level;
	int number;
	vector<Node*> children;

public:
	Node(int value, int level, int number) :
		value(value), level(level), number(number) {}
	int getNumber() { return number; }
	void setNumber(int number) { this->number = number; }
	int getLevel() { return level; }

	bool addChild(Node* child, int previous);   //додавання дочірньої вершини
	void increase() {
		for (auto child : children)
		{
			child->number++;
		}
	}
	int getLast();
	void printInfo();   //виведення інформації про дерево
	int calculateChildCount();   //підрахунок дочірніх вершин

};

