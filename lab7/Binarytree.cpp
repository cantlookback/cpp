#include "Binarytree.h"

BinaryTree::BinaryTree(const int &m_length, const int &m_base) : length(m_length){
    tree = new int[m_length];
    for (int i = 0; i < length; i++) tree[i] = 0;
    tree[1] = m_base;
}

BinaryTree::~BinaryTree(){
    delete tree;
}

void BinaryTree::addTree(const int &n, const int &i, const char &dir){
    if (tree[i] == 0){
        tree[i] = n;
        return;
    }
    if (n < tree[i]){
        addTree(n, 2*i, 'L');
    } else {
        addTree(n, 2*i+1, 'R');
    }
}

void BinaryTree::printTree(){
    cout << tree[1] << endl;
    for (int i = 2; i < length; i++){
        cout << tree[i] << ' ';
        if (i == 3 || i == 7 || i == 15){
            cout << endl;
        }
    }
}