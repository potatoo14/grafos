#include "grafo_matriz.h"
#include <stdio.h>
#include <stdlib.h>

GrafoMatriz* criar_grafo_matriz(int n) {
  GrafoMatriz *grafo = malloc(sizeof(GrafoMatriz));
  grafo->n = n;
  grafo->adj = malloc(n * sizeof(int *));
  for (int i = 0; i < n; i++) {
    grafo->adj[i] = calloc(n, sizeof(int));
  }
  return grafo;
}
void liberar_grafo_matriz(GrafoMatriz *grafo) {
  for (int i = 0; i < grafo->n; i++) {
    free(grafo->adj[i]);
  }
  free(grafo->adj);
  free(grafo);
}
void inserir_aresta_matriz(GrafoMatriz *grafo, int u, int v) {
  grafo->adj[u][v] = 1;
  grafo->adj[v][u] = 1;
}
void remover_aresta_matriz(GrafoMatriz *grafo, int u, int v) {
  grafo->adj[u][v] = 0;
  grafo->adj[v][u] = 0;
}
int grau_matriz(GrafoMatriz *grafo, int u) {
  int c = 0;
  for (int v = 0; v < grafo->n; v++) {
    if (grafo->adj[u][v] == 1) {
      c++;
    }
  }
  return c;
}
int sao_adjacentes_matriz(GrafoMatriz *grafo, int u, int v) {
  if (grafo->adj[u][v] == 1) {
    return 1;
  }
  return 0;
}

void exibir_matriz(GrafoMatriz *grafo) {
  printf("\n");
  for (int i = 0; i < grafo->n; i++) {
    for (int j = 0; j < grafo->n; j++) {
      printf("%3i", grafo->adj[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}
