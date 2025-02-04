#include "asiakas.h"
#include <iostream>

Asiakas::Asiakas(const std::string& nimi, double luottoraja)
    : nimi(nimi), saldo(0), luottoraja(luottoraja) {}

bool Asiakas::talletus(double maara) {
    if (maara > 0) {
        saldo += maara;
        return true;
    }
    return false;
}

bool Asiakas::nosto(double maara) {
    if (maara > 0 && saldo >= maara) {
        saldo -= maara;
        return true;
    }
    return false;
}

bool Asiakas::luotonNosto(double maara) {
    if (maara > 0 && (saldo + luottoraja) >= maara) {
        saldo -= maara;
        return true;
    }
    return false;
}

bool Asiakas::luotonMaksu(double maara) {
    if (maara > 0 && saldo <= 0) {
        saldo += maara;
        return true;
    }
    return false;
}

bool Asiakas::tiliSiirto(double maara, Asiakas& kohde) {
    if (maara > 0 && saldo >= maara) {
        saldo -= maara;
        kohde.talletus(maara);
        return true;
    }
    return false;
}

void Asiakas::naytaSaldo() const {
    std::cout << "Asiakkaan " << nimi << " saldo: " << saldo << std::endl;
}

std::string Asiakas::getNimi() const {
    return nimi;
}




