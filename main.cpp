#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
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
            cout << fixed << setprecision(2);
            cout << "Balance: " << balance << endl;
        }
};

int main(){

    cout << "Welcome to the Bank Account Management System!" << endl;
    cout << "Enter Account Details:" << endl;
    int choice;
    do {
        cout << "1. Create Account" << endl;
        cout << "2. Exit" << endl;
        cout << "Choose an option: ";
        cin >> choice;
    } while (choice != 1 && choice != 2);

    string accNum, accHolder;
    double initialBalance;

   if(choice == 1) {
       cout << "Account Number: ";
       cin >> accNum;
       cin.ignore();
       cout << "Account Holder Name: ";
       getline(cin, accHolder);
       cout << "Initial Balance: ";
    while (!(cin >> initialBalance) || initialBalance < 0) {
        cout << "Enter a valid non-negative amount: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    } else {
         cout << "Exiting the system. Goodbye!" << endl;
         return 0;
            }

    BankAccount account(accNum, accHolder, initialBalance);

    account.displayAccountInfo();

    account.deposit(500.0);
    account.withdraw(200.0);
    account.displayAccountInfo();

    return 0;
}