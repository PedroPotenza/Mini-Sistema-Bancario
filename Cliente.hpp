#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include <string>

	class Cliente{
		private:
			std::string nome;
			int cpf;
			
		protected:
		std::vector<int> Extrato;
		public: 
			inline std::string getNome() const;
			inline void setNome(std::string x);
			inline int getCpf() const;
			inline void setCpf(int y);
			inline int getExtrato(int x) const;
			inline void setExtrato(int x);
			inline int getTamExtrato() const;

			Cliente(std::string nome, int cpf) : nome(nome),cpf(cpf){
			}
		
	};
	
	//getters e setters desnecessários
	//vi dps que não é necessario ter a opcao do menu para cadastrar os clientes

	//serviu de teste e treino

	inline std::string Cliente::getNome() const
	{
		return (this->nome);
	}
	
	inline void Cliente::setNome(std::string x)
	{
		nome = x;
	}
		
	inline int Cliente::getCpf() const
	{
		return (this->cpf);
	}	
	
	inline void Cliente::setCpf(int y)
	{
		cpf = y;
	}
	
	inline int Cliente::getExtrato(int x) const
	{
		return (this->Extrato.at(x));
	}

	inline void Cliente::setExtrato(int x)
	{
		Extrato.push_back(x);
	}

	inline int Cliente::getTamExtrato() const
	{
		return (this->Extrato.size());
	}
#endif
