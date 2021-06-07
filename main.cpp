#include <iostream>
#include <vector>

#include "Conta.hpp"
#include "Banco.hpp"

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


	do {
		std::cout << std::endl << "Escolha um item pelo numero:" << std::endl;
		std::cout << "(0) Lista de Clientes" << std::endl;
		std::cout << "(1) Lista de Contas" << std::endl;
		std::cout << "(2) Saldo" << std::endl;
		std::cout << "(3) Extrato" << std::endl;
		std::cout << "(4) Realizar Transferencia" << std::endl;
		std::cout << "(5) Valor Total das Contas" << std::endl;
		std::cout << "(6) Sair" << std::endl;

		std::cin >> opcao;

		switch(opcao) {
			case 0:
				agencia->showClientes();
				break;
			case 1:
				agencia->showContas();
				break;
			case 2:
				agencia->saldoCliente();
				break;
			case 3:
				agencia->showExtrato();
				break;
			case 4:
				agencia->transferencia();
				break;
			case 5:
				agencia->getBalanco();
				break;
			case 6:
				opcao = -1;
				std::cout << "Saindo..." << std::endl;
				break;
			default:
				std::cout << "Escolha uma opcao valida" << std::endl;
		}

	} while (opcao != -1);
}
