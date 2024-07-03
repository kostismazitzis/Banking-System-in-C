#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define MAX_TRANSACTIONS 100

typedef struct {
    char type[10]; // "Deposit", "Withdraw", "Transfer"
    double amount;
    double balanceAfter;
    char description[100];
} Transaction;

typedef struct {
    int accountNumber;
    char name[100];
    char address[200];
    double balance;
    Transaction transactions[MAX_TRANSACTIONS];
    int transactionCount;
} Account;

// Function declarations
void createAccount(Account accounts[], int *numAccounts);
void depositMoney(Account *account);
void withdrawMoney(Account *account);
void checkBalance(Account account);
void viewAccountDetails(Account account);
void transferMoney(Account accounts[], int numAccounts);
void displayMenu(void);
void addTransaction(Account *account, const char *type, double amount, const char *description);
Account* findAccountByNumber(Account accounts[], int numAccounts, int accountNumber);

void addTransaction(Account *account, const char *type, double amount, const char *description) {
    Transaction *transaction = &account->transactions[account->transactionCount++];
    strcpy(transaction->type, type);
    transaction->amount = amount;
    transaction->balanceAfter = account->balance;
    strcpy(transaction->description, description);
}

void createAccount(Account accounts[], int *numAccounts) {
    Account *account = &accounts[(*numAccounts)++];
    printf("Enter account name: ");
    fgets(account->name, sizeof(account->name), stdin);
    account->name[strcspn(account->name, "\n")] = '\0';

    printf("Enter account address: ");
    fgets(account->address, sizeof(account->address), stdin);
    account->address[strcspn(account->address, "\n")] = '\0';

    account->balance = 0.0;
    account->transactionCount = 0;
    account->accountNumber = rand() % 100000; // Simple random account number
    printf("Account created successfully! Your account number is %d\n", account->accountNumber);
}

void depositMoney(Account *account) {
    double amount;
    printf("Enter amount to deposit: ");
    scanf("%lf", &amount);
    getchar(); // Consume newline character

    account->balance += amount;
    addTransaction(account, "Deposit", amount, "Deposit money");
    printf("Deposit successful! New balance: %.2f\n", account->balance);
}

void withdrawMoney(Account *account) {
    double amount;
    printf("Enter amount to withdraw: ");
    scanf("%lf", &amount);
    getchar(); // Consume newline character

    if (amount > account->balance) {
        printf("Insufficient balance!\n");
    } else {
        account->balance -= amount;
        addTransaction(account, "Withdrawal", amount, "Withdraw money");
        printf("Withdrawal successful! New balance: %.2f\n", account->balance);
    }
}

void checkBalance(Account account) {
    printf("Current balance: %.2f\n", account.balance);
}

void viewAccountDetails(Account account) {
    printf("Account Number: %d\n", account.accountNumber);
    printf("Name: %s\n", account.name);
    printf("Address: %s\n", account.address);
    printf("Balance: %.2f\n", account.balance);
    printf("Transaction History:\n");

    for (int i = 0; i < account.transactionCount; i++) {
        Transaction transaction = account.transactions[i];
        printf("%s: %.2f, Balance After: %.2f, Description: %s\n",
            transaction.type, transaction.amount, transaction.balanceAfter, transaction.description);
    }
}

void transferMoney(Account accounts[], int numAccounts) {
    int fromAccountNumber, toAccountNumber;
    double amount;

    printf("Enter your account number: ");
    scanf("%d", &fromAccountNumber);
    getchar(); // Consume newline character

    Account *fromAccount = findAccountByNumber(accounts, numAccounts, fromAccountNumber);
    if (fromAccount == NULL) {
        printf("Account not found.\n");
        return;
    }

    printf("Enter the recipient account number: ");
    scanf("%d", &toAccountNumber);
    getchar(); // Consume newline character

    Account *toAccount = findAccountByNumber(accounts, numAccounts, toAccountNumber);
    if (toAccount == NULL) {
        printf("Recipient account not found.\n");
        return;
    }

    printf("Enter the amount to transfer: ");
    scanf("%lf", &amount);
    getchar(); // Consume newline character

    if (amount > fromAccount->balance) {
        printf("Insufficient balance for transfer.\n");
        return;
    }

    fromAccount->balance -= amount;
    addTransaction(fromAccount, "Transfer", amount, "Transfer to another account");
    toAccount->balance += amount;
    addTransaction(toAccount, "Transfer", amount, "Transfer from another account");

    printf("Transfer successful! New balance: %.2f\n", fromAccount->balance);
}

Account* findAccountByNumber(Account accounts[], int numAccounts, int accountNumber) {
    for (int i = 0; i < numAccounts; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            return &accounts[i];
        }
    }
    return NULL;
}

void displayMenu(void) {
    printf("Banking System Menu:\n");
    printf("1. Create a Bank account\n");
    printf("2. Deposit money\n");
    printf("3. Withdraw money\n");
    printf("4. Check Balance\n");
    printf("5. View Account Details\n");
    printf("6. Transfer Money\n");
    printf("7. Exit\n");
    printf("Enter your choice: ");
}

int main(void) {
    Account accounts[MAX_ACCOUNTS];
    int numAccounts = 0;
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        getchar(); // Consume the newline character left by scanf

        switch (choice) {
            case 1:
                createAccount(accounts, &numAccounts);
                break;
            case 2:
                {
                    int accountNumber;
                    printf("Enter your account number: ");
                    scanf("%d", &accountNumber);
                    getchar(); // Consume newline character
                    Account *account = findAccountByNumber(accounts, numAccounts, accountNumber);
                    if (account != NULL) {
                        depositMoney(account);
                    } else {
                        printf("Account not found.\n");
                    }
                }
                break;
            case 3:
                {
                    int accountNumber;
                    printf("Enter your account number: ");
                    scanf("%d", &accountNumber);
                    getchar(); // Consume newline character
                    Account *account = findAccountByNumber(accounts, numAccounts, accountNumber);
                    if (account != NULL) {
                        withdrawMoney(account);
                    } else {
                        printf("Account not found.\n");
                    }
                }
                break;
            case 4:
                {
                    int accountNumber;
                    printf("Enter your account number: ");
                    scanf("%d", &accountNumber);
                    getchar(); // Consume newline character
                    Account *account = findAccountByNumber(accounts, numAccounts, accountNumber);
                    if (account != NULL) {
                        checkBalance(*account);
                    } else {
                        printf("Account not found.\n");
                    }
                }
                break;
            case 5:
                {
                    int accountNumber;
                    printf("Enter your account number: ");
                    scanf("%d", &accountNumber);
                    getchar(); // Consume newline character
                    Account *account = findAccountByNumber(accounts, numAccounts, accountNumber);
                    if (account != NULL) {
                        viewAccountDetails(*account);
                    } else {
                        printf("Account not found.\n");
                    }
                }
                break;
            case 6:
                transferMoney(accounts, numAccounts);
                break;
            case 7:
                printf("Exiting...\n");
                exit(0);
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
