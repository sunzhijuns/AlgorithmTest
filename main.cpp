#include<iostream>
#include<assert.h>
#include"FileOps.h"
#include"SequenceST.h"
#include<ctime>
using namespace std;

template<typename Key, typename Value>
class BST
{
private:
	struct Node
	{
		Key key;
		Value value;
		Node *left;
		Node *right;
		Node(Key key, Value value) {
			this->key = key;
			this->value = value;
			this->left = this->right = NULL;
		}
	};
	Node *root;
	int count;
private:
	// 以node为根的二叉搜索树递归的插入节点
	Node* insert(Node *node, Key key, Value value) {
		if (node == NULL)
		{
			count++;
			return new Node(key, value);
		}
		if (key == node->key)
		{
			node->value = value;
		}
		else if (key < node->key)
		{
			node->left = insert(node->left, key, value);
		}
		else {
			node->right = insert(node->right, key, value);
		}
		return node;
	}
	// 以node为根的二叉搜索树非递归的插入节点
	void __insert(Node *node, Key key, Value value) {
		if (node == NULL)
		{
			count++;
			root = new Node(key, value);
			return;
		}
		while (true)
		{
			if (key == node->key)
			{
				node->value = value;
				return;
			}
			else if (key < node->key)
			{
				if (node->left == NULL)
				{
					count++;
					node->left = new Node(key,value);
					return;
				}
				node = node->left;

			}
			else {
				//(key > node->key)
				if (node->right == NULL)
				{
					count++;
					node->right = new Node(key,value);
					return;
				}
				node = node->right;
			}
		}
	}
	// 以node为根的二叉搜索树非递归的查找节点
	bool __contain(Node*node, Key key) {
		if (node == NULL)
		{
			return false;
		}
		while (true)
		{
			if (node->key == key)
			{
				return true;
			}
			else if (key < node->key)
			{
				if (node->left == NULL)
				{
					return false;
				}
				node = node->left;
			}
			else {//(key < node->key)
				if (node->right == NULL)
				{
					return false;
				}
				node = node->right;
			}
		}
	}
	// 以node为根的二叉搜索树递归的查找节点
	bool contain(Node * node, Key key) {
		if (node == NULL)
		{
			return false;
		}
		if (key == node->key)
		{
			return true;
		}
		else if (key < node->key)
		{
			return contain(node->left, key);
		}
		else {//(key > node->key)
			return contain(node->right, key);
		}
	}
	// 以node为根的非递归查找
	Value*__search(Node*node, Key key) {
		if (node == NULL)
		{
			return NULL;
		}
		while (true)
		{
			if (key == node->key)
			{
				return &(node->value);
			}
			else if (key < node->key)
			{
				if (node->left == NULL)
				{
					return NULL;
				}
				node = node->left;
			}
			else
			{
				if (node->right == NULL)
				{
					return NULL;
				}
				node = node->right;
			}
		}
	}
	// 以node为根的递归查找
	Value* search(Node *node, Key key) {
		if (node == NULL)
		{
			return NULL;
		}
		if (key == node->key)
		{
			return &(node->value);
		}
		else if (key < node->key)
		{
			return search(node->left, key);
		}
		else {
			return search(node->right, key);
		}
	}

public:
	void insert(Key key, Value value) {
		root = insert(root, key, value);
		//insert(root, key, value);
	}

	bool contain(Key key) {
		return contain(root, key);
	}
	Value* search(Key key) {
		return search(root, key);
	}



public:
	BST()
	{
		root = NULL;
		count = 0;
	}

	~BST()
	{
	}
	int size(){
		return count;
	}
	bool isEmpty() {
		return count == 0;
	}

private:

};


int main() {

	// 使用圣经作为我们的测试用例
	string filename = "bible.txt";
	vector<string> words;
	if (FileOps::readFile(filename, words)) {

		cout << "There are totally " << words.size() << " words in " << filename << endl;
		cout << endl;


		// 测试 BST
		time_t startTime = clock();

		// 统计圣经中所有词的词频
		// 注: 这个词频统计法相对简陋, 没有考虑很多文本处理中的特殊问题
		// 在这里只做性能测试用
		BST<string, int> bst = BST<string, int>();
		for (vector<string>::iterator iter = words.begin(); iter != words.end(); iter++) {
			int *res = bst.search(*iter);
			if (res == NULL)
				bst.insert(*iter, 1);
			else
				(*res)++;
		}

		// 输出圣经中god一词出现的频率
		if (bst.contain("god"))
			cout << "'god' : " << *bst.search("god") << endl;
		else
			cout << "No word 'god' in " << filename << endl;

		time_t endTime = clock();

		cout << "BST , time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;
		cout << endl;


		// 测试顺序查找表 SST
		startTime = clock();

		// 统计圣经中所有词的词频
		// 注: 这个词频统计法相对简陋, 没有考虑很多文本处理中的特殊问题
		// 在这里只做性能测试用
		SequenceST<string, int> sst = SequenceST<string, int>();
		for (vector<string>::iterator iter = words.begin(); iter != words.end(); iter++) {
			int *res = sst.search(*iter);
			if (res == NULL)
				sst.insert(*iter, 1);
			else
				(*res)++;
		}

		// 输出圣经中god一词出现的频率
		if (sst.contain("god"))
			cout << "'god' : " << *sst.search("god") << endl;
		else
			cout << "No word 'god' in " << filename << endl;

		endTime = clock();

		cout << "SST , time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;
	}

	return 0;
	system("pause");
	return 0;
}