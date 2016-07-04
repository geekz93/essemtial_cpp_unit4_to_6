#include "Pell.h"

vector<int> Pell::_elems;

void Pell::gen_elems(int pos) const
{
	if (_elems.empty())
	{
		_elems.push_back(1);
		_elems.push_back(2);
	}

	if (_elems.size() < pos)
	{
		int ix = _elems.size();
		int n1 = _beg_pos-1;
		int n2 = _beg_pos;

		for (; ix < pos; ix++)
			_elems.push_back(
			2 * _elems[n2++] + _elems[n1++]);
	}
}
