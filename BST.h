#pragma once

class  BST {
private:
	struct node {
		int key;
		node* left;
		node* right;
	};

	node* root;

	void PrivateAddNode(int key, node*  Ptr);
	void PrivatePrintInorder(node* Ptr);
	void PrivatePrintPreorder(node* Ptr);
	void PrivatePrintPostorder(node* Ptr);
	node* PrivateReturnNode(int key, node* Ptr);
	int PrivateFindMinimum(node* Ptr);
	int PrivateFindMaximum(node* Ptr);
	void PrivateRemoveNode(int key, node* parent);
	void RemoveKeyAtRoot();
	void RemoveKey(node* parent, node* match, bool left);
	node* CreateNode(int key);
	node* ReturnNode(int key);
	void RemoveSubtree(node* Ptr);

public:

	BST();
	~BST(); // deconstructor to avoid memleaks
	void AddNode(int key);
	void PrintInorder();
	void PrintPreorder();
	void PrintPostorder();
	int GetRootKey();
	void PrintChildNodes(int key);
	int GetMinimumKey();
	int GetMaximumKey();
	void RemoveNode(int key);

};