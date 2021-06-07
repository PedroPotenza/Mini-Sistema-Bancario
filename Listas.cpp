#include <vector>   
#include <iostream> 
#include "Conta.hpp"

std::vector<Conta*> Contas;

void showContas(){
    int i;
    for(i=0; i < Contas.size(); i++){
        std::cout << "-------Conta "<< Contas.at(i)->getId() << "--------\n" << std::endl;
        std::cout << "Nome do Titular da Conta: " << Contas.at(i)->getNome() << std::endl;
        std::cout << "CPF do Titular da Conta: " << Contas.at(i)->getCpf() << "\n"<<  std::endl;
        std::cout << "Saldo da Conta: " << Contas.at(i)->getSaldo() / 100 << "\n"<<  std::endl;
    }
}

void saldoCliente(){
    int cpflocal, saldolocal(0), i;

    std::cout << "CPF do Cliente desejado: " ;
    std::cin >> cpflocal;

    for(i=0; i < Contas.size(); i++){
        if(cpflocal == Contas.at(i)->getCpf()){
            saldolocal = saldolocal + Contas.at(i)->getSaldo();
        }
    }

    std::cout << "Saldo do cliente: " << saldolocal << std::endl;
}

void showExtrato(){
    int i, idlocal, j;
    
    std::cout << "Id da conta: ";
    std::cin >> idlocal;

    for(i=0; i < Contas.size();i++){
        if(idlocal == Contas.at(i)->getId()){
            for(j=0; j < Contas.at(i)->getTamExtrato(); j++){
                std::cout << Contas.at(i)->getExtrato(j) << std::endl;
            }
        }
    }
}

void transferencia(){

    int idpaga, idrecebe, valorpago, i;

    std::cout << "Id da conta que envia: " ;
    std::cin >> idpaga;
    std::cout << "Valor que deseja transferir: " ; //lembrando de não utilizar virgula
    std::cin >> valorpago;
    std::cout << "Id da conta de quem recebe: " ;
    std::cin >> idrecebe;

    //fazer o tratamento de erro:
    //--> se informado um valor alem do q tem na conta
    //--> informou id inexistente
    //--> verificar o balanco

    for(i=0; i < Contas.size();i++){
        if(idpaga == Contas.at(i)->getId()){
            Contas.at(i)->setSaldo(Contas.at(i)->getSaldo()-valorpago);
            Contas.at(i)->setExtrato(-valorpago);
        }
        if(idrecebe == Contas.at(i)->getId()){
            Contas.at(i)->setSaldo(Contas.at(i)->getSaldo()+valorpago);
            Contas.at(i)->setExtrato(+valorpago);
        }
    }
}

//eu poderia evitar utilizar estruturas de repetição para localizar o id das contas pois elas são facilmente
//deduzidas (comecam nos 400 e terminam no 400+numero de contas), porem optei por deixar com os for para que
//meu código ficasse mais genérico e reutilizavel em um cenario onde é possivel uma conta ser deletada por exemplo
//o que causaria uma mudança na ordem de ids.
//(404 foi deletado, mas isso não torna o 405 em 404 por exemplo)
