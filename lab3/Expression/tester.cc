#include "Expression_Tree.h"
int main(int argc, char const *argv[])
{
	Integer* a;
	Real* b;

	Plus* c;
	Plus* d;
	Integer* i;
	Integer* h;
	Times* f;
	Power* e;
	int x;
	a = new Integer(5);
	h = new Integer(3);
	i = new Integer(7);
	b = new Real(7.18);
	c = new Plus(a,h);
	d = new Plus(a,c);
	e = new Power(c,d);
	f = new Times(c,i);
	std::cout << f->evaluate() << std::endl;
	f->print(std::cout);
	std::cout << f->get_postfix() << std::endl;

	std::cout << std::endl << std::endl << std::endl;
	std::cout << f->str();

	return 0;
}