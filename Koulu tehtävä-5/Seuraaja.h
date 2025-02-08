#ifndef SEURAAJA_H
#define SEURAAJA_H

#include <iostream>
#include <string>

class Seuraaja {
public:
    Seuraaja* next;
    std::string nimi;

    Seuraaja(std::string n);
    void paivitys(const std::string& viesti);
    std::string getNimi();
};

#endif // SEURAAJA_H
