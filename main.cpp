#include <iostream>
#include <cstdlib>

#include "BST.h"

using namespace std;

int main() {

	int TreeKeys[16] = { 24,86,221,46,856,234,3,53,634,13,255,274,2,434,9,22 };

	BST myTree; // create binary search tree object

	cout << "Printing the tree in order\nBEFORE ADDING NUMBERS\n";
	myTree.PrintInOrder();


	for (int i = 0; i < 16; i++) {
		myTree.AddLeaf(TreeKeys[i]); // add the keys to the search tree
	}

	cout << "Printing the tree in order\nAFTER ADDING NUMBERS\n";
	myTree.PrintInOrder();

	cout << endl;

	return 0;
}