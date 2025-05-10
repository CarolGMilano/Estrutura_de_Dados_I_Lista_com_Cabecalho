#include <stdio.h>
#include <stdlib.h>
#include "listacomcabecalho.h"

Lista* criarLista() {
  Lista* lista = (Lista*)malloc(sizeof(Lista));
  lista->cabeca = (No*)malloc(sizeof(No)); 
  lista->cabeca->prox = NULL;
 
  return lista;
}

void inserirInicio(Lista* lista, int valor) {
  No* novo = (No*)malloc(sizeof(No));

  novo->dado = valor;
  novo->prox = lista->cabeca->prox;
  lista->cabeca->prox = novo;
}

void imprimirLista(Lista* lista) {
  No* atual = lista->cabeca->prox;

  while (atual != NULL) {
    printf("%d -> ", atual->dado);
    atual = atual->prox;
  }

  printf("NULL\n");
}

int remover(Lista* lista, int valor) {
  No* ant = lista->cabeca;
  No* atual = ant->prox;

  while (atual != NULL && atual->dado != valor) {
    ant = atual;
    atual = atual->prox;
  }

  if (atual == NULL) return 0; // não encontrado

  ant->prox = atual->prox;
  free(atual);

  return 1; // removido com sucesso
}

void liberarLista(Lista* lista) {
  No* atual = lista->cabeca;

  while (atual != NULL) {
    No* temp = atual;
    atual = atual->prox;
    free(temp);
  }

  free(lista);
}

void inserirFim(Lista* lista, int valor) {
  //Cria um ponteiro para o novo nó.
  No* novo = (No*) malloc(sizeof(No));

  //Adiciona o valor ao nó.
  novo->dado = valor;
  //Adiciona NULL ao próximo do novo nó.
  novo->prox = NULL;
  
  //O primeiro nó da lista é NULL?
  if(lista->cabeca->prox == NULL) {
    //Se sim, ele será colocado na primeira posição, ligando-o ao próximo do cabeçalho.
    lista->cabeca->prox = novo;
  } else {
    //Se não, cria-se um ponteiro para o primeiro elemento da lista.
    No* atual = lista->cabeca->prox;
    
    //O laço while vai percorrer a lista até encontrar o último elemento.
    while(atual->prox != NULL) {
      atual = atual->prox;
    }
  
    //Ao encontrar, irá adicionar o novo nó ao final da lista.
    atual->prox = novo;
  }
}

int contarElementos(Lista* lista) {
  //Contador de elementos
  int cont = 0;

  //Primeiro nó da lista
  No* atual = lista->cabeca->prox;

  //Percorra a lista até chegar ao final da lista, ou seja, enquanto o nó atual for diferente de NULL.
  while (atual != NULL) {
    //Adicione um a cada iteração que não for NULL.
    cont++;

    //Atualiza o atual para o próximo nó.
    atual = atual->prox;
  }

  //Retorna o contador
  return cont;
}

int obterMaior(Lista* lista) {
  //Primeiro nó da lista
  No* atual = lista->cabeca->prox;
  //Valor do primeiro elemento da lista
  int aux = lista->cabeca->prox->dado;

  //Enquanto o atual for difetente de NULL
  while(atual != NULL) {
    //O valor do nó atual é maior que o aux?
    if(atual->dado > aux) {
      //Se sim, atualize a variável aux para o valor do nó atual.
      aux = atual->dado;
    }

    //Atualiza o atual para o próximo nó.
    atual = atual->prox;
  }

  //Retorna o maior valor encontrado ao final da comparação.
  return aux;
}

int obterMenor(Lista* lista) {
  //Primeiro nó da lista
  No* atual = lista->cabeca->prox;
  //Valor do primeiro elemento da lista
  int aux = lista->cabeca->prox->dado;

  //Enquanto o atual for difetente de NULL
  while(atual != NULL) {
    //O valor do nó atual é menor que o aux?
    if(atual->dado < aux) {
      //Se sim, atualize a variável aux para o valor do nó atual.
      aux = atual->dado;
    }

    //Atualiza o atual para o próximo nó.
    atual = atual->prox;
  }

  //Retorna o menor valor encontrado ao final da comparação.
  return aux;
}

int estaVazia(Lista* lista) {
  //A nó de cabeçalho está ligado ao NULL, ou seja, não tem nó ligado a ele?
  if(lista->cabeca->prox == NULL) {
    //Se sim, a lista está vazia, retorne 1;
    return 1;
  } 

  //Se não, a lista possue elementos, retorne 0.
  return 0;
}

