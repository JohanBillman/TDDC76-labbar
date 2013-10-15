#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
 

static int input_Function(){
  int read_value;

  cout << "Ge önskat slutvärde (minst 1): ";
  cin >> read_value;
  while(read_value < 0){
      cout << "Felaktigt värde, försök igen!" << endl;
      cout << "Ge önskat slutvärde (minst 1): ";
      cin >> read_value;
    }
  return read_value; 
}

int main(){
  int value = input_Function();
 
  cout << setw(10) << "DEC" << setw(10) << "OKT" << setw(10) << "HEX" << "\n\n";
  for(int i=1; i<=value; i++){
      cout << setw(10) << dec << i << setw(10) << oct << i << setw(10) << hex << i ;
      cout << endl;
    }
  return 0;
}
