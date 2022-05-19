#include"Card.h"
#include"Deck.h"
#include"Player.h"
#include"Human.h"
#include"Computer.h"

int main(){
	srand(time(NULL));
	Human human;
	//set player
	int num_players;
	cout << "How many players :";
	cin >> num_players;
	Computer players[num_players];
	players[num_players-1].setDealer();
	for(int i=0;i<num_players;i++)
		cout << players[i].getName() << "(" << players[i].getPersonality() << ")" << "--" << players[i].getBankroll() << endl;
	//set Desk
    Deck cardDeck(num_players);
    cardDeck.shuffleDeck();

	while(1){
		cout << "Okay,time for betting!" << endl;
		cout << "----------------------" << endl;
		cout << human.getName() << ",how much would you like to bet?";
		human.decideBet();
		cout << human.getName() << " bets $" << human.getBet() << endl;
		for(int i=0;i<num_players;i++){
			players[i].decideBet();
			cout << players[i].getName() << " bets $" << players[i].getBet() << endl;
		}
		cout << endl;
		
		//deal card
		cout << "The initial starting cards are:" << endl;
        cout << "-------------------------------" << endl;
		
		for(int j=0;j<2;j++)human.setHandCard(cardDeck.dealCard());
		cout << human.getName() << "'s current hand:";
		cardDeck.displayCard(human.getHandCard(0));
		cardDeck.displayCard(human.getHandCard(1));
		cout << endl;
		for(int i=0;i<num_players;i++){
			for(int j=0;j<2;j++)players[i].setHandCard(cardDeck.dealCard());
			cout << players[i].getName() << "'s current hand:[??]";
			cardDeck.displayCard(players[i].getHandCard(1));
			cout << endl;
		}
		cout << endl;
		
		//Human's turn
		cout << human.getName() << "'s turn:" << endl;
		cout << "----------------------" << endl;
		while(1){
			cout << human.getName() << "'s current hand:";
			for(int j=0;j<human.getNumHandCard();j++)cardDeck.displayCard(human.getHandCard(j));
			human.computeTotalPoint(cardDeck);
			cout << "(" << human.getTotalPoint() << " points)" <<endl;

			if(human.decideDraw()){
				cout << human.getName() << " chooses to draw." << endl;
				human.setHandCard(cardDeck.dealCard());
				human.computeTotalPoint(cardDeck);
				if(human.getTotalPoint()>21){
					cout << human.getName() << " busted at " << human.getTotalPoint() << endl;
					for(int j=0;j<human.getNumHandCard();j++)cardDeck.displayCard(human.getHandCard(j));
					cout << endl;
					cout << endl;
					break;
				}
			}
			else{
				cout << human.getName() << " chooses to stay." << endl;
				cout << endl;
				break;
			}			
		}
		
		//Computer's turn
		for(int i=0;i<num_players;i++){
			cout << players[i].getName() << "'s turn:" << endl;
			cout << "----------------------" << endl;
			while(1){
				cout << players[i].getName() << "'s current hand:";
				for(int j=0;j<players[i].getNumHandCard();j++)cardDeck.displayCard(players[i].getHandCard(j));
				players[i].computeTotalPoint(cardDeck);
				cout << "(" << players[i].getTotalPoint() << ")" <<endl;

				if(players[i].decideDraw()){
					cout << players[i].getName() << " chooses to draw." << endl;
					players[i].setHandCard(cardDeck.dealCard());
					players[i].computeTotalPoint(cardDeck);
					if(players[i].getTotalPoint()>21){
						cout << players[i].getName() << " busted at " << players[i].getTotalPoint() << endl;
						for(int j=0;j<players[i].getNumHandCard();j++)
							cardDeck.displayCard(players[i].getHandCard(j));
						cout << endl;
						cout << endl;
						break;
					}
				}
				else{
					cout << players[i].getName() << " chooses to stay." << endl;
					cout << endl;
					break;
				}
			}
		}

		//Settlement
		cout << "Let's see how it turned out:" << endl;
        cout << "----------------------------" << endl;
		int Dealer_sum=0;
		Dealer_sum+=human.judge(players[num_players-1].getTotalPoint());
		for(int i=0;i<num_players-1;i++)Dealer_sum+=players[i].judge(players[num_players-1].getTotalPoint());
		Dealer_sum+=players[num_players-1].getBankroll();
		players[num_players-1].setBankroll(Dealer_sum);
		cout << endl;

		//Show last money
		cout << "The standings so far:" << endl;
        cout << "---------------------" << endl;
		cout << human.getName() << " $" << human.getBankroll() << endl;
		for(int i=0;i<num_players;i++)cout << players[i].getName() << " $" << players[i].getBankroll() << endl;
		cout << endl;
		
		string answer;
		while(1){
			cout << "Another round?(Y op N):";
			cin >> answer;
			if(answer!="N" && answer!="Y")cout << "invalid input!" << endl;
			else if(answer=="N")return 0;
			else{
				human.resetHandCard();
				for(int i=0;i<num_players;i++)players[i].resetHandCard();
				break;				
			}
		}
	}
	return 0;
}
