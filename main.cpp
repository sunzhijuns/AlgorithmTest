// AlgorithmTest.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include"Student.h"
//#include<algorithm>
using namespace std;
template<typename T>
void selectionSort(T arr[], int n) {
	for (int i = 0; i < n - 1; i++)
	{
		int minIndex = i;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[j]<arr[minIndex] )
			{
				minIndex = j;
			}
		}
		if (minIndex != i)
		{
			swap(arr[minIndex], arr[i]);
		}
	}


}

int main()
{
	int arr[5] = { 1,2,3,1,2 };
	selectionSort(arr, 5);
	for (int i = 0; i < 5; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	float b[3] = {1.0,0.0,4.0};
	selectionSort(b,3);
	for (int i = 0; i < 3; i++)
	{
		cout << b[i] << " ";
	}
	cout << endl;

	string b1[3] = { "awe","a","asd" };
	selectionSort(b1, 3);
	for (int i = 0; i < 3; i++)
	{
		cout << b1[i].c_str() << " ";
	}
	cout << endl;


	Student b2[3] = { {"A",45},{ "B",65 },{ "C",0 } };
	selectionSort(b2, 3);
	for (int i = 0; i < 3; i++)
	{
		cout << b2[i];
	}
	cout << endl;
	system("pause");

	return 0;
}