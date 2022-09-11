#include <stdio.h>
#include <stdlib.h>
#include "LSE.h"

int menu(LSE *ls);

int main(){

    //cria a lista de alunos de matemática 
    LSE *ListaMatematica = criaListaLSE();

    //cria o elemento de LSE chamado pedro
    Aluno *pedro = cadastraAluno("Pedro",44,1123301);

}