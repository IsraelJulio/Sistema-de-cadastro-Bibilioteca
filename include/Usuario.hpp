#ifndef Usuario_H
#define Usuario_H
#include<vector>
#include"User.hpp"
#include"Livro.hpp"

using namespace std;

class Usuario : public User{
    private:
        
    public:
    Usuario(string nome, string matricula, EPerfil perfil);
    Usuario(string nome, string matricula, EPerfil perfil, bool stats);
    Usuario(string nome, string matricula, EPerfil perfil,vector<Livro*> livros);
    vector<Livro*> _meusLivros;
    bool Reservar(int LivroId);
    vector<Livro> ListarReservados();
    string GetMyBooks();
    virtual void Imprime() override;
    virtual string GetDados() override;

};

#endif