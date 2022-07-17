#include "../include/Administrador.hpp"
#include"../include/Operacoes.hpp"
#include"../include/Opcoes.hpp"
#include <iostream>
#include <fstream>
#include <typeinfo>

/**
 * @brief Construct a new Administrador:: Administrador object
 * 
 * @param nome 
 * @param matricula 
 * @param perfil 
 * @author Israel Julio
 * @since 17-07-2022
 */


Administrador::Administrador(string nome, string matricula, EPerfil perfil): User(nome,matricula,perfil){}
Administrador::Administrador(string nome, string matricula, EPerfil perfil,bool active): User(nome,matricula,perfil,active){}

/**
 * @brief Função para imprimir os dados do administrador
 * 
 */
void Administrador::Imprime(){
    cout <<endl <<  "Perfil: ADMINISTRADOR \nNome: " << _nome << "\nMATRICULA: " << _matricula  << endl;
    return;
}

/**
 * @brief Função Para Listar Livros Bloqueados
 * 
 * @param livrosSalvos 
 * @return vector<Livro*> 
 */
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

/**
 * @brief Função para listar Usuarios Ativos
 * 
 * @param usuarios 
 * @return vector<User*> 
 */
vector<User*> Administrador::ListarUsuariosAtivos(vector<User*> usuarios){

    for(std::vector<User*>::iterator it = usuarios.begin(); it != usuarios.end(); it++){
        if((*it)->GetStatusUser() == "1"){
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

/**
 * @brief Função para criar Usuario
 * 
 * @param Usuario 
 * @return true 
 * @return false 
 */
bool Administrador::SetUsuario(User* Usuario){

    _usuariosAtivos = User::GetAllUsers();
    for(std::vector<User*>::iterator it = _usuariosAtivos.begin(); it != _usuariosAtivos.end(); it++){
        if((*it)->GetMatricula() == Usuario->GetMatricula()) return false;
    }
    _usuariosAtivos.push_back(Usuario);
    bool result = Administrador::AtualizarListaDeUsuarios(_usuariosAtivos);
    return result;

}

/**
 * @brief Função para remover um usuario
 * 
 * @param matricula 
 * @param list 
 * @return true 
 * @return false 
 */
bool Administrador::removerUsuario(string matricula, vector<User *> list)
{
  for(std::vector<User*>::iterator it = _usuariosAtivos.begin(); it != _usuariosAtivos.end(); it++){
        if((*it)->GetMatricula() == matricula) return false;
    }
    return true;
}

/**
 * @brief Função para criar um livro
 * 
 * @param nome 
 * @param genero 
 * @return true 
 * @return false 
 */
bool Administrador::SetLivro(string nome, EGenero genero)
{
    nome = Operacoes::contencao(nome);
    auto livros = Livro::CarregarLivrosSalvos();
    int id = livros.back()->GetId();
    Livro* novo = new Livro(id+1,nome,genero,true);
    livros.push_back(novo);
    ofstream livro_txt("Livros.txt");
    if(livro_txt.is_open())
    {
        for(auto livro : livros)
        {
            livro_txt << livro->GetId()<< "," << livro->GetName() << "," << static_cast<int>(livro->GetGenre()) << "," << livro->GetStats() << endl;            
        }
    }else return false;
    livro_txt.close();
    return true;
}

/**
 * @brief Função para validar se a matriicula existe no banco
 * 
 * @param matricula 
 * @return true 
 * @return false 
 */
bool Administrador::validarUsuario(string matricula)
{
    auto checkList = GetBlockUsers();
    for(auto user : checkList)
    {
        if(user->GetMatricula() == matricula){
            Opcoes::UsuarioBloqueado();
            return false;
        }
    }
    return true;
}

/**
 * @brief Função para associar um livro a um usuario
 * 
 * @param id 
 * @param matricula 
 * @return true 
 * @return false 
 */
bool Administrador::SetLivroByUsuario(int id, string matricula)
{
    matricula = Operacoes::contencao(matricula);
    vector<User*> usuariosSalvos = User::GetAllUsers();
    vector<Livro*> livrosSalvos;
    ifstream arq("Usuarios.txt");
    string conteudo = "";
    vector<string> value;
    string livros ="";
    bool eq = false;
    ofstream beckup ("Usuarios_bkp.txt", std::ofstream::trunc);
    string _id = to_string(id);

    if(!validarUsuario(matricula))
        return false; 
            
     if (arq.is_open())
    {
        if (beckup.is_open())
         {
            while (getline(arq, conteudo)){
                Operacoes::split(conteudo.begin(),conteudo.end(),',', back_inserter(value));
            if (stoi(value[2]) != 2)
                beckup << value[0] <<"," << value[1] <<"," << value[2]<<"," << value[3]<<endl;
            else 
            {
                if (value[1] == matricula)
                {                        
                    for (long unsigned int o = 4; o < value.size(); o++)
                    {
                        if(stoi(value[o]) == id) {

                            eq = true; 
                        }           
                    livros += "," + value[o]; 
                    }
                    if(!eq){
                        livros += "," +_id;                        
                    }
                }else
                    {

                        for (long unsigned int o = 4; o < value.size(); o++)
                        {
                            livros += "," + value[o]; 
             
                        }
                        
                    }
                beckup << value[0] <<"," << value[1] <<",2," << value[3]<<  livros << endl;
                livros = "";

            }
          value.clear();
            }
        }
        else
            Opcoes::CadastroSucesso();
        beckup.close();
    }
    else
        Opcoes::CadastroSucesso();
    arq.close();
    Updatesrc();    

    return true;
}

/**
 * @brief Função para validar a matricula relativa a um perfil
 * 
 * @param matricula 
 * @param perfil 
 * @return true 
 * @return false 
 */
bool Administrador::validarMatricula(string matricula, int perfil)
{
    auto usuariosAtivos = User::GetAllUsers();
     for(std::vector<User*>::iterator it = usuariosAtivos.begin(); it != usuariosAtivos.end(); it++){ // validar matricula
        if((*it)->GetMatricula() == matricula && (*it)->GetPerfil() == perfil)  return  true;
    }
    return false;
}

/**
 * @brief Função para validar se o id do livro existe no banco
 * 
 * @param id 
 * @return true 
 * @return false 
 */
bool Administrador::validarLivro(int id)
{
    auto livros = Livro::CarregarLivrosSalvos();
     for(std::vector<Livro*>::iterator it = livros.begin(); it != livros.end(); it++){ // validar matricula
        if((*it)->GetId() == id) return true;
    }
    return false;
}

/**
 * @brief Função para atulizar a lista de usuarios
 * 
 * @param list 
 * @return true 
 * @return false 
 */
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

/**
 * @brief Função para listar os dados de um determiado usuario
 * 
 * @return string 
 */
string Administrador::GetDados(){
    return this->_nome + "," + this->_matricula + ",1,"+ this->GetStatusUser();    
}

/**
 * @brief função que atualiza os bancos de dados
 * 
 */
void Administrador::Updatebkp()
{
    ifstream  src("Usuarios.txt", std::ios::binary);
    ofstream  dst("Usuarios_bkp.txt",   std::ios::binary);
    dst << src.rdbuf();
}

/**
 * @brief Função que atuyaliza os bancos de dados
 * 
 */
void Administrador::Updatesrc()
{
    ifstream  src("Usuarios_bkp.txt", std::ios::binary);
    ofstream  dst("Usuarios.txt",   std::ios::binary);
    dst << src.rdbuf();
}

/**
 * @brief Função para retirar um livro da lista de emprestimos de um determinado usuario
 * 
 * @param matricula 
 * @param id 
 * @return true 
 * @return false 
 */
bool Administrador::Devolucao(string matricula, int id)
{

    vector<User*> usuariosSalvos = User::GetAllUsers();
    vector<Livro*> livrosSalvos;
    ifstream arq("Usuarios.txt");
    string conteudo = "";
    vector<string> value;
    string livros ="";
    bool eq = false;

    ofstream beckup ("Usuarios_bkp.txt", std::ofstream::trunc);
    string _id = to_string(id);

    if(!validarMatricula(matricula,1))
        return false; // todo exceção;
    if(!validarLivro(id))
        return false; // todo exceção;
    
     if (arq.is_open())
    {
        if (beckup.is_open())
         {
            while (getline(arq, conteudo)){
                Operacoes::split(conteudo.begin(),conteudo.end(),',', back_inserter(value));
            if (stoi(value[2]) != 2)
                beckup << value[0] <<"," << value[1] <<"," << value[2]<<"," << value[3]<<endl;
            else 
            {
                if (value[1] == matricula)
                {                        
                    for (long unsigned int o = 4; o < value.size(); o++)
                    {
                        if(stoi(value[o]) == id)
                            eq = true; 
                        else                                  
                            livros += "," + value[o]; 
                    }
                    if(!eq){
                        return false; // Todo Exceção                        
                    }
                }else
                    {

                        for (long unsigned int o = 4; o < value.size(); o++)
                        {
                            livros += "," + value[o]; 
             
                        }
                        
                    }
                beckup << value[0] <<"," << value[1] <<",2," << value[3] <<  livros << endl;
                livros = "";

            }
          value.clear();
            }
        }
        beckup.close();
    }
    arq.close();
    Updatesrc();  
    return true;
}

/**
 * @brief Função para bloquear um usuario
 * 
 * @param matricula 
 * @param block 
 * @return true 
 * @return false 
 */
bool Administrador::SetBloqueio(string matricula, string block)
{
    matricula = Operacoes::contencao(matricula);
    vector<User*> usuariosSalvos = User::GetAllUsers();
    vector<Livro*> livrosSalvos;
    ifstream arq("Usuarios.txt");
    string conteudo = "";
    vector<string> value;
    string livros ="";
    ofstream beckup ("Usuarios_bkp.txt", std::ofstream::trunc);

    if(!validarMatricula(matricula,1))
        return false; // todo exceção;

     if (arq.is_open())
    {
        if (beckup.is_open())
         {
            while (getline(arq, conteudo)){
                Operacoes::split(conteudo.begin(),conteudo.end(),',', back_inserter(value));

            if ((stoi(value[2]) != 2) && value[1] != matricula)
                beckup << value[0] <<"," << value[1] <<"," << value[2]<<"," << value[3]<<endl;
            else if((stoi(value[2]) != 2))
                beckup << value[0] <<"," << value[1] <<"," << value[2]<<"," << value[3]<<endl;
                else if((stoi(value[2]) != 2) && value[1] == matricula)
                  beckup << value[0] <<"," << value[1] <<"," << value[2]<<",0"<<endl;  
                else{
                    if (value[1] == matricula)
                    {                        
                        for (long unsigned int o = 4; o < value.size(); o++)
                        {                                
                            livros += "," + value[o]; 
                        }
                        value[3] = block;
                    }else
                        {

                            for (long unsigned int o = 4; o < value.size(); o++)
                            {
                                livros += "," + value[o]; 
                
                            }
                            
                        }
                    beckup << value[0] <<"," << value[1] <<",2," << value[3] <<  livros << endl;
                    livros = "";

                }
          value.clear();
            }
        }
        beckup.close();
    }
    arq.close();
    Updatesrc();  
    return true;
}