#ifndef MENU_C
#define MENU_C

#include "Assinaturas.h"

int Menu(){

    int op = 0;

    printf("================================================================================================\n\n");

    printf("[1] Alocar memoria para Grafo.\n[2] Criar Vertices.\n[3] Criar Arestas.\n[4] Quantidade de Vertices e Arestas.\n[5] Imprimir Grafo.\n");
    printf("[6] Grafo Complementar.\n[7] Verificar Passeio.\n[8] Verificar Trilha.\n[9] Verificar Caminho.\n");
    printf("[10] Verificar Ciclo.\n[11] Sair do programa.\n\n");

    printf("Escolha: ");
    scanf("%d", &op);

    return op;
}

#endif