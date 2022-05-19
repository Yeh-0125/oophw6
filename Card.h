#ifndef CARD_H
#define CARD_H

#include<iostream>
#include<cstdlib>
#include<string>
#include <ctime>
using namespace std;

class Card{
	private:
	int value;
	int cardID;
	int suit;

	public:
	Card();
	int getCard();
	int getValue();
	int getSuit();
	void setCard(int);
	void displayCard();
};
#endif
