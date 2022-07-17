#include "Usuario.hpp"
#include"../include/Operacoes.hpp"
#include <iostream>
#include<fstream>
#include <iterator>
#include <algorithm>
/**
 * @brief Construct a new Usuario:: Usuario object
 * 
 * @param nome 
 * @param matricula 
 * @param perfil 
 * @author Israel
 */
Usuario::Usuario(string nome, string matricula, EPerfil perfil): User(nome,matricula,perfil){}
/**
 * @brief Construct a new Usuario:: Usuario object
 * 
 * @param nome 
 * @param matricula 
 * @param perfil 
 * @param stats 
 * @author Israel
 */
Usuario::Usuario(string nome, string matricula, EPerfil perfil,bool stats): User(nome,matricula,perfil,stats){}
/**
 * @brief Construct a new Usuario:: Usuario object
 * 
 * @param nome 
 * @param matricula 
 * @param perfil 
 * @param livros 
 * @author Israel
 */
Usuario::Usuario(string nome, string matricula, EPerfil perfil,vector<Livro*> livros): User(nome,matricula,perfil){
    _meusLivros = livros;
}
/**
 * @brief Imprime na tela os dados do usuario
 * 
 */
void Usuario::Imprime(){
    cout <<endl <<  "Perfil: USUARIO \nNome: " << _nome << "\nMATRICULA: " << _matricula  << endl;
    if(_meusLivros.size() != 0)
    {
        cout << "Livros Reservados: " << endl;

        for(auto lv : _meusLivros)
        {
            lv->Imprime();
        }
    }

    return;
}
/**
 * @brief retorna os dados do usuario
 * 
 * @return string 
 */
string Usuario::GetDados(){
    return this->_nome + "," + this->_matricula + ",2," + this->GetStatusUser() + GetMyBooks();    
}

/**
 * @brief Retorna uma string coms os Ids dos livros do usuario
 * 
 * @return string 
 */
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

/**
 * @brief Pega o usuario pela matricula
 * 
 * @param matricula 
 * @return User* 
 */
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
