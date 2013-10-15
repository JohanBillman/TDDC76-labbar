/*

 * IDENTIFIERING 
 *FILNAMN			List.h
 *LABORANTION		1
 *PROGRAMMERARE		emmva911 johbi142
 *DATUM				2013-09-18
 *BESKRIVNING		Laboration 1.5

 * 
 *
 * BESKRIVNING 
 * Initierar List klassen samt skapar structarna till den länkade listan
 *
 * REVISIONSBERÄTTELSE 
 * 
 * Revision     Datum   Förändringar 
 * 
 * 1            130918  Ursprungsversion 
 * 2            2013-09-25 Komplettering
 * 3			2013-10-04 Komplettering
 */


#ifndef LIST_H 
#define LIST_H 

#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <utility>


 class List{	

 public:	
 	struct List_Node{
 		std::string name;
 		List_Node* list_pointer = nullptr;

 		List_Node(){
 			std::string name;
 			List_Node* list_pointer = nullptr;

 		}

 		List_Node(std::string str, List_Node* p){
 			name = str;
 			list_pointer = p;
 		}
 	};



 	/*~List_Node(){
 	}

 	List_Node(const List_Node& lnode){
 		this->name = lnode.name;
 		this->list_pointer = lnode.list_pointer;
 	}

 	List_Node& operator=(const List_Node& lnode){
 		if(this != &lnode){
 			this->name = lnode.name;
 			this->list_pointer = lnode.list_pointer;
 		}
 		return *this;
 	}*/

 		
 		List();
 		List(const List&);
 		~List();

 		List& operator=(const List&);

 		void print_reversed() const;

 		void print() const;

 		void reverse();

 		void insert(const std::string& w);

 		void clear();

 		void swap(List&);

 	private:

 		List_Node* root;

 		List_Node* copy(List_Node*);

 		void construct_(const List_Node*);

 		void print_reversed_helper(List_Node* node) const;

 		void print_helper(List_Node* node) const;

 		List_Node* reverse_helper(List_Node* node);

 		void clear_helper(List_Node* node);

 	};



#endif