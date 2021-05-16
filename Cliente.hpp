#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include <string>

	class Cliente{
		private:
			std::string nome;
			int cpf;
		public: 
			inline std::string getNome() const;
			inline void setNome(std::string x);
			inline int getCpf() const;
			inline void setCpf(int y);

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
		
#endif
