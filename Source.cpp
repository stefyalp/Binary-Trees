/*
Stefania Ascencio
COSC 2436
CHAPTER 19 Binary Trees
trial 3
Write the definition of the function nodeCount that returns the number of
nodes in the binary tree.
Add this function to the class binaryTreeType and create a program to test
this function.
*/
#include <iostream>
#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;
class BinarySearchTree
{
private:
	struct treeNode//struct derived from BinarySearchTree
	{
		treeNode* left;
		treeNode* right;
		int data;
	};
	treeNode* root;
public:
	BinarySearchTree()
	{
		root = NULL;
	}
	bool isEmpty() const { return root == NULL; }
	void printInordered();
	void inorder(treeNode*);
	void insert(int);
	int count(treeNode*);
	int nodeCount();
};
// Smaller elements to the left
// larger ele to the right
void BinarySearchTree::insert(int d)
{
	treeNode* t = new treeNode;
	treeNode* parent;
	t->data = d;
	t->left = NULL;
	t->right = NULL;
	parent = NULL;
	// is this a new tree?
	if (isEmpty()) root = t;
	else
	{
		//ALL insertions are as leaf nodes****
		treeNode* curr;
		curr = root;
		// Find the Node's base or parent
		while (curr)
		{
			parent = curr;
			if (t->data > curr->data) curr = curr->right;
			else curr = curr->left;
		}
		if (t->data < parent->data)
			parent->left = t;
		else
			parent->right = t;
	}
}
void BinarySearchTree::printInordered()
{
	inorder(root);
}
void BinarySearchTree::inorder(treeNode* p)
{
	if (p != NULL)
	{
		if (p->left) inorder(p->left);
		cout << " " << p->data << " ";
		if (p->right) inorder(p->right);
	}
	else return;
}
int BinarySearchTree::nodeCount()
{
	return count(root);
}
int BinarySearchTree::count(treeNode* p)
{
	if (p == NULL)
		return 0;
	return 1 + count(p->left) + count(p->right);
}
int main()
{
	BinarySearchTree b;
	int ch, tmp, tmp1;
	while (1)
	{
		cout << endl << endl;
		cout << " ****Binary Search Menu**** " << endl;
		cout << " ----------------------------- " << endl;
		cout << " 1. Insertion of a number, insert a number: " <<
			endl;
		cout << " 2. To Print In Order Traversal " << endl;
		cout << " 3. Node Count " << endl;
		cout << " 4. QUIT " << endl;
		cout << " Enter your choice : " << endl;
		cout << " ----------------------------- " << endl;
		cin >> ch;
		switch (ch)
		{
		case 1: cout << " Enter Number to be inserted : ";
			cin >> tmp;
			b.insert(tmp);
			break;
		case 2: cout << endl;
			cout << " In Order Traversal: " << endl;
			cout << " ********************" << endl;
			b.printInordered();
			break;
		case 3: cout << endl;
			cout << " Node Count is: ";
			cout << b.nodeCount() << endl;
			break;
		case 9:
			return 0;
		}
	}
}
