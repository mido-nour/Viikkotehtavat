#include "Pankitiili.h"

Pankkitili::Pankkitili(std::string omistajaNimi) {
    omistaja = omistajaNimi;
    saldo = 0;
}

bool Pankkitili::deposit(double sum) {
    if (sum> 0) {
        saldo = saldo + sum;
        return true;
    }
    return false;
}

bool Pankkitili::withdraw(double maara) {
    if (maara > 0 && saldo >= maara) {
        saldo = saldo - maara;
        return true;
    }
    return false;
}

double Pankkitili::getBalance() const {
    return saldo;
}
