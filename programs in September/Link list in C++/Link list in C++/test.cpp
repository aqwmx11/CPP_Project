#include <iostream>
#include <cctype> //necessary to use toupper function
using namespace std;

//The declaration of a linked list usually consists of 2 things
struct myNode {
	//The data that a node contains
	char data;
	//The pointer to the next node
	myNode* next;
	myNode(char c, myNode* ptr):data(c),next(ptr){}
};

//First function: initiate a linked list of myNode
//Input: string, output: a pointer to the first node
myNode* makeList(const char* s) {
	myNode* begin(nullptr);
	myNode* end(nullptr);

	//loop through the string
	for (; *s; ++s) {
		myNode* pnew = new myNode(*s, nullptr);
		if (!end) {//which only valid in the very beginning
			end = begin = pnew;
		}
		else {
			//we are doing 2 things here, end->next=pnew ensures the pointer points to the next data
			//end = pnew ensures we are looping through the linked list
			end = end->next = pnew;
		}
	}
	return begin;
}

//Second function, show the size of a linked list
size_t showSize(const myNode* a) {
	size_t size(0);
	for (; a; a = a->next)
		size += 1;
	return size;
}

//Third function, display all the element in a linked list
void display(const myNode* a) {
	for (; a; a = a->next)
		cout << a->data;
	cout << endl;
}

//Fourth function, change all the element to upper case
void toUpper(myNode* a) {
	for (; a; a = a->next)
		a->data = toupper(a->data);
}

//Fifth function, delete the whole linked list
//Pay attention to the type of the input!
void delList(myNode** ptr) {
	while (*ptr) { //the delete process will continue unless it reaches a nullptr, which is the end of the linked list
		myNode* tmp = *ptr;//use this temp variable to store the node pointing at now
		*ptr = (*ptr)->next;//when we have not deleted the data now, move to the next element
		cout << tmp->data << " has been deleted from the list." << endl;
		delete tmp;
	}
}

int main() {
	myNode* myList = makeList("illusion");
	cout << showSize(myList) << endl;
	display(myList);
	cout << "Make the link list to upper case now." << endl;
	toUpper(myList);
	display(myList);
	delList(&myList);
	return 0;
}