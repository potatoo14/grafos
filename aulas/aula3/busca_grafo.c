#include "grafo_lista.h"
#include <stdio.h>

int topo = 0;

void dfs(GrafoLista *g, int u, int *visitado) {
  visitado[u] = 1;
  printf("empilha %i, visita %i\n", u+1, u+1);
  No *no = g->lista[u];
  while (no != NULL) {
    int v = no->vertice;
    if (!visitado[v])
      dfs(g, v, visitado);
    no = no->proximo; // pilha de recursividade
  }
  printf("desempilha %i\n", u+1);
}
// void bfs(GrafoLista *g, int v) {}
