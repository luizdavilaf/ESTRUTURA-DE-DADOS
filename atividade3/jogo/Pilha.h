typedef struct disco
{
    int cor;
    struct disco *proximo;
} Disco;

typedef struct pilha
{ // atributos de pilha
    Disco *topo;
    int tamanhoMax;
    int qtd;
    int numeroPilha;
} Pilha;

typedef struct jogo
{
    int tempo;
    int movimentos;
    char nome[10];
    char dificuldade[7];
    char estado[3];
    
} Jogo;

void menu();

Pilha *criaPilha(int tamanhoMax, int numeroPilha);

Disco *criaElementoPilhaDisco(int cor);

Jogo *comecaJogoFacil(Jogo *jogo, int tamanho);

void mostraJogo(Jogo *jogo);

int push(Pilha *p, Disco *e); // insereNoInicio()

Disco *pop(Pilha *p); // removeNoInicio()

void mostraDisco(Disco l);

void mostraTopo(Pilha *p);

void apagaPilha(Pilha *p);

Pilha *invertePilha(Pilha *p);

void invertePilha2(Pilha **p);

void mostraPilha(Pilha *p);

int checkGameStatus(Pilha *pilhas[]);

int getCorDaPilha(Pilha *p);