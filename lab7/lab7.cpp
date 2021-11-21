#include <iostream>
#include "Binarytree.cpp"
using namespace std;


int main(){
    
    BinaryTree tree {10, 50};

    tree.addTree();
    tree.printTree();

    return 0;
}