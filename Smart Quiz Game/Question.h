#pragma once
#include <iostream>
using namespace std;

class Question
{
private:
	string question;
	string options[2];
	char correct;
public:
	//constructors
	Question() {};
	Question(string, string[2], char);

	//getters
	string getQuestion()const;
	char getCorrectOption()const;
	string getOption1();
	string getOption2();

	//setters
	void setQuestion(const string);
	void setOptions(const string[2]);
	void setCorrectOption(const char);

	//printing
	friend ostream& operator << (ostream& out, const Question& s);

	//compare
	bool operator==(char) const;

	//input question from user
	void inputQuestion();
};