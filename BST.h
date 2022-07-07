#pragma once

#include <iostream>
#include <cstdlib>

using namespace std;

template<typename type>
class  BST {
private:
	struct node {
		type key;
		node* left;
		node* right;
	};

	bool performanceAnalysisMode;

	node* root;

	void PrivateAddNode(type key, node* pointer) {
		if (root == NULL) {
			root = CreateNode(key); // if root is null, this is the first item in the tree (root)
		}
		else if (key < pointer->key) { // if the new key is LESS than the current key, TRAVERSE LEFT
			if (pointer->left != NULL) { // if left is not null (already pointing to something),
				PrivateAddNode(key, pointer->left); // try again. Recursively call PrivateAddNode, passing the new key and the current item
			}
			else { // in this case, the left IS null (not pointing to anything), so we can add the new key here
				pointer->left = CreateNode(key);
			}
		}
		else if (key > pointer->key) { // if the new key is GREATER than the current key, TRAVERSE RIGHT
			if (pointer->right != NULL) { // if right is not null (already pointing to something),
				PrivateAddNode(key, pointer->right); // try again. Recursively call PrivateAddNode, passing a pointer to the current node's right child
			}
			else { // in this case, the right IS null (not pointing to anything), so we can add the new key here
				pointer->right = CreateNode(key);
			}
		}
		else { // keys are equal
			cout << "The key " << key << " has already been added to the tree\n"; // warn the user
		}
	}

	void PrivatePrintInorder(node* pointer) { // inorder traversal (left, root, right)
		if (root != NULL) { // check to see if there's anything in the tree
			// left
			if (pointer->left != NULL) { // if left is pointing to something, it's possible to traverse left
				PrivatePrintInorder(pointer->left); // try again.  Recursively call PrivatePrintInorder, passing pointer to the current node's left child
			}

			// root
			cout << pointer->key << " "; // print the current key

			// right
			if (pointer->right != NULL) { // if right is pointing to something, it's possible to traverse right
				PrivatePrintInorder(pointer->right); // try again.  Recursively call PrivatePrintInorder, passing pointer to the current node's right child
			}
		}
		else {
			cout << "EMPTY TREE!\n";
		}
	}

	void PrivatePrintPreorder(node* pointer) { // preorder traversal (root, left, right)
		if (root != NULL) { // check to see if there's anything in the tree
			// root
			cout << pointer->key << " "; // print the current key

			// left
			if (pointer->left != NULL) { // if left is pointing to something, it's possible to traverse left
				PrivatePrintPreorder(pointer->left); // try again.  Recursively call PrivatePrintPreorder, passing pointer to the current node's left child
			}

			// right
			if (pointer->right != NULL) { // if right is pointing to something, it's possible to traverse right
				PrivatePrintPreorder(pointer->right); // try again.  Recursively call PrivatePrintPreorder, passing pointer to the current node's right child
			}
		}
		else {
			cout << "EMPTY TREE!\n";
		}
	}

	void PrivatePrintPostorder(node* pointer) { // postorder traversal (left, right, root)
		if (root != NULL) { // check to see if there's anything in the tree
			// left
			if (pointer->left != NULL) { // if left is pointing to something, it's possible to traverse left
				PrivatePrintPostorder(pointer->left); // try again.  Recursively call PrivatePrintPostorder, passing pointer to the current node's left child
			}

			// right
			if (pointer->right != NULL) { // if right is pointing to something, it's possible to traverse right
				PrivatePrintPostorder(pointer->right); // try again.  Recursively call PrivatePrintPostorder, passing pointer to the current node's right child
			}

			// root
			cout << pointer->key << " "; // print the current key
		}
		else {
			cout << "EMPTY TREE!\n";
		}
	}

	node* PrivateReturnNode(type key, node* pointer) {
		if (pointer != NULL) { // if the pointer is pointing to something
			if (pointer->key == key) { // compare to the key we're passing in. if it's identical, we've found the node that we want
				return pointer; // so, return the pointer that's pointing to the current node
			}
			else { // do some recursion 
				if (key < pointer->key) { // check if it's LESS than the current pointer's key.  if so, TRAVERSE LEFT.
					return PrivateReturnNode(key, pointer->left); // Try again.  Recursively call PrivateReturnNode with current node's LEFT child.
				}
				else { // since we already checked for equality, the only possibility remaining is GREATER than the current key. So,
					return PrivateReturnNode(key, pointer->right); // Try again. Recursively call PrivateReturnNode with current node's RIGHT child.
				}
			}
		}
		else { // null pointer.  return it.
			return NULL;
		}
	}

