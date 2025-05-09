#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include "User.h"

using namespace std;

class Student : public User {
private:

	int totalScore;
	int EasyAttempted[8];
	int	HardAttempted[8];
public:
	//constructors
	Student();

	Student(string un, string p, string e, long long int c);

	Student(string un, string p, string e, long long int c, int score);

	// for reading from file
	Student(string un, string p, string e, long long int c, int score, int* arr1, int* arr2);

	void signup();

	//setter
	void setTotalScore(int);
	//getter
	int getTotalScore()const;
	//update score
	void IncrementTotalScore();
	void DecrementTotalScore();

	int* getEasyAttempted();

	int* getHardAttempted();

	//operator overloading
	Student& operator=(const Student&);
	Student& operator=(Student&);
	friend ostream& operator<<(std::ostream& os, const Student& u);

	//open quiz for user to complete
	void openQuiz(Subject[], class Student& s);

	void InitializeVar();
};