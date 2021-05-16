#ifndef CONTA_HPP
#define CONTA_HPP

#include "Cliente.hpp"
	
	class Conta : public Cliente
	{
		private: 
			static int numeroContas;
			int id;
			int	saldo;
		public:
			inline int getSaldo() const;
			inline void setSaldo(int x);
			inline int getId() const;

			Conta(std::string nome, int cpf) :
				Cliente(nome,cpf),id(Conta::getNumeroContas()), saldo(1000){
				}

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
