#ifndef Livro_H
#define Livro_H
#include<iostream>
#include<string>
#include<vector>

#include "EGenero.hpp"
using namespace std;

class Livro{
    private:
        int _id;
        string _nome;
        EGenero _genero;
        bool _active;
        
    public:
        Livro(int id, string nome, EGenero genero, bool active);
        static vector<Livro*> CarregarLivrosSalvos();
        void Imprime();
        string GetEnum(EGenero EnumId);
        static Livro* GetById(int id);
        int GetId();      
        string GetName();      
        EGenero GetGenre();  
        bool GetStats();    
};

#endif