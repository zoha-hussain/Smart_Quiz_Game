#pragma once
#include <iostream>
using namespace std;

template<typename T>
class NodeTree
{
public:
	T data;
	NodeTree* left;
	NodeTree* right;
	int height;

	//constructors
	NodeTree()
	{
		left = NULL;
		right = NULL;
		height = 0;
	}
	NodeTree(T d)
	{
		data = d;
		left = NULL;
		right = NULL;
		height = 1;
	}
	NodeTree(T d, NodeTree* l, NodeTree* r, int h)
	{
		data = d;
		left = l;
		right = r;
		height = h;
	}
};