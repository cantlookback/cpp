#include <iostream>
#include "Binarytree.cpp"
using namespace std;


int main(){
    
    BinaryTree tree {15, 50};

    tree.addTree(45);
    tree.addTree(43);
    tree.addTree(55);
    tree.addTree(51);
    tree.addTree(53);
    tree.addTree(47);
    
    tree.printTree();

    return 0;
}