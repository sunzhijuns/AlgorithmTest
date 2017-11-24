#pragma once
#include<cassert>
#include<iostream>
#define Root 0
#define Left(i) (2*(i)+1)
#define Right(i) (2*(i)+2)
#define Parent(i) (((i)-1)/2)
template<typename Item>
class MinHeap
{
	Item *data;
	int capacity;
	int count;
private:
	bool expand() {
		capacity *= 2;
		Item *newData = new Item[capacity];
		if (newData == NULL)
		{
			return false;
		}
		for (int i = 0; i < count; i++)
		{
			newData[i] = data[i];
		}
		delete[] data;
		data = newData;
		return true;
	}
	void shiftDown(int k) {
		Item value = data[k];
		while (Left(k) < count)
		{
			int j = Left(k);
			if (Right(k) < count && data[Right(k)] < data[Left(k)])
			{
				j = Right(k);
			}
			if (data[j]>= value)
			{
				break;
			}
			data[k] = data[j];
			k = j;
		}
		data[k] = value;
	}
	void shiftUp(int k) {
		Item value = data[k];
		while (Parent(k) > Root && data[Parent(k)] > value) {
			data[k] = data[Parent(k)];
			k = Parent(k);
		}
		if (Parent(k) >= Root && data[Parent(k)] > value)
		{
			data[k] = data[Parent(k)];
			k = Parent(k);

		}
		data[k] = value;
	}

public:
	MinHeap(int capacity)
	{
		assert(capacity > 0);
		this->capacity = capacity;
		count = 0;
		data = new Item[capacity];
	}
	MinHeap(Item *arr, int n) {
		this->capacity = n;
		count = n;
		data = new Item[capacity];
		for (int i = Parent(count-1); i>= Root; i--)
		{
			shiftDown(i);
		}
	}
	void insert(Item item) {
		if (count + 1 > capacity){ assert(expand());}
		data[count] = item;
		shiftUp(count);
		count++;
	}
	Item extractMin() {
		Item ret = data[Root];
		data[Root] = data[count - 1];
		count--;
		shiftDown(Root);
		return ret;
	}
	void print() {
		for (int i = 0; i < count; i++)
		{
			std::cout << data[i] << " ";
		}
		std::cout << std::endl;
	}

	~MinHeap()
	{
		delete[] data;
	}
	int size() {
		return count;
	}
	bool isEmpty() {
		return count == 0;
	}

private:

};
