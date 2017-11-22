// AlgorithmTest.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include"Student.h"
#include"SelectionSort.h"
#include"SortTestHelper.h"
#include"InsertionSort.h"
#include"ShellSort.h"
//#include<algorithm>
using namespace std;


//[L,Mid],[Mid+1,R]
template<typename T>
void merge(T *arr, int L, int Mid, int R){
	T *aux = new T[R - L + 1];
	for (int i = L; i <= R; i++)
	{
		aux[i - L] = arr[i];
	}
	/*copy(arr + L, arr + R, aux);*/

	int i = L;
	int j = Mid + 1;
	for (int k = L; k <= R; k++)
	{
		if (i > Mid)
		{
			arr[k] = aux[j - L];
			j++;
		}
		else if (j > R)
		{
			arr[k] = aux[i - L];
			i++;
		}
		else if (aux[i - L] <= aux[j - L])
		{
			arr[k] = aux[i - L];
			i++;
		}
		else
		{
			arr[k] = aux[j - L];
			j++;
		}
	}
	delete[] aux;
}

template<typename T>
void __mergeSort(T *arr,int L, int R) {
	if (L>=R)
	{
		return;
	}
	int Mid = L + (R - L) / 2;
	__mergeSort(arr, L, Mid);
	__mergeSort(arr, Mid + 1, R);
	merge(arr,L,Mid,R);
}

template<typename T>
void mergeSort(T *arr, int n) {
	__mergeSort(arr,0,n-1);
}


template<typename T>
void __mergeSort1(T *arr, int L, int R,int minSort) {
	if (R-L < minSort)
	{
		insertSort(arr + L, R - L + 1);
		return;
	}
	int Mid = L + (R - L) / 2;
	__mergeSort1(arr, L, Mid,minSort);
	__mergeSort1(arr, Mid + 1, R,minSort);
	merge(arr, L, Mid, R);
}

template<typename T>
void mergeSort1(T *arr, int n,int minSort) {
	__mergeSort1(arr, 0, n - 1,minSort);
}

int main()
{
	int n = 1000000;
	//int *arr0 = SortTestHelper::generateNearlyOrderedArray(n,1000);
	int *arr0 = SortTestHelper::generateRandomArray(n,0,n);
	int *arr;
	for (int i = 1; i < 100; i++)
	{
		arr = SortTestHelper::copyIntArray(arr0, n);
		SortTestHelper::testSort("mergeSort1", mergeSort1, arr, n, i);
		delete[] arr;
	}
	//int *arr1 = SortTestHelper::copyIntArray(arr0, n);
	//int *arr2 = SortTestHelper::copyIntArray(arr0,n);
	//int *arr3 = SortTestHelper::copyIntArray(arr0, n);

	//SortTestHelper::testSort("selectionSort", selectionSort, arr0, n);
	//SortTestHelper::testSort("insertSort", insertSort, arr1, n);
	
	//SortTestHelper::testSort("mergeSort", mergeSort, arr1, n);
	//SortTestHelper::testSort("mergeSort", mergeSort, arr3, n);
	delete[] arr0;
	//delete[] arr1;
	//delete[] arr2;
	//delete[] arr3;
	system("pause");

	return 0;
}