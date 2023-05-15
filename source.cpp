// ----------Bank Management System------------ //

#include <iostream>
#include <stdio.h>
#include <conio.h>
using namespace std;

class Bank
{
  char name[100], adr[100], ac_t;
  int balance;
  public:
    void Open_account();
    void Deposite_money();
    void Withdraw_money();
    void Display_account();
};
void Bank :: Open_account()
{
  cout<<"Enter your full name: ";
  cin.ignore();
  cin.getline(name, 100);
  cout<<"Enter your address: ";
  cin.ignore();
  cin.getline(adr, 100);
  cout<<"What type of account you want to open savings(s) or current(c): ";
  cin>>ac_t;
  cout<<"Enter amount for deposite: ";
  cin>>balance;
  cout<<"Your account is created";
}
void Bank :: Deposite_money()
{
  int a;
  cout<<"Enter how much you want to Deposite: ";
  cin>>a;
  balance+=a;
  cout<<"Total amount you have Deposite: \t";
}
void Bank :: Withdraw_money()
{
  float amount;
  cout<<"\n ----Withdraw---- ";
  cout<<"Enter amount to withdraw: ";
  cin>>amount;
  balance-=amount;
  cout<<"Total amount left currently: "<<balance;
  
}

void Bank :: Display_account()
{
  cout<<"Your full name: \t"<<name;
  cout<<"Your address: \t"<<adr;
  cout<<"Type of account that you have opened: \t"<<ac_t;
  cout<<"Amount you have deposite : \t"<<balance;
}

int main() 
{
  int num, x; Bank obj;
  do{
    cout<<"1. Open Account.   \n";
    cout<<"2. Deposite Money. \n";
    cout<<"3. Withdraw Money. \n";
    cout<<"4. Display Account. \n";
    cout<<"5. Exit System. \n";
    cout<<"Select the option from above: \n";
    switch(num)
      {
        case 1:
        system("clear");
        cout<<"1. Open Account.   \n";
        obj.Open_account();
        break;
        case 2:
        system("clear");
        cout<<"2. Deposite Money. \n";
        obj.Deposite_money();
        break;
        case 3:
        system("clear");
        cout<<"3. Withdraw Money. \n";
        obj.Withdraw_money();
        break;
        case 4:
        system("clear");
        cout<<"4. Display Account. \n";
        obj.Display_account();
        break;
        case 5:
        system("clear");
          if(num==5)
            exit(1);
        default:
          cout<<"Wrong option!!! try again \n";
      }
        cout<<"\n Do you want to select next option then press(y) \n";
        cout<<"If you want to exit then press(n) \n";
        x = getch();
        if(x=='n' || x=='N')
          exit(0);
  }while(x=='y' || x=='Y');

  
  getch();
  return 0;
}
