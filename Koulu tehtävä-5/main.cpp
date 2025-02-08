#include "Notifikaattori.h"
#include <iostream>
#include <string>

int main() {
    Notifikaattori notifikaattori;

    std::string nimi1, nimi2, nimi3;


    std::cout << "Anna ensimmainen seuraajan nimi: ";
    std::getline(std::cin, nimi1);

    std::cout << "Anna toinen seuraajan nimi: ";
    std::getline(std::cin, nimi2);

    std::cout << "Anna kolmas seuraajan nimi: ";
    std::getline(std::cin, nimi3);


    Seuraaja* seuraaja1 = new Seuraaja(nimi1);
    Seuraaja* seuraaja2 = new Seuraaja(nimi2);
    Seuraaja* seuraaja3 = new Seuraaja(nimi3);


    notifikaattori.lisaa(seuraaja1);
    notifikaattori.lisaa(seuraaja2);
    notifikaattori.lisaa(seuraaja3);


    std::cout << "\nSeuraajat:" << std::endl;
    notifikaattori.tulosta();


    std::cout << "\nPostitetaan viesti:" << std::endl;
    notifikaattori.postita("Tervehdys kaikille!");


    std::string poistettavaNimi;
    std::cout << "\nAnna poistettavan seuraajan nimi: ";
    std::getline(std::cin, poistettavaNimi);


    notifikaattori.poista(poistettavaNimi);


    std::cout << "\nSeuraajat poiston jalkeen:" << std::endl;
    notifikaattori.tulosta();

    std::cout << "\nPostitetaan toinen viesti:" << std::endl;
    notifikaattori.postita("kiitos teille!");



    return 0;
}
