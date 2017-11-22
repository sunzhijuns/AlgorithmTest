// AlgorithmTest.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include"Student.h"
#include"SelectionSort.h"
#include"SortTestHelper.h"
#include"InsertionSort.h"
#include"ShellSort.h"
#include<algorithm>
using namespace std;

#include<cmath>

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


//[L,Mid],[Mid+1,R]
template<typename T>
void merge1(T *arr, int L, int Mid, int R,T * aux) {
	for (int i = L; i <= R; i++)
	{
		aux[i] = arr[i];
	}
	/*copy(arr + L, arr + R, aux);*/

	int i = L;
	int j = Mid + 1;
	for (int k = L; k <= R; k++)
	{
		if (i > Mid)
		{
			arr[k] = aux[j];
			j++;
		}
		else if (j > R)
		{
			arr[k] = aux[i];
			i++;
		}
		else if (aux[i] <= aux[j])
		{
			arr[k] = aux[i];
			i++;
		}
		else
		{
			arr[k] = aux[j];
			j++;
		}
	}
}

template<typename T>
void __mergeSort1(T *arr, int L, int R , T *aux) {
	if (R-L < 30)
	{
		insertSort(arr + L, R - L + 1);
		return;
	}
	int Mid = L + (R - L) / 2;
	__mergeSort1(arr, L, Mid,aux);
	__mergeSort1(arr, Mid + 1, R,aux);
	if (arr[Mid] > arr[Mid+1])
	{
		merge1(arr, L, Mid, R, aux);
	}
	
}

template<typename T>
void mergeSort1(T *arr, int n) {
	T *aux = new T[n];
	__mergeSort1(arr, 0, n - 1,aux);
	delete[] aux;
}

int min1(int a, int b) {
	return a < b ? a : b;
}
template<typename T>
void mergeSort2(T *arr, int n) {
	T *aux = new T[n];

	for (int i = 0; i < n; i+=30)
	{
		insertSort(arr+i, min(30, n-i));
	}

	int sz = 30;
	for (; sz < n; sz *= 2)
	{
		for (int i = 0; i+sz < n; i += sz + sz)
		{
			if (arr[i+sz-1] > arr[i+sz])
			{
				merge1(arr, i, i + sz - 1, min(i + sz + sz - 1, n - 1), aux);
			}
			
		}

	}
	delete[] aux;
}

int main()
{
	int n = 1000000;
	//int *arr0 = SortTestHelper::generateNearlyOrderedArray(n,1000);
	int *arr0 = SortTestHelper::generateRandomArray(n,0,n);
	int *arr1 = SortTestHelper::copyIntArray(arr0, n);
	int *arr2 = SortTestHelper::copyIntArray(arr0,n);
	int *arr3 = SortTestHelper::copyIntArray(arr0, n);

	//SortTestHelper::testSort("selectionSort", selectionSort, arr0, n);
	//SortTestHelper::testSort("insertSort", insertSort, arr1, n);
	
	SortTestHelper::testSort("mergeSort", mergeSort, arr0, n);
	SortTestHelper::testSort("mergeSort1", mergeSort1, arr1, n);
	SortTestHelper::testSort("mergeSort", mergeSort, arr2, n);
	SortTestHelper::testSort("mergeSort2", mergeSort2, arr3, n);
	delete[] arr0;
	delete[] arr1;
	delete[] arr2;
	delete[] arr3;

	int *a = new int[81];
	for (int i = 0; i < 81; i++)
	{
		a[i] = 81 - i;
	}
	SortTestHelper::testSort("mergeSort2", mergeSort2, a,81);
	SortTestHelper::printArray(a,81);
	delete[]a;
	system("pause");

	return 0;
}