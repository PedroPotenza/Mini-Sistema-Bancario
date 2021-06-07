#ifndef BANCO_H
#define BANCO_H

  class Banco{
    private: 
      static int numeroAgencias; //mesma coisa que fiz para contas, apenas para deixar o meu código mais generico
      static int balanco; //static para generalizacao (caso tivesse mais de uma agencia do banco,
                          // o balanco geral do banco continua o mesmo so somando o total de varias contas
                          // de todas as agencias, nesse caso eu poderia criar um balanco local porem nao quero 
                          // complicar o codigo por agora)
      int id;

    public:
      std::vector<Cliente*> Clientes;
      std::vector<Conta*> Contas;

      inline int getBalanco() const;
      inline void setBalanco(int valor);

      Banco() : id(Banco::getNumeroAgencias())
      {

      }

      int getNumeroAgencias(){
        return(++ numeroAgencias);
      }

      void showClientes(){
		int i;
		for(i=0; i < Clientes.size(); i++){
			std::cout << "-------Cliente "<< i + 1 << "--------\n" << std::endl;
			std::cout << "Nome do cliente: " << Clientes.at(i)->getNome() << std::endl;
			std::cout << "CPF do cliente: " << Clientes.at(i)->getCpf() << "\n"<<  std::endl;
		}
      }

      void showContas(){
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

          std::cout << "CPF do Cliente desejado: " ;
          std::cin >> cpflocal;

          for(i=0; i < Contas.size(); i++){
              if(cpflocal == Contas.at(i)->getCpf()){
                  saldolocal = saldolocal + Contas.at(i)->getSaldo();
              }
          }

          std::cout << "Saldo do cliente: " << saldolocal << std::endl;
      }

      void showExtrato(){
          int i, idlocal, j;

          std::cout << "Id da conta: ";
          std::cin >> idlocal;

          for(i=0; i < Contas.size();i++){
              if(idlocal == Contas.at(i)->getId()){
                  for(j=0; j < Contas.at(i)->getTamExtrato(); j++){
                      std::cout << Contas.at(i)->getExtrato(j) << std::endl;
                  }
              }
          }
      }

      void transferencia(){

          int idpaga, idrecebe, valorpago, i;

          std::cout << "Id da conta que envia: " ;
          std::cin >> idpaga;
          std::cout << "Valor que deseja transferir: " ; //lembrando de não utilizar virgula
          std::cin >> valorpago;
          std::cout << "Id da conta de quem recebe: " ;
          std::cin >> idrecebe;

          //fazer o tratamento de erro:
          //--> se informado um valor alem do q tem na conta
          //--> informou id inexistente
          //--> verificar o balanco

          for(i=0; i < Contas.size();i++){
              if(idpaga == Contas.at(i)->getId()){
                  Contas.at(i)->setSaldo(Contas.at(i)->getSaldo()-valorpago);
                  Contas.at(i)->setExtrato(-valorpago);
              }
              if(idrecebe == Contas.at(i)->getId()){
                  Contas.at(i)->setSaldo(Contas.at(i)->getSaldo()+valorpago);
                  Contas.at(i)->setExtrato(+valorpago);
              }
          }
      }

  };

  inline int Banco::getBalanco() const
  {
    return(this->balanco);
  }

  inline void Banco::setBalanco(int valor)
  {
    balanco = balanco + valor;
  }

#endif
