// Name :Qingqiao Hu
// Course: 16:332:503, PM for Financial Applications and Numerical Computing.
// Example: Finalproject
// Date:4/5/2015
#include <iostream>
#pragma comment( lib, "libmx.lib" )
#pragma comment( lib, "libmex.lib" )
#pragma comment( lib, "libeng.lib" )
#include <yvals.h>
#if (_MSC_VER >= 1600)
#define __STDC_UTF_16__
#endif
#include "mex.h" 
#include <engine.h>
#include <vector>
#include <cstdlib>
using namespace std;
#include <string>
using std::string;
#include <new>
#include <iomanip>
#include <fstream>
#include <time.h>
using std::setw;
#include "Account_QingqiaoHu.h"
#include "BankAccount_QingqiaoHu.h"

#ifndef StockAccount_H
#define StockAccount_H
//StockAccount inherits from BankAccount in order to get currentcashbalance
class StockAccount :public BankAccount{
public:
	StockAccount();
	//~StockAccount();
	void displaystockprice(string);
	void addtolist(Node*);
	void displaycurrentportfolio();
	void sellshares(string, double);
	void buyshares(string, double);
	void simplifyforbuy();
	void simplifyforsell();
	void graph();
	void recordhistory(int, string, double, double);
	void recordstockinfo();
	bool isEmpty() const;
	Node *StockAccount::getNewNode(Node *value);
	void viewhistory();
	void recordportfoliovalue(double);
private:
	Node *firstPtr;
	Node *lastPtr;
	double portfoliototalvalue;
};//end declaration

StockAccount::StockAccount(){
	string stockname;
	double stocknumber;
	ifstream stockinfo;
	stockinfo.open("stockinfo.txt");//read the information from stockinfo.txt
	if (!stockinfo)
	{
		cout << "Failed to open the document" << endl;
		exit(1);
	}//end if
	else{
		//cout << "Your stockaccount information is:" << endl;
		while (stockinfo >> stockname >> stocknumber){

			Node *newnode = new Node(stockname, stocknumber);
			addtolist(newnode);//store the information to the linklist
		}//end while
		stockinfo.close();
	}//end else

	ifstream portvalueinfo;
	portvalueinfo.open("portvalue.txt");
	if (!portvalueinfo)
	{
		cout << "Failed to open the document" << endl;
		exit(1);
	}//end if
	else{
		//cout << "Your current portvalue is:" << endl;
		portvalueinfo >> portfoliototalvalue;
	}
	portvalueinfo.close();
}//end function

void StockAccount::viewhistory(){
	string operation;
	string name;
	double amount;
	double price;
	double value;
	string time;
	ifstream stockhistory("stock_transaction_history.txt");//read the information from stockinfo.txt
	if (!stockhistory)
	{
		cout << "Failed to open the document" << endl;
		exit(1);
	}//end if
	else{
		cout << "Stock account history is:" << endl;
		cout << "Event" << "  " << "CompanySymbol" << "  " << "Number" << "  " << "PricePerShare" << "  " << "TotalValue" << "  " << "Time" << endl;
		string fileline;
		while (getline(stockhistory, fileline))
			cout << fileline << endl;


	}//end else
	stockhistory.close();
}//end function

bool StockAccount::isEmpty() const
{
	return firstPtr == 0;
} // end function isEmpty

Node *StockAccount::getNewNode(Node *value)
{
	return new Node(*value);
} // end function getNewNod

void StockAccount::displaystockprice(string stocksymbol)
{
	unsigned seed;
	cout << "Enter seed:" << endl;
	cin >> seed;
	srand(seed);
	int m = rand() % 2 + 1;
	string stockname;
	double stockprice;
	string date;
	ifstream results;
	if (m == 1)
		results.open("result1.txt");//read the information from result1.tet such that stock pricing info are consulted
	else
		results.open("result2.txt");
	if (!results)
	{
		cout << "Failed to open the document" << endl;
		exit(1);
	}//end if

	int flag = 0;
	while (results >> stockname >> stockprice >> date){

		if (stockname == stocksymbol)//if found
		{
			cout << "The stock information is:" << endl;
			cout << "Company-symbol" << setw(7) << "Price per share" << endl;
			cout << stockname << setw(17) << stockprice << endl;
			flag = 1;
			break;
		}

	}//end while
	if (flag == 0)
		cout << "The symbol cannot be found." << endl;

}//end function

