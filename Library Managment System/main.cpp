#include<iostream>
#include<fstream>
#include <vector>
#include <cctype>
#include "Book.h"
#include "Catalog.h"
#include "ReadershipList.h"
#include "Loan.h"
#include "ListofLoans.h"
#include "Borrower.h"
using namespace std;

void menu() {
	//prints out options for the user
	cout << endl;
	cout << "\tChoose an option!" << endl;
	cout << "a. Register a new borrower" << endl;
	cout << "b. Add a new book to the catalog. " << endl;
	cout << "c. List all borrowers. " << endl;
	cout << "d. List all books. " << endl;
	cout << "e. Search for a given borrower or book by ID/name/title etc." << endl;
	cout << "f. Loan a book. " << endl;
	cout << "g. Return a book. " << endl;
	cout << "h. List all loans (returned and unreturned loans). " << endl;
	cout << "i. List information about unreturned books. " << endl;
	cout << "z. Exit Program. " << endl <<endl;
	cout << "Enter Character: " << endl;
}

//add serachandfind function

int main() {
	menu();
	string rFileName = "readershiplist.txt";
	string cFileName = "catalog.txt";
	string lFileName = "loans.txt";

	ReadershipList rList(rFileName);
	Catalog blist(cFileName);
	ListofLoans loanList(lFileName);

	blist.listBook();
	rList.listBorrowers();


	char option;

	while (true) {
		menu();
		cin >> option;
		switch (tolower(option))
		{
		case 'a':
			rList.AddBorrower();
			break;
		case 'b':
			blist.AddBook();
			break;
		case 'c':
			rList.listBorrowers();
			break;
		case 'd':
			blist.listBook();
			break;
		case 'e':
			cout << "Nothing here" << endl;
			break;
		case 'f':
			loanList.LoanABook(rList, blist);
			break;
		case 'g':
			loanList.returnABook(rList, blist);
			break;
		case 'h':
			loanList.listAllLoans(blist, rList);
			break;
		case 'i':
			loanList.listActiveLoans(blist, rList);
			break;
		case 'z':
			cout << "Are you sure you would like to exit the program " << endl;
			cout << "Enter any key for Yes or 'n' for No:  " << endl;
			cin >> option;
			if (tolower(option) != 'n')
				exit(1);
			break;
		default:
			cout << "INVALID! OPTION!" << endl;
			break;
		}

	}
	
	return 0;
	
}