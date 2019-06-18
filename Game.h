/* Yakir Amar 204590095 */
using namespace std;
#ifndef GAME_H
#define GAME_H
#include "Player.h"
#include "Card.h"
#include <vector>
class Game {
private:
	//private members and functions
	int num_of_palyer;//number of players
	int how_many_cards;//number of cards
	vector<Player> players;//the list of the players
public:
	//public members and functions
	void start();
	int whose_turn_now(const Card card);//This function returns the number of steps to move forward or change direction
};
#endif




