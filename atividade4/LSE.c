// biblioteca de funções, implementações
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LSE.h"

#define TAM 101 // 2*50 e o proximo numero primo

LSE *criaListaLSE()
{
    LSE *nova = (LSE *)malloc(sizeof(LSE));
    nova->primeiro = NULL;
    nova->n_elementos = 0;
    return nova;
}

void mostraSite(Site *novo)
{
    printf("\nIp:%s", novo->ip);
    printf("\t Url:%s", novo->url);
}

Site *cadastraSite(char ip[], char url[])
{
    Site *novoSite = (Site *)malloc(sizeof(Site));
    strcpy(novoSite->ip, ip);
    strcpy(novoSite->url, url);
    novoSite->proximo = NULL;
    return novoSite;
}

Site *validaExistente(LSE *ls, Site *novo)
{
    Site *aux = ls->primeiro;
    if (aux == NULL)
    {
        printf("\n Site cadastrado\n");
        return novo;
    }
    else
    {
        while (aux != NULL)
        {
            if ((strcmp(aux->ip, novo->ip) == 0) || (strcmp(aux->url, novo->url) == 0))
            {
                printf("\n Erro! Site ja cadastrado na base de dados\n");
                mostraSite(novo);
                return NULL;
            }
            aux = aux->proximo;
        }
        return novo;
    }
}

Site *criaNovoSite()
{
    char url[20], ip[15];
    printf("\nInforme o ip:");
    scanf("%s", ip);
    printf("\nInforme a url:");
    scanf("%s", url);
    return cadastraSite(ip, url);
}

void insereNoInicio(LSE *ls, Site *novo)
{

    if (ls->primeiro == NULL)
    {
        novo->proximo = NULL;
    }
    else
    {
        novo->proximo = ls->primeiro;
    }
    ls->primeiro = novo;
    ls->n_elementos++;
}

Site *removeNoInicio(LSE *ls)
{

    Site *aux = ls->primeiro;
    if (aux != NULL)
    {
        ls->n_elementos--;
        ls->primeiro = aux->proximo;
        aux->proximo = NULL;
    }
    return aux;
}

void mostraLista(LSE *ls)
{
    Site *aux = ls->primeiro;
    if (aux == NULL)
        printf("\n Lista Vazia!!\n");
    else
        while (aux != NULL)
        {
            mostraSite(aux);
            aux = aux->proximo;
        }
}

void inicializarTabela(Site tabela[])
{
    for (int i = 0; i < TAM; i++)
        strcpy(tabela[i].url, "");
}

int funcaoHash(int chave){
    return chave % TAM;
}

int funcaoHashString(char str[])
{
    int tamS = strlen(str);
    unsigned int hash = 0;

    for (int i = 0; i < tamS; i++)
    {
        hash += str[i] * (i + 1); // somatório do código ASCII vezes a posição
    }

    return hash % TAM;
}


void inserir(Site tabela[], Site *novo){    
    int id = funcaoHashString(novo->url);
    while(strlen(tabela[id].url) > 0) // enquanto ocorrer colisão
        {
            id = funcaoHash(id + 1); // vai para a posição seguinte
        }
    tabela[id] = *novo;
}


Site* busca(Site tabela[], char chave[]){
    // gera o índice a partir do nome a ser buscado
    int id = funcaoHashString(chave);
    printf("\nIndice gerada: %d\n", id);
    while(strlen(tabela[id].url) > 0){ // enquanto o tamanho do nome for maior que zero
        if(strcmp(tabela[id].url, chave) == 0) // se o nome for o nome procurad
            return &tabela[id]; // retorna o endereço da pessoa
        else
            id = funcaoHash(id + 1); // vai para a posição seguinte
    }
    return NULL;
}

