#include <iostream>
#include <cstdlib>

#include "BST.h"

using namespace std;



BST::BST() {
	root = NULL; // make sure root is pointing to NULL
}


BST::node* BST::CreateLeaf(int key) {
	node* n = new node;
	n->key = key;
	n->left = NULL;
	n->right = NULL;

	return n;
}

void BST::AddLeaf(int key) {
	AddLeafPrivate(key, root);
}


void BST::AddLeafPrivate(int key, node* Ptr) {
	if (root == NULL) {
		root = CreateLeaf(key); // if root is null, this is the first item in the tree (root)
	}
	else if (key < Ptr->key) { // if the new key is LESS than the current key, TRAVERSE LEFT
		if (Ptr->left != NULL) { // if left is not null (already pointing to something),
			AddLeafPrivate(key, Ptr->left); // try again. Recursively call AddLeafPrivate, passing the new key and the current item
		}
		else { // in this case, the left IS null (not pointing to anything), so we can add the new key here
			Ptr->left = CreateLeaf(key);
		}
	}
	else if (key > Ptr->key) { // if the new key is GREATER than the current key, TRAVERSE RIGHT
		if (Ptr->right != NULL) { // if right is not null (already pointing to something),
			AddLeafPrivate(key, Ptr->right); // try again. Recursively call AddLeafPrivate, passing a pointer to the current node's right child
		}
		else { // in this case, the right IS null (not pointing to anything), so we can add the new key here
			Ptr->right = CreateLeaf(key);
		}
	}
	else { // keys are equal
		cout << "The key " << key << " has already been added to the tree\n"; // warn the user
	}
}

void BST::PrintInOrder() {
	PrintInOrderPrivate(root);
}

void BST::PrintInOrderPrivate(node* Ptr) { // recursively traverse the tree from lowest to highest value
	if (root != NULL) { // check to see if there's anything in the tree
		if (Ptr->left != NULL) { // if left is pointing to something, it's possible to traverse left
			PrintInOrderPrivate(Ptr->left); // try again.  Recursively call PrintInOrderPrivate, passing pointer to the current node's left child
		}
		cout << Ptr->key << " "; // print the current key
		if (Ptr->right != NULL) { // if right is pointing to something, it's possible to traverse right
			PrintInOrderPrivate(Ptr->right); // try again.  Recursively call PrintInOrderPrivate, passing pointer to the current node's right child
		}
	}
	else {
		cout << "The tree is empty\n";
	}
}