/*
 * FILNAMN:       Monetary.h
 * LABORATION:    2
 * PROGRAMMERARE: Johan Billman 9202271772 johbi142
 * 				  Emma Värbrand 9101283068 emmva911
 * DATUM:         2013-09-26
 *
 * BESKRIVNING 
 * 
 * headerfil för klassen Monetary och felklassen monetary_error
 */

#ifndef MONEY_H
#define MONEY_H

#include <iostream>
#include <iomanip>
#include <String>
#include <cctype>
#include <stdexcept>
#include <sstream>

 namespace monetary{
 	class Money{

 	public: 		
 		Money(const int, const int = 0);
 		Money(const std::string = "", const int = 0, const int = 0);
 		Money(const Money&) = default;
 		~Money() = default;

 		
 		Money& operator=(const Money&);
 		const Money operator+(const Money&) const;
 		const Money operator-(const Money&) const;
 		Money& operator+=(const Money);
 		Money& operator-=(const Money);

 		bool operator<(const Money&) const;
 		bool operator==(const Money&) const;
 		bool operator!=(const Money&) const;
 		bool operator<=(const Money&) const;
 		bool operator>=(const Money&) const;
 		bool operator>(const Money&) const;


 		Money& operator++();
 		Money operator++(int);

 		Money& operator--();
 		Money operator--(int);

 		void print(std::ostream&) const;

 		std::string currency() const; 		

 	private:
 		std::string currenci;
 		int units; 
 		int cents;


 		void remove_ws(std::istream&);
 		bool remove_pc(std::istream&);
 		std::string read_currency(std::istream&);
 		int read_units(std::istream&);
 		int read_cents(std::istream&);
 		bool values_ok(const int, const int) const;
 		bool values_ok(const std::string, const int, const int) const;
 		bool currencies_ok(const std::string, const std::string) const;
		friend std::istream& operator>>(std::istream&, Money&);
 	};

 	std::ostream& operator<<(std::ostream&, const Money&);
 	std::istream& operator>>(std::istream&, Money&);

 	class monetary_error : public std::logic_error{
 	public:
 		explicit monetary_error(const std::string& what_arg) 
 		: logic_error(what_arg) {}
 	};

 }

#endif
