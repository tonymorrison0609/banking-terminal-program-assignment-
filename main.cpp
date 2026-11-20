#include <iostream>

using namespace std;

//Forward decleration=============================================================================================
void menu();
void menu1(int user);
int loggin();
void balance_(int user);
void deposit(int user);
void withdraw(int user);
void sendCash(int user);
int findAccount(long long number);
int readChoice();
double readAmount();
int exit_();





//Variables=======================================================================================================
int menu_;
string inputname, inputpassword;
string name[]={"Anthony","Jack","Phile","Prince","Victor"};
string password[]={"117700@bank","Jackemmit@","Bright345","DubaiHabibi","787654$%^"};
long long accno[]={4657345867,2634756879,2635473523,9564735234,3241523487};
double balance[]={5500,34440,450,113,320};


//Read choice=====================================================================================================
int readChoice()
{
    int choice;
    cin>>choice;

    if (cin.fail())
    {
        cin.clear();
        cin.ignore(1000,'\n');
        return -1;
    }
    return choice;
}


//Read amount=====================================================================================================
double readAmount()
{
    double amount;
    cin>>amount;

    if (cin.fail())
    {
        cin.clear();
        cin.ignore(1000,'\n');
        return -1;
    }
    return amount;
}


//Find account====================================================================================================
int findAccount(long long number)
{
    for (int i = 0; i < 5; i++)
    {
        if (accno[i] == number)
        {
            return i;
        }
    }
    return -1;
}


//loggin==========================================================================================================
int loggin()
{
    for (int attempt = 1; attempt <= 3; attempt++)
    {
        cout<<"Enter your name: ";
        cin>>inputname;
        cout<<"Enter your password: ";
        cin>>inputpassword;

        for (int i = 0; i < 5; i++)
        {
            if (inputname == name[i] && inputpassword == password[i])
            {
                cout<<endl;
                cout<<"Welcome "<<name[i]<<". Your account no. is "<<accno[i]<<endl;
                return i;
            }
        }

        cout<<"Incorrect identity or password, please try again"<<endl;
    }

    cout<<"Too many failed attempts. Returning to the main menu."<<endl;
    return -1;
}


//Full Exit=======================================================================================================
int exit_()
{
    cout<<"Thank you for banking with us. Goodbye!"<<endl;
    return 0;
}


//Balance=========================================================================================================
void balance_(int user)
{
    cout<<"Your balance is R"<<balance[user]<<"."<<endl;
}


//Deposit=========================================================================================================
void deposit(int user)
{
    cout<<"Enter amount to deposit: R";
    double amount = readAmount();

    if (amount > 0)
    {
        balance[user] = balance[user] + amount;
        cout<<"R"<<amount<<" deposited. Your new balance is R"<<balance[user]<<"."<<endl;
    }
    else
    {
        cout<<"Invalid amount. The amount must be a number more than 0."<<endl;
    }
}


//Withdraw========================================================================================================
void withdraw(int user)
{
    cout<<"Enter amount to withdraw: R";
    double amount = readAmount();

    if (amount <= 0)
    {
        cout<<"Invalid amount. The amount must be a number more than 0."<<endl;
    }
    else if (amount > balance[user])
    {
        cout<<"Insufficient funds. Your balance is only R"<<balance[user]<<"."<<endl;
    }
    else
    {
        balance[user] = balance[user] - amount;
        cout<<"R"<<amount<<" withdrawn. Your new balance is R"<<balance[user]<<"."<<endl;
    }
}


//Send cash=======================================================================================================
void sendCash(int user)
{
    long long number;

    cout<<"Enter the account number to send to: ";
    cin>>number;

    if (cin.fail())
    {
        cin.clear();
        cin.ignore(1000,'\n');
        cout<<"Invalid account number. Please use numbers only."<<endl;
        return;
    }

    int receiver = findAccount(number);

    if (receiver == -1)
    {
        cout<<"Account not found. Please check the account number."<<endl;
    }
    else if (receiver == user)
    {
        cout<<"You cannot send cash to your own account."<<endl;
    }
    else
    {
        cout<<"Enter amount to send: R";
        double amount = readAmount();

        if (amount <= 0)
        {
            cout<<"Invalid amount. The amount must be a number more than 0."<<endl;
        }
        else if (amount > balance[user])
        {
            cout<<"Insufficient funds. Your balance is only R"<<balance[user]<<"."<<endl;
        }
        else
        {
            balance[user] = balance[user] - amount;
            balance[receiver] = balance[receiver] + amount;
            cout<<"R"<<amount<<" sent to "<<name[receiver]<<". Your new balance is R"<<balance[user]<<"."<<endl;
        }
    }
}


//Menu============================================================================================================
void menu()
{
    menu_ = 0;

    while (menu_ != 2)
    {
        cout<<endl;
        cout<<"================================================================================"<<endl;
        cout<<"                              National Bank of Ghana"<<endl;
        cout<<"================================================================================"<<endl;
        cout<<"1: Loggin"<<endl;
        cout<<"2: Exit"<<endl;
        cout<<"Enter choice: ";
        menu_ = readChoice();
        cout<<""<<endl;

        switch(menu_)
        {
            case 1:
            {
                int user = loggin();
                if (user != -1)
                {
                    menu1(user);
                }
                break;
            }
            case 2:
                exit_();
                break;
            default:
                cout<<"Invalid choice. Please enter 1 or 2."<<endl;
        }
    }
}


//Menu1===========================================================================================================
void menu1(int user)
{
    int choice = 0;

    while (choice != 5)
    {
        cout<<endl;
        cout<<"Logged in as "<<name[user]<<endl;
        cout<<"1: Check balance"<<endl;
        cout<<"2: Deposit"<<endl;
        cout<<"3: Withdrawal"<<endl;
        cout<<"4: Transfer Funds"<<endl;
        cout<<"5: Exit"<<endl;
        cout<<"Enter choice: ";
        choice = readChoice();
        cout<<""<<endl;

        switch(choice)
        {
            case 1:
                balance_(user);
                break;
            case 2:
                deposit(user);
                break;
            case 3:
                withdraw(user);
                break;
            case 4:
                sendCash(user);
                break;
            case 5:
                cout<<"Logging out..."<<endl;
                break;
            default:
                cout<<"Invalid choice. Please enter a number from 1 to 5."<<endl;
        }
    }
}






int main()
{
    menu();

    return 0;
}
