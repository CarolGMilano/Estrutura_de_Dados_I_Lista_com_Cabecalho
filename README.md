# Lista Encadeada com Cabeçalho

Este projeto implementa uma **lista encadeada com nó-cabeçalho** em linguagem C, com diversas operações úteis para manipulação dinâmica de dados.

## 🧠 Funcionalidades

A lista conta com as seguintes operações:

### ✅ Já implementadas originalmente:
- `criarLista` – Cria uma nova lista com nó-cabeçalho
- `inserirInicio` – Insere um valor no início da lista
- `imprimirLista` – Imprime os elementos da lista
- `remover` – Remove a primeira ocorrência de um valor
- `liberarLista` – Libera toda a memória da lista

### ✳️ Implementadas por mim:
- `inserirFim` – Insere um valor no final da lista
- `contarElementos` – Retorna o número de elementos da lista
- `obterMaior` – Retorna o maior valor presente na lista
- `obterMenor` – Retorna o menor valor presente na lista
- `estaVazia` – Verifica se a lista está vazia
- `reverterLista` – Inverte a ordem dos elementos
- `buscar` – Retorna se um valor está presente na lista
- `copiarLista` – Retorna uma cópia profunda da lista
- `concatenarListas` – Concatena duas listas
- `removerDuplicatas` – Remove valores duplicados da lista

## 🛠️ Compilação e Execução

Compile com:

```bash
gcc main.c listacomcabecalho.c -o programa
```

Execute com:

```bash
./programa
```

## 🧪 Demonstração

A funcionalidade de cada função é demonstrada no arquivo `main.c`, por meio de:

- Um **menu interativo** com as seguintes opções:

  1. Inserir no início;
  2. Inserir no final;
  3. Remover valor;
  4. Imprimir lista;
  5. Contar elementos;
  6. Buscar valor;
  7. Obter maior valor;
  8. Obter menor valor;
  9. Descobrir se a lista está vazia;
  10. Inverter ordem;
  11. Copiar lista;
  12. Concatenar listas;
  13. Remover duplicatas;
  0. Sair;
  
- Diversos `printf`s mostrando as alterações nas listas após cada operação
