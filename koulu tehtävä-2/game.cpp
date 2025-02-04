#include "game.h"

Game::Game(int mn) {

    maxNumber= mn;
    cout << "maxNumber"
         <<maxNumber
         << endl;

}

Game::~Game()
{

}

void Game::play()
{
   cout <<"peli alkaa!!"<<endl;
/*    // jäsenmuuttuja koska pitää
   // välittä arvausten määrrä
   // toiselle jäsem funktiolle


   // kutsutaan toiseta jäsenfunktita
    //joka tekee tulostuksen
   printGameResult();
*/

   srand(time(0));
   randomNumber = (rand() % maxNumber)+1;  //otetaan jakojäännös, nyt pitäisi olla välillä 1-20

   bool stayInLoop = true;
   while(stayInLoop)
   {
       cout<<"Give your guess between 1-"<<maxNumber<<endl;
       cin>>playerGuess;
       numOfGuesses++;
       if(playerGuess == randomNumber)
       {
           cout<<"oiken just nain bro "<<playerGuess<<endl;
           stayInLoop = false;
       }
       else if(playerGuess<randomNumber)
       {
           cout<< "kamaan bro oli aika pieni "<<endl;
       }
       else
       {
           cout<<"omg oli aika suuri"<<endl;
       }

printGameResult();



}
}

void Game::printGameResult()
{
   cout << "Arvaus lukumaara = "
        << numOfGuesses
        << endl;
}
