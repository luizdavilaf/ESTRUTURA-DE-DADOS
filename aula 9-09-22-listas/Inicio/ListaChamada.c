#include <stdio.h>
#include <stdlib.h>
#include "LSE.h"

int menu(LSE *ls);

int main(){

    //cria a lista de alunos de matemática 
    LSE *ListaMatematica = criaListaLSE();

    //cria o elemento de LSE chamado pedro
    
    Aluno *jocao = cadastraAluno("Jocao",20,1123302);
    Aluno *luiz = cadastraAluno("Luiz",21,1123303);
    //mostraAluno(luiz);
    Aluno *pedro = cadastraAluno("Pedro",44,1123301);
    Aluno pedro2 = *pedro; //passar apenas os dados de pedro
    insereNoFim(ListaMatematica, &pedro2); 

    insereNoInicio(ListaMatematica, pedro);
    insereNoFim(ListaMatematica, jocao);
    
    insereNoFim(ListaMatematica, luiz);
    
    
   
    mostraLista(ListaMatematica);
}