#include <iostream>
#include <vector>

#include "Conta.hpp"
#include "Banco.hpp"
#include "Banco.cpp"

<<<<<<< HEAD
//menu
#include "menu/Menu.hpp"
#include "menu/Menu.cpp"
#include "menu/Itens.cpp"
Banco agencia;

// fazer um arquivo com o inicializador de todas as variaveis statics
int Conta::numeroContas(400); //eu quis que todos os ids das contas começassem a partir de 400 pra facilitar a visualizacao
=======
int Conta::numeroContas(400); // Inicializacao dos ID's em 400 para maior facilidade na visualizacao
>>>>>>> develop
int Banco::numeroAgencias(0);
int Banco::balanco(0);

void clear()	// Funcao utilizada para limpar a tela em todos os sistemas operacionais
{
	#if defined _WIN32
	    system("cls");
	#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__) || defined (__APPLE__)
	    system("clear");
	#endif
}

int main(int argc, char* argv[]){

	Banco* agencia = new Banco();
<<<<<<< HEAD
//	std::vector<Cliente*> Clientes; (vector criado no Listas.cpp)
		agencia->Clientes.push_back(new Cliente(std::string("Arthur"),892));
		agencia->Clientes.push_back(new Cliente(std::string("Clovis"),7));
		agencia->Clientes.push_back(new Cliente(std::string("Carlos"),9));
		agencia->Clientes.push_back(new Cliente(std::string("Klaus"),497));
		agencia->Clientes.push_back(new Cliente(std::string("Patricia"),576));
//	std::vector<Conta*> Contas; (vector criado no Listas.cpp)
		agencia->Contas.push_back(new Conta(std::string("Arthur"),892,*agencia));
		agencia->Contas.push_back(new Conta(std::string("Clovis"),7,*agencia));
		agencia->Contas.push_back(new Conta(std::string("Carlos"),9,*agencia));
		agencia->Contas.push_back(new Conta(std::string("Arthur"),892,*agencia));
		agencia->Contas.push_back(new Conta(std::string("Carlos"),9,*agencia));

//	Conta* p3 = new Conta(*c1, *agencia); //tentativa q deu erro la no Conta.hpp
	
	menu::Menu menu;
	
	menu.adiciona(new MenuListaClientes());
	menu.adiciona(new MenuListaContas());
	menu.adiciona(new MenuSaldoCliente());
	menu.adiciona(new MenuExtratoCliente());
	menu.adiciona(new MenuTransferencia());
	menu.adiciona(new MenuSaldoTotal());


	while (menu.executa()); //vai ficar solicitando a opção até informar um numero invalido

	std::cout << "Nome do CLIENTE: " << agencia->Clientes.at(0)->getNome() << std::endl;
	std::cout << "CPF do CLIENTE: " << agencia->Clientes.at(0)->getCpf() << std::endl;
	std::cout << "Numero de Clientes: " << agencia->Clientes.size() << std::endl;
=======
	int opcao = 0, subOpcao = 0;

	// Inicializacao dos clientes do banco
	agencia->adicionaCliente(new Cliente(std::string("Pedro Potenza"), 12345671));
	agencia->adicionaCliente(new Cliente(std::string("Gabriel Tetzlaf"), 12345672));
	agencia->adicionaCliente(new Cliente(std::string("Thiago Gottardi"), 12345673));
	agencia->adicionaCliente(new Cliente(std::string("Claudia Soares"), 12345674));
	agencia->adicionaCliente(new Cliente(std::string("Maria Antonieta"), 12345675));

	// Inicializacao das contas dos clientes
	agencia->adicionaConta(new Conta(std::string("Pedro Potenza"), 12345671));
	agencia->adicionaConta(new Conta(std::string("Gabriel Tetzlaf"), 12345672));
	agencia->adicionaConta(new Conta(std::string("Thiago Gottardi"), 12345673)); 
	agencia->adicionaConta(new Conta(std::string("Claudia Soares"), 12345674));
	agencia->adicionaConta(new Conta(std::string("Maria Antonieta"), 12345675));

	// Inicializa extrato do cliente
	agencia->ExtratoClienteStart();

	// Menu de opcoes disponiveis
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
>>>>>>> develop

	// Invocando Destrutor de Banco
	agencia->destructBanco();
}
