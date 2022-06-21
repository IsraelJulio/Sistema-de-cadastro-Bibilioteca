using namespace std;


#include "Livro.h"
#include "User.h"
#include "Operacoes.h"



int main() {

    vector<Livro*> livrosSalvos = Livro::CarregarLivrosSalvos();
    
    for (auto livro : livrosSalvos)
    {
         livro->Imprime();
    }
    
    vector<User*> usersSalvos = User::CarregarUsuarios();

    for(auto u : usersSalvos)
    {
        u->Imprime();
    }


    return 0;
}