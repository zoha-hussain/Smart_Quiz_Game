#include <iostream>
#include <chrono>
#include <thread>
#include "Student.h"
#include "DoubleLL.h"
#include "Question.h"
using namespace std;

Student::Student() :User() {
	totalScore = 0;
}
Student::Student(string un, string p, string e, long long int c) :User(un, p, e, c) {
	totalScore = 0;
}

// for reading from file
Student::Student(string un, string p, string e, long long int c, int score, int* arr1, int* arr2) :User(un, p, e, c) {
	totalScore = score;
	for (int i = 0; i < 8; i++)
	{
		EasyAttempted[i] = arr1[i];
		HardAttempted[i] = arr2[i];
	}
}

Student::Student(string un, string p, string e, long long int c, int score) :User(un, p, e, c) {
	totalScore = score;
}

void Student::signup()
{
	bool verified = false;
	inputForSignup();
	checkLength();
	verifyingPassword();
	Student::InitializeVar();
}

void Student::InitializeVar()
{
	for (int i = 0; i < 8; i++)
	{
		EasyAttempted[i] = 0;
		HardAttempted[i] = 0;
	}
}

void Student::setTotalScore(int x) {
	totalScore = x;
}

void Student::IncrementTotalScore() {
	totalScore++;
}

void Student:: DecrementTotalScore() {
	totalScore--;
}
//getter
int Student::getTotalScore()const {
	return totalScore;
}

int* Student::getEasyAttempted() {
	return EasyAttempted;
}

int* Student::getHardAttempted() {
	return HardAttempted;

}

Student& Student::operator=(Student& other) {
	if (this != &other) { // Avoid self-assignment
		this->setUsername(other.getUsername());
		this->setPassword(other.getPassword());
		this->setContact(other.getContact());
		this->setEmail(other.getEmail());
		int* arr, * arr1;
		arr = other.getEasyAttempted();
		arr1 = other.getHardAttempted();
		this->setTotalScore(other.getTotalScore());
		for (int i = 0; i < 8; i++)
		{
			EasyAttempted[i] = arr[i];
			HardAttempted[i] = arr1[i];
		}
		/*In case this dont work,
		delete int* arr, arr1 and replace the for loop with
				for (int i = 0; i < 8; i++)
		{
			EasyAttempted[i] = other.EasyAttempted[i];
			HardAttempted[i] = other.HardAttempted[i];
		}
		*/
	}
	return *this;
}


ostream& operator<<(std::ostream& os, const Student& u)
{
	os << "Username: " << u.getUsername();
	return os;
}

void Student::openQuiz(Subject s[],class Student &st)
{

	int subject = inputSubject(s);
	int category = inputCategory();
	ifstream fin;

	//reading quiz data
	fin.open("Mathseasy1.txt");
	if (!fin.is_open())
	{
		cout << "Error! Could not read from questions file" << endl;
		return;
	}
	DoubleLL<Question> dll;
	while (!fin.eof()) {
		string question;
		getline(fin, question);
		string opt1, opt2;
		string options[2];
		getline(fin, opt1);
		getline(fin, opt2);
		options[0] = opt1;
		options[1] = opt2;
		char correctopt;
		fin >> correctopt;
		Question q(question, options, correctopt);
		dll.insertAtTail(q);
		getline(fin, question);
	}
	dll.printQuestions(dll.getHead(),st);
}