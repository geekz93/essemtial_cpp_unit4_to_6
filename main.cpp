#include<iostream>
#include "LibMat.h"
using namespace std;
//const LibMat& mat, ���õ�print����ҲҪ�� const
void print(const LibMat& mat)
{
	cout << "global print(): print mat.print()\n";
	mat.print();
}

int main()
{
	AudioBook a("Little Prince", "xiuBoli", "this is a story");
	print(a);
	return 0;
}