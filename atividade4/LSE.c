// biblioteca de funções, implementações
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LSE.h"
#include <time.h>   // for clock_t, clock(), CLOCKS_PER_SEC
#include <unistd.h> // for sleep()

#define TAM 101 // 2*50 e o proximo numero primo

LSE *criaListaLSE()
{
    LSE *nova = (LSE *)malloc(sizeof(LSE));
    nova->primeiro = NULL;
    nova->n_elementos = 0;
    return nova;
}

void inicializarLista(Lista *l)
{
    l->primeiro = NULL;
    l->n_elementos = 0;
}

void mostraSite(Site *novo)
{
    printf("\nIp:%s", novo->ip);
    printf("\t Url:%s", novo->url);
}

void mostraSite2(Site novo)
{
    printf("\nIp:%s", novo.ip);
    printf("\t Url:%s", novo.url);
}

Site *cadastraSite(char ip[], char url[])
{
    Site *novoSite = (Site *)malloc(sizeof(Site));
    strcpy(novoSite->ip, ip);
    strcpy(novoSite->url, url);
    novoSite->proximo = NULL;
    return novoSite;
}


void inserirNoInicioHash(Lista *l,char ip[], char url[], int valor)
{
    SiteHash *novo = malloc(sizeof(SiteHash));    
    strcpy(novo->ip, ip);
    strcpy(novo->url, url);
    novo->chave = valor;
    novo->proximo = l->primeiro;
    l->primeiro = novo;
    l->n_elementos++;
}

int buscarNaLSEHash(Lista *l, int valor)
{
    SiteHash *aux = l->primeiro;
    if (aux == NULL)
        printf("\n Lista Vazia!!\n");
    else
        while (aux != NULL)
        {
            if (aux->chave == valor)
            {
                return aux->chave;
            }
            aux = aux->proximo;
        }
    return 0;
}

