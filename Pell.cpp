#include "Pell.h"

vector<int> Pell::_elems;

int Pell::elem(int pos) const
{
	if (!check_integrity(pos))
		return 0;
	if (pos > _elems.size())
		Pell::gen_elems(pos);

	return _elems[pos - 1];
}

void Pell::gen_elems(int pos) const
{//2 * a[n − 1] + a[n - 2] (n > 2)
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

ostream& Pell::print(ostream &os) const
{
	os << Pell::what_am_i() << ": ";
	os << "( " << _beg_pos << ", " << _length << " ) ";
	int elem_pos = _beg_pos - 1;
	int end_pos = elem_pos + _length;

	if (end_pos > _elems.size())
		Pell::gen_elems(end_pos);

	while (elem_pos < end_pos)
		os << _elems[elem_pos++] << ' ';
	return os;
}

bool Pell::
check_integrity(int pos)const
{
	if (!num_sequence::check_integrity(pos))
		return false;

	if (pos > _elems.size())
		Pell::gen_elems(pos);

	return true;
}