#pragma once
#include <iostream>
#include "nodeTree.h"
using namespace std;

template<typename T>
class AVLtree
{
private:
	NodeTree<T>* root;
public:
	//constructors
	AVLtree()
	{
		root = NULL;
	}
	AVLtree(NodeTree<T>* n)
	{
		root = n;
	}

	//getter
	NodeTree<T>* getRoot()
	{
		return root;
	}

	//setter
	void setRoot(NodeTree<T>* n)
	{
		root = n;
	}

	//rotation functions
	NodeTree<T>* leftRotate(NodeTree<T>* x)
	{
		NodeTree<T>* y = x->right;
		NodeTree<T>* T2 = y->left;

		y->left = x;
		x->right = T2;

		x->height = findMax(height(x->left),
			height(x->right)) + 1;
		y->height = findMax(height(y->left),
			height(y->right)) + 1;

		return y;
	}
	NodeTree<T>* rightRotate(NodeTree<T>* y)
	{
		NodeTree<T>* x = y->left;
		NodeTree<T>* T2 = x->right;

		x->right = y;
		y->left = T2;

		y->height = findMax(height(y->left),
			height(y->right)) + 1;
		x->height = findMax(height(x->left),
			height(x->right)) + 1;

		return x;
	}

	//insertion
	NodeTree<T>* insert(NodeTree<T>* node, T data)
	{
		if (node == NULL)
			return new NodeTree<T>(data);

		if (data < node->data)
			node->left = insert(node->left, data);
		else if (data > node->data)
			node->right = insert(node->right, data);
		else
			return node;

		node->height = 1 + findMax(height(node->left),
			height(node->right));
		int balance = getBalance(node);
		if (balance > 1 && data < node->left->data)
			return rightRotate(node);
		if (balance < -1 && data > node->right->data)
			return leftRotate(node);
		if (balance > 1 && data > node->left->data)
		{
			node->left = leftRotate(node->left);
			return rightRotate(node);
		}
		if (balance < -1 && data < node->right->data)
		{
			node->right = rightRotate(node->right);
			return leftRotate(node);
		}

		return node;
	}

	//deletion
	NodeTree<T>* deleteNode(NodeTree<T>* node, T data)
	{
		if (node == NULL)
			return node;
		if (data < node->data)
			node->left = deleteNode(node->left, data);
		else if (data > node->data)
			node->right = deleteNode(node->right, data);
		else
		{
			if ((node->left == NULL) || (node->right == NULL))
			{
				NodeTree<T>* temp = node->left ? node->left : node->right;
				if (temp == NULL)
				{
					temp = node;
					node = NULL;
				}
				else
					*node = *temp;
				delete temp;
			}
			else
			{
				NodeTree<T>* temp = minValueNode(node->right);
				node->data = temp->data;

				node->right = deleteNode(node->right,
					temp->data);
			}
		}
		if (node == NULL)
			return node;
		node->height = 1 + findMax(height(node->left),
			height(node->right));
		int balance = getBalance(node);
		if (balance > 1 &&
			getBalance(node->left) >= 0)
			return rightRotate(node);
		if (balance > 1 &&
			getBalance(node->left) < 0)
		{
			node->left = leftRotate(node->left);
			return rightRotate(node);
		}
		if (balance < -1 &&
			getBalance(node->right) <= 0)
			return leftRotate(node);
		if (balance < -1 &&
			getBalance(node->right) > 0)
		{
			node->right = rightRotate(node->right);
			return leftRotate(node);
		}
		return node;
	}

	//utility functions
	//finding successor node
	NodeTree<T>* minValueNode(NodeTree<T>* node)
	{
		NodeTree<T>* current = node;

		/* loop down to find the leftmost leaf */
		while (current->left != NULL)
			current = current->left;

		return current;
	}
	//finding height
	int height(NodeTree<T>* node)
	{
		if (node == NULL)
			return 0;
		return node->height;
	}
	// Get Balance factor of node N 
	//finding balance
	int getBalance(NodeTree<T>* node)
	{
		if (node == NULL)
			return 0;
		return height(node->left) - height(node->right);
	}
	int findMax(int a, int b)
	{
		return (a > b) ? a : b;
	}
	//printing
	void inOrder(NodeTree<T>* traverse, char& number)
	{
		if (!traverse)
			return;
		inOrder(traverse->left, number);
		cout << number << ") " << traverse->data << endl;
		number++;
		inOrder(traverse->right, number);
	}
	//searching
	NodeTree<T>* search(NodeTree<T>* traverse, T d)
	{
		if (!traverse)
			return traverse;
		if (d == traverse->data)
		{
			return traverse;
		}
		if (d > traverse->data)
			return search(traverse->right, d);
		else if (d < traverse->data)
			return search(traverse->left, d);
	}

	//Login to account
	//only for the teacher and student
	NodeTree<T>* login() {
		T user;
		string un, p;
		int attempts = 3;
		bool userFound = false;

		cout << "Login to your account..." << endl << endl;

		while (!userFound && attempts != 0) {
			cout << " Enter Username: ";
			cin >> un;
			user.setUsername(un);
			cout << endl << "Enter Password: ";
			cin >> p;
			user.setPassword(p);

			NodeTree<T>* newNode = search(root, user);
			if (newNode == NULL)
			{
				userFound = false;
				attempts--;
			}
			else
			{
				userFound = true;
				return newNode;
			}
			cout << endl << "Try again...." << attempts << " left..." << endl;
		}
		exit(0);
	}
};