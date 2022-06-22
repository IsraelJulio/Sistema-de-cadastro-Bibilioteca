#include "../include/Administrador.h"

Administrador::Administrador(string nome, string matricula, EPerfil perfil): User(nome,matricula,perfil){}

void Administrador::Imprime(){
    cout << _nome << " : " << _matricula << "." << endl;
    return;
}

vector<Livro*> Administrador::ListarLivrosBloqueados(vector<Livro*> livrosSalvos){
    vector<Livro*> livrosBloqueados;

    for(std::vector<Livro*>::iterator it = livrosSalvos.begin(); it != livrosSalvos.end(); it++){
       if((*it)->GetStats() == true){
        livrosBloqueados.push_back(*it);
       }
    }

    return livrosBloqueados;
}