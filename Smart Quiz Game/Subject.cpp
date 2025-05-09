#include <iostream>
#include <chrono>
#include <thread>
#include "Subject.h"

//constructors
Subject::Subject(string n, int e, int h)
{
	name = n;
	nEasy = e;
	nHard = h;
}

Subject::Subject(string n, int e, int h, NodeSingleLL<string>* n1, NodeSingleLL<string>* n2)
{
	name = n;
	nEasy = e;
	nHard = h;
	easy.setHead(n1);
	hard.setHead(n2);
}

//getters
string Subject::getName()const
{
	return name;
}

int Subject::getNEasy()const
{
	return nEasy;
}

int Subject::getNHard()const
{
	return nHard;
}

NodeSingleLL<string>* Subject::getHeadEasy()
{
	return easy.getHead();
}
NodeSingleLL<string>* Subject::getHeadHard()
{
	return hard.getHead();
}

NodeSingleLL<string>* Subject::getTailEasy()
{
	return easy.getTail();
}
NodeSingleLL<string>* Subject::getTailHard()
{
	return hard.getTail();
}

//setters
void Subject::setName(string n)
{
	name = n;
}
void Subject::setNEasy(int n)
{
	nEasy = n;
}
void Subject::setNHard(int n)
{
	nHard = n;
}

void Subject::setHeadEasy(NodeSingleLL<string>* n)
{
	easy.setHead(n);
}
void Subject::setHeadHard(NodeSingleLL<string>* n)
{
	hard.setHead(n);
}

void Subject::setTailEasy(NodeSingleLL<string>* n)
{
	easy.setTail(n);
}
void Subject::setTailHard(NodeSingleLL<string>* n)
{
	hard.setTail(n);
}


//operator overloading
//this is for searching of required name of subject in avl
//the operations are wrt to alphabetical order
bool Subject::operator<(Subject& s)
{
	return (getName() < s.getName());
}

bool Subject::operator>(Subject& s)
{
	return (getName() > s.getName());
}

bool Subject::operator==(Subject& s)
{
	return (getName() == s.getName());
}

//operator overloading for printing
ostream& operator << (ostream& out, const Subject& s)
{
	out << s.name;
	return out;
}
