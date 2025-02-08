#include "Seuraaja.h"

Seuraaja::Seuraaja(std::string n) : nimi(n), next(nullptr) {}

void Seuraaja::paivitys(const std::string& viesti) {
    std::cout << nimi << " sai viestin: " << viesti << std::endl;
}

std::string Seuraaja::getNimi() {
    return nimi;
}
