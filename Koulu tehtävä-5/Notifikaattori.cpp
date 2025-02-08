#include "Notifikaattori.h"

Notifikaattori::Notifikaattori() : seuraajat(nullptr) {}

void Notifikaattori::lisaa(Seuraaja* uusi) {
    uusi->next = seuraajat;
    seuraajat = uusi;
}

void Notifikaattori::poista(const std::string& nimi) {
    Seuraaja* nykyinen = seuraajat;
    Seuraaja* edellinen = nullptr;

    while (nykyinen != nullptr) {
        if (nykyinen->getNimi() == nimi) {
            if (edellinen == nullptr) {
                seuraajat = nykyinen->next;
            } else {
                edellinen->next = nykyinen->next;
            }
            delete nykyinen;
            return;
        }
        edellinen = nykyinen;
        nykyinen = nykyinen->next;
    }
}

void Notifikaattori::tulosta() {
    Seuraaja* nykyinen = seuraajat;
    while (nykyinen != nullptr) {
        std::cout << nykyinen->getNimi() << std::endl;
        nykyinen = nykyinen->next;
    }
}

void Notifikaattori::postita(const std::string& viesti) {
    Seuraaja* nykyinen = seuraajat;
    while (nykyinen != nullptr) {
        nykyinen->paivitys(viesti);
        nykyinen = nykyinen->next;
    }
}
