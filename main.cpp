#include <iostream>
#include<ctime>
#include<iomanip>
using namespace std;

class Depositdata{//class with deposit data
public:
int famerId;
double amount;
time_t timestamp;//changed from int to time_t

Depositdata(int famerId,double amount){//constructor with the same name as class
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
void pushs(Depositdata data){//function to push deposit data objects into a stack
if(top==99){
    cout<<"overflow"<<endl;//prints overflow if stack is full
}else{
top=top+1;
deposits[top]=data;
}
}
void prints(){
for(int i=0;i<=top;i++){
    cout<<"farmerId:"<<deposits[i].famerId<<endl;
    cout<<"amount:"<<deposits[i].amount<<endl;
    cout<<"Unix timestamp:"<<deposits[i].timestamp<<endl;

    //format the timestamp to be readable
    time_t rawtime=deposits[i].timestamp;//declare a variable with same data type as timestamp
    tm*timeinfo=localtime(&rawtime);//time function assigned to address containing the unix time
    char datetime[100];//array to store the time stamp
    strftime(datetime,sizeof (datetime),"%Y-%m-%d-%H-%M-%S",timeinfo);//function to declare style of how we need time to be displayed
    cout<<"human Readable timestamp:"<<datetime<<endl;
}
}
};
int main()
{
stack depositstack;

//create deposits
Depositdata deposit1(1,50000);

//push deposits into stack
depositstack.pushs(deposit1);

//print the stack currently
depositstack.prints();
    return 0;
}