void reverterLista(Lista* lista) {
  //Nó nulo
  No* anterior = NULL;
  //Primeiro nó da lista
  No* atual = lista->cabeca->prox;
  //Próximo nó
  No* proximo;

  //Enquanto o nó atual for diferente de NULL.
  while(atual != NULL) {
    //Atualize o próximo para o próximo nó do atual.
    proximo = atual->prox;
    //Atualize o próximo nó para o nó anterior.
    atual->prox = anterior;
    //Atualize o anterior para o atual;
    anterior = atual;
    //Atualize o atual para próximo.
    atual = proximo;

    /*
      Ex.: Cabecalho -> 1 -> 2 -> 3 -> NULL
        anterior = NULL;
        atual = 1;
        proximo = NULL;

        1º Iteração:
          - proximo = 2;
          - 1 -> NULL;
          - anterior = 1;
          - atual = 2;

          Cabecalho -> 1  2 -> 3 -> NULL
                       ↓
                      NULL

        2º Iteração:
          - proximo = 3;
          - 2 -> 1;
          - anterior = 2;
          - atual = 3;

          Cabecalho -> 1 <- 2  3 -> NULL
                       ↓
                      NULL    
 
        3º Iteração:
          - proximo = NULL;
          - 3 -> 2;
          - anterior = 3;
          - atual = NULL;

          Cabecalho -> 1 <- 2 <- 3 
                       ↓
                      NULL                      
    */
  }

  //Atualiza o primeiro da lista
  lista->cabeca->prox = anterior;
  /*
    Ao final da última iteração:
      Cabecalho -> 1 <- 2 <- 3 
                   ↓
                  NULL  
      
    Após a atualização:              
      NULL <- 1 <- 2 <- 3 <- Cabeçalho
  */
}

int buscar(Lista* lista, int valor) {
  //Primeiro nó da lista
  No* atual = lista->cabeca->prox;

  //Enquanto o nó atual for diferente de NULL.
  while(atual != NULL) {
    //O valor do nó atual é igual ao valor que quero encontrar?
    if(atual->dado == valor) {
      //Se sim, encontrei o valor, retorne 1.
      return 1;
    }

    //Se não, atualize o nó para o próximo.
    atual = atual->prox;
  }

  //Caso não encontre o valor na lista, ao final da iteração, retorne 0.
  return 0;
} 

Lista* copiarLista(Lista* lista) {
  //Nova lista vazia
  Lista* novaLista = criarLista();

  //Primeiro nó da lista que será copiada
  No* atual = lista->cabeca->prox;

  //Enquanto o nó atual da lista que será copiada for diferente de NULL
  while(atual != NULL) {
    //Insere o valor do nó atual da lista original na nova lista.
    inserirFim(novaLista, atual->dado);

    //Atualiza o nó atual para o próximo.
    atual = atual->prox;
  }

  //Retorna a cópia
  return novaLista;
}

void concatenarListas(Lista* l1, Lista* l2) {
  //Primeiro elemento da segunda lista
  No* noL2 = l2->cabeca->prox;

  //Enquanto o nó da lista dois for diferente de NULL
  while(noL2 != NULL) {
    //Insere na primeira lista os elementos da segunda lista, ao final.
    inserirFim(l1, noL2->dado);

    //Atualiza o nó atual da segunda lista para o próximo
    noL2 = noL2->prox;
  }

  //Ao final da concatenação, libera a segunda lista, pois está vazia.
  liberarLista(l2);
}

void removerDuplicatas(Lista* lista) {
  //Primeiro elemento da lista
  No* referencia = lista->cabeca->prox;
  
  //Enquanto o nó for diferente de NULL
  while(referencia != NULL){
    //Nó observado no momento
    No* atual = referencia;
    //Próximo nó do nó observado
    No* proximo = referencia->prox;
    
    //Enquanto o próximo nó for diferente de NULL
    while(proximo != NULL) {
      //O dado do próximo nó é igual ao do nó referencia?
      if(proximo->dado == referencia->dado) {
        //Se sim, atualiza o próximo do atual para o próximo do próximo
        atual->prox = proximo->prox;
        //Libera o próximo, pois ele é repetido.
        free(proximo);
        //Atualiza o proximo para o proximo do atual, para continuar a procura.
        proximo = atual->prox;
      } else {
        //Se não, atualize o atual para próximo
        atual = proximo;
        //E o próximo para o próximo do atual, para continuar a procura.
        proximo = atual->prox;
      }
    }

    //Após comparar com todos os elementos, atualize a referencia para o próximo elemento e repita a comparação de nó em nó.
    referencia = referencia->prox;
  }
}
