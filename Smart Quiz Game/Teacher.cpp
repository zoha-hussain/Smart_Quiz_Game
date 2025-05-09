#include <iostream>
#include <fstream>
#include <sstream>
#include "User.h"
#include "Teacher.h"
#include "Question.h"


Teacher::Teacher() :User()
{

}

Teacher::Teacher(string un, string p, string e, long long int c) :User(un, p, e, c) {}

//input subject and category for making quiz
int Teacher::inputNumberOfQuestions()
{
	int questions;
	cout << "Enter number of questions. They should be greater than(or equal to) 2 and less than(or equal to) 15: ";
	cin >> questions;
	while (questions < 2 && questions >15)
	{
		cout << "Please enter valid number of questions: ";
		cin >> questions;
	}
	return questions;
}

void Teacher::signup()
{
	bool verified = false;
	inputForSignup();
	checkLength();
	verifyingPassword();
	InitializeVar();
}

void Teacher::InitializeVar()
{

}
void Teacher::fileName(Subject s[8])
{
	int subject = inputSubject(s);
	int category = inputCategory();
	if (category == 1)
	{
		SingleLL<string> l(s[subject - 1].getHeadEasy(), s[subject - 1].getTailEasy());
		s[subject - 1].setNEasy(s[subject - 1].getNEasy() + 1);
		char quizNum = 48 + s[subject - 1].getNEasy();
		string quizName = s[subject - 1].getName() + "easy" + quizNum;
		l.insertAtTail(quizName);
		s[subject - 1].setHeadEasy(l.getHead());

		createQuiz(quizName);
	}
	else
	{
		SingleLL<string> l(s[subject - 1].getHeadHard(), s[subject - 1].getTailHard());
		s[subject - 1].setNHard(s[subject - 1].getNHard() + 1);
		char quizNum = 48 + s[subject - 1].getNHard();
		string quizName = s[subject - 1].getName() + "hard" + quizNum;
		l.insertAtTail(quizName);
		s[subject - 1].setHeadHard(l.getHead());
		createQuiz(quizName);
	}
}

void Teacher::createQuiz(string quizName)
{
	//create array of questions 
	int questionNumber = inputNumberOfQuestions();
	cout << endl << "Taking input for " << questionNumber << " questions! You must enter question statement, 2 options and 1 correct option!";
	SingleLL<Question> questions;
	for (int i = 0; i < questionNumber; i++)
	{
		cout << endl << endl << "Input for question " << i + 1 << ": " << endl;
		Question q;
		q.inputQuestion();
		questions.insertAtTail(q);
	}

	//now, after taking input, create file for this quiz
	string fileName = quizName + ".txt";
	ofstream fout;
	fout.open(fileName);
	if (!fout.is_open())
	{
		cout << "Error! Could not create file for quiz." << endl;
		return;
	}
	NodeSingleLL<Question>* traverse = questions.getHead();
	while (traverse)
	{
		fout << traverse->data.getQuestion() << endl;
		fout << traverse->data.getOption1() << endl;
		fout << traverse->data.getOption2() << endl;
		fout << traverse->data.getCorrectOption() << endl;
		traverse = traverse->next;
	}
	fout.close();
}