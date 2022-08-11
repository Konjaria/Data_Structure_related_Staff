#ifndef Assign4_Binarystree_BST_H
#define Assign4_Binarystree_BST_H


#include <iostream>
#include "Treenode.h"


class BST {
	
	TreeNode* root = nullptr;

public:

	BST() = default;//default  constr

	bool IsEmpty();
	
	BST(const BST&); //Copy constructor

	
	~BST(); //Destructor
	
	void In_Order_Traversal(); //Displays the elements of BST  inorder fashion

	void  Pre_Order_Traversal();	// Displays the elements of BST preorder fashion

	void  Post_Order_Traversal();  // Displays the elements of BST postorder fashion
	
	void Insert_an_item (Datatype item);  //Inserts item in BST
	
	void Delete(Datatype fet_deleted);   //Deletes given item form BST if it is in so
	
	bool Search(Datatype data);  //Searchs item in BST and retuns true if it is found else returns false 

	//searches with boolean if it is true finds it depth and then traverse

	BST& operator =(const BST&);  //Overloading assignment operator

	void Display_Tree(std::ostream&);

	void Search_find_Depth(int Key);

	bool iterative_Search(Datatype);

	void Insert_an_item_iteratively(Datatype);
	
	void Delete_an_item_iteratively(Datatype);

private:
	//  Helper functionalities in the class private section
	void HelpInCopy(TreeNode*);  //Copy Constructor Helper 
	//Destructor Helper
	void HelpInDelete(TreeNode*&);
	//Inoder traversial helper
	void In_Order_Traversal(TreeNode*);
	//Postorder traversial helper
	void  Post_Order_Traversal(TreeNode*);
	//Preorder traversial helper
	void  Pre_Order_Traversal(TreeNode*);
	//Insertion helper
	void Insert_an_item (TreeNode*&, Datatype);
	//Deletiong helper
	void Delete(TreeNode*&, Datatype);
	//Search helper
	bool Search(TreeNode*, Datatype);
	//Search iteratively
};

#endif