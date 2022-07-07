#include "../include/Livro.h"
#include "../include/User.h"
#include "../include/Operacoes.h"

using namespace std;

int main() {

    vector<Livro*> livrosSalvos = Livro::CarregarLivrosSalvos();
    
    for (auto livro : livrosSalvos)
    {
         livro->Imprime();
    } 
     
    vector<User*> usersSalvos = User::GetAllUsers();

    for(auto u : usersSalvos)
    {
        u->Imprime();
    }

    return 0;
}