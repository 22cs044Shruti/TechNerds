#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;
class Bank_Account{
public:
string Birthdate,Address,gender,status,Email_add,Qualification,Occupation;
int Age;
char AdharNum[12],MobileNumb[10],Pancard_Num[10];
    void To_create_acc();
    void Deposit();
    void To_Withdrawl();
};
long long int AccNum;
string NameAccHolder,AccType;
long int First_deposit_money,Current_Deposit_money,Withdrawl_money,Bank_balance=0;
 void Show_Acc();

void Bank_Account::To_create_acc(){
cout<<"Hello..."<<endl
    <<"....Welcome To DSD Bank...."<<endl
    <<"Enter: "<<endl;
cout<<"Enter Account Number: ";
cin>>AccNum;
cout<<"Name of account holder: ";
cin>>NameAccHolder;
cout<<"Date of birth: ";
cin>>Birthdate;
cout<<"Age: ";
cin>>Age;
cout<<"Gender: ";
cin>>gender;
cout<<"Status(NRI/INDIAN): ";
cin>>status;
cout<<"Address: ";
cin>>Address;
cout<<"Qualification: ";
cin>>Qualification;
cout<<"Email address: ";
cin>>Email_add;
cout<<"Aadhaar Number: ";
cin>>AdharNum;
cout<<"Mobile Number: ";
cin>>MobileNumb;
cout<<"Occupation: ";
cin>>Occupation;
cout<<"How much amount you want to deposit?? ";
cin>>First_deposit_money;
cout<<"Which type of account you want to create??"<<endl<<"1).Saving Account 2).Current Account"<<endl;
cin>>AccType;
cout<<"Account is created..."<<endl;
}

void Show_Acc(){
cout<<"Name: "<<NameAccHolder<<endl
    <<"Account Type: "<<AccType<<endl
    <<"Balance: "<<Bank_balance<<endl
    <<"Account number: "<<AccNum<<endl;
}

void Bank_Account::Deposit(){
   cout<<"How much amount you want to deposit: ";
   cin>>Current_Deposit_money;
   First_deposit_money+=Current_Deposit_money;
   cout<<"Total Balance: "<<First_deposit_money;
}

void Bank_Account::To_Withdrawl(){
    cout<<"How much amount you want to widrawl: ";
    cin>>Withdrawl_money;
    First_deposit_money+=Withdrawl_money;
    cout<<"Total Balance: "<<First_deposit_money;
}
void write_bank_account();
void display(int n);
int main()
{
    int option,num;
    Bank_Account b;

cout<<"1). To create new account"<<endl
    <<"2). To deposit money to your account"<<endl
    <<"3). To withdraw money from your account"<<endl
    <<"4). To Show your Account"<<endl;
cout<<"What you want to do??"<<endl;
cin>>option;
switch(option)
{
 case 1:
      write_bank_account();
      break;
 case 2:
      cout<<"Enter Bank account number: ";
      cin>>num;
      b.Deposit();
      break;

 case 3:
      cout<<"Enter Bank account number: ";
      cin>>num;
      b.To_Withdrawl();
     break;

 case 4:
    system("CLS");
      cout<<"Enter Bank account number: ";
      cin>>num;
      display(num);
      break;
 default :
    cout<<"\a";
  }
return 0;
}
void write_bank_account()
{
    Bank_Account ba;
    ofstream file;
    file.open("Account_Detail.txt", ios::app);
    ba.To_create_acc();
    file << "Name: " << NameAccHolder << endl;
    file << "Account Type: " << AccType << endl;
    file << "Balance: " << Bank_balance << endl;
    //file << "Account number: " << ba.AccNum << endl;
    file.close();
}


void display(int n){
bool flag=false;
    ifstream file;
    file.open("Account_Detail.txt");
    while(file>> n){
        if(AccNum==n){
            Show_Acc();
            flag=true;
        }
    }
    if(!flag){
        cout<<"Account not found"<<endl;
    }
    file.close();
}
