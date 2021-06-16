#ifndef BANCO_H
#define BANCO_H
#include "Cliente.hpp"
#include "Conta.hpp"

  class Banco{
    private: 
      static int numeroAgencias; //mesma coisa que fiz para contas, apenas para deixar o meu código mais generico
      static int balanco; //static para generalizacao (caso tivesse mais de uma agencia do banco,
                          // o balanco geral do banco continua o mesmo so somando o total de varias contas
                          // de todas as agencias, nesse caso eu poderia criar um balanco local porem nao quero 
                          // complicar o codigo por agora)
      int id; 
      std::vector<Cliente*> Clientes;
      std::vector<Conta*> Contas;

    public:
      inline int calculaBalanco();
      inline void setBalanco(int valor);
      inline void adicionaCliente(Cliente* cliente);
      inline void adicionaConta(Conta* conta);
      inline void destructBanco();
      void showClientes();
      void showContas();
      void saldoCliente();
      void saldoConta();
      void showExtratoCliente();
      void showExtratoConta();
      void transferencia();
      void ExtratoClienteStart();

      Banco() : id(Banco::getNumeroAgencias())
      {
      }

      int getNumeroAgencias(){
        return(++ numeroAgencias);
      }
  };

  inline int Banco::calculaBalanco()
  {
    if (this->Contas.empty()) {
      return 0;
    } else {
        int balancolocal=0 , i;

        for (i=0; i < this->Contas.size(); i++) { // Percorre contas para calcular o balanco
          balancolocal = balancolocal + Contas.at(i)->getSaldo();
        }
        return(balancolocal);
    }

  }

  inline void Banco::setBalanco(int valor)
  {
    balanco = balanco + valor;
  }

  inline void Banco::adicionaCliente(Cliente* cliente)
  {
    this->Clientes.push_back(cliente);
  }

  inline void Banco::adicionaConta(Conta* conta)
  {
    this->Contas.push_back(conta);
  }

  inline void Banco::destructBanco(){ // Deleta todos os elementos dos vetores relacionados a banco
    for(int i=0; i < Contas.size(); i++){
      delete(Contas.at(i));
    }

    for(int i=0; i < Clientes.size(); i++){
      delete(Clientes.at(i));
    }
  }
#endif