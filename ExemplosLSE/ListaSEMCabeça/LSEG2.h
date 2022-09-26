
typedef struct dados{
    int valor;
}Dados;

typedef struct node{
    Dados info;
    struct node *prox;
}Node;


Node* insereInicio(Node *lista, Dados info);

Node* insereFim(Node *lista, Dados info);

Node* inserePosicao(Node *lista, Dados info, int pos);

Node* removeInicio(Node *lista);

Node* removeFim(Node *lista);

Node* removePosicao(Node *lista, int pos);

void mostraLista(Node *lista);

void mostraListaInvertida(Node *lista);

int localizaElemento(Node *lista, int num);

Node* criaNovaListaOrdenada(Node *Lista);

Node* criaSubLista(Node *lista, int inicio, int fim);

Node* criaNovaListaInvertida(Node *lista);

void menuLista(Node *lista);

void mostraDados(Dados info);

Dados criaNoDados();