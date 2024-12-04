#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;

class Transaction {
public:
    static int global_transaction_no; // Static counter for transaction numbers
    int transaction_no;
    string status;
    string key;
    long int amount;
    long int accNo;

    Transaction() {
        transaction_no = ++global_transaction_no; // Increment and assign unique number
        status = "0";
        amount = 0;
        accNo = 0;
        key = "0";
    }
};

// Initialize the static member
int Transaction::global_transaction_no = 0;

class Bank {
public:
    int age;
    long int bankaccNo;
    string name;
    long int bankbalance;
    vector<Transaction> T;
};

class Pain {
public:
    unordered_map<int, Bank> gsm;

    void display_Instructions() {
        cout << "Enter 1 for entering bank details for new user" << "\n";
        cout << "Enter 2 for displaying bank balance" << "\n";
        cout << "Enter 3 for depositing money" << "\n";
        cout << "Enter 4 for withdrawing money" << "\n";
        cout << "Enter 5 for transferring money" << "\n";
        cout << "Enter 6 for displaying transaction history" << "\n";
        cout << "Enter 0 for displaying instructions" << "\n";
        cout << "Enter -1 for exiting the program" << "\n";
        return;
    }

    void Bank_details(long int BankAccNo, int a, string n, long int BB) {
        Bank B;
        B.age = a;
        B.name = n;
        B.bankbalance = BB;
        gsm[BankAccNo] = B;
        return;
    }

    bool check_AccNo(long int BankAccNo) {
        return gsm.count(BankAccNo) > 0;
    }

    void display_balance(long int BankAccNo) {
        cout << "Your SBI Account balance is " << gsm[BankAccNo].bankbalance << "\n";
    }

    void deposit(long int BankAccNo, long int m) {
        gsm[BankAccNo].bankbalance += m;
        Transaction V;
        V.amount = m;
        V.status = "deposit";
        gsm[BankAccNo].T.push_back(V);
        cout << "Transaction successful. Transaction ID: " << V.transaction_no << "\n";
        return;
    }

    bool withdraw(long int BankAccNo, long int m) {
        if (gsm[BankAccNo].bankbalance >= m) {
            gsm[BankAccNo].bankbalance -= m;
            Transaction V;
            V.amount = m;
            V.status = "withdraw";
            gsm[BankAccNo].T.push_back(V);
            cout << "Transaction successful. Transaction ID: " << V.transaction_no << "\n";
            return true;
        }
        return false;
    }

    bool transfer(long int BankAccNo1, long int m, long int BankAccNo2) {
        if (gsm[BankAccNo1].bankbalance >= m) {
            gsm[BankAccNo1].bankbalance -= m;
            gsm[BankAccNo2].bankbalance += m;

            Transaction V;
            V.amount = m;
            V.status = "sent";
            V.key = "to";
            V.accNo = BankAccNo2;
            gsm[BankAccNo1].T.push_back(V);

            Transaction P;
            P.amount = m;
            P.status = "received";
            P.key = "from";
            P.accNo = BankAccNo1;
            gsm[BankAccNo2].T.push_back(P);

            cout << "Transaction successful. Transaction ID: " << V.transaction_no << "\n";
            return true;
        }
        return false;
    }

    void display_TH(long int BankAccNo) {
        if (!check_AccNo(BankAccNo)) {
            cout << "Bank account is NOT FOUND" << "\n";
            return;
        }

        if (gsm[BankAccNo].T.empty()) {
            cout << "No transaction history for this account.\n";
            return;
        }

        cout << "Transaction history for " << BankAccNo << ":\n";
        int f = 0;
        for (int i = gsm[BankAccNo].T.size() - 1; i >= 0; --i) {
            f++;
            cout << "Transaction ID: " << gsm[BankAccNo].T[i].transaction_no << " | ";
            cout << gsm[BankAccNo].T[i].status << " " << gsm[BankAccNo].T[i].amount;

            if (gsm[BankAccNo].T[i].accNo != 0) {
                cout << " " << gsm[BankAccNo].T[i].key << " " << gsm[BankAccNo].T[i].accNo;
            }
            cout << "\n";

            if (f >= 10) break; // Limit to last 10 transactions
        }

        cout << "Number of transactions that have been done are " << gsm[BankAccNo].T.size() << "\n";
    }
};

int main() {
    cout << "Welcome to SBI BANK\n" << "Please read the instructions carefully\n";
    Pain w;
    w.display_Instructions();
    int choice;
    cout << "\nEnter your choice and press 0 for displaying instructions: ";
    cin >> choice;

    while (choice != -1) {
        switch (choice) {
            case 0:
                w.display_Instructions();
                break;
            case 1: {
                int age;
                long int bankaccNo;
                string nam;
                long int bankbalance;
                cout << "Enter your Bank Account number: ";
                cin >> bankaccNo;
                if (!(w.gsm.count(bankaccNo))) {
                    cout << "Enter your name: ";
                    cin >> nam;
                    cout << "Enter your age: ";
                    cin >> age;
                    cout << "Enter your Bank Balance: ";
                    cin >> bankbalance;
                    w.Bank_details(bankaccNo, age, nam, bankbalance);
                    cout << "Bank account created successfully\n";
                } else {
                    cout << "Bank account already exists\n";
                }
                break;
            }
            case 2: {
                cout << "Enter your bank account number: ";
                long int ba2;
                cin >> ba2;
                if (!(w.check_AccNo(ba2))) {
                    cout << "Bank account is NOT FOUND\n";
                } else {
                    w.display_balance(ba2);
                }
                break;
            }
            case 3: {
                cout << "Enter your bank account number: ";
                long int ba3;
                cin >> ba3;
                if (!(w.check_AccNo(ba3))) {
                    cout << "Bank account is NOT FOUND\n";
                    break;
                } 
                
                cout << "Enter the amount you want to deposit: ";
                long int m3;
                cin >> m3;
                if(m3 < 0) {
                     cout << "Invalid amount entered\n";
                     break;
                }
                w.deposit(ba3, m3);
                
                break;
            }
            case 4: {
                cout << "Enter your bank account number: ";
                long int ba4;
                cin >> ba4;
                if (!(w.check_AccNo(ba4))) {
                    cout << "Bank account is NOT FOUND\n";
                    break;
                } 
                    cout << "Enter the amount you want to withdraw: ";
                    long int m4;
                    cin >> m4;
                    if(m4 < 0) {
                            cout << "Invalid amount entered\n";
                            break;
                        }
                    if (w.withdraw(ba4, m4)) {
                        cout << "Amount " << m4 << " is withdrawn from your bank successfully\n";
                    } else {
                        cout << "Bank balance is not sufficient\n";
                    }
                
                break;
            }
            case 5: {
                cout << "Enter your bank account number: ";
                long int ba51;
                cin >> ba51;
                if (!(w.check_AccNo(ba51))) {
                    cout << "Bank account is NOT FOUND\n";
                    break;
                } 
                long int ba52;
                cout << "Enter the bank account number which you want to transfer the money to: ";
                cin >> ba52;
                if (!(w.check_AccNo(ba52))) {
                        cout << "Bank account is NOT FOUND\n";
                        break;
                 } 
                 cout << "Enter the amount you want to transfer: ";
                 long int m5;
                 cin >> m5;
                 if(m5 < 0) {
                    cout << "Invalid amount entered\n";
                    break;
                 }
                 if (w.transfer(ba51, m5, ba52)) {
                   cout << "Amount " << m5 << " is transferred successfully\n";
                 } 
                    else {
                 cout << "Bank balance is not sufficient\n";
                 }
                    
                
                break;
            }
            case 6: {
                cout << "Enter your bank account number: ";
                long int ba6;
                cin >> ba6;
                w.display_TH(ba6);
                break;
            }
            default:
                cout << "Enter valid number\n";
                break;
        }
        cout << "\nEnter your choice and press 0 for displaying instructions: ";
        cin >> choice;
    }

    return 0;
}
