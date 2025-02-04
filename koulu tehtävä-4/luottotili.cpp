#include "Luottotili.h"

Luottotili::Luottotili(std::string omistajaNimi, double raja)
    : Pankkitili(omistajaNimi) {
    luottoRaja = raja;
}

bool Luottotili::deposit(double maara) {
    if (maara> 0) {
        saldo = saldo + maara;
        return true;
    }
    return false;
}

bool Luottotili::withdraw(double maara) {
    if (maara > 0 && saldo - maara>= -luottoRaja) {
        saldo = saldo - maara;
        return true;
    }
    return false;
}
