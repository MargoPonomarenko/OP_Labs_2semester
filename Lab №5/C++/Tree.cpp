#include "Tree.h"

bool Tree::addNode(int value, int level, int number)
{
	Node* newNode = new Node(value, level, number);
	if (root == nullptr) {   
		root = newNode;   //створення кореня
		root->setNumber(1);
		root->printInfo();
		cout << "\n";
		return true;
	}
	else if(level == 0 && number == 0){   //припинення спроби створити більше одного кореня
		cout << "Ви намагаєтесь додати вже iснуючий корiнь\n";
		return false;
	}
	if (!root->addChild(newNode, 0)) {
		cout << "Не вдалося додати вузол\n";
		return false;
	}
	return true;
}

int Tree::calculateChild()
{
	int childAmount = root->calculateChildCount();
	return childAmount;
}

void Tree::printInfo()
{
	root->printInfo();
}
