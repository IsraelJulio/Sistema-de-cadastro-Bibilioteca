#ifndef Livro_H
#define Livro_H
#include<iostream>
#include<string>
#include<vector>

#include "EGenero.h"
using namespace std;

class Livro{
    private:
        int _id;
        string _nome;
        EGenero _genero;
        
    public:
        Livro(int id, string nome, EGenero genero);
        static vector<Livro*> CarregarLivrosSalvos();
        void Imprime();
        string GetEnum(EGenero EnumId);
        
};

#endif