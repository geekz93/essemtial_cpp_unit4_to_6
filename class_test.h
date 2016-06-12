#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Constru
{
public:
	Constru();
	Constru(int len);
	Constru(int len, int pos);
	void disp_elem(){ cout << _a << " " << _b << endl; }
	int _a;
	int _b;
	string _name;
};
