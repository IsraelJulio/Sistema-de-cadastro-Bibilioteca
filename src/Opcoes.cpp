#include"../include/Opcoes.hpp"



#include<string.h>
#include<iostream>
#include<algorithm>
#include <vector>
#include<stdio.h>

void Opcoes::SaltarLinhas( int linhas)
{
    for(int i = 0; i< linhas; i++){
        cout << endl;
    }
}
void Opcoes::OpcoesLogin()
{
    cout << "Selecione uma das opcoes a seguir:" << endl;
    SaltarLinhas(3);
    cout<< "[0] Login como Administrador" << endl;
    cout<< "[1] Login como Usuario" << endl;
    cout<< "[9] fechar programa" << endl;
}
void Opcoes::OpcoesMenu()
{

}
void Opcoes::OPcoesMatricula()
{
    cout << "Digite o numero da sua matricula cadastrada" << endl;
    SaltarLinhas(8);
    cout<< "[9] Voltar ao menu principal" << endl;
    SaltarLinhas(3);        
}
void Opcoes::OpcoesUsuario(string nome)
{
    cout << "*********************************" << endl;
    cout << "Bem Vindo:"<< nome <<endl;
    cout << "*********************************" << endl;
    cout << "Selecione uma das opcoes a seguir:" << endl;
    SaltarLinhas(3);
    cout<< "[0] Visualizar meus Livros" << endl;
    cout<< "[1] Visualizar Livros disponiveis" << endl;
    cout<< "[9] Voltar ao Menu Principal" << endl;
}

void Opcoes::LimparTela()
{
     system("clear||cls");
     return;
}

bool Opcoes::OpcoesEncerrar()
{
    bool skip = false;
    std::vector<string> encerrar = { "0",  "9" };
    while(!skip)
    {
        cout << "Deseja Encerrar o Programa?" << endl;
        SaltarLinhas(3);
        cout << "[Y] Sim" << "\t" << "[N] Nao" << endl;
        char resposta;
        cin >> resposta;
        if(std::toupper(resposta) == 'Y')
            return false;

        if(std::toupper(resposta) == 'N')
            skip = true;
            

        LimparTela();
        cout << "************* opcao invalida *********************" << endl;
     }
    

    return true;
}
bool Opcoes::VoltarUsuario()
{
    bool skip = false;
    std::vector<string> voltar = { "0",  "9" };
    while(!skip)
    {
        string resposta = "";
        SaltarLinhas(5);
        cout<< "[0] Voltar ao Menu Anterior" << endl;
        cout<< "[9] Voltar ao Menu Principal" << endl;
        cin >> resposta;

        if(resposta == "0")
            return false;

        if(resposta == "9")
            skip = true;     

        LimparTela();
        cout << "************* opcao invalida *********************" << endl;   
    }

    return true;

}