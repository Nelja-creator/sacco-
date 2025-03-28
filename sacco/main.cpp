#include <iostream>
#include<ctime>
#include<iomanip>
using namespace std;

class Depositdata{//class with deposit data
public:
    int accountNumber;
int famerId;
double amount;
time_t timestamp;//changed from int to time_t

Depositdata(int accountNumber,int famerId,double amount){//constructor with the same name as class
    this->accountNumber=accountNumber;
    this->famerId=famerId;
    this->amount=amount;
timestamp=time(0);//gets current time using the time library
}
Depositdata(){}//default constructor
};
class stack{//class for stack to store deposit data
    public:
Depositdata deposits[100];//array to store deposit data objects
int top;

stack(){//constructor containing initialisation of top
top=-1;
}
void deposit(Depositdata data){//function to push deposit data objects into a stack
if(top==99){
    cout<<"you have reached the max account limit,sorry man"<<endl;//prints overflow if stack is full
    //format the timestamp to be readable
    time_t rawtime=deposits[top].timestamp;//declare a variable with same data type as timestamp
    tm*timeinfo=localtime(&rawtime);//time function assigned to address containing the unix time
    char datetime[100];//array to store the time stamp
    strftime(datetime,sizeof (datetime),"%Y-%m-%d-%H-%M-%S",timeinfo);//function to declare style of how we need time to be displayed
    cout<<"timestamp:"<<datetime<<endl;
}else{
top=top+1;
deposits[top]=data;
//format the timestamp to be readable
    time_t rawtime=deposits[top].timestamp;//declare a variable with same data type as timestamp
    tm*timeinfo=localtime(&rawtime);//time function assigned to address containing the unix time
    char datetime[100];//array to store the time stamp
    strftime(datetime,sizeof (datetime),"%Y-%m-%d-%H-%M-%S",timeinfo);//function to declare style of how we need time to be displayed
    cout<<"timestamp:"<<datetime<<endl;
}
}
void withdraw(int famerId,double amount1){//function to withdraw money
if(top==-1){
    cout<<"you don't have any deposits bro!"<<endl;
   //format the timestamp to be readable
    time_t rawtime=deposits[top].timestamp;//declare a variable with same data type as timestamp
    tm*timeinfo=localtime(&rawtime);//time function assigned to address containing the unix time
    char datetime[100];//array to store the time stamp
    strftime(datetime,sizeof (datetime),"%Y-%m-%d-%H-%M-%S",timeinfo);//function to declare style of how we need time to be displayed
    cout<<"timestamp:"<<datetime<<endl;
}
if(deposits[top].amount>=amount1){//access the amount at the top of the stack at the particular time for particular account
        cout<<"enter your farmer Id"<<endl;
cin>>famerId;
Depositdata withdrawal(0,famerId,-amount1);//creates new object withdrawal
   deposit(withdrawal);//adds the negative withdrawal value to the account
   cout<<"you removed"<<amount1<<"successfully"<<endl;
   cout<<"you have"<<deposits[top].amount<<"left"<<endl;

   //format the timestamp to be readable
    time_t rawtime=deposits[top].timestamp;//declare a variable with same data type as timestamp
    tm*timeinfo=localtime(&rawtime);//time function assigned to address containing the unix time
    char datetime[100];//array to store the time stamp
    strftime(datetime,sizeof (datetime),"%Y-%m-%d-%H-%M-%S",timeinfo);//function to declare style of how we need time to be displayed
    cout<<"timestamp:"<<datetime<<endl;

}else{
cout<<"sorry cant remove any money man."<<endl;
//format the timestamp to be readable
    time_t rawtime=deposits[top].timestamp;//declare a variable with same data type as timestamp
    tm*timeinfo=localtime(&rawtime);//time function assigned to address containing the unix time
    char datetime[100];//array to store the time stamp
    strftime(datetime,sizeof (datetime),"%Y-%m-%d-%H-%M-%S",timeinfo);//function to declare style of how we need time to be displayed
    cout<<"timestamp:"<<datetime<<endl;
}
}
Depositdata peek(int accountNumber){//peek function to view balance linked to the deposit data
    if(top==-1){
        cout<<"underflow"<<endl;
        return Depositdata();
    }else{
        for(int i=0;i<=top;i++){
                if(accountNumber==deposits[i].accountNumber){
        cout<<"acc no:"<<deposits[i].accountNumber<<endl;
        cout<<"farmer Id:"<<deposits[i].famerId<<endl;
        cout<<"amount:"<<deposits[i].amount<<endl;
       return deposits[i];
        //format the timestamp to be readable
    time_t rawtime=deposits[i].timestamp;//declare a variable with same data type as timestamp
    tm*timeinfo=localtime(&rawtime);//time function assigned to address containing the unix time
    char datetime[100];//array to store the time stamp
    strftime(datetime,sizeof (datetime),"%Y-%m-%d-%H-%M-%S",timeinfo);//function to declare style of how we need time to be displayed
    cout<<"timestamp:"<<datetime<<endl;
                }
        }
}
}
void prints(){
for(int i=0;i<=top;i++){
    cout<<"farmerId:"<<deposits[i].famerId<<endl;
    cout<<"amount:"<<deposits[i].amount<<endl;

    //format the timestamp to be readable
    time_t rawtime=deposits[i].timestamp;//declare a variable with same data type as timestamp
    tm*timeinfo=localtime(&rawtime);//time function assigned to address containing the unix time
    char datetime[100];//array to store the time stamp
    strftime(datetime,sizeof (datetime),"%Y-%m-%d-%H-%M-%S",timeinfo);//function to declare style of how we need time to be displayed
    cout<<"timestamp:"<<datetime<<endl;
}
}
};
int main()
{
stack depositstack;
int accountNumber;
double amount;
int famerId;
int choice;
do{
cout<<"----------------------------------------------------------------------------------------------------"<<endl;
cout<<"welcome to the SACCO! Thanks for joining us "<<endl;
cout<<"How can we help you today ?"<<endl;

cout<<"choose the corresponding number\n 1.deposit\n 2.withdraw\n 3.viewbalance\n 4.exit\n"<<endl;
cin>>choice;
//checks user choice
    switch(choice){
case 1://deposit
    cout<<"----------------------------------------------------------------------------------------------------"<<endl;
    cout<<"enter your account number"<<endl;
    cin>>accountNumber;
    cout<<"enter your farmer Id"<<endl;
    cin>>famerId;
    cout<<"enter your deposit amount"<<endl;
    cin>>amount;

    depositstack.deposit(Depositdata(accountNumber,famerId,amount));

    break;
case 2://withdrawal
    cout<<"----------------------------------------------------------------------------------------------------"<<endl;
    cout<<"enter the amount to withdraw"<<endl;
    cin>>amount;
    depositstack.withdraw(famerId,amount);

    break;
case 3://view balance
    cout<<"----------------------------------------------------------------------------------------------------"<<endl;
    cout<<"enter account number"<<endl;
    cin>>accountNumber;
depositstack.peek(accountNumber);
    break;
case 4:
    cout<<"----------------------------------------------------------------------------------------------------"<<endl;
    cout<<"exiting...."<<endl;
    break;
default:
    cout<<"----------------------------------------------------------------------------------------------------"<<endl;
    cout<<"invalid input"<<endl;
    }
    //early exit
    int choice2;
    cout<<"----------------------------------------------------------------------------------------------------"<<endl;
    cout<<"finished with nothing else to do and want to exit immediately? 1.yes or 2.no"<<endl;
    cin>>choice2;
    if(choice2==1){
        break;
    }else{
    continue;
    }
}while(choice!=4);
    return 0;
}
