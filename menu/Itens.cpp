#include "MenuItem.hpp"

#include <iostream>
#include <string>

//fazer todas as opções do menu
//1. Lista clientes
//2. Lista contas
//3. Saldo do cliente
//4. Extrato do cliente
//5. Realizar transferencia
//6. Mostrar o balanco (outro nome)

class MenuOlaMundo : public menu::MenuItem
{
	virtual void comportamento()
	{
		std::cout << "Comportamento Ola Mundo!" << std::endl;
	}

	virtual const std::string nome()
	{
		return (std::string("Ola Mundo"));
	}
};

class MenuMultiplica :  public menu::MenuItem
{
    virtual void comportamento()
	{
		std::cout << "Insira os dois parametros para multiplicar:" << std::endl;
		int x,y;
		std::cin >> x >> y;

		std::cout << "O produto eh = " << (x*y) << std::endl;
	}

	virtual const std::string nome()
	{
		return (std::string("Multiplicar"));
	}
};

class MenuSoma : public menu::MenuItem
{
	virtual void comportamento()
	{
		std::cout << "Insira os dois parametros para somar:" << std::endl;
		int x,y;
		std::cin >> x >> y;	
		
		std::cout << "A soma eh = " << (x+y) << std::endl;		
	}	
	
	virtual const std::string nome()
	{
		return(std::string("Somar"));
	}
};



