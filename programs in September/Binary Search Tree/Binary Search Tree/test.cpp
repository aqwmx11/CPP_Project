#include <iostream>
using namespace std;

struct myNode {
	int val;
	myNode* left;
	myNode* right;
	myNode(int a = 0, myNode* b = nullptr, myNode* c = nullptr) :val(a), left(b), right(c) {}
};

//First function, display all the value in the tree
//We are doing it in a recursive way
void display(myNode* top) {
	if (top) {
		display(top->left);
		cout << top->val << " ";
		display(top->right);
	}
}

//Second function, insert a node into the tree
void insert(myNode** ptop, int val) {
	if (*ptop) {
		if (val < (*ptop)->val)
			insert(&(*ptop)->left, val);
		else
			insert(&(*ptop)->right, val);
	}
	else {
		*ptop = new myNode(val, 0, 0);
	}
}

//Third function, delete a BST
void myDelete(myNode** ptop) {
	if (*ptop) {
		if ((*ptop)->left)
			myDelete(&(*ptop)->left);
		if ((*ptop)->right)
			myDelete(&(*ptop)->right);
		delete *ptop;
		*ptop = 0;
	}
}

//4th function, find the minimum int in a BST
int findMin(const myNode* top) {
	if (top == nullptr)
		return 0;
	else {
		for (; top->left; top = top->left);
		return top->val;
	}
}

//5th function, find the sum of left leaves
//leetCode 404
//Note that the left leaves means the leaves which have no "lefter" leaves
int sumOfLeftLeaves(myNode* top) {
	if (!top)
		return 0;
	if (top->left && !top->left->left && !top->left->right)
		return top->left->val + sumOfLeftLeaves(top->right);
	return sumOfLeftLeaves(top->left) + sumOfLeftLeaves(top->right);
}

int findSum(myNode* root) {
	if (!root)
		return 0;
	return findSum(root->left) + findSum(root->right) + root->val;
}

int main() {
	myNode* top = 0;
	insert(&top, 5);
	insert(&top, 12);
	insert(&top, 10);
	insert(&top, 9);
	display(top);
	cout << endl;
	cout << findMin(top) << endl;
	cout << findSum(top) << endl;
	myDelete(&top);
	return 0;
}