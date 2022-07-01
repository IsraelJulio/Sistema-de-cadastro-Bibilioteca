#ifndef User_H
#define User_H
#include<iostream>
#include<string>
#include<vector>

#include"EPerfil.h"
#include"Livro.h"

using namespace std;

class User{
    protected:
        string _nome;
        string _matricula;
        EPerfil _perfil;
        bool _active;
    public:
        vector<Livro*>ListarLivrosDisponiveis();
        User(string nome, string matricula, EPerfil perfil, bool active);
        User(string nome, string matricula, EPerfil perfil);
        static vector<User*> CarregarUsuarios();
        virtual void Imprime() = 0;
        bool GetStatusUser();
        
};

#endif