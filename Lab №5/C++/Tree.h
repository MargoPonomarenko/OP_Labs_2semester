#pragma once
#include <vector>
#include "Node.h"
using namespace std;

class Tree
{
private:
	Node* root = nullptr;
public:
	bool addNode(int value, int level = 0, int number = 0);   //додавання вузла в дерево
	int calculateChild();
	void printInfo();
};

