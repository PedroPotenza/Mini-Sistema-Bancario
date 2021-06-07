#include <iostream>
#include <vector>

#include "Conta.hpp"
#include "Banco.hpp"

//menu
#include "menu/Menu.hpp"
#include "menu/Menu.cpp"
#include "menu/Itens.cpp"
Banco agencia;

// fazer um arquivo com o inicializador de todas as variaveis statics
int Conta::numeroContas(400); //eu quis que todos os ids das contas começassem a partir de 400 pra facilitar a visualizacao
int Banco::numeroAgencias(0);
int Banco::balanco(0);


int main(int argc, char* argv[]){

	Banco* agencia = new Banco();
//	std::vector<Cliente*> Clientes; (vector criado no Listas.cpp)
		agencia->Clientes.push_back(new Cliente(std::string("Arthur"),892));
		agencia->Clientes.push_back(new Cliente(std::string("Clovis"),7));
		agencia->Clientes.push_back(new Cliente(std::string("Carlos"),9));
		agencia->Clientes.push_back(new Cliente(std::string("Klaus"),497));
		agencia->Clientes.push_back(new Cliente(std::string("Patricia"),576));
//	std::vector<Conta*> Contas; (vector criado no Listas.cpp)
	Contas.push_back(new Conta(std::string("Arthur"),892,*agencia));
	Contas.push_back(new Conta(std::string("Clovis"),7,*agencia));
	Contas.push_back(new Conta(std::string("Carlos"),9,*agencia));
	Contas.push_back(new Conta(std::string("Arthur"),892,*agencia));
	Contas.push_back(new Conta(std::string("Carlos"),9,*agencia));

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

}
