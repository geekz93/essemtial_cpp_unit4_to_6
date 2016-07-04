#include "Fibonacci.h"
#include "num_seq_base.h"

vector<int> Fibonacci::_elems;

//��ʲôʹ����const�����Զ�_elems�����������
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


