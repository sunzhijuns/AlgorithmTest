// AlgorithmTest.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include"Student.h"
#include"SortTestHelper.h"
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
	int n = 10000;
	int *arr = SortTestHelper::generateRandomArray(n,0,10);
	SortTestHelper::testSort("Selection Sort", selectionSort, arr, n);
	delete[] arr;

	system("pause");

	return 0;
}