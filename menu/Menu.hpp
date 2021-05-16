#ifndef MENU_HPP
#define MENU_HPP

#include <vector>
#include <iostream>

#include "MenuItem.hpp"
namespace menu
{
    class Menu
    {
        private:
            std::vector<menu::MenuItem*> itens; //vector de itens do MenuItem.hpp
        public:
            inline Menu(); //construtor (que ta vazio)
            virtual ~Menu(); //destrutor
            inline void adiciona(MenuItem* menuItem); //adiciona os itens do menu
            const int mostra() const; //mostra as opções do menu
            const bool executa(); // executa no while do main, retornando um bool, mantendo o menu  
                                  //perguntando a opção apos terminar o comportamento() do MenuItem.hpp

    };
}
// toda função inline, obrigatoriamente tem que estar no header (.hpp)
menu::Menu::Menu(): itens()
{
}

// inline no header
void menu::Menu::adiciona(MenuItem* menuItem)
{
	this->itens.push_back(menuItem);
}

#endif