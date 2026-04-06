#include <stdio.h>
#include <string.h>

// Structure declaration
struct account
{
    char account_number[12];
    char account_holder_name[50];
    float account_balance;
};
struct account user;
int account_created = 0;
// Create Account
void create_account()
{
    while (1)
    {
        printf("\nEnter 11-Digits Account Number : ");
        scanf("%s", &user.account_number);

        if (strlen(user.account_number) == 11)
        {
            break;
        }
        else
        {
            printf("Invalid Input! Please enter exactly 11 digits account number.\n");
        }
    }
    // Account Holder Details
    printf("Please Enter Account Holder Name : ");
    scanf("%s", &user.account_holder_name);

    // Account Opening Balance

    while (1)
    {
        printf("Please enter opening account balance (Minimum Opening Balance is 500) : ");
        scanf("%f", &user.account_balance);
        if (user.account_balance >= 500)
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
    printf("Account Opening Balance is %.2f", user.account_balance);
}
// Deposit
void deposit()
{
    if (!account_created)
    {
        printf("Please Create an Account! \n");
        return;
    }
    float amount;

    while (1)
    {
        printf("Please enter amount you want to deposit (Minimum amount for deposit is '100' : )");
        scanf("%f", &amount);

        if (amount >= 100)
        {
            break;
        }
        else
        {
            printf("Minimum deposit limit is 100 | Please try again!");
        }
    }
    user.account_balance += amount;
    printf("Thank you, Your amount %.2f succesfully deposit!\n", amount);
    printf("Current Account Balance : %.2f\n", user.account_balance);
}
// Withdraw
void withdraw()
{
    if (!account_created)
    {
        printf("Please Create an Account! \n");
        return;
    }

    float amount;

    while (1)
    {
        printf("Please enter amount you want to withdraw : ");
        scanf("%f", &amount);
        if (amount <= user.account_balance)
        {
            break;
        }
        else
        {
            printf("Insufficient Account Balance. Please try again!\n");
        }
    }
    user.account_balance -= amount;
    printf("Your amount %.2f succesfull withdraw form your account \n", amount);
    printf("Current Account Balance : %.2f\n", user.account_balance);
}
// Check Account Balance
void check_account_balance()
{
    if (!account_created)
    {
        printf("Please Create an Account! \n");
        return;
    }
    printf("Your Current Account Balance is %.2f\n", user.account_balance);
}
// Display Account Holder's Details
void account_details()
{
    if (!account_created)
    {
        printf("Please Create an Account! \n");
        return;
    }
    printf("\nAccount Number : %s\n", user.account_number);
    printf("Account Holder's Name : %s\n", user.account_holder_name);
    printf("Account available balance : %.2f\n", user.account_balance);
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
        printf("|2. Deposite Money to Your Bank Account.       |\n");
        printf("|3. Withdrwal Money form Your Bank Account.    |\n");
        printf("|4. Check Your Current Account Balance.        |\n");
        printf("|5. Check Account Holder's Details.            |\n");
        printf("|6. For Exit                                   |\n");
        printf("|______________________________________________|\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            create_account();
        }
        else if (choice == 2)
        {
            deposit();
        }
        else if (choice == 3)
        {
            withdraw();
        }
        else if (choice == 4)
        {
            check_account_balance();
        }
        else if (choice == 5)
        {
            account_details();
        }
        else if (choice == 6)
        {
            printf("Thank you for doing business with The Syndicate!\n");
            return 0;
        }
        else
        {
            printf("Invalide Choice. Please try again!");
        }

        
    }
    return 0;
}