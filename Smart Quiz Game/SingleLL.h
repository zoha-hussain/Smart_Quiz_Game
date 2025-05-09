#pragma once
#include <iostream>
#include "NodeSingleLL.h"
using namespace std;

template <typename T>
class SingleLL
{
private:
	NodeSingleLL<T>* head;
	NodeSingleLL<T>* tail;
public:
	//constructors
	SingleLL()
	{
		head = NULL;
		tail = NULL;
	}
	SingleLL(NodeSingleLL<T>* h, NodeSingleLL<T>* t)
	{
		head = h;
		tail = t;
	}
	SingleLL(const SingleLL& l)
	{
		head = NULL;
		tail = NULL;
		NodeSingleLL<T>* temp = l.head;
		while (temp != NULL)
		{
			insertAtTail(temp->data);
			temp = temp->next;
		}
	}
	//getters
	NodeSingleLL<T>* getHead()
	{
		return head;
	}
	NodeSingleLL<T>* getTail()
	{
		return tail;
	}
	//setters
	void setHead(NodeSingleLL<T>* h)
	{
		head = h;
	}
	void setTail(NodeSingleLL<T>* t)
	{
		tail = t;
	}

	//insertion
	void insertAtHead(T n)
	{
		if (head == NULL)
		{
			head = tail = new NodeSingleLL<T>(n);
		}
		else
		{
			head = new NodeSingleLL<T>(n, head);
		}
	}
	void insertAtTail(T n)
	{
		if (tail != NULL)
		{
			NodeSingleLL<T>* temp = tail;
			tail = new NodeSingleLL<T>(n);
			temp->next = tail;
		}
		else
		{
			head = tail = new NodeSingleLL<T>(n);
		}
	}
	//deletion
	void deleteAtHead()
	{
		if (head == NULL)
		{
			return;
		}
		NodeSingleLL<T>* temp = head;
		head = temp->next;
		delete temp;
	}
	void deleteAtTail()
	{
		if (tail == NULL)
		{
			return;
		}
		NodeSingleLL<T>* traverse = head;
		while (traverse->next)
		{
			tail = traverse;
			traverse = traverse->next;
		}
		delete traverse;
		tail->next = NULL;
	}
};