	type PrivateFindMinimum(node* pointer) { // here, we are finding the smallest node in specified node's right subtree
		if (root == NULL) { // if tree is empty
			cout << "EMPTY TREE!\n";
			return -666;
		}
		else {
			if (pointer->left != NULL) { // if it's possible to traverse LEFT, do it.
				return PrivateFindMinimum(pointer->left); // only go left.  it's gotta be smaller.
			}
			else { // else, only larger keys exist, so we are currently on the smallest key.  Return it.
				return pointer->key;
			}
		}
	}

	type PrivateFindMaximum(node* Ptr) { // here, we are finding the smallest node in specified node's right subtree
		if (root == NULL) { // if tree is empty
			cout << "EMPTY TREE!\n";
			return -666;
		}
		else {
			if (Ptr->right != NULL) { // if it's possible to traverse RIGHT, do it.
				return PrivateFindMaximum(Ptr->right); // only go right.  it's gotta be larger.
			}
			else { // else, only smaller keys exist, so we are currently on the largest key.  Return it.
				return Ptr->key;
			}
		}
	}

	void PrivateRemoveNode(type key, node* parent) {
		if (root != NULL) { // check if tree is empty
			if (root->key == key) { // is there a matchingNode at root? if so, we need to reconstruct the tree...
				RemoveKeyAtRoot();
			}
			else { // look at left child
				if (key < parent->key && parent->left != NULL) { // if the key that we want to remove has a value less than the current node's key, we want to look down the left pointer, as long as it's not null
					parent->left->key == key ? // if parent's left key is equal to the key we want to delete,
						RemoveKey(parent, parent->left, true) : // remove it from the tree, passing true as it IS a LEFT
						PrivateRemoveNode(key, parent->left); // otherwise, left node becomes parent node in next recursive iteration.
				}
				else if (key > parent->key && parent->right != NULL) { // if the key that we want to remove has a value greater than the current node's key, we want to look down the right pointer, as long as it's not null
					parent->right->key == key ? // if parent's right key is equal to the key we want to delete,
						RemoveKey(parent, parent->right, false) : // remove it from the tree, passing false as it's not a LEFT
						PrivateRemoveNode(key, parent->right); // otherwise, right node becomes parent node in next recursive iteration.
				}
				else { // the key that we're looking for is not in the tree
					cout << "The key " << key << " was not found in the tree\n";
				}
			}
		}
		else { // tree is empty
			cout << "EMPTY TREE!\n";
		}
	}

	void RemoveKeyAtRoot() { // only used for removing the root node and reconstructing the tree
		if (root != NULL) { // check for empty tree
			node* pointerToDelete = root; // define pointer to delete as root
			type rootKey = root->key; // get root key
			type minimumInRightSubtree; // declare int for smallest key in right subtree (to be new root later)

			// root node has 0 children
			if (root->left == NULL && root->right == NULL) {
				root = NULL;
				delete pointerToDelete;
			}

			// root node has 1 child
			else if (root->left == NULL && root->right != NULL) { // root has right child but no left child
				root = root->right; // root's right is the new root
				pointerToDelete->right = NULL; // disconnect old root from tree
				delete pointerToDelete;
				if (!performanceAnalysisMode) { // only print if performance analysis mode is off
					cout << "The root node with key " << rootKey << " was deleted. " <<
						"The new root contains key " << root->key << endl; // inform user
				}
			}

			// root node has 1 child
			else if (root->left != NULL && root->right == NULL) { // root has left child but no right child
				root = root->left; // root's left is the new root
				pointerToDelete->left = NULL; // disconnect old root from tree
				delete pointerToDelete;
				if (!performanceAnalysisMode) { // only print if performance analysis mode is off
					cout << "The root node with key " << rootKey << " was deleted. " <<
						"The new root contains key " << root->key << endl; // inform user
				}
			}

			// root node has 2 children
			else {
				minimumInRightSubtree = PrivateFindMinimum(root->right); // find the smallest in right subtree
				PrivateRemoveNode(minimumInRightSubtree, root); // delete smallest in root's right subtree
				root->key = minimumInRightSubtree; // overwrite root key with smallest key in its right subtree
				if (!performanceAnalysisMode) { // only print if performance analysis mode is off
					cout << "The root key containing key " << rootKey <<
						" was overwritten with key " << root->key << endl; // inform user
				}
			}
		}
		else { // tree is empty
			cout << "Cannot remove root on an empty tree!\n";
		}
	}

