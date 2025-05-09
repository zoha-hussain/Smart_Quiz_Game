#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>
#include <thread>
#include "Avl.h"
#include "nodeTree.h"
#include "NodeSingleLL.h"
#include "SingleLL.h"
#include "Subject.h"
#include "DoubleLL.h"
#include "NodeDoubleLL.h"
#include "Queue.h"
#include "Teacher.h"
#include "LeaderBoard.h"
using namespace std;

//----------------------------------------------------------------------------------------------------------------------------------------

//prototypes
int studentOrTeacher();
int singUpOrLogin();
void isStudent(int, Subject[8], Student&, AVLtree<Student>&);
void isTeacher(int, Subject[8], Teacher&, AVLtree<Teacher>&);
void writeSubjectsToFile(Subject[8]);
void readSubjectsFromFile(Subject[8]);
void inputStudentSubject(Subject[8]);
void writeStudentToFile(AVLtree<Student>& students);
void readStudentFromFile(LeaderBoard& l, AVLtree<Student>& bst);


//create quiz(input questions from user)


//----------------------------------------------------------------------------------------------------------------------------------------

//writing subject names with number of quizes in file

void writeSubjectsToFile(Subject s[8])
{
	ofstream fout;
	fout.open("Subjects.txt");
	if (!fout.is_open())
	{
		cout << "Error! Could not write to subjects file" << endl;
		return;
	}
	for (int i = 0; i < 8; i++)
	{
		fout << s[i].getName() << " " << s[i].getNEasy() << " " << s[i].getNHard() << endl;
		NodeSingleLL<string>* temp = s[i].getHeadEasy();
		while (temp)
		{
			fout << temp->data << " ";
			temp = temp->next;
		}
		fout << endl;
		temp = s[i].getHeadHard();
		while (temp)
		{
			fout << temp->data << " ";
			temp = temp->next;
		}
		fout << endl;
	}
	fout.close();
}

//----------------------------------------------------------------------------------------------------------------------------------------

//reading subject names with number of quizes from file

void readSubjectsFromFile(Subject s[8])
{
	ifstream fin;
	fin.open("Subjects.txt");
	if (!fin.is_open())
	{
		cout << "Error! Could not read from subjects file" << endl;
		return;
	}
	for (int i = 0; i < 8; i++)
	{
		string name;
		int nEasy;
		int nHard;
		SingleLL<string> easy;
		SingleLL<string> hard;

		//first line contains subject name and no of quizzes
		string line;
		getline(fin, line);
		istringstream str(line);
		str >> name >> nEasy >> nHard;

		//next line contains name of easy quizzes
		getline(fin, line);
		for (int i = 1; i <= nEasy; i++)
		{
			int p1;
			int p2 = line.find(i + 48);
			if (i != 1)
				p1 = line.find(i - 1 + 48);
			else p1 = -2;
			string quizName = line.substr(p1 + 2, p2 + 1);
			easy.insertAtTail(quizName);
		}

		//next line contains name of hard quizzes
		getline(fin, line);
		for (int i = 1; i <= nHard; i++)
		{
			int p1;
			int p2 = line.find(i + 48);
			if (i != 1)
				p1 = line.find(i - 1 + 48);
			else p1 = -1;
			string quizName = line.substr(p1 + 1, p2 + 1);
			hard.insertAtTail(quizName);
		}
		s[i].setName(name);
		s[i].setNEasy(nEasy);
		s[i].setNHard(nHard);
		s[i].setHeadEasy(easy.getHead());
		s[i].setTailEasy(easy.getTail());
		s[i].setHeadHard(hard.getHead());
		s[i].setTailHard(hard.getTail());

	}
	fin.close();
}

//----------------------------------------------------------------------------------------------------------------------------------------

//write students signup/login info

