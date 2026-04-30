#include <iostream>
#include <string>
using namespace std;

// ==========================================
// 1. Base Class: BankAccount
// ==========================================
class BankAccount {
private:
    // Encapsulation: Making attributes private
    int accountNumber;
    string accountHolderName;
    double balance;

public:
    // Constructor
    BankAccount(int accNum, string name, double initialBalance) {
        accountNumber = accNum;
        accountHolderName = name;
        balance = initialBalance;
    }

    // Virtual Destructor
    virtual ~BankAccount() {}

    // Accessors (Getters & Setters)
    int getAccountNumber() { return accountNumber; }
    string getAccountHolderName() { return accountHolderName; }
    
    double getBalance() { return balance; }
    void setBalance(double newBalance) { balance = newBalance; }

    // Transaction Methods
    virtual void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Successfully deposited: $" << amount << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    virtual void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Successfully withdrawn: $" << amount << endl;
        } else {
            cout << "Insufficient balance or invalid amount!" << endl;
        }
    }

    virtual void displayAccountInfo() {
        cout << "A/C No: " << accountNumber << " | Name: " << accountHolderName << " | Balance: $" << balance;
    }

    // Virtual method for Polymorphism (calculateInterest)
    virtual void calculateInterest() {
        cout << "Interest calculation is not applicable for a standard Bank Account." << endl;
    }
};

// ==========================================
// 2. Derived Class: SavingsAccount
// ==========================================
class SavingsAccount : public BankAccount {
private:
    double interestRate; // in percentage

public:
    SavingsAccount(int accNum, string name, double initialBalance, double rate) 
        : BankAccount(accNum, name, initialBalance) {
        interestRate = rate;
    }

    // Calculates interest based on the balance and interest rate
    void calculateInterest() override {
        double interest = (getBalance() * interestRate) / 100.0;
        cout << "Calculated Interest for Savings Account: $" << interest << endl;
    }

    void displayAccountInfo() override {
        BankAccount::displayAccountInfo();
        cout << " | Type: Savings | Int. Rate: " << interestRate << "%";
    }
};

// ==========================================
// 3. Derived Class: CheckingAccount
// ==========================================
class CheckingAccount : public BankAccount {
private:
    double overdraftLimit;

public:
    CheckingAccount(int accNum, string name, double initialBalance, double limit) 
        : BankAccount(accNum, name, initialBalance) {
        overdraftLimit = limit;
    }

    // Checks if a withdrawal exceeds the overdraft limit
    bool checkOverdraft(double amount) {
        if (amount <= (getBalance() + overdraftLimit)) {
            return true; // Withdrawal is allowed
        }
        return false; // Exceeds limit
    }

    
    void withdraw(double amount) override {
        if (amount > 0) {
            if (amount <= getBalance()) {
                setBalance(getBalance() - amount);
                cout << "Successfully withdrawn: $" << amount << endl;
            } 
            else if (checkOverdraft(amount)) {
                setBalance(getBalance() - amount);
                cout << "Successfully withdrawn using Overdraft: $" << amount << endl;
            } 
            else {
                cout << "Withdrawal failed! Exceeds Overdraft Limit." << endl;
            }
        } else {
            cout << "Invalid withdrawal amount!" << endl;
        }
    }

    void displayAccountInfo() override {
        BankAccount::displayAccountInfo();
        cout << " | Type: Checking | Overdraft Limit: $" << overdraftLimit;
    }
};

// ==========================================
// 4. Derived Class: FixedDepositAccount
// ==========================================
class FixedDepositAccount : public BankAccount {
private:
    int term; 
    double interestRate; 

public:
    FixedDepositAccount(int accNum, string name, double initialBalance, int durationMonths, double rate) 
        : BankAccount(accNum, name, initialBalance) {
        term = durationMonths;
        interestRate = rate;
    }

    // Calculates fixed deposit interest
    void calculateInterest() override {
        double interest = (getBalance() * interestRate * (term / 12.0)) / 100.0;
        cout << "Calculated Fixed Deposit Interest for " << term << " months: $" << interest << endl;
    }

    void withdraw(double amount) override {
        cout << "Withdrawal is not allowed from Fixed Deposit Account before maturity term ends!" << endl;
    }

    void displayAccountInfo() override {
        BankAccount::displayAccountInfo();
        cout << " | Type: Fixed Deposit | Term: " << term << " months";
    }
};

