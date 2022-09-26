// biblioteca de funções, implementações
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LSE.h"
int main()
{

    // cria a Agenda de Contatos
    LSE *agenda = criaListaLSE();

    //menu(agenda);
    menu2(agenda);
}