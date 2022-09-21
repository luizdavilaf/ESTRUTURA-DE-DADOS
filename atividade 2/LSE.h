
//Arquivo de prototipos das funções e definicao das estruturas

typedef struct contato{
    char nome[20];
    char telefone [20];
    char tipo;
    struct contato *proximo;
}Contato;

typedef struct lse{
    Contato *primeiro;
    int n_elementos;
}LSE;

//protótipo das funções - chamadas das funções

LSE* criaListaLSE();

LSE* divideLista(LSE *ls, int inicio, int fim);

Contato* cadastraContato(char nome[],char tel[], char tipo);

Contato* criaNovoContato();

void insereNoInicio(LSE *ls, Contato *novo);

void insereNoFim(LSE *ls, Contato *novo);

void insereNaPosicao(LSE *ls, Contato *novo, int pos);

void insereOrdenado(LSE *ls, Contato *novo);

Contato* removeNoInicio(LSE *ls);

Contato* removeNoFim(LSE *ls);

Contato* removeNaPosicao(LSE *ls, int pos);

Contato* removeContatoNome(LSE *ls, char nome[]);

int retornaQuantidade(LSE *ls);

int buscaContatoPorNome(LSE *ls, char nome[]);

void mostraLista(LSE *ls);

void mostraContato(Contato *novo);

void mostraContatoPosicao(LSE *ls, int pos);

void apagaLista(LSE *ls);

void apagaContato(Contato *novo);

void menu(LSE *ls);

void menu2(LSE *ls);