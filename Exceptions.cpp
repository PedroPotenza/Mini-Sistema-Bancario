#include <iostream>
#include <exception>

using namespace std;

class userNotFOundException: public exception { // Excecao utilizada para usuarios nao encontrados
    virtual const char* what() const throw() {
        return "Usuario nao encontrado.";
    }
};

class accountNotFOundException: public exception { // Excecao utilizada para contas nao encontradas
    virtual const char* what() const throw() {
        return "Conta nao encontrada.";
    }
};

class wrongBalanceException: public exception { // Excecao utilizada para Balanco final adulterado em transferencias
    virtual const char* what() const throw() {
        return "O Balanco total do banco foi adulterado.";
    }
};

class lowBalanceException: public exception { // Excecao utilizada para usuarios que tentam transferir mais dinheiro que o seu saldo
    virtual const char* what() const throw() {
        return "O saldo do cliente e menor que o valor informado.";
    }
};