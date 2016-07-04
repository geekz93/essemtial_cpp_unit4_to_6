#ifndef _NUM_SEQ_BASE_H
#define _NUM_SEQ_BASE_H

#include <iostream>
#include <vector>
using namespace std;

class num_sequence
{
public:
	virtual ~num_sequence(){ }

	virtual int         elem(int pos) const;
	virtual const char* what_am_i() const = 0;
	virtual ostream&    print(ostream &os = cout)const;

	static int          max_elems(){ return _max_elems; }

protected:
	num_sequence(vector<int>& elems, int length = 1, int beg_pos = 1 )
		:_length(length), _beg_pos(beg_pos),_relems(elems){}
	virtual void        gen_elems(int pos) const = 0;
	bool                check_integrity(int pos) const;

	int                 _length;
	int                 _beg_pos;
	vector<int>&        _relems;
	const static int    _max_elems = 1024;
};

inline bool num_sequence::check_integrity(int pos)const
{
	if (pos <= 0 || pos> _max_elems)
	{
		cerr << "err...";
		return false;
	}
	return true;
}

#endif