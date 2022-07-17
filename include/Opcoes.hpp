#ifndef OPCOES_H
#define OPCOES_H

#include<iostream>
#include<vector>
using namespace std;

class Opcoes
{
private:
public:    
    static void SaltarLinhas( int linhas);
    static void OpcoesLogin();
    static void OpcoesMenu();
    static void OPcoesMatricula();
    static void OpcoesUsuario(string nome);
    static void OpcoesAdm(string nome);
    static bool OpcoesEncerrar();
    static void LimparTela();
    static bool VoltarUsuario();
    static void OpcaoSelecionada(string opcao);
    static void OpcaoLivroNome();
    static void OpcaoLivroGenero();
    static void OpcaoLivroGeneroDisponivel();
    static void CadastroSucesso();
    static void CadastroFalha();


};




#endif