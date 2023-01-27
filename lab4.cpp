#include <iostream>
#include "ItemType.h"
#include "TreeType.h"

using namespace std;
void printingOrders(TreeType& Tree,OrderType order) //function that prints the tree in given order.
{
	ItemType item;
	bool finished = false;
	for (int i = 0; i < Tree.GetLength(); i++)//loops through entire tree, getting next item.
	{
		Tree.GetNextItem(item, order, finished);
		item.Print();
	}
}

int main()
{
	//test cases from TestCase example:
	ItemType First;
	First.Initialize('F');
	ItemType Second;
	Second.Initialize('N');
	ItemType Third;
	Third.Initialize('R');
	ItemType Fourth;
	Fourth.Initialize('D');
	ItemType Fifth;
	Fifth.Initialize('G');
	ItemType Sixth;
	Sixth.Initialize('C');

	TreeType Tree;
	TreeType swapTree;

	Tree.InsertItem(First);
	cout << "After inserting the first item in the tree, the tree looks like: " << endl;
	Tree.Print();
	cout << "Inserting Node: " << Second.getItem() << endl;
	Tree.InsertItem(Second);
	cout << "Inserting Node: " << Third.getItem() << endl;
	Tree.InsertItem(Third);
	cout << "Inserting Node: " << Fourth.getItem() << endl;
	Tree.InsertItem(Fourth);
	cout << "Inserting Node: " << Fifth.getItem() << endl;
	Tree.InsertItem(Fifth);
	cout << "Inserting Node: " << Sixth.getItem() << endl;
	Tree.InsertItem(Sixth);
	cout << "After inserting " << Tree.GetLength() << "items into the tree, the tree looks like :" << endl;
	Tree.Print();
	cout << "The tree has " << Tree.GetLength() << " elements." << endl;
	
	cout << "The tree in post-order: "<<endl;
	Tree.ResetTree(POST_ORDER);
	printingOrders(Tree, POST_ORDER);

	cout << endl << "The tree in pre-order: " << endl;
	Tree.ResetTree(PRE_ORDER);
	printingOrders(Tree, PRE_ORDER);
	Tree.ResetTree(IN_ORDER);
	
	cout << endl << "Testing for ancestors for item C" << endl;
	Tree.Ancestors(Sixth);

	cout << endl<<"Testing Swap: " << endl;
	Tree.Swap(swapTree);
	cout << "The swapped tree in-order:" << endl;
	swapTree.Print();

	cout << "Test leaf count: " << endl;
	cout << "There are " << Tree.LeafCount() << " leaf nodes." << endl;

	cout << "Testing delete, we want to delete item '" << First.getItem() << "'" << endl;
	Tree.DeleteItem(First);
	cout << "After deleting '" << First.getItem() << "' from the tree, the tree has " << Tree.GetLength() << " elements." << endl;
	Tree.Print();

	cout << "The tree in pre-order:" << endl;
	Tree.ResetTree(PRE_ORDER);
	printingOrders(Tree, PRE_ORDER);
	Tree.ResetTree(IN_ORDER);

	cout << endl << "After emptying the tree: " << endl;
	Tree.MakeEmpty();
	Tree.Print();

	return 0;
}

