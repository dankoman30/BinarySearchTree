#include <iostream>
#include <cstdlib>

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

void mainMenu() {
	for (;;) { // main loop

		BST tree; // instantiate new BST object

		cout << endl << "What would you like to do?" <<
			"1. Create new tree with specified number of nodes with random values" <<
			"2. " << endl <<
			"3. Print the two children of node with specified value" << endl << 
			"4. Insert a node into the tree" << endl << 
			"5. Delete a node from the tree" << endl <<
			"6. Find minimum value in the tree" << endl <<
			"7. Find maximum value in the tree" << endl << 
			"8. Traverse the tree and return data in order of traversal" << endl << 
			"9. Traverse the tree and return data in sorted order" << endl << 
			"0. EXIT" << endl << endl;
		int choice = getNumberFromUser("ENTER A CHOICE");
		switch (choice) {
		case 1: // new tree with specified number of nodes with random values
			
			continue;
		case 2: // 
			
			continue;
		case 3: // print 2 children of specified node
			
			continue;
		case 4: // insert value into tree
			tree.AddLeaf(getNumberFromUser("ENTER A VALUE TO ADD TO THE TREE"));
			continue;
		case 5: // delete a node
			
			continue;
		case 6: // find minimum
			
			continue;
		case 7: // find maximum
			
			continue;
		case 8: // print in order sorted
			
			continue;
		case 9: // print in order of traversal
			
			continue;
		case 0: // exit
			cout << "\n\nBYE!!!\n\n";
			break; // exit loop
		}
		break; // exit program
	}
}

int main() {

	demo();

	return 0;
}