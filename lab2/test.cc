#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int x;

	cin >> x;

	cout << "cout skriver:" << x << "slut här" << endl;

	/*char c;
	while(isspace(cin.peek())){
		c = cin.get();
	}*/

	char c;
 	if(cin.peek() == '.'){
 		cout << cin.peek();
 		c = cin.get();
 	}


	cin >> x;

	cout << "cout skriver:" << x << "slut här" << endl;
	

	return 0;
}