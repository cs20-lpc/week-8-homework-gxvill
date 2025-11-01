/*
TODO List
[x] clear
[x] copy
[x] peek
[x] pop
[x] push 
[x] rotate
*/


template <typename T>
LinkedListStack<T>::LinkedListStack(){ 
	top = nullptr;
	this->length = 0;
}

template <typename T>
LinkedListStack<T>::LinkedListStack(const LinkedListStack<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
LinkedListStack<T>& LinkedListStack<T>::operator=(const LinkedListStack<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
LinkedListStack<T>::~LinkedListStack() {
    clear();
}

template <typename T>
void LinkedListStack<T>::clear() {
    // TO DO: Delete all the elements in the stack
    // delete all nodes and set the top = nullptr (top will be the same as head)

    if(this->length == 0){
		return;
	}
    while(top != nullptr){
        Node<T>* ptr = top->next;
        delete top;
        top = nullptr;
        top = ptr;
    }
    this->length = 0;
    return;
    
}

template <typename T>
void LinkedListStack<T>::copy(const LinkedListStack<T>& copyObj) {
    // TO DO: Implement copy 

    if(copyObj.length == 0){
        top = nullptr;
        this->length = 0;
        return;
    }

	this->length = copyObj.length;

    Node<T>* copyPtr = copyObj.top;
	Node<T>* temp = top;

    while(copyPtr){
		Node<T>* add = new Node<T>(copyPtr->data); //create new node with copied data
		add->next = nullptr;
		if(top == nullptr){
			top = add;
			temp = add;
			copyPtr = copyPtr->next;
			continue;
		}
		temp->next = add;
		temp = add;
		copyPtr = copyPtr->next; // increment the next pointer
		if(copyPtr->next == nullptr){
			add->next = nullptr;
			break;
		}
    }
}

template <typename T>
int LinkedListStack<T>::getLength() const {
    return this->length;
}


template <typename T>
bool LinkedListStack<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
T LinkedListStack<T>::peek() const {
    // TO DO: implement peek
	return top->data;
}

template <typename T>
void LinkedListStack<T>::pop() {
    // TO DO: Implement pop
	if(this->length == 0){
		throw -1;
	}
	Node<T>* temp = top;
	top = top->next;
	delete temp;
	temp = nullptr;
	this->length--;
}

template <typename T>
void LinkedListStack<T>::push(const T& elem) {
    // TO DO: Implement push
	Node<T>* push = new Node<T>(elem);
	push->next = top;
	top = push;
	this->length++;
}

template <typename T>
void LinkedListStack<T>::rotate(typename Stack<T>::Direction dir) {
    // TO DO: Implement rotate
	if(this->length == 1 || this->length == 0){
		return;
	}

	Node<T>* ptr = top;
	if(dir == Stack<T>::RIGHT){ // top goes to bottom
		Node<T>* temp = top;
		while(ptr->next != nullptr){
			ptr = ptr->next;
		}
		top = top->next;
		ptr->next = temp;
		temp->next = nullptr;
	}
	else if(dir == Stack<T>::LEFT){ // bottom goes to top
		while(ptr->next != nullptr){ // bottom is stored in ptr
			ptr = ptr->next;
		}
		Node<T>* bottom = top;
		while(bottom->next != ptr){ // new bottom is stored in bottom
			bottom = bottom->next;
		}

		ptr->next = top;
		top = ptr;
		bottom->next = nullptr;
	}
}

template <typename T>
void LinkedListStack<T>::print() {
    cout << "LinkedListStack contents: ";
    if (isEmpty()) {
        cout << "Stack is empty, no elements to display.\n";
    }
    else {
        Node<T> *curr = top;
        while (curr != nullptr){
            cout <<  curr->data  << "\t";
            curr = curr->next;
        }
    }

    cout << endl;
}