void StockAccount::displaycurrentportfolio()
{
	if (isEmpty()) {
		cout << "The list is empty\n\n";
		return;
	} // end if
	unsigned seed;
	cout << "Enter seed:" << endl;
	cin >> seed;
	srand(seed);
	int m = rand() % 2 + 1;
	string stockname;
	double stockprice;
	ifstream results;
	string date;
	double portfoliototalvalue = currentbalance;
	if (m == 1)
		results.open("result1.txt");//read the information from result1.tet such that stock pricing info are consulted
	else
		results.open("result2.txt");
	if (!results)
	{
		cout << "Failed to open the document" << endl;
		exit(0);
	}//end if
	cout << "CompanySymbol" << "  " << "Number" << "  " << "Price per share" << "  " << "Toltal value" << endl;
	while (results >> stockname >> stockprice >> date){
		Node *currentPtr = firstPtr;
		while (currentPtr != 0) {
			if (currentPtr->itemSymbol == stockname){
				double t = currentPtr->itemNumber*stockprice;
				portfoliototalvalue += t;
				cout << currentPtr->itemSymbol << "  " << currentPtr->itemNumber << "  " << stockprice << "  " << t << endl;
			}
			currentPtr = currentPtr->nextPtr;
		} // end while for linklist
	} //stock price information
	cout << "\n\n";
	cout << "Current Cashbalance is:" << currentbalance << endl;
	cout << "Total portfolio value is:" << portfoliototalvalue << endl;
	recordportfoliovalue(portfoliototalvalue);
}//end function

void StockAccount::buyshares(string name, double number)
{
	unsigned seed;
	cout << "Enter seed:" << endl;
	cin >> seed;
	srand(seed);
	int m = rand() % 2 + 1;
	string stockname;
	double stockprice;
	string date;
	ifstream results;
	if (m == 1)
		results.open("result1.txt");//read the information from result1.tet such that stock pricing info are consulted
	else
		results.open("result2.txt");
	if (!results)
	{
		cout << "Failed to open the document" << endl;
		exit(1);
	}//end if
	int maximumprice;
	cout << "Enter the maximum price you will pay for each share:" << endl;
	cin >> maximumprice;//maximum amount you gonna pay and it needs to be greater than the stockprice
	//find the company
	int flag = 0;
	while (results >> stockname >> stockprice >> date){
		if (stockname == name)//if found
		{
			cout << "The stock information is:" << endl;
			cout << "Company-symbol" << setw(7) << "Price per share" << endl;
			cout << stockname << setw(17) << stockprice << endl;
			flag = 1;
			break;
		}
	}//end while
	if (flag == 0)
		cout << "Company not found." << endl;
	cout << "You want to buy:" << name << "  " << "Its price per share is:" << stockprice << endl;
	if (maximumprice >= stockprice){
		if (currentbalance < stockprice*number)
			cout << "Transition failed, because there isn't enough balance in your account" << endl;
		else{
			currentbalance -= stockprice*number;//change current balance
			cout << "The current balance is:" << currentbalance << endl;//store the information to the account
			Node *newnode = new Node(name, number);
			addtolist(newnode);
			simplifyforbuy();
			recordhistory(1, name, number, stockprice);//recoord history
			recordstockinfo();
			recordbankinfo(currentbalance);//change current cash balance
		}//end else
	}//end if
	else
		cout << "Transition failed, because the maximum is less than the stock price." << endl;

}//end function

