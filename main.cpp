#include <iostream>
#include <cstdlib>
#include <time.h>
#include <memory>
#include <chrono>
#include <algorithm>
#include <random>
#include <vector>

#include "BST.h"

using namespace std;
using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::duration;
using std::chrono::milliseconds;

class performanceAnalyzer {
private:
	std::chrono::steady_clock::time_point startTime, endTime; // PERFORMANCE ANALYSIS
	duration<double, std::milli> runtimeMillis;

	auto getTime() {
		return high_resolution_clock::now();
	}
public:
	void start() {
		startTime = getTime();
	}
	void end() {
		endTime = getTime();
		runtimeMillis = endTime - startTime;
		cout << "\n*************************************************************\n";
		cout << "\nPERFORMANCE ANALYSIS: THAT OPERATION TOOK " << runtimeMillis.count() << " ms.\n";
		cout << "\n*************************************************************\n\n";
	}
};

performanceAnalyzer pa; // instantiate performance analyzer

int getNumberFromUser(string message, bool startPerformanceAnalyzer) { // function to get input from user
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
	if(startPerformanceAnalyzer) pa.start(); // PERFORMANCE ANALYSIS (START HERE IMMEDIATELY AFTER TAKING INPUT FROM THE USER)
	return entry;
}

int mainMenu(bool performanceAnalysisMode) {

	BST tree; // instantiate BST object with scope in this function
	vector<int> values;
	int nodes = getNumberFromUser("ENTER DESIRED NUMBER OF NODES TO ADD TO THE TREE, OR ENTER 0 FOR AN EMPTY TREE", false); // false set here because we want more control over when the pa timer will start (after vector creation and shuffling)
	if (nodes < 1) { // check for 0 or negative cases
		cout << endl << "Cannot add " << nodes << " nodes to the tree. Number of nodes must be greater than 0. The tree is empty.\n";
	}
	else {
		// create the vector
		cout << endl << "Creating a vector containing values 1 to " << nodes;
		for (int i = 0; i < nodes; i++) {
			values.push_back(i + 1); // add numbers 1 through nodes to the vector
		}

		// shuffle the vector
		cout << " and shuffling it in random order." << endl;
		auto rng = std::default_random_engine{};
		std::shuffle(std::begin(values), std::end(values), rng);

		// start performance analyzer here because it was not started on user input
		if (performanceAnalysisMode) pa.start();

		// add nodes to tree
		cout << endl << "Adding " << nodes << " nodes from vector to the tree.\n";
		for (int i = 0; i < values.size(); i++) {
			int value = values[i];
//			cout << "\nAdding a node with value " << value << " to the tree.\n";
			tree.AddNode(value); //  on each loop iteration to add to the tree
		}

		if (performanceAnalysisMode) {
			pa.end(); // PERFORMANCE ANALYSIS
		}
	}

	for (;;) { // main loop

		int minimum, maximum; // declare minimum and maximum ints

		cout << endl << "What would you like to do?" << endl <<
			"1.  Create new tree with specified number of nodes with random values" << endl <<
			"2.  Print the two children of node with specified value" << endl <<
			"3.  Insert a node into the tree" << endl << 
			"4.  Delete a node from the tree" << endl << 
			"5.  Find minimum value in the tree" << endl <<
			"6.  Find maximum value in the tree" << endl <<
			"7.  Print tree with Preorder Traversal (root, left, right)" << endl << 
			"8.  Print tree with Inorder Traversal (left, root, right)" << endl <<
			"9.  Print tree with Postorder Traversal (left, right, root)" << endl <<
			"10. Delete all nodes" << endl <<
			"0.  EXIT" << endl << endl;
		int choice = getNumberFromUser("ENTER A CHOICE", performanceAnalysisMode); // start performance analyzer only if performanceAnalysisMode is true (used for cases 7 through 10)
		switch (choice) {
		case 1: // new tree with specified number of nodes from 1 to # of nodes, shuffled in random order
			return 1; // return 1 to run the main menu again, creating a new tree in the process (old tree will be destroyed once out of scope)
		case 2: // print 2 children of specified node
			tree.PrintChildNodes(getNumberFromUser("ENTER THE VALUE OF THE NODE WHOSE CHILDREN YOU'D LIKE TO PRINT", false)); // do not start performance analyzer
			continue;
		case 3: // insert value into tree
			tree.AddNode(getNumberFromUser("ENTER A VALUE TO ADD TO THE TREE", false)); // do not start performance analyzer
			continue;
		case 4: // delete a node
			tree.RemoveNode(getNumberFromUser("ENTER THE VALUE OF THE NODE YOU'D LIKE TO REMOVE FROM THE TREE", false)); // do not start performance analyzer
			continue;
		case 5: // find minimum
			minimum = tree.GetMinimumKey();
			minimum == -666 ? cout << "\nOOPS...\n" : // if function returns -666, tree is empty
				cout << "\nThe minimum value in the tree is " << minimum << endl;
			continue;
		case 6: // find maximum
			maximum = tree.GetMaximumKey();
			maximum == -666 ? cout << "\nOOPS...\n" : // if function returns -666, tree is empty
				cout << "\nThe maximum value in the tree is " << maximum << endl;
			continue;
		case 7: // preorder - root, left, right
			tree.PrintPreorder();
			if (performanceAnalysisMode) {
				pa.end(); // PERFORMANCE ANALYSIS
			}
			continue;
		case 8: // inorder - left, root, right
			tree.PrintInorder();
			if (performanceAnalysisMode) {
				pa.end(); // PERFORMANCE ANALYSIS
			}
			continue;
		case 9: // postorder - left, right, root
			tree.PrintPostorder();
			if (performanceAnalysisMode) {
				pa.end(); // PERFORMANCE ANALYSIS
			}
			continue;
		case 10: // delete all nodes
			while (tree.GetRootKey() != -666) {
				tree.RemoveNode(tree.GetRootKey());
			}
			if (performanceAnalysisMode) {
				pa.end(); // PERFORMANCE ANALYSIS
			}
			cout << endl << "ALL NODES HAVE BEEN DELETED FROM THE TREE AND IT'S NOW EMPTY!" << endl;
			continue;
		default: // exit
			cout << "\n\nBYE!!!\n\n";
			break; // exit loop
		}
		break; // exit program
	}
	return 0;
}

int main() {
	bool performanceAnalysisMode;
	cout << "\nActivate performance analysis mode?\n1. yes\n2. no\n\n";
	performanceAnalysisMode = getNumberFromUser("YOUR CHOICE", false) == 1 ? true : false; // set boolean for performance analysis mode based on user input. get number from user without starting timer


	while(mainMenu(performanceAnalysisMode) != 0); // loop main menu until it returns a 0

	return 0;
}