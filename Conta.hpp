#ifndef CONTA_HPP
#define CONTA_HPP

#include "Cliente.hpp"
	
	class Conta : public Cliente
	{
		private: 
			static int numeroContas;
			int id;
			int	saldo;
			std::vector<int> Extrato;

		public:
			inline int getSaldo() const;
			inline void setSaldo(int x);
			inline int getId() const;
			inline int getExtrato(int x) const;
			inline void setExtrato(int x);
			inline int getTamExtrato() const;

			Conta(std::string nome, int cpf) :
				Cliente(nome,cpf),id(Conta::getNumeroContas()), saldo(100000){
					setExtrato(100000);
					//poderia aproveitar aqui e passar o id_agencia do objeto agencia
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

	inline int Conta::getExtrato(int x) const
	{
		return (this->Extrato.at(x));
	}

	inline void Conta::setExtrato(int x)
	{
		Extrato.push_back(x);
	}

	inline int Conta::getTamExtrato() const
	{
		return (this->Extrato.size());
	}
#endif
