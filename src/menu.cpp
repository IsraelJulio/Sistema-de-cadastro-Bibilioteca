#include "../include/menu.hpp"
#include "../include/Administrador.hpp"
#include "../include/Usuario.hpp"
#include "../include/Opcoes.hpp"
#include "../include/Operacoes.hpp"

#include <algorithm>
#include<stdio.h>
#include<string.h>

void menu::Titulo(){

cout<<" ██╗ ██╗  ██╗ ██╗  ██╗ ██╗  ██╗ ██╗  ██╗ ██╗  ██╗ ██╗  ██╗ ██╗  ██╗ ██╗  ██╗ ██╗  ██╗ ██╗  ██╗ ██╗  ██╗ ██╗  ██╗ ██╗  ██╗ ██╗  " << endl;
cout<<"████████╗████████╗████████╗████████╗████████╗████████╗████████╗████████╗████████╗████████╗████████╗████████╗████████╗████████╗ " << endl;
cout<<"╚██╔═██╔╝╚██╔═██╔╝╚██╔═██╔╝╚██╔═██╔╝╚██╔═██╔╝╚██╔═██╔╝╚██╔═██╔╝╚██╔═██╔╝╚██╔═██╔╝╚██╔═██╔╝╚██╔═██╔╝╚██╔═██╔╝╚██╔═██╔╝╚██╔═██╔╝ " << endl;
cout<<"████████╗████████╗████████╗████████╗████████╗████████╗████████╗████████╗████████╗████████╗████████╗████████╗████████╗████████╗ " << endl;
cout<<"╚██╔═██╔╝╚██╔═██╔╝╚██╔═██╔╝╚██╔═██╔╝╚██╔═██╔╝╚██╔═██╔╝╚██╔═██╔╝╚██╔═██╔╝╚██╔═██╔╝╚██╔═██╔╝╚██╔═██╔╝╚██╔═██╔╝╚██╔═██╔╝╚██╔═██╔╝ " << endl;
cout<<" ╚═╝ ╚═╝  ╚═╝ ╚═╝  ╚═╝ ╚═╝  ╚═╝ ╚═╝  ╚═╝ ╚═╝  ╚═╝ ╚═╝  ╚═╝ ╚═╝  ╚═╝ ╚═╝  ╚═╝ ╚═╝  ╚═╝ ╚═╝  ╚═╝ ╚═╝  ╚═╝ ╚═╝  ╚═╝ ╚═╝  ╚═╝ ╚═╝  " << endl;
cout<<" ██╗ ██╗     ███████╗██╗███████╗████████╗     ██████╗ █████╗ ██████╗  █████╗ ███████╗████████╗██████╗  ██████╗         ██╗ ██╗ " << endl;
cout<<"████████╗    ██╔════╝██║██╔════╝╚══██╔══╝    ██╔════╝██╔══██╗██╔══██╗██╔══██╗██╔════╝╚══██╔══╝██╔══██╗██╔═══██╗       ████████╗" << endl;
cout<<"╚██╔═██╔╝    ███████╗██║███████╗   ██║       ██║     ███████║██║  ██║███████║███████╗   ██║   ██████╔╝██║   ██║       ╚██╔═██╔╝" << endl;
cout<<"████████╗    ╚════██║██║╚════██║   ██║       ██║     ██╔══██║██║  ██║██╔══██║╚════██║   ██║   ██╔══██╗██║   ██║       ████████╗" << endl;
cout<<"╚██╔═██╔╝    ███████║██║███████║   ██║██╗    ╚██████╗██║  ██║██████╔╝██║  ██║███████║   ██║   ██║  ██║╚██████╔╝       ╚██╔═██╔╝" << endl;
cout<<" ╚═╝ ╚═╝     ╚══════╝╚═╝╚══════╝   ╚═╝╚═╝     ╚═════╝╚═╝  ╚═╝╚═════╝ ╚═╝  ╚═╝╚══════╝   ╚═╝   ╚═╝  ╚═╝ ╚═════╝         ╚═╝ ╚═╝ " << endl;
cout<<" ██╗ ██╗     ██████╗ ███████╗    ██████╗ ██╗██████╗ ██╗     ██╗ ██████╗ ████████╗███████╗ ██████╗ █████╗               ██╗ ██╗ " << endl;
cout<<"████████╗    ██╔══██╗██╔════╝    ██╔══██╗██║██╔══██╗██║     ██║██╔═══██╗╚══██╔══╝██╔════╝██╔════╝██╔══██╗             ████████╗" << endl;
cout<<"╚██╔═██╔╝    ██║  ██║█████╗      ██████╔╝██║██████╔╝██║     ██║██║   ██║   ██║   █████╗  ██║     ███████║             ╚██╔═██╔╝" << endl;
cout<<"████████╗    ██║  ██║██╔══╝      ██╔══██╗██║██╔══██╗██║     ██║██║   ██║   ██║   ██╔══╝  ██║     ██╔══██║             ████████╗" << endl;
cout<<"╚██╔═██╔╝    ██████╔╝███████╗    ██████╔╝██║██████╔╝███████╗██║╚██████╔╝   ██║   ███████╗╚██████╗██║  ██║             ╚██╔═██╔╝" << endl;
cout<<" ╚═╝ ╚═╝     ╚═════╝ ╚══════╝    ╚═════╝ ╚═╝╚═════╝ ╚══════╝╚═╝ ╚═════╝    ╚═╝   ╚══════╝ ╚═════╝╚═╝  ╚═╝              ╚═╝ ╚═╝ " << endl;
cout<<" ██╗ ██╗  ██╗ ██╗  ██╗ ██╗  ██╗ ██╗  ██╗ ██╗  ██╗ ██╗  ██╗ ██╗  ██╗ ██╗  ██╗ ██╗  ██╗ ██╗  ██╗ ██╗  ██╗ ██╗  ██╗ ██╗  ██╗ ██╗  " << endl;
cout<<"████████╗████████╗████████╗████████╗████████╗████████╗████████╗████████╗████████╗████████╗████████╗████████╗████████╗████████╗ " << endl;
cout<<"╚██╔═██╔╝╚██╔═██╔╝╚██╔═██╔╝╚██╔═██╔╝╚██╔═██╔╝╚██╔═██╔╝╚██╔═██╔╝╚██╔═██╔╝╚██╔═██╔╝╚██╔═██╔╝╚██╔═██╔╝╚██╔═██╔╝╚██╔═██╔╝╚██╔═██╔╝ " << endl;
cout<<"████████╗████████╗████████╗████████╗████████╗████████╗████████╗████████╗████████╗████████╗████████╗████████╗████████╗████████╗ " << endl;
cout<<"╚██╔═██╔╝╚██╔═██╔╝╚██╔═██╔╝╚██╔═██╔╝╚██╔═██╔╝╚██╔═██╔╝╚██╔═██╔╝╚██╔═██╔╝╚██╔═██╔╝╚██╔═██╔╝╚██╔═██╔╝╚██╔═██╔╝╚██╔═██╔╝╚██╔═██╔╝ " << endl;
cout<<" ╚═╝ ╚═╝  ╚═╝ ╚═╝  ╚═╝ ╚═╝  ╚═╝ ╚═╝  ╚═╝ ╚═╝  ╚═╝ ╚═╝  ╚═╝ ╚═╝  ╚═╝ ╚═╝  ╚═╝ ╚═╝  ╚═╝ ╚═╝  ╚═╝ ╚═╝  ╚═╝ ╚═╝  ╚═╝ ╚═╝  ╚═╝ ╚═╝" << endl;    
}

