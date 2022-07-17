#include "../include/Livro.hpp"
#include"../include/Operacoes.hpp"
#include<fstream>
#include <iterator>
/**
 * @brief Construct a new Livro:: Livro object
 * 
 * @param id 
 * @param nome 
 * @param genero 
 * @param active 
 */
Livro::Livro(int id, string nome, EGenero genero, bool active){
    _id = id;
    _nome = nome;
    _genero = genero;
    _active = active;
}
/**
 * @brief Pegar Id
 * 
 * @return int 
 */
int Livro::GetId(){
    return _id;
}
/**
 * @brief Pegar Nome
 * 
 * @return string 
 */
string Livro::GetName(){
    return _nome;
}
/**
 * @brief Pegar Genero
 * 
 * @return EGenero 
 */
EGenero Livro::GetGenre(){
    return _genero;
}
/**
 * @brief Pegar Status
 * 
 * @return true 
 * @return false 
 */
bool Livro::GetStats(){
    return _active == true? "1" : "0";
}
/**
 * @brief Função para carregar todos os livros salvos
 * 
 * @return vector<Livro*> 
 */
vector<Livro*> Livro::CarregarLivrosSalvos(){
    vector<Livro*> livrosSalvos;
    vector<string> value;
    string conteudo = "";
    ifstream arq("Livros.txt");

    if (arq.is_open())
    {
        while (getline(arq, conteudo)){            
            Operacoes::split(conteudo.begin(),conteudo.end(),',', back_inserter(value));     
            Livro* livro = new Livro(stoi(value[0]),value[1], static_cast<EGenero>(stoi(value[2])),stoi(value[3])==1);
            livrosSalvos.push_back(livro);
            value.clear();
        }
    }   
    return livrosSalvos;
}
/**
 * @brief Função para imprimir os dados dos usuarios
 * 
 */
void Livro::Imprime(){
    cout << _id << " - " << _nome << " | " << GetEnum(_genero) << endl;
}
/**
 * @brief Função para retornar o nome de um determinado Enum
 * 
 * @param EnumId 
 * @return string 
 */
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
    
        case EGenero::OUTROS:
            result =  "Outros";
            break;

        default:
            break;
    }
    return result;
}
/**
 * @brief Pega o livro pelo seu ID
 * 
 * @param id 
 * @return Livro* 
 */
Livro* Livro::GetById(int id){
    vector<Livro*> livrosSalvos = Livro::CarregarLivrosSalvos();
    for(auto it : livrosSalvos) {
        if(it->GetId() == id) {
            return it;       
        }
    }
    Livro* t = new Livro(0,"",EGenero::AVENTURA,false);
    return t;
}