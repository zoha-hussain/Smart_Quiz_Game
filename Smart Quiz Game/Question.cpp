#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include "Question.h"
using namespace std;

//constructors
Question::Question(string q, string o[2], char c)
{
	question = q;
	for (int i = 0; i < 2; i++)
		options[i] = o[i];
	correct = c;
}

//getters
string Question::getQuestion()const
{
	return question;
}

char Question::getCorrectOption()const
{
	return correct;
}

string Question::getOption1()
{
	return options[0];
}

string Question::getOption2()
{
	return options[1];
}

//setters
void Question::setQuestion(const string q)
{
	question = q;
}

void Question::setOptions(const string o[2])
{
	for (int i = 0; i < 2; i++)
		options[i] = o[i];
}

void Question::setCorrectOption(const char c)
{
	correct = c;
}

//printing
ostream& operator << (ostream& out, const Question& q)
{
	cout << endl << q.question << endl;
	cout << "a) " << q.options[0] << "\t\tb) " << q.options[1] << endl;
	return out;
}

bool Question::operator==(char selectedOption) const
{
	return (selectedOption == correct);
}

//input question from user
void Question::inputQuestion()
{
	cout << "Enter question: ";
	cin.ignore();
	getline(cin, question);
	for (int i = 0; i < 2; i++)
	{
		cout << "Enter option number " << i + 1 << ": ";
		getline(cin, options[i]);
	}
	cout << "Enter correct option, a or b: ";
	cin >> correct;
	while (correct != 'a' && correct != 'b')
	{
		cout << "Please enter either a or b:";
		cin >> correct;
	}
}