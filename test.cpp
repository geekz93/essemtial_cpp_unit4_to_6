#include"class_test.h"

int main() 
{
	Constru t;
	Constru t2(12);
	Constru t3(20, 6);
	t.disp_elem();
	cout << "t_name: " << t._name << endl;
	t2.disp_elem();
	cout << "t2_name: "<< t2._name << endl;
	t3.disp_elem();
	return 0;
}
