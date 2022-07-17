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
void Opcoes::OpcaoInvalida()
{
    cout << "************* opcao invalida *********************" << endl;
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
    cout << "Bem Vindo "<< nome <<endl;
    cout << "*********************************" << endl;
    cout << "Selecione uma das opcoes a seguir:" << endl;
    SaltarLinhas(3);
    cout<< "[0] Visualizar meus Livros" << endl;
    cout<< "[1] Visualizar Livros disponiveis" << endl;
    cout<< "[9] Voltar ao Menu Principal" << endl;
}

void Opcoes::OpcoesAdm(string nome)
{
    cout << "*********************************" << endl;
    cout << "Bem Vindo "<< nome <<endl;
    cout << "*********************************" << endl;
    cout << "Selecione uma das opcoes a seguir:" << endl;
    SaltarLinhas(3);
    cout<< "[0] Cadastrar Um Livro" << endl;
    cout<< "[1] Visualizar Livros disponiveis" << endl;
    cout<< "[2] Visualizar todos os usuarios" << endl;
    cout<< "[3] Visualizar usuarios bloqueados" << endl;
    cout<< "[4] Bloquear Usuario" << endl;
    cout<< "[5] Efetuar Devolucao" << endl;
    cout<< "[6] Efetuar Emprestimo para usuario" << endl;
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
        OpcaoInvalida();
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
        OpcaoInvalida();  
    }

    return true;

}

void Opcoes::OpcaoSelecionada(string opcao)
{
    SaltarLinhas(5);
    LimparTela();
    cout << "******************************************************" << endl;
    cout << "opcao Selecionada: "<< opcao <<endl;
    cout << "******************************************************" << endl;
    SaltarLinhas(2);
    return;
}

void Opcoes::OpcaoLivroNome()
{
    cout << endl << "Informe o nome do Livro:" << endl;
}

void Opcoes::OpcaoLivroGenero()
{
    cout << endl << "Informe a classificacao do Livro entre as disponiveis:" << endl;
    cout << "[0] - Cálculo" << endl;
    cout << "[1] - Geometria" << endl;
    cout << "[2] - Quimica" << endl;
    cout << "[3] - Física" << endl;
    cout << "[4] - Fantasia" << endl;
    cout << "[5] - Aventura" << endl;
    cout << "[6] - Romance" << endl;
    SaltarLinhas(3);   
    cout << "[9] - Para Cancelar e Voltar ao menu principal" << endl;   

}

void Opcoes::CadastroSucesso()
{
    cout << "Cadastro Efetuado com sucesso!!" << endl;
    SaltarLinhas(5);
}

void Opcoes::CadastroFalha()
{
    cout << "Cadastro Falhou! " << endl << "Parece que o Arquivo .txt esta aberto =(" << endl;
}