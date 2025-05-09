#pragma once
#include <iostream>
using namespace std;

template <typename T>
class NodeSingleLL
{
public:
	T data;
	NodeSingleLL<T>* next;

	//constructors
	NodeSingleLL()
	{
		data = 0;
		next = NULL;
	}
	NodeSingleLL(T n)
	{
		data = n;
		next = NULL;
	}
	NodeSingleLL(T n, NodeSingleLL<T>* address)
	{
		data = n;
		next = address;
	}
};