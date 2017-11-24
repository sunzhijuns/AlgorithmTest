#include<iostream>
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
		else if (key < node->value)
		{
			node->left = insert(node->left, key, value);
		}
		else {
			node->right = insert(node->right, key, value);
		}
		return node;
	}
	void *__insert(Node *node, Key key, Value value) {
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

public:
	void insert(Key key, Value value) {
		//root = insert(root, key, value);
		__insert(root, key, value);
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
	cout << "dd" << endl;
	system("pause");
	return 0;
}