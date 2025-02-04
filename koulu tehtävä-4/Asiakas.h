#ifndef ASIAKAS_H
#define ASIAKAS_H

#include <string>

class Asiakas {
private:
    std::string nimi;
    double saldo;
    double luottoraja;

public:
    Asiakas(const std::string& nimi, double luottoraja);
    bool talletus(double maara);
    bool nosto(double maara);
    bool luotonNosto(double maara);
    bool luotonMaksu(double maara);
    bool tiliSiirto(double maara, Asiakas& kohde);
    void naytaSaldo() const;
    std::string getNimi() const;

};

#endif