void StockAccount::addtolist(Node *value)
{
	Node *newPtr = getNewNode(value);
	if (isEmpty())  // List is empty
		firstPtr = lastPtr = newPtr;
	else {  // List is not empty
		lastPtr->nextPtr = newPtr;
		newPtr->previousPtr = lastPtr;
		//lastPtr->previousPtr = lastPtr;
		lastPtr = newPtr;
	} // end else
}// end function

void StockAccount::simplifyforbuy(){
	Node *currentPtr = firstPtr;
	double b = -1;
	string s;
	Node *fakeHeadPtr = new Node(s, b);
	Node *tempPtr;
	int flag = 0;
	fakeHeadPtr->nextPtr = firstPtr;
	firstPtr->previousPtr = fakeHeadPtr;
	firstPtr = fakeHeadPtr;
	currentPtr = firstPtr;
	tempPtr = lastPtr;
	while (currentPtr->nextPtr != lastPtr){
		if ((currentPtr->nextPtr)->itemSymbol == tempPtr->itemSymbol){
			(currentPtr->nextPtr)->itemNumber += tempPtr->itemNumber;
			delete tempPtr;
			flag = 1;//show that list has been simplified
		}//end if
		currentPtr = currentPtr->nextPtr;
	}//end while
	if (flag == 0)
		cout << "Simplification succeed." << endl;
	firstPtr = firstPtr->nextPtr;
	delete fakeHeadPtr;
}//end function

void StockAccount::simplifyforsell(){
	Node *currentPtr;
	double b = -1;
	string s;
	Node *fakeHeadPtr = new Node(s, b);
	Node *tempPtr;
	int flag = 0;
	fakeHeadPtr->nextPtr = firstPtr;
	firstPtr->previousPtr = fakeHeadPtr;
	firstPtr = fakeHeadPtr;
	currentPtr = firstPtr;
	//tempPtr = lastPtr;
	while (currentPtr->nextPtr!= NULL){
	//flag = 1;//show that list has been simplified
		if (currentPtr->itemNumber == 0){
			Node *tempPtr = currentPtr;
			currentPtr->previousPtr->nextPtr = currentPtr->nextPtr;
			currentPtr->nextPtr->previousPtr = currentPtr->previousPtr;
			//currentPtr->nextPtr = currentPtr->nextPtr->nextPtr;
			//currentPtr->nextPtr->nextPtr->previousPtr = currentPtr;
			delete tempPtr;//delete the stock of zero number
			break;
		}//end if
		currentPtr = currentPtr->nextPtr;
	}//end while
	if (currentPtr == lastPtr && currentPtr->itemNumber == 0){
		currentPtr->previousPtr->nextPtr = NULL;
		lastPtr = currentPtr->previousPtr;
		Node *temp = currentPtr;
		delete temp;
	}
		
	if (flag == 0)
		cout << "Simplification succeed." << endl;
	firstPtr = firstPtr->nextPtr;
	delete fakeHeadPtr;
}//end function

void StockAccount::sellshares(string name, double number)
{
	unsigned seed;
	cout << "Enter seed:" << endl;
	cin >> seed;
	srand(seed);
	int m = rand() % 2 + 1;
	string stockname;
	double stockprice;
	string date;
	ifstream results;
	if (m == 1)
		results.open("result1.txt");//read the information from result1.tet such that stock pricing info are consulted
	else
		results.open("result2.txt");
	if (!results)
	{
		cout << "Failed to open the document" << endl;
		exit(1);
	}//end if

	int minimumprice;
	cout << "Enter the minimum price you will sell for each share:" << endl;
	cin >> minimumprice;//minimum amount you gonna pay and it needs to be less than the stockprice
	Node *currentPtr = firstPtr;
	int flag = 0;
	while (results >> stockname >> stockprice >> date)
	{
		if (stockname == name)
		{
			cout << "The price for the stock you wanna sell is:" << stockprice << endl;
			flag = 1;
			break;
		}
	}//end while
	if (flag == 0)
		cout << "Company not found." << endl;
	int hasfound = 0;
	while (currentPtr != NULL){
		if (currentPtr->itemSymbol == name)
		{  //find the stockname
			hasfound = 1;
			cout << "You want to sell:" << name << "  " << "Its price per share is:" << stockprice << endl;
			if (minimumprice > stockprice)
				cout << "Transition failed because the minimum price you ganna sell it is more than the stockprice." << endl;
			else{
				currentbalance += stockprice*number;//change current balance
				currentPtr->itemNumber -= number;
				recordstockinfo();
				cout << "The current balance is:" << currentbalance << endl;//store the information to the account
				simplifyforsell();//simplify
				recordhistory(2, name, number, stockprice);
				
				recordbankinfo(currentbalance);
			}
			break;
		}//end if
		currentPtr = currentPtr->nextPtr;
	}//end while
	if (hasfound == 0)
		cout << "The stock of this company doesn't exist in your account." << endl;
}//end function

