🏦 Account Management System in C

This is a simple command-line *Account Management System* written in C. It allows users to:

- Create new accounts
- View existing accounts
- Update account information
- Delete accounts

All account data is stored securely using basic XOR encryption.

🔧 Features

- *Create Account*: Add a new account with a unique account number, name, and initial balance.
- *View Accounts*: Display all existing accounts with their details.
- *Update Account*: Modify the name and balance of an existing account.
- *Delete Account*: Remove an account from the system.

🔐 Security

Account data is stored in a binary file (`accounts.dat`) with simple XOR encryption to provide basic security.

🚀 Getting Started

Prerequisites

- A C compiler (e.g., `gcc`)

Compilation
To compile the program, run:

```bash
gcc account_management.c -o account_management
```

Usage

After compiling, run the program:

```bash
./account_management
```

Follow the on-screen prompts to interact with the system.

📂 File Structure

- `account_management.c`: The main C source code file.
- `accounts.dat`: Binary file where account information is stored.
- `README.md`: This file.

📄 License

This project is licensed under the MIT License.

🙏 Acknowledgments

Inspired by the need for a simple account management system for educational purposes.
