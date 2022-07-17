#include "../include/User.hpp"
#include "../include/Usuario.hpp"
#include "../include/Administrador.hpp"
#include"../include/Operacoes.hpp"
#include<fstream>
#include <iterator>
#include <algorithm>
/**
 * @brief Construct a new User:: User object
 * 
 * @param nome 
 * @param matricula 
 * @param perfil 
 * @param active 
 * @author Israel
 */
User::User(string nome, string matricula, EPerfil perfil, bool active){
    _nome = nome;
    _matricula = matricula;
    _perfil = perfil;
    _active = active;
}
/**
 * @brief Construct a new User:: User object
 * 
 * @param nome 
 * @param matricula 
 * @param perfil 
 * @author Israel
 */
User::User(string nome, string matricula, EPerfil perfil){
    _nome = nome;
    _matricula = matricula;
    _perfil = perfil;
    _active = true;

}
/**
 * @brief Pegar usuarios bloqueados
 * 
 * @return vector<User*> 
 */
vector<User*> User::GetBlockUsers(){
vector<User*> usuariosSalvos = GetAllUsers();
vector<User*>  result;

    copy_if(usuariosSalvos.begin(), usuariosSalvos.end(), std::back_inserter(result), [](User* i) {
      
        return !i->_active;
    });
return result;
}
/**
 * @brief Pegar todos os usuarios
 * 
 * @return vector<User*> 
 */
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
          if (stoi(value[2]) == 1)
          { 
            Administrador* admin = new Administrador(value[0],value[1],EPerfil::ADMIN,stoi(value[3])==1);
            usuariosSalvos.push_back(admin);
          } else {
            for (long unsigned int o = 4; o < value.size(); o++)
            {
                auto lv = Livro::GetById(stoi(value[o]));
                Livro* livro = new Livro(lv->GetId(),lv->GetName(), lv->GetGenre(),lv->GetStats());                        
                livrosSalvos.push_back(livro);                
            }
            Usuario* user = new Usuario(value[0],value[1],EPerfil::USER,stoi(value[3])==1);
            user->_meusLivros = livrosSalvos;
            usuariosSalvos.push_back(user);
          }
          livrosSalvos.clear();
          value.clear();
        }
        arq.close();
    }   
    return usuariosSalvos;
}

/**
 * @brief Pegar o status do usuario
 * 
 * @return string 
 */
string User::GetStatusUser(){
    return _active == true? "1" : "0";
}
/**
 * @brief retorna a matricula do usuario
 * 
 * @return string 
 */
string User::GetMatricula(){
  return _matricula;
}
/**
 * @brief retorna o nome do usuario
 * 
 * @return string 
 */
string User::GetNome()
{
    return _nome;
}
/**
 * @brief retorna o perfil do usuario
 * 
 * @return int 
 */
int User::GetPerfil()
{
  return _perfil == EPerfil::ADMIN ? 0 : 1;
}

