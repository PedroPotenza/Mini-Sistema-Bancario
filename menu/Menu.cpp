#include "Menu.hpp"

menu::Menu::~Menu() //destrutor
{
    // enquanto não vazio
    while (! (itens.empty()) )  
    {
        // desaloca ponteiro do ultimo.
        delete (this->itens.back());
        // remove ponteiro do último.
        this->itens.pop_back();

        //assumo que nao entendi muito bem essa parte
    }
}

const int menu::Menu::mostra() const
{
    std::cout << "Itens do menu:" << std::endl;

    for (int i(0); i < this->itens.size(); i++)
    {
        std::cout << '(' << i << ')' << ':' << ' ' << this->itens.at(i)->nome() << std::endl;
        //mostra todos os itens do vector
    }
    std::cout << "Escolha um item pelo numero:" << std::endl;
    int itemIndice(-1);//inicializa com um valor negativo para n ter chance de erro por lixo

    std::cin >> itemIndice;

    return (itemIndice); //retorna um int (sendo a opção escolhida pelo usuario)
}

const bool menu::Menu::executa() //while da main
{
    const int opcao(this->mostra()); //inicializa o valor de opção com o valor de retorno do mostra();

    if ((opcao >= 0) && (opcao < this->itens.size())) //se existe a opção
    {
        std::cout << std::endl;
        this->itens.at(opcao)->comportamento(); //executa o comportamento da opção escolhida
        std::cout << std::endl;
        return (true); //retorna 1, mantendo o valor em verdadeiro (retorno em bool) -- retorna isso na main
    }
    else
    {
        return (false); //retorna 0, fazendo o main continuar (e consequentemente terminando a execução)
    }
}
