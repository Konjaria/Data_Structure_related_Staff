#ifndef Assign4_Bsth_Treenode_H
#define Assign4_Bsth_Treenode_H
typedef int Datatype; // do some implementations with integers then another data types and soon
class TreeNode {
	friend class BST;//it should be friend according to our instruction
public:
	Datatype data = 0;
	TreeNode* left = nullptr, * right = nullptr; // by default data is initialized  to zero and the pointers to right
	//and left are nullpointers as well
	TreeNode() = default;  //Default constructor 
	TreeNode(Datatype Data, TreeNode* Left = nullptr, TreeNode* Right = nullptr) :
		data(Data), left(Left), right(Right) {} //Explicite  value constructor
	Datatype GetItem()const { return data; } //data accessor 
}; 
#endif