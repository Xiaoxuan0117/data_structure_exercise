/*
This code can be compiled and run ok.

This is to generate a arithmetic test which allows the users to determine how many question they need and the range of number in the question.
This also can show the result of the test and how long it take for the test.

usage:
First, input the number and the range, then it will show the question.
After you have answered all the question, it will show the result of the test.

no input/output file

compile:
g++ -o exercise2 exercise2.cpp

pseudocode:
struct question{
    int type;
    int a,b,c,r,ansc,ansr;
    bool isCorrect;
};
------------------
cin>>n>>l>>u;
t=new question [n];
t_start=time(NULL);
------------------
for(int i=0;i<n;i++)
{
    typeDef(i,t);
-------------------
    if(t[i].type==1)
    {
        t[i].a=GenRanInt(l,u);
        t[i].b=GenRanInt(l,u);
    }
    else if(t[i].type==2)
    {
        t[i].a=GenRanInt(l,u);
        t[i].b=GenRanInt(l,t[i].a);
    }
    else if(t[i].type==3)
    {
        t[i].a=GenRanInt(l,u);
        t[i].b=GenRanInt(1,10);
    }
    else if(t[i].type==4)
    {
        t[i].a=GenRanInt(l,u);
        int m=10; //determine the small one between 10 and t[i].a
        if(t[i].a<10)
        m=t[i].a;
        t[i].b=GenRanInt(1,m);
----------------------
    }
    Print_Q(i,t);
    cin>>t[i].ansc;
    if(Check_Result(i,t)==false)
    f++;
}
t_end=time(NULL);
------------------
for(int i=0;i<n;i++)
{
  Print_WQA(i,t);
}
------------------
r=(n-f)/n*100;
duration=difftime(t_end, t_start);

coded by Xiao-Xiuan Pan, ID:c44071061, email:coco24688642@gmail.com
date:2020.09.23
*/
#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<ctime>
using namespace std;

struct question{
//there are 4 different type of questions,which are addition,substraction, multiplication and division
int type;
int a,b,c,r,ansc,ansr;
bool isCorrect;
};

void typeDef(int,question *);
int GenRanInt(int,int);
void Print_Q(int,question *);
bool Check_Result(int,question *);
void Print_WQA(int,question*);

int main(){

time_t t_start, t_end;
double duration;

srand(time(NULL));

int n,l,u;/*n meas the number of question.
l,u means the range of number can be used in the question.
*/
float f,r;/*f means the number of wrong answer.
r means the average correct rate.*/
cout<<"Please key in how many question do you want to practice: \n";
cin>>n;

cout<<"Please key in the range(two number)\n";
cin>>l>>u;
if(l>u){
    int k=u;
    u=l;
    l=k;
}
f=0;

struct question *t;
t=new question [n];

t_start=time(NULL);

for(int i=0;i<n;i++)
{
    typeDef(i,t);
    if(t[i].type==1)
    {
        t[i].a=GenRanInt(l,u);
        t[i].b=GenRanInt(l,u);
    }
    else if(t[i].type==2)
    {
        t[i].a=GenRanInt(l,u);
        t[i].b=GenRanInt(l,t[i].a);
    }
    else if(t[i].type==3)
    {
        t[i].a=GenRanInt(l,u);
        t[i].b=GenRanInt(1,10);
    }
    else if(t[i].type==4)
    {
        t[i].a=GenRanInt(l,u);
        int m=10;/*determine the small one between 10 and t[i].a*/
        if(t[i].a<10)
        m=t[i].a;
        t[i].b=GenRanInt(1,m);
    }

    Print_Q(i,t);

    if(t[i].type==1||t[i].type==2||t[i].type==3)
        cin>>t[i].ansc;
    else
        cin>>t[i].ansc>>t[i].ansr;

    if(Check_Result(i,t)==false)
    f++;
}

t_end=time(NULL);
duration=difftime(t_end, t_start);

cout<<"================Question of Wrong Answers====================\n";
cout<<"Among the "<<n<<" question, you give "<<f<<" wrong answers :\n";
for(int i=0;i<n;i++)
{
  Print_WQA(i,t);
}
cout<<"----------------Summary of your Test-------------------------\n";
r=(n-f)/n*100;
cout<<"Average correct rate = "<<r<<"%"<<endl;
if(r>=0&&r<=30)
    cout<<"==> Hey! You are worse than an elementary school student!\n";
else if(r>30&&r<=60)
    cout<<"==> Too bad! You require more practice in arithmetics!\n";
else if(r>60&&r<=90)
    cout<<"==> You can do some arithmetic operations, but should be more cautious.\n";
else if(r>90&&r<=100)
    cout<<"==> Well done!I am very impressed by your performance!\n";
cout<<"Totally you take "<<duration<<" second";
}

//define the type randomly
void typeDef(int i,question *Q)
{
    Q[i].type=1+(rand()%4);
}

//generate random number
int GenRanInt(int l,int u){
    int j;

    j=(rand()%(u-l+1)+l);

return j;
}

//cout question
void Print_Q(int i,question *Q){
int I=i+1;/*the number of the question*/
if(Q[i].type==1)
{
    Q[i].c=Q[i].a+Q[i].b;
    cout<<"Q["<<I<<"]: "<<Q[i].a<<" + "<<Q[i].b<<" =? ";
}
else if(Q[i].type==2)
{
    Q[i].c=Q[i].a-Q[i].b;
    cout<<"Q["<<I<<"]: "<<Q[i].a<<" - "<<Q[i].b<<" =? ";
}
else if(Q[i].type==3)
{
    Q[i].c=Q[i].a*Q[i].b;
    cout<<"Q["<<I<<"]: "<<Q[i].a<<" * "<<Q[i].b<<" =? ";
}
else if(Q[i].type==4)
{
    Q[i].c=Q[i].a/Q[i].b;
    Q[i].r=Q[i].a%Q[i].b;
    cout<<"Q["<<I<<"]: "<<Q[i].a<<" / "<<Q[i].b<<" =?...? ";
}}

bool Check_Result(int i,question *Q)
 {
if(Q[i].type==1||Q[i].type==2||Q[i].type==3)
 {
   if(Q[i].c==Q[i].ansc)
    {
        cout<<"Bingo !! Very good !!\n";
        Q[i].isCorrect=1;
        return 1;
    }
    else
    {
        cout<<"!!Wrong!!Correct Answer= "<<Q[i].c<<endl;
        Q[i].isCorrect=0;
        return 0;
    }
 }
 else{
    if(Q[i].c==Q[i].ansc&&Q[i].r==Q[i].ansr)
    {
    cout<<"Bingo !! Very good !!\n";
    Q[i].isCorrect=1;
    return 1;
    }
    else
    {
    cout<<"!!Wrong!!Correct Answer= "<<Q[i].c<<"..."<<Q[i].r<<endl;
    Q[i].isCorrect=0;
    return 0;
    }
 }
}

//correct the question with wrong answer
void Print_WQA(int i,question*Q)
{

    if(Q[i].isCorrect==false)
    {
        if(Q[i].type==1||Q[i].type==2||Q[i].type==3)
        {
        Print_Q(i,Q);
        cout<<"  Ans: "<<Q[i].c<<" ,  NOT "<<Q[i].ansc<<endl;
        }
        else if(Q[1].type==4)
        {
        Print_Q(i,Q);
        cout<<"  Ans: "<<Q[i].c<<Q[i].r<<" ,  NOT "<<Q[i].ansc<<Q[i].ansr<<endl;
        }
    }

}
