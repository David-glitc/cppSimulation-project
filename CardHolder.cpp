#include <iostream>
#include <string>
#include<vector>
#include<math.h>

using namespace std;


// define account type enum to hold only possible values
enum Acc_type { Savings, Current, Real };
string ACC;

// define main class to hold card holder details and methods
class Cardholder
{
private:
    // initialize storage objects FOr each cardholder
    string First_Name;
    string Surname;
    Acc_type account_type;
    string card_number;
    int CVC;
    int PIN;
    int account_balance;
    // Account balance setter function definition in private scope

public:

    // constructor
    Cardholder(string first_name, string surname, Acc_type ACC, string cardno, int cvc, int pin, int balance);//default
    Cardholder() {};
    // utility to display instance values
    
    void setAccount_balance(int balance);
    void display()
    {
        

        if (Cardholder::account_type == Acc_type::Savings) {
            ACC = "Savings";
        }
        else if (Cardholder::account_type == Acc_type::Current)
        {
            ACC = "Current";
        }
        else if (Cardholder::account_type == Acc_type::Real)
        {
            ACC = "Real";
        }

        cout << "                                       " << endl;
        cout << "User Name: " << getName() << endl;
        cout << "Account Type: " << ACC << endl;
        cout << "Card Number: " << Cardholder::card_number << endl;
        cout << "CVC: " << Cardholder::CVC << endl;
        cout << "Account Balance:  $" << Cardholder::account_balance<<".00" << endl;
        cout << "Pin: "<< Cardholder::PIN << endl;
        cout << "                                       " << endl;


    }
    // Getters for objects
    string getName() {  
        return First_Name+"  "+Surname;
    };

    Acc_type getAccount_type() {
        return account_type;
    };

    string getCard_number() {
        return card_number;
    };

    int getCVC() {
        return CVC;
    };

    int getPIN() {
        return PIN;
    };

    int heap() { return _get_heap_handle(); };

    int getAccount_balance() {


        return account_balance;
    };


    
};
int CvcGenerator(int start) {
    int result = rand() * 100 % 10 + start;
    return  result;
    
}

void Cardholder::setAccount_balance(int balance)
{
    account_balance = balance;
}

Cardholder::Cardholder(string first_name,string surname, Acc_type ACC, string cardno, int cvc, int pin, int balance) {
    First_Name = first_name;
    Surname = surname;
    account_type = ACC;
    card_number = cardno;
    CVC = cvc;
    PIN = pin;
    account_balance = balance;
};

Acc_type save = Acc_type::Savings;
Acc_type curr = Acc_type::Current;
Acc_type real = Acc_type::Real;



    



Cardholder CreateUser() {
        string Surname;
        string firstname;
        int pin;
        int cvcseed;
        int initialDeposit;
        string Cardno;
        Acc_type AccountType;
        string acc;
        cout << "~~~~~~~~~~~~~~~~~~Create Your new account~~~~~~~~~~~~~~~~~~~\n\n";
        cout << "\t\tInput your First Name: \n";
        cin >> firstname;
        cout << "\t\tInput your Surname Name: \n";
        cin >> Surname;
        cout << "What Type of account do you want to create: \n";
        cin >> acc;
        if (acc == to_string(Acc_type::Savings)) {
            AccountType = Acc_type::Savings;
        };
        if (acc == to_string(Acc_type::Current)) {
            AccountType = Acc_type::Current;
        };
        if (acc == to_string(Acc_type::Real)) {
            AccountType = Acc_type::Real;
        };
    
    
    
        cout << "Enter your preferred pin of four numbers you can easily remember: \n";
        cin >> pin;
        if (to_string(pin).length() < 4 | to_string(pin).length() > 4) {
            cout << "your pin must be four Characters int\n";
        }
        
        cout << "How much Do you want to deposit as your Initial deposit: \n";
        cin >> initialDeposit;
        
        cout << "creating your account.....";
        


        

        Cardno = to_string(CvcGenerator(2137818654));
        cvcseed = CvcGenerator(400);

        
        Cardholder Newuser(firstname, Surname, AccountType, Cardno, cvcseed, pin, initialDeposit);
        cout << endl;
        cout << "New User Added Succecfully..." << endl;
        cout << "This are your details\n";
        Newuser.display();
        cout << "----------Thank you for Banking With Us----------\n";
        return Newuser;

}

