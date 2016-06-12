#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Stack
{
public:
	bool push(const string &elem);
	bool pop(string &elem);
	bool peek(string &elem);

	bool empty();
	bool full();

	int size();
private:
	vector<string> _stack;

};

inline bool Stack::empty(){ return(_stack.empty()); }
inline bool Stack::full(){ return(_stack.size() == _stack.max_size()); }
inline int Stack::size(){ return(_stack.size()); }


