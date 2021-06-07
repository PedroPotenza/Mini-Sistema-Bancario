#include "MenuItem.hpp"
#include "../Banco.hpp"
#include "../Banco.cpp"

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
	}
};
 //não consegui achar um meio de evitar usar o extern (sei q é ruim utilizar ele por se tornar algo global certo?)
//talvez eu poderia passar ela pelo Listas.cpp instanciando o objeto la e criando a função la.

class MenuSaldoTotal : public menu::MenuItem
{
	virtual const std::string nome()
	{
		return (std::string("Valor Total das Contas"));
	}

	virtual void comportamento()
	{
		std::cout << "Balanco no Menu: " << std::endl;
	}
};
