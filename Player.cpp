/* Yakir Amar 204590095 */
using namespace std;
#include<string>
#include "Player.h"


// public:

    Player::Player(){
        name="yakir";
        num_of_cards=7;
        int i;
        for(i=0;i<num_of_cards;i++){
            Card card=Card::generate_card();
            my_cards.push_back(card);
        }
    
    }
    Player::Player(string name2, int num_of_cards2){
        name=name2;
        num_of_cards=num_of_cards2;
        int i;
        for(i=0;i<num_of_cards;i++){
            Card card=Card::generate_card();
            my_cards.push_back(card);
        }
    }
    
    //copy constructor
    Player::Player(const Player& player){
        name=player.name;
        num_of_cards=player.num_of_cards;
        int i;
        for(i=0;i<player.my_cards.size();i++){
            Card card=player.my_cards[i];
            my_cards.push_back(card);
        }
    }
    
    //operator =
    Player& Player::operator=(const Player& player){
        if(this==&player){ return *this;}
        my_cards.erase(my_cards.begin(), my_cards.end());
        int i;
        for(i=0;i<player.my_cards.size();i++){
           my_cards.push_back(player.my_cards[i]);   
        }
        name=player.name;
        num_of_cards=player.num_of_cards;
    }
    
    
    //check if there is a wiiner
    bool Player::check_win(){
        if(my_cards.empty())
        {
          cout<<name<<" wins!"<<endl;
          return true;
        }
        else{
          return false;
        }
    }
    
    
    //play function Performs the player action
    bool Player::play(Card &cur_card){
        int j;
        for(j=1;j<=my_cards.size();j++){//output all the cards
            cout<<" ("<<j<<")"<<my_cards[j-1];
        }
        cout<<endl;
        int index_of_card;
        bool player_not_finish=true,check_card;
        while(player_not_finish){
            cin>>index_of_card;//get the index of the card that the player want to use
            if((index_of_card<=0)||(index_of_card>my_cards.size()))//if the index is't legal the player take one more card
            { 
              Card take_card=Card::generate_card();
              my_cards.push_back(take_card);
              return false;
            }
             
            Card card_in;
            card_in=my_cards[index_of_card-1];//card_in get the card of the index
            check_card=card_in.is_legal(cur_card);//
            if(check_card)//if it's a ligle card
            {
              cur_card=card_in;//switch card
              my_cards.erase(my_cards.begin()+index_of_card-1);
              return true;
              int j;
              for(j=1;j<=my_cards.size();j++){//output all the cards
                 cout<<" ("<<j<<")"<<my_cards[j-1];
              }
              cout<<endl;
                       
            }
                 
            else{
              cout<< "You can't put "<<card_in<<" on "<<cur_card<<endl;
            }
        }
            
    }

