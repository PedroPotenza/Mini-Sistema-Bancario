#include <iostream>

#include "Conta.hpp"
//menu
#include "menu/Menu.hpp"
#include "menu/Menu.cpp"
#include "menu/Itens.cpp"

int Conta::numeroContas(400);

int main(int argc, char* argv[]){


	Conta* p1 = new Conta(std::string("Carlos"),9);

	menu::Menu menu;
	
	menu.adiciona(new MenuOlaMundo());

	while (menu.executa()); //vai ficar solicitando a opção até informar um numero invalido

	std::cout << "Nome: " << p1->getNome() << std::endl;
	std::cout << "CPF: " << p1->getCpf() << std::endl;
	std::cout << "Id da Conta: " << p1->getId() << std::endl;
	std::cout << "Saldo: " << p1->getSaldo() << std::endl;

}
