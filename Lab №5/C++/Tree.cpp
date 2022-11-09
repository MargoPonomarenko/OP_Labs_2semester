#include "Tree.h"

bool Tree::addNode(int value, int level, int number)
{
	Node* newNode = new Node(value, level, number);
	if (root == nullptr) {   
		root = newNode;   //��������� ������
		root->setNumber(1);
		root->printInfo();
		cout << "\n";
		return true;
	}
	else if(level == 0 && number == 0){   //���������� ������ �������� ����� ������ ������
		cout << "�� ���������� ������ ��� i������� ���i��\n";
		return false;
	}
	if (!root->addChild(newNode, 0)) {
		cout << "�� ������� ������ �����\n";
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
