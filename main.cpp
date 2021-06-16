#include <iostream>
#include <vector>

#include "Conta.hpp"
#include "Banco.hpp"
#include "Banco.cpp"
//Teste
// fazer um arquivo com o inicializador de todas as variaveis statics
int Conta::numeroContas(400); //eu quis que todos os ids das contas começassem a partir de 400 pra facilitar a visualizacao
int Banco::numeroAgencias(0);
int Banco::balanco(0);

void clear()	//funcao encontrada na internet para poder dar o comando cls em todos os sistemas operacionais
{				//sou usuario de windows 10 apenas, por isso dependi de uma funcao da internet para limpar a tela no lixus e IOS.
	#if defined _WIN32
	    system("cls");
	#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__) || defined (__APPLE__)
	    system("clear");
	#endif
}

int main(int argc, char* argv[]){

	Banco* agencia = new Banco();
	int opcao = 0, subOpcao = 0;

	agencia->adicionaCliente(new Cliente(std::string("Arthur"),892));
	agencia->adicionaCliente(new Cliente(std::string("Clovis"),7));
	agencia->adicionaCliente(new Cliente(std::string("Carlos"),9));
	agencia->adicionaCliente(new Cliente(std::string("Klaus"),497));
	agencia->adicionaCliente(new Cliente(std::string("Patricia"),576));

	agencia->adicionaConta(new Conta(std::string("Arthur"),892));
	agencia->adicionaConta(new Conta(std::string("Clovis"),7));
	agencia->adicionaConta(new Conta(std::string("Carlos"),9)); 
	agencia->adicionaConta(new Conta(std::string("Arthur"),892));
	agencia->adicionaConta(new Conta(std::string("Carlos"),9));

	agencia->ExtratoClienteStart();

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
		clear();
		
		switch(opcao) {
			case 0:
				agencia->showClientes();
				break;
			case 1:
				agencia->showContas();
				break;
			case 2:
				std::cout << "(1) Saldo de cliente" << std::endl;
				std::cout << "(2) Saldo de conta" << std::endl;

				std::cin >> subOpcao;
				if(subOpcao == 1){
					try {
						agencia->saldoCliente();
					} catch (exception& e) {
						cout << e.what() << '\n';
					}
				} else if (subOpcao == 2) {
					try {
						agencia->saldoConta();
					} catch (exception& e) {
						cout << e.what() << '\n';
					}
				} else {
					std::cout << "Opcao invalida" << std::endl;
				}
				
				break;
			case 3:

				std::cout << "(1) Extrato do cliente" << std::endl;
				std::cout << "(2) Extrato da conta" << std::endl;

				std::cin >> subOpcao;
				if(subOpcao == 1){
					try {
						agencia->showExtratoCliente();
					} catch (exception& e) {
						cout << e.what() << '\n';
					}
				} else if (subOpcao == 2) {
					try {
						agencia->showExtratoConta();
					} catch (exception& e) {
						cout << e.what() << '\n';
					}
				} else {
					std::cout << "Opcao invalida" << std::endl;
				}
				break;
			case 4:
				try {
					agencia->transferencia();
				} catch (exception& e) {
					cout << e.what() << '\n';
				}
				break;
			case 5:
				std::cout << "Balanco do Banco: " << std::setprecision(2) << std::fixed << ((float)agencia->calculaBalanco())/100 << std::endl;
				break;
			case 6:
				opcao = -1;
				std::cout << "Saindo..." << std::endl;
				break;
			default:
				std::cout << "Escolha uma opcao valida" << std::endl;
		}
	} while (opcao != -1);

	agencia->destructBanco();
}