void menu2(LSE *ls)
{
    int op;
    Site *aux, tabela[TAM];

    inicializarTabela(tabela);

    printf("\n Menu para controlar os sites:");
    Site *sites[50];

    sites[0] = cadastraSite("ft.com", "83.58.231.165");
    sites[1] = cadastraSite("un.org", "153.14.188.74");
    sites[2] = cadastraSite("360.cn", "77.23.212.64");
    sites[3] = cadastraSite("utexas.edu", "154.84.51.18");
    sites[4] = cadastraSite("jigsy.com", "79.133.190.191");
    sites[5] = cadastraSite("networkadvertising.org", "44.215.163.47");
    sites[6] = cadastraSite("exblog.jp", "33.124.176.70");
    sites[7] = cadastraSite("bravesites.com", "41.79.185.136");
    sites[8] = cadastraSite("scientificamerican.com", "154.177.38.240");
    sites[9] = cadastraSite("mail.ru", "198.47.234.147");
    sites[10] = cadastraSite("last.fm", "226.130.219.46");
    sites[11] = cadastraSite("friendfeed.com", "57.244.226.201");
    sites[12] = cadastraSite("hubpages.com", "250.132.112.229");
    sites[13] = cadastraSite("sbwire.com", "77.241.60.188");
    sites[14] = cadastraSite("mediafire.com", "205.37.187.145");
    sites[15] = cadastraSite("biglobe.ne.jp", "225.197.167.95");
    sites[16] = cadastraSite("si.edu", "72.69.121.104");
    sites[17] = cadastraSite("bravesites.com", "241.23.51.33");
    sites[18] = cadastraSite("g.co", "13.68.1.94");
    sites[19] = cadastraSite("columbia.edu", "136.93.155.71");
    sites[20] = cadastraSite("newyorker.com", "174.115.101.157");
    sites[21] = cadastraSite("blog.com", "199.58.236.221");
    sites[22] = cadastraSite("omniture.com", "226.165.40.136");
    sites[23] = cadastraSite("yellowbook.com", "122.152.132.60");
    sites[24] = cadastraSite("europa.eu", "91.225.98.50");
    sites[25] = cadastraSite("apple.com", "96.28.64.179");
    sites[26] = cadastraSite("dedecms.com", "124.215.225.195");
    sites[27] = cadastraSite("si.edu", "168.15.206.9");
    sites[28] = cadastraSite("goodreads.com", "43.218.8.219");
    sites[29] = cadastraSite("bizjournals.com", "229.145.65.36");
    sites[30] = cadastraSite("squidoo.com", "37.88.166.204");
    sites[31] = cadastraSite("webmd.com", "135.189.33.79");
    sites[32] = cadastraSite("admin.ch", "95.100.207.80");
    sites[33] = cadastraSite("spiegel.de", "65.187.98.128");
    sites[34] = cadastraSite("godaddy.com", "25.20.15.213");
    sites[35] = cadastraSite("who.int", "168.127.114.201");
    sites[36] = cadastraSite("army.mil", "103.66.42.19");
    sites[37] = cadastraSite("ebay.com", "185.176.146.255");
    sites[38] = cadastraSite("phoca.cz", "21.21.79.127");
    sites[39] = cadastraSite("lycos.com", "72.104.184.141");
    sites[40] = cadastraSite("pcworld.com", "229.10.46.44");
    sites[41] = cadastraSite("squidoo.com", "245.206.112.188");
    sites[42] = cadastraSite("symantec.com", "200.233.57.32");
    sites[43] = cadastraSite("ehow.com", "114.246.229.171");
    sites[44] = cadastraSite("baidu.com", "30.147.50.250");
    sites[45] = cadastraSite("theglobeandmail.com", "232.231.113.139");
    sites[46] = cadastraSite("tuttocitta.it", "101.158.17.16");
    sites[47] = cadastraSite("bravesites.com", "111.134.248.163");
    sites[48] = cadastraSite("theglobeandmail.com", "43.203.12.13");
    sites[49] = cadastraSite("phpbb.com", "40.60.188.215");
    for (int i = 0; i < 50; i++)
    {
        aux = validaExistente(ls, sites[i]);
        if (aux != NULL){
            insereNoInicio(ls,aux);
            inserir(tabela,aux);
        }
    }

    do
    {

        printf("\n\nInforme uma Opção:");
        printf("\n -- 1 - Inserir novo site:");
        printf("\n -- 2 - Remover site:");
        printf("\n -- 3 - ");
        printf("\n -- 4 - Mostrar Lista de sites:");
        printf("\n -- 5 - ");
        printf("\n -- 6 - Apaga lista");
        printf("\n -- 0 - Sair do Programa:\n");
        printf("\nInforme sua Opçao:");
        scanf("%d", &op);
        fflush(stdin);

        system("clear");

        switch (op)
        {
        case 1:
            printf("\n Inserção!\n");
            aux = criaNovoSite();
            aux = validaExistente(ls, aux);
        if (aux != NULL){
            insereNoInicio(ls,aux);
            inserir(tabela,aux);
        }

            break;
        case 2:

            break;

        case 3:

            break;

        case 4:
            printf("\n Mostra Lista Ordenada: \n");
            mostraLista(ls);
            break;

        case 5:

            break;
        case 6:
            printf("\n Apaga Lista \n");
            // apagaLista(ls);
            break;
        default:
            printf("\nOpção Inválida!!\n");
        }
    } while (op > 0);
}
