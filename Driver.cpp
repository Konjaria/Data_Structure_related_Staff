#include "Bst.h"
#include <vector>
#include <limits>

void Test1();
void Test2();

std::ostream& operator<<(std::ostream& COUT, BST& tree) {
	tree.Display_Tree(COUT);
	return COUT;
}

std::string yes_or_not(bool statement ) {
	return (statement) ? "Yes" : "No";
}

template <typename Datatype> Datatype validate_(Datatype Data) {
		while (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(1000000000, '\n');
			std::cout << "\n\aError Occured  -  Invalid Input ";
			std::cout << "Provide again : "; std::cin >> Data;
			//validate_(Data);
		}
		return Data;
}
void ShowMenu() {
	std::cout << "\nProvided - Implementations "
		<< "\n************************************"
		<< "\n0 -  Are you tired?You can quit the programme anytime "
		<< "\n1 -  Check whether empty or not"
		<< "\n2 -  Insert an element into a BST"
		<< "\n3 -  Remove an element from a BST"
		<< "\n4 -  Traverse the  Elements from a BST in Pre-order Fashion"
		<< "\n5 -  Traverse the  Elements from a BST in Post-order Fashion"
		<< "\n6 -  Traverse the  Elements from a BST in In-order Fashion"
		<< "\n7 -  Just Check whether the element is in the tree or not"
		<< "\n8 -  Provide the Key and we will  tell you the depth "
		<< "\n9 -  Print the contents of a tree in Pre-order fashion "
		<< "\n************************************" << std::endl;
}

int menu() {
	int your_answer, final_result;  static int temp = 0;
	if (temp == 0)
		ShowMenu();
	++temp;
	std::cout << "\n\t --> Which one you prefer ?  Your answer : ";  std::cin >> your_answer;
	final_result = validate_<int>(your_answer);
	if (final_result != 1 and
		final_result != 2 and 
		final_result != 3 and 
		final_result != 4 and 
		final_result != 5 and 
		final_result != 6 and 
		final_result != 7 and
		final_result != 8 and
		final_result != 9 and
		final_result != 0)
	{
		std::cout << "\a\n\t --> Please provide the namber betweeen 0 to 9  " << std::endl;
		return  -1;
	}

	return final_result;
}

int main()
{
	system("title Binary_Search_Tree_Implementation");
	system("color 3");
	Test2();
}

void Test1() {
	std::cout << "\n\n\t\t\t   Test1" << std::endl;
	std::cout << "\t\t*****************************" << std::endl;
	BST bst;
	int result;
	do {
		result = menu();
		
		if (result == 1) {
			std::cout << "\n\n\t -- > Is Bst Empty or not ?  Answer is " << yes_or_not(bst.IsEmpty()) << std::endl;
			continue;
		}
		else if (result == 2) {
			Datatype item;
			std::cout << "\n\n\t Pass the item to be inserted (it should be integer number) : "; std::cin >> item;
			item = validate_(item);
			bst.Insert_an_item(item);
			continue;
		}
		else if (result == 3) {
			Datatype deleted;
			std::cout << "\n\n\t --> Put the data you want to remove from BST : "; std::cin >> deleted;
			bst.Delete(deleted);
			continue;
		}
		else if (result == 4) {

			bst.Pre_Order_Traversal();
			continue;
		}
		else if (result == 5) {

			bst.Post_Order_Traversal();
			continue;
		}
		else if (result == 6) {
			bst.In_Order_Traversal();
			continue;
		}
		else if (result == 7) {
			Datatype searhing_item;
			std::cout << "\n\n\tWhat are you searching for? Searhing Key  : "; std::cin >> searhing_item;
			searhing_item = validate_(searhing_item);
			std::cout<<"Statement : "<< searhing_item <<" Is in BST is : "<< std::boolalpha << bst.Search(searhing_item);
			continue;
		}
		else if (result == 8) {
			Datatype Key;
			std::cout <<"\n\n\tWhat are you searching for ? Searhing Key : "; std::cin >> Key;
			Key = validate_(Key);
			bst.Search_find_Depth(Key);
			continue;
		}
		else if (result == 9) {
			std::cout << bst;
			continue;
		}
		else if (result == 0) {
			system("cls");
			std::cout << "\n\n\t Okay I hope we will meet each other again :* ( " << std::endl;
			system("pause>0");
			break;
		}
	} while (true);
}

