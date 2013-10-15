#include <iostream>;
using namespace std;

int howBigBet(int currMoney){
	int currBet = 99999;

	cout<<"Satsa inför spelet"<<endl;

	while(currMoney<currBet){
			cin>>currBet ;
			sleep(.1);
	
	}
	return currBet;
}

void welcomeMessage(){
	cout<<"Välkommen till min tvåarmadebandit som har amputerat den ena armen!"<<endl;
	return;
}

bool playerQuit(){
	cout<<"Vill du avsluta tryck 0 annars något annat"<<endl;
	int val;
	cin>>val;
	if(val==0){
		return true;
	}else{
		return false;
	}
}


int gameLoop(int currMoney){
	int gameArray[2][2];
	while(currMoney>0){
		int pot = howBigBet(currMoney);
		currMoney -= pot;	
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				gameArray[i][j] = rand() % 3;
			}	
		}
		
		int currRows = 0;
		//Horiz rows
		for(int i=0;i<3;i++){
			if((gameArray[i][0] == gameArray[i][1]) && (gameArray[i][1] == gameArray[i][2])){
				currRows++;
				}
		}	
		//Vert rows
		for(int j=0;j<3;j++){
			if((gameArray[0][j] == gameArray[1][j]) && (gameArray[1][j] == gameArray[2][j])){
				currRows++;
				}
		}
		//diagRows
		if((gameArray[0][0] == gameArray[1][1]) && (gameArray[1][1] == gameArray[2][2])){
				currRows++;
				}
		if((gameArray[0][2] == gameArray[1][1]) && (gameArray[1][1] == gameArray[2][0])){
				currRows++;
				}
	
	for(int i=0;i<3;i++){
			cout<<endl;
			for(int j=0;j<3;j++){
				cout<<gameArray[i][j]<<" ";
				}	
		}
	
	cout<<endl;
	if(currRows==0){
		cout<<"Du fick 0 rader och förlorar din insats"<<endl;
		cout<<"Du förlorar din insats"<<endl;		
		}else if(currRows==1){
			cout<<"Du fick 1 rader"<<endl;
			cout<<"Du vinner "<<2*pot<<endl;
			currMoney += 2*pot;
		}else if(currRows==2){
			cout<<"Du fick 2 rader"<<endl;
			cout<<"Du vinner "<<4*pot<<endl;
			currMoney += 4*pot;
		}else if(currRows==3){
			cout<<"Du fick 3 rader"<<endl;
			cout<<"Du vinner "<<4*pot<<endl;
			currMoney += 8*pot;
		}else if(currRows==4){
			cout<<"Du fick 4 rader"<<endl;
			cout<<"Du vinner "<<16*pot<<endl;
			currMoney += 16*pot;
		}else if(currRows>4){
			cout<<"Du fick ett fullt spelfält"<<endl;
			cout<<"Du vinner "<<128*pot<<endl;
			currMoney += 128*pot;
		}
		if(playerQuit()){
			cout<<"Du tar ut "<<currMoney<<" och fölorar allt i spelskatten"<<endl;
			return 0;
			}
	currRows=0;		
	}
}



int main(){
	
	srand(time(0));
	welcomeMessage();
	cout<<"Hur mycket vill du satsa?"<<endl;
	int currMoney;
	while(currMoney != 50 && currMoney != 100 && currMoney != 500){
			cin>>currMoney;
			sleep(.1);
	}
	
	gameLoop(currMoney);
	return 0;
} 