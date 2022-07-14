#ifndef User_H
#define User_H
#include<iostream>
#include<string>
#include<vector>

#include"EPerfil.hpp"
#include"Livro.hpp"

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
        static vector<User*> GetAllUsers();
        virtual void Imprime() = 0;
        virtual string GetDados() = 0;
        string GetStatusUser();
        string GetMatricula();
        
};

#endif