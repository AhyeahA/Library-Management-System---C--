#pragma once
#ifndef Borrower_hpp
#define Borrower_hpp
#include <iostream>
using namespace std;
class Borrower {
private:
	string ID, name;
public:
	Borrower() {
		name = "";
		ID = "";
	}
	//default construnctor that sets the ID and anme as empty string
	Borrower(string x, string y) {
		name = x;
		ID = y;
	}
	//non default constructor that assigns the ID and Name
	string getID() {
		return ID;
	}
	//returns the ID of the borrower
	string getName() {
		return name;
	}
	//returns the name of the borrower
	void setName(string name) {
		this->name = name;
	}
	//assigns a name
	void setID(string id) {
		this->ID = id;
	}
	//assigns an ID
};
#endif // !Borrower_hpp
