#include<iostream>
#include "BinaryTree.h"
#include "BinaryTree.cpp"
#include<string>
using namespace std;

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
	return 0;
}

