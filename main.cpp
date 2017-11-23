
#include "stdafx.h"
#include<iostream>
#include<ctime>
#include"MaxHeap.h"
#include"SortTestHelper.h"
#include"MergeSort.h"
#include"QuickSort.h"

using namespace std;

template<typename T>
void heapSort1(T arr[], int n) {
	MaxHeap<T> maxheap = MaxHeap<T>(n);
	for (int i = 0; i < n; i++)
	{
		maxheap.insert(arr[i]);
	}
	for (int i = n-1; i >=0; i--)
	{
		arr[i] = maxheap.extractMax();
	}
}
template<typename T>
void heapSort2(T arr[], int n) {
	MaxHeap<T> maxheap = MaxHeap<T>(arr, n);
	for (int i = n - 1; i >= 0; i--)
	{
		arr[i] = maxheap.extractMax();
	}
}

int main()
{
	int n = 1000000;
	cout << "size = " << n << " , random range [0, " << n << "]" << endl;
	int *arr1 = SortTestHelper::generateRandomArray(n,0,n);

	int* arr2 = SortTestHelper::copyIntArray(arr1,n);
	int* arr3 = SortTestHelper::copyIntArray(arr1, n);
	int* arr4 = SortTestHelper::copyIntArray(arr1, n);
	int* arr5 = SortTestHelper::copyIntArray(arr1, n);
	
	
	SortTestHelper::testSort("mergeSort", mergeSort, arr1,n);
	SortTestHelper::testSort("quickSort", quickSort, arr2, n);

	SortTestHelper::testSort("heapSort1", heapSort1, arr3, n);
	SortTestHelper::testSort("heapSort2", heapSort2, arr3, n);
	
	SortTestHelper::testSort("mergeSort", mergeSort, arr4, n);
	delete[] arr1;
	delete[] arr2;
	delete[] arr3;
	delete[] arr4;
	delete[] arr5;

	n = 10;
	int *arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = n - i;
	}
	SortTestHelper::testSort("heapSort2", heapSort2, arr, n);
	SortTestHelper::printArray(arr,n);

	delete[] arr;


	system("pause");

	return 0;
}