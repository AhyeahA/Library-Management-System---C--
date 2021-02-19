#pragma once
#ifndef ReadershipList_hpp
#define ReadershipList_hpp
#include "Borrower.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class ReadershipList {
private:
	vector<Borrower> listofBorrowers;
	string filename;
public:
	ReadershipList(string filename) {
		this->filename = filename;
		ifstream f1(filename);
		if (f1.fail()) {
			cout << "Failed to open the file";
			exit(0);
		}
		Borrower tmp;
		string Name, ID;
		f1 >> ID;
		getline(f1, Name);
		tmp.setID(ID);
		tmp.setName(Name);
		while (!f1.eof()) {
			listofBorrowers.push_back(tmp);
			f1 >> ID;
			getline(f1, Name);
			tmp.setID(ID);
			tmp.setName(Name);
		}
		f1.close();
	}
	//passes the name of the filename
	//reads the content of the file
	//saves the Name and ID of the borrower in a vector
	~ReadershipList() {
		ofstream f1(filename);
		if (f1.fail()) {
			cout << "Failed to open the file";
			exit(0);
		}
		for (int i = 0; i < listofBorrowers.size(); i++) {
			f1 << listofBorrowers[i].getID() << " " << listofBorrowers[i].getName() << endl;
		}
		f1.close();
		f1.flush();
	}
	//prints out the content of the borrower back to the same file
	int findBorrower(string target) {
		string b = make_lowerNopunct(target);
		for (int i = 0; i < listofBorrowers.size(); i++) {
			string a = make_lowerNopunct(listofBorrowers[i].getName());
			if (a.find(b) != -1)
				return i;
		}

		for (int i = 0; i < listofBorrowers.size(); i++) {
			if (listofBorrowers[i].getID() == target)
				return i;
		}
		return 0;
	}
	//returns the index of the name or ID of the borrower

	void listBorrowers() {
		cout << "List of the borrower's names and IDs: " << endl;
		for (int i = 0; i < listofBorrowers.size(); i++) {
			cout << listofBorrowers[i].getName() << " " << listofBorrowers[i].getID() << endl;
		}
	}
	//prints out all the borrower's ID's and Names to the console

	string PrintgetAt(int index) {
		string a = listofBorrowers[index].getID() + " " + listofBorrowers[index].getName();
		return a;
	}
	//ptints out student ID and name at specific index

	string getID(int index) {
		return listofBorrowers[index].getID();
	}
	//returns th eID of the student at a specific index

	bool findID(string target) {
		for (int i = 0; i < listofBorrowers.size(); i++) {
			if (listofBorrowers[i].getID() == target)
				return true;
		}
		return false;
	}
	//returns true if th eID matches the user input, false otherwise

	bool findName(string target) {
		string b = make_lowerNopunct(target);
		for (int i = 0; i < listofBorrowers.size(); i++) {
			string a = make_lowerNopunct(listofBorrowers[i].getName());
			if (a.find(b) != -1)
				return true;
		}
		return false;
	}
	//returns true if there is a name that matches the user input, false otherwise

	string make_lowerNopunct(string target) {
		string temp(target);
		for (int i = 0; i < target.length(); i++) {
			temp[i] = tolower(target[i]);
		}

		int i = 0, j = 0;
		while (temp[i]) {
			if (temp[i] != ' ')
				temp[j++] = temp[i];
			i++;
		}

		return temp;
	}
	//converts the characters to lowercase
	//then deletes all o fthe spaces in the string
	//returns the new converted string

	void AddBorrower() {
		cin.ignore(1000, '\n');
		Borrower tmp;
		string ID, Name;
		cout << "Enter name to add to the list: " << endl;
		getline(cin, Name);

		//check if person's name already exists in the system
		if (findName(Name)) {
			cout << "This person's name already exists " << endl;
		}
		else {
			cout << "Enter ID to add  to the list: " << endl;
			cin >> ID;
			cin.ignore(1000, '\n');
			if (findID(ID)) {
				cout << "The person's ID already exists" << endl;
			}
			else {
				tmp.setID(ID);
				tmp.setName(Name);
				listofBorrowers.push_back(tmp);
			}
		}
	}
	//adds a borrower's name and ID from the user unput
	//checks if the user's name or ID already exists
};
#endif // !ReadershipList_hpp
