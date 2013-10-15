/*
FILNAMN			List.cc
LABORANTION		1
PROGRAMMERARE	emmva911 johbi142
DATUM			2013-09-18
BESKRIVNING		Innehåller klassen List:s alla funktioner
 */

#include "List.h"


List::List(){
	root = nullptr;
}

List::List(const List& orig){
	if(orig.root == nullptr){
		root = nullptr;
	}
	else{
		List_Node* ptr = orig.root;
		root = copy(ptr);
	}
}

List::~List(){
	clear();
}

List& List::operator=(const List& orig){
	List temp(orig);
	this->swap(temp);
	return *this;
}

List::List_Node* List::copy(List_Node* ptr){
	List_Node* temp = nullptr;
	if(ptr->list_pointer != nullptr){
		temp = copy(ptr->list_pointer);
	}
	return new List::List_Node(ptr->name, temp);
}

void List::swap(List& rhs){
	std::swap(root, rhs.root);
}

void List::print_reversed() const{
	print_reversed_helper(root);
};



void List::print() const{
	print_helper(root);
};



void List::reverse(){
	root = reverse_helper(root);
};



void List::insert(const std::string& w){
	root = new List_Node(w,root);
};


void List::clear(){

	List_Node* current;
	current = root;
	while (current != nullptr)
	{
		root = root->list_pointer;
		delete current;
		current = root;
	}
}


List::List_Node* List::reverse_helper(List_Node* node){

	List_Node* current = node;
	List_Node* result = nullptr;

	while(current != nullptr){
		List_Node* next = current->list_pointer;
		current->list_pointer = result;
		result = current;
		current = next;
	}
	return result;
};



void List::print_helper(List_Node* node) const{
	if(node == nullptr){
		return;
	}
	while (node->list_pointer != nullptr){
		std::cout << std::setw(10) << node->name << std::endl;
		node = node->list_pointer;
	}
	std::cout << std::setw(10) << node->name << std::endl;
};


void List::print_reversed_helper(List_Node* node) const{
	if(node == nullptr){
		return;
	}
	if(node->list_pointer != nullptr){
		print_reversed_helper(node->list_pointer);
	}
	std::cout << std::setw(10) << node->name << std::endl;
};






