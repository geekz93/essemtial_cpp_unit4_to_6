#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<list>
#include<fstream>

#define CopySize 512
using namespace std;
//copy file


int main(int argc, char* argv[])
{
	if (argc < 3)
	{
		cerr << "arguement err..." << endl;
		return 1;
	}
	enum FileName
	{
		Exe,OldFile,NewFile
	};

	ifstream ifile(argv[OldFile], ios_base::binary|ios_base::app);
	ofstream ofile(argv[NewFile], ios_base::binary | ios_base::app);
	

	char *c = new char[CopySize]();
	
	ifile.read(c, CopySize);
	while (ifile.gcount() == CopySize)
	{
		ofile.write(c, CopySize);
		ifile.read(c, CopySize);
	}
	//ofile.write(c, sizeof(c));
	ofile.write(c, ifile.gcount());
	ifile.close();
	ofile.close();
	//int ReadNum = ifile.gcount();
	//cout << ifile.gcount() << endl;

	return 0;
}
