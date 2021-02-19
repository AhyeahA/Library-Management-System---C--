#pragma once
#ifndef Loan_hpp
#define Loan_hpp
#include <iostream>
using namespace std;

class Loan {
private:
	string ID, ISBN;
	bool available;
public:
	Loan() {
		ID = "";
		ISBN = "";
		available = true;
	}
	Loan(string x, string y, bool available) {
		ID = x;
		ISBN = y;
		if (available == true) {
			this->available = true;
		}
		else {
			available = false;
		}
	}

	string getISBN() {
		return ISBN;
	}

	string getID() {
		return ID;
	}

	bool getAvailable() {
		return available;
	}

	void setID(string id) {
		this->ID = id;
	}

	void setISBN(string isbn) {
		this->ISBN = isbn;
	}

	void setAvailable(bool a) {
		available = a;
	}

	string isAvailable() {
		if (available)
			return "has been returned";
		else
			return "has not been returned yet";
	}

};
#endif // !Loan_hpp
