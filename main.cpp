#include<iostream>
#include "BinaryTree.h"
#include "BinaryTree.cpp"
#include<string>
using namespace std;

//di

int main()
{
	BinaryTree<string> bt;
	bt.insert("Piglet");
	bt.insert("Eeyore");
	bt.insert("Roo");
	bt.insert("Tigger");
	bt.insert("Chris");
	bt.insert("Pooh");
	bt.insert("Kanga");
	
	bt.preorder();
	cout << endl;
	bt.remove("Piglet");

	bt.preorder();
	//bt.remove_root();
	return 0;
}

