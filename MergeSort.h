#pragma once
#include<algorithm>

//[L,Mid],[Mid+1,R]
template<typename T>
void merge1(T *arr, int L, int Mid, int R) {
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
void __mergeSort1(T *arr, int L, int R) {
	if (L >= R)
	{
		return;
	}
	int Mid = L + (R - L) / 2;
	__mergeSort1(arr, L, Mid);
	__mergeSort1(arr, Mid + 1, R);
	merge1(arr, L, Mid, R);
}

template<typename T>
void mergeSort1(T *arr, int n) {
	__mergeSort1(arr, 0, n - 1);
}


//[L,Mid],[Mid+1,R]
template<typename T>
void __merge(T *arr, int L, int Mid, int R, T * aux) {
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
void __mergeSort(T *arr, int L, int R, T *aux) {
	if (R - L < 30)
	{
		insertSort(arr + L, R - L + 1);
		return;
	}
	int Mid = L + (R - L) / 2;
	__mergeSort(arr, L, Mid, aux);
	__mergeSort(arr, Mid + 1, R, aux);
	if (arr[Mid] > arr[Mid + 1])
	{
		__merge(arr, L, Mid, R, aux);
	}

}

template<typename T>
void mergeSort(T *arr, int n) {
	T *aux = new T[n];
	__mergeSort(arr, 0, n - 1, aux);
	delete[] aux;
}

template<typename T>
void mergeSort2(T *arr, int n) {
	T *aux = new T[n];

	for (int i = 0; i < n; i += 30)
	{
		insertSort(arr + i, min(30, n - i));
	}

	int sz = 30;
	for (; sz < n; sz *= 2)
	{
		for (int i = 0; i + sz < n; i += sz + sz)
		{
			if (arr[i + sz - 1] > arr[i + sz])
			{
				__merge(arr, i, i + sz - 1, std::min(i + sz + sz - 1, n - 1), aux);
			}

		}

	}
	delete[] aux;
}