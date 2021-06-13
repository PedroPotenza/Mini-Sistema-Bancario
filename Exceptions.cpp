#include <iostream>
#include <exception>

using namespace std;
class userNotFOundException: public exception {
    virtual const char* what() const throw() {
        return "Usuário não encontrado.";
    }
};

class wrongBalanceException: public exception {
    virtual const char* what() const throw() {
        return "O Balanco total do banco foi adulterado.";
    }
};

class lowBalanceException: public exception {
    virtual const char* what() const throw() {
        return "O saldo do cliente é menor que o valor informado.";
    }
};