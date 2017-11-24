#include<iostream>
#include<assert.h>
#include"FileOps.h"
#include"SequenceST.h"
#include<ctime>
#include<stack>
#include<queue>
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
	void __preOrder(Node *node) {
		if (node == NULL)
		{
			return;
		}
		cout << node->value << endl;
		stack<Node *> nodeStack = stack<Node*>();
		while (!nodeStack.empty())
		{
			node = nodeStack.pop();
			cout << node->value << endl;
			if (node->right)
			{
				nodeStack.push(node->right);
			}
			if (node->left)
			{
				nodeStack.push(node->left);
			}
		}
	}
	void __inOrder(Node*node) {

	}
	// 递归的前序遍历
	void preOrder(Node *node) {
		if (node==NULL)
		{
			return;
		}
		cout << node->value << endl;
		preOrder(node->left);
		preOrder(node->right);
	}
	// 递归的中序遍历
	void inOrder(Node *node) {
		if (node == NULL)
		{
			return;
		}
		inOrder(node->left);
		cout << node->value << endl;
		inOrder(node->right);
	}
	// 递归的后序遍历
	void postOrder(Node *node) {
		if (node == NULL)
		{
			return;
		}
		postOrder(node->left);
		postOrder(node->right);
		cout << node->value << endl;
	}
	// 递归的删除树
	void destroy(Node *node) {
		if (node ==NULL)
		{
			return;
		}
		destroy(node->left);
		destroy(node->right);
		delete node;
		count--;
	}


public:
	void insert(Key key, Value value) {
		//root = insert(root, key, value);
		__insert(root, key, value);
	}

	bool contain(Key key) {
		return contain(root, key);
	}
	Value* search(Key key) {
		return search(root, key);
	}
	void preOrder() {
		preOrder(root);
	}
	void inOrder() {
		inOrder(root);
	}
	void postOrder() {
		postOrder(root);
	}
	void levelOrder() {
		queue<Node*>q;
		if (root != NULL)
		{
			q.push(root);
		}
		while (!q.empty())
		{
			Node *node = q.front();
			q.pop();
			cout << node->key << endl;
			if (node->left)
			{
				q.push(node->left);
			}
			if (node->right)
			{
				q.push(node->right);
			}
		}	
	}


public:
	BST()
	{
		root = NULL;
		count = 0;
	}

	~BST()
	{
		destroy(root);
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

	BST<int, int> bst = BST<int, int>();
	for (int i = 0; i < 5; i++)
	{
		bst.insert(i, i);
	}
	bst.insert(23, 23);
	bst.insert(8,8);
	bst.insert(-5, -5);

	bst.inOrder();
	bst.levelOrder();
	
	system("pause");
	return 0;
}