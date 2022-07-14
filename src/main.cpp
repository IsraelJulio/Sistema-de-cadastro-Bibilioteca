#include "../include/Livro.hpp"
#include "../include/User.hpp"
#include "../include/Operacoes.hpp"
#include "../include/Administrador.hpp"

using namespace std;

int main() {

 vector<User*> usersSalvos = User::GetAllUsers();

    for(auto u : usersSalvos)
    {
        u->Imprime();
    }
    cout << endl << endl;
    Administrador admin = Administrador("novo admin","0000001",EPerfil::ADMIN);     
    
    // Usuario novo = Usuario("novo usuario comum 2", "000000002", EPerfil::USER);


   
    admin.Devolucao("000000002",4);
     

usersSalvos = User::GetAllUsers();

    for(auto u : usersSalvos)
    {
        u->Imprime();
    }
    cout << endl << endl;



    return 0;
}