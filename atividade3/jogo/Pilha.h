typedef struct disco{       
    int cor;
    struct disco *proximo;
}Disco;

typedef struct pilha{   //atributos de pilha
    Disco *topo;
    int qtd;
}Pilha;

void menu();

Pilha* criaPilha();

Disco *criaElementoPilhaDisco(int cor);

void comecaJogoFacil();

void push(Pilha *p, Disco *e); // insereNoInicio()

Disco* pop(Pilha *p);  //removeNoInicio()

void mostraDisco(Disco l);

void mostraTopo(Pilha *p);

void apagaPilha(Pilha *p);

Pilha * invertePilha(Pilha *p);

void invertePilha2(Pilha **p);

void mostraPilha(Pilha *p);