#ifndef User_H
#define User_H
#include<iostream>
#include<string>
#include<vector>

#include"EPerfil.h"
#include"Livro.h"

using namespace std;

class User{
    private:
        string _nome;
        string _matricula;
        EPerfil _perfil;
    public:
        vector<Livro>ListarLivrosDisponiveis();
        User(string nome, string matricula, EPerfil perfil);
};

#endif