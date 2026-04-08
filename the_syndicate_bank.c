#include <stdio.h>
#include <string.h>

// Taking Variable
char account_number[12];
char account_holder_name[50];
float account_balance;
int account_created = 0;

// Create Account
void create_account()
{
    while (1)
    {
        printf("\nEnter 11-Digits Account Number : ");
        scanf("%s", account_number);

        if (strlen(account_number) == 11)
        {
            break;
        }
        else
        {
            printf("Invalid Input! Please enter exactly 11 digits account number.\n");
        }
    }

    printf("Please Enter Account Holder Name (First Name) : ");
    scanf("%s", account_holder_name);

    while (1)
    {
        printf("Please enter opening account balance (Minimum Opening Balance is 500) : ");
        scanf("%f", &account_balance);
        if (account_balance >= 500)
        {
            break;
        }
        else
        {
            printf("Minimum Opening Balance is '500'\n");
        }
    }

    account_created = 1;
    printf("Thank You for opening account in The Syndicate Bank\n");
    printf("Account Created Successfully\n");
    printf("Account Opening Balance is %.2f\n", account_balance);
}

// Deposit
void deposit()
{
    if (!account_created)
    {
        printf("Please Create an Account!\n");
        return;
    }

    float amount;

    while (1)
    {
        printf("Please enter amount you want to deposit (Minimum amount is 100) : ");
        scanf("%f", &amount);

        if (amount >= 100)
        {
            break;
        }
        else
        {
            printf("Minimum deposit limit is 100 | Please try again!\n");
        }
    }

    account_balance += amount;
    printf("Thank you, Your amount %.2f successfully deposited!\n", amount);
    printf("Current Account Balance : %.2f\n", account_balance);
}

// Withdraw
void withdraw()
{
    if (!account_created)
    {
        printf("Please Create an Account!\n");
        return;
    }

    float amount;

    while (1)
    {
        printf("Please enter amount you want to withdraw : ");
        scanf("%f", &amount);

        if (amount <= account_balance)
        {
            break;
        }
        else
        {
            printf("Insufficient Account Balance. Please try again!\n");
        }
    }

    account_balance -= amount;
    printf("Your amount %.2f successfully withdrawn from your account\n", amount);
    printf("Current Account Balance : %.2f\n", account_balance);
}

// Check Balance
void check_account_balance()
{
    if (!account_created)
    {
        printf("Please Create an Account!\n");
        return;
    }
    printf("Your Current Account Balance is %.2f\n", account_balance);
}

// Account Details
void account_details()
{
    if (!account_created)
    {
        printf("Please Create an Account!\n");
        return;
    }
    printf("\nAccount Number : %s\n", account_number);
    printf("Account Holder's Name : %s\n", account_holder_name);
    printf("Account Available Balance : %.2f\n", account_balance);
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|");
        printf("\n\t  Welcome to The Syndicate Bank\n");
        printf("\t   Please select your option\n");
        printf("|**------------------------------------------**|\n");
        printf("|1. Open an Account.                           |\n");
        printf("|2. Deposit Money to Your Bank Account.        |\n");
        printf("|3. Withdrawal Money from Your Bank Account.   |\n");
        printf("|4. Check Your Current Account Balance.        |\n");
        printf("|5. Check Account Holder's Details.            |\n");
        printf("|6. Exit                                       |\n");
        printf("|______________________________________________|\n");

        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid Choice\n");
            continue;
        }

        if (choice == 1)
            create_account();
        else if (choice == 2)
            deposit();
        else if (choice == 3)
            withdraw();
        else if (choice == 4)
            check_account_balance();
        else if (choice == 5)
            account_details();
        else if (choice == 6)
        {
            printf("Thank you for doing business with The Syndicate!\n");
            return 0;
        }
        else
            printf("Invalid Choice. Please try again!\n");
    }

    return 0;
}
