#pragma once
#include <iostream>
#include "NodeSingleLL.h"
#include "SingleLL.h"
using namespace std;

class Subject
{
private:
	string name;
	int nEasy;
	int nHard;
	SingleLL<string> easy;
	SingleLL<string> hard;
public:
	//constructors
	Subject() {}
	Subject(string, int, int);
	Subject(string, int, int, NodeSingleLL<string>*, NodeSingleLL<string>*);

	//getters
	string getName()const;
	int getNEasy()const;
	int getNHard()const;
	NodeSingleLL<string>* getHeadEasy();
	NodeSingleLL<string>* getHeadHard();
	NodeSingleLL<string>* getTailEasy();
	NodeSingleLL<string>* getTailHard();

	//setters
	void setName(string);
	void setNEasy(int);
	void setNHard(int);
	void setHeadEasy(NodeSingleLL<string>*);
	void setHeadHard(NodeSingleLL<string>*);
	void setTailEasy(NodeSingleLL<string>*);
	void setTailHard(NodeSingleLL<string>*);

	//operator overloading
	//this is for searching of required name of subject in avl
	bool operator<(Subject& s);
	bool operator>(Subject& s);
	bool operator==(Subject& s);
	//this is for printing subject name (which user will select)
	friend ostream& operator << (ostream&, const Subject&);
};