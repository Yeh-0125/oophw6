#ifndef PLAYER_H
#define PLAYER_H

#include"card.h"
#include"deck.h"
#include<vector>

class Player{
	private:
	//about player infomation
	string name;
	int bankroll;
	int bet;
	int round_win;
	virtual int decideBet()=0;
	virtual bool decideDraw()=0;
	
	//about hand card
	int totalPoint;
	int handCard[7];
	int num_handCard;

	public:
	Player();
	string getName();
	int getBet();
	void setBet(int);
	int getBankroll();
    void setBankroll(int);
	void setName(string);
	int getRoundWin();

	//about hand card
	int getHandCard(int);
	void setHandCard(int);
	void resetHandCard();
	int getNumHandCard();
	void computeTotalPoint(Deck &cardDeck);
	int getTotalPoint();

	int judge(int);
};

#endif
