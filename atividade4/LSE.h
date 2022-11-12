


typedef struct site{
    char url[20];
    char ip[15];    
    struct site *proximo;
}Site;

typedef struct lse{
    Site *primeiro;
    int n_elementos;
}LSE;

typedef struct sitehash{
    int chave;
    char url[20];
    char ip[15];   
    struct sitehash *proximo;
}SiteHash;

typedef struct lista{
    SiteHash *primeiro;
    int n_elementos;
}Lista;


LSE* criaListaLSE();

Site *cadastraSite(char ip[], char url[]);

Site* criaNovoContato();

void insereNoInicio(LSE *ls, Site *novo);

Site* removeNoInicio(LSE *ls);

void mostraLista(LSE *ls);

void mostraContato(Site *novo);

void apagaLista(LSE *ls);

void apagaContato(Site *novo);

void menu2(LSE *ls);