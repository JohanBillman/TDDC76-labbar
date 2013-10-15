/*
FILNAMN			lab1-4.cc
LABORANTION		1
PROGRAMMERARE	emmva911 johbi142
DATUM			2013-09-18
BESKRIVNING		Laboration 1.4. Ett litet program för att räkna antalet ord som skrivs in
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


struct word_entry{
	string word;
	unsigned int number_of_occ;
};

//Inserts string at the correct place in the vector
static void insert(const string& word, vector<word_entry>& list){
	for(unsigned int i=0;i<list.size();i++){
			//Checks if the word is to be inserted at i
		if(word<list.at(i).word){
			word_entry temp;
			temp.word = word;
			temp.number_of_occ = 1;

			list.insert(list.begin()+i,temp);
			break;
		}
		if(list.at(i).word == word){
			list[i].number_of_occ++;
			break;
		}
			//If the word is to be entered last in the vector
		else if(i == list.size() - 1){
			word_entry temp;
			temp.word = word;
			temp.number_of_occ = 1;
			list.insert(list.end(),temp);
			break;
		}
	}
		//If the vector is empty
	if (list.size()==0){
		word_entry temp;
		temp.word = word;
		temp.number_of_occ = 1;
		list.push_back(temp);
	}
	
	return;
}

//Prints the list
static void print(const vector<word_entry>& list){
	cout << endl << endl << setw(10) << "Ord" << "  " << left << setw(10) << "Antal" << endl << endl;
	for(unsigned int i=0;i<list.size();i++){
		cout << setw(10) << right << list[i].word << "  " << setw(10) << left << list[i].number_of_occ << endl;
	}
	return;
}

int main(){
	vector<word_entry> word_list;
	string read_word;
	cout << "Skriv in en text" << endl;
	//Reads the input word by word -> transforms it to lowercase
	//and inserts it in the vector (word_list)
	while(cin >> read_word){
		transform(read_word.begin(),read_word.end(),read_word.begin(), ::tolower);
		insert(read_word,word_list);
	}
	print(word_list);
	return 0;	
}