void StockAccount::recordhistory(int index, string name, double number, double price){
	// function main begins program execution
	ofstream file;
	//opens the file myfile.txt
	file.open("stock_transaction_history.txt", ios::app);
	//for loop to write the values to the file
	time_t seconds;
	seconds = time(NULL);
	//cout << seconds << endl;
	struct tm timeinfo;
	localtime_s(&timeinfo, &seconds);

	if (index == 1)
		file << "Buy" << setw(7) << name << setw(13) << number << setw(8) << price << setw(13) << price*number << setw(11) << timeinfo.tm_hour << ":" << timeinfo.tm_min << ":" << timeinfo.tm_sec << endl;
	if (index == 2)
		file << "Sell" << setw(6) << name << setw(13) << number << setw(8) << price << setw(13) << price*number << setw(11) << timeinfo.tm_hour << ":" << timeinfo.tm_min << ":" << timeinfo.tm_sec << endl;
	file.close();
}

void StockAccount::recordstockinfo(){
	// function main begins program execution
	ofstream file;
	file.open("stockinfo.txt");
	//opens the file myfile.txt
	if (!file){
		cout << "Failed to open the file." << endl;
		exit(1);
	}
	//for loop to write the values to the file
	Node *currentPtr = firstPtr;
	while (currentPtr != NULL){
		file << currentPtr->itemSymbol << "  " << currentPtr->itemNumber << endl;
		currentPtr = currentPtr->nextPtr;
	}//end while
	file.close();//show that the information of stock has been recorded.

}//end function

void StockAccount::recordportfoliovalue(double portfoliototalvalue){
	time_t seconds;
	seconds = time(NULL);
	//cout << seconds << endl;
	struct tm timeinfo;
	localtime_s(&timeinfo, &seconds);
	ofstream file;
	file.open("portvalue.txt", ios::app);
	if (!file){
		cout << "Failed to open the file." << endl;
		exit(1);
	}
	else{
		file << portfoliototalvalue << endl;
		file.close();
	}
}

void StockAccount::graph(){
Engine *ep;
ep = engOpen(NULL);
if (ep == NULL)
{
cout << "Error: Not Found" << endl;
exit(1);
}//end if
string fileline;
vector<string>v;
ifstream portvalue;
portvalue.open("portvalue.txt");
if (portvalue.is_open())
{
	while (!portvalue.eof())
	{
		getline(portvalue, fileline);
		v.push_back(fileline);
	}//end while
	portvalue.close();
}//end if
else
cout << "Failed to open the file." << endl;

double *array = new double[v.size()];//indicate that it's a dynamic vector
for (int i = 0; i < v.size(); i++)
	array[i] = atof(v[i].c_str());

mxArray *Vec;
Vec = mxCreateDoubleMatrix(1, v.size(), mxREAL);
memcpy((void *)mxGetPr(Vec), (void *)array, sizeof(double)*v.size());
engPutVariable(ep, "array", Vec);
engEvalString(ep, "title('Figure of Total Portfolio value')");
engEvalString(ep, "plot(array)");
engEvalString(ep, "grid on");
system("pause");
engClose(ep);
delete[]array;
return;
}
#endif