/*
This code can be compiled and run ok

This is to sort the numbers by heap sort and quick sort

usage:
First, input how many numbers and the range of number you want,and the program will output the sorted array

no input file and output file

compile:
g++ -o hw5 c44071061_hw5.cpp

pseudocode:
printout_array(A,m,n)
    for i=1 to n
        cout<<A[m][n]
---------------------
duplicate_array(A,B,m,n)
    for i=1 to n
        B[m][n]=A[m][n]
---------------------
MAX_HEAPIFY(A,i,n)
    l=2*i;
    r=2*i+1;
    if l<=n and A[0][l]>A[0][i]
        largest=l;
    else
        largest=i;

    if r<= and &A[0][r]>A[0][largest]
        largest=r;
    if largest!=i
        exchange A[0][i] and A[0][largest]
        MAX_HEAPIFY(A,largest,n);
    return A;
---------------------
BUILD_MAX_HEAP(A,n)
    for i<-(n/2) to 1
        MAX_HEAPIFY(A,i,n);
    return A;
---------------------
heap_sort(A,n)
    BUILD_MAX_HEAP(A,n);
    for i<n to 1
        exchange A[0][i] and A[0][1]
        MAX_HEAPIFY(A,1,i-1);
    return A;
---------------------
partition(B,p,r)
    int c=0;
    x=B[c][r];
    i=p-1;
    forj<-p to r-1;j++)
        if(B[c][j]<=x)
            i++;
            exchange B[c][i] and B[c][j]
    exchange B[c][r] and B[c][i+1]
    return i+1;
---------------------
quick_sort(B,int p,int r)
if p<r
    q=partition(B,p,r);
    quick_sort(B,p,q-1);
    quick_sort(B,q+1,r);
---------------------
int main()
---------------------
cout<<"Please input [n, a_min, a_max,random_seed]: "<<endl;
cin>>n>>a_min>>a_max>>random_seed;

srand(random_seed);


A=new int*[m];
for i<-0 to m-1
    A[i]=new int [n];
B=new int*[m];
for i<-0 to m-1
    B[i]=new int [n];


for i<-0 to m-1
    for j<-1 to n
        A[i][j]=rand()%(a_max-a_min+1)+a_min;
        cout<<A[i][j]

duplicate_array(A,B,m,n);

A=heap_sort(A,n);
quick_sort(B,1,n);

cout<<"By heap sort:"
printout_array(A,m,n);

cout<<"By quick sort:"<<endl;
printout_array(B,m,n);

coded by Hsiao-Hsuan Pan, ID: c44071061, email: c44070161@gs.ncku.edu.tw
   date: 2020.11.19
*/
#include<iostream>
#include<stdlib.h>
#include<ctime>
using namespace std;

void printout_array(int**A,int m,int n){
    for(int i=0;i<m;i++)
    {
        for(int j=1;j<=n;j++)
         {
          cout<<A[i][j];//output
          if(j<n)
          cout<<",";
         }
          cout<<endl;
    }

}

void duplicate_array(int**A,int**B,int m,int n){
    for(int i=0;i<m;i++)
    {
        for(int j=1;j<=n;j++)
           B[i][j]=A[i][j];//asssign A to B
    }

}

int **MAX_HEAPIFY(int**A,int i,int n){
int l,r,largest;
l=2*i;//left child
r=2*i+1;//right child
if(l<=n&&A[0][l]>A[0][i])//if left child bigger than length,n,and parent, then assign l to largest
    largest=l;

else
    largest=i;

if(r<=n&&A[0][r]>A[0][largest])//if right child bigger than length,n,and parent, then assign l to largest
    largest=r;
if(largest!=i){//exchange parent and child
    int key=A[0][i];
    A[0][i]=A[0][largest];
    A[0][largest]=key;
    A=MAX_HEAPIFY(A,largest,n);
    }
   return A;
}

int**BUILD_MAX_HEAP(int**A,int n){
        for(int i=(n/2);i>0;i--){
            A=MAX_HEAPIFY(A,i,n);
        }
        return A;
}

int**heap_sort(int**A,int n){
    A=BUILD_MAX_HEAP(A,n);//build a max heap array
    for(int i=n;i>1;i--)
    {
        int key;
        //exchange first and last
        key=A[0][i];
        A[0][i]=A[0][1];
        A[0][1]=key;
        A=MAX_HEAPIFY(A,1,i-1);//do max heap in 1 to i-1
    }
    return A;
}

int partition(int **B,int p,int r){
    int c=0;
    int key1,key2,x,i;
    x=B[c][r];
    i=p-1;
    for(int j=p;j<=r-1;j++){//if B[][j] is smaller than pivot, then exchange B[][j] with B[][i++]
        if(B[c][j]<=x){
        i++;
        key1=B[c][i];
        B[c][i]=B[c][j];
        B[c][j]=key1;
        }
    }
    key2=B[c][r];
    B[c][r]=B[c][i+1];
    B[c][i+1]=key2;
    return i+1;
}

void quick_sort(int **B,int p,int r){
if(p<r){
    int q;
    q=partition(B,p,r);
    quick_sort(B,p,q-1);
    quick_sort(B,q+1,r);
}
}

int main(){

int n,a_min,a_max,random_seed;
int m=1;

cout<<"Please input [n, a_min, a_max,random_seed]: (rendom_seed can be any number)"<<endl;
cin>>n>>a_min>>a_max>>random_seed;

srand(random_seed);//make numbers random

int **A;
int **B;

A=new int*[m];
for(int i=0;i<m;i++)
{
    A[i]=new int [n];
}

B=new int*[m];
for(int i=0;i<m;i++)
{
    B[i]=new int [n];
}

for(int i=0;i<m;i++){
    for(int j=1;j<=n;j++)
    {
        A[i][j]=rand()%(a_max-a_min+1)+a_min;//randomly choose number between a_max and a_min
        cout<<A[i][j]<<endl;
    }
}
duplicate_array(A,B,m,n);


A=heap_sort(A,n);
quick_sort(B,1,n);

cout<<"By heap sort:"<<endl;
printout_array(A,m,n);

cout<<"By quick sort:"<<endl;
printout_array(B,m,n);




}
