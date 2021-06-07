#include <iostream>
#include <vector>

#include "Conta.hpp"
#include "Banco.hpp"

//menu
#include "menu/Menu.hpp"
#include "menu/Menu.cpp"
#include "menu/Itens.cpp"

// fazer um arquivo com o inicializador de todas as variaveis statics
int Conta::numeroContas(400); //eu quis que todos os ids das contas começassem a partir de 400 pra facilitar a visualizacao
int Banco::numeroAgencias(0);
int Banco::balanco(0);

int main(int argc, char* argv[]){

	Banco* agencia = new Banco();
	int opcao = 0;

	agencia->adicionaCliente(new Cliente(std::string("Arthur"),892));
	agencia->adicionaCliente(new Cliente(std::string("Clovis"),7));
	agencia->adicionaCliente(new Cliente(std::string("Carlos"),9));
	agencia->adicionaCliente(new Cliente(std::string("Klaus"),497));
	agencia->adicionaCliente(new Cliente(std::string("Patricia"),576));

//	std::vector<Conta*> Contas; (vector criado no Listas.cpp)
	agencia->adicionaConta(new Conta(std::string("Arthur"),892));
	agencia->adicionaConta(new Conta(std::string("Clovis"),7));
	agencia->adicionaConta(new Conta(std::string("Carlos"),9));
	agencia->adicionaConta(new Conta(std::string("Arthur"),892));
	agencia->adicionaConta(new Conta(std::string("Carlos"),9));

	agencia->showContas();
//	Conta* p3 = new Conta(*c1, *agencia); //tentativa q deu erro la no Conta.hpp
	
	menu::Menu menu;
	
	menu.adiciona(new MenuListaClientes());
	menu.adiciona(new MenuListaContas());
	menu.adiciona(new MenuSaldoCliente());
	menu.adiciona(new MenuExtratoCliente());
	menu.adiciona(new MenuTransferencia());
	menu.adiciona(new MenuSaldoTotal());


	do {
		std::cout << "Escolha um item pelo numero:" << std::endl;
		std::cout << "(0) Lista de Clientes" << std::endl;
		std::cout << "(1) Lista de Contas" << std::endl;
		std::cout << "(2) Saldo" << std::endl;
		std::cout << "(3) Extrato" << std::endl;
		std::cout << "(4) Realizar Transferencia" << std::endl;
		std::cout << "(5) Valor Total das Contas" << std::endl;

		std::cin >> opcao;

	} while (opcao != -1);
}