void imprimir_lista(Lista *l)
{
    SiteHash *aux = l->primeiro;
    printf(" Tam: %d: ", l->n_elementos);
    while (aux)
    {
        printf("%d ", aux->chave);
        aux = aux->proximo;
    }
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

int funcaoHash(int chave)
{
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

void inserir(Site tabela[], Site *novo)
{
    int id = funcaoHashString(novo->url);
    while (strlen(tabela[id].url) > 0) // enquanto ocorrer colisão
    {
        id = funcaoHash(id + 1); // vai para a posição seguinte
    }
    tabela[id] = *novo;
}

Site *busca(Site tabela[], char chave[])
{
    // gera o índice a partir do nome a ser buscado
    int id = funcaoHashString(chave);
    printf("\nIndice gerada: %d\n", id);
    while (strlen(tabela[id].url) > 0)
    {                                           // enquanto o tamanho do nome for maior que zero
        if (strcmp(tabela[id].url, chave) == 0) // se o nome for o nome procurad
        {
            printf("\nENCONTRADO NA HASH!!!! %d\n", id);
            return &tabela[id]; // retorna o endereço da pessoa
        }
        else
            id = funcaoHash(id + 1); // vai para a posição seguinte
    }
    return NULL;
}

Site *buscaLista(LSE *ls, char chave[])
{
    Site *aux = ls->primeiro;
    if (aux == NULL)
        printf("\n Lista Vazia!!\n");
    else
        while (aux != NULL)
        {
            if (strcmp(aux->url, chave) == 0) // se o nome for o nome procurad
            {
                printf("\nENCONTRADO NA LISTA!!!!\n");
                return aux; // retorna o endereço da pessoa
            }
            aux = aux->proximo;
        }
    return NULL;
}

void menu2(LSE *ls)
{
    int op;
    Site *aux, tabela[TAM];
    char url[20];

    inicializarTabela(tabela);

    printf("\n Menu para controlar os sites:");
    Site *sites[50];

    sites[0] = cadastraSite("83.58.231.165", "ft.com");
    sites[1] = cadastraSite("153.14.188.74", "un.org");
    sites[2] = cadastraSite("77.23.212.64", "360.cn");
    sites[3] = cadastraSite("154.84.51.18", "utexas.edu");
    sites[4] = cadastraSite("79.133.190.191", "jigsy.com");
    sites[5] = cadastraSite("44.215.163.47", "networkadvertising.org");
    sites[6] = cadastraSite("33.124.176.70", "exblog.jp");
    sites[7] = cadastraSite("41.79.185.136", "bravesites.com");
    sites[8] = cadastraSite("154.177.38.240", "scientificamerican.com");
    sites[9] = cadastraSite("198.47.234.147", "mail.ru");
    sites[10] = cadastraSite("226.130.219.46", "last.fm");
    sites[11] = cadastraSite("57.244.226.201", "friendfeed.com");
    sites[12] = cadastraSite("250.132.112.229", "hubpages.com");
    sites[13] = cadastraSite("77.241.60.188", "sbwire.com");
    sites[14] = cadastraSite("205.37.187.145", "mediafire.com");
    sites[15] = cadastraSite("225.197.167.95", "biglobe.ne.jp");
    sites[16] = cadastraSite("72.69.121.104", "si.edu");
    sites[17] = cadastraSite("241.23.51.33", "bravesites2.com");
    sites[18] = cadastraSite("13.68.1.94", "g.co");
    sites[19] = cadastraSite("136.93.155.71", "columbia.edu");
    sites[20] = cadastraSite("174.115.101.157", "newyorker.com");
    sites[21] = cadastraSite("199.58.236.221", "blog.com");
    sites[22] = cadastraSite("226.165.40.136", "omniture.com");
    sites[23] = cadastraSite("122.152.132.60", "yellowbook.com");
    sites[24] = cadastraSite("91.225.98.50", "europa.eu");
    sites[25] = cadastraSite("96.28.64.179", "apple.com");
    sites[26] = cadastraSite("124.215.225.195", "dedecms.com");
    sites[27] = cadastraSite("168.15.206.9", "si2.edu");
    sites[28] = cadastraSite("43.218.8.219", "goodreads.com");
    sites[29] = cadastraSite("229.145.65.36", "bizjournals.com");
    sites[30] = cadastraSite("37.88.166.204", "squidoo2.com");
    sites[31] = cadastraSite("135.189.33.79", "webmd.com");
    sites[32] = cadastraSite("95.100.207.80", "admin.ch");
    sites[33] = cadastraSite("65.187.98.128", "spiegel.de");
    sites[34] = cadastraSite("25.20.15.213", "godaddy.com");
    sites[35] = cadastraSite("168.127.114.201", "who.int");
    sites[36] = cadastraSite("103.66.42.19", "army.mil");
    sites[37] = cadastraSite("185.176.146.255", "ebay.com");
    sites[38] = cadastraSite("21.21.79.127", "phoca.cz");
    sites[39] = cadastraSite("72.104.184.141", "lycos.com");
    sites[40] = cadastraSite("229.10.46.44", "pcworld.com");
    sites[41] = cadastraSite("245.206.112.188", "squidoo.com");
    sites[42] = cadastraSite("200.233.57.32", "symantec.com");
    sites[43] = cadastraSite("114.246.229.171", "ehow.com");
    sites[44] = cadastraSite("30.147.50.250", "baidu.com");
    sites[45] = cadastraSite("232.231.113.139", "theglobeandmail.com");
    sites[46] = cadastraSite("101.158.17.16", "tuttocitta.it");
    sites[47] = cadastraSite("111.134.248.163", "bravesites3.com");
    sites[48] = cadastraSite("43.203.12.13", "theglobeandmail.com");
    sites[49] = cadastraSite("40.60.188.215", "phpbb.com");
    for (int i = 0; i < 50; i++)
    {
        aux = validaExistente(ls, sites[i]);
        if (aux != NULL)
        {
            insereNoInicio(ls, aux);
            inserir(tabela, aux);
        }
    }

    do
    {

        printf("\n\nInforme uma Opção:");
        printf("\n -- 1 - Inserir novo site:");
        printf("\n -- 2 - buscar site:");
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
            if (aux != NULL)
            {
                insereNoInicio(ls, aux);
                inserir(tabela, aux);
            }
            break;
        case 2:
            printf("\n Busca de por site: \n");
            printf("\nInforme a url para busca:\n");
            scanf("%s", url);
            double time_spent = 0.0;
            clock_t begin = clock();
            aux = busca(tabela, url);
            clock_t end = clock();
            time_spent += (double)(end - begin) / CLOCKS_PER_SEC;

            if (aux != NULL)
            {
                printf("\nUrl encontrada na hash");
                mostraSite2(*aux);
            }
            else
            {
                printf("\nUrl NAO encontrada na hash");
            }
            printf("\nO tempo de execucao pela busca em hash foi %f segundos", time_spent);
            time_spent = 0.0;
            begin = clock();
            aux = buscaLista(ls, url);
            end = clock();
            time_spent += (double)(end - begin) / CLOCKS_PER_SEC;

            if (aux != NULL)
            {
                printf("\nUrl encontrada na lista");
                mostraSite2(*aux);
            }
            else
            {
                printf("\nUrl NAO encontrada");
            }
            printf("\nO tempo de execucao pela lista encadeada foi %f segundos", time_spent);
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
