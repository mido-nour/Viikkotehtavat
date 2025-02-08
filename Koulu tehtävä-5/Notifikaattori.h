#ifndef NOTIFIKAATTORI_H
#define NOTIFIKAATTORI_H

#include "Seuraaja.h"

class Notifikaattori {
public:
    Seuraaja* seuraajat;

    Notifikaattori();
    void lisaa(Seuraaja* uusi);
    void poista(const std::string& nimi);
    void tulosta();
    void postita(const std::string& viesti);
};

#endif // NOTIFIKAATTORI_H
