#include<iostream>
#ifndef _CLASS_TEST_H
#define _CLASS_TEST_H

#include<vector>
#include<algorithm>
#include "Triangular_iterator.h"
using namespace std;

class Triangular
{
	friend class Triangular_iterator;
public:
	typedef Triangular_iterator iterator;
	Triangular();
	Triangular(int, int);
	int length() const{ return _length; }
	int beg_pos() const{ return _beg_pos; }
	Triangular& copy(const Triangular &rhs);

	Triangular_iterator begin() const{ return Triangular_iterator(_beg_pos); }
	Triangular_iterator end() const{ return Triangular_iterator(_beg_pos + _length); }
	//static functions
	bool is_elem(int val);
	static void gen_elements(int length);
	static void gen_elem_to_value(int val);
	static void display(int len, int beg_pos, ostream &os = cout);

private:
	int _length;
	int _beg_pos;
	mutable int _next;

	static const int _max_elems = 1024;
	static vector<int> _elems;


};

#endif