Introduction:
For this project, I build an account management system which contains a stock portfolio account and a bank account. The class of these two system are both inherited from the base class ‘Account’. 

Stock Portfolio Account:
Stock Portfolio account is doubly linked list which combined by several nodes. Each node contains the information of stock symbol, stock number of shares, stock price. The stock portfolio account are equipped with 6 functions as the following:
1.	Display the price for a stock symbol.
2.	Display the current portfolio.
3.	Buy shares.
4.	Sell shares.
5.	View a graph for the portfolio value.
6.	View the transaction history.
Each time the program is run, the constructor will download the stock portfolio account information from a txt.file named ‘stockinfo.txt’, which stores the information of the account when the program is closed, so that the account information will not get lost. The price of each stock are obtained from ‘Result1.txt’. The cash balance which stored by the variable ‘currentbalance’, and it changes when user implement the operations that cause a change in account cash balance. Each time user buys shares, the function ‘addtolist’ will store the company symbol, number of shares, price of shares to the stock account, and I build a function  named ’simplifyforbuy’ to check whether if this stock share is in your account, if so, it will directly change the number of shares that already in your account. What is more, if the price of the stock is more than the maximum amount you pay for it, transaction will fail, and it will also fail if the total value of this purchase exceeds you current account cash balance. Each time user sell the shares, the function named ’simplifyforsell’ will run to check the amount of the share that in your account so that the node storing information about this share will be deleted if the number of shares is 0. The sell implementation will fail if the amount to sell is greater than that in your account, and the minimum price to sell is greater the market price of this stock. Finally, when the program exits, the information of the stock account will be stored in the txt.file named ‘stockinfo.txt’. The history of account implementation is stored in the txt.file named ‘stock_transaction_history’.

Bank Account:
The bank account system contains 4 functions as the following:
1.	View account balance.
2.	Deposit Money.
3.	Withdraw Money
4.	Print out history.
Each time the program is run, the bank account information will be obtained from the txt.file named ‘bankinfo’ which stores the information of the account when the program is closed. The history of account implementation is stored in the txt.file named ‘bank_transaction_history’.
