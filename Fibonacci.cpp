#include "Fibonacci.h"
#include "num_seq_base.h"

vector<int> Fibonacci::_elems;
int Fibonacci::
elem(int pos)const
{//调用check_interity()的时候不需要作用域
	if (!check_integrity(pos))
		return 0;
	if (pos > _elems.size())
		//为什么需要有作用域
		Fibonacci::gen_elems(pos);

	return _elems[pos - 1];
}

//是什么使用了const还可以对_elems进行添加数据
void Fibonacci::
gen_elems(int pos) const
{
	if (_elems.empty())
	{
		_elems.push_back(1); 
		_elems.push_back(1);
	}

	if (_elems.size() < pos)
	{
		int ix = _elems.size();
		int n_2 = _elems[ix - 2];
		int n_1 = _elems[ix - 1];

		for (; ix < pos; ++ix)
		{
			int elem = n_2 + n_1;
			_elems.push_back(elem);
			n_2 = n_1; n_1 = elem;
		}
	}
}

ostream& Fibonacci::
print(ostream &os)const
{
	os << Fibonacci::what_am_i() << ": ";
	os << "( " << _beg_pos << ", " << _length << " ) ";
	int elem_pos = _beg_pos - 1;
	int end_pos = elem_pos + _length;

	if (end_pos > _elems.size())
		Fibonacci::gen_elems(end_pos);

	while (elem_pos < end_pos)
		os << _elems[elem_pos++] << ' ';
	return os;
}

bool Fibonacci::
check_integrity(int pos)const
{
	if (!num_sequence::check_integrity(pos))
		return false;

	if (pos > _elems.size())
		Fibonacci::gen_elems(pos);

	return true;
}