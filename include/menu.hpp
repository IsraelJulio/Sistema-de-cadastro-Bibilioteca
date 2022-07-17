#ifndef MENU_H
#define MENU_H

#include<iostream>
#include<vector>
using namespace std;

class menu
{
private:
    bool _telaprincipal;
public:
    
    bool GetTelaPrincipal();
    void SetTelaPrincipal(bool value);
    bool GetUsuario(string matricula);
    void Titulo();
    void LimparTela();
    void SaltarLinhas(int num);
    bool TelaPrincipal();
    bool Run();
    bool UsuarioComum(bool force=false);
    bool Navegacao(string input);
    

};




#endif