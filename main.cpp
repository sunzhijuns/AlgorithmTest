
#include "stdafx.h"
#include<iostream>
#include<ctime>
#include"MaxHeap.h"
#include"SortTestHelper.h"
#include"MergeSort.h"
#include"QuickSort.h"
#include"IndexMaxHeap.h"
#include"MinHeap.h"

using namespace std;

int main()
{
	/*int n = 1000000;
	cout << "size = " << n << " , random range [0, " << n << "]" << endl;
	int *arr1 = SortTestHelper::generateRandomArray(n,0,n);

	int* arr2 = SortTestHelper::copyIntArray(arr1,n);
	int* arr3 = SortTestHelper::copyIntArray(arr1, n);
	int* arr4 = SortTestHelper::copyIntArray(arr1, n);
	int* arr5 = SortTestHelper::copyIntArray(arr1, n);
	int* arr6 = SortTestHelper::copyIntArray(arr1, n);
	
	
	SortTestHelper::testSort("mergeSort", mergeSort, arr1,n);
	SortTestHelper::testSort("quickSort", quickSort, arr2, n);

	SortTestHelper::testSort("heapSort1", heapSort1, arr3, n);
	SortTestHelper::testSort("heapSort2", heapSort2, arr5, n);
	SortTestHelper::testSort("heapSort", heapSort, arr6, n);
	
	SortTestHelper::testSort("mergeSort", mergeSort, arr4, n);
	delete[] arr1;
	delete[] arr2;
	delete[] arr3;
	delete[] arr4;
	delete[] arr5;
	delete[] arr6;*/

	int n = 10;
	MinHeap<int> heap = MinHeap<int>(n);
	for (int i = 0; i < n; i++)
	{
		heap.insert(n-i);
	}
	//SortTestHelper::testSort("heapSort", heapSort, arr, n);
	while (!heap.isEmpty())
	{
		//heap.print();
		cout << heap.extractMin() << endl;
		heap.print();
		cout << "----------" << endl;
	}
	


	system("pause");

	return 0;
}