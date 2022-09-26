
//Arquivo de prototipos das funções e definicao das estruturas

typedef struct node{
    int valor;
    struct node *proximo;
}Node;

typedef struct lse{
    Node *primeiro;
    int n_elementos;
}LSE;


LSE* criaListaLSE();

Node* criaNoDados();

Node lerNode();

void insereNoInicio(LSE *ls, Node *novo);

void insereNoFim(LSE *ls, Node *novo);

void insereNaPosicao(LSE *ls, Node *novo, int pos);

Node* removeNoInicio(LSE *ls);

Node* removeNoFim(LSE *ls);

Node* removeNaPosicao(LSE *ls, int pos);

int retornaQuantidade(LSE *ls);

void mostraLista(LSE *ls);

void mostraNode(Node novo);

void mostraPosicao(LSE *ls, int pos);

void apagaLista(LSE *ls);

void apagaNode(Node *novo);
