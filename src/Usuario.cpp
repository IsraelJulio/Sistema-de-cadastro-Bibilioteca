#include "Usuario.hpp"
#include"../include/Operacoes.hpp"
#include <iostream>
#include<fstream>
#include <iterator>
#include <algorithm>

Usuario::Usuario(string nome, string matricula, EPerfil perfil): User(nome,matricula,perfil){}
Usuario::Usuario(string nome, string matricula, EPerfil perfil,bool stats): User(nome,matricula,perfil,stats){}
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
    return this->_nome + "," + this->_matricula + ",2," + this->GetStatusUser() + GetMyBooks();    
}

string Usuario::GetMyBooks(){
    string result = "";    
    ifstream arq("Usuarios_bkp.txt");
    vector<Livro*> livrosSalvos;
    string conteudo = "";
    vector<string> value;

     if (arq.is_open())
    {
        while (getline(arq, conteudo)){
            Operacoes::split(conteudo.begin(),conteudo.end(),',', back_inserter(value));
            
            if (value[1] == this->_matricula)
            {
                for (long unsigned int o = 4; o < value.size(); o++)
                {                    
                    result +=  "," + value[o];                                                  
                }
            }            
            value.clear();
        }
        arq.close();
    }
    return result;
}

User* Usuario::GetUserByMatricula(string matricula)
{
    auto usuariosAtivos = User::GetAllUsers();

    for(auto user : usuariosAtivos)
    {
        if(user->GetMatricula() == matricula){            
            return user;
        }
            
    }
    return nullptr;    
}