void menu::LimparTela()
{
     system("clear||cls");
     return;
}



bool menu::TelaPrincipal()
{
    string resposta="";
    string matricula = "";
    std::vector<string> principal = { "0", "1", "9" };
    std::vector<string> comum = { "0", "1", "9" };
    this->SetTelaPrincipal(true);

    bool skip = false;
    bool voltarOpUsuario = false;

    Opcoes::OpcoesLogin();

    cin >> resposta;
    
    if(resposta == "9")
        return false;

    if(std::find(principal.begin(), principal.end(), resposta) == principal.end()){
        LimparTela();
        cout << "*************opcao invalida*********************" << endl;
        TelaPrincipal();
    }
    LimparTela();
    this->SetTelaPrincipal(false);
    if(resposta == "1")
    {
        while(skip != true)
        {
            Opcoes::OPcoesMatricula();
            cin >> matricula;
            if(matricula == "9")
            return false;
            LimparTela();            
            if(Administrador::validarMatricula(matricula))                
                skip = true;
            else
                cout << "************* matricula invalida *********************" << endl;    
        }
        
        skip = false;
        auto u = Usuario::GetUserByMatricula(matricula);
        Usuario* _user = new Usuario(u->GetNome(),u->GetMatricula(),EPerfil::USER);  

       while (!voltarOpUsuario)
       {             
            while(skip != true)
            {
                Opcoes::OpcoesUsuario(u->GetNome());
                cin >> resposta;

                if(resposta == "9")
                return false;

                if(std::find(comum.begin(), comum.end(), resposta) != comum.end())
                    skip = true;

                LimparTela();
                cout << "************* opcao invalida *********************" << endl;

            }
            skip = false;
                if(resposta=="1")
                {
                    vector<Livro*> livros = Livro::CarregarLivrosSalvos();                   

                    for(auto livro : livros)
                    {
                            livro->Imprime();
                    }
                }
                else
                {
                    string livrosId = _user->GetMyBooks();
                    vector<string> ids;
                    Operacoes::split(livrosId.begin(),livrosId.end(),',', back_inserter(ids)); 

                    for(auto id : ids)
                    {
                        auto char_arr = &id[0];
                        if(strlen(char_arr) > 0)
                        {
                            auto livro = Livro::GetById(stoi(id));
                            livro->Imprime();
                        }
                    }
                }
                voltarOpUsuario = Opcoes::VoltarUsuario();

                if(voltarOpUsuario)
                    return false;
                LimparTela();
        }
        LimparTela();
    }

        
    else
        Admin();

    return true;
}

bool menu::Run(){

    if(!TelaPrincipal())
        return false;
        
    return true;
}

bool menu::Admin(){
    return true;
}

bool menu::GetTelaPrincipal()
{
    return _telaprincipal;
}
void menu::SetTelaPrincipal(bool value)
{
    _telaprincipal = value;
    return;
}