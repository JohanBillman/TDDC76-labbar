#include <iostream>
#include <iomanip>
using namespace std;
void print_squares(int n)
{
 cout << '\n' << setw(6) << "i" << setw(12) << "i * i" << "\n\n";
 for (int i = 1; i <= n; ++i)
 {
  cout << setw(6) << i << setw(12) << i * i << '\n';
 }
}
int main()
{
 int x;
 cout << "Ge ett positivt heltal: ";
 cin >> x;
 if (x < 1)
  cout << "Det var inget positivt heltal!\n";
 else if (x>1000)
cout << "Talet är för stort!\n";
else
  print_squares(x);
return 0;
}