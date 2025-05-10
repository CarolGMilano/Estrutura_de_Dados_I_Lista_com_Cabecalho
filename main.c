#include <stdio.h>
#include <stdlib.h>
#include "listacomcabecalho.h"

void mostrarMenu() {
  printf("\n====== MENU - Lista com Cabeçalho ======\n");
  printf("1. Inserir no início\n");
  printf("2. Inserir no final\n");
  printf("3. Remover valor\n");
  printf("4. Imprimir lista\n");
  printf("5. Contar elementos\n");
  printf("6. Buscar valor\n");
  printf("7. Obter maior valor\n");
  printf("8. Obter menor valor\n");
  printf("9. Descobrir se a lista está vazia\n");
  printf("10. Inverter ordem\n");
  printf("11. Copiar lista\n");
  printf("12. Concatenar listas\n");
  printf("13. Remover duplicatas\n");
  printf("0. Sair\n");
  printf("========================================\n");
  printf("Escolha uma opção: ");
}

int main() {
  Lista* lista = criarLista();
  Lista* copia;
  
  Lista* l2 = criarLista();

  int opcao, valor, resultado, quantidade;

  do {
    mostrarMenu();
    scanf("%d", &opcao);

    switch (opcao) {
      case 1:
        printf("\nDigite o valor a inserir no início: ");
        scanf("%d", &valor);
        inserirInicio(lista, valor);
      break;

      case 2:
        printf("\nDigite o valor a inserir no final: ");
        scanf("%d", &valor);
        inserirFim(lista, valor); 
      break;

      case 3:
        printf("\nDigite o valor a remover: ");
        scanf("%d", &valor);

        resultado = remover(lista, valor);
        
        if (resultado)
          printf("\nValor removido com sucesso.\n");
        else
          printf("\nValor não encontrado.\n");
      break;

      case 4:
        printf("\nConteúdo da lista:\n");
        imprimirLista(lista);
      break;

      case 5:
        printf("\nA lista contém %d elemento(s).\n", contarElementos(lista)); 
      break;

      case 6:
        printf("\nDigite o valor a buscar: ");
        scanf("%d", &valor);
        
        resultado = buscar(lista, valor);
        
        if (resultado)
          printf("\nValor encontrado na lista.\n");
        else
          printf("\nValor não encontrado.\n");
      break;

      case 7:
        printf("\nO maior valor da lista é %d.\n", obterMaior(lista));
      break;

      case 8:
        printf("\nO menor valor da lista é %d.\n", obterMenor(lista));
      break;

      case 9:
        printf("\n %s\n", (estaVazia(lista) ? "A lista está vazia." : "A lista não está vazia."));
      break;

      case 10:
        printf("\nLista original:\n");
        imprimirLista(lista);

        reverterLista(lista);

        printf("\nLista invertida:\n");
        imprimirLista(lista);
      break;

      case 11:
        printf("\nLista original:\n");
        imprimirLista(lista);

        copia = copiarLista(lista);

        printf("\nCópia:\n");
        imprimirLista(copia);
      break;

      case 12:      
        printf("\nLista 01:\n");
        imprimirLista(lista);

        printf("\nLista 02:\n\n");
        printf("\nQuantos elementos deseja adicionar a lista 02? ");
        scanf("%d", &quantidade);

        for(int i = 0; i < quantidade; i++) {
          printf("Digite o %dº valor: ", i+1);
          scanf("%d", &valor);
          inserirFim(l2, valor);
        }

        printf("\nLista 2:\n");
        imprimirLista(l2);

        concatenarListas(lista, l2);

        printf("\nLista concatenada:\n");
        imprimirLista(lista);
      break;

      case 13:
        printf("\nLista original:\n");
        imprimirLista(lista);

        removerDuplicatas(lista);

        printf("\nLista sem duplicatas:\n");
        imprimirLista(lista);
      break;

      case 0:
        printf("\nEncerrando programa.\n");
        liberarLista(lista);
      break;

      default:
       printf("\nOpção inválida. Tente novamente.\n");
    }
  } while (opcao != 0);

  return 0;
}