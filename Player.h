/* Yakir Amar 204590095 */
using namespace std;
#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <vector>
#include "Card.h"


class Player {
private:
	int num_of_cards; // num_of_cards;
	vector<Card> my_cards; // container of cards
	
	// more private members

public:
    string name; // name;
    Player();//defalut constractor
    Player(string name, int num_of_cards);//constructor that get name and number of cards
    Player(const Player& player);//copy constructor
    Player& operator=(const Player& player);//= operator
    bool check_win();//check if there is a player that win 
    bool play(Card &cur_card);//return true if the player play and false if he take another card
    
    
    

};
#endif



