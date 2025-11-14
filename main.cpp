#include <iostream>
using namespace std;
class BankAccount {
    private:
        string accountNumber;
        string accountHolderName;
        double balance;

    public:
        BankAccount(string accNum, string accHolder, double initialBalance) {
            accountNumber = accNum;
            accountHolderName = accHolder;
            balance = initialBalance;
        }

        void deposit(double amount) {
            balance += amount;
            cout << "Deposited: " << amount << endl;
        }

        void withdraw(double amount) {
            if (amount <= balance) {
                balance -= amount;
                cout << "Withdrew: " << amount << endl;
            } else {
                cout << "Insufficient funds!" << endl;
            }
        }

        void displayAccountInfo() {
            cout << "Account Number: " << accountNumber << endl;
            cout << "Account Holder: " << accountHolderName << endl;
            cout << "Balance: " << balance << endl;
        }
};

int main(){

    cout << "Welcome to the Bank Account Management System!" << endl;
    BankAccount account("123456789", "Chan khosa", 1000.0);

    account.displayAccountInfo();

    account.deposit(500.0);
    account.withdraw(200.0);
    account.displayAccountInfo();

    return 0;
}