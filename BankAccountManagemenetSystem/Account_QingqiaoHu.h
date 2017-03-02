// Name :Qingqiao Hu
// Course: 16:332:503, PM for Financial Applications and Numerical Computing.
// Example: Finalproject
// Date:4/5/2015
#include <iostream>
using namespace std;
#include <string>
using std::string;
#include <new>
#include <iomanip>
using std::setw;
#include "Node_QingqiaoHu.h"
#ifndef ACCOUNT_H
#define ACCOUNT_H
class Account{
public:
	//Account();
	//~Account();
	const double initialbalance = 10000;
	int mySize;
};

//Account::Account() :firstPtr(0), lastPtr(0){
	//empty body
//}

/*Account::~Account(){
		if (!isEmpty()) {    // List is not empty
			cout << "Destroying nodes ...\n";
			Node *currentPtr = firstPtr;
			Node *tempPtr;
			while (currentPtr != 0) {  // delete remaining nodes
				tempPtr = currentPtr;
				cout << tempPtr->itemSymbol << '\n' << tempPtr->itemPrice << endl;
				currentPtr = currentPtr->nextPtr;
				delete tempPtr;
			} // end while
		} // end if
		cout << "All nodes destroyed\n\n";
	}// end List destructor*/


#endif