/*
 * Expression_Tree.cc
 */
#include "Expression_Tree.h"
// INKLUDERA FÖR DET SOM KOMMER ATT ANVÄNDAS I DENNA FIL!
 using namespace std;

// SEPARATA DEFINITIONER FÖR FÖR EXPRESSION_TREE-KLASSERNA DEFINIERAS HÄR.
//frågor
//1. Variabler och dynamic cast.
//2.	varför skriver vi inte i clone:
	  //return new Times(left->clone(),right->clone()); 

		//new_left = left->clone();
		//new_right = right->clone();
		//temp = new Times(new_left, new_right);

//3. Är utskriften från expression-test.cc korrekt? 
//4. Vad är värdet (evaluate) och postfixet för ett tomt träd?
//5. Fråga om hur man gör om till infix
//6. Fråga om hur de med felhantering i make_expression_tree



 Expression_Tree::Expression_Tree(){};

 Expression_Tree::~Expression_Tree(){};	



 Binary_Operator::Binary_Operator(Expression_Tree* l, Expression_Tree* r){
 	left = l;
 	right = r;
 }

 Binary_Operator::~Binary_Operator(){
 	delete this->left;
 	delete this->right;	
 }

 string Binary_Operator::get_postfix() const {
 	return left->get_postfix() + " " + right->get_postfix() + " " + this->str();
 }	

 void Binary_Operator::print(ostream& os,unsigned int c) const{
 	right->print(os, c + 2);
 	os << setfill(' ') << setw(c + 1) << "/" << endl;
 	os << setfill(' ') << setw(c) << this->str() << endl;
 	os << setfill(' ') << setw(c + 1) << "\\" << endl;
 	left->print(os, c + 2);

	return;
}

string Binary_Operator::get_infix() const{
	
}

string Operand::get_postfix() const{
	return this->str();
}

void Operand::print(ostream& os, unsigned int c) const{
	string to_print = this->str();
	os << setfill(' ') << setw(c + to_print.size()) << to_print << endl;
}



//Binary_Operators subclasses


Plus::Plus(Expression_Tree* l, Expression_Tree* r):Binary_Operator(l,r){
}
Plus::~Plus(){
}

long double Plus::evaluate() const{
	return left->evaluate() + right->evaluate();
}

string Plus::str() const{
	return "+";
}

Divide::Divide(Expression_Tree* l, Expression_Tree* r):Binary_Operator(l,r){
}
Divide::~Divide(){
}

long double Divide::evaluate() const{
	if(right->evaluate() == 0){
		cout << "Kasta ett fel" << endl;
		//throw error("Divide by zero");
	}
	return left->evaluate() / right->evaluate();
}

string Divide::str() const{
	return "/";
}

Power::Power(Expression_Tree* l, Expression_Tree* r):Binary_Operator(l,r){
}
Power::~Power(){
}

long double Power::evaluate() const{
	return pow(left->evaluate(),right->evaluate());
}

string Power::str() const{
	return "^";
}

Minus::Minus(Expression_Tree* l, Expression_Tree* r):Binary_Operator(l,r){
}

Minus::~Minus(){
}

long double Minus::evaluate() const{
	return left->evaluate() - right->evaluate();
}

string Minus::str() const{
	return "-";
}


Times::Times(Expression_Tree* l, Expression_Tree* r):Binary_Operator(l,r){
}

Times::~Times(){
}

long double Times::evaluate() const{
	return left->evaluate() * right->evaluate();
}

string Times::str() const{
	return "*";
}


Assign::Assign(Expression_Tree* l, Expression_Tree* r) : Binary_Operator(l,r){
	if(not isalpha(l->str()[0] and r->str().size()==0)){
		throw expression_error("Det får endast stå variabler till vänster om =");
	}
}

string Assign::str() const{
	return "=";
}


