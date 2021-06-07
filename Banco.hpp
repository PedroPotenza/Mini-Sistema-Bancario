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
