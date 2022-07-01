#ifndef Administrador_H
#define Administrador_H
#include<vector>
#include"User.h"
#include"Livro.h"
#include "Usuario.h"
using namespace std;

class Administrador: public User{
    private:
        vector<User*> _usuariosAtivos;
        vector<Livro*> _livrosBloqueados;
        vector<Livro*> _livrosDevolvidos;

    public:
        Administrador(string nome, string matricula, EPerfil perfil);
        virtual void Imprime() override;
        vector<Livro*>ListarLivrosBloqueados(vector<Livro*> livros);
        vector<User*>ListarUsuariosAtivos(vector<User*> usuarios);
        bool Cadastro(Usuario* Usuario);
        bool CadastrarLivro(int id, string nome, EGenero genero);
        bool EditarUsuario(string matricula);

};

#endif