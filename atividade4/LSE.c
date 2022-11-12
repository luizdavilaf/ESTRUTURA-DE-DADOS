// biblioteca de funções, implementações
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>   // for clock_t, clock(), CLOCKS_PER_SEC
#include <unistd.h> // for sleep()

#define TAM 101 // proximo numero primo do dobro da quantidade de elementos

typedef struct site
{
    char url[40];
    char ip[15];
    int chave;
    struct site *proximo;
} Site;

typedef struct lse
{
    Site *primeiro;
    int n_elementos;
} LSE;

/**
 * funcao para hash com lista tamanho 15
 */
int funcaoHashStringParaLista(char str[])
{
    int tamS = strlen(str);
    unsigned int hash = 0;

    for (int i = 0; i < tamS; i++)
    {
        hash += str[i] * (i + 1); // somatório do código ASCII vezes a posição
    }

    return hash % 15;
}

/**
 *
 * aloca memoria da lista e cria
 */
LSE *criaListaLSE(LSE *nova)
{

    nova->primeiro = NULL;
    nova->n_elementos = 0;
    return nova;
}
/**
 * imprime o site
 */
void mostraSite(Site *novo)
{
    printf("\nIp:%s", novo->ip);
    printf("\t Url:%s", novo->url);
    printf("\t Chave Hash:%d", novo->chave);
}
/**
 * ALOCA MEMORIA E RETORNA o site
 */
Site *cadastraSite(char ip[], char url[])
{
    Site *novoSite = (Site *)malloc(sizeof(Site));
    strcpy(novoSite->ip, ip);
    strcpy(novoSite->url, url);
    novoSite->chave = funcaoHashStringParaLista(url);
    novoSite->proximo = NULL;
    return novoSite;
}
/**
 * VERIFICA SE JA EXISTE
 * @returns null se já existe ou o site se não
 */
Site *validaExistente(Site *sites[50], Site *novo)
{
    for (int i = 0; i < 50; i++)
    {
        if (sites[i])
        {
            if ((strcmp(sites[i]->ip, novo->ip) == 0) || (strcmp(sites[i]->url, novo->url) == 0))
            {
                printf("\n Erro! Site ja cadastrado na base de dados\n");
                mostraSite(novo);
                return NULL;
            }
        }
    }
    return novo;
}

/**
 * digitar a url e ip do site a ser criado
 * @returns ponteiro do site
 */
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
/**
 * inicializa tabela hash simples
 */
void inicializarTabela(Site tabela[])
{
    for (int i = 0; i < TAM; i++)
        strcpy(tabela[i].url, "");
}
/**
 * inicializa tabela hash com lista
 */
void inicializarTabelaHashLista(LSE tabelaLista[])
{
    for (int i = 0; i < 15; i++)
        criaListaLSE(&tabelaLista[i]);
}

int funcaoHash(int chave)
{
    return chave % TAM;
}
/**
 * funcao hash para tabela com tamanho previamente definido
 */
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

/**
 * insercao na tabela hash sem lista
 */
void inserir(Site tabela[], Site *novo)
{
    int id = funcaoHashString(novo->url);
    while (strlen(tabela[id].url) > 0) // enquanto ocorrer colisão
    {
        id = funcaoHash(id + 1); // vai para a posição seguinte
    }
    tabela[id] = *novo;
}
/**
 * busca na tabela hash sem lista
 */
Site *busca(Site tabela[], char chave[])
{
    // gera o índice a partir do nome a ser buscado
    int id = funcaoHashString(chave);
    printf("\nIndice gerada: %d\n", id);
    while (strlen(tabela[id].url) > 0)
    {                                           // enquanto o tamanho do nome for maior que zero
        if (strcmp(tabela[id].url, chave) == 0) // se o nome for o nome procurad
        {
            printf("\nENCONTRADO NA HASH!!!! %d", id);
            return &tabela[id]; // retorna o endereço da pessoa
        }
        else
            id = funcaoHash(id + 1); // vai para a posição seguinte
    }
    return NULL;
}
/**
 * busca na tabela hash com lista
 */
