#include <iostream>
#include <cctype>
using namespace std;

int main(){
	int char_counter           = 0;                                                            
	int numbers                = 0;                                                                                          
	int interpunctuation_chars = 0;
	int white_space            = 0;                                                                  
	int total_chars            = 0;                                                                  

	cout <<"Skriv en text: " << endl;
	char c;

	while(cin.get(c)){
		if(isalpha(c)){
			char_counter++;
		}
		if(isdigit(c)){
			numbers++;
		}
		if(ispunct(c)){
			interpunctuation_chars++;
		}		
		if(isspace(c)){
			white_space++;
		}
		total_chars++;
	}

	cout << endl << endl << "Indata innehöll:" << endl << endl;
	cout << char_counter << " alfabetiska tecken" << endl;
	cout << numbers << " siffertecken" << endl;
	cout << interpunctuation_chars << " interpunktionstecken" << endl;
	cout << white_space << " vita tecken" << endl;
	cout << total_chars << " tecken totalt" << endl << endl;

	return 0;

}
