#include <iostream>
#include <cstdlib>
#include<time.h>
#include <memory>

#include "BST.h"

using namespace std;

void demo() {
	int TreeKeys[16] = { 24,86,221,46,856,234,3,53,634,13,255,274,2,434,9,22 };

	BST myTree; // create binary search tree object

	int input = 0;

	cout << "Printing the tree in order\nBEFORE ADDING NUMBERS\n";
	myTree.PrintInOrder();


	for (int i = 0; i < 16; i++) {
		myTree.AddLeaf(TreeKeys[i]); // add the keys to the search tree
	}

	cout << "Printing the tree in order\nAFTER ADDING NUMBERS\n";
	myTree.PrintInOrder();

	cout << endl;

	myTree.PrintChildren(myTree.ReturnRootKey());

	for (int i = 0; i < 16; i++) {
		myTree.PrintChildren(TreeKeys[i]); // print the children for every tree node
		cout << endl;
	}

	cout << "The smallest key in the tree is " << myTree.FindSmallest() << endl;

	cout << "Enter a key value you want to delete. Enter -1 to stop\n";

	while (input != -1) {
		cout << "Delete node: ";
		cin >> input;
		if (input != -1) {
			cout << endl;
			myTree.RemoveNode(input);
			myTree.PrintInOrder();
			cout << endl;
		}
	}
}

int getNumberFromUser(string message) { // function to get input from user
	cout << endl << endl << message + ": ";
	int entry;
	cin >> entry;
	while (!cin) { // keep repeating until we have a valid entry
		cout << endl << "INVALID ENTRY! PLEASE ENTER AN INTEGER!! Try again." << endl;
		cin.clear(); // clear the input stream
		cin.ignore(256, '\n');
		cout << endl << endl << message + ": "; // repeat message
		cin >> entry;
	}
	cout << endl;
	return entry;
}

int mainMenu() {
	BST tree; // instantiate BST object with scope in this function
	int nodes = getNumberFromUser("ENTER DESIRED NUMBER OF NODES TO ADD TO THE TREE, OR ENTER 0 FOR AN EMPTY TREE");
	if (nodes < 1) { // check for 0 or negative cases
		cout << endl << "Cannot add " << nodes << " nodes to the tree. Number of nodes must be greater than 0. The tree is empty.\n";
	}
	else {
		cout << endl << "Adding " << nodes << " nodes with random values between 1 and 1000 to the tree.\n";
		// add nodes to tree
		for (int i = 0; i < nodes; i++) {
			int value = (rand() % 1000) + 1; // generate random number (between 1 and 1000)
			cout << "\nAdding a node with value " << value << " to the tree.\n";
			tree.AddLeaf(value); //  on each loop iteration to add to the tree
		}
	}

	for (;;) { // main loop

		int smallest, largest; // declare smallest and largest ints

		cout << endl << "What would you like to do?" << endl <<
			"1. Create new tree with specified number of nodes with random values" << endl <<
			"2. Print the two children of node with specified value" << endl <<
			"3. Insert a node into the tree" << endl << 
			"4. Delete a node from the tree" << endl << 
			"5. Find minimum value in the tree" << endl <<
			"6. Find maximum value in the tree" << endl <<
			"7. Print tree with Preorder Traversal (root, left, right)" << endl << 
			"8. Print tree with Inorder Traversal (left, root, right)" << endl << 
			"9. Print tree with Postorder Traversal (left, right, root)" << endl << 
			"0. EXIT" << endl << endl;
		int choice = getNumberFromUser("ENTER A CHOICE");
		switch (choice) {
		case 1: // new tree with specified number of nodes with random values
			return 1; // return 1 to run the main menu again, creating a new tree in the process (old tree will be destroyed once out of scope)
		case 2: // print 2 children of specified node
			tree.PrintChildren(getNumberFromUser("ENTER THE VALUE OF THE NODE WHOSE CHILDREN YOU'D LIKE TO PRINT"));
			continue;
		case 3: // insert value into tree
			tree.AddLeaf(getNumberFromUser("ENTER A VALUE TO ADD TO THE TREE"));
			continue;
		case 4: // delete a node
			tree.RemoveNode(getNumberFromUser("ENTER THE VALUE OF THE NODE YOU'D LIKE TO REMOVE FROM THE TREE"));
			continue;
		case 5: // find minimum
			smallest = tree.FindSmallest();
			smallest == -666 ? cout << "\nOOPS...\n" : // if function returns -666, tree is empty
				cout << "\nThe minimum value in the tree is " << smallest << endl;
			continue;
		case 6: // find maximum
			largest = tree.FindLargest();
			largest == -666 ? cout << "\nOOPS...\n" : // if function returns -666, tree is empty
				cout << "\nThe maximum value in the tree is " << largest << endl;
			continue;
		case 7: // preorder - root, left, right
			tree.PrintPreOrder();
			continue;
		case 8: // inorder - left, root, right
			tree.PrintInOrder();
			continue;
		case 9: // 
			tree.PrintPostOrder();
			continue;
		case 0: // exit
			cout << "\n\nBYE!!!\n\n";
			break; // exit loop
		}
		break; // exit program
	}
	return 0;
}

int main() {
	srand(time(0)); // at program start, use time as a seed for random number generator

	while(mainMenu() != 0); // loop main menu until it returns a 0

	return 0;
}