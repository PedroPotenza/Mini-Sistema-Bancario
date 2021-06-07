#include "MenuItem.hpp"
#include "../Banco.hpp"

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
		agencia.showClientes();
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
		agencia.showContas();
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
		agencia.saldoCliente();
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
		agencia.showExtrato();
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
		agencia.transferencia();
	}
};

extern Banco agencia; //não consegui achar um meio de evitar usar o extern (sei q é ruim utilizar ele por se tornar algo global certo?)
//talvez eu poderia passar ela pelo Listas.cpp instanciando o objeto la e criando a função la.

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
