#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <iostream>
using namespace std;

class BinaryTree{
public:
    void show(BinaryTree *&Tree);
    void del(BinaryTree *&Tree);
    void add_Node(int x, BinaryTree *&Tree);

    int x;                           //То, что записываем в дерево
    BinaryTree *left,*right; 
};

ostream& operator<<(ostream &os, const BinaryTree &tree);

#endif