#include "Node.h"

bool Node::addChild(Node* child, int previous)
{
	if (level < child->getLevel() - 1) {
		cout << "перехiд на рiвень вище..." << endl;
		for (size_t i = 0; i < children.size(); i++)
		{
			int last = i > 0 ? children.at(i - 1)->getLast() : 0;
			if (children.at(i)->addChild(child, last)) {
				if (child->getLevel() == level + 2 && i < children.size() - 1) {
					for (size_t j = i + 1; j < children.size(); j++)
					{
						children.at(j)->increase();
					}
				}
				return true;
			}
		}
	}
	else if(level == child->getLevel() - 1){
		if (number == child->getNumber()) {
			if (children.size() == 0) {
				child->setNumber(previous + 1);
			}
			else {
				child->setNumber(children.at(children.size() - 1)->getNumber() + 1);
			}
			children.push_back(child);
			if (child->value == 9) {
				cout << " ";
			}
			cout << "added on level: " << child->getLevel() << " number: " << child->getNumber() << endl;   //успішна спроба добавлення дочірнього вузла
			return true;
		}
	}
	return false;
}

int Node::getLast()
{
	if (children.size() > 0) {
		return children.at(children.size() - 1)->getNumber();
	}
	return 0;
}

void Node::printInfo()
{
	cout << "value: " << value << " (lev:" << level << "; num:" << number << ") - ";
	for (auto child: children)
	{
		child->printInfo();
		cout << "\n\t\t\tL";
	}
}

int Node::calculateChildCount()
{
	int count = 1;
	for (auto child : children)
	{
		count += child->calculateChildCount();
	}
	return count;
}



