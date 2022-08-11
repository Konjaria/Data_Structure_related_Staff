#include "BST.h"



BST::BST(const BST& B2) {
	HelpInCopy(B2.root);
}//Copty constructor


void BST::HelpInCopy(TreeNode* Root) {
//Iterating inorder to add copy item  with helper functions 
// because of we need to output things  in pre-order traversal methodic (according to the instruction ) I am copying respectively  from original to another one
	if (Root != nullptr) {
		Insert_an_item(Root->data);
		HelpInCopy(Root->right);
		HelpInCopy(Root->left);
	}
}  //Copy Constructor Helper

BST::~BST() {
	HelpInDelete(root);
}    //Destructor 

void BST::HelpInDelete(TreeNode*& Root) {
	if (Root != nullptr) {
		HelpInDelete(Root->left);
		HelpInDelete(Root->right);
		delete Root;
		Root = nullptr;
	}
} //Destructor Helper

void BST::In_Order_Traversal() {
	if (IsEmpty()) {
		std::cout << "\n\n\tBST is Empty" << std::endl;
		return;
	}
	In_Order_Traversal(root);
	std::cout << std::endl;
}// inorder traversal method


void BST:: Pre_Order_Traversal() {
	if (IsEmpty()) {
		std::cout << "\n\n\tBST is Empty" << std::endl;
		return;
	}
	 Pre_Order_Traversal(root);
	std::cout << std::endl;
}//pre-order traversal method 

void BST:: Post_Order_Traversal() {
	if (IsEmpty()) {
		std::cout << "\n\n\tBST is Empty" << std::endl;
		return;
	}
	 Post_Order_Traversal(root);
	std::cout << std::endl;
}

void BST::In_Order_Traversal(TreeNode* Root) {
	if (IsEmpty()) {
		std::cout << "\n\n\tBST is Empty" << std::endl;
		return;
	}
	if (Root != nullptr) {
		In_Order_Traversal(Root->left);
		std::cout <<"\t\t" << Root->data << " ";
		In_Order_Traversal(Root->right);
	}
}//Inorder traversal helper


void BST:: Post_Order_Traversal(TreeNode* Root) {
	if (IsEmpty()) {
		std::cout << "\n\n\tBST is Empty" << std::endl;
		return;
	}
	if (Root != nullptr) {
		 Post_Order_Traversal(Root->left);
		 Post_Order_Traversal(Root->right);
		std::cout <<"\t\t" << Root->data << " ";
	}
}//Postorder traversal helper

void BST:: Pre_Order_Traversal(TreeNode* Root) {
	if (IsEmpty()) {
		std::cout << "\n\n\tBST is Empty" << std::endl;
		return;
	}
	if (Root != nullptr) {
		std::cout <<"\t\t" << Root->data << "  ";
		 Pre_Order_Traversal(Root->left);
		 Pre_Order_Traversal(Root->right);
	}
}//Preorder traversal helper

void BST::Insert_an_item (Datatype data) {
	Insert_an_item (root, data);
}//Insert item in BST

void BST::Insert_an_item (TreeNode*& Root, Datatype data) {
	if (Root == nullptr) {
		//At this point we have found the place to insert the node
		Root = new TreeNode(data);
	}
	else if (Root->data == data) {
		std::cout << "\n\aDuplicate values can not be passed in BST , Value is Already There" << std::endl;
	}
	else if (Root->data < data) {
		Insert_an_item (Root->right, data);
	}
	else if (Root->data > data) {
		Insert_an_item (Root->left, data);
	}
}//Insertion helper

void BST::Delete(Datatype data) {
	Delete(root, data);
}//Deletes item from BST

