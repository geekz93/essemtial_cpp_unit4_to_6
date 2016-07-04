#include<iostream>
#include<typeinfo>
#include "Fibonacci.h"
#include "Pell.h"
#include "num_seq_base.h"

using namespace std;

//////////////////////////////////
//ͷ�ļ�<typeid>
//typeid( *ps ):�õ�type_info����
//static_cast<Fibonacci*>( ps ):��
//���͵�ת����������ת��
//dynamic_cast<Fibonacci*>( ps )�� 
//�����͵�ת����ת���ɹ�����true
//�루Fibonacci*��ps������ͬ
//////////////////////////////////


ostream& operator<<(ostream& os, const num_sequence& ns)
{
	return ns.print(os);
}

int main()
{
	Fibonacci fib(10, 1);
	num_sequence *ps = &fib;
	cout << typeid(*ps).name() << endl;
	//Fibonacci *pf = dynamic_cast<Fibonacci*>(ps);
	Fibonacci *pf = (Fibonacci*)ps;

	cout << ps->elem(20) << endl;
	cout << pf->what_am_i() << endl;
	return 0;
}