void Test2() {
	system("cls");//clears everything that was before written on cmd
	//system("color 5");// gives a color the text in cmd
	BST binarytree, bst;
	std::cout << "\n\n\t\t\t   Test2" << std::endl;
	std::cout << "\t\t*****************************" << std::endl;
	std::cout << "\n\n\tStatement : Class of BST object called binarytree is Empty - " << std::boolalpha << binarytree.IsEmpty();
	binarytree.Insert_an_item(70);
	binarytree.Insert_an_item(7);
	binarytree.Insert_an_item(28);
	binarytree.Insert_an_item(90);
	binarytree.Insert_an_item(89);
	binarytree.Insert_an_item(50);
	binarytree.Insert_an_item(29);
	binarytree.Insert_an_item(26);
	binarytree.Insert_an_item(15);
	binarytree.Insert_an_item(14);
	//after insertion of some elements let's delete  some of them

	binarytree.Delete(26);
	binarytree.Delete(15);
	binarytree.Delete(14);
	binarytree.Delete(12);


	//then let's Traverse
	std::cout << "\n\tAfter inserting and then removing some data from an object binarytree ... \n\t\tBst Object called  'binarytree'  Looks like this " << std::endl << binarytree;



	//test overloaded assignment operator
	bst = binarytree;
	std::cout << "\n\tWe assign the elements from an object binarytree to a new one \n\n\t\t new Bst object  called  'bst'  looks like this " << std::endl << bst;


	//test copy constr
	BST Test_Copy_Constr_In_BST = binarytree;
	std::cout << "\n\tCopy constructor copies the data from binary tree and passes into a new object \n\n\t\t new Bst object  called  'Test_Copy_Constr_In_BST'  looks like this " << std::endl;
	Test_Copy_Constr_In_BST.Display_Tree(std::cout);




	//check for dynamic memory and then assignment
	BST* Test_For_Dynamic_Memory = new BST;
	std::cout << "\n\tStatement : In the beginning BST object called Test_For_Dynamic_Memory was empty  - " << std::boolalpha << Test_For_Dynamic_Memory->IsEmpty();
	Test_For_Dynamic_Memory = &binarytree;
	try {
		std::cout << "\n\tAfter  assigning to the address of a previous object called 'Test_For_Dynamic_Memory'  it is  still empty - " << std::boolalpha << Test_For_Dynamic_Memory->IsEmpty();
		if (Test_For_Dynamic_Memory->IsEmpty())
			throw std::logic_error("err");
	}
	catch (std::logic_error& err) {
		std::cout << "\n\tOverloaded asssignment operator is not working Properly . . . " << std::endl;
		return;
	}
	Datatype Keyword;
	std::cout << "\n\n\tSearch keyword in BST : "; std::cin >> Keyword; Keyword = validate_<Datatype>(Keyword);
	std::cout << std::endl << "\n\n\tStatement that  "<<Keyword<<" is  in Bst is " <<std::boolalpha<<binarytree.iterative_Search(Keyword) << std::endl;
	Datatype Item = 9;
	BST emptynewObject;
	std::cout << "\n\n\tYou have to Provide  item to insert into an empty new Object  \n Please be informed that you have to Provide the items  till the it  won't be 0  so you can not insert 0 "<<std::endl;

	while (Item != 0) {
		std::cout << "\n\n\tProvide The item : "; std::cin >> Item;
		if (Item == 0) break;
		Keyword = validate_<Datatype>(Item);
		emptynewObject.Insert_an_item_iteratively(Item);
	}
	std::cout << "\n\n\tAfter Insertion  emptynewObject 's data is " << emptynewObject;
	std::cout << "\n\tDelete two elements from an object \n";
	int count = 0;
	for (count; count < 2; count++) {
		Datatype Number;
		std::cout << "\n\n\tPass the number here to delete : "; std::cin >> Number;
		Number = validate_<Datatype>(Number);
		emptynewObject.Delete_an_item_iteratively(Number);
	}
	std::cout << "\n\n\tAfter Deletion : " << emptynewObject;
	std::cout << "\n****************************  End of The  Testing 2  ****************************" << std::endl;
	Test1();
}