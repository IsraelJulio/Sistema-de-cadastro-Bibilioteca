#ifndef MENU_H
#define MENU_H

#include<iostream>
#include<vector>
using namespace std;

class menu
{
private:
public:
    
    bool GetUsuario(string matricula);
    void Titulo();
    void LimparTela();
    void SaltarLinhas(int num);
    bool TelaPrincipal();
    bool Run();
    bool Admin();
    bool UsuarioComum(bool force=false);
    bool Navegacao(string input);

};




#endif