#include "../include/Administrador.hpp"
#include"../include/Operacoes.hpp"
#include <iostream>
#include <fstream>


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

bool Administrador::SetUsuario(User* Usuario){

    _usuariosAtivos = User::GetAllUsers();
    for(std::vector<User*>::iterator it = _usuariosAtivos.begin(); it != _usuariosAtivos.end(); it++){
        if((*it)->GetMatricula() == Usuario->GetMatricula()) return false;
    }
    _usuariosAtivos.push_back(Usuario);
    bool result = Administrador::AtualizarListaDeUsuarios(_usuariosAtivos);
    return result;

}

bool Administrador::removerUsuario(string matricula, vector<User *> list)
{
  for(std::vector<User*>::iterator it = _usuariosAtivos.begin(); it != _usuariosAtivos.end(); it++){
        if((*it)->GetMatricula() == matricula) return false;
    }
    return true;
}

bool Administrador::SetLivro(int id, string nome, EGenero genero){return true;}

bool Administrador::SetLivroByUsuario(int id, string matricula)
{
    vector<User*> usuariosSalvos;
    vector<Livro*> livrosSalvos;
    ifstream arq("Usuarios_bkp.txt");
    string conteudo = "";
    vector<string> value;
    vector<string> livros;
    bool eq = false;

    if(!validarMatricula(matricula))
        return false; // todo exceção;
    if(!validarLivro(id))
        return false; // todo exceção;
    auto _id = Livro::GetById(id);
    
     if (arq.is_open())
    {
        while (getline(arq, conteudo)){
            Operacoes::split(conteudo.begin(),conteudo.end(),',', back_inserter(value));
cout<< endl << "é isso: (";
cout << value[2];
cout << ")"<< endl << endl;
          if (stoi(value[2]) != 2)
          {
            Administrador* admin = new Administrador(value[0],value[1],static_cast<EPerfil>(stoi(value[2])));
            usuariosSalvos.push_back(admin);
          } else {
            if (value[1] == matricula)
            {
                for (long unsigned int o = 3; o < value.size(); o++)
                {        
                    if(stoi(value[o]) == id)            
                        eq = true; 
                    
                    auto lv = Livro::GetById(stoi(value[o]));
                Livro* livro = new Livro(lv->GetId(),lv->GetName(), lv->GetGenre(),lv->GetStats());                        
                livrosSalvos.push_back(livro); 
                }
                if(!eq)
                    livrosSalvos.push_back(_id);                    
            }    

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
        AtualizarListaDeUsuarios(usuariosSalvos);
    }
    return true;
}

bool Administrador::validarMatricula(string matricula)
{
    _usuariosAtivos = User::GetAllUsers();
     for(std::vector<User*>::iterator it = _usuariosAtivos.begin(); it != _usuariosAtivos.end(); it++){ // validar matricula
        if((*it)->GetMatricula() == matricula) return true;
    }
    return false;
}

bool Administrador::validarLivro(int id)
{
    auto livros = Livro::CarregarLivrosSalvos();
     for(std::vector<Livro*>::iterator it = livros.begin(); it != livros.end(); it++){ // validar matricula
        if((*it)->GetId() == id) return true;
    }
    return false;
}


bool EditarUsuario(string matricula){return true;}

bool Administrador::AtualizarListaDeUsuarios(vector<User *> list){

ofstream myfile ("Usuarios.txt");
 if (myfile.is_open())
  {

    for( auto u : list )
    {
        myfile << u->GetDados() << endl;
    }
    myfile.close();
  }
  else { cout << "chamou retorna" ;return false;}

  this->Updatebkp();
  return true;

}

string Administrador::GetDados(){
    return this->_nome + "," + this->_matricula + ",1";    
}

void Administrador::Updatebkp()
{
    ifstream  src("Usuarios.txt", std::ios::binary);
    ofstream  dst("Usuarios_bkp.txt",   std::ios::binary);
    dst << src.rdbuf();
}