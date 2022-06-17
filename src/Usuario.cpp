#include "Usuario.h"

Usuario::Usuario(string nome, string matricula, EPerfil perfil): User(nome,matricula,perfil){}
Usuario::Usuario(string nome, string matricula, EPerfil perfil,vector<Livro*> livros): User(nome,matricula,perfil){
    _meusLivros = livros;
}