Site *buscaLista(LSE *ls, char url[])
{
    Site *aux = ls->primeiro;
    if (aux == NULL)
        printf("\n Lista Vazia!!\n");
    else
        while (aux != NULL)
        {
            if (strcmp(aux->url, url) == 0) // se o nome for o nome procurad
            {
                printf("\nENCONTRADO NA LISTA!!!!");
                return aux;
            }
            aux = aux->proximo;
        }
    return NULL;
}
/**
 * insere na tabela hash com lista
*/
void inserirNaTabelaHashComLista(LSE tabela[], Site *novo)
{
    // int id = funcaoHashStringParaLista(novo->url);
    insereNoInicio(&tabela[novo->chave], novo);
}
/**
 * busca na tabela hash com lista
*/
Site *buscaTabelaHashComLista(LSE tabela[], char url[])
{
    int id = funcaoHashStringParaLista(url);
    return buscaLista(&tabela[id], url);
}
/**
 * mostra todas as listas que estao na tabela hash e cada site dentro de cada uma
*/
void MostraTabelaHashLista(LSE tabela[])
{
    for (int i = 0; i < 15; i++)
    {
        printf("\n\nlista %d", i);
        mostraLista(&tabela[i]);
    }
}
/**
 * faz a busca cega em cada site
*/
Site *buscaCega(Site *tabela[], char url[])
{
    for (int i = 0; i < 50; i++)
    {
        // mostraSite(tabela[i]);
        if (strcmp(tabela[i]->url, url) == 0)
        {
            printf("\nENCONTRADO NA BUSCA CEGA");

            return tabela[i];
        }
    }
    return NULL;
}
/**
 * mostra todos os sistes cadastrados
*/
void MostraSitesDaTabela(Site *tabela[])
{
    for (int i = 0; i < 50; i++)
    {
       if(tabela[i]){
            mostraSite(tabela[i]);
        }
    }
}

void menu2()
{
    int op, indice = 0;
    Site *aux, tabela[TAM];
    LSE tabelaLista[15];
    char url[20];

    inicializarTabela(tabela);
    inicializarTabelaHashLista(tabelaLista);

    printf("\n Menu para controlar os sites:");
    Site *sites[50];

     /*    sites[0] = cadastraSite("83.58.231.165", "ft.com");
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
            inserir(tabela, sites[i]);
            inserirNaTabelaHashComLista(tabelaLista, sites[i]);
        }
 */
    do
    {

        printf("\n\nInforme uma Opção:");
        printf("\n -- 1 - Inserir novo site:");
        printf("\n -- 2 - buscar site:");
        printf("\n -- 3 - Mostrar sites por lista Hash:");
        printf("\n -- 4 - Mostrar Todos sites");
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
            aux = validaExistente(sites, aux);
            if (aux != NULL)
            {
                // insereNoInicio(ls, aux);
                sites[indice] = aux;
                indice++;
                inserir(tabela, aux);
                inserirNaTabelaHashComLista(tabelaLista, aux);
            }
            break;
        case 2:
            printf("\n Busca de por site: \n");
            printf("\nInforme a url para busca:\n");
            scanf("%s", url);
            double time_spent = 0.0;
            clock_t begin = clock();
            // BUSCA HASH SIMPLES
            aux = busca(tabela, url);
            clock_t end = clock();
            time_spent += (double)(end - begin) / CLOCKS_PER_SEC;

            if (aux != NULL)
            {
                printf("\nUrl encontrada na hash");
                mostraSite(aux);
            }
            else
            {
                printf("\nUrl NAO encontrada na hash");
            }
            printf("\nO tempo de execucao pela busca em hash foi %f segundos\n", time_spent);
            // BUSCA LISTA ENCADEADA
            time_spent = 0.0;
            begin = clock();
            aux = buscaTabelaHashComLista(tabelaLista, url);
            end = clock();
            time_spent += (double)(end - begin) / CLOCKS_PER_SEC;

            if (aux != NULL)
            {
                printf("\nUrl encontrada na lista");
                mostraSite(aux);
            }
            else
            {
                printf("\nUrl NAO encontrada");
            }
            printf("\nO tempo de execucao pela lista encadeada foi %f segundos\n", time_spent);

            // BUSCA CEGA
            time_spent = 0.0;
            begin = clock();
            aux = buscaCega(sites, url);
            end = clock();
            time_spent += (double)(end - begin) / CLOCKS_PER_SEC;

            if (aux != NULL)
            {
                printf("\nUrl encontrada na lista");
                mostraSite(aux);
            }
            else
            {
                printf("\nUrl NAO encontrada");
            }
            printf("\nO tempo de execucao pela lista cega foi %f segundos\n", time_spent);
            break;

        case 3:
            printf("\n Mostra lista de sites \n");
            MostraTabelaHashLista(tabelaLista);
            break;

        case 4:
        MostraSitesDaTabela(sites);

            break;

        case 0:
            op = -1;
            break;

        default:
            printf("\nOpção Inválida!!\n");
        }
    } while (op > 0);
}

int main()
{

    menu2();
}