	void RemoveKey(node* parent, node* matchingNode, bool left) {
		if (root != NULL) { // verify tree isn't empty
			node* pointerToDelete;
			type matchingNodeKey = matchingNode->key;
			type minimumInRightSubtree; // used if node we're deleting has 2 children

			// no children
			if (matchingNode->left == NULL && matchingNode->right == NULL) { // no children
				pointerToDelete = matchingNode;
				left == true ? // if it's the left
					parent->left = NULL : // if it's
					parent->right = NULL;
				delete pointerToDelete;
				if (!performanceAnalysisMode) { // only print if performance analysis mode is off
					cout << "The node containing key " << matchingNodeKey << " was removed.\n";
				}
			}

			// matching node has only 1 child
			else if (matchingNode->left == NULL && matchingNode->right != NULL) { // right child only
				left == true ? parent->left = matchingNode->right : parent->right = matchingNode->right; // 
				matchingNode->right = NULL; // disconnect from tree
				pointerToDelete = matchingNode; // set pointer to delete to the matchingNode
				delete pointerToDelete; // delete it
				if (!performanceAnalysisMode) { // only print if performance analysis mode is off
					cout << "The node containing key " << matchingNodeKey << " was removed.\n";
				}
			}
			// matching node has only 1 child
			else if (matchingNode->left != NULL && matchingNode->right == NULL) { // left child only
				left == true ? parent->left = matchingNode->left : parent->right = matchingNode->left; // 
				matchingNode->left = NULL; // disconnect from tree
				pointerToDelete = matchingNode; // set pointer to delete to the matchingNode
				delete pointerToDelete; // delete it
				if (!performanceAnalysisMode) { // only print if performance analysis mode is off
					cout << "The node containing key " << matchingNodeKey << " was removed.\n";
				}
			}

			// matching node has 2 children
			else {
				minimumInRightSubtree = PrivateFindMinimum(matchingNode->right);
				PrivateRemoveNode(minimumInRightSubtree, matchingNode); // start searching for key at matchingNode (the matching node)
				matchingNode->key = minimumInRightSubtree; // overwrite value with smallest value in right subtree
			}
		}
		else {
			cout << "Can't remove match from empty tree!!\n";
		}

	}

	node* CreateNode(type key) {
		node* newNode = new node;
		newNode->key = key;
		newNode->left = NULL;
		newNode->right = NULL;

		return newNode;
	}

	node* ReturnNode(type key) {
		return PrivateReturnNode(key, root);
	}

	void RemoveSubtree(node* pointer) { // post-order traversal to remove all the nodes
		if (pointer != NULL) { // check for null
			if (pointer->left != NULL) {
				RemoveSubtree(pointer->left); // recursively move down left subtree
			}
			if (pointer->right != NULL) {
				RemoveSubtree(pointer->right); // recursively move down right subtree
			}
			// at this point, we've gone as far left and as far right as we possibly can
			cout << "Deleting the node containing key " << pointer->key << endl;
			delete pointer;
		}
	}

public:

	BST() {
		BST(false); // if object is instantiated without a bool flag for PA mode, let's default to false
	}

	BST(bool paOn) {
		root = NULL; // make sure root is pointing to NULL
		performanceAnalysisMode = paOn;
	}

	~BST() { // using tilde operator (~), this function is called whenever our BST object goes out of scope. This is a deconstructor / destructor
		RemoveSubtree(root); // call remove subtree on root node
	}

	void AddNode(type key) {
		PrivateAddNode(key, root);
	}

	void PrintInorder() {
		PrivatePrintInorder(root);
	}

	void PrintPreorder() {
		PrivatePrintPreorder(root);
	}

	void PrintPostorder() {
		PrivatePrintPostorder(root);
	}

	type GetRootKey() {
		if (root != NULL) {
			return root->key;
		}
		else {
			return -666;
		}
	}

	void PrintChildNodes(type key) { // print the two children of the specified key
		node* pointer = ReturnNode(key); // create pointer that points to the node containing the key, if it exists

		if (pointer != NULL) { // only if the key was found in the tree will pointer not be NULL
			cout << "Parent Node = " << pointer->key << endl;

			pointer->left == NULL ? // check left child for null
				cout << "Left Child = NULL\n" :
				cout << "Left Child = " << pointer->left->key << endl; // print the left child's key
			pointer->right == NULL ? // check right child for null
				cout << "Right Child = NULL\n" :
				cout << "Right Child = " << pointer->right->key << endl; // print the right child's key
		}
		else { // if it's NULL, it does not exist in the tree
			cout << "Key " << key << " not found in the tree\n";
		}
	}

	type GetMinimumKey() {
		return PrivateFindMinimum(root); // call find smallest with the root node
	}

	type GetMaximumKey() {
		return PrivateFindMaximum(root); // call find smallest with the root node
	}

	void RemoveNode(type key) {
		PrivateRemoveNode(key, root); // start recursion at root
	}

};