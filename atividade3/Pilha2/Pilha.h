typedef struct livro{   //dados do elemento livro
    char autor [20];
    char titulo [20];
    int ano;
    struct livro *proximo;
}Livro;

typedef struct pilha{   //atributos de pilha
    Livro *topo;
    int qtd;
}Pilha;



Pilha* criaPilha();

Livro* criaElementoPilhaLivro(int ano, char at [] , char tit [] );

void push(Pilha *p, Livro *e); //insereNoInicio()

Livro* pop(Pilha *p);  //removeNoInicio()

void mostraLivro(Livro l);

void mostraTopo(Pilha *p);

void apagaPilha(Pilha *p);

Pilha * invertePilha(Pilha *p);

void invertePilha2(Pilha **p);

void mostraPilha(Pilha *p);