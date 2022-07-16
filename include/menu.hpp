#ifndef MENU_H
#define MENU_H

#include<iostream>
#include<vector>
using namespace std;

class menu
{
private:
public:
    
    bool GetUsuario();
    void Titulo();
    void LimparTela();
    void SaltarLinhas(int num);
    bool TelaPrincipal();
    bool Run();
    bool Admin();
    bool UsuarioComun();
    bool Navegacao(string input);

};




#endif