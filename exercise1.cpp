/*
    This code can be compiled and run ok.
    this is used to show the sum and product of the numbers input by user and the biggest, second biggest, smallest and second smallest number within them.

    usage:
    input the number you want, and it will show the answer

    no input/output files

    compile:
    g++ -o exersies1 exersies1.cpp

    pseudocode:
    cin>>n;
    new A[n];
    ------------
    sort the numbers:
    insert =A[next];
    if A[moveItem] < A[moveItem - 1]
        then A[moveItem] = A[moveItem - 1];
			moveItem--;
			A[moveItem] = insert;
    ------------
    from A[0] to A[n-1]
    sum = sum + A[i];
    product = product * A[i];
    -------------
    cout<<
    min
    2nd min
    max
    2nd max
    sum
    product
    -------------
    */
#include <iostream>
using namespace std;

int main()
{
	int n;
	int* A;
	int sum = 0;
	int product=1;
	cout<< "Please input a positive integer n larger than 4"<<endl;
	cin >> n;

	//tell how many digit you want to execute
	while(n < 4)
	{
		cout << "!!Warning!!" << n << "is NOT larger than 4!"<<endl;
		cout << "Please input a positive integer n larger than 4"<<endl;
		cin >> n;
	}

	//create a array
	A = new int[n];
	cout << "Please input " << n << " integers:";
	//input numbers to the array
	for (int i = 0; i < n; i++)
	{
		cin >> A[i];
	}

	//retur the number you input
	cout << "Among the " << n << " integers:";
	for (int i = 0; i < n; i++)
	{
		cout<<A[i]<<" ";
	}

	//sort
	int insert;
	for (int next = 1; next < n; next++)
	{
		insert =A[next];
		int moveItem = next;
		while ((moveItem > 0) && (A[moveItem] < A[moveItem - 1]))
		{
			A[moveItem] = A[moveItem - 1];
			moveItem--;
			A[moveItem] = insert;
		}

	}

	//sum
	for (int i = 0; i < n; i++)
	{
		sum = sum + A[i];
	}

	//product
	for (int i = 0; i < n; i++)
	{
		product = product * A[i];
	}

	//cout the result
	cout<<endl<<"min = " << A[0] << endl
		<< "2nd_min = " << A[1] << endl
		<< "max = " << A[n - 1] << endl
		<< "2nd_max = " << A[n - 2] << endl
		<< "sum = " << sum << endl
		<< "product = " << product;
}

