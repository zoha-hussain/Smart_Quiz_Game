#include<iostream>
#include<Windows.h>
#include "User.h"

using namespace std;

User::User() {
	contact = 0;
}

//For reading data from the file
User::User(string un, string p, string e, long long int c) {
	email = e;
	username = un;
	password = p;
	contact = c;
}
void User::inputForSignup() {
	cout << "Enter email:";
	cin >> email;
	cout << "Enter contact:";
	cin >> contact;
	cout << "Enter Username:";
	cin >> username;
	cout << "----------------------------------------------------------------------------------------" << endl;
	//HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	//SetConsoleTextAttribute(h, 14);
	cout << "Enter Password, Such That it Contains 8 to 16 Characters.It Should Include:" << endl;
	cout << "Uppercase Characters;" << endl << "Lowercase Characters;" << endl;
	cout << "Numbers;" << endl << "& Special Symbols." << endl << "It should not include:" << endl;
	cout << "Tabs or" << endl << "Spaces:" << endl;
	mask(password);
}


void User::checkConditions(int length) {
	int i;
	int upper = 0, lower = 0, sym = 0, num = 0; //Upper:Uppercase Letter; Lower:lowercase letter;Sym:Symbol;Num=Number
	while (num == 0 || upper == 0 || sym == 0 || lower == 0) {    //Checking if Password Satisfies Conditions or Not
		for (i = 0; i < length; i++) {
			if (password[i] >= 'a' && password[i] <= 'z')
				lower = 1;
			else if (password[i] >= 'A' && password[i] <= 'Z')
				upper = 1;
			else if (password[i] >= '0' && password[i] <= '9')
				num = 1;
			else sym = 1;
			if (i == length - 1) {
				if (num == 0 || upper == 0 || sym == 0 || lower == 0) {
					cout << endl << "Conditions for Password Unsatisfied." << endl;
					if (num == 0)
						cout << endl << "You Did Not Include Any Numbers." << endl;
					else if (sym == 0)
						cout << endl << "You Did Not Include Any Symbols." << endl;
					else if (lower == 0)
						cout << endl << "You Did Not Include Any Lowercase Letters." << endl;
					else if (upper == 0)
						cout << endl << "You Did Not Include Any Uppercase Letters." << endl;
					cout << endl << "Re-Enter a Password which Fulfills the Conditions:" << endl;
					mask(password);
					length = password.length();
				}
			}
		}
	}
}

void User::checkLength() {
	int length;
	length = password.length();
	while (length < 8 || length>16) {   //If Password is Not in Range, Then Input Password Again
		if (length < 8) {
			cout << endl << "Password too Short!Re-Enter:" << endl;
			mask(password);
		}
		else if (length > 16) {
			cout << endl << "Password too Long!Re-Enter:" << endl;
			mask(password);
		}
		length = password.length();
	}
	//once length is appropriate, checking other conditions
	checkConditions(length);
}

void User::verifyingPassword() {
	bool verified = false;
	static int attempts = 0;
	string verify;
	cout << endl << "Kindly Re - Enter Your Password for Confirmation:";
	mask(verify);
	while (!verified) {
		if (verify != password) {   //If the 2 Passwords are Different
			while (verify != password) {
				attempts++;
				if (attempts <= 3) {
					cout << endl << "The 2 Passwords Do Not Match! Kindly Re-Enter Your Password:";
					mask(verify);
				}
				else {
					cout << endl << "You were unable to verify password in 3 attempts.";
					cout << "Account locked. Try Again later!";
					cout << "Exiting application...";
					verified = false;
					exit(1);
				}
			}
		}
		else {
			if (verify == password) {   //If the 2 Passwords are matching
				cout << endl << "Account Created Successfully!" << endl;
				verified = true;
			}

		}
	}
}

void User::mask(string& array) {
	cin >> array;

	for (int i = 0; array[i] != '\0'; i++) {
		if (array[i] == ' ')
			cin >> array;
		else if (array[i] == '	')
			cin >> array;
	}

}

bool User::operator==(const User& other) const
{
	if (username == other.getUsername()) {
		if (password == other.getPassword())
			return true;
		else
			return false;
	}
	else
		return false;
}

bool User::operator>(const User& other) const {
	return username > other.getUsername();
}

bool User::operator<(const User& other) const {
	return username < other.getUsername();
}

// getters/accessors of attributes
// no accessor for password, as it must not be accessible
string User::getEmail()const {
	return email;
}

string User::getUsername()const {
	return username;
}

long long int User::getContact()const {
	return contact;
}

string User::getPassword()const {
	return password;
}

// setter/mutator functions
//no mutator for password, as it must not be changed
void User::setEmail(string e) {
	email = e;
}

void User::setUsername(string un) {
	username = un;
}


void User::setContact(const long long int c) {
	contact = c;
}

void User::setPassword(string p) {
	password = p;
}

ostream& operator<<(std::ostream& os, const User& u)
{
	os << "Username: " << u.username;
	return os;
}


int User::inputCategory()
{
	int choice;
	cout << "Enter 1 for easy quiz and 2 for hard quiz: ";
	cin >> choice;
	while (choice != 1 && choice != 2)
	{
		cout << "Please enter either 1 or 2: ";
		cin >> choice;
	}
	return choice;
}

int User::inputSubject(Subject s[8])
{
	int subject;
	cout << "Following subjects are available for quizzes:" << endl;
	for (int i = 0; i < 8; i++)
		cout << i + 1 << ") " << s[i].getName() << endl;
	cout << endl << "Enter corresponding number: ";
	cin >> subject;
	while (subject < 1 || subject>8)
	{
		cout << "Please enter valid number between 1 and 8: ";
		cin >> subject;
	}
	return subject;

}