/*
FILNAMN			lab1-5.cc
LABORANTION		1
PROGRAMMERARE	emmva911 johbi142
DATUM			2013-09-18
BESKRIVNING		Laboration 1.5 Huvudprogram fil, hanterar inläsning från fil. Skapar listan.
 */

#include "List.h"

using namespace std;




int main(int argc, char const *argv[])
{
	if (argc!=2){
		cout << "Felmeddelande: Du har inte skrivit in ETT ord" << endl;
		return 1;
	}
	
	fstream fs;
	fs.open (argv[1], fstream::in );
	
	if (fs.fail()){
		cout << "Felmeddelande: Filnamnet finns ej!" << endl;
		return 1;
	}

	string w;
	
	List name_list;
	
	while(fs >> w){
		name_list.insert(w);
	}
	fs.close();

	cout << "print_reversed" << endl << endl; 
	//name_list.print_reversed();
	//cout << "print" << endl << endl;
	//name_list.print();
	//cout << "reverse" << endl;
	//name_list.reverse();
	//cout <<"listan vänd" << endl;
	//name_list.print();
	//name_list.clear();
	//cout << "listan tömd" << endl;
	//name_list.print();
	//name_list.print_reversed();
	//cout << "slut" << endl;
	//name_list.print();
	List list2 = name_list;
	list2.insert("Johan");
	list2.print_reversed();
	cout << "Hej" << endl << endl;
	name_list.print_reversed();

	return 0;
}