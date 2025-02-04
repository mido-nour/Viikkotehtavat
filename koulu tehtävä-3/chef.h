#ifndef CHEF_H
#define CHEF_H
#include <iostream>

class Chef {
protected:
    std::string name;

public:
    Chef(const std::string& name);
    virtual ~Chef();

    virtual int makeSalad(int ingredients);
    virtual int makeSoup(int ingredients);
};

class ItalianChef : public Chef {
private:
    std::string secretPassword;
    int makePizza(int flour, int water);

public:
    ItalianChef(const std::string& name);
    ~ItalianChef();

    bool askSecret(const std::string& password, int flour, int water);
};

#endif

