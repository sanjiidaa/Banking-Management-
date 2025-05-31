/* Name- SANJIDA ISLAM
   ID- 20244103105 */
#include <iostream>
using namespace std;

class BankAccount {
public:
    string name;
    int accountNumber;
    double balance;
    double fdrAmount;
    double dpsMonthly;
    double FDR_INTEREST = 0.08;
    double DPS_INTEREST = 0.06;

    BankAccount() {
        name = "";
        accountNumber = 0;
        balance = 0;
        fdrAmount = 0;
        dpsMonthly = 0;
    }
    void setDetails(string accName, int accNo, double initialBalance) {
        name = accName;
        accountNumber = accNo;
        balance = initialBalance;
    }
    void deposit(double amount) {
        balance += amount;
        cout << name << " deposited " << amount << ". New balance: " << balance << endl;
    }
    void withdraw(double amount) {
        if (amount > balance) {
            cout << name << " has insufficient balance!" << endl;
        } else {
            balance -= amount;
            cout << name << " withdrew " << amount << ". New balance: " << balance << endl;
        }
    }
    void createFDR(double amount, int years) {
        if (amount > balance) {
            cout << name << " has insufficient balance for FDR!" << endl;
            return;
        }
        balance -= amount;
        fdrAmount = amount + (amount * FDR_INTEREST * years);
        cout << name << " created FDR for " << years << " years. Maturity amount: " << fdrAmount << endl;
    }
    void createDPS(double monthlyAmount, int years) {
        dpsMonthly = monthlyAmount;
        double total = monthlyAmount * 12 * years;
        double interest = total * DPS_INTEREST;
        double maturity = total + interest;
        cout << name << " created DPS for " << years << " years. Total after maturity: " << maturity << endl;
    }
    void showDetails() {
        cout << "Name: " << name << ", Account No: " << accountNumber
             << ", Balance: " << balance << endl;
    }
};
int main() {
    BankAccount users[10];

    string defaultNames[10] = {
        "Ahmed Tanvir", "Sahinur Islam", "Ismail hossen", "Jahin Jahan", "Selim morsalin",
        "Sahrif Islam", "Azam Ahmed", "Niloy Ahmed", "Golam Faruque", "Hasiba Islam"
    };
    for (int i = 0; i < 10; i++) {
        users[i].setDetails(defaultNames[i], 1001 + i, 1000);
    }
    users[0].deposit(500);
    users[0].withdraw(200);
    users[0].createFDR(700, 2);
    users[0].createDPS(100, 3);

    cout << "\nAll User Details:\n";
    for (int i = 0; i < 10; i++) {
        users[i].showDetails();
    }
    return 0;
}
