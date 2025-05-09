#pragma once
#include <iostream>
#include <chrono>
#include <thread>
#include "Student.h"
#include "NodeDoubleLL.h"
using namespace std;

const int TOTAL_QUIZ_DURATION = 10;

template <typename T>
class DoubleLL
{
private:
	NodeDoubleLL<T>* head;
	NodeDoubleLL<T>* tail;
public:
	//constructors
	DoubleLL()
	{
		head = NULL;
		tail = NULL;
	}
	DoubleLL(NodeDoubleLL<T>* h, NodeDoubleLL<T>* t)
	{
		head = h;
		tail = t;
	}
	DoubleLL(const DoubleLL& l)
	{
		head = NULL;
		tail = NULL;
		NodeDoubleLL<T>* temp = l.head;
		while (temp != NULL)
		{
			insertAtTail(temp->data);
			temp = temp->next;
		}
	}
	//getters
	NodeDoubleLL<T>* getHead()
	{
		return head;
	}
	NodeDoubleLL<T>* getTail()
	{
		return tail;
	}
	//setters
	void setHead(NodeDoubleLL<T>* h)
	{
		head = h;
	}
	void setTail(NodeDoubleLL<T>* t)
	{
		tail = t;
	}

	//insertion
	void insertAtHead(T n)
	{
		if (head == NULL) {
			NodeDoubleLL<T>* newnode = new NodeDoubleLL<T>(n);
			head = newnode;
			tail = newnode;
			return;
		}
		NodeDoubleLL<T>* newnode = new NodeDoubleLL<T>(n);
		NodeDoubleLL<T>* temp = head;
		newnode->next = temp;
		temp->prev = newnode;
		head = newnode;
	}
	void insertAtTail(T n)
	{
		NodeDoubleLL<T>* newnode = new NodeDoubleLL<T>(n);
		if (head == NULL) {
			head = newnode;
			tail = newnode;
			return;
		}
		NodeDoubleLL<T>* temp = tail;
		tail->next = newnode;
		newnode->prev = tail;
		newnode->next = NULL;
		tail = newnode;
	}
	//deletion
	void deleteAtHead()
	{
		if (!head) {
			cout << "List is already empty." << endl;
			return;
		}
		NodeDoubleLL<T>* temp = head;
		head = head->next;
		if (head) {
			head->prev = NULL;
		}
		else {
			tail = NULL;
		}
		delete temp;
	}
	void deleteAtTail()
	{
		if (!tail) {
			cout << "List is already empty." << endl;
			return;
		}
		NodeDoubleLL<T>* temp = tail;
		tail = tail->prev;
		if (tail) {
			tail->next = NULL;
		}
		else {
			head = NULL;
		}
		delete temp;
	}
	//printing
	void printQuestions(NodeDoubleLL<T>* temp, Student& st)
	{
		if (temp == NULL) {
			cout << "End of Questions." << endl;
			return;
		}

		auto quizStartTime = std::chrono::steady_clock::now(); // Record the start time of the entire quiz
		int numQuestions = 0;
		cout << endl << "Total time to attempt the quiz is 10 Seconds" << endl;
		while (true) {
			if (temp != NULL) {
				auto questionStartTime = std::chrono::steady_clock::now(); // Record the start time of each question

				// Display the question
				cout << temp->data; // Assuming NodeDoubleLL has an appropriate << operator

				while (true) {
					auto currentTime = std::chrono::steady_clock::now();
					auto elapsedTime = std::chrono::duration_cast<std::chrono::seconds>(currentTime - questionStartTime);

					int remainingTime = TOTAL_QUIZ_DURATION - elapsedTime.count();

					if (remainingTime <= 0) {
						cout << "Timeout for the entire quiz! Moving to the next question." << endl;
						break;
					}

					int c = choice();
					char selectedOption;

					if (c == 1) {
						cout << "Enter the Correct Option (a/A or b/B): " << endl;
						cin >> selectedOption;

						if (temp->data == selectedOption) {
							st.IncrementTotalScore();
						}
						else {
							st.DecrementTotalScore();
						}
						if (temp->next == NULL) {
							cout << endl << "There is no next Question." << endl;
							break;
						}
						else temp = temp->next;
						break; // Break the loop when an answer is provided
					}
					else if (c == 2) {
						if (temp->prev == NULL) {
							cout << endl << "There is no Previous Question." << endl;
							break;
						}
						else {
							cout << endl << "Moving to the previous question." << endl;
							temp = temp->prev;
							break;
						}
					}
					else if (c == 3) {
						if (temp->next == NULL) {
							cout << endl << "There is no next Question." << endl;
							break;
						}
						else {
							cout << endl << "Moving to the next question." << endl;
							temp = temp->next;
							break;
						}
					}
					else {
						cout << "Invalid Choice!!" << endl;
					}
				}
			}

			++numQuestions;

			// Check total quiz duration
			auto currentTime = std::chrono::steady_clock::now();
			auto elapsedTime = std::chrono::duration_cast<std::chrono::seconds>(currentTime - quizStartTime);

			if (elapsedTime.count() >= TOTAL_QUIZ_DURATION) {
				cout << endl << "Total time for the quiz has elapsed after " << numQuestions << " questions." << endl;
				break;
			}
			system("cls");
		}


		int score = st.getTotalScore();
		cout << endl << "TOTAL SCORE: " << score << endl;
	}

	int choice() {
		int Choice;
		cout << endl << "Please enter the respective number, what do you want to do:" << endl << "1. Answer" << endl << "2. Prev Question" << endl << "3. Next Question" << endl;
		cin >> Choice;
		return Choice;
	}

};
