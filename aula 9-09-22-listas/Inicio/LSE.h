
//Arquivo de prototipos das funções e definicao das estruturas

typedef struct aluno{
    char nome[20];
    int idade;
    int matricula;
    struct aluno *proximo;
}Aluno;

typedef struct lse{
    Aluno *primeiro;
    int n_elementos;
}LSE;


LSE* criaListaLSE();

Aluno* cadastraAluno(char nome[20],int idade, int matricula);

Aluno* lerAluno();

void insereNoInicio(LSE *ls, Aluno *novo);

void insereNoFim(LSE *ls, Aluno *novo);

void insereNaPosicao(LSE *ls, Aluno *novo, int pos);

Aluno* removeNoInicio(LSE *ls);

Aluno* removeNoFim(LSE *ls);

Aluno* removeNaPosicao(LSE *ls, int pos);

int retornaQuantidade(LSE *ls);

void mostraLista(LSE *ls);

void mostraAluno(Aluno *novo);

void mostraPosicao(LSE *ls, int pos);

void apagaLista(LSE *ls);

void apagaAluno(Aluno *novo);
