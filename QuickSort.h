#pragma once
#include<ctime>
#include<algorithm>
using namespace std;

template<typename T>
// [L, R] 只少两个
int __partition1(T arr[], int L, int R) {
	int q = rand() % (R - L + 1) + L;
	swap(arr[L], arr[q]);

	int j = L;
	for (int i = L + 1; i <= R; i++)
	{
		if (arr[i] >= arr[L])
		{
			continue;
		}
		else {
			swap(arr[j + 1], arr[i]);
			j++;
		}

	}
	swap(arr[j], arr[L]);

	return j;
}

template<typename T>
void __quickSort1(T arr[], int L, int R) {
	if (L >= R)
	{
		return;
	}
	//[L,R]
	int q = __partition1(arr, L, R);
	__quickSort1(arr, L, q - 1);
	__quickSort1(arr, q + 1, R);
}

template<typename T>
void quickSort1(T arr[], int n) {
	__quickSort1(arr, 0, n - 1);
}



template<typename T>
// [L, R] 只少两个
int __partition2(T arr[], int L, int R) {
	int q = rand() % (R - L + 1) + L;
	swap(arr[L], arr[q]);

	int j = L;
	T value = arr[L];
	for (int i = L + 1; i <= R; i++)
	{
		if (arr[i] < value)
		{
			swap(arr[j + 1], arr[i]);
			j++;
		}

	}
	swap(arr[j], arr[L]);
	return j;
}



template<typename T>
// [L, R] 只少两个
int __partition(T arr[], int L, int R) {
	int q = rand() % (R - L + 1) + L;
	swap(arr[L], arr[q]);

	T value = arr[L];
	int i = L + 1;
	int j = R;
	while (true)//i<=j) // 不可以i<j;
	{
		while (arr[i] < value)
		{
			i++;
		}
		while (arr[j] > value)
		{
			j--;
		}
		if (i>j) // 不可以i>=j
		{
			break;
		}
		swap(arr[i], arr[j]);
		i++;
		j--;

	}
	//for (int i = L + 1; i <= R; i++)
	//{
	//	if (arr[i] < value)
	//	{
	//		swap(arr[j + 1], arr[i]);
	//		j++;
	//	}

	//}
	swap(arr[j], arr[L]);
	return j;
}

template<typename T>
void __quickSort(T arr[], int L, int R) {
	if (R - L<30)
	{
		insertSort(arr + L, R - L + 1);
		return;
	}
	//[L,R]
	int q = __partition(arr, L, R);
	__quickSort(arr, L, q - 1);
	__quickSort(arr, q + 1, R);
}




template<typename T>
// [L, R] 只少两个
int* __partition3(T arr[], int L, int R) {
	int random = rand() % (R - L + 1) + L;
	swap(arr[L], arr[random]);

	T value = arr[L];
	int  LT = L;
	int GT = R + 1;
	int i = L + 1;
	while (i <= R)
	{
		if (arr[i] == value)
		{
			i++;
		}
		else if (arr[i] < value)
		{
			LT++;
			swap(arr[LT], arr[i]);
			i++;
		}
		else if (arr[i] > value)
		{
			GT--;
			swap(arr[GT], arr[i]);
		}
	}
	swap(arr[LT], arr[L]);
	int res[2] = { LT - 1,GT };
	return res;
}

template<typename T>
void __quickSort3(T arr[], int L, int R) {
	if (R - L<30)
	{
		insertionSort(arr, L, R);
		return;
	}
	//[L,R]
	/*int* q = __partition3(arr, L, R);*/
	int random = rand() % (R - L + 1) + L;
	swap(arr[L], arr[random]);

	T value = arr[L];
	int  LT = L;
	int GT = R + 1;
	int i = L + 1;
	while (i < GT)
	{
		if (arr[i] == value)
		{
			i++;
		}
		else if (arr[i] < value)
		{
			LT++;
			swap(arr[LT], arr[i]);
			i++;
		}
		else// if (arr[i] > value)
		{
			GT--;
			swap(arr[GT], arr[i]);
		}
	}
	swap(arr[LT], arr[L]);



	__quickSort3(arr, L, LT - 1);
	__quickSort3(arr, GT, R);
}


template<typename T>
void quickSort(T arr[], int n) {
	srand(time(NULL));
	__quickSort3(arr, 0, n - 1);
}



// 递归的三路快速排序算法
template <typename T>
void __quickSort3Ways(T arr[], int l, int r) {

	// 对于小规模数组, 使用插入排序进行优化
	if (r - l <= 15) {
		insertionSort(arr, l, r);
		return;
	}

	// 随机在arr[l...r]的范围中, 选择一个数值作为标定点pivot
	swap(arr[l], arr[rand() % (r - l + 1) + l]);

	T v = arr[l];

	int lt = l;     // arr[l+1...lt] < v
	int gt = r + 1; // arr[gt...r] > v
	int i = l + 1;    // arr[lt+1...i) == v
	while (i < gt) {
		if (arr[i] < v) {
			swap(arr[i], arr[lt + 1]);
			i++;
			lt++;
		}
		else if (arr[i] > v) {
			swap(arr[i], arr[gt - 1]);
			gt--;
		}
		else { // arr[i] == v
			i++;
		}
	}

	swap(arr[l], arr[lt]);

	__quickSort3Ways(arr, l, lt - 1);
	__quickSort3Ways(arr, gt, r);
}

template <typename T>
void quickSort3Ways(T arr[], int n) {

	srand(time(NULL));
	__quickSort3Ways(arr, 0, n - 1);
}

