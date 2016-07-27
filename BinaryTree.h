#ifndef _BINARYTREE_H_
#define _BINARYTREE_H_

#include<iostream>
using namespace std;

//forward declaration
template <typename elemType>
class BinaryTree;

template< typename valType>
class BTnode{
	friend class BinaryTree<valType>;
public:
	BTnode();//Œ¥∂®“Â
	BTnode(const valType &val);

	void insert_value(const valType &val);
	static void lchild_leaf(BTnode *leaf, BTnode *subtree);
	void remove_value(const valType &val, BTnode *& prev);
	void preorder(BTnode *pt, ostream &os=cout);
	void display_val(BTnode *pt, ostream &os);
	void print(BTnode *pt, ostream &os){ os << pt->_val; }

private:
	valType _val;
	int     _cnt;
	BTnode  *_lchild;
	BTnode  *_rchild;
};


template<typename valType>
inline BTnode<valType>::
BTnode(const valType &val)
:_val(val)
{
	_cnt = 1;
	_lchild = _rchild = 0;
}



template <typename elemType>
class BinaryTree{
public:
	BinaryTree();
	BinaryTree(const BinaryTree&);
	~BinaryTree();
	BinaryTree& operator=(const BinaryTree&);

	bool empty(){ return _root == 0; }
	void clear(){ if (_root){ clear(_root); _root = 0; } };
	void insert(const elemType &elem);
	void remove(const elemType &elem);
	void remove_root();
	void preorder(){ preorder(_root); }
	
	//void print(BTnode *pt, ostream &os = cout){ os << pt->_val; };

private:
	BTnode<elemType> *_root;
	void clear(BTnode<elemType>*);
	void copy(BTnode<elemType>*tar, BTnode<elemType>*src);
	void preorder(BTnode<elemType> *pt);
};

template<typename elemType>
inline BinaryTree<elemType>::
BinaryTree() :_root(0)
{}

template<typename elemType>
inline BinaryTree<elemType>::
BinaryTree(const BinaryTree &rhs)
{
	copy(_root, rhs._root);
}

template<typename elemType>
inline BinaryTree<elemType>::
~BinaryTree()
{
	clear();
}

template<typename elemType>
inline BinaryTree<elemType>&
BinaryTree<elemType>::
operator=(const BinaryTree &rhs)
{
	if (this != &rhs)
	{
		clear(); copy(_root, rhs._root);
	}
	return *this;
}





#endif