void writeStudentToFile(AVLtree<Student>& students)
{
	ofstream fout("Student.txt", ofstream::out | ofstream::trunc); // Open in truncation mode

	if (!fout.is_open())
	{
		cout << "Error! Could not write to students file" << endl;
		return;
	}
	int* arr1, * arr2;
	Queue<NodeTree<Student>, Student> q;
	q.Enqueue(students.getRoot());
	while (!q.isEmpty()) {
		NodeTree<Student>* current = q.Dequeue();
		fout << current->data.getUsername() << " " << current->data.getPassword() << " " << current->data.getEmail() << " " << current->data.getContact() << " ";
		arr1 = current->data.getEasyAttempted();
		arr2 = current->data.getHardAttempted();
		for (int i = 0; i < 8; i++)
		{
			fout << arr1[i] << " ";
			fout << arr2[i] << " ";
		}
		fout << endl;
		if (current->left != NULL)
			q.Enqueue(current->left);
		if (current->right != NULL)
			q.Enqueue(current->right);
	}
	fout.close();
}

void readStudentFromFile(LeaderBoard& l, AVLtree<Student>& bst)
{
	ifstream fin;
	fin.open("Student.txt");
	if (!fin.is_open())
	{
		cout << "Error! Could not read from student file" << endl;
		return;
	}
	string line;

	while (getline(fin, line)) {
		istringstream str(line);
		string name;
		string password;
		string email;
		long long int contact;
		int totalScore;
		int arr1[8], arr2[8];

		str >> name >> password >> email >> contact >> totalScore;

		for (int i = 0; i < 8; i++) {
			str >> arr1[i] >> arr2[i];
		}

		Student a(name, password, email, contact, totalScore, arr1, arr2);
		bst.setRoot(bst.insert(bst.getRoot(), a));
		l.Insert(a);
	}
}

//signing in to application

int studentOrTeacher()
{
	int choice;
	cout << "How do you want to use this application?" << endl << "1) As a Student" << endl << "2) As a Teacher" << endl << "Enter corresponding number: ";
	cin >> choice;
	while (choice != 1 && choice != 2)
	{
		cout << "Please enter 1 or 2: ";
		cin >> choice;
	}
	return choice;
}

int singUpOrLogin()
{
	int choice;
	cout << "Do you want to" << endl << "1) Signup" << endl << "2) Login" << endl << "Enter corresponding number:";
	cin >> choice;
	while (choice != 1 && choice != 2)
	{
		cout << "Please enter 1 or 2: ";
		cin >> choice;
	}
	return choice;
}

void isStudent(int choice, Subject subjects[8], Student& S_User, AVLtree<Student>& Students)
{
	Student s;
	if (choice == 1)
	{
		s.signup();
		Students.setRoot(Students.insert(Students.getRoot(), s));
		system("cls");
	}
	S_User = Students.login()->data;
	s.openQuiz(subjects,s);
}

void isTeacher(int choice, Subject subjects[8], Teacher& T_User, AVLtree<Teacher>& Teachers)
{
	Teacher t;
	if (choice == 1)
	{
		t.signup();
		Teachers.setRoot(Teachers.insert(Teachers.getRoot(), t));
		system("cls");
	}
	T_User = Teachers.login()->data;
	t.fileName(subjects);
}


int main() {
	AVLtree <Student> Students;
	AVLtree <Teacher> Teachers;
	LeaderBoard l;
	Student S_User;
	Teacher T_User;
	Subject subjects[8];

	readSubjectsFromFile(subjects);

	int userType = studentOrTeacher();
	int signInChoice = singUpOrLogin();
	if (userType == 1)
	{
		readStudentFromFile(l, Students);
		isStudent(signInChoice, subjects, S_User, Students);
	}
	else
	{
		//readTeacherFromFile(l, Students);
		isTeacher(signInChoice, subjects, T_User, Teachers);
	}

	//final rewriting and closing of files 
	if (userType == 1)
	{
		writeStudentToFile(Students);
	}
	else
	{
		//write to file in this section
	}
	return 0;
}