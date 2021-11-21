#include "Binarytree.h"

BinaryTree::BinaryTree(const int &m_length, const int &m_base) : length(m_length){
    tree = new int[m_length];
    for (int i = 0; i < length; i++) tree[i] = 0;
    tree[0] = m_base;
}

BinaryTree::~BinaryTree(){
    delete tree;
}

void BinaryTree::addTree(){
    
}

void BinaryTree::printTree(){
    for (int i = 0; i < length; i++){
        cout << tree[i] << '\t';
    }
}