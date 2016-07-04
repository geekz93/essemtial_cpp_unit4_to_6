#ifndef _PELL_H
#define _PELL_H

#include "num_seq_base.h"
#include <vector>

class Pell : public num_sequence
{
public:
	Pell(int length=1, int beg_pos=1, vector<int>& elems = _elems) :
		num_sequence(elems, length, beg_pos){};
	const char* what_am_i() const{ return "Pell"; }


protected:
	void gen_elems(int pos) const;
	static vector<int> _elems;

};

#endif