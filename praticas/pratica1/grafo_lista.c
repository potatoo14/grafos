#include "grafo_lista.h"
#include <stdio.h>
#include <stdlib.h>

GrafoLista* criar_grafo_lista(int n) {
    GrafoLista *grafo = malloc(sizeof(GrafoLista));
    grafo->n = n;
    grafo->adj = calloc(n, sizeof(No*));
    return grafo;
}

void liberar_grafo_lista(GrafoLista *grafo) {
    for (int i = 0; i < grafo->n; i++) {
        No *atual = grafo->adj[i];
        while (atual != NULL) {
            No *temp = atual;
            atual = atual->prox;
            free(temp);
        }
    }
    free(grafo->adj);
    free(grafo);
}

void inserir_direcionado(GrafoLista *grafo, int u, int v) {
    No *novo = malloc(sizeof(No));
    novo->destino = v;
    novo->prox = grafo->adj[u];
    grafo->adj[u] = novo;
}

void inserir_aresta_lista(GrafoLista *grafo, int u, int v) {
    inserir_direcionado(grafo, u, v);
    inserir_direcionado(grafo, v, u);
}

void remover_direcionado(GrafoLista *grafo, int u, int v) {
    No *atual = grafo->adj[u];
    No *ant = NULL;

    while (atual != NULL && atual->destino != v) {
        ant = atual;
        atual = atual->prox;
    }

    if (atual == NULL) return;

    if (ant == NULL) {
        grafo->adj[u] = atual->prox;
    } else {
        ant->prox = atual->prox;
    }
    free(atual);
}

void remover_aresta_lista(GrafoLista *grafo, int u, int v) {
    remover_direcionado(grafo, u, v);
    remover_direcionado(grafo, v, u);
}

int grau_lista(GrafoLista *grafo, int u) {
    int c = 0;
    No *atual = grafo->adj[u];
    while (atual != NULL) {
        c++;
        atual = atual->prox;
    }
    return c;
}

int sao_adjacentes_lista(GrafoLista *grafo, int u, int v) {
    No *atual = grafo->adj[u];
    while (atual != NULL) {
        if (atual->destino == v) return 1;
        atual = atual->prox;
    }
    return 0;
}

void exibir_lista(GrafoLista *grafo) {
    printf("\n");
    for (int i = 0; i < grafo->n; i++) {
        printf("%d: ", i);
        No *atual = grafo->adj[i];
        while (atual != NULL) {
            printf("-> %d ", atual->destino);
            atual = atual->prox;
        }
        printf("\n");
    }
    printf("\n");
}