long double Assign::evaluate() const{

	Variable* leftVar = dynamic_cast<Variable*>(left);
	if(leftVar == nullptr)
		throw expression_error("Det måste vara en variabel till vänster om =");
	leftVar->set_value(right->evaluate());
	return right->evaluate();
}

//Operands subclasses

Integer::Integer(int num){
	number = num; 
}

Integer::~Integer(){
}

long double Integer::evaluate() const{
	return number;
}

string Integer::str() const{
	return to_string(number);
}

Real::Real(long double num){
	number = num;
}

Real::~Real(){
}

long double Real::evaluate() const{
	return number;
}

string Real::str() const{
	ostringstream ss;
	ss << number;
	return string(ss.str());
}

Variable::Variable(string varName_, long double num){
	number = num;
	varName=varName_;
}

long double Variable::evaluate() const{
	//lookup(table);
	return number;
}

string Variable::str() const{
	return varName;
}
void Variable::set_value(long double num){
	number = num;
}

long double Variable::get_value() const{
	return this->evaluate();
}



//////////////////LAND OF CLONES
Expression_Tree* Assign::clone() const{
	Expression_Tree* new_left = nullptr;
	Expression_Tree* new_right = nullptr;
	Assign* temp = nullptr; 
	
	try{
		new_left = left->clone();
		new_right = right->clone();
		temp = new Assign(new_left, new_right);
	}
	catch(...){
		delete new_right;
		delete new_left;
		delete temp;

		throw;
	}
	return temp;
}


Expression_Tree* Plus::clone() const{
	Expression_Tree* new_left = nullptr;
	Expression_Tree* new_right = nullptr;
	Plus* temp = nullptr; 
	
	try{
		new_left = left->clone();
		new_right = right->clone();
		temp = new Plus(new_left, new_right);
	}
	catch(...){
		delete new_right;
		delete new_left;
		delete temp;

		throw;
	}
	return temp;
}

Expression_Tree* Minus::clone() const{
	Expression_Tree* new_left = nullptr;
	Expression_Tree* new_right = nullptr;
	Minus* temp = nullptr; 
	
	try{
		new_left = left->clone();
		new_right = right->clone();
		temp = new Minus(new_left, new_right);
	}
	catch(...){
		delete new_right;
		delete new_left;
		delete temp;

		throw;
	}
	return temp;
}

Expression_Tree* Times::clone() const{
	Expression_Tree* new_left = nullptr;
	Expression_Tree* new_right = nullptr;
	Times* temp = nullptr; 
	
	try{
		new_left = left->clone();
		new_right = right->clone();
		temp = new Times(new_left, new_right);
		//varför skriver vi inte:
		//return new Times(left->clone(),right->clone())
	}
	catch(...){
		delete new_right;
		delete new_left;
		delete temp;

		throw;
	}
	return temp;
}

Expression_Tree* Divide::clone() const{
	Expression_Tree* new_left = nullptr;
	Expression_Tree* new_right = nullptr;
	Divide* temp = nullptr; 
	
	try{
		new_left = left->clone();
		new_right = right->clone();
		temp = new Divide(new_left, new_right);
	}
	catch(...){
		delete new_right;
		delete new_left;
		delete temp;

		throw;
	}
	return temp;
}

Expression_Tree* Power::clone() const{
	Expression_Tree* new_left = nullptr;
	Expression_Tree* new_right = nullptr;
	Power* temp = nullptr; 
	
	try{
		new_left = left->clone();
		new_right = right->clone();
		temp = new Power(new_left, new_right);
	}
	catch(...){
		delete new_right;
		delete new_left;
		delete temp;

		throw;
	}
	return temp;
}

Expression_Tree* Integer::clone() const{
	try{
		return new Integer(number);
	}
	catch(...){
		throw;
	}
}

Expression_Tree* Real::clone() const{
	try{
		return new Real(number);
	}
	catch(...){
		throw;
	}
}

Expression_Tree* Variable::clone() const{
	try{
		return new Variable(*this);
	}
	catch(...){
		throw;
	}
}