#ifndef DECK_H
#define DECK_H

#include"Card.h"
using namespace std;

class Deck{
	friend ostream& operator << (ostream&,const Card&);
	
	private:
	Card *aDeck;
	int decktop;
	int num_deck;
	int num_card;

	public:
	Deck(int);
	void shuffleDeck();
	void displayDeck();
	void displayCard(int);
	int dealCard();
	void swapCard(int,int);
	int getCardValue(int);
	int getNumCard();
};
#endif
