#include <iostream>
#include "game.h"
using namespace std;

int main()
{
    int maxluku = 0;
    cout << "no annapa nyt se maxnumero katotaan voitatko ekalta kerta;)"
         << endl;
    cin >> maxluku;

    Game peliolio(maxluku);

    peliolio.play();


       return 0;
}
