#include<iostream>
#include<typeinfo>
#include "Fibonacci.h"
#include "Pell.h"
#include "num_seq_base.h"

using namespace std;

//////////////////////////////////
//头文件<typeid>
//typeid( *ps ):得到type_info对象
//static_cast<Fibonacci*>( ps ):类
//类型的转换，无条件转化
//dynamic_cast<Fibonacci*>( ps )： 
//类类型的转换，转化成功返回true
//与（Fibonacci*）ps功能相同
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

