#include <iostream>
#include "Binarytree.cpp"
using namespace std;
 
int main()
{
    BinaryTree *Tree = NULL;                 
	  for (int i=5; i>0; i--) Tree->add_Node(i,Tree); 
	  Tree->show(Tree);                      
	  cout << '\n';
	  Tree->del(Tree);                 
 
	  for (int i=20; i>5; i--) Tree->add_Node(i,Tree);      
	  Tree->show(Tree);                 
	  Tree->del(Tree);                  
}