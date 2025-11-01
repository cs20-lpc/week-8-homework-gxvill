#include <cstdlib>
#include "ArrayStack.hpp"
#include "LinkedListStack.hpp"
#include "StackFactory.hpp"

using namespace std;
/*
 TODO:
 [-] construct
 [-] copy
 [-] destruct
 [-] clear
 [-] peek
 [-] pop
 [-] push
 [ ] rotate
 [-] isEmpty
 [-] getLength
*/

int main(){

	// linkedlist stack testing
	LinkedListStack<int> ll;


	for(int i = 0; i < 10; i++){
		ll.push(i);
		cout << "top of ll: " << ll.peek() << endl;
	}

	LinkedListStack<int> mm = ll;
	
	cout << "length of ll is: " << ll.getLength() << endl;
	cout << "length of mm is: " << mm.getLength() << endl;

	cout << "top before rotation right: " << ll.peek() << endl;
	ll.rotate(Stack<int>::RIGHT);
	cout << "top after rotation right: " << ll.peek() << endl;

	cout << "top before rotation left: " << ll.peek() << endl;
	ll.rotate(Stack<int>::LEFT);
	cout << "top after rotation left: " << ll.peek() << endl;

	while(!ll.isEmpty()){
		cout << "popping value: " << ll.peek() << " from ll" << endl;
		ll.pop();	
	}

	cout << "length of ll is: " << ll.getLength() << endl;
	cout << "length of mm is: " << mm.getLength() << endl;
	try{
		mm.clear();
	}
	catch(const string& e){
		cout << e << endl;
	}

	try{
		ll.clear();
	}
	catch(const string& e){
		cout << e << endl;
	}

	// array stack testing
	const int SIZE = 10;
	ArrayStack<int> as(SIZE);

	for(int i = 0; i < 10; i++){
		as.push(i);
		cout << "top of as: " << as.peek() << endl;
	}

	try{
		as.push(10);
	}
	catch(const string& e){
		cout << e << endl;
	}

	ArrayStack<int> bs = as; // copy constructor

	while(!as.isEmpty()){
		cout << "popping value: " << as.peek() << " from as" << endl;
		as.pop();	
	}

	while(!bs.isEmpty()){
		cout << "popping value: " << bs.peek() << " from bs" << endl;
		bs.pop();	
	}


	return 0;
}
