//biblioteca de funções, implementações
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LSE.h"

LSE* criaListaLSE(){
    """Aloca memória para uma nova lista"""; 
    LSE *nova = (LSE*)malloc(sizeof(LSE));  
    nova->primeiro = NULL;
    nova->n_elementos = 0;
    return nova;
}

Aluno* cadastraAluno(char nome[20],int idade, int matricula){
    """Aloca memória para um novo Elemento (aluno)""";
    Aluno *novoAluno = (Aluno*)malloc(sizeof(Aluno));
    strcpy(novoAluno->nome,nome);
    novoAluno->idade = idade;
    novoAluno->matricula = matricula;
    novoAluno->proximo = NULL;
    return novoAluno;
}

Aluno* lerAluno(){
}

void insereNoInicio(LSE *ls, Aluno *novo){
}

void insereNoFim(LSE *ls, Aluno *novo){
}

void insereNaPosicao(LSE *ls, Aluno *novo, int pos){
}


Aluno* removeNoInicio(LSE *ls){
    Aluno *aux = ls->primeiro;
    if(aux==NULL){
        printf("LISTA VAZIA");
    }else{
        ls->primeiro=aux->proximo;
        ls->n_elementos--;
    }
    return aux;

}

Aluno* removeNoFim(LSE *ls){
    """Remove e retorna o último elemento da lista""";
}

Aluno* removeNaPosicao(LSE *ls, int pos){
    """Remove e retorna o elemento da lista na posição indicada""";
}

int retornaQuantidade(LSE *ls){
    """Retorna a quantidade de Elementos da Lista """;
    return ls->n_elementos;
}

void mostraLista(LSE *ls){
}

void mostraAluno(Aluno *novo){
    """Mostra os dados de um Elemento Aluno""";
    printf("\n\t Nome:%s",novo->nome);
    printf("\t Idade:%d",novo->idade);
    printf("\t Matricula:%d",novo->matricula);
}

void mostraPosicao(LSE *ls, int pos);

void apagaLista(LSE *ls){
}

void apagaAluno(Aluno *novo){
    """Apaga um elemento de Lista""";
    printf("\n Aluno Apagado!");
    mostraAluno(novo);
    free(novo);
}