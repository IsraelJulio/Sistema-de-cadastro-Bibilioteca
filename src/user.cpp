#include "../include/User.h"
#include "../include/Usuario.h"
#include "../include/Administrador.h"
#include"../include/Operacoes.h"
#include<fstream>
#include <iterator>

User::User(string nome, string matricula, EPerfil perfil, bool active){
    _nome = nome;
    _matricula = matricula;
    _perfil = perfil;
    _active = active;
}

User::User(string nome, string matricula, EPerfil perfil){
    _nome = nome;
    _matricula = matricula;
    _perfil = perfil;
    _active = true;

}

vector<User*> User::GetAllUsers(){
    vector<User*> usuariosSalvos;
    vector<Livro*> livrosSalvos;
    string conteudo = "";
    ifstream arq("Usuarios.txt");
    vector<string> value;
    if (arq.is_open())
    {
        while (getline(arq, conteudo)){
          Operacoes::split(conteudo.begin(),conteudo.end(),',', back_inserter(value));    
          if (value.size() < 4)
          {
            Administrador* admin = new Administrador(value[0],value[1],static_cast<EPerfil>(stoi(value[2])));
            usuariosSalvos.push_back(admin);
          } else {
            for (long unsigned int o = 3; o < value.size(); o++)
            {
                auto lv = Livro::GetById(stoi(value[o]));
                Livro* livro = new Livro(lv->GetId(),lv->GetName(), lv->GetGenre(),lv->GetStats());                        
                livrosSalvos.push_back(livro);                
            }
            Usuario* user = new Usuario(value[0],value[1],static_cast<EPerfil>(stoi(value[2])));
            user->_meusLivros = livrosSalvos;
            usuariosSalvos.push_back(user);
          }
          value.clear();
        }
        arq.close();
    }   
    return usuariosSalvos;
}

bool User::GetStatusUser(){
    return _active;
}

string User::GetMatricula(){
  return _matricula;
}

