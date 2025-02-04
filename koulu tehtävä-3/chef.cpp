#include "Chef.h"

// Chef class methods
Chef::Chef(const std::string& name) : name(name) {
    std::cout << "Chef " << name << " created.\n";
}

Chef::~Chef() {
    std::cout << "Chef " << name << " destroyed.\n";
}

int Chef::makeSalad(int ingredients) {
    int servings = ingredients / 5;  // 5 ainesosaa per salatti
    std::cout << "Chef " << name << " made " << servings << " salads.\n";
    return servings;
}

int Chef::makeSoup(int ingredients) {
    int servings = ingredients / 3;  // 3 ainesosa per keitto
    std::cout << "Chef " << name << " made " << servings << " soups.\n";
    return servings;
}

// ItalianChef class
ItalianChef::ItalianChef(const std::string& name) : Chef(name), secretPassword("pizza") {
    std::cout << "Italian Chef " << name << " created.\n";
}

ItalianChef::~ItalianChef() {
    std::cout << "Italian Chef " << name << " destroyed.\n";
}

int ItalianChef::makePizza(int flour, int water) {
    int possibleFlourPizzas = flour / 5;  // 5 jauhoa per pizza
    int possibleWaterPizzas = water / 5;  // 5 vettä per pizza
    int pizzas = std::min(possibleFlourPizzas, possibleWaterPizzas);
    std::cout << "Italian Chef " << name << " made " << pizzas << " pizzas.\n";
    return pizzas;
}

bool ItalianChef::askSecret(const std::string& password, int flour, int water) {
    if (password.empty()) {
        std::cout << "Password cannot be empty!\n";
        return false;
    }

    if (password == secretPassword) {
        std::cout << "Correct password!\n";
        int pizzas = makePizza(flour, water);
        std::cout << "ItalianChef " << name << " with " << flour << " flour and " << water << " water can make " << pizzas << " pizzas.\n";
        return true;
    } else {
        std::cout << "Wrong password!\n";
        return false;
    }
}
