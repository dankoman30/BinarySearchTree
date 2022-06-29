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

void BST::PrintInOrderPrivate(node* Ptr) { // inorder traversal (left, root, right)
	if (root != NULL) { // check to see if there's anything in the tree
		// left
		if (Ptr->left != NULL) { // if left is pointing to something, it's possible to traverse left
			PrintInOrderPrivate(Ptr->left); // try again.  Recursively call PrintInOrderPrivate, passing pointer to the current node's left child
		}

		// root
		cout << Ptr->key << " "; // print the current key

		// right
		if (Ptr->right != NULL) { // if right is pointing to something, it's possible to traverse right
			PrintInOrderPrivate(Ptr->right); // try again.  Recursively call PrintInOrderPrivate, passing pointer to the current node's right child
		}
	}
	else {
		cout << "The tree is empty\n";
	}
}

void BST::PrintPreOrder() {
	PrintPreOrderPrivate(root);
}

void BST::PrintPreOrderPrivate(node* Ptr) { // preorder traversal (root, left, right)
	if (root != NULL) { // check to see if there's anything in the tree
		// root
		cout << Ptr->key << " "; // print the current key

		// left
		if (Ptr->left != NULL) { // if left is pointing to something, it's possible to traverse left
			PrintPreOrderPrivate(Ptr->left); // try again.  Recursively call PrintPreOrderPrivate, passing pointer to the current node's left child
		}
		
		// right
		if (Ptr->right != NULL) { // if right is pointing to something, it's possible to traverse right
			PrintPreOrderPrivate(Ptr->right); // try again.  Recursively call PrintPreOrderPrivate, passing pointer to the current node's right child
		}
	}
	else {
		cout << "The tree is empty\n";
	}
}

void BST::PrintPostOrder() {
	PrintPostOrderPrivate(root);
}

void BST::PrintPostOrderPrivate(node* Ptr) { // postorder traversal (left, right, root)
	if (root != NULL) { // check to see if there's anything in the tree
		// left
		if (Ptr->left != NULL) { // if left is pointing to something, it's possible to traverse left
			PrintPostOrderPrivate(Ptr->left); // try again.  Recursively call PrintPostOrderPrivate, passing pointer to the current node's left child
		}

		// right
		if (Ptr->right != NULL) { // if right is pointing to something, it's possible to traverse right
			PrintPostOrderPrivate(Ptr->right); // try again.  Recursively call PrintPostOrderPrivate, passing pointer to the current node's right child
		}

		// root
		cout << Ptr->key << " "; // print the current key
	}
	else {
		cout << "The tree is empty\n";
	}
}

BST::node* BST::ReturnNode(int key) {
	return ReturnNodePrivate(key, root);
}

BST::node* BST::ReturnNodePrivate(int key, node* Ptr) {
	if (Ptr != NULL) { // if the pointer is pointing to something
		if (Ptr->key == key) { // compare to the key we're passing in. if it's identical, we've found the node that we want
			return Ptr; // so, return the pointer that's pointing to the current node
		}
		else { // do some recursion 
			if (key < Ptr->key) { // check if it's LESS than the current pointer's key.  if so, TRAVERSE LEFT.
				return ReturnNodePrivate(key, Ptr->left); // Try again.  Recursively call ReturnNodePrivate with current node's LEFT child.
			}
			else { // since we already checked for equality, the only possibility remaining is GREATER than the current key. So,
				return ReturnNodePrivate(key, Ptr->right); // Try again. Recursively call ReturnNodePrivate with current node's RIGHT child.
			}
		}
	}
	else { // null pointer.  return it.
		return NULL;
	}
}

int BST::ReturnRootKey() {
	if (root != NULL) {
		return root->key;
	}
	else {
		return -666;
	}
}

void BST::PrintChildren(int key) { // print the two children of the specified key
	node* Ptr = ReturnNode(key); // create pointer that points to the node containing the key, if it exists

	if (Ptr != NULL) { // only if the key was found in the tree will Ptr not be NULL
		cout << "Parent Node = " << Ptr->key << endl;

		Ptr->left == NULL ? // check left child for null
			cout << "Left Child = NULL\n" :
			cout << "Left Child = " << Ptr->left->key << endl; // print the left child's key
		Ptr->right == NULL ? // check right child for null
			cout << "Right Child = NULL\n" :
			cout << "Right Child = " << Ptr->right->key << endl; // print the right child's key
	}
	else { // if it's NULL, it does not exist in the tree
		cout << "Key " << key << " not found in the tree\n";
	}
}

int BST::FindSmallest() {
	return FindSmallestPrivate(root); // call find smallest with the root node
}

int BST::FindSmallestPrivate(node* Ptr) { // here, we are finding the smallest node in specified node's right subtree
	if (root == NULL) { // if tree is empty
		cout << "The tree is empty\n";
		return -666;
	}
	else {
		if (Ptr->left != NULL) { // if it's possible to traverse LEFT, do it.
			return FindSmallestPrivate(Ptr->left); // only go left.  it's gotta be smaller.
		}
		else { // else, only larger keys exist, so we are currently on the smallest key.  Return it.
			return Ptr->key;
		}
	}
}

int BST::FindLargest() {
	return FindLargestPrivate(root); // call find smallest with the root node
}

int BST::FindLargestPrivate(node* Ptr) { // here, we are finding the smallest node in specified node's right subtree
	if (root == NULL) { // if tree is empty
		cout << "The tree is empty\n";
		return -666;
	}
	else {
		if (Ptr->right != NULL) { // if it's possible to traverse RIGHT, do it.
			return FindLargestPrivate(Ptr->right); // only go right.  it's gotta be larger.
		}
		else { // else, only smaller keys exist, so we are currently on the largest key.  Return it.
			return Ptr->key;
		}
	}
}

