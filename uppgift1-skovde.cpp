#include <iostream>
using namespace std;


int slumptal;
bool playerWon;
int highestPlayerDice;
int highestCompDice;

int howBigBet(int currMoney){ //Ser till att spelaren satser r�tt insatser
	int currBet = 99999;

	cout<<"Satsa inf�r spelet"<<endl;

	while(currBet != 300 && currBet != 100 && currBet != 500){
			cin>>currBet ;
			sleep(.1);
	}
	return currBet;
}               

bool playerFinishBet(){  //anv�nds f�r att spelar ska kunna s�tta in pengar i olika m�ngder
	cout<<"Har du satsar f�rdigt tryck 0 annars n�got annat"<<endl;
	int val;
	cin>>val;
	if(val==0){
		return true;
	}else{
		return false;
	}
}


int initBet(){ //Ins�ttning av pengar. 
	int currMoney=0;
	int alloc;		
	while(true){
			cin>>alloc;
			currMoney += alloc;
			sleep(.1);
			if(currMoney>5000){
				return currMoney;
				}
			if(playerFinishBet()){
				return currMoney;
				}else{
					cout<<"Satsa mer"<<endl;
					}
	}
	return currMoney;
}

bool playerQuit(){ //anv�nds f�r att spelaren ska kunna avsluta spelet
	cout<<"Vill du avsluta tryck 0 annars n�got annat"<<endl;
	int val;
	cin>>val;
	if(val==0){
		return true;
	}else{
		return false;
	}
}


int gameLoop(int currMoney){ //stor loop. sk�ter det mesta spellogiska

	int	dice0;
	int	dice1;
	int roundNr=1;
	int pot;
	int nrOfPlayerWins=0;
	int nrOfCompWins=0;
   	pot = 2 * howBigBet(currMoney); 	

	while(true){
		//Player rolls dices
	    dice0 = rand() % 6 + 1;
	    dice1 = rand() % 6 + 1;
		cout<<"Spelarens t�rningar: " << dice0 << ", " << dice1 <<endl;


		highestPlayerDice = dice0; //Kollar vilken t�rning som �r st�rst hos spelaren
		if(dice1 > dice0){
			highestPlayerDice = dice1;
		}
	
	
    	dice0 = rand() % 6 + 1;
    	dice1 = rand() % 6 + 1;
		cout<<"Datorns t�rningar: " << dice0 << ", " << dice1 <<endl;
	
		highestCompDice = dice0;  //Motsvarande f�r datorn
		if(dice1 > dice0){
			highestCompDice = dice1;
		}
	
   		if(highestPlayerDice > highestCompDice){  //Kollar vem som vinner rundan
			nrOfPlayerWins++;
			cout<<"Spelaren vinner runda: "<<roundNr<<endl;
			roundNr++;
		}else{
			nrOfCompWins++;
			cout<<"Datorn vinner runda: "<<roundNr<<endl;
			roundNr++;
		}
		
		
		if(nrOfCompWins == 2){ //N�r n�gon vunnit tv� rundor s� skriva medelanden ut
			cout<<"Datorn vinner, vad synd :("<<endl;
			currMoney = currMoney - pot/2;
			cout<<"Du har "<<currMoney<<"kr kvar att satsa"<<endl;
			roundNr = 1; //V�rden nollst�lls s� att en ny loop kan k�ras
			nrOfPlayerWins=0;
			nrOfCompWins=0;		
			if(playerQuit()){ //spelaren fr�gas om den vill avsluta
				return 0;
				}
			if(currMoney<=0){//Har man f�r lite pengar m�ste man fylla p�
				cout<<"Du har slut p� pengar, s�tt in mer"<<endl;
				currMoney = initBet();
				}	
		    	pot = 2 * howBigBet(currMoney);
		}else if(nrOfPlayerWins == 2){//motsvarande f�r spelaren
			cout<<"Spelaren vinner"<<endl;
			currMoney = currMoney + pot;
			cout<<"Du vann "<<pot<<" och har nu totalt "<<currMoney<<"kr"<<endl;
			roundNr = 1;
			nrOfPlayerWins=0;
			nrOfCompWins=0;			
			if(playerQuit()){
				return 0;
				}
			if(currMoney<=0){
				cout<<"Du har slut p� pengar, s�tt in mer"<<endl;
				currMoney = initBet();
				}
	    	pot = 2 * howBigBet(currMoney);

		}
	}	
}
       
	


int main(){
 
 	srand(time(0));
	
	cout<<"Hur mycket vill du satsa?"<<endl;
	int currMoney;
	currMoney = initBet(); //Tar in den f�rsta insatsen
	gameLoop(currMoney);
	
	
}

