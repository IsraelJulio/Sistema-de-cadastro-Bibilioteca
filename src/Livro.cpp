#include "Livro.h"
#include<fstream>
Livro::Livro(int id, string nome, EGenero genero, bool active){
    _id = id;
    _nome = nome;
    _genero = genero;
    _active = active;
}

vector<Livro*> Livro::CarregarLivrosSalvos(){
    vector<Livro*> livrosSalvos;
    string conteudo = "";
    ifstream arq("Livros.txt");
    string id,nome,genero,state = "";
    long unsigned int i =0;
    if (arq.is_open())
    {
        while (getline(arq, conteudo)){
            
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
                    state += conteudo[i] ;
                } else{
                    break;
                }
            }
            Livro* livro = new Livro(stoi(id),nome, static_cast<EGenero>(stoi(genero)),state == "A");
            livrosSalvos.push_back(livro);
            nome = "";
            genero = "";
            id = "";
            state = "";
        }
    }   
    return livrosSalvos;
}

void Livro::Imprime(){
    cout << _id << "- " << _nome << " | " << GetEnum(_genero) << endl;
}

string Livro::GetEnum(EGenero EnumId){
    string result = "";
    switch (EnumId)
    {
        case EGenero::CALCULO:
            result =  "Cálculo";
            break;
    
        case EGenero::GEOMETRIA:
            result =  "Geometria";
            break;
    
        case EGenero::QUIMICA:
            result =  "Quimica";
            break;
    
        case EGenero::FISICA:
            result =  "Física";
            break;
    
        case EGenero::FANTASIA:
            result =  "Fantasia";
            break;
    
        case EGenero::AVENTURA:
            result =  "Aventura";
            break;
    
        case EGenero::ROMANCE:
            result =  "Romance";
            break;

        default:
            break;
    }
    return result;
}