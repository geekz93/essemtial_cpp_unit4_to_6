#include "class_test.h"
//constructor
Triangular::Triangular()
{
	_length = 1;
	_beg_pos = 1;
	_next = 0;

}

Triangular::Triangular(int len, int beg)
: _length(len > 0 ? len : 1),
_beg_pos(beg > 0 ? beg : 1)
{
	_next = beg - 1;
	int elem_cnt = _beg_pos + _length;

	if (_elems.size() < elem_cnt)
		gen_elements(elem_cnt);
}


Triangular& Triangular::copy(const Triangular &rhs)
{
	//check that the two object are not the same
	if (this != &rhs)
	{
		_length = rhs.length();
		_beg_pos = rhs.beg_pos();
		_next = rhs.beg_pos() - 1;
	}
	return *this;
}

void Triangular::gen_elem_to_value(int val)
{
	int ix = _elems.size();
	if (!ix)
	{
		_elems.push_back(1);
		ix = 1;
	}

	while (_elems[ix - 1] < val &&
		ix < _max_elems)
	{
		//cout << "elems to value: " << ix*(ix+1)/2 << endl;
		_elems.push_back(ix*(ix + 1) / 2);
		++ix;
	}

	if (ix == _max_elems)
		cerr << "Triangular Sequence: oops: value to large "
		<< val << " -- exceeds max size of "
		<< _max_elems << endl;
}

void Triangular::
gen_elements(int length)
{
	if (length < 0 || length > _max_elems)
	{
		cerr << "err..." << endl;
		return;
	}

	if (_elems.size() < length)
	{
		int ix = _elems.size() ? _elems.size() + 1 : 1;
		for (; ix <= length - 1; ++ix)
			_elems.push_back(ix*(ix + 1) / 2);
	}
}



vector<int> Triangular::_elems;
bool Triangular::is_elem(int val)
{
	if (!_elems.size() ||
		_elems[_elems.size() - 1] < val)
		gen_elem_to_value(val);
	vector<int>::iterator found_it;
	vector<int>::iterator end_it = _elems.end();
	found_it = find(_elems.begin(), end_it, val);
	return found_it != end_it;
}

void Triangular::display(int len, int beg_pos, ostream &os)
{
	//没有进行错误处理
	int ix = 0;
	for (; ix < len; ++ix)
		os << _elems[beg_pos - 1 + ix] << " ";
	cout << endl;
}
