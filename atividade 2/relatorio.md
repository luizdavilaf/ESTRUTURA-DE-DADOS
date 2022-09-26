1. Sobre a inserção ordenada, eu consegui uma solução mais limpinha:
    ```c
    void insereOrdenado(LSE *ls, Contato *novo) {
      Contato *current = ls->primeiro;
  
      if (current == NULL || strcmp(novo->nome, current->nome) <= 0) {
        return insereNoInicio(ls, novo);
      }
  
      Contato *next = current->proximo;
  
      while (next != NULL) {
        if (strcmp(novo->nome, next->nome) <= 0) {
          goto insert;
        }
  
        current = next;
        next = next->proximo;
      }
  
    insert:
      current->proximo = novo;
      novo->proximo = next;
      ls->n_elementos++;
    }
    ```
    
    (Acho que não tem problema eu te mandar código já que tu já tinha uma solução que funciona, né?)
    
    Eu só tive que ter uma condição excepcional pra quando tem que inserir no início ou como segundo item, já que, como eu to sempre comparando o item novo com o próximo da iteração, eu nunca compararia o primeiro item com o novo.
  
    Em termos de quantidade de `if`, a minha solução tem só 2, 50% do original, então nesse quesito creio que foi um aprimoramento k.
    
    Eu substituí o `for` original por um `while` simples porque eu não vejo justificativa pra um `for`.
    
    E o `goto` que tem ali eu acho que poderia ser uma chamada pra uma função; por exemplo um `return insereEntre(current, next, novo)`. Mas eu não queria criar mais uma função, então fiz assim mesmo.
    
    Muita gente fala mal de `goto`, mas por exemplo no repositório do Linux é o que mais tem: <https://github.com/torvalds/linux/search?q=goto>, então eu acho de boa.
  
    Uma outra coisa que eu fiz também foi usar `return` pra evitar usar `else`. Eu acho mais bonitinho, mas tanto faz.
    
    No geral o meu algoritmo não tem muita coisa de diferente do que tu fez, acho que eu só tirei o que não era necessário mesmo. 🤔

2. Sobre dividir a lista, eu creio que o Luciano pediu um negócio que não faz sentido mesmo
  
    É uma operação muito comum acessar a sublista que começa em um ponto e vai **até o fim da lista**, mas eu nunca vi acessar uma sublista que começa num ponto e termina antes do fim.
    
    Por exemplo, se tem uma lista com {1, 2, 3, 4, 5}, é comum acessar {2, 3, 4, 5} (frequentemente se chama de `tail` da primeira lista), {3, 4, 5}, {4, 5} e {5}, porque todas terminam no mesmo lugar, mas, por exemplo {2, 3, 4}, não...
    
    Dito isso, não acho que tenha uma solução muito bonita pra esse problema ¯\_(ツ)_/¯ por causa da dificuldade de demarcar onde é o fim
    
    Uma coisa que dá pra fazer é declarar o `struct` da lista um pouco diferente:
    
    ```c
    typedef struct lse {
      Contato *primeiro;
      Contato *ultimo;
      int n_elementos;
    } LSE;
    ```
    
    Aí, sempre que se fosse iterar sobre essa lista, a pessoa teria que garantir que, se ela chegou no último elemento, a iteração tem que parar, mesmo que `proximo` não seja `NULL`.
    
    É bem imprático, mas me parece o mais elegante :T
    
    A alternativa que eu vejo seria, quando for criar a sublista, duplicar o último elemento, aí definir o `proximo` dele pra `NULL`. E portanto não alterar o valor original.
    
    Mas aí a pessoa tem que saber que, se for mudar esse elemento, não vai mudar o original... aí fica uma bagunça (na minha opinião)
    
    Mas é, de qualquer forma, eu acredito que o Luciano fez merda. Não sei uma solução boa k
  
3. Sobre o _grupo da família_, eu acho que eu vou entrar em contato com o Luciano pra confirmar, porque o tipo de linguagem que ele usou na ordem do exercício é estranhamente matemática pros padrões dele 🤔

    Mas, analisando rigorosamente, parece que, se tu define os `tipo` dos contatos pros valores certos (`F` pra família, `O` ou `A` pros outros), tá bom...
    
    Porque uma "sublista" é um conceito abstrato, então, por exemplo, não me parece necessário que exista mais de um struct `LSE` no programa. Dada uma lista `L`, tu pode dizer que os elementos de `L` onde o tipo é `F` compõem uma sublista, então eras isso.
    
    Por essa interpretação, "destruir" o grupo da família eu entendo que seria só fazer com que nenhum elemento tenha o tipo `F`.
    
    Mas eu vou mandar um email pra ver
