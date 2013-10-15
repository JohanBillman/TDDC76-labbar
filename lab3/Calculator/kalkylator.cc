/*
 * kalkylator.cc
 *
 * Ett objekt av typen Calculator skapas i main() och Calculator::run()
 * körs. Om ett undantag kastas av Calculator::run() fångas detta och 
 * programmet avslutas sedan efter att ett felmeddelande skrivits ut.
 * Alla förutsedda fel ska ha fångats och hanterats av Calculator::run().
 */
#include "Calculator.h"
#include <iostream>
using namespace std;

int main()
{
   Calculator calc;

   try
   {
      calc.run();
   }
   catch (...)
   {
      cout << "Ett okänt fel har inträffat.\n";
   }

   return 0;
}