void BST::Delete(TreeNode*& Root, Datatype data) {
	if (Root == nullptr)
		std::cout << "\a\n\tThere is not "<<data<<" found in Bst We can not delete it" << std::endl;
	else if (Root->data > data)
		Delete(Root->left, data);
	else if (Root->data < data)
		Delete(Root->right, data);
	else {
		//At this point we have found the node that should be deleted
		if (Root->left == nullptr) {
			TreeNode* temp = Root;
			Root = Root->right;
			delete temp;
		}
		else if (Root->right == nullptr) {
			TreeNode* temp = Root;
			Root = Root->left;
			delete temp;
		}
		else if (Root->left != nullptr && Root->right && nullptr) {

			//Lets find max form left subtree
			TreeNode* MaxFromLeftSubTree = Root->left;
			while (MaxFromLeftSubTree->right != nullptr)
				MaxFromLeftSubTree = MaxFromLeftSubTree->right;
			//Exchange values and delete
			Root->data = MaxFromLeftSubTree->data;
			delete MaxFromLeftSubTree;
			MaxFromLeftSubTree = nullptr;
		}
	}
}//Deletiong helper

bool BST::Search(Datatype data) {
	return Search(root, data);
}//Searchs item in BST and retuns boolean


bool BST::Search(TreeNode* Root, Datatype data) {
	if (Root == nullptr)
		return false;
	if (Root->data > data)
		Search(Root->left, data);
	else if (Root->data < data)
		Search(Root->right, data);
	else if (Root->data = data)
		return true;
}//recursively searches

bool BST::iterative_Search(Datatype keyword)
{
	while (root != NULL) {
		if (keyword > root->data)
			root = root->right;
		else if (keyword < root->data)
			root = root->left;
		else
			return true; 
	}
	return false;
}


void BST::Insert_an_item_iteratively(Datatype data) {
	TreeNode* temp = root;
	TreeNode* mom = 0;
	bool found = false;
	while (!found && temp != 0) {
		mom = temp;
		if (data < temp->data)
			temp = temp->left;
		else if (data > temp->data)
			temp = temp->right;
		else
			found = true;
	}
	if (!found) {
		temp = new TreeNode(data);
		if (mom == 0)
			root = temp;
		else if (data < mom->data)
			mom->left = temp;
		else
			mom->right = temp;
	}
	else {
		std::cout << "\n\aDuplicate values can not be passed in BST , Value is Already There" << std::endl;
	}
}

void BST::Delete_an_item_iteratively(Datatype keyvalue) { 
	TreeNode* temp = root;
	TreeNode* mom = 0;
	bool found = false;
	while (!found && temp != 0) {
		mom = temp;
		if (keyvalue < temp->data)
			temp = temp->left;
		else if (keyvalue > temp->data)
			temp = temp->right;
		else
			found = true;
	}
	if (!found)
	{
		std::cout << "\a\nKeyvalue you are providing to delete is not in BST at all we can not delete \n";
		return;
	}
	if(temp->left != 0 && temp->right!= 0)
	{
		TreeNode* temporary = temp->right;
		mom = temp;
		while (temporary->left != NULL)
		{
			mom = temporary;
			temporary = temporary->left;
		}
		temp->data = temporary->data;
		temp = temporary;
	}
	TreeNode* Stree = temp->left;
	if (Stree == 0)
		Stree = temp->right;
	if (mom == 0)
		root = Stree;
	else if (mom->left == temp)
		mom->left = Stree;
	else
		mom->right = Stree;
	//delete temp;
}

//Overloading assignment operator

BST& BST::operator = (const BST& B2) {
	//First of all clearing up this tree
	HelpInDelete(root);
	HelpInCopy(B2.root);
	return *this;
}

void BST::Display_Tree(std::ostream&) {
	if (IsEmpty()) {
		std::cout << "\n\n\tBST is Empty" << std::endl;
		return;
	}
	Pre_Order_Traversal();
}

void BST::Search_find_Depth(int Key)
{
	int depth = 0;
	TreeNode* temp = new TreeNode;
	temp = root;
	while (temp != NULL)
	{
		depth++;
		if (temp->data == Key)
		{
			std::cout << "\nData found at depth : " << depth << std::endl;
			return;
		}
		else if (temp->data > Key)
			temp = temp->left;
		else
			temp = temp->right;
	}
	std::cout << "\nData not found " << std::endl;
	return;
}

bool BST::IsEmpty() {
	return root == NULL;
}