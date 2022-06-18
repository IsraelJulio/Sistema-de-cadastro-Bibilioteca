using namespace std;
#include <iostream>
#include <vector>
#include "Livro.h"
#include "User.h"
#include "Operacoes.h"

#include <iterator>

int main() {

    vector<Livro> livrosSalvos = Livro::CarregarLivrosSalvos();
    
    for (auto livro : livrosSalvos)
    {
         livro.Imprime();
    }
    // string a = "4,Fundamentos da Quimica,2,A,";
    // vector<string> y;
    // Operacoes::split(a.begin(),a.end(),',', back_inserter(y));
    // cout << y[3] << endl << y[1];
    return 0;
}