void BST::RemoveNode(int key) {
	RemoveNodePrivate(key, root); // start recursion at root
}

void BST::RemoveNodePrivate(int key, node* parent) {
	if (root != NULL) { // check if tree is empty
		if (root->key == key) { // is there a match at root? if so, we need to reconstruct the tree...
			RemoveRootMatch();
		}
		else { // look at left child
			if (key < parent->key && parent->left != NULL) { // if the key that we want to remove has a value less than the current node's key, we want to look down the left pointer, as long as it's not null
				parent->left->key == key ? // if parent's left key is equal to the key we want to delete,
					RemoveMatch(parent, parent->left, true) : // remove it from the tree, passing true as it IS a LEFT
					RemoveNodePrivate(key, parent->left); // otherwise, left node becomes parent node in next recursive iteration.
			}
			else if (key > parent->key && parent->right != NULL) { // if the key that we want to remove has a value greater than the current node's key, we want to look down the right pointer, as long as it's not null
				parent->right->key == key ? // if parent's right key is equal to the key we want to delete,
					RemoveMatch(parent, parent->right, false) : // remove it from the tree, passing false as it's not a LEFT
					RemoveNodePrivate(key, parent->right); // otherwise, right node becomes parent node in next recursive iteration.
			}
			else { // the key that we're looking for is not in the tree
				cout << "The key " << key << " was not found in the tree\n";
			}
		}
	}
	else { // tree is empty
		cout << "The tree is empty\n";
	}
}

void BST::RemoveRootMatch() { // only used for removing the root node and reconstructing the tree
	if (root != NULL) { // check for empty tree
		node* delPtr = root; // define pointer to delete as root
		int rootKey = root->key; // get root key
		int smallestInRightSubtree; // declare int for smallest key in right subtree (to be new root later)

		// case 0 - root node has 0 children
		if (root->left == NULL && root->right == NULL) {
			root = NULL;
			delete delPtr;
		}

		// case 1a - root node has 1 child
		else if (root->left == NULL && root->right != NULL) { // root has right child but no left child
			root = root->right; // root's right is the new root
			delPtr->right = NULL; // disconnect old root from tree
			delete delPtr;
			cout << "The root node with key " << rootKey << " was deleted. " <<
				"The new root contains key " << root->key << endl; // inform user
		}

		// case 1b - root node has 1 child
		else if (root->left != NULL && root->right == NULL) { // root has left child but no right child
			root = root->left; // root's left is the new root
			delPtr->left = NULL; // disconnect old root from tree
			delete delPtr;
			cout << "The root node with key " << rootKey << " was deleted. " <<
				"The new root contains key " << root->key << endl; // inform user
		}

		// case 2 - root node has 2 children
		else {
			smallestInRightSubtree = FindSmallestPrivate(root->right); // find the smallest in right subtree
			RemoveNodePrivate(smallestInRightSubtree, root); // delete smallest in root's right subtree
			root->key = smallestInRightSubtree; // overwrite root key with smallest key in its right subtree
			cout << "The root key containing key " << rootKey <<
				" was overwritten with key " << root->key << endl; // inform user
		}
	}
	else { // tree is empty
		cout << "Cannot remove root on an empty tree!\n";
	}
}

void BST::RemoveMatch(node* parent, node* match, bool left) {
	if (root != NULL) { // verify tree isn't empty
		node* delPtr;
		int matchKey = match->key;
		int smallestInRightSubtree; // used if node we're deleting has 2 children

		// case 0 - no children
		if (match->left == NULL && match->right == NULL) { // no children
			delPtr = match;
			left == true ? // if it's the lef t
				parent->left = NULL : // if it's
				parent->right = NULL;
			delete delPtr;
			cout << "The node containing key " << matchKey << " was removed.\n";
		}

		// case 1a - matching node has only 1 child
		else if (match->left == NULL && match->right != NULL) { // right child only
			left == true ? parent->left = match->right : parent->right = match->right; // 
			match->right = NULL; // disconnect from tree
			delPtr = match; // set pointer to delete to the match
			delete delPtr; // delete it
			cout << "The node containing key " << matchKey << " was removed.\n";
		}
		// case 1b - matching node has only 1 child
		else if (match->left != NULL && match->right == NULL) { // left child only
			left == true ? parent->left = match->left : parent->right = match->left; // 
			match->left = NULL; // disconnect from tree
			delPtr = match; // set pointer to delete to the match
			delete delPtr; // delete it
			cout << "The node containing key " << matchKey << " was removed.\n";
		}

		// case 2 - matching node has 2 children
		else {
			smallestInRightSubtree = FindSmallestPrivate(match->right);
			RemoveNodePrivate(smallestInRightSubtree, match); // start searching for key at match (the matching node)
			match->key = smallestInRightSubtree; // overwrite value with smallest value in right subtree
		}
	}
	else {
		cout << "Can't remove match from empty tree!!\n";
	}

}

BST::~BST() { // using tilde operator (~), this function is called whenever our BST object goes out of scope. This is a deconstructor / destructor
	RemoveSubtree(root); // call remove subtree on root node
}

void BST::RemoveSubtree(node* Ptr) { // post-order traversal to remove all the nodes
	if (Ptr != NULL) { // check for null
		if (Ptr->left != NULL) {
			RemoveSubtree(Ptr->left); // recursively move down left subtree
		}
		if (Ptr->right != NULL) {
			RemoveSubtree(Ptr->right); // recursively move down right subtree
		}
		// at this point, we've gone as far left and as far right as we possibly can
		cout << "Deleting the node containing key " << Ptr->key << endl;
		delete Ptr;
	}
}