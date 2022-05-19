#ifndef COMPUTER_H
#define COMPUTER_H

class Computer:public Player{
	private:
	int personality;

	public:
	Computer();
	void setDealer();
	int getPersonality();
	//about strategy
	virtual int decideBet() override;
	virtual bool decideDraw() override;
};

#endif