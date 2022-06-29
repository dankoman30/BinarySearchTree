#pragma once

class  BST {
private:
	struct node {
		int key;
		node* left;
		node* right;
	};

	node* root;

	void AddLeafPrivate(int key, node*  Ptr);
	void PrintInOrderPrivate(node* Ptr);
	void PrintPreOrderPrivate(node* Ptr);
	void PrintPostOrderPrivate(node* Ptr);
	node* ReturnNodePrivate(int key, node* Ptr);
	int FindSmallestPrivate(node* Ptr);
	int FindLargestPrivate(node* Ptr);
	void RemoveNodePrivate(int key, node* parent);
	void RemoveRootMatch();
	void RemoveMatch(node* parent, node* match, bool left);
	node* CreateLeaf(int key);
	node* ReturnNode(int key);
	void RemoveSubtree(node* Ptr);

public:

	BST();
	~BST(); // deconstructor to avoid memleaks
	void AddLeaf(int key);
	void PrintInOrder();
	void PrintPreOrder();
	void PrintPostOrder();
	int ReturnRootKey();
	void PrintChildren(int key);
	int FindSmallest();
	int FindLargest();
	void RemoveNode(int key);

};