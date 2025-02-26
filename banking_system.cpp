#include <iostream>
#include <string>
using namespace std;


class BankAccount {
private:
    string accountHolder;
    int accountNumber;
    double balance;

public:
   
    BankAccount(string name, int accNumber, double initialBalance) {
        accountHolder = name;
        accountNumber = accNumber;
        balance = initialBalance;
    }

    
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: Rs." << amount << endl;
        } else {
            cout << "Deposit amount should be greater than 0." << endl;
        }
    }

    
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrew: Rs." << amount << endl;
        } else if (amount > balance) {
            cout << "Insufficient balance." << endl;
        } else {
            cout << "Withdraw amount should be greater than 0." << endl;
        }
    }

    
    void checkBalance() {
        cout << "Current balance: Rs." << balance << endl;
    }

    
    void displayAccountInfo() {
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: Rs." << balance << endl;
    }
};

int main() {
    string name;
    int accNumber;
    double initialBalance;

    cout << "Enter Account Holder's Name: ";
    getline(cin, name);
    cout << "Enter Account Number: ";
    cin >> accNumber;
    cout << "Enter Initial Deposit: Rs.";
    cin >> initialBalance;

    BankAccount account(name, accNumber, initialBalance);
    
    int choice;
    
    do {
        cout << "\n===== Bank Menu =====" << endl;
        cout << "1. Deposit Money" << endl;
        cout << "2. Withdraw Money" << endl;
        cout << "3. Check Balance" << endl;
        cout << "4. Account Details" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                double depositAmount;
                cout << "Enter amount to deposit: Rs.";
                cin >> depositAmount;
                account.deposit(depositAmount);
                break;
            }
            case 2: {
                double withdrawAmount;
                cout << "Enter amount to withdraw: Rs.";
                cin >> withdrawAmount;
                account.withdraw(withdrawAmount);
                break;
            }
            case 3:
                account.checkBalance();
                break;
            case 4:
                account.displayAccountInfo();
                break;
            case 5:
                cout << "Exiting system. Thank you!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}