#include<iostream>
#include<string>
using namespace std;

class BankAccount{
    private:
        string a_number;
        double balance;
        string ownername;

    public:
        BankAccount(string accnum, string owner, double blc){
            a_number = accnum;
            ownername = owner;
            balance = blc >= 0 ? blc : 0;
        }

        void credit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Credited: $" << amount << ". New Balance: $" << balance << endl;
        } else {
            cout << "Invalid credit amount." << endl;
        }
    }

    void debit(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Debited: $" << amount << ". New Balance: $" << balance << endl;
        } else if (amount > balance) {
            cout << "Insufficient funds to debit $" << amount << "." << endl;
        } else {
            cout << "Invalid debit amount." << endl;
        }
    }

    void displayBalance() const {
        cout << "Account: " << a_number << " | Owner: " << ownername << " | Balance: $" << balance << endl;
    }
};
int main(){

    BankAccount a("123456789", "vina shah", 1000.0);

    a.displayBalance();

    a.credit(500);
    a.debit(300.0);
    a.debit(2000.0);

    a.displayBalance();

    return 0;
}
