#ifndef Administrador_H
#define Administrador_H
#include<vector>
#include"User.hpp"
#include"Livro.hpp"
#include "Usuario.hpp"
using namespace std;

class Administrador: public User{
    private:
        vector<User*> _usuariosAtivos;
        vector<Livro*> _livrosBloqueados;
        vector<Livro*> _livrosDevolvidos;

    public:
        Administrador(string nome, string matricula, EPerfil perfil);
        Administrador(string nome, string matricula, EPerfil perfil, bool stats);
        virtual void Imprime() override;
        vector<Livro*>ListarLivrosBloqueados(vector<Livro*> livros);
        vector<User*>ListarUsuariosAtivos(vector<User*> usuarios);
        bool SetUsuario(User* Usuario);
        bool SetLivro(string nome, EGenero genero);
        bool EditarUsuario(string matricula);
        bool AtualizarListaDeUsuarios(vector<User *> list);
        bool SetLivroByUsuario(int id, string matricula);
        static bool validarMatricula(string matricula);
        bool validarLivro(int id);
        bool removerUsuario(string matricula, vector<User *> list);
        virtual string GetDados() override;
        void Updatebkp();
        void Updatesrc();
        bool Devolucao(string matricula, int id);
        bool SetBloqueio(string matricula);
};

#endif