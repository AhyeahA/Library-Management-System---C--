#pragma once
#ifndef Catalog_hpp
#define Catalog_hpp
#include <fstream>
#include <vector>
#include "Book.h"
#include <iostream>
#include <string>
using namespace std;
class Catalog {
private:
	vector<Book> listofBooks;
	string filename;
public:
	Catalog(string filename) {
		this->filename = filename;
		ifstream f1(filename);
		if (f1.fail()) {
			cout << "Failed to open the file";
			exit(0);
		}
		Book tmp;
		string ISBN, title;
		f1 >> ISBN;
		getline(f1, title);
		tmp.setISBN(ISBN);
		tmp.setTitle(title);
		while (!f1.eof()) {
			listofBooks.push_back(tmp);
			f1 >> ISBN;
			getline(f1, title);
			tmp.setISBN(ISBN);
			tmp.setTitle(title);
		}
		f1.close();
	}
	//reads the content of the file and saves them in the vector of type book
	~Catalog() {
		ofstream f1(filename);
		if (f1.fail()) {
			cout << "Failed to open the file";
			exit(0);
		}
		for (int i = 0; i < listofBooks.size(); i++) {
			f1 << listofBooks[i].getISBN() << " " << listofBooks[i].getTitle() << endl;
		}
		f1.close();
		f1.flush();
	}
	//saves and prints out the conteent back to the same file
	void AddBook() {
		Book tmp;
		string ISBN, title;
		cin.ignore(1000, '\n');
		cout << "Enter Book's title to add to the list: " << endl;
		getline(cin, title);
		//check ig the person alrready exists in the system
		if (findTitle(title)) {
			cout << "This Book's Title already exists" << endl;

		}
		else {
			cout << "Enter the ISBN to add to the list: " << endl;
			cin >> ISBN;
			if (findISBN(ISBN)) {
				cout << "This Book's ISBN already exists" << endl;
			}
			else {
				tmp.setISBN(ISBN);
				tmp.setTitle(title);
				listofBooks.push_back(tmp);
			}
		}

	}
	//allows the user to add the book by title and ISBN, but checks if both the title and ISBN already exists
	string getBookISBN(int index) {
		return listofBooks[index].getISBN();
	}
	//returns ISBN at a given index
	int findBook(string target) {
		string b = make_lowerpunct(target);
		for (int i = 0; i < listofBooks.size(); i++) {
			string a = make_lowerpunct(listofBooks[i].getTitle());
			if (a.find(b) != -1)
				return i;
		}

		for (int i = 0; i < listofBooks.size(); i++) {
			if (listofBooks[i].getISBN() == target)
				return i;
		}
		return 0;
	}
	//returns index of the book's title or ISBN is found
	void listBook() {
		cout << "list of all books: " << endl;
		for (int i = 0; i < listofBooks.size(); i++) {
			cout << listofBooks[i].getTitle() << " " << listofBooks[i].getISBN() << endl;
		}
	}
	//prints out all the books in the catalog
	string getAt(int index) {
		string a = listofBooks[index].getTitle() + " " + listofBooks[index].getISBN();
		return a;

	}
	//returns book title and ISBN at given index
	bool findISBN(string target) {

		for (int i = 0; i < listofBooks.size(); i++) {
			if (listofBooks[i].getISBN() == target)
				return true;
		}
		return false;
	}
	//find ISBN if it exists
	bool findTitle(string target) {
		string b = make_lowerpunct(target);
		for (int i = 0; i < listofBooks.size(); i++) {
			string a = make_lowerpunct(listofBooks[i].getTitle());
			if (a.find(b) != -1)
				return true;
		}
		return false;
	}
	//returns true if given title exists or not
	string make_lowerpunct(string target) {
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
		temp[j] = '\0';
		return temp;
	}
	//convert all characters to lowercase
	//then deletes all spaces in the string
	//retuerns the new converted string
};
#endif // !Catalog_hpp
