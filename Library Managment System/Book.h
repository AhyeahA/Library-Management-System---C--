#pragma once
#ifndef Book_hpp
#define Book_hpp
#include <iostream>
using namespace std;
class Book {
private:
	string ISBN, title;
public:
	Book() {
		ISBN = "";
		title = "";
	}
	//assigns the ISBN and Title to empty Strings
	Book(string x, string y) {
		title = x;
		ISBN = y;
	}
	//assigns the ISBN and title to x and y
	string getISBN() {
		return ISBN;
	}
	//returns the ISBN of the book
	void setISBN(string isbn) {
		ISBN = isbn;
	}
	//set the ISBN
	void setTitle(string t) {
		title = t;
	}
	//set the title of the book
	string getTitle() {
		return title;
	}
	//set the title of the book
};
#endif // !Book_hpp
