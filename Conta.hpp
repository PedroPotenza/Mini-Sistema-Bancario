#ifndef CONTA_HPP
#define CONTA_HPP

#include "Cliente.hpp"
#include "Banco.hpp"
	
	class Conta : public Cliente
	{
		private: 
			static int numeroContas;
			int id;
			int	saldo;
			//poderia implementar tambem um int id_agencia para  saber a qual agencia essa conta pertence, 
			//mas n vou adicionar para n complicar
		public:
			inline int getSaldo() const;
			inline void setSaldo(int x);
			inline int getId() const;

			Conta(std::string nome, int cpf, Banco& agencia) :
				Cliente(nome,cpf),id(Conta::getNumeroContas()), saldo(1000)
				{
					agencia.setBalanco(saldo);
					//poderia aproveitar aqui e passar o id_agencia do objeto agencia
				}
			
		/*	Conta(Cliente& cliente, Banco& agencia) :
				id(Conta::getNumeroContas()), saldo(1000){ //erro nessa chave ("não existe construtor padrão para a classe Cliente")
					this->setNome(cliente.getNome());
					this->setCpf(cliente.getCpf());
					agencia.setBalanco(saldo);
				} */

			int getNumeroContas(){
				return(++ numeroContas);
			}
	};
		
	inline int Conta::getSaldo() const
	{
		return (this->saldo);	
	} 

	inline void Conta::setSaldo(int x)
	{
		saldo = x;
	}

	inline int Conta::getId() const
	{
		return (this->id);
	}

#endif
