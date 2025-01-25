#include "Chef.h"
#include <iostream>


int main() {
    // italianchef-olio
    ItalianChef italianChef("mohammed");

    // kysy käytäjä salasana
    std::string userPassword;
    std::cout << "Enter the password to make pizza: ";
    std::cin >> userPassword;

    // hyväksytään kytäjän salasana
    bool passwordCorrect = italianChef.askSecret(userPassword, 12, 12);

    return 0;
}
