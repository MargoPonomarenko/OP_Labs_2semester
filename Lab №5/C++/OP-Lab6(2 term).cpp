//Побудувати дерево, елементами якого є цілі числа. Визначити кількість вузлових вершин даного дерева та надрукувати їх координати 
//(номер рівня та номер гілки).

#include <iostream>
#include "Node.h"
#include "Tree.h"
using namespace std;

int main()
{
	setlocale(LC_CTYPE, "ukr");

	int num;
	cout << "Скiльки елементiв бажаєте сворити? ";
	cin >> num;
	int value, level, number;

	Tree tree;
	for (size_t i = 0; i < num; i++)
	{
		cout <<endl<< "Node №" << i << endl;
		cout << "Введiть значення: ";
		cin >> value;
		cout << "Введiть номер рiвня: ";
		cin >> level;
		cout << "Введiть номер батькiвського вузла: ";
		cin >> number;
		if (!tree.addNode(value, level, number)) {
			i--;
		}
	}
	cout <<endl <<"Кiлькiсть вузлових вершин = " << tree.calculateChild()<<endl;   //обрахунок кількості вузлових вершин
	tree.printInfo();
	return 0;
}

