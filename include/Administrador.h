#ifndef Administrador_H
#define Administrador_H
#include<vector>
#include"User.h"
#include"Livro.h"
using namespace std;

class Administrador: public User{
    private:

    public:
        Administrador(string nome, string matricula, EPerfil perfil);
        void Imprime() override;
        vector<Livro*>ListarLivrosBloqueados(vector<Livro*> livros);
        vector<User*>ListarUsuariosAtivos(vector<User*> usuarios);
};

#endif