void deposit(Cardholder user) {
    int ammount;
    int total;
    cout << "\nHow Much Money would you like to deposit: $";
    cin >> ammount;
    total = user.getAccount_balance() + ammount;
    cout << total << endl;
    user.setAccount_balance(total);
    cout << "\nDeposit successfull!! :) your new balance is: $" + user.getAccount_balance()<<endl;
}
void withdrawl(Cardholder user) {
    int amount;int total;
    cout << "\nHow Much Money would you like to withdrawl: $";
    cin >> amount;
    
    if (amount > user.getAccount_balance()) {
        cout << "\nInsufficient balance :(";


    }
    else {
        int pin;
        int con = 0;
        cout << " Please enter your pin to confirm the transaction: ";
        cin >> pin;
        if (pin == user.getPIN())
        {
            total = user.getAccount_balance() - amount;
            user.setAccount_balance(total);
            cout << "\nsuccessfully withdrew $" << to_string(amount) + " from your account.\n your current balance is : $" << user.getAccount_balance();
        }
        else {
            cout << "you have " << con << "times left";
            cout << "incorrect pin please try again: ";
            con++;
        }
        
        }
}

void getAccount_balance(Cardholder user) {
cout<<"\nYour account balance is: $"<< user.getAccount_balance();
}

void display(Cardholder user) {
    cout << "\n~~~~~~~~~This is your account details~~~~~~~~~\n\n";
    user.display();
}

void getBalance(Cardholder user) {
    cout <<"\nYour account balanace is: $"<< to_string(user.getAccount_balance());
}

Cardholder currentUser;
bool logged;

void prompt() {
    int choice;

        cout << "\nWelocome back " + currentUser.getName() + "\n";
        cout << "select an option for the transaction you want to make\n";
        cout << "\t1. Balance Enquiry\n";
        cout << "\t2. Deposit Money\n";
        cout << "\t3. Withdraw Money\n";
        cout << "\t4. Change Pin\n";
        cout << "\t5. Transfer Money\n";
        cout << "\t6. Display my details\n";
        cout << "\t7. Cancel\n";
        cout << ">>";
        cin >> choice;
    

    // Choices to select from
    switch (choice) {
        case 1:
            getBalance(currentUser);

            break;
        case 2:
            deposit(currentUser);
            break;
        case 3:
            withdrawl(currentUser);
            break;
        case 4:
            // changePin();
            break;
        case 5:
            // trfmoney();
        case 6:
            currentUser.display();
        case 7:

            exit(1);
        default:
            cout << "\nInvalid choice\n";
    }
}


int main()
{
    Cardholder User("David ", "Opuene", save, "1323447988", 232, 2050, 205);
    Cardholder User2("Tokoni ", "Opuene", curr, "3273891047", 231, 2003, 1371);
    Cardholder User3("Glory", " Opuene", real, "3278913347", 663, 1889, 1378943271);
    Cardholder User4("Richard", "Nice", real, "2314753232", 663, 1889, 347232422);
    Cardholder User5("Perez", "Ogunwe", curr, "3278914347", 663, 1889, 32523);
    Cardholder User6("Holando", " Faith", save, "3274413347", 663, 1889, 2343523);


    vector<Cardholder> Customers = { User,User2,User3,User4,User5, User6 };

    cout << "Welcome to Trapedz ATM consoole\n\n";
    cout << "Please insert your card Number:  \n";

    string cardno;
    int create;
    while (true)
    {
        try
        {
            cin >> cardno;
            if (cardno.length() < 10) {
                cout << "\nPlease your account number should be ten (10) digits. Try again: ";
                logged = false;
            }
            for (auto&& i : Customers)
            {
                if (i.getCard_number() == cardno)
                {
                    currentUser = i;
                    logged = true;
                };
            }
            if (logged == true)
            {
                break;
            }
            else {
                cout << "\nCard not recognised. press 1 to re-try number again or press (2) to create a new account: ";
                cin >> create;
                if (create == 2)
                {
                    Cardholder newbie = CreateUser();

                    Customers.push_back(newbie);
                }
                else {
                    logged = false;
                }
                
            }

        }
        catch (const std::exception& e)
        {
            std::cerr << e.what() << '\n';

        }

    }
    int nu;
    int pin;
    do
    {
        cout << "\nPlease enter your pin: ";
        cin >> pin;
        if (pin != currentUser.getPIN())
        {
            cout << "\nthe pin you entered is incorrect. please try again: ";
        }
        else {
            break;
        }
    } while (pin!=currentUser.getPIN());
    
    
    while (logged == true)
    {
       
       
        prompt();
        cout << "\n Do want to make another transaction! press (1) or press (0) exit\n";
        cin >> nu;
        switch (nu)
        {
        case 1:
            prompt();
            break;
        case 0:
            cout << "\nThanks for Banking with us";
            exit(0);
            break;
        default:
            cout << "You must enter a valid number";
            break;
        }

    }
    return 0;
    
};
