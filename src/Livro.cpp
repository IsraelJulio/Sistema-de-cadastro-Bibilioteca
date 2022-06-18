#include "Livro.h"
#include"Operacoes.h"
#include<fstream>
#include <iterator>

Livro::Livro(int id, string nome, EGenero genero, bool active){
    _id = id;
    _nome = nome;
    _genero = genero;
    _active = active;
}
int Livro::GetId(){
    return _id;
}
vector<Livro> Livro::CarregarLivrosSalvos(){
    vector<Livro> livrosSalvos;
    vector<string> value;
    string conteudo = "";
    ifstream arq("Livros.txt");

    if (arq.is_open())
    {
        while (getline(arq, conteudo)){            
            Operacoes::split(conteudo.begin(),conteudo.end(),',', back_inserter(value));     
            Livro livro = Livro(stoi(value[0]),value[1], static_cast<EGenero>(stoi(value[2])),value[3] == "A");
            livrosSalvos.push_back(livro);
            value.clear();
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

Livro Livro::GetById(int id){
    vector<Livro> livrosSalvos = Livro::CarregarLivrosSalvos();
    for(auto it = livrosSalvos.begin(); it <= livrosSalvos.end(); ++it) {
        if(it->GetId() == id) {
            return *it;       
        }
    }
    Livro t = Livro(0,"",EGenero::AVENTURA,false);
    return t;
}