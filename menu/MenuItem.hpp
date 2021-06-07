#ifndef MENUITEM_HPP
#define MENUITEM_HPP

#include <string>
namespace menu
{
    class MenuItem
    {
        public:
        virtual void comportamento() = 0; 
        virtual const std::string nome() = 0; //nome que aparecera no meu
    };
    //interface criada para cada item do menu obrigatoriamente ter um nome e um comportamento
    //código baseado no exercício exemplo dado pelo professor
}

#endif 
