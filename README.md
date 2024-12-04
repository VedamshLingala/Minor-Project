# Banking System - DSA Project

This project is a simple banking system designed using C++ to demonstrate various data structures and basic banking operations like deposit, withdrawal, transfer, and transaction history tracking.

## Features

- *Bank Account Creation:* Allows users to create a bank account with an account number, name, age, and initial balance.
- *Deposit:* Users can deposit money into their account.
- *Withdraw:* Users can withdraw money from their account, with checks for sufficient balance.
- *Transfer:* Users can transfer money between accounts, with transaction history for both sender and receiver.
- *Transaction History:* Displays the transaction history for a user, limited to the last 10 transactions.
- *Account Validation:* Each operation checks if the account number exists in the system.

## Data Structures Used

### 1. *Vector (for Transaction History)*
   - The vector is used for storing the transaction history for each bank account. A vector allows dynamic resizing, and it is ideal for managing a list of transactions where the number of elements can vary. In this project, a vector is used for the following reasons:
     - *Dynamic Size:* It can dynamically store an arbitrary number of transactions.
     - *Flexibility:* Allows the user to display recent transactions or older ones, and to limit the display to a fixed number (e.g., last 10 transactions).
     - *Efficient Access:* It provides efficient random access to transactions by index, allowing easy iteration and manipulation of transactions.

### 2. *Unordered Map (for Bank Accounts)*
   - The unordered_map is used to store the bank accounts, where the account number is the key and the Bank object is the value. An unordered map is ideal for this use case because:
     - *Fast Lookup:* Provides constant time complexity (O(1)) for checking whether an account exists and accessing the corresponding bank details, making account-related operations efficient.
     - *Efficient Insertion and Deletion:* Allows fast insertion of new accounts and checking of existing ones, which is crucial for managing a large number of accounts in a real-world system.

## Classes Used

- *Transaction Class:* Handles the details of a transaction, including transaction number, status, amount, associated account number, and a key for indicating transaction direction (sent/received).
  - *Static Member:* The global_transaction_no ensures that each transaction gets a unique ID.
  
- *Bank Class:* Contains details of a bank account, including account number, name, balance, and associated transactions. It uses a vector to track the transaction history for the account.

- *Pain Class:* This class contains the main logic of the banking system, including operations such as creating new bank accounts, checking balances, depositing and withdrawing money, transferring money between accounts, and displaying transaction history. It manages all bank accounts using an unordered map.

## Operations and Instructions

1. *Create Bank Account:* Enter user details and create a bank account.
2. *Display Balance:* View the current balance of a specified bank account.
3. *Deposit Money:* Deposit a specified amount into the account.
4. *Withdraw Money:* Withdraw a specified amount from the account, checking if the balance is sufficient.
5. *Transfer Money:* Transfer money from one account to another.
6. *Transaction History:* Display the transaction history for a specific bank account.

## Example Workflow

1. Create a new bank account by entering an account number, name, age, and balance.
2. Deposit money into an account.
3. Withdraw money or transfer money to another account.
4. View the transaction history for any account.

## How to Run

1. Clone this repository to your local machine.
2. Compile the code using a C++ compiler.
   ```bash
   g++ -o bank_system bank_system.cpp
