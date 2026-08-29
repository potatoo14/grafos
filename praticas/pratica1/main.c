#include "grafo_lista.h"
#include "grafo_matriz.h"
#include <stdio.h>
#include <assert.h>

int main() {
    int n = 5;

    GrafoMatriz *gm = criar_grafo_matriz(n);

    inserir_aresta_matriz(gm, 0, 1);
    inserir_aresta_matriz(gm, 0, 4);
    inserir_aresta_matriz(gm, 1, 2);
    inserir_aresta_matriz(gm, 1, 3);
    inserir_aresta_matriz(gm, 1, 4);
    inserir_aresta_matriz(gm, 2, 3);
    inserir_aresta_matriz(gm, 3, 4);

    printf("Estado inicial da Matriz:\n");
    exibir_matriz(gm);

    printf("Testando Grau: vertice 1 tem grau %d (Esperado: 4)\n", grau_matriz(gm, 1));
    assert(grau_matriz(gm, 1) == 4);

    printf("Testando Adjacencia (positiva): (0,4) sao adjacentes? %d (Esperado: 1)\n", sao_adjacentes_matriz(gm, 0, 4));
    assert(sao_adjacentes_matriz(gm, 0, 4) == 1);

    printf("Testando Adjacencia (negativa): (0,2) sao adjacentes? %d (Esperado: 0)\n", sao_adjacentes_matriz(gm, 0, 2));
    assert(sao_adjacentes_matriz(gm, 0, 2) == 0);

    printf("\nRemovendo aresta (1,4)...\n");
    remover_aresta_matriz(gm, 1, 4);
    exibir_matriz(gm);
    
    printf("Apos remocao: (1,4) sao adjacentes? %d (Esperado: 0)\n", sao_adjacentes_matriz(gm, 1, 4));
    assert(sao_adjacentes_matriz(gm, 1, 4) == 0);
    assert(grau_matriz(gm, 1) == 3); // Degree should drop

    liberar_grafo_matriz(gm); 
    printf("Grafo Matriz liberado com sucesso.\n\n");


    printf("=== INICIANDO TESTES: GRAFO LISTA ===\n");

    GrafoLista *gl = criar_grafo_lista(n);

    inserir_aresta_lista(gl, 0, 1);
    inserir_aresta_lista(gl, 0, 4);
    inserir_aresta_lista(gl, 1, 2);
    inserir_aresta_lista(gl, 1, 3);
    inserir_aresta_lista(gl, 1, 4);
    inserir_aresta_lista(gl, 2, 3);
    inserir_aresta_lista(gl, 3, 4);

    printf("Estado inicial da Lista:\n");
    exibir_lista(gl);

    printf("Testando Grau: vertice 1 tem grau %d (Esperado: 4)\n", grau_lista(gl, 1));
    assert(grau_lista(gl, 1) == 4);

    printf("Testando Adjacencia (positiva): (0,4) sao adjacentes? %d (Esperado: 1)\n", sao_adjacentes_lista(gl, 0, 4));
    assert(sao_adjacentes_lista(gl, 0, 4) == 1);

    printf("Testando Adjacencia (negativa): (0,2) sao adjacentes? %d (Esperado: 0)\n", sao_adjacentes_lista(gl, 0, 2));
    assert(sao_adjacentes_lista(gl, 0, 2) == 0);

    printf("\nRemovendo aresta (1,4)...\n");
    remover_aresta_lista(gl, 1, 4);
    exibir_lista(gl);
    
    printf("Apos remocao: (1,4) sao adjacentes? %d (Esperado: 0)\n", sao_adjacentes_lista(gl, 1, 4));
    assert(sao_adjacentes_lista(gl, 1, 4) == 0);
    assert(grau_lista(gl, 1) == 3);

    liberar_grafo_lista(gl);
    printf("Grafo Lista liberado com sucesso.\n");

    printf("\nTodos os testes passaram.\n");
}
