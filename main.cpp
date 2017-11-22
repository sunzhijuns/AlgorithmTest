// AlgorithmTest.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include"Student.h"
#include"SelectionSort.h"
#include"SortTestHelper.h"
//#include<algorithm>
using namespace std;

template<typename T>
void insertSort(T arr[], int n) {
	for (int i = 1; i < n; i++)
	{
		T value = arr[i];
		int j = i;
		for (; j > 0; j--)
		{
			if (value < arr[j-1])
			{
				arr[j] = arr[j - 1];
			}
			else {
				break;
			}
		}
		arr[j] = value;
	}
}
template<typename T>
void insertSort1(T arr[], int n) {
	for (int i = 1; i < n; i++)
	{
		for (int j = i; j > 0; j--)
		{
			if (arr[j] < arr[j - 1])
			{
				swap(arr[j], arr[j-1]);
			}
			else {
				break;
			}
		}
	}
}
int main()
{
	int n = 10000;
	int *arr0 = SortTestHelper::generateRandomArray(n, 0, 10);
	int *arr1 = SortTestHelper::copyIntArray(arr0, n);
	int *arr2 = SortTestHelper::copyIntArray(arr1,n);

	SortTestHelper::testSort("selectionSort", selectionSort, arr0, n);
	SortTestHelper::testSort("insertSort", insertSort, arr1, n);
	SortTestHelper::testSort("insertSort1", insertSort1, arr2, n);
	delete[] arr0;
	delete[] arr1;
	delete[] arr2;

	system("pause");

	return 0;
}