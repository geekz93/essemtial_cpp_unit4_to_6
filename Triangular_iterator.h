#ifndef _TRIANGULAR_H
#define _TRIANGULAR_H

#include "class_test.h"

class Triangular_iterator
{
public:
	Triangular_iterator(int index) :_index(index - 1){}
	//--define operator
	bool operator==(const Triangular_iterator) const;
	bool operator!=(const Triangular_iterator) const;

	int operator*() const;
	int& operator++(); //prefix version
	int operator++(int);//postfix version
private:
	void check_integrity() const;
	int _index;
};


#endif // _TRIANGULAR_H
