#include "num_seq_base.h"

int num_sequence::elem(int pos)const
{
	if (!check_integrity(pos))
		return 0;
	if (pos > _relems.size())
		gen_elems(pos);
		return _relems[pos - 1];
}

ostream& num_sequence::print(ostream& os)const
{
	os << what_am_i() << ": ";
	os << "( " << _beg_pos << ", " << _length << " ) ";
	int elem_pos = _beg_pos - 1;
	int end_pos = elem_pos + _length;

	if (end_pos > _relems.size())
		gen_elems(end_pos);

	while (elem_pos < end_pos)
		os << _relems[elem_pos++] << ' ';
	return os;

}