#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <iostream>
using namespace std;

class BinaryTree{
public:
    BinaryTree(const int &m_length, const int &m_base);
    ~BinaryTree();

    void addTree();
    void printTree();

private:
    int length;
    int* tree;
};
#endif