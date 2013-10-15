#include <iostream>
using namespace std;

int main(int argc, char* argv[]) 
{
  if (argc == 1)
  {
   cout << "C++ is so cool!\n";
  }
  else
  {
   for (int i = argc - 1; i > 0	; i=i-1)
//    cout << i << endl;	 
	cout << argv[i] << " ";
  }
}