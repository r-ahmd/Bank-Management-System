// ----------Bank Management System------------ //

#include <bits/stdc++.h>
#include <vector>
#include <string>
using namespace std;

class BankAcc{
  private:
    string name;
    int acc_num;
    double balance;
  public:
    BankAcc(string n, int ac, double bl){
      name = n;
      acc_num = ac;
      balance = bl;
    }
    string getName(){
      return name;
    }
    int getAcc(){
      return acc_num;
    }
    double getBal(){
      return balance;
    }
    void deposite(double amount){
        balance = balance+amount;
    }
    void withdraw(double amount){
        if(balance>=amount){
            balance -= amount;
            cout<<"\t\tMoney Withdrawn Successfully...."<<endl;
        }
        else
            cout<<"\t\tInsufficient Balance..!!!!"<<endl;
    }
};

class BankManage{
  private:
    vector<BankAcc> accounts;
    public:
        void Add_acc(string name, int acc_num, double balance){
            accounts.push_back(BankAcc(name, acc_num, balance));
        }
        void Show_acc(){
            cout<<"\t\tAll Account Holders"<<endl;
            for(int i=0; i<accounts.size(); i++){
                cout<<"\tName: "<<accounts[i].getName()<<endl;
                cout<<"\tAccount Number: "<<accounts[i].getAcc()<<endl;
                cout<<"\tBalance: "<<accounts[i].getBal()<<endl<<endl;
            }
        }
        void Search_Acc(int acc){
            cout<<"\t\tAccount Holder "<<endl;
            for(int i=0; i<accounts.size(); i++){
                if(accounts[i].getAcc()==acc){
                    cout<<"\tName: "<<accounts[i].getName()<<endl;
                    cout<<"\tAccount Number: "<<accounts[i].getAcc()<<endl;
                    cout<<"\tBalance: "<<accounts[i].getBal()<<endl;
                }
            }
        }
        BankAcc* find_Acc(int accountNum){
            for(int i=0; i<accounts.size(); i++){
                if(accounts[i].getAcc()==accountNum){
                    return &accounts[i];
                }
            }
        }
};


int main() 
{
  BankManage Bank;
  int choice;
  char op;
  do{
      system("clear");
      cout<<"\t\t:: Bank Management System ::"<<endl;
      cout<<"\t\t\tMain Menu"<<endl;
      cout<<"\t\t 1. Create New Account"<<endl;
      cout<<"\t\t 2. Show All Account"<<endl;
      cout<<"\t\t 3. Search Account"<<endl;
      cout<<"\t\t 4. Deposite Money"<<endl;
      cout<<"\t\t 5. Withdraw Money"<<endl;
      cout<<"\t\t 6. Exit"<<endl;
      cout<<"\t--------------------------------------"<<endl;
      cout<<"\t\tEnter Your Choice:";
      cin>>choice;
      switch(choice){
            case 1:{
                string name;
                int acc_num;
                double balance;
                cout<<"\t\tEnter Name: ";
                cin.ignore();
                getline(cin,name);
                cout<<"\t\tEnter Account Number: ";
                cin>>acc_num;
                cout<<"\t\tEnter Initial Balance: ";
                cin>>balance;
                Bank.Add_acc(name, acc_num, balance);
                cout<<"\t\tAccount Created Successfully...."<<endl;
                break;
            }
            case 2:{
                Bank.Show_acc();
                break;
            }
            case 3:{
                int account_num;
                cout<<"\t\tEnter Account Number: ";
                cin>>account_num;
                Bank.Search_Acc(account_num);
                break;
            }
            case 4:{
                int accountNum;
                double amount;
                cout<<"\t\tEnter Account Number To Deposite Money: ";
                cin>>accountNum;
                BankAcc* account = Bank.find_Acc(accountNum);
                if(account !=NULL){
                    cout<<"\t\tEnter Amount To Deposite: ";
                    cin>>amount;
                    account->deposite(amount);
                    cout<<"\t\t"<<amount<<" Deposite Successfully..."<<endl;
                }
                else
                    cout<<"\t\tAccount Not Found...!!!"<<endl;
                break;
            }
            case 5:{
                int accountNum;
                double amount;
                cout<<"\t\tEnter Account Number To Withdraw Money: ";
                cin>>accountNum;
                BankAcc* account = Bank.find_Acc(accountNum);
                if(account !=NULL){
                    cout<<"\t\tEnter Amount To Withdraw: ";
                    cin>>amount;
                    account->withdraw(amount);
                    cout<<"\t\t"<<amount<<" Withdraw Successfully..."<<endl;
                }
                else
                    cout<<"\t\tAccount Not Found...!!!"<<endl;
                break;
            }
            case 6:{
                cout<<"\t\tExited From the Program";
                exit(1);
                break;
            }
            default:
                cout<<"\t\tError!!"<<endl;
                break;
        }
  cout<<"\t\tDo You Want To Continue or Exit [Yes/No]??";
  cin>>op;
  }while(op=='y'||op=='Y');
  
}
