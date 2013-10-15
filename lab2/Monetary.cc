/*
 * FILNAMN:       Monetary.cc
 * LABORATION:    2
 * PROGRAMMERARE: Johan Billman 9202271772 johbi142
 * 				  Emma Värbrand 9101283068 emmva911
 * DATUM:         2013-10-02
 *
 * BESKRIVNING 
 * 
 * Innehåller medlemsfunktioner till klassen Money samt tillhörande operatorer.
 */


#include "Monetary.h"
 namespace monetary{

 	Money::Money(const int units_, const int cents_){
 		if(values_ok(units_,cents_)){
 			units = units_;
 			cents = cents_;
 			currenci = "";
 		}
 	}


 	Money::Money(const std::string curr_, const int units_, const int cents_){
 		if(values_ok(curr_,units_,cents_)){
 			units = units_;
 			cents = cents_;
 			currenci = curr_;
 		}
 	}

 	Money& Money::operator=(const Money& obj){
 		if(currencies_ok(currenci, obj.currenci)){
 			units = obj.units;
 			cents = obj.cents;
			// If one of them are without a currency, both get the same currency
 			if(currenci == ""){
 				currenci = obj.currenci;
 			}
 		}else{
 			throw monetary_error("Valutorna stämmer ej överens");
 		}
 		return *this;
 	}

 	Money& Money::operator+=(const Money obj){
 		*this = *this + obj;
 		if(currenci == ""){
 			currenci = obj.currenci;
 		}
 		return *this;
 	}

 	Money& Money::operator-=(const Money obj){
 		*this = *this - obj;
 		if(currenci == ""){
 			currenci = obj.currenci;
 		}
 		return *this;
 	}


 	bool Money::operator<(const Money& arg) const{
 		if(currencies_ok(currenci, arg.currenci)){
 			if(units < arg.units){
 				return true;
 			}
 			else if(units == arg.units && cents < arg.cents){
 				return true;	
 			}
 			return false;
 		}
 		throw monetary_error("Valutorna stämmer ej överens");
 	}

 	bool Money::operator==(const Money& arg) const{
 		if(currencies_ok(currenci, arg.currenci)){
 			if(units == arg.units && cents == arg.cents){
 				return true;
 			}
 			return false;
 		}
 		throw monetary_error("Valutorna stämmer ej överens");
 	}

	//Using xor-logic to create comparisions

 	bool Money::operator!=(const Money& arg) const{
 		return !(*this == arg);
 	}

 	bool Money::operator<=(const Money& arg) const{
 		return (*this == arg || *this < arg);
 	}

 	bool Money::operator>=(const Money& arg) const{
 		return (*this == arg || !(*this < arg));
 	}

 	bool Money::operator>(const Money& arg) const{
 		return !(*this <= arg);
 	}

 	Money& Money::operator++(){
 		int new_cents = cents + 1;
 		if(new_cents >= 100){
 			units = units + 1;
 			new_cents -= 100;
 		}
 		cents = new_cents;
 		return *this;
 	}

 	Money Money::operator++(int n){
	//store the current values
 		int old_units = units;
 		int old_cents = cents;

 	//update the objects values
 		cents = cents + 1;
 		if(cents >= 100){
 			units = units + 1;
 			cents -= 100;
 		}
 	//returns an object with the old values
 		return Money(currenci, old_units, old_cents);	
 	}

 	Money Money::operator--(int n){
 		int old_cents = cents;
 		int old_units = units;

 		cents = cents - 1;
 		if(cents < 0){
 			units = units - 1;
 			cents = 1 + cents;
 			if(units < 0){
 				throw monetary_error("Negativt belopp");
 			}
 		}
 		return Money(currenci, old_units, old_cents);
 	}

 	Money& Money::operator--(){
 		int new_cents = cents - 1;
 		int new_units = units;
 		if(new_cents < 0){
 			new_units = new_units - 1;
 			new_cents = 1 + new_cents;
 			if(new_units < 0){
 				throw monetary_error("Negativt belopp");
 			}
 		}
 		cents = new_cents;
 		units = new_units;
 		return *this;
 	}

 	const Money Money::operator+(const Money& arg) const{
 	//Checks if either is empty
 		if(currencies_ok(currenci, arg.currenci)){
 			int new_units = units + arg.units;
 			int new_cents = cents + arg.cents;
		//Checks if we got a new unit, if so converts it.
 			if(new_cents >= 100){
 				new_units++;
 				new_cents -= 100;
 			}
 			return Money(currenci, new_units, new_cents);
 		}
 		throw monetary_error("Valutorna stämmer ej överens");
 	}

 	const Money Money::operator-(const Money& arg) const{
 		if(*this >= arg){
 			int new_units = units - arg.units;
 			int new_cents = cents - arg.cents;
 			std::string new_currenci = currenci;
 		
 			if(new_cents < 0){
 				new_units = units - 1;
 				new_cents = 100 + cents;
 			}

 			return Money(currenci, new_units, new_cents);
 		}else{
 			throw monetary_error("Negativt belopp");
 		}
 	}




 	void Money::print(std::ostream& os) const{
 		if(currenci == ""){
 			os << units << "." << std::setfill('0') << std::setw(2) << cents;

 		}else{
 			os << std::setw(3) << currenci << " " << units << "." << std::setfill('0') << std::setw(2) << cents; 
 		}
 	}


 	std::ostream& operator<<(std::ostream& os, const Money& obj){
 		obj.print(os);
 		return os;
 	}

 	std::istream& operator>>(std::istream& is, Money& obj){
 		std::string read_curr = "";
 		int read_units_ = 0;
 		int read_cents_ = 0;


 		obj.remove_ws(is);
 		if(isalpha(is.peek())){
 			read_curr = obj.read_currency(is);
 			if(is.peek() == ' '){
 				std::cout << "a" << is.get() << "a" << std::endl;
 				if(!isdigit(is.peek())){
 					   is.setstate(std::ios::failbit);
 					throw monetary_error("Felaktig inmatning");
 				}
 			}else{
 				is.setstate(std::ios::failbit);
 				throw monetary_error("Felaktig inmatning");
 			}
 		}


 		read_units_ = obj.read_units(is);

 		if(obj.remove_pc(is)){ //removes the punct
 			read_cents_ = obj.read_cents(is);
 		}

 		if(obj.currencies_ok(obj.currenci, read_curr)){
 			obj.units = read_units_;
 			obj.cents = read_cents_;
 			if(obj.currenci == ""){
 				obj.currenci = read_curr;
 			}
 		}else{
 			throw monetary_error("Valutorna matchar inte");
 		}
 		return is;
 	}
 		//Removes a dot if there is one and returns true if it was removed
 	bool Money::remove_pc(std::istream& is){
 		char c;
 		if(is.peek() == '.'){
 			c = is.get();
 			return true;
 		}else{
 			return false;
 		}
 	}

 		//Removes whitespace
 	void Money::remove_ws(std::istream& is){
 		char c;
 		while(isspace(is.peek())){
 			c = is.get();
 		}
 	}

 	std::string Money::read_currency(std::istream& is){
 		//This function is called when all starting whitespace is gone
 		//and the first char is a letter
 		std::string read_curr;

 		is >> read_curr;

 		if(read_curr.length() == 3){ //if the word is 3 long
 			for (int i = 0;i < 3;i++){ //go throw the word, letter by letter
 				if(!isupper(read_curr[i])){ //checks if one letter is not a upper
 					is.setstate(std::ios::failbit);
 					throw monetary_error("Inmatningen ej en riktig valuta");
 				}
 			}
 			return read_curr;
 		}
 		is.setstate(std::ios::failbit);
 		throw monetary_error("Inmatningen av valuta har fel längd");
 	}

 	int Money::read_units(std::istream& is){
 		//reads the units, whitespace is removed when called
 		int read_units_;

 		is >> read_units_;
 		return read_units_;
 	}

 	int Money::read_cents(std::istream& is){
 		//reads the cents, after the punct, is called with the punct removed.
 		std::string temp_digit = "0";
 		std::string second_digit = "0";

 		temp_digit = is.get();
 		if(isdigit(is.peek())){
 			second_digit = is.get();
 		}
 		//append the strings
 		temp_digit += second_digit;
 		int read_cents_;
 		//convert the string to an int
 		std::istringstream(temp_digit) >> read_cents_;

 		return read_cents_;
 	}

 	std::string Money::currency() const{
 		return currenci;
 	}

 	bool Money::currencies_ok(const std::string s1, const std::string s2) const{
 		 return (s1 == "" || s2 == "" ||  s1 == s2);
 	}

 	bool Money::values_ok(const int units_, const int cents_) const{
 		if(units_ < 0 || cents_ < 0 || cents_ > 99){
 			return false;
 			throw monetary_error("Felaktiga startvärden för en valuta");
 		}
 		return true;
 	}

 	bool Money::values_ok(const std::string curr_, const int units_, const int cents_) const{
 		if(curr_.length() == 3){ //if the word is 3 long
 			for (int i = 0;i < 3;i++){ //go throw the word, letter by letter
 				if(!isupper(curr_[i])){ //checks if one letter is not a upper
 					return false;
 					throw monetary_error("Felaktigt angiven valuta");
 				}
 			}
 			return values_ok(units_,cents_);
 		}else{
 			return false;
 			throw monetary_error("Felaktig längd på valutan");
 		}
 	}
 }
