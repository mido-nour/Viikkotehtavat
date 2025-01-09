#include <iostream>


using namespace std;


int game (int maxnum );  //se funktio joka kokko koodi on silela


int main()
{

    // arvauksen nimi ja lähte nollasta
    int arvausten_lukumara=0;

    // arvaukset maximi on

      int maxnum=0;

    cout<< "Anna arvon  numeron maksimi:";
      cin>>maxnum;

    // gmae funktio anta arvausten_lukumara  että montako kerta se arvautukset ja se talenta sinne sit tuosta.

      arvausten_lukumara = game(maxnum);


    // tulosta montako arvaukset on kokeltu.
       cout<< "arvaukset: "<< arvausten_lukumara<< endl;



    return 0;
}

int game (int maxnum){
    int arvausten_lukumara=0;

    // asenetaan muutujat
    int satunnaisluku;
    int arvaus=0;

    // se tulosta montako kerta on mahdolista arvata.
    cout << "Maxnum=" << maxnum<<endl;


  //  satunnaisluku = 21;  //  se luku joka täyty arvata


    //  se muoka koko ajan se satunnaisluku.
    srand(time(NULL));
     satunnaisluku = rand() % maxnum+1;


     // käytin while että aina jos on väärin niin sinne toista.
    while (arvaus != satunnaisluku) {
        cout <<"Anna luku? " <<endl;

        cin >> arvaus;
        arvausten_lukumara++;


        // aloitetaan vertailumista peni tai suurempi taoi oiken
        if (arvaus == satunnaisluku){
            cout<< "oikein!"  << endl;}


        if (arvaus < satunnaisluku){
            cout<< "pienempi kun satunnaisluku!"  << endl <<endl;}


        if (arvaus > satunnaisluku){
            cout<< "suurempi kun satunnaisluku!"  <<endl << endl;}

    }


    return arvausten_lukumara;
}
