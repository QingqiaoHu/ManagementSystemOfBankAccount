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
#include <time.h>
#include<fstream>
using std::setw;
#include "Account_QingqiaoHu.h"
#include "BankAccount_QingqiaoHu.h"
#include "Node_QingqiaoHu.h"
#include "StockAccount_QingqiaoHu.h"
#include<fstream>
void main(){
	StockAccount stock;
	BankAccount bank;
	cout << "Welcome to the Account Management System" << endl;
	cout << "Please select an account to access." << endl;
	cout << "1. Stock Portfolio Account." << endl;
	cout << "2. Bank Account." << endl;
	cout << "3. Exit." << endl;
	int op;
	cin >> op;
	while (op != 3)
	{

		while (op == 1)
		{
			cout << "Please select an opration:" << endl;
			cout << "1. Display the price for a stock symbol." << endl;
			cout << "2. Display the current portfolio." << endl;
			cout << "3. Buy shares." << endl;
			cout << "4. Sell shares." <<endl;
			cout << "5. View a graph for the portfolio value." << endl;
			cout << "6. View the transaction history." << endl;
			cout << "7. Return to the previous menu." << endl;
			int op1;
			cin >> op1;
			if (op1 == 7)
				break;
			while (op1 != 7){
				switch (op1){
				case 1:
				{
						  cout << "Enter the symbol of company that you wanna find:" << endl;
						  string symbol;
						  cin >> symbol;
						  stock.displaystockprice(symbol);
						  break;
				}//end case 1
				case 2:
				{
						  stock.displaycurrentportfolio();
						  break;
				}//end case 2
				case 3:
				{
						  string symbol;
						  double number;
						  cout << "Please enter the company name and the amount of shares you wanna buy:" << endl;
						  cin >> symbol >> number;
						  stock.buyshares(symbol, number);
						  break;
				}//end case 3
				case 4:
				{
						  string symbol;
						  double number;
						  cout << "Please enter the company name and the amount of shares you wanna sell:" << endl;
						  cin >> symbol >> number;
						  stock.sellshares(symbol, number);
						  break;
				}//end case 4
				case 5:
				{
						  stock.graph();
						  break;
				}//end case 5
				case 6:
				{
						  stock.viewhistory();
						  break;
				}//end case 6

				}//end switch
				cout << "Please enter the number for next command, 7 for exit." << endl;
				cin >> op1;
			}//end while for op1
			
		}//end while for op

		while (op == 2)
		{
			cout << "Please select an opration:" << "\n1. View Account balance." << "\n2. Deposit money" << "\n3. Withdraw money." << "\n4. Print out history." << "\n5. Return to previous menu." << endl;
			int op2;
			cin >> op2;
			if (op2 == 5)
				break;
			while (op2 != 5){
				switch (op2){
				case 1:
				{
						  bank.viewbankaccountbalance();
						  break;
				}//end case 1
				case 2:
				{
						  cout << "Enter the amount of money you wanna deposit:" << endl;
						  double money;
						  cin >> money;
						  bank.deposit(money);
						  break;
				}//end case 2
				case 3:
				{
						  cout << "Entet the amount of money you wanna withdraw:" << endl;
						  double money;
						  cin >> money;
						  bank.withdraw(money);
						  break;
				}//end case 3
				case 4:
				{
						  bank.viewhistory();
						  break;
				}//end case 4
				}//end switch
				cout << "Please enter the number for next command, 5 for exit." << endl;
				cin >> op2;
			}//end while for op2

		}//end while for op
		cout << "Welcome to the Account Management System" << endl;
		cout << "Please select an account to access." << endl;
		cout << "1. Stock Portfolio Account." << endl;
		cout << "2. Bank Account." << endl;
		cout << "3. Exit." << endl;
		cin >> op;
	}
	system("pause");
}