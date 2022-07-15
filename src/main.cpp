#include "../include/Livro.hpp"
#include "../include/User.hpp"
#include "../include/Operacoes.hpp"
#include "../include/Administrador.hpp"

using namespace std;

int main() {

//  vector<User*> usersSalvos = User::GetAllUsers();

//     for(auto u : usersSalvos)
//     {
//         u->Imprime();
//     }
//     cout << endl << endl;
     Administrador admin = Administrador("novo admin","0000001",EPerfil::ADMIN);     
    
//     Usuario novo = Usuario("Hulk", "46", EPerfil::USER);

    admin.SetBloqueio("46");
//    admin.SetUsuario(&novo);
//     admin.SetLivro("Hobt",EGenero::AVENTURA);
//     admin.SetLivroByUsuario(8,"46");

// auto usersSalvos = User::GetAllUsers();

//     for(auto u : usersSalvos)
//     {
//         u->Imprime();
//     }
//     cout << endl << endl;




    return 0;
}