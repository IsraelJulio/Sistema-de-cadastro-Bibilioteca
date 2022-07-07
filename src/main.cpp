#include "../include/Livro.h"
#include "../include/User.h"
#include "../include/Operacoes.h"
#include "../include/Administrador.h"

using namespace std;

int main() {

    // vector<Livro*> livrosSalvos = Livro::CarregarLivrosSalvos();
    
    // for (auto livro : livrosSalvos)
    // {
    //      livro->Imprime();
    // } 
     
    vector<User*> usersSalvos = User::GetAllUsers();

    for(auto u : usersSalvos)
    {
        u->Imprime();
    }
    cout << endl << endl;


    // Administrador admin = Administrador("novo admin","0000001",EPerfil::ADMIN);     
    // admin.SetUsuario(&admin);
    // usersSalvos = User::GetAllUsers();

    // for(auto u : usersSalvos)
    // {
    //     u->Imprime();
    // }
    // cout << endl << endl;


    // Usuario novo = Usuario("novo usuario comum 2", "000000002", EPerfil::USER);
    // admin.SetUsuario(&novo);
     

    // usersSalvos = User::GetAllUsers();

    // for(auto u : usersSalvos)
    // {
    //     u->Imprime();
    // }
    // cout << endl << endl;


    return 0;
}