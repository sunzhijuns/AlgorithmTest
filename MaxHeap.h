#pragma once
#include<algorithm>
#include<cassert>
#include<string>
using namespace std;
#define root (0)
#if root == 1
#define parent(i) ((i)/2)
#define left(i) 2*(i)
#define right(i) (2*(i)+1)
#else
#define parent(i) (((i)-1)/2)
#define left(i) (2*(i)+1)
#define right(i) (2*(i)+2)
#endif


template<typename Item>
class MaxHeap {
private:
	Item* data;
	int count;
	int capacity;
	void shiftUp(int k) {
		while (k > root && data[parent(k)]<data[k])
		{
			swap(data[k], data[parent(k)]);
			k = parent(k);
		}
	}
	void shiftDown(int k) {
		while (left(k) <= count-1+root)
		{
			int j = left(k);
			if (right(k) <= count-1+root  && data[j+1] > data[j])
			{
				j++;
			}
			if (data[k] >= data[j])
			{
				break;
			}
			swap(data[k],data[j]);
			k = j;
		}
	}
public:
	MaxHeap(int capacity) {
		assert(capacity > 1);
		this->capacity = capacity;
		data = new Item[capacity+root];
		count = 0;
	}
	~MaxHeap() {
		delete[] data;
	}
	int size() {
		return count;
	}
	bool isEmpty() {
		return count == 0;
	}
	bool expand() {
		cout << capacity << " -> " << capacity * 2 << endl;
		capacity *= 2;
		Item *newData = new Item[capacity + root];
		if (!newData)
		{
			return false;
		}
		for (int i = 0; i < count+root; i++)
		{
			newData[i] = data[i];
		}
		delete[] data;
		data = newData;
		return true;
	}
	void insert(Item item) {
		if (count + root >= capacity)
		{
			assert (expand());
		}

		data[count + root] = item;
		shiftUp(count+root);
		count++;
		
	}
	Item extractMax() {
		assert(count > 0);
		Item ret = data[root];
		swap(data[root], data[count+root-1]);
		count--;
		shiftDown(root);
		return ret;
	}






public:
	void print() {
		for (int i = root; i < count+root; i++)
		{
			cout << data[i]<<" ";

		}
		cout << endl;
	}
	// 以树状打印整个堆结构
	void testPrint() {

		// 我们的testPrint只能打印100个元素以内的堆的树状信息
		if (size() >= 100) {
			cout << "This print function can only work for less than 100 int";
			return;
		}

		// 我们的testPrint只能处理整数信息
		if (typeid(Item) != typeid(int)) {
			cout << "This print function can only work for int item";
			return;
		}

		cout << "The max heap size is: " << size() << endl;
		cout << "Data in the max heap: ";
		for (int i = 1; i <= size(); i++) {
			// 我们的testPrint要求堆中的所有整数在[0, 100)的范围内
			assert(data[i] >= 0 && data[i] < 100);
			cout << data[i] << " ";
		}
		cout << endl;
		cout << endl;

		int n = size();
		int max_level = 0;
		int number_per_level = 1;
		while (n > 0) {
			max_level += 1;
			n -= number_per_level;
			number_per_level *= 2;
		}

		int max_level_number = int(pow(2, max_level - 1));
		int cur_tree_max_level_number = max_level_number;
		int index = 1;
		for (int level = 0; level < max_level; level++) {
			string line1 = string(max_level_number * 3 - 1, ' ');

			int cur_level_number = min(count - int(pow(2, level)) + 1, int(pow(2, level)));
			bool isLeft = true;
			for (int index_cur_level = 0; index_cur_level < cur_level_number; index++, index_cur_level++) {
				putNumberInLine(data[index], line1, index_cur_level, cur_tree_max_level_number * 3 - 1, isLeft);
				isLeft = !isLeft;
			}
			cout << line1 << endl;

			if (level == max_level - 1)
				break;

			string line2 = string(max_level_number * 3 - 1, ' ');
			for (int index_cur_level = 0; index_cur_level < cur_level_number; index_cur_level++)
				putBranchInLine(line2, index_cur_level, cur_tree_max_level_number * 3 - 1);
			cout << line2 << endl;

			cur_tree_max_level_number /= 2;
		}
	}

private:
	void putNumberInLine(int num, string &line, int index_cur_level, int cur_tree_width, bool isLeft) {

		int sub_tree_width = (cur_tree_width - 1) / 2;
		int offset = index_cur_level * (cur_tree_width + 1) + sub_tree_width;
		assert(offset + 1 < line.size());
		if (num >= 10) {
			line[offset + 0] = '0' + num / 10;
			line[offset + 1] = '0' + num % 10;
		}
		else {
			if (isLeft)
				line[offset + 0] = '0' + num;
			else
				line[offset + 1] = '0' + num;
		}
	}

	void putBranchInLine(string &line, int index_cur_level, int cur_tree_width) {

		int sub_tree_width = (cur_tree_width - 1) / 2;
		int sub_sub_tree_width = (sub_tree_width - 1) / 2;
		int offset_left = index_cur_level * (cur_tree_width + 1) + sub_sub_tree_width;
		assert(offset_left + 1 < line.size());
		int offset_right = index_cur_level * (cur_tree_width + 1) + sub_tree_width + 1 + sub_sub_tree_width;
		assert(offset_right < line.size());

		line[offset_left + 1] = '/';
		line[offset_right + 0] = '\\';
	}









};