/*
This code can be compiled and run ok

This is to sort numbers

usage:
input the numbers, then it will show the sorted version

no input/output file

compile:
g++ -o exercise3 exercise3.cpp

pseudocode:

int m=1,n
float **A
float **B
cin>>n;
new A[m][n]
------------
input_array
for i=1 to n
    cin>>A[m][n]
-------------
printout_array(A,m,n)
for i=1 to n
    cout<<A[m][n]
------------
duplicate_array(A,B,m,n)
for i=1 to n
    B[m][n]=A[m][n]
------------
ins_sort(A,m,n)
for number=2 to n
    key=A[m][number]
    moveitem=number-1
    while moveitem>0 and key<A[i][moveitem]
        A[i][moveitem+1]=A[i][moveitem]
        moveitem--
    A[i][moveitem+1]=key
---------------
printout_array(A,m,n)
is_ascending(A,n)
for i=1 to n
    j=i+1;
    A[0][i]<A[0][j];
    if(i=n)
        cout<<"Great!! It is in ascending order!!"
    else
        cout<<"Warning!! the order is NOT ascending!!"
    i++
----------------
mg_sort(B,p,r)
if (p<r)
    int q=((p+r)/2)
    mg_sort(B,p,q)
    mg_sort(B,q+1,r)

    int n1=q-p+1
    int n2=r-q
    float L[n1+1]
    float R[n2+1]

    for i=1 to n1
        L[i]=B[0][p+i-1]
        i++
    for j=1 to n2
        R[j]=B[0][q+j]
        j++

    L[n1+1]=MAX;
    R[n2+1]=MAX;
    i=1;
    j=1;
    for k=p to r+1
        if (L[i]<=R[j])
            B[0][k]=L[i]
            i++;
        else
            B[0][k]=R[j]
            j++
        k++

*/

#include<iostream>
#include<limits.h>
using namespace std;

void input_array(float**,int,int);
void printout_array(float**,int,int);
void duplicate_array(float**,float**,int,int);
float** ins_sort(float**,int,int);
void is_ascending(float**,int);
void mg_sort(float**,int,int);

int main(){
int m=1;
int n;
float **A;
float **B;

cout<<"Please input n:";
cin>>n;

//create a two-dimensional array
A=new float*[m];
for(int i=0;i<m;i++)
{
    A[i]=new float [n];
}
//create a two-dimensional array
B=new float*[m];
for(int i=0;i<m;i++)
{
    B[i]=new float [n];
}
cout<<"Please input "<<n<<" real numbers:";
input_array(A,m,n);
printout_array(A,m,n);
duplicate_array(A,B,m,n);

A=ins_sort(A,m,n);
cout<<"By insertion sort:";
printout_array(A,m,n);
is_ascending(A,n);

mg_sort(B,1,n);
cout<<"By merge sort:";
printout_array(B,m,n);
is_ascending(B,n);
}

//input numbers into array
void input_array(float**A,int m,int n)
{
    for(int i=0;i<m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>A[i][j];
        }
    }
}

//cout numbers from array
void printout_array(float**A,int m,int n)
{
    for(int i=0;i<m;i++)
    {
        for(int j=1;j<=n;j++)
         {
          cout<<A[i][j];
          if(j!=n)
          cout<<",";
         }
          cout<<endl;
    }

}

//duplicate A array to B
void duplicate_array(float**A,float**B,int m,int n)
{
    for(int i=0;i<m;i++)
    {
        for(int j=1;j<=n;j++)
           B[i][j]=A[i][j];
    }

}

//insertion sort, using A
float** ins_sort(float**A,int m,int n)
{
    float key;
    for(int i=0;i<m;i++)
    {
        for(int number=2;number<=n;number++)
        {
            key=A[i][number];
            int moveitem=number-1;
            //if key is smaller then it's previous number, then change thier order
            while((moveitem>0)&&(key<A[i][moveitem]))
            {
                A[i][moveitem+1]=A[i][moveitem];
                moveitem--;
            }
            A[i][moveitem+1]=key;
        }
    }

  return A;
}

void is_ascending(float**A,int n)
{
    //check whether the order is ascending
    int i;
    for(i=1;i<=n;i++)
    {
        int j=i+1;
        A[0][i]<A[0][j];
    }
    if(i=n)
        cout<<"Great!! It is in ascending order!!"<<endl;
    else
        cout<<"Warning!! the order is NOT ascending!!"<<endl;
}

//merge sort, usung B
void mg_sort(float**B,int p,int r)
{
    //if p=r , then exit the array
    if (p<r)
    {
        int q=((p+r)/2);
        mg_sort(B,p,q);
        mg_sort(B,q+1,r);

        int M=INT_MAX;
        int n1=q-p+1;
        int n2=r-q;
        int i,j;
        float L[n1+1];
        float R[n2+1];

        //input number to left array
        for(i=1;i<=n1;i++)
        L[i]=B[0][p+i-1];
        //input number to rgiht array
        for(j=1;j<=n2;j++)
        R[j]=B[0][q+j];

        //let last array value be MAX
        L[n1+1]=M;
        R[n2+1]=M;
        i=1;
        j=1;

        //input number into array B again with ascending order
        for(int k=p;k<r+1;k++)
        {
            if (L[i]<=R[j])
            {  B[0][k]=L[i];
                i++;
            }
            else
            {
               B[0][k]=R[j];
               j++;
            }
        }
    }
}






