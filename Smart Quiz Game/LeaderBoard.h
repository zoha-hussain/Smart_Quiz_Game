#include < iostream>
#include <vector>
#include "Student.h"

class LeaderBoard {
public:
	vector <Student> LeaderBoard;
	void swap(Student& a, Student& b)
	{
		Student temp = a;
		a = b;
		b = temp;
	}
	int ReturnGreater(int index)
	{
		int rightchild = (index * 2 + 2);
		int leftchild = (index * 2 + 1);
		int size = LeaderBoard.size();
		if (rightchild < size) {
			if (LeaderBoard[leftchild].getTotalScore() > LeaderBoard[rightchild].getTotalScore())
				return leftchild;
			else if (LeaderBoard[leftchild].getTotalScore() < LeaderBoard[rightchild].getTotalScore())
				return rightchild;
			else
				return -1;
		}
		else if (leftchild == size - 1)
		{
			return leftchild;
		}
		else
			return -1;
	}
	void Insert(Student s) {
		LeaderBoard.push_back(s);
		for (int i = LeaderBoard.size() - 1; i > 0; (i /= 2))
		{
			if (LeaderBoard[i].getTotalScore() > LeaderBoard[(i - 1) / 2].getTotalScore()) {
				swap(LeaderBoard[i], LeaderBoard[(i - 1) / 2]);
			}
			i--;
		}
	}
	Student Delete() {
		int size = LeaderBoard.size();
		Student temp = LeaderBoard[0];
		swap(LeaderBoard[0], LeaderBoard[(size - 1)]);
		LeaderBoard.pop_back();
		size = LeaderBoard.size();
		int greaterIndex;
		for (int i = 0; i < (size - 1) / 2 && i >= 0;) {
			greaterIndex = ReturnGreater(i);
			if (greaterIndex != -1)
			{
				if (LeaderBoard[i].getTotalScore() < LeaderBoard[greaterIndex].getTotalScore())
					swap(LeaderBoard[i], LeaderBoard[greaterIndex]);
			}
			i = greaterIndex;
		}
		return temp;
	}

	//Printing LeaderBoard
	void Print() {
		int size = LeaderBoard.size();
		for (int i = 0; i < size; i++)
		{
			cout << i + 1 << ". " << Delete().getUsername() << endl;
		}
	}
};