#include "MenuItem.hpp"

#include <iostream>
#include <vector>
#include <string>

class MenuListaClientes : public menu::MenuItem
{
	virtual const std::string nome()
	{
		return (std::string("Lista de Clientes"));
	}

	virtual void comportamento()
	{
		
		
	}
};

class MenuListaContas : public menu::MenuItem
{
	virtual const std::string nome()
	{
		return (std::string("Lista de Contas"));
	}

	virtual void comportamento()
	{
		//std::cout << "Nome: " << p1->getNome() << std::endl;
		//std::cout << "CPF: " << p1->getCpf() << std::endl;
	}
};

class MenuSaldoCliente : public menu::MenuItem
{
	virtual const std::string nome()
	{
		return (std::string("Saldo do Cliente"));
	}

	virtual void comportamento()
	{
		//std::cout << "Nome: " << p1->getNome() << std::endl;
		//std::cout << "CPF: " << p1->getCpf() << std::endl;
	}
};

class MenuExtratoCliente : public menu::MenuItem
{
	virtual const std::string nome()
	{
		return (std::string("Extrato do Cliente"));
	}

	virtual void comportamento()
	{
		//std::cout << "Nome: " << p1->getNome() << std::endl;
		//std::cout << "CPF: " << p1->getCpf() << std::endl;
	}
};

class MenuTransferencia : public menu::MenuItem
{
	virtual const std::string nome()
	{
		return (std::string("Realizar Transferencia"));
	}

	virtual void comportamento()
	{
		//std::cout << "Nome: " << p1->getNome() << std::endl;
		//std::cout << "CPF: " << p1->getCpf() << std::endl;
	}
};

extern Banco agencia; //não consegui achar um meio de evitar usar o extern (sei q é ruim utilizar ele por se tornar algo global certo?)

class MenuSaldoTotal : public menu::MenuItem
{
	virtual const std::string nome()
	{
		return (std::string("Valor Total das Contas"));
	}

	virtual void comportamento()
	{
		std::cout << "Balanco no Menu: " << agencia.getBalanco() << std::endl;
	}
};
