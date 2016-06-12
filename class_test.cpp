#include "class_test.h"

Constru::Constru() :_name("init_name01")
{
	_a = 1, _b = 2;
}

Constru::Constru(int len)
: _name("init_name02")
{
	_a = len, _b = 2;
}

Constru::Constru(int len, int pos)
{
	_a = len, _b = pos;
}