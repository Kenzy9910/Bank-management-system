#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ENCRYPTION_KEY 'K'

struct Account {
    int accountNumber;
    char name[50];
    float balance;
};

// XOR encryption/decryption
void encryptDecrypt(char *data, int length) {
    for (int i = 0; i < length; i++) {
        data[i] ^= ENCRYPTION_KEY;
    }
}

void createAccount() {
    struct Account acc;
    FILE *fp = fopen("accounts.dat", "ab");
    if (!fp) {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter Account Number: ");
    scanf("%d", &acc.accountNumber);
    printf("Enter Name: ");
    scanf(" %[^\n]", acc.name);
    printf("Enter Initial Balance: ");
    scanf("%f", &acc.balance);

    encryptDecrypt((char *)&acc, sizeof(acc));
    fwrite(&acc, sizeof(acc), 1, fp);
    fclose(fp);

    printf("Account created successfully.\n");
}

void displayAccounts() {
    struct Account acc;
    FILE *fp = fopen("accounts.dat", "rb");
    if (!fp) {
        printf("No accounts found.\n");
        return;
    }
    fwrite(&acc, sizeof(acc), 1, fp);
            found = 1;
            printf("Account updated successfully!\n");
            break;
        }
    }

    fclose(fp);
    if (!found) {
        printf(" Account not found.\n");
    }
}

void deleteAccount() {
    int accNum, found = 0;
    struct Account acc;
    FILE *fp = fopen("accounts.dat", "rb");
    FILE *temp = fopen("temp.dat", "wb");

    if (!fp || !temp) {
        printf(" Unable to access files.\n");
        return;
    }

    printf("\n Enter Account Number to delete: ");
    scanf("%d", &accNum);

    while (fread(&acc, sizeof(acc), 1, fp)) {
        encryptDecrypt((char *)&acc, sizeof(acc));
        if (acc.accountNumber != accNum) {
            encryptDecrypt((char *)&acc, sizeof(acc));
            fwrite(&acc, sizeof(acc), 1, temp);
        } else {
            found = 1;
        }
    }

    fclose(fp);
    fclose(temp);
    remove("accounts.dat");
    rename("temp.dat", "accounts.dat");

    if (found)
        printf("🗸 Account successfully deleted.\n");
    else
        printf(" No account found with that number.\n");
}

int main() {
    int choice;

    printf(" Welcome to the Account Management System\n");

    do {
        printf("\n Please choose an option:\n");
        printf("\n All Accounts:\n");
    while (fread(&acc, sizeof(acc), 1, fp)) {
        encryptDecrypt((char *)&acc, sizeof(acc));
        printf(" Account Number: %d\n", acc.accountNumber);
        printf(" Name: %s\n", acc.name);
        printf(" Balance: %.2f\n\n", acc.balance);
    }

    fclose(fp);
}

void updateAccount() {
    int accNum, found = 0;
    struct Account acc;
    FILE *fp = fopen("accounts.dat", "rb+");

    if (!fp) {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter Account Number to update: ");
    scanf("%d", &accNum);

    while (fread(&acc, sizeof(acc), 1, fp)) {
        encryptDecrypt((char *)&acc, sizeof(acc));
        if (acc.accountNumber == accNum) {
            printf("Enter New Name: ");
            scanf(" %[^\n]", acc.name);
            printf("Enter New Balance: ");
            scanf("%f", &acc.balance);
            encryptDecrypt((char *)&acc, sizeof(acc));
            fseek(fp, -sizeof(acc), SEEK_CUR);
            fwrite(&acc, sizeof(acc), 1, fp);
            found = 1;
            printf(" Account updated.\n");
            break;
        }
    }

    fclose(fp);
    if (!found) printf(" Account not found.\n");
}

void deleteAccount() {
    int accNum, found = 0;
    struct Account acc;
    FILE *fp = fopen("accounts.dat", "rb");
    FILE *temp = fopen("temp.dat", "wb");

    if (!fp || !temp) {
        printf("Error processing files.\n");
        return;
    }

    printf("Enter Account Number to delete: ");
    scanf("%d", &accNum);

    while (fread(&acc, sizeof(acc), 1, fp)) {
        encryptDecrypt((char *)&acc, sizeof(acc));
        if (acc.accountNumber != accNum) {
            encryptDecrypt((char *)&acc, sizeof(acc));
            fwrite(&acc, sizeof(acc), 1, temp);
        } else {
            found = 1;
        }
    }

    fclose(fp);
    fclose(temp);

    remove("accounts.dat");
    rename("temp.dat", "accounts.dat");

    if (found)
        printf(" Account deleted successfully.\n");
    else
        printf(" Account not found.\n");
}

int main() {
    int choice;

    do {
        printf("\n Account Management Menu \n");
        printf("1.  Create Account\n");
        printf("2.  Display All Accounts\n");
        printf("3.   Update Account\n");
        printf("4.  Delete Account\n");
        printf("0.  Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: createAccount(); break;
            case 2: displayAccounts(); break;
