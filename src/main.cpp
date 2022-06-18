using namespace std;
#include <iostream>
#include <vector>
#include "Livro.h"
#include "User.h"

int main() {

    vector<Livro> livrosSalvos = Livro::CarregarLivrosSalvos();
    
    for (auto livro : livrosSalvos)
    {
         livro.Imprime();
    }

    return 0;
}