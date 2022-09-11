#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>  
//Struct para definir pessoa

typedef struct pessoa{
    char nome [20];
    char cpf [14];    
}Pessoa;

//struct para definir data
typedef struct data{
    int dia,mes,ano;
}Data;

//struct para definir um apartamento
typedef struct apartamento{
    char bloco; //codigo do bloco
    int num; //numero apartamento
    int andar; //andar do apartamento
    int comodos; //quantidade de peças
    double vAluguel; //valor do aluguel
    double vCondominio; //valor do condominio
    int box; //número da garagem
    Pessoa *locatario; //locatário do apto
    Pessoa proprietario; //dono do apto
    Data dataLocacao; //data da locacao
    int status;
}Apto;

Data defineData(int dia, int mes, int ano){
//função criar uma data, retorna uma data
    Data novaData;
    novaData.dia=dia;
    novaData.mes=mes;
    novaData.ano=ano;
    return novaData;
}

void mostraData(Data dt){
//função para mostrar uma data, sem retorno
    printf(" %02d/%02d/%d", dt.dia,dt.mes,dt.ano);
}

Pessoa criaPessoa(char nome[20], char cpf[14]){
//função para criar uma pessoa, retorna uma pessoa
    Pessoa novaPessoa;
    strcpy(novaPessoa.nome, nome);
    strcpy(novaPessoa.cpf, cpf);
    return novaPessoa;
}

void mostraPessoa(Pessoa ps)
{
    printf("\nNome: %s CPF: %s ",ps.nome, ps.cpf);
}

int numeroBox (Apto ap){
//função para retornar o número do box
    printf("\nBox: %d", ap.box);
}

double valorAluguel(Apto ap){
//função para retornar o valor do aluguel de um apartamento
    printf("\nAluguel: %.2f", ap.vAluguel);
}

double valorCondominio(Apto ap){
//função para retornar o valor do condomínio de um apartamento
    return ap.vCondominio;
}

double totalCondominio(Apto *bloco[], int tam){
//função para calcular o total do condomínio arrecadado
    double total = 0;
    for (int i = 0; i < tam; i++)
    {
        total = total + bloco[i]->vCondominio;        
    }
    return total;   
}

Apto* criaNovoApartamento(char bl,int num,int andar, int comodos, double aluguel, double condominio, int box, Pessoa proprietario){
//funcao para criar um novo apartamento, retorna um ponteiro de apartamento
    Apto *novoApto;
    novoApto = (Apto*)malloc(sizeof(Apto));
    novoApto->bloco=bl;
    novoApto->num=num;
    novoApto->andar=andar;
    novoApto->comodos=comodos;
    novoApto->vAluguel=aluguel;
    novoApto->vCondominio=condominio;
    novoApto->box=box;
    novoApto->proprietario=proprietario;
    novoApto->locatario=NULL;
    novoApto->status=0;
    novoApto->dataLocacao=(defineData(0,0,0));
    return novoApto;
}

void mostraApartamento(Apto ap){
//função para mostrar os dados de um apartamento
    printf("\nApartamento:\n\t Bloco: %c Numero: %d Andar: %d Comodos: %d Box: %d", ap.bloco,ap.num,ap.andar,ap.comodos,ap.box);
    printf("\n\t\t Nome Proprietario: %s Aluguel: %.2f Condominio: %.2f", ap.proprietario.nome, ap.vAluguel, ap.vCondominio);
    if(ap.status){
        printf("\n\t\t\t Locatario: %s",ap.locatario->nome);
        printf(" Data de Locacao: ");
        mostraData(ap.dataLocacao);
    }else{
        printf("\n\t\t\t Status: O Apartamento esta livre!");
    }

}

int  locacaoApartamento(Apto *ap, Pessoa *locatario, Data dt){
//funcao para locar um apartamento para uma pessoa, validar se o apartamento está disponivel
    if(ap->status){
        printf("\nApartamento ocupado! Erro na locação!");
        return 0;        
    }
    else{
        ap->locatario=locatario;
        ap->dataLocacao=dt;
        ap->status=1;
        printf("\n%s locou o apartamento %d Bloco: %c ",locatario->nome,ap->andar,ap->bloco);
        return 1;
    }
}

void liberaApartamento(Apto *ap ){
//funcao para liberar um apartamento de uma locação
    if(ap->status){
        ap->dataLocacao=defineData(0,0,0);
        ap->status=0;          
    }
    
}

void mostraCondominio(Apto *bloco[], int tam){
//mostra todos apartamentos de um bloco
    for (int i = 0; i < tam; i++){
        mostraApartamento(*bloco[i]); //ou (*(*(bloco+i)))
    }
}

void mostraCondominio2(Apto **bloco, int tam){
//mostra todos apartamentos de um bloco recebido por ponteiro de ponteiro
    /* for (int i = 0; i < 4; i++){
        mostraApartamento(*bloco[i]); //ou (*(*(bloco+i)))
    } */        
    mostraCondominio(bloco, tam);
}

int main()
{
    setlocale(LC_ALL, "portuguese-brazilian");    
    //criar bloco de apartamentos
    Apto *blocoA [4], *blocoB [4];

    Pessoa joaquim = criaPessoa("Joaquim Silva","233.343.233-51");
    Pessoa juca = criaPessoa("juca Silva","243.343.233-51");
    Pessoa marcio = criaPessoa("Marcio Silva","234.343.233-51");
    mostraPessoa(joaquim);

    //criar os apartamentos bloco A
    blocoA[0] = criaNovoApartamento('A',101,1,3,200,90,10,joaquim);
    blocoA[1] = criaNovoApartamento('A',201,2,3,230,90,11,juca);
    blocoA[2] = criaNovoApartamento('A',301,3,3,240,90,12,joaquim);
    blocoA[3] = criaNovoApartamento('A',401,4,3,250,90,13,marcio);
    mostraCondominio(blocoA, 4);
  
    //criar os apartamentos bloco B
    blocoB[0] = criaNovoApartamento('B',101,1,3,300,190,20,juca);
    blocoB[1] = criaNovoApartamento('B',201,2,3,330,290,21,juca);
    blocoB[2] = criaNovoApartamento('B',301,3,3,340,390,22,juca);
    blocoB[3] = criaNovoApartamento('B',401,4,3,350,490,23,marcio);    
    mostraCondominio(blocoB, 4);


    
    Data hoje = defineData(01,9,2022);
    int locar = locacaoApartamento(blocoA[0],&marcio,hoje); 
    //retorno do status em string ficou dentro da função locacaoApartamento
    //a função nao precisaria ter um retorno em inteiro
   /*  printf("\nMarcio locou o apartamento %d Bloco: %c ",blocoA[0]->andar,blocoA[0]->bloco); */

    //mostraCondominio(blocoA);
 
   /*  if(locar)
        printf("\nLocacao iniciada!!");
    else
        printf("\nErro na locação!!"); */

    printf("\n\nlocando apartamento ocupado:");
    locar = locacaoApartamento(blocoA[0],&marcio,hoje);
    mostraApartamento(*blocoA[0]);

   
    //passado um vetor de ponteiros
    printf("\n\nPassando um vetor de ponteiros");
    mostraApartamento(*blocoB[0]);
   
    printf("\n\nLIBERANDO APTO:");
    liberaApartamento(blocoA[0]);
    mostraApartamento(*blocoA[0]);


    //passado um ponteiro de ponteiros
    printf("\n\nPONTEIRO DE PONTEIRO:");
    mostraCondominio2(blocoB, 4);


    printf("\n\n O total de arrecadação do Condomínio Bloco B é: %.2f Reais\n ",totalCondominio(blocoB, 4));



    Apto *blocoC [8];

    Pessoa roberto = criaPessoa("Roberto Silva","233.343.233-51");
    Pessoa joao = criaPessoa("João Silva","243.343.233-51");
    Pessoa luiz = criaPessoa("Luiz Silva","234.343.233-51");
    Pessoa celso = criaPessoa("Celso Portiolli","234.343.233-51");
    Pessoa lavinia = criaPessoa("Lavinia Silva","234.343.233-51");
    Pessoa pedro = criaPessoa("Pedro Silva","234.343.233-51");
    Pessoa tulio = criaPessoa("Tulio Silva","234.343.233-51");
    Pessoa marcos = criaPessoa("Marcos Silva","234.343.233-51");
    

    //criar os apartamentos bloco C
    blocoC[0] = criaNovoApartamento('C', 101, 1, 3, 200, 40, 10, roberto);
    blocoC[1] = criaNovoApartamento('C', 102, 2, 3, 230, 40, 11, joao);
    blocoC[2] = criaNovoApartamento('C', 201, 3, 3, 240, 40, 12, luiz);
    blocoC[3] = criaNovoApartamento('C', 202, 4, 3, 250, 40, 13, celso);
    blocoC[4] = criaNovoApartamento('C', 301, 4, 3, 250, 40, 14, lavinia);
    blocoC[5] = criaNovoApartamento('C', 302, 4, 3, 250, 40, 15, pedro);
    blocoC[6] = criaNovoApartamento('C', 401, 4, 3, 250, 40, 16, tulio);
    blocoC[7] = criaNovoApartamento('C', 402, 4, 3, 250, 40, 17, marcos);

    locacaoApartamento(blocoC[7], &luiz, hoje);
    liberaApartamento(blocoC[7]);
    locacaoApartamento(blocoC[7], &roberto, hoje);
    mostraCondominio(blocoC, 8);




}




