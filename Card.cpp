#include"Card.h"

Card::Card(){
	value=0;
	cardID=0;
	suit=0;
}

int Card::getCard(){
	return cardID;
}

int Card::getValue(){
    return value;
}

int Card::getSuit(){
	return suit;
}

void Card::setCard(int newID){
	if(newID>=0 && newID<52){
		cardID=newID;
		value=cardID%13;
		suit=cardID/13;
	}
	else{
		value=0;
		cardID=0;
		suit=0;
	}
}

void Card::displayCard(){
	string suit[]={"Spade","Heart","Diamond","Club"};
	string value[]={"Ace","2","3","4","5","6","7","8","9","10","Jack","Queen","King"};

	cout << "[" << value[this->value] << "," << suit[this->suit] << "]";
}
