#include "class_test.h"
bool Stack::push(const string &elem)
{
	if (full())
	{
		cout << "it full...";
		return false;
	}

	_stack.push_back(elem);
	return true;
}

bool Stack::pop(string &elem)
{
	if (empty())
	{
		cout << "it empty...";
		return false;
	}
	elem = _stack.back();
	_stack.pop_back( );
	return true;
}

bool Stack::peek(string &elem)
{
	if (empty())
	{
		cout << "it empty...";
		return false;
	}

	elem = _stack.back();
	return true;
}