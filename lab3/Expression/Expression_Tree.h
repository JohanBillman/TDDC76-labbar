/*
 * Expression_Tree.h
 */
#ifndef EXPRESSIONTREE_H
#define EXPRESSIONTREE_H
#include <iosfwd>
#include <iostream>
#include <iomanip>
#include <string>
#include <stdexcept>
#include <math.h>
#include <sstream>
#include <stdexcept>
 
/*
 * expression_error: kastas om ett fel inträffar i en Expression-operation;
 * ett diagnostiskt meddelande ska skickas med.
 */
// ATT GÖRA!


// OBSERVERA: NEDANSTÅENDE ÄR ENDAST KODSKELETT - MODIFIERA OCH KOMPLETTERA!

/*
 * Expression_Tree: Abstrakt, polymorf basklass för alla trädnodklasser.
 */



/*
Att fråga om:
1. Fråga ang. clone();

 */
class Expression_Tree
{
public:

	Expression_Tree();
	virtual ~Expression_Tree();
	virtual long double      evaluate() const = 0;
	virtual std::string      get_postfix() const = 0;
	virtual std::string      str() const = 0;
	virtual void             print(std::ostream&, unsigned int = 1) const = 0;
 	virtual Expression_Tree* clone() const = 0;
 	virtual std::string      get_infix() const = 0;
};

class Binary_Operator : public Expression_Tree
{
public:

	Binary_Operator(Expression_Tree*, Expression_Tree*);
	~Binary_Operator();
	void print(std::ostream&, unsigned int = 1) const;
//protected:
	Expression_Tree* left;
	Expression_Tree* right;
	std::string get_postfix() const;
	std::string get_infix() const;

};

class Operand : public Expression_Tree
{
public:

	//Operand();
	//~Operand();
	void print(std::ostream&, unsigned int = 1) const;
//protected:
	std::string get_postfix() const;
	std::string get_infix() const;
};


class Plus : public Binary_Operator
{ 
public:
	Plus(Expression_Tree*,Expression_Tree*);
	~Plus();
	long double evaluate() const;
	std::string str() const;
	Expression_Tree* clone() const;
};

class Assign : public Binary_Operator
{
public:
	Assign(Expression_Tree*, Expression_Tree*);
	~Assign() = default;
	long double evaluate() const;
	std::string str() const;
	Expression_Tree* clone() const; 
};

class Integer : public Operand
{
public:
	Integer(int);
	~Integer();
private:
	int number;
	long double evaluate() const;
	std::string str() const;
	Expression_Tree* clone() const;
};


class Minus : public Binary_Operator 
{
public:
	Minus(Expression_Tree*,Expression_Tree*);
	~Minus();
	long double evaluate() const;
	std::string str() const;
	Expression_Tree* clone() const;
};

class Times : public Binary_Operator
{
public:
	Times(Expression_Tree*,Expression_Tree*);
	~Times();
	long double evaluate() const;
	std::string str() const;
	Expression_Tree* clone() const;
};

class Divide : public Binary_Operator
{
public:
	Divide(Expression_Tree*,Expression_Tree*);
	~Divide();
	long double evaluate() const;
	std::string str() const;
	Expression_Tree* clone() const;
};

class Power: public Binary_Operator
{
public:
	Power(Expression_Tree*,Expression_Tree*);
	~Power();
	long double evaluate() const;
	std::string str() const;
	Expression_Tree* clone() const;
};


class Real : public Operand
{
public:
	Real(long double);
	~Real();
//private:
	long double number;
	long double evaluate() const;
	std::string str() const;
	Expression_Tree* clone() const;
};

class Variable : public Operand
{

public:
	Variable(std::string, long double = 0); //has to take a var table for VG
	~Variable() = default;
	void set_value(long double);
	long double get_value() const;
	Expression_Tree* clone() const;
	long double evaluate() const;

private:
	std::string varName;
	long double number;
	std::string str() const;
};


class expression_error : public std::logic_error{
 	public:
 		explicit expression_error(const std::string& what_arg) noexcept
 		: logic_error(what_arg) {}
 	};

#endif
