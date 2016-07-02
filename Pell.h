#ifndef _PELL_H
#define _PELL_H

#include "num_seq_base.h"
#include <vector>

class Pell : public num_sequence
{
public:
	Pell(int length=1, int beg_pos=1) :_length(length), _beg_pos(beg_pos){};

	int         elem(int pos) const;
	const char* what_am_i() const{ return "Pell"; }
	ostream&    print(ostream &os = cout)const;
	bool        check_integrity(int pos)const;

protected:
	void gen_elems(int pos) const;
	int _length;
	int _beg_pos;

	static vector<int> _elems;

};

#endif