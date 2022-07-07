#include "Usuario.hpp"
#include <iostream>

Usuario::Usuario(string nome, string matricula, EPerfil perfil): User(nome,matricula,perfil){}
Usuario::Usuario(string nome, string matricula, EPerfil perfil,vector<Livro*> livros): User(nome,matricula,perfil){
    _meusLivros = livros;
}
void Usuario::Imprime(){
    cout << _nome << " : " << _matricula << "." << endl;
    cout << "Livros: " << endl;
    for(auto lv : _meusLivros)
    {
        lv->Imprime();
    }
    return;
}

string Usuario::GetDados(){
    return this->_nome + "," + this->_matricula + ",2," + GetMyBooks();    
}

string Usuario::GetMyBooks(){
    string result = "";
    for(auto id : _meusLivros)
    {
        result += id->GetId() + ",";
    }
    return result;
}