#include <iostream>
#include <string>
#include "asiakas.h"

const std::string SALASANA = "pankki020";

void tulostaMenu() {
    std::cout << "\nA. Luo asiakas\n";
    std::cout << "B. Tallenna rahaa\n";
    std::cout << "C. Nosta rahaa\n";
    std::cout << "D. Nayta saldo\n";
    std::cout << "E. Nosta luottoa\n";
    std::cout << "F. Maksa luottoa\n";
    std::cout << "G. Siirra rahaa toiselle asiakkaalle\n";
    std::cout << "H. Lopeta\n";
    std::cout << "Valitse toiminto: ";
}

bool tarkistaSalasana() {
    std::string kayttajanSalasana;
    std::cout << "Anna salasana: ";
    std::cin >> kayttajanSalasana;
    return (kayttajanSalasana == SALASANA);
}

int main() {
    double maara, luottoraja;
    int valinta;
    Asiakas* asiakas1 = nullptr;
    Asiakas* asiakas2 = nullptr;

    std::cout << "Tervetuloa pankkiohjelmaan!\n";

    do {
        tulostaMenu();
        std::cin >> valinta;

        switch (valinta) {
        case 1: {
            if (asiakas1 == nullptr) {
                std::string nimi;
                std::cout << "Anna asiakkaan nimi: ";
                std::cin >> nimi;
                std::cout << "Anna luottoraja: ";
                std::cin >> luottoraja;
                asiakas1 = new Asiakas(nimi, luottoraja);
                std::cout << "Asiakas " << nimi << " luotu!\n";
            } else if (asiakas2 == nullptr) {
                std::string nimi;
                std::cout << "Anna toisen asiakkaan nimi: ";
                std::cin >> nimi;
                std::cout << "Anna luottoraja: ";
                std::cin >> luottoraja;
                asiakas2 = new Asiakas(nimi, luottoraja);
                std::cout << "Asiakas " << nimi << " luotu!\n";
            } else {
                std::cout << "Et voi luoda enempaa asiakkaita!\n";
            }
            break;
        }
        case 2: {
            if (asiakas1 == nullptr) {
                std::cout << "Luo ensin asiakas!\n";
                break;
            }
            if (!tarkistaSalasana()) {
                std::cout << "Virheellinen salasana!\n";
                break;
            }
            std::cout << "Anna talletettava summa: ";
            std::cin >> maara;
            if (asiakas1->talletus(maara)) {
                std::cout << "Talletus onnistui!\n";
            } else {
                std::cout << "Talletus epaonnistui!\n";
            }
            break;
        }
        case 3: {
            if (asiakas1 == nullptr) {
                std::cout << "Luo ensin asiakas!\n";
                break;
            }
            if (!tarkistaSalasana()) {
                std::cout << "Virheellinen salasana!\n";
                break;
            }
            std::cout << "Anna nostettava summa: ";
            std::cin >> maara;
            if (asiakas1->nosto(maara)) {
                std::cout << "Nosto onnistui!\n";
            } else {
                std::cout << "Nosto epaonnistui!\n";
            }
            break;
        }
        case 4: {
            if (asiakas1 == nullptr) {
                std::cout << "Luo ensin asiakas!\n";
                break;
            }
            if (!tarkistaSalasana()) {
                std::cout << "Virheellinen salasana!\n";
                break;
            }
            asiakas1->naytaSaldo();
            break;
        }
        case 5: {
            if (asiakas1 == nullptr) {
                std::cout << "Luo ensin asiakas!\n";
                break;
            }
            if (!tarkistaSalasana()) {
                std::cout << "Virheellinen salasana!\n";
                break;
            }
            std::cout << "Anna nostettava luotto: ";
            std::cin >> maara;
            if (asiakas1->luotonNosto(maara)) {
                std::cout << "Luoton nosto onnistui!\n";
            } else {
                std::cout << "Luoton nosto epaonnistui!\n";
            }
            break;
        }
        case 6: {
            if (asiakas1 == nullptr) {
                std::cout << "Luo ensin asiakas!\n";
                break;
            }
            if (!tarkistaSalasana()) {
                std::cout << "Virheellinen salasana!\n";
                break;
            }
            std::cout << "Anna maksettava summa: ";
            std::cin >> maara;
            if (asiakas1->luotonMaksu(maara)) {
                std::cout << "Luoton maksu onnistui!\n";
            } else {
                std::cout << "Luoton maksu epaonnistui!\n";
            }
            break;
        }
        case 7: {
            if (asiakas1 == nullptr || asiakas2 == nullptr) {
                std::cout << "Luo ensin kaksi asiakasta!\n";
                break;
            }
            if (!tarkistaSalasana()) {
                std::cout << "Virheellinen salasana!\n";
                break;
            }
            std::cout << "Anna siirrettava summa: ";
            std::cin >> maara;
            if (asiakas1->tiliSiirto(maara, *asiakas2)) {
                std::cout << "Tilisiirto onnistui!\n";
            } else {
                std::cout << "Tilisiirto epaonnistui!\n";
            }
            break;
        }
        }
    } while (valinta != 0);

    delete asiakas1;
    delete asiakas2;
    return 0;
}
