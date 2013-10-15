#include "Expression_Tree.h"
int main(int argc, char const *argv[])
{
	Integer* a;
	Real* b;

	Plus* c;
	Plus* d;
	Times* f;
	Power* e;
	int x;
	a = new Integer(8);
	b = new Real(7.18);
	c = new Plus(a,b);
	d = new Plus(a,c);
	e = new Power(c,d);
	f = new Times(c,a);
	std::cout << e->evaluate() << std::endl;
	e->print(std::cout);
	std::cout << e->get_postfix() << std::endl;

	std::cout << std::endl << std::endl << std::endl;
	std::cout << b->str();

	return 0;
}