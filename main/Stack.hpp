#pragma once
#include <iostream>
#include "DoublyLinkedList.hpp"
#include "Cell.hpp"
#include "StackUnderflowException.hpp"

using namespace std;

template < class T >
class Stack {
public:
	Stack();
	~Stack();

	T pop();
	T top();

	void push(const T& element);

	bool isEmpty();

	int size();

private:
	DoublyLinkedList <T> doublyLinkedList;

	int numElements;
};

template < class T >
Stack<T>::Stack() {
	numElements = 0;
}

template < class T >
Stack<T>::~Stack() {
}

template < class T >
T Stack<T>::pop() {
	T element;

	if (doublyLinkedList.isEmpty() == false) {
		doublyLinkedList.removeFromFront(element);
		numElements--;
	}
	else {
		StackUnderflowException exception;
		throw exception;
	}

	return element;
}

template < class T >
T Stack<T>::top() {
	return doublyLinkedList.at(0);
}

template < class T >
void Stack<T>::push(const T& element) {
	doublyLinkedList.insertAtFront(element);
	numElements++;
}

template < class T >
bool Stack<T>::isEmpty() {
	bool retVal = false;
	if (numElements == 0) {
		retVal = true;
	}
	return retVal;
}

template < class T >
int Stack<T>::size() {
	return numElements;
}