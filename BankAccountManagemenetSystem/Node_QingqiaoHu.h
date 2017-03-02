// Name :Qingqiao Hu
// Course: 16:332:503, PM for Financial Applications and Numerical Computing.
// Example: Finalproject
// Date:4/5/2015
#ifndef NODE_H
#define NODE_H

class Node{
	friend class Account;
	friend class StockAccount;
public:

	Node(string& name,double &number)
		: itemSymbol(name), itemNumber(number)
	{
		this->nextPtr = NULL;
		this->previousPtr = NULL;
	}
protected:
	string itemSymbol;
	//double itemPrice;
	double itemNumber;
	Node *nextPtr;
	Node *previousPtr;
};


#endif