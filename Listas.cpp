#include <vector>   
#include <iostream> 
#include "Cliente.hpp"
#include "Conta.hpp"


std::vector<Cliente*> Clientes;

void imprimirClientes(){
    int i;
    for(i=0; i < Clientes.size(); i++){
        std::cout << "-------Cliente "<< i + 1 << "--------\n" << std::endl;
        std::cout << "Nome do cliente: " << Clientes.at(i)->getNome() << std::endl;
        std::cout << "CPF do cliente: " << Clientes.at(i)->getCpf() << "\n"<<  std::endl;
    }
}

std::vector<Conta*> Contas;

void imprimirContas(){
    int i;
    for(i=0; i < Contas.size(); i++){
        std::cout << "-------Conta "<< Contas.at(i)->getId() << "--------\n" << std::endl;
        std::cout << "Nome do Titular da Conta: " << Contas.at(i)->getNome() << std::endl;
        std::cout << "CPF do Titular da Conta: " << Contas.at(i)->getCpf() << "\n"<<  std::endl;
        std::cout << "Saldo da Conta: " << Contas.at(i)->getSaldo() / 100 << "\n"<<  std::endl;
    }
}

void saldoCliente(){
    int cpflocal, saldolocal(0), i;

    std::cout << "CPF do Cliente desejado: " << std::endl;
    std::cin >> cpflocal;

    for(i=0; i < Contas.size(); i++){
        if(cpflocal == Contas.at(i)->getCpf()){
            saldolocal = saldolocal + Contas.at(i)->getSaldo();
        }
    }

    std::cout << "Saldo do cliente: " << saldolocal << std::endl;
}