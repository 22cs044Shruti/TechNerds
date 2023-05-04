#include<iostream>
#include<cstring>
#include<fstream>
#include <ctime>
#include <cstdlib>
using namespace std;
class Bank_Account{
public:
string Birthdate,Address,gender,status,Email_add,Qualification,Occupation;
string NameAccHolder,AccType;
long int First_deposit_money,Current_Deposit_money,Withdraw_money,Bank_balance=0;
int Age;
char AdharNum[12],MobileNumb[10],Pancard_Num[10];
long long int AccNum;
void To_create_acc();
void Show_Acc(long long int);
void deposit(long long int);
void To_Withdrawl(long long int);
void Print_Pattern();
};
void Bank_Account::To_create_acc(){

cout<<"Fill up the details to create a new account:"<<endl;
cout<<"Which type of account you want to create??"<<endl
    <<"1).Saving Account 2).Current Account"<<endl;
int n;
cin>>n;
switch(n)
{
case 1:
    cout<<"Creating Saving Account..."<<endl;
    AccType="Saving Account";
    break;
case 2:
    cout<<"Creating Current Account..."<<endl;
    AccType="Current Account";
    break;
default:
    cout<<"Account type is not valid"<<endl;
    break;
    }
if(n==1 || n==2){
 cout<<"Name of account holder: ";
fflush(stdin);
getline(cin,NameAccHolder);
cout<<"Date of birth (DD/MM/YYYY): ";
cin>>Birthdate;
cout<<"Age: ";
cin>>Age;
cout<<"Gender ( MALE / FEMALE / OTHER ): ";
cin>>gender;
cout<<"Status ( NRI / INDIAN ): ";
cin>>status;
cout<<"Address: ";
fflush(stdin);
getline(cin,Address);
cout<<"Qualification: ";
fflush(stdin);
getline(cin,Qualification);
cout<<"Email address: ";
cin>>Email_add;
cout<<"* Aadhar Number ( 12 digits ): ";
cin>>AdharNum;
cout<<"Mobile Number ( 10 digits ): ";
cin>>MobileNumb;
cout<<"Occupation: ";
fflush(stdin);
getline(cin,Occupation);
cout<<"How much amount you want to deposit?? ";
cin>>First_deposit_money;
srand((unsigned) time(0));
AccNum = rand() % 1000000 + 100000; // generate a random 6-digit number
cout << "Account number: " << AccNum << endl;
cout<<"Account is created..."<<endl;
Bank_balance=First_deposit_money+Current_Deposit_money;
}
else{
cout<<"Choose valid Account Type"<<endl;
}
}

void Bank_Account::deposit(long long int x){
cout<<"How much amount you want to deposit?? ";
cin>>Current_Deposit_money;
Bank_balance=First_deposit_money+Current_Deposit_money;
cout<<"Bank Balance: "<<Bank_balance<<" Rs."<<endl;
}
void Bank_Account::Show_Acc(long long int y){
cout<<"Name: "<<NameAccHolder<<endl
    <<"Account Type: "<<AccType<<endl;
cout<<"Balance: "<<Bank_balance<<" Rs."<<endl
    <<"Account number: "<<AccNum<<endl;
}

void Bank_Account::To_Withdrawl(long long int z){
cout<<"How much amount you want to withdraw: ";
cin>>Withdraw_money;
Bank_balance=Bank_balance-Withdraw_money;
cout<<"Remaining Balance: "<<Bank_balance<<" Rs."<<endl;
}
void Bank_Account::Print_Pattern(){
cout<<"************************************"<<endl;
}
int main()
{
    long long int num;
    char option;
    Bank_Account b;
b.Print_Pattern();
cout<<"Hello..."<<endl
    <<"Welcome To our Bank...."<<endl;
b.Print_Pattern();
cout<<endl;
cout<<"1). create new account"<<endl
    <<"2). deposit money to your account"<<endl
    <<"3). withdraw money from your account"<<endl
    <<"4). Show your Account"<<endl
    <<"5). Delete account"<<endl
    <<"6). Exit"<<endl;
b.Print_Pattern();
do{
 cout<<"What you want to do??"<<endl;
 cin>>option;
switch(option)
{
 case '1':
      system("CLS");
      b.Print_Pattern();
      b.To_create_acc();
      b.Print_Pattern();
      break;
 case '2':
      system("CLS");
      b.Print_Pattern();
      cout<<"Enter Bank account number: ";
      cin>>num;
      if(num==b.AccNum){
       b.deposit(num);
      }
      else{
        cout<<"Error!! Please enter a valid account number... "<<endl;
      }
      b.Print_Pattern();
      break;

 case '3':
      system("CLS");
      b.Print_Pattern();
      cout<<"Enter Bank account number: ";
      cin>>num;
      if(num==b.AccNum){
       b.To_Withdrawl(num);
      }
      else{
        cout<<"Error!! Please enter a valid account number... "<<endl;
      }
      b.Print_Pattern();
      break;

 case '4':
      system("CLS");
      b.Print_Pattern();
      cout<<"Enter Bank account number: ";
      cin>>num;
       if(num==b.AccNum){
       b.Show_Acc(num);
       }
      else{
        cout<<"Error!! Please enter a valid account number... "<<endl;
       }
       b.Print_Pattern();
      break;

 case '5':
      system("CLS");
////      Print_Pattern();
      cout<<"Your account is successfully deleted.."<<endl;
      b.Print_Pattern();
 default :
      cout<<"\a";
}
}while(option!='6');
cout<<endl<<"Thanks for your trust and support..."<<endl;
b.Print_Pattern();
return 0;
}
