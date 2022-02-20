#include "Binarytree.h"

void BinaryTree::show(BinaryTree *&Tree)            
{
	if (Tree != NULL)      
	{
	   show(Tree->left);              
	   cout << Tree->x << '\t';          
	   show(Tree->right);             
	}
}
 
/*Добавили очистку памяти*/
void BinaryTree::del(BinaryTree *&Tree){
   if (Tree != NULL)        
	{
	   del(Tree->left);                
	   del(Tree->right);             
	   delete Tree;               
	   Tree = NULL;                
	}
 
}
 
void BinaryTree::add_Node(int x,BinaryTree *&Tree)
{
	if (NULL == Tree)             
	{
		Tree = new BinaryTree;         
		Tree->x = x;              
		Tree->left = Tree->right = NULL; 
	}
 
                   if (x < Tree->x)   
                      {
                          if (Tree->left != NULL) add_Node(x, Tree->left); 
                          else        
                          {
                              Tree->left = new BinaryTree;                
                              Tree->left->left = Tree->left->right = NULL;   
                              Tree->left->x = x;                     
                          }
                      }
 
                    if (x > Tree->x)           
                      {
                          if (Tree->right != NULL) add_Node(x, Tree->right);
                          else              
                          {
                              Tree->right = new BinaryTree;                
                              Tree->right->left = Tree->right->right = NULL;   
                              Tree->right->x = x;                   
                          }
                      }
}