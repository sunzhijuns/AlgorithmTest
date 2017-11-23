
#include "stdafx.h"
#include<iostream>
#include<ctime>
#include"MaxHeap.h"

using namespace std;

int main()
{
	MaxHeap<int> maxheap = MaxHeap<int>(5);
	cout << maxheap.size() << endl;
	srand(time(NULL));
	for (int i = 0; i < 8; i++)
	{
		maxheap.insert(i);
	}
	maxheap.print();
	while (!maxheap.isEmpty())
	{
		cout << maxheap.extractMax() << endl;
		maxheap.print();

	}
	system("pause");

	return 0;
}