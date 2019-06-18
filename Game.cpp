/* Yakir Amar 204590095 */
using namespace std;
#include "Game.h"
#include "Player.h"



//Whose_turn_now returns the number of steps to move forward or change direction
    int Game::whose_turn_now(const Card card){
        switch (card.get_sign()){
        case sign::PLUS: return 0;
        case sign::STOP: return 2;
        case sign::TAKI: return 1;
        case sign::CD: return -1;//we want special number to know if we need to change direction
        }
        return 1;//If none of the special cards
        
    }

    

    void Game:: start(){
        int i,j,steps=1,mod,change_direction=1,help_turn=0;
        bool win=false,the_player_play;
        cout<<"How many players?"<<endl;
        cin>>num_of_palyer;
        if(num_of_palyer<0)
        {
          cout<<"eror, You can not insert a negative number" <<endl;
          win=true;
        }
        if(win==false)
        {
          cout<<"How many cards?"<<endl;
          cin>>how_many_cards;
          if(how_many_cards<0)
         {
           cout<<"eror, You can not insert a negative number" <<endl;
           win=false;
         }
        }
        mod=num_of_palyer;
        for(i=1;i<=num_of_palyer;i++){//get the names of all the players and build vector of them.
           string name;
           cout<< "player number "<<i<< " name?"<<endl;
           cin>>name;
           Player player(name, how_many_cards);
           players.push_back(player);
        }
      
       //Displays a random card 
        Card cur_card=Card::generate_card();
        vector<Player>::iterator turn = players.begin();//turn getting the first member on the list
        while(win==false){
             cout<<"current: "<<cur_card<<endl;
             cout<<turn->name<<","<<" your turn -"<<endl;
             cout<<"Your cards:";
             the_player_play=turn->play(cur_card);//check if the player play or take another card
             win=turn->check_win();
             if(the_player_play){ steps=whose_turn_now(cur_card);}
             else{steps=1;}
             if(steps==-1)
             {
               if(change_direction==mod-1)
               {
                 change_direction=1;
                 steps=1;
               }
               else{
                change_direction=mod-1;
                steps=1;
               }
              }
             help_turn=(help_turn+(steps*change_direction))%mod;//here we calculate a few steps from the beginning and go to get to the player whose turn is now
             turn = players.begin();
             for(j=0;j<help_turn;j++){//here we go as far as necessary
                turn++;
             }
        }
    }