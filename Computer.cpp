#include"Player.h"
#include"Computer.h"

Computer::Computer(){
    //0-Meek 1-Random 2-Wild 3-Dealer
    personality=rand()%3;
}

void Computer::setDealer(){
	personality=3;
	setName("Dealer");
    setBankroll(100000);
}

int Computer::getPersonality(){
	return personality;
}

int Computer::decideBet(){
	//0-Meek 1-Random 2-Wild 3-Dealer
	int bet=0;
	if(personality==0){
		bet=2*(1+getRoundWin()/3);
	}
	else if(personality==1){
		if(getBankroll()<=1)bet=1;
		else bet=rand()%getBankroll();
	}
	else if(personality==2){
		bet=1000;
	}
	else{
		bet=0;
	}
	setBet(bet);
	return bet;
}

bool Computer::decideDraw(){
	//0-Meek 1-Random 2-Wild 3-Dealer
    if(personality==0){
		//if(getTotalClub(cardDeck)==7)return true;

		if(getTotalPoint()%2==0)return true;
		else return false;	
    }
    else if(personality==1){
		int point=getTotalPoint();
        if(point<=9)return true;
		else if(point>=10 && point<=12){
			if(rand()%10>=8)return true;
			else return false;
		}
		else if(point>=13 && point<=15){
			if(rand()%10>=7)return true;
            else return false;
		}
		else if(point>=16 && point<=18){
            if(rand()%10>=5)return true;
            else return false;
        }
		else return false;
    }
    else if(personality==2){
        if(getTotalPoint()<19)return true;
		else return false;
    }
    else{
        if(getTotalPoint()<=16)return true;
		else return false;
    }
	return false;
}

/*
int Computer::getTotalClub(Deck &cardDeck){
	for(int i=0;i<getNumHandCard();i++){
		for(int j=0;j<cardDeck.getNumCard();j++){
			if(aDeck[i].getCard()==cardID)
		}
	}
}
*/