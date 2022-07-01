#ifndef Usuario_H
#define Usuario_H
#include<vector>
#include"User.h"
#include"Livro.h"

using namespace std;

class Usuario : public User{
    private:
        
    public:
    vector<Livro*> _meusLivros;
    bool Reservar(int LivroId);
    vector<Livro> ListarReservados();
    Usuario(string nome, string matricula, EPerfil perfil);
    Usuario(string nome, string matricula, EPerfil perfil,vector<Livro*> livros);
    virtual void Imprime() override;

};

#endif