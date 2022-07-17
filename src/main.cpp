#include "../include/Livro.hpp"
#include "../include/User.hpp"
#include "../include/Operacoes.hpp"
#include "../include/Administrador.hpp"
#include "../include/menu.hpp"
#include "../include/Opcoes.hpp"

using namespace std;

int main() {

    menu* m = new menu();
    m->LimparTela();
    m->Titulo();
    bool run = true;
    while(run)
    {
        if(!m->Run())
        { 
            m->LimparTela();
            
            if(!m->GetTelaPrincipal())
                m->TelaPrincipal();
            if(m->GetTelaPrincipal())
                run = Opcoes::OpcoesEncerrar();
            m->LimparTela();
        }
    }






    return 0;
}