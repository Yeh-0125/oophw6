#ifndef HUMAN_H
#define HUMAN_H

class Human:public Player{
	public:
	Human();
	virtual int decideBet() override;
	virtual bool decideDraw() override;
};

#endif