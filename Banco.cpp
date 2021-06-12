#include <vector>   
#include <iostream> 
#include <iomanip>
#include "Banco.hpp"
#include "Cliente.hpp"
#include "Conta.hpp"

void Banco::showClientes(){
    int i;
    for(i=0; i < Clientes.size(); i++){
        std::cout << "-------Cliente "<< i + 1 << "--------\n" << std::endl;
        std::cout << "Nome do cliente: " << Clientes.at(i)->getNome() << std::endl;
        std::cout << "CPF do cliente: " << Clientes.at(i)->getCpf() << "\n"<<  std::endl;
    }
}


void Banco::showContas(){
    int i;
    for(i=0; i < Contas.size(); i++){
        std::cout << "-------Conta "<< Contas.at(i)->getId() << "--------\n" << std::endl;
        std::cout << "Nome do Titular da Conta: " << Contas.at(i)->getNome() << std::endl;
        std::cout << "CPF do Titular da Conta: " << Contas.at(i)->getCpf() << "\n"<<  std::endl;
        std::cout << "Saldo da Conta: " << std::setprecision(2) << std::fixed << ((float)Contas.at(i)->getSaldo()) / 100 << "\n"<<  std::endl;
    }
}

void Banco::saldoCliente(){
    int cpflocal, saldolocal(0), i;

    std::cout << "CPF do Cliente desejado: " ;
    std::cin >> cpflocal;

    for(i=0; i < Contas.size(); i++){
        if(cpflocal == Contas.at(i)->getCpf()){
            saldolocal = saldolocal + Contas.at(i)->getSaldo();
        }
    }

    std::cout << "Saldo do cliente: " << std::setprecision(2) << std::fixed << ((float)saldolocal)/100 << std::endl;
}

void Banco::showExtrato(){
    int i, idlocal, j;
    
    std::cout << "Id da conta: ";
    std::cin >> idlocal;

    for(i=0; i < Contas.size();i++){
        if(idlocal == Contas.at(i)->getId()){
            for(j=0; j < Contas.at(i)->getTamExtrato(); j++){
                if(Contas.at(i)->getExtrato(j) > 0)
                    std::cout << "+" << std::setprecision(2) << std::fixed  << ((float)Contas.at(i)->getExtrato(j))/100 << std::endl;
                else
                    std::cout << std::setprecision(2) << std::fixed << ((float)Contas.at(i)->getExtrato(j))/100 << std::endl;
            }
        }
    }
}

void Banco::transferencia(){

    int idpaga, valorpago,idrecebe, i;
    int balancoinicial, balancofinal;
    float valorinformado;

    balancoinicial = this->calculaBalanco();

    std::cout << "Id da conta que envia: " ;
    std::cin >> idpaga;
    std::cout << "Valor que deseja transferir: "; 
    std::cin >> valorinformado;
    std::cout << "Id da conta de quem recebe: " ;
    std::cin >> idrecebe;

    valorinformado = valorinformado * 100;
    valorpago = (int)valorinformado;

    //fazer o tratamento de erro:
    //--> se informado um valor alem do q tem na conta
    //--> informou id inexistente
    //--> verificar o balanco

    for(i=0; i < this->Contas.size();i++){
        if(idpaga == this->Contas.at(i)->getId()){
            this->Contas.at(i)->setSaldo(this->Contas.at(i)->getSaldo()-valorpago);
            this->Contas.at(i)->setExtrato(-valorpago);
        }
        if(idrecebe == this->Contas.at(i)->getId()){
            this->Contas.at(i)->setSaldo(this->Contas.at(i)->getSaldo()+valorpago);
            this->Contas.at(i)->setExtrato(+valorpago);
        }
    }

    balancofinal = this->calculaBalanco();
    //Balanco Inicial e o Balanco Final TEM que ser iguais.
    

    //eu poderia evitar utilizar estruturas de repetição para localizar o id das contas pois elas são facilmente
    //deduzidas (comecam nos 400 e terminam no 400+numero de contas), porem optei por deixar com os for para que
    //meu código ficasse mais genérico e reutilizavel em um cenario onde é possivel uma conta ser deletada por exemplo
    //o que causaria uma mudança na ordem de ids.
    //(404 foi deletado, mas isso não torna o 405 em 404 por exemplo)

}

    


