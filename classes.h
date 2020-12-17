#pragma once
#include <iostream>


class Node {
	friend class Stack;
private:
	int d;
	Node* next;
	int key;

public:
	Node(int d, Node* next) {
		this->next = next;
		this->d = d;
	};

	Node(int d) {
		this->d = d;
	};

	~Node() { 
		delete next;
	}
};

class Stack {
private:
	Node* begin;

public:
	Stack() : begin(NULL) {};

	~Stack() {
		delete begin;
	};

	void append(int d) {
		Node* New = new Node(d);
	
		if (begin) {
			bool flag = true;
			Node* curr = begin;
			while (curr && flag) {
				if (!(curr->next)) {
					curr->next = New;
					flag = false;
				}
				curr = curr->next;
			}
		}
		else {
			begin = New;
		}

		Counter();
	};

	void pop() {
		if (begin) {
			Node* curr = begin;
			
			while (curr) {
				if (!((curr->next)->next)){
					curr->next = NULL;
				}
				curr = curr->next;
			}
		}
		else{
			std::cout << "It is already clear. " << '\n';
		}

		Counter();
	};

	void Print() {	
		if (begin) {
			Node* curr = begin;
			
			while (curr) {
				std::cout << curr->key << " - " << curr->d << '\n';
				curr = curr->next;
			}
		}
		else {
			std::cout << "It is clear. " << '\n';
		}
		std::cout << '\n';
	}

	void Counter() {
		int i = 0;
		Node* curr = begin;
		
		while (curr){
			curr->key = ++i;
			curr = curr->next;
		}
	};
};
