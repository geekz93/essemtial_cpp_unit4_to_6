#include"class_test.h"

int main() 
{
	Stack stackTest;
	string elem;
	
	while (cin >> elem && !stackTest.full())
		stackTest.push(elem);
	if (stackTest.empty())
	{
		cout << "stack is empty..." << endl;
		return 0;
	}

	stackTest.peek(elem);
	cout << '\n' << "read in " << stackTest.size() << " string!\n";
	cout << "The string, in reverse order:\n";

	while (stackTest.size())
	if (stackTest.pop(elem)) cout << elem << ' ';
	cout << endl;

	return 0;
}
