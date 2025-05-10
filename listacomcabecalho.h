#ifndef LISTACOMCABECALHO_H
#define LISTACOMCABECALHO_H

  typedef struct No {
    int dado;
    struct No* prox;
  } No;

  typedef struct {
    No* cabeca; // Nó de cabeçalho
  } Lista;

  Lista* criarLista(); //Implementado
  void inserirInicio(Lista* lista, int valor); //Implementado
  void imprimirLista(Lista* lista); //Implementado
  int remover(Lista* lista, int valor); //Implementado
  void liberarLista(Lista* lista); //Implementado
  
  void inserirFim(Lista* lista, int valor); //OK
  int contarElementos(Lista* lista); //OK
  int obterMaior(Lista* lista); //OK
  int obterMenor(Lista* lista); //OK
  int estaVazia(Lista* lista); //OK
  void reverterLista(Lista* lista); //OK
  int buscar(Lista* lista, int valor); //OK
  Lista* copiarLista(Lista* lista); //OK
  void concatenarListas(Lista* l1, Lista* l2); //OK
  void removerDuplicatas(Lista* lista); //OK

#endif