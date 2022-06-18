#include "User.h"
#include "Usuario.h"
#include "Administrador.h"
#include<fstream>

User::User(string nome, string matricula, EPerfil perfil){
    _nome = nome;
    _matricula = matricula;
    _perfil = perfil;
}

vector<User*> CarregarUsuarios(){
    vector<User*> usuariosSalvos;
    vector<Livro*> livrosSalvos;
    string conteudo = "";
    ifstream arq("Usuarios.txt");
    string nome,matricula,perfil = "";

    string id,genero,state = "";
    long unsigned int i =0;
    if (arq.is_open())
    {
        while (getline(arq, conteudo)){

            for ( i = i+1; i < conteudo.size(); i++)
            {
                if(conteudo[i] != ','){
                    nome += conteudo[i] ;
                } else{
                    break;
                }
            }
            for ( i = i+1; i < conteudo.size(); i++)
            {
                if(conteudo[i] != ','){
                    matricula += conteudo[i] ;
                } else{
                    break;
                }
            }
            for ( i = i+1; i < conteudo.size(); i++)
            {
                if(conteudo[i] != ',' || conteudo[i] != ';'){
                    perfil += conteudo[i] ;
                } else{
                    break;
                }
            }
            if(conteudo[i+1] != ';'){                  
                while (conteudo[i+1] != ';')
                {                
                    for ( i = 0; i < conteudo.size(); i++)
                    {
                        if(conteudo[i] != ','){
                            id += conteudo[i] ;
                        } else{
                            break;
                        }
                    }
                    for ( i = i+1; i < conteudo.size(); i++)
                    {
                        if(conteudo[i] != ','){
                            nome += conteudo[i] ;
                        } else{
                            break;
                        }
                    }
                    for ( i = i+1; i < conteudo.size(); i++)
                    {
                        if(conteudo[i] != ','){
                            genero += conteudo[i] ;
                        } else{
                            break;
                        }
                    }
                    for ( i = i+1; i < conteudo.size(); i++)
                    {
                        if(conteudo[i] != ','){
    
                         if(conteudo[i] != ','){
                            state += conteudo[i] ;
                        } else{
                            break;
                            }
                        }
                    
                    }
                    Livro* livro = new Livro(stoi(id),nome, static_cast<EGenero>(stoi(genero)),state == "A");                        
                    livrosSalvos.push_back(livro);
                }
                Usuario* user = new Usuario(nome,matricula,static_cast<EPerfil>(stoi(perfil)),livrosSalvos);
                usuariosSalvos.push_back(user);
            }
            else{
                Administrador* admin = new Administrador(nome,matricula,static_cast<EPerfil>(stoi(perfil)));
                usuariosSalvos.push_back(admin);
            }
            
            nome = "";
            genero = "";
            id = "";
            state = "";
            matricula = "";
            perfil = "";
        }
    }   
    return usuariosSalvos;
}