#pragma once
#include <iostream>
#include "User.h"
#include "Subject.h"

using namespace std;

class Teacher : public User {

public:
	Teacher();
	Teacher(string un, string p, string e, long long int c);
	void signup();

	//functions for creating quiz
	void createQuiz(string);
	int inputNumberOfQuestions();
	void fileName(Subject[]);
	void InitializeVar();

};