#ifndef LUOTTOTILI_H
#define LUOTTOTILI_H

#include "Pankitiili.h"

class Luottotili : public Pankkitili {
private:
    double luottoRaja;

public:
    Luottotili(std::string omistajaNimi, double raja);
    bool deposit(double maara) override;
    bool withdraw(double maara) override;
};

#endif
