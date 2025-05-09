#include<iostream>
#include "nodeTree.h"
using namespace std;


template<typename T>
class Node {
public:
	T* data;
	Node<T>* next;

	Node() {
		data = NULL;
		next = NULL;
	}

	Node(T* d) : data(d), next(nullptr) {}
};

template<typename T, typename s>
class Queue {
public:
	Node<T>* Rear, * Front;
	Queue()
	{
		Rear = NULL;
		Front = NULL;
	}
	void Enqueue(NodeTree<s>* newNode)
	{
		Node<T>* node = new Node<T>(newNode);
		if (Rear == NULL) {
			Front = Rear = node;
		}
		else
		{
			Rear->next = node;
			Rear = node;
		}
	}

	T* Dequeue()
	{
		Node<T>* temp = Front;
		if (temp == NULL)
			return NULL;
		if (Front == Rear)
		{
			Rear = Front = NULL;
		}
		else
		{
			Front = Front->next;
		}
		return temp->data;

	}
	bool isEmpty() {
		if (Rear == NULL || Front == NULL)
			return true;
		return false;
	}
};