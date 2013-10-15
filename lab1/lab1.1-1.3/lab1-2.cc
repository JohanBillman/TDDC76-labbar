#include <iostream>
using namespace std;


static double input_Function(){
  double read_value;

	cout << "Ge en temperatur i Kelvin: ";
  	cin >> read_value;
  while(read_value < 0){
      cout << "Negativa kelvinvärden är ej tillåtna!" << endl;
	  cout << "Ge en temperatur i Kelvin: ";
      cin >> read_value;
    }
  return read_value; 
}


int main(){
	double temp_in_kelvin = 1;

	while(temp_in_kelvin > 0){
		temp_in_kelvin = input_Function();

		cout.precision(2);
		cout << fixed << temp_in_kelvin << " Kelvin motsvarar " << temp_in_kelvin - 273.15;
    	cout << " grader Celsius eller " << 1.8*temp_in_kelvin - 459.67 << " grader Farenheit." << endl << endl;
	}
	
	cout << "Slut." << endl << endl;
	return 0;
}