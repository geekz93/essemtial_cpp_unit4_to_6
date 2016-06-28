#include "Triangular_iterator.h"

void Triangular_iterator::
check_integrity() const
{
	if (_index > Triangular::_max_elems)
		return;

	if (_index > Triangular::_elems.size())
		Triangular::gen_elements(_index);
}

bool Triangular_iterator::operator==(const Triangular_iterator &rhs)
{
	return _index == rhs._index;
}

bool Triangular_iterator::
operator!=(const Triangular_iterator &rhs) const
{
	return _index != rhs._index;
}

int Triangular_iterator::
operator*() const
{
	check_integrity();
	return Triangular::_elems[_index];
}

int& Triangular_iterator::
operator++()
{
	++index;
	check_integrity();
	return Triangular::_elems[_index];
}

int Triangular_iterator::
operator++(int)
{
	check_integrity();
	return Triangular::_elems[_index++];
}