#pragma once
#include<iostream>
#include"Subject.h"
using namespace std;


class User {
	//attributes
	string email;
	string username;
	long long int contact;
	string password;
	//default constructor
public:
	//constructors
	User();

	//For reading data from the file
	User(string un, string p, string e, long long int c);

	//checking if password fulfils conditions
	void checkConditions(int length);

	//input userdata for signup
	void inputForSignup();

	//checking if password has desired length
	void checkLength();

	//verifying password
	void verifyingPassword();

	//allowing password to appear as * on screen
	void mask(string& array);

	//operator overloading
	bool operator==(const User& other) const;

	bool operator>(const User& other) const;

	bool operator<(const User& other) const;

	friend ostream& operator<<(std::ostream& os, const User& u);

	// getters/accessors of attributes
	// no accessor for password, as it must not be accessible
	string getEmail()const;

	string getUsername()const;

	string getPassword() const;

	long long int getContact()const;

	// setter/mutator functions
	void setEmail(string e);

	void setUsername(string un);

	void setContact(const long long int c);

	void setPassword(string p);

	//for conducting/creating quiz
	int inputCategory();
	int inputSubject(Subject[8]);
};