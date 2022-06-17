#ifndef Usuario_H
#define Usuario_H
#include<vector>
#include"User.h"
#include"Livro.h"

using namespace std;

class Usuario : public User{
    private:
    vector<Livro*> _meusLivros;
        
    public:
    bool Reservar(int LivroId);
    vector<Livro> ListarReservados();
    Usuario(string nome, string matricula, EPerfil perfil);

};

#endif