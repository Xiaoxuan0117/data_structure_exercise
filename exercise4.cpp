/*
This code can be compiled and run ok.

This is to read the file, and convert the numbers into binary by queue and stock

usage:
input the file name, then it will output the answer

input file:
number.txt

no output file

compile:
g++ -o exercise4 exercise4.cpp

pseudocode:

struct Q{key,prev,next}

*enqueue(head,tail,x){
if head->key==0{
        head->key=x;
        Q *newQ=new Q;
        newQ->key==0;
        newQ->prev=head;
        newQ->next=NULL;
        tail=newQ;
        head->next=tail;
    }
    else{
    Q *newQ=new Q;
    Q *newtail=new Q;
    newQ=tail;
    newQ->key=x;
    newQ->next=newtail;
    newQ->prev=tail->prev;
    newtail->key=0;
    newtail->next=NULL;
    newtail->prev=newQ;
    tail=newtail;
    }
return tail;
}
*dequeue(head,tail){
    number=head->key;
    trans_binary(number);
    head=head->next;
    head->prev=NULL;
return head;
}
------------------------
trans_binary(number){
    inputnumber=number;
    S *top=new S;
    top->bin=-1;
    top->next=NULL;

    while number>0{
        remainder=number%2;
        number=number/2;
        if(remainder==0)
            top=push(top,0);
        else if (remainder==1)
            top=push(top,1);
    }
    cout<<inputnumber<<"->";
    while(!stack_empty(top)){
    top=pop(top);
    }
    ans_bin=top->bin;
    cout<<ans_bin<<endl;
}
----------------------
struct S{bin,next}
----------------------
*push(*top,data){
    if top->bin==-1{
        top->bin=data;
    }
    else{
        S *newS=new S;
        newS->bin=data;
        newS->next=top;
        top=newS;
    }
    return top;
}

*pop(*top){
	ans_bin=top->bin;
        cout<<ans_bin;
        top=top->next;
    return top;
    }
-----------------------
input file name
open file
while inClientFile>>x{
    tail=enqueue(head,tail,x);
}
while !queue_empty{
    head=dequeue(head,tail);

coded by Hsiao Huan Pan, ID: c44071061, email: C44071061@gs.nuku.edu.tw
date: 2020/11/4

*/
#include<iostream>
#include<fstream>
using namespace std;

struct Q{//struct for queue
    int key;//the number
    Q *prev;//point to previous struct
    Q *next;//point to next struct
};

struct S{//struct for stack
    int bin;//the binary number
    S *next;//point to next struct
    };

Q *enqueue(Q *head,Q *tail,int x);//insert number to the queue
Q *dequeue (Q *head,Q *tail);//move number from the queue
bool queue_empty(Q *head,Q *tail);//check whether the queue is empty
void trans_binary(int x);//transform the number to binary
S *push(S *top,int data);//insert number to the stack
S *pop(S *top);//move number from the stack
bool stack_empty(S *top);//check whether the stack is empty


Q *enqueue(Q *head,Q *tail,int x){
    if (queue_empty(head,tail)){//if the queue is empty, then insert number to head
        head->key=x;
        Q *newQ=new Q;//new a Q*, newQ, next to head, and make tail point to newQ
        newQ->key==0;
        newQ->prev=head;
        newQ->next=NULL;
        tail=newQ;
        head->next=tail;
    }
    else{
    Q *newtail=new Q;//new a Q*, newtail, next to origin tail
    tail->key=x;//insert the number to the tail
    tail->next=newtail;//next of tail point to newtail
    newtail->key=0;
    newtail->next=NULL;
    newtail->prev=tail;
    tail=newtail;//tail point to newtail
    }
return tail;
}

Q *dequeue(Q *head,Q *tail){
    int number;
    number=head->key;//save the number be dequeued
    trans_binary(number);//change the number to binary
    head=head->next;//head point to next struct
    head->prev=NULL;
return head;
}

bool queue_empty(Q *head,Q *tail){
if (head->key==0)
    return true;
else
    return false;
}

S *push(S *top,int data){
    if(top->bin==-1){//i have set the default bin of top to be -1.if bin=-1, then insert the number to top
        top->bin=data;
    }
    else{
        S *newS=new S;//new a S*, newS, and insert number to it
        newS->bin=data;
        newS->next=top;
        top=newS;//top point to newS
    }
    return top;
    }

S *pop(S *top){
        int ans_bin;
        ans_bin=top->bin;//save the number be removed
        cout<<ans_bin;
        top=top->next;//make top point to next struct
        return top;
    }

bool stack_empty(S *top){
        if(top->next==NULL){
            return true;}
        else{
            return false;}
    }

void trans_binary(int number){

    int inputnumber=number;//save the origin number form
    int ans_bin;
    S *top=new S;//new the top of satck
    top->bin=-1;//make default bin -1
    top->next=NULL;

    int remainder;
    while(number>0){//if number smaller than 0, then stop the loop
        remainder=number%2;
        number=number/2;//save number as number/2
        if(remainder==0)//push the remainder to the stack
            top=push(top,0);
        else if (remainder==1)
            top=push(top,1);
    }
    cout<<inputnumber<<"->";
    while(!stack_empty(top)){//if the stack is not empty, then remove the struct out
    top=pop(top);
    }
    ans_bin=top->bin;//deepest number in the stack's next point to NULL, and its bin had not been printed out
    cout<<ans_bin<<endl;
}

int main(){

int x;
string file;

Q* head=new Q;//top of queue
Q* tail=new Q;//tail of tail

head->key=0;
head->prev=NULL;
head->next=NULL;

tail=head;

cout<<"File name:";//ask to input which file
cin>>file;

ifstream inClientFile(file,ios::in);//open file
if(!inClientFile)//if file cannot be opened
{
    cerr<<"File could not be opened"<<endl;
    exit(1);
}

while(inClientFile>>x){//read the number in file
    tail=enqueue(head,tail,x);//enqueue numbers to the queue
}
cout<<"The Result:"<<endl;
int n;
while(!queue_empty(head,tail)){
    head=dequeue(head,tail);//out but the binary number
}
}
