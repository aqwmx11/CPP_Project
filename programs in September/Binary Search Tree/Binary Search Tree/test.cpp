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

int main() {
	myNode a(2);
	myNode b(1);
	myNode c(8);
	myNode d(5, &b, &c);
	myNode e(3, &a, &d);
	display(&e);
	return 0;
}