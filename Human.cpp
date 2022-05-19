#include"Player.h"
#include"Human.h"

Human::Human(){
	string name;
	cout << "what is your name?";
	cin >> name;
	setName(name);

	int bankroll;
	cout << "How much your bankroll?";
	cin >> bankroll;
	setBankroll(bankroll);
}

int Human::decideBet(){
	int bet=0;
	cin >> bet;
	setBet(bet);
	return bet;
}

bool Human::decideDraw(){
	string answer;
	while(1){
		cout << "Would you like to draw another casr(Y OR N):";
		cin >> answer;
		if(answer=="N" || answer=="Y")break;
		else cout << "invalid input!" << endl;
	}
	if(answer=="N")return false;
	else return true;
}