// ==========================================
// Main Function (User-Friendly Menu)
// ==========================================
int main() {
    BankAccount* accounts[100];
    int totalAccounts = 0;
    int choice;

    while (true) {
        cout << "\n========== BANK ACCOUNT MANAGEMENT SYSTEM ==========\n";
        cout << "1. Create New Account\n";
        cout << "2. Deposit Funds\n";
        cout << "3. Withdraw Funds\n";
        cout << "4. Display All Accounts\n";
        cout << "5. Calculate Interest\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            if (totalAccounts >= 100) {
                cout << "=> System is full! Cannot add more accounts.\n";
                continue;
            }

            int type, accNum;
            string name;
            double balance;

            cout << "\n--- Select Account Type ---\n";
            cout << "1. Savings Account\n";
            cout << "2. Checking Account\n";
            cout << "3. Fixed Deposit Account\n";
            cout << "Choice: ";
            cin >> type;

            cout << "Enter Account Number: ";
            cin >> accNum;
            cout << "Enter Account Holder Name: ";
            cin >> name; 
            cout << "Enter Initial Balance: ";
            cin >> balance;

            if (type == 1) {
                double rate;
                cout << "Enter Interest Rate (%): ";
                cin >> rate;
                accounts[totalAccounts] = new SavingsAccount(accNum, name, balance, rate);
                totalAccounts++;
                cout << "=> Savings Account Created Successfully!\n";
            } 
            else if (type == 2) {
                double limit;
                cout << "Enter Overdraft Limit: ";
                cin >> limit;
                accounts[totalAccounts] = new CheckingAccount(accNum, name, balance, limit);
                totalAccounts++;
                cout << "=> Checking Account Created Successfully!\n";
            } 
            else if (type == 3) {
                int term;
                double rate;
                cout << "Enter Term Duration (in months): ";
                cin >> term;
                cout << "Enter Fixed Deposit Interest Rate (%): ";
                cin >> rate;
                accounts[totalAccounts] = new FixedDepositAccount(accNum, name, balance, term, rate);
                totalAccounts++;
                cout << "=> Fixed Deposit Account Created Successfully!\n";
            } 
            else {
                cout << "=> Invalid Account Type!\n";
            }
        } 
        else if (choice == 2) {
            int accNum;
            double amount;
            bool found = false;

            cout << "Enter Account Number: ";
            cin >> accNum;

            for (int i = 0; i < totalAccounts; i++) {
                if (accounts[i]->getAccountNumber() == accNum) {
                    cout << "Enter Amount to Deposit: $";
                    cin >> amount;
                    accounts[i]->deposit(amount);
                    found = true;
                    break;
                }
            }
            if (!found) cout << "=> Account Not Found!\n";
        } 
        else if (choice == 3) {
            int accNum;
            double amount;
            bool found = false;

            cout << "Enter Account Number: ";
            cin >> accNum;

            for (int i = 0; i < totalAccounts; i++) {
                if (accounts[i]->getAccountNumber() == accNum) {
                    cout << "Enter Amount to Withdraw: $";
                    cin >> amount;
                    accounts[i]->withdraw(amount);
                    found = true;
                    break;
                }
            }
            if (!found) cout << "=> Account Not Found!\n";
        } 
        else if (choice == 4) {
            if (totalAccounts == 0) {
                cout << "=> No accounts exist.\n";
            } else {
                cout << "\n--- All Accounts Info ---\n";
                for (int i = 0; i < totalAccounts; i++) {
                    accounts[i]->displayAccountInfo(); // Demonstrates Polymorphism
                    cout << endl;
                }
            }
        } 
        else if (choice == 5) {
            int accNum;
            bool found = false;
            cout << "Enter Account Number: ";
            cin >> accNum;

            for (int i = 0; i < totalAccounts; i++) {
                if (accounts[i]->getAccountNumber() == accNum) {
                    accounts[i]->calculateInterest(); 
                    found = true;
                    break;
                }
            }
            if (!found) cout << "=> Account Not Found!\n";
        } 
        else if (choice == 6) {
            cout << "Exiting the system. Goodbye!\n";
            break;
        } 
        else {
            cout << "Invalid choice! Try again.\n";
        }
    }

    // Memory cleanup
    for (int i = 0; i < totalAccounts; i++) {
        delete accounts[i];
    }

    return 0;
}
