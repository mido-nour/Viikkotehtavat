#ifndef PANKKITILI_H
#define PANKKITILI_H

#include <string>

class Pankkitili {
protected:
    std::string omistaja;
    double saldo;

public:
    Pankkitili(std::string omistajaNimi);
    virtual bool deposit(double maara);
    virtual bool withdraw(double maara);
    double getBalance() const;
};

#endif // PANKKITILI_H
