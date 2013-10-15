#include "Monetary.h"

using namespace monetary;

int main(){
	Money m1; // Defaultinitiering, ospeciﬁcerad valuta: 0 enheter 0 hundradelar 
	Money m2(100); // Ospeciﬁcerad valuta: 100 enheter 0 hundradelar 
	Money m3(10, 50); // Ospeciﬁcerad valuta: 100 enheter 50 hundradelar 
	Money m4("SEK"); // Svenska kronor: 0 kronor 0 öre 
	Money m5("SEK", 10); // Svenska kronor: 10 kronor, 0 öre 
	Money m6("FFR", 100, 50);// Franska franc: 100 franc, 50 centimer 
	Money m7(m6); // Franska franc: 100 franc, 50 centimer 
	Money m8(m1); // Ospeciﬁcerad valuta: 0 enheter 0 hundradelar

	m5.print(std::cout);

	std::cout << m5 << std::endl;

	m4 = m5;
	m4 = m3;
	m1 = m6;

	std::cout << m4 << std::endl;

	std::cout << m4 + m4 << std::endl;
	try{
		if(m4 >= m4){
			std::cout << "true" << std::endl;
		}
		else{
			std::cout << "fasle" << std::endl;
		}
	}catch(const monetary_error& e){
		std::cout << e.what() << std::endl;
	}
	/*std::cout << m4-- << std::endl;
	std::cout << m4 << std::endl;

	std::cout << --m4 << std::endl;
	std::cout << m4 << std::endl;*/
	Money m9("SEK", 10, 01); // Svenska kronor: 10 kronor, 01 öre 

	std::cout << m4 + m9 << std::endl;

	//std::cout << m1.currency() << std::endl;
	std::cout << "Gammal m4: " << m4 << std::endl;
	try{
		std::cin >> m4;
	}catch(const monetary_error& e){
		std::cout << e.what() << std::endl;
	}
	std::cout << "Ny m4:  " << m4 << std::endl;
	std::cout << "m9: " << m9 << std::endl;

	std::cout << std::endl << "Slut på main" << std::endl;

	return 0;
	
}