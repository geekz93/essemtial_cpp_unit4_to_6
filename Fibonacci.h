#ifndef _NUM_SEQ_DERIVED_H
#define _NUM_SEQ_DERIVED_H

#include "num_seq_base.h"
#include<vector>

class Fibonacci : public num_sequence
{
public:
	Fibonacci(int len = 1, int beg_pos = 1, vector<int>& elems = _elems)
	: num_sequence(elems, len, beg_pos){}
	
	const char* what_am_i() const{ return "Fibonacci"; }


protected:
	virtual void        gen_elems(int pos) const;
	static vector<int>  _elems;
};



#endif