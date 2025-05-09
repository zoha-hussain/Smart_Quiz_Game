#pragma once
#include <iostream>
using namespace std;

template <typename T>
class NodeDoubleLL
{
public:
	T data;
	NodeDoubleLL<T>* next;
	NodeDoubleLL<T>* prev;

	//constructors
	NodeDoubleLL()
	{
		data = 0;
		next = NULL;
		prev = NULL;
	}
	NodeDoubleLL(T n)
	{
		data = n;
		next = NULL;
		prev = NULL;

	}
	NodeDoubleLL(T n, NodeDoubleLL<T>* address1, NodeDoubleLL<T>* address2)
	{
		data = n;
		next = address1;
		prev = address2;
	}
	
};