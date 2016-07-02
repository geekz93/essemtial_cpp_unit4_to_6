#include<iostream>
#include "Fibonacci.h"
#include "Pell.h"
using namespace std;

ostream& operator<<(ostream& os, const num_sequence& ns)
{
	return ns.print(os);
}



int main()
{
	Fibonacci fib(10, 1);
	cout << fib << endl;
	
	Pell pell(10, 1);
	cout << pell << endl;

	Pell pell_02(5, 4);
	cout << pell_02 << endl;

	return 0;
}