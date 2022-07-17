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
    std::vector<string> opAdm = { "0", "1", "2" , "3", "4", "5", "6", "9" };
    this->SetTelaPrincipal(true);

    bool skip = false;
    bool voltarOpUsuario = false;
    bool voltarOpAdm = false;

    Opcoes::OpcoesLogin();

    cin >> resposta;
    
    if(resposta == "9")
        return false;

    if(std::find(principal.begin(), principal.end(), resposta) == principal.end()){
        LimparTela();
        Opcoes::OpcaoInvalida();
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
            if(Administrador::validarMatricula(matricula,1))                
                skip = true;
            else
                Opcoes::OpcaoInvalida();    
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

                LimparTela();
                if(resposta == "9")
                return false;

                if(std::find(comum.begin(), comum.end(), resposta) != comum.end())
                    skip = true;
                else
                    Opcoes::OpcaoInvalida();

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
    {
        while(skip != true)
        {
            Opcoes::OPcoesMatricula();
            cin >> matricula;
            if(matricula == "9")
            return false;
            LimparTela();            
            if(Administrador::validarMatricula(matricula,0))                
                skip = true;
            else
                Opcoes::OpcaoInvalida();   
        }
        skip = false;
        auto u = Usuario::GetUserByMatricula(matricula);
        Administrador* _adm = new Administrador(u->GetNome(),u->GetMatricula(),EPerfil::ADMIN); 

        while(!voltarOpAdm)
        {
            while(skip != true)
            {
                Opcoes::OpcoesAdm(u->GetNome());
                cin >> resposta;

                LimparTela();
                if(resposta == "9")
                return false;

                if(std::find(opAdm.begin(), opAdm.end(), resposta) != opAdm.end())
                    skip = true;
                else
                    Opcoes::OpcaoInvalida();
            }
            skip = false;
            if(resposta == "0")
            {
                string nome = "";
                while(skip != true)
                {
                    Opcoes::OpcaoSelecionada("Cadastrar Livro!"); 
                    Opcoes::OpcaoLivroNome();
                    cin.ignore();
                    std::getline (std::cin,nome);
           
                    Opcoes::OpcaoLivroGenero();
                    cin >> resposta;

                    LimparTela();
                    if(resposta == "9")
                    return false;

                    if(std::find(opAdm.begin(), opAdm.end(), resposta) != opAdm.end())
                        skip = true;
                    else
                        Opcoes::OpcaoInvalida();
                }
                skip = false;

                if(_adm->SetLivro(nome,static_cast<EGenero>(stoi(resposta))))
                    Opcoes::CadastroSucesso();
                else
                    Opcoes::CadastroFalha();
                
                
            } 
            if(resposta== "1")
            {
                Opcoes::OpcaoSelecionada("Carregar Livros Salvos");
                vector<Livro*> livros = Livro::CarregarLivrosSalvos();                   

                for(auto livro : livros)
                {
                        livro->Imprime();
                }

                voltarOpAdm = Opcoes::VoltarUsuario();

                if(voltarOpAdm)
                    return false;
                LimparTela();
            }
            if(resposta == "2")
            {
                Opcoes::OpcaoSelecionada("Visualizar Todos os Usuarios!");
                auto allUsers = User::GetAllUsers(); 

                for(auto user : allUsers)
                {
                    user->Imprime();
                }

                voltarOpAdm = Opcoes::VoltarUsuario();

                if(voltarOpAdm)
                    return false;
                LimparTela();
            }
            if(resposta == "3")
            {
                Opcoes::OpcaoSelecionada("Visualizar Usuarios Bloqueados!");
                auto blockUsers = User::GetBlockUsers(); 
                 for(auto user : blockUsers)
                {
                    user->Imprime();
                }

                voltarOpAdm = Opcoes::VoltarUsuario();

                if(voltarOpAdm)
                    return false;
                LimparTela();
            }
        }
    }
        

    return true;
}

bool menu::Run(){

    if(!TelaPrincipal())
        return false;
        
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