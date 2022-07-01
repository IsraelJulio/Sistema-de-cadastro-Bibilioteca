#include "../include/Administrador.h"

Administrador::Administrador(string nome, string matricula, EPerfil perfil): User(nome,matricula,perfil){}

void Administrador::Imprime(){
    cout << _nome << " : " << _matricula << "." << endl;
    return;
}

vector<Livro*> Administrador::ListarLivrosBloqueados(vector<Livro*> livrosSalvos){  

    for(std::vector<Livro*>::iterator it = livrosSalvos.begin(); it != livrosSalvos.end(); it++){
       if((*it)->GetStats() == true){
        for(std::vector<Livro*>::iterator it2 = _livrosBloqueados.begin(); it2 != _livrosBloqueados.end(); it2++){
            if((*it2)!=(*it)){                              //verifica se o livro já está na lista de livros bloqueados
                _livrosBloqueados.push_back(*it);
                break;
            }
        }
       }
    }
    return _livrosBloqueados;
}

vector<User*> Administrador::ListarUsuariosAtivos(vector<User*> usuarios){

    for(std::vector<User*>::iterator it = usuarios.begin(); it != usuarios.end(); it++){
        if((*it)->GetStatusUser() == true){
         for(std::vector<User*>::iterator it2 = _usuariosAtivos.begin(); it2 != _usuariosAtivos.end(); it2++){
                if((*it2)!=(*it)){                            //verifica se o usuário já está na lista de usuarios ativos
                _usuariosAtivos.push_back(*it);
                break;
                }
        }
       }
    }
    return _usuariosAtivos;
}

bool Administrador::Cadastro(Usuario* Usuario){

    for(std::vector<User*>::iterator it = _usuariosAtivos.begin(); it != _usuariosAtivos.end(); it++){
        if((*it)->GetMatricula() == Usuario->GetMatricula()) return false;
    }

    _usuariosAtivos.push_back(Usuario);
    return true;

}

bool Administrador::CadastrarLivro(int id, string nome, EGenero genero){

}

bool EditarUsuário(string matricula){

}