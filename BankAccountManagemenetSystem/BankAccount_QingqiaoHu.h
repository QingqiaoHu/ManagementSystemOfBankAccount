// Name :Qingqiao Hu
// Course: 16:332:503, PM for Financial Applications and Numerical Computing.
// Example: Finalproject
// Date:4/5/2015
#include <iostream>
using namespace std;
#include <string>
using std::string;
#include<fstream>
#include<cctype> 
#include <new>
#include <iomanip>
using std::setw;
#include "Account_QingqiaoHu.h"

#ifndef BankAccount_H
#define BankAccount_H
class BankAccount :public Account{
public:
	BankAccount();
	void viewbankaccountbalance() const;
	void deposit(double);
	void withdraw(double);
	void recordhistory(int, double);
	void viewhistory();
	void recordbankinfo(double);
protected:
	double currentbalance;
};

BankAccount::BankAccount(){
	ifstream bankinfo;
	bankinfo.open("bankinfo.txt");//read the information from stockinfo.txt
	if (!bankinfo)
	{
		cout << "Failed to open the document" << endl;
		exit(0);
	}
	else{
		//cout << "Your bank account information is:" << endl;
		bankinfo >> currentbalance;
	}
	
}

void BankAccount::recordbankinfo(double currentbalance){
	// function main begins program execution
	ofstream file;
	//opens the file myfile.txt
	file.open("bankinfo.txt");
	//for loop to write the values to the file
	file << currentbalance;
	file.close();
}
void BankAccount::viewbankaccountbalance() const{
	cout << "\n Balance amount:" << currentbalance<<endl;
}

void BankAccount::deposit(double x){
	currentbalance += x;
	recordhistory(1, x);
	recordbankinfo(currentbalance);
}

void BankAccount::withdraw(double x){
	if (currentbalance >= x){
		currentbalance -= x;
		recordhistory(2, x);
		recordbankinfo(currentbalance);
	}
	else
		cout << "The bankbalance is not enough for withdraw" << endl;
}

void BankAccount::recordhistory(int index, double amount){
	// function main begins program execution
	ofstream file;
	//opens the file myfile.txt
	file.open("bank_transaction_history.txt",ios::app);
	//for loop to write the values to the file
	time_t seconds;
	seconds = time(NULL);
	//cout << seconds << endl;
	struct tm timeinfo;
	localtime_s(&timeinfo, &seconds);
	if (index == 1)
		file << "Deposit" << setw(7) << amount << setw(13) << currentbalance << setw(8) << timeinfo.tm_year + 1900 << "/" << timeinfo.tm_mon + 1 << "/" << timeinfo.tm_mday <<"  "<< timeinfo.tm_hour << ":" << timeinfo.tm_min << ":" << timeinfo.tm_sec << endl;
	if (index == 2)
		file << "Withdraw" << setw(6) << amount << setw(13) << currentbalance << setw(8) << timeinfo.tm_year + 1900 << "/" << timeinfo.tm_mon + 1 << "/" << timeinfo.tm_mday <<"  "<< timeinfo.tm_hour << ":" << timeinfo.tm_min << ":" << timeinfo.tm_sec << endl;
	file.close();
}

void BankAccount::viewhistory(){
	string operation;
	double amount;
	string time;
	ifstream bankhistory("bank_transaction_history.txt");//read the information from stockinfo.txt
	if (!bankhistory)
	{
		cout << "Failed to open the document" << endl;
		exit(0);
	}//end if
	else {
		cout << "The bank history is:" << endl;
		cout << "Event" << "  " << "Amount" << "  " << "AccountBalance" << "  " << "Time" << endl;
		string fileline;
		while (getline(bankhistory, fileline))
			cout << fileline << endl;
	}
	bankhistory.close();
}//end function
#endif