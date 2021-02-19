#pragma once
#ifndef ListofLoans_hpp
#define ListofLoans_hpp
#include "Loan.h"
#include "Catalog.h"
#include "ReadershipList.h"
#include <fstream>
#include <string>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class ListofLoans {
private:
	vector<Loan> list;
	string filename;
public:
	ListofLoans(string filename) {
		this->filename = filename;
		ifstream f1(filename);
		if (f1.fail()) {
			cout << "Failed to open the file" << endl;
			exit(0);
		}
		Loan tmp;
		string ID, ISBN;
		bool av = true;
		f1 >> ID >> ISBN >> av;
		tmp.setISBN(ISBN);
		tmp.setID(ID);
		tmp.setAvailable(av);
		while (!f1.eof()) {
			list.push_back(tmp);
			f1 >> ID >> ISBN >> av;
			tmp.setISBN(ISBN);
			tmp.setID(ID);
			tmp.setAvailable(av);
		}
		f1.close();
	}

	void listAllLoans(Catalog& books, ReadershipList& Student) {
		//print out all books
		cout << "Loans (Borrower's name and ID, Book Title and ISBN, returned or unreturned" << endl;
		for (int i = 0; i < list.size(); i++) {
			cout << Student.PrintgetAt(i) << "has" << "\"" << books.getAt(i) << "\"  and " << list[i].isAvailable() << endl;

		}
	}

	void listActiveLoans(Catalog& books, ReadershipList& Student) {
		//returns a list of unreturned
		cout << "List information about unreturned books: " << endl;

		for (int i = 0; i < list.size(); i++) {
			if (list[i].getAvailable() == false)
				cout << list[i].getID() << Student.PrintgetAt(i) << " has " << books.getAt(i) << " and " << list[i].isAvailable() << endl;
		}
	}

	void LoanABook(ReadershipList& Student, Catalog& Book) {
		string target, target2;
		int index = 0, index2 = 0;
		Loan tmp;
		cin.ignore(1000, '\n');
		cout << "Enter ID or name: " << endl;
		getline(cin, target);
		if (Student.findName(target) || Student.findID(target)) {
			index = Student.findBorrower(target);
			cout << "Enter the book ID or Title you would like to borrow: " << endl;
			getline(cin, target2);
			for (int i = 0; i < list.size(); i++) {
				if (list[i].getISBN() == Book.getBookISBN(index2)) {
					if (!list[i].getAvailable()) {
						cout << "This book is not available to be borrowed" << endl;
						break;
					}
					else {
						tmp.setID(Student.getID(index));
						tmp.setISBN(Book.getBookISBN(index2));
						tmp.setAvailable(false);
						list.push_back(tmp);
						break;
					}
				}
				else {
					cout << "INVALID INPUT!! BOOK/ISBN DOES NOT EXIST!!" << endl;
				}
			}
		}
		else {
			cout << "INVALID INPUT!! Name/ID DOES NOT EXIST" << endl;
		}
		tmp.setID(Student.getID(index));
		tmp.setISBN(Book.getBookISBN(index2));
		tmp.setAvailable(false);
		list.push_back(tmp);
	}

	void returnABook(ReadershipList& Student, Catalog& Book) {
		string target, target2;
		int index = 0, index2 = 0;
		cin.ignore(1000, '\n');
		cout << "Enter ID or name: " << endl;
		getline(cin, target);
		if (Student.findName(target) || Student.findID(target)) {
			index = Student.findBorrower(target);
		}
		else {
			cout << "INVALID INPUT!! Name/ID DOES NOT EXIST" << endl;
		}
		int counter = 0;
		for (int i = 0; i < list.size(); i++) {
			//check if the borrower has borrowed a book
			if (list[i].getID() != Student.getID(index)) {
				counter++;
			}
		}
		if (counter == list.size()) {
			cout << Student.PrintgetAt(index) << "has never borrowed a book from the library.";
		}
		else {
			cout << "Enter the book ID or Title you would like to borrow: " << endl;
			getline(cin, target2);
			for (int i = 0; i < list.size(); i++) {
				if (list[i].getISBN() == Book.getBookISBN(index2)) {
					//checks if the borrower at this index of the list vector matches the book the user entered
					if (!list[i].getAvailable()) {
						cout << "This book is not available to be borrowed" << endl;
						break;
					}
					else {
						cout << "This book has already been returned" << endl;
					}
				}
				else {
					cout << "INVALID INPUT!! BOOK/ISBN DOES NOT EXIST!!" << endl;
				}
			}



		}
	}

	~ListofLoans() {
		ofstream f1(filename);
		if (f1.fail()) {
			cout << "Failed to open file" << endl;
			exit(0);
		}
		for (int i = 0; i < list.size(); i++) {
			f1 << list[i].getID() << " " << list[i].getISBN() << " " << list[i].getAvailable() << endl;
		}

		f1.close();
		f1.flush();


	}
};
#endif // !ListofLoans_hpp
