#include <iostream>
using namespace std;


int slumptal;
bool playerWon;
int highestPlayerDice;
int highestCompDice;

int howBigBet(int currMoney){ //Ser till att spelaren satser rätt insatser
	int currBet = 99999;

	cout<<"Satsa inför spelet"<<endl;

	while(currBet != 300 && currBet != 100 && currBet != 500){
			cin>>currBet ;
			sleep(.1);
	}
	return currBet;
}               

bool playerFinishBet(){  //används för att spelar ska kunna sätta in pengar i olika mängder
	cout<<"Har du satsar färdigt tryck 0 annars något annat"<<endl;
	int val;
	cin>>val;
	if(val==0){
		return true;
	}else{
		return false;
	}
}


int initBet(){ //Insättning av pengar. 
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

bool playerQuit(){ //används för att spelaren ska kunna avsluta spelet
	cout<<"Vill du avsluta tryck 0 annars något annat"<<endl;
	int val;
	cin>>val;
	if(val==0){
		return true;
	}else{
		return false;
	}
}


int gameLoop(int currMoney){ //stor loop. sköter det mesta spellogiska

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
		cout<<"Spelarens tärningar: " << dice0 << ", " << dice1 <<endl;


		highestPlayerDice = dice0; //Kollar vilken tärning som är störst hos spelaren
		if(dice1 > dice0){
			highestPlayerDice = dice1;
		}
	
	
    	dice0 = rand() % 6 + 1;
    	dice1 = rand() % 6 + 1;
		cout<<"Datorns tärningar: " << dice0 << ", " << dice1 <<endl;
	
		highestCompDice = dice0;  //Motsvarande för datorn
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
		
		
		if(nrOfCompWins == 2){ //När någon vunnit två rundor så skriva medelanden ut
			cout<<"Datorn vinner, vad synd :("<<endl;
			currMoney = currMoney - pot/2;
			cout<<"Du har "<<currMoney<<"kr kvar att satsa"<<endl;
			roundNr = 1; //Värden nollställs så att en ny loop kan köras
			nrOfPlayerWins=0;
			nrOfCompWins=0;		
			if(playerQuit()){ //spelaren frågas om den vill avsluta
				return 0;
				}
			if(currMoney<=0){//Har man för lite pengar måste man fylla på
				cout<<"Du har slut på pengar, sätt in mer"<<endl;
				currMoney = initBet();
				}	
		    	pot = 2 * howBigBet(currMoney);
		}else if(nrOfPlayerWins == 2){//motsvarande för spelaren
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
				cout<<"Du har slut på pengar, sätt in mer"<<endl;
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
	currMoney = initBet(); //Tar in den första insatsen
	gameLoop(currMoney);
	
	
}

