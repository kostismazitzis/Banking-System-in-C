This project is a simple banking system program written in C. It allows users to create bank accounts, deposit money, withdraw money, check balances, view account details, and transfer money between accounts. The program uses structures to represent accounts and transactions, and provides a menu-driven interface for users to interact with the system.

Features
Create Account: Allows the user to create a new bank account by providing a name and address. Each account is assigned a unique account number.
Deposit Money: Allows the user to deposit money into their account.
Withdraw Money: Allows the user to withdraw money from their account, with a check to ensure sufficient balance.
Check Balance: Allows the user to check the current balance of their account.
View Account Details: Displays the account number, name, address, current balance, and transaction history of the account.
Transfer Money: Allows the user to transfer money from their account to another account within the system.
Data Structures
Account: Represents a bank account, including account number, name, address, balance, transaction history, and the number of transactions.
Transaction: Represents a transaction, including type (deposit, withdrawal, transfer), amount, balance after the transaction, and a description.
Function Descriptions
createAccount(Account accounts[], int *numAccounts): Creates a new account and stores it in the accounts array.
depositMoney(Account *account): Deposits money into the specified account.
withdrawMoney(Account *account): Withdraws money from the specified account, checking for sufficient balance.
checkBalance(Account account): Displays the current balance of the specified account.
viewAccountDetails(Account account): Displays detailed information about the specified account, including transaction history.
transferMoney(Account accounts[], int numAccounts): Transfers money from one account to another, updating both balances.
addTransaction(Account *account, const char *type, double amount, const char *description): Adds a transaction to the specified account's transaction history.
findAccountByNumber(Account accounts[], int numAccounts, int accountNumber): Finds and returns a pointer to the account with the specified account number.

Usage
Compile the program using GCC:
gcc -g Banking_System.c -o Banking_System

Run the compiled program:
./Banking_System
Follow the on-screen menu to perform various banking operations.

Example
(markdown)
Banking System Menu:
1. Create a Bank account
2. Deposit money
3. Withdraw money
4. Check Balance
5. View Account Details
6. Transfer Money
7. Exit
Enter your choice: 1
Enter account name: konstantinos
Enter account address: kritis 20
Account created successfully! Your account number is 12345.
