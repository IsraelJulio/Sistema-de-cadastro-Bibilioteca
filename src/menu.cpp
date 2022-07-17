#include "../include/menu.hpp"
#include "../include/Administrador.hpp"
#include "../include/Usuario.hpp"
#include "../include/Opcoes.hpp"
#include "../include/Operacoes.hpp"

#include <algorithm>
#include<stdio.h>
#include<string.h>
/**
 * @brief Titulo da Aplicação
 * 
 */
void menu::Titulo()
{
    Opcoes::Titulo();
}

/**
 * @brief Limpesa do console
 * 
 */
void menu::LimparTela()
{
  system("clear||cls");
  return;
}


/**
 * @brief Açoes da tela principal
 * 
 * @return true 
 * @return false 
 */
bool menu::TelaPrincipal()
{
    string resposta="";
    string matricula = "";
    std::vector<string> principal = { "0", "1", "9" };
    std::vector<string> comum = { "0", "1", "9" };
    std::vector<string> opAdmMenu = { "0", "1", "2" , "3", "4", "5", "6", "7", "8", "9" };
    std::vector<string> opAdm = { "0", "1", "2" , "3", "4", "5", "6", "7", "9" };
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

                if(std::find(opAdmMenu.begin(), opAdmMenu.end(), resposta) != opAdmMenu.end())
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
            }
            if(resposta == "2")
            {
                Opcoes::OpcaoSelecionada("Visualizar Todos os Usuarios!");
                auto allUsers = User::GetAllUsers(); 

                for(auto user : allUsers)
                {
                    user->Imprime();
                }               
            }
            if(resposta == "3")
            {
                Opcoes::OpcaoSelecionada("Visualizar Usuarios Bloqueados!");
                auto blockUsers = User::GetBlockUsers(); 
                 for(auto user : blockUsers)
                {
                    user->Imprime();
                }
            }
            if(resposta == "4")
            {
                Opcoes::OpcaoSelecionada("Bloquear Usuario!");
                Opcoes::InformeMatricula();

                while(skip != true)
                {
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

                if(_adm->SetBloqueio(matricula,"0"))
                    Opcoes::CadastroSucesso();
                else
                    Opcoes::CadastroFalha();

            }
            if(resposta == "5")
            {
                int livroId = 0;
                while(skip != true)
                {
                    Opcoes::OpcaoSelecionada("Devolucao de Livros!");
                    Opcoes::InformeMatricula();
                    cin >> matricula;
                    if(matricula == "9")
                    return false;
                    LimparTela();            
                    if(_adm->validarMatricula(matricula,1))                
                        skip = true;
                    else
                        Opcoes::OpcaoInvalida();   
                }
                skip = false;
                
                while(skip != true)
                {
                    Opcoes::InformeLivroId();
                    cin >> resposta;                    
                    try
                    {
                        LimparTela();            
                        livroId = stoi(resposta);
                        if(_adm->validarLivro(livroId))                
                            skip = true;
                        else
                            Opcoes::OpcaoInvalida();
                    }
                    catch(const std::exception& e)
                    {
                        Opcoes::OpcaoInvalida();
                    }                   
                       
                }
                skip = false;

                if(_adm->Devolucao(matricula,livroId))
                    Opcoes::CadastroSucesso();
                else
                    Opcoes::DadosIncorretos();
            }
            if(resposta == "6")
            {
                while(skip != true)
                {
                    Opcoes::OpcaoSelecionada("Desbloquear Usuario!");
                    Opcoes::InformeMatricula();
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

                if(_adm->SetBloqueio(matricula,"1"))
                    Opcoes::CadastroSucesso();
                else
                    Opcoes::CadastroFalha();
            }
            if(resposta == "7")
            {
                int livroId = 0;
                while(skip != true)
                {
                    Opcoes::OpcaoSelecionada("Efetuar Emprestimo para usuario!");
                    Opcoes::InformeMatricula();
                    cin >> matricula;
                    if(matricula == "9")
                    return false;
                    LimparTela();            
                    if(_adm->validarMatricula(matricula,1))                
                        skip = true;
                    else
                        Opcoes::OpcaoInvalida();   
                }
                skip = false;
                
                while(skip != true)
                {
                    Opcoes::InformeLivroId();
                    cin >> resposta;                    
                    try
                    {
                        LimparTela();            
                        livroId = stoi(resposta);
                        if(_adm->validarLivro(livroId))                
                            skip = true;
                        else
                            Opcoes::OpcaoInvalida();
                    }
                    catch(const std::exception& e)
                    {
                        Opcoes::OpcaoInvalida();
                    }                  

                 }
                 skip = false;
                 if(_adm->SetLivroByUsuario(livroId,matricula))
                    Opcoes::CadastroSucesso();

            }
            if(resposta == "8")
            {
                Opcoes::OpcaoSelecionada("Cadastro de Usuario");
                string nome = "";
               
                while(skip != true)
                {    
                    Opcoes::InformeNome();
                    cin.ignore();
                    std::getline (std::cin,nome);
                    nome = Operacoes::contencao(nome);
                    Opcoes::InformeMatriculaC();
                    cin >> matricula;
                    matricula = Operacoes::contencao(matricula);
                    Opcoes::InformePerfil();
                    cin >> resposta;                                    
                    if(resposta == "9")
                    return false;
                    LimparTela();            
                    if(resposta == "0")     
                    {
                        if(_adm->SetUsuario(new Usuario(nome,matricula,EPerfil::USER))){
                            skip = true;
                         Opcoes::CadastroSucesso();
                        }
                            skip = true;
                    }
                     if(resposta == "1")     
                    {
                        if(_adm->SetUsuario(new Administrador(nome,matricula,EPerfil::ADMIN))){
                            skip = true;
                         Opcoes::CadastroSucesso();
                        }
                    }
                    if(std::find(comum.begin(), comum.end(), resposta) == comum.end())
                        Opcoes::OpcaoInvalida();   
                }
                skip = false;

            }
            skip = false;
            voltarOpAdm = Opcoes::VoltarUsuario();

                if(voltarOpAdm)
                    return false;
                LimparTela();
        }
    }
        

    return true;
}

/**
 * @brief Aplicação rodando
 * 
 * @return true 
 * @return false 
 */
bool menu::Run(){

    if(!TelaPrincipal())
        return false;
        
    return true;
}
/**
 * @brief Função para retorna se a aplicação esta na tela inicial
 * 
 * @return true 
 * @return false 
 */
bool menu::GetTelaPrincipal()
{
    return _telaprincipal;
}
/**
 * @brief Função para setar se a aplicação esta na tela inicial
 * 
 * @param value 
 */
void menu::SetTelaPrincipal(bool value)
{
    _telaprincipal = value;
    return;
}