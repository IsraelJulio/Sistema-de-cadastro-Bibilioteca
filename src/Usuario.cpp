#include "Usuario.h"
#include <iostream>

Usuario::Usuario(string nome, string matricula, EPerfil perfil): User(nome,matricula,perfil){}
Usuario::Usuario(string nome, string matricula, EPerfil perfil,vector<Livro*> livros): User(nome,matricula,perfil){
    _meusLivros = livros;
}
void Usuario::Imprime(){
    cout << _nome << " : " << _matricula << "." << endl;
    cout << "Livros: ";
    for(auto lv : _meusLivros)
    {
        lv->Imprime();
    }
    return;
}