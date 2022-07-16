#include "../include/Livro.hpp"
#include "../include/User.hpp"
#include "../include/Operacoes.hpp"
#include "../include/Administrador.hpp"
#include "../include/menu.hpp"

using namespace std;

int main() {

menu* m = new menu();
m->LimparTela();
m->Titulo();
while(m->Run());




    return 0;
}