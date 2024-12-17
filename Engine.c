#ifndef ENGINE_C
#define ENGINE_C

#include "Assinaturas.h"

void Selection(Grafo* grafo){

    bool end = true, flag_grafo = false, flag_vet = false, flag_ares = false;

    do {

        switch(Menu()){

            case 1:

                grafo = flag_grafo ? Reset_Grafo(grafo, &flag_grafo, &flag_vet, &flag_ares) : Cria_Grafo(&flag_grafo);

            break;

            case 2:

                flag_grafo ? Cria_Vertices(grafo, &flag_vet) : printf("\nCrie um grafo primeiro!\n\n");

            break;

            case 3:

                flag_vet ? Cria_Arestas(grafo, &flag_ares) : printf("\nCrie vertices primeiro!\n\n");

            break;

            case 4:

                Verifica_Flag(flag_grafo, flag_vet, flag_ares) ? Quantidade_Vet_Ares(grafo) : printf("\nCrie um grafo com vertices e arestas primeiro!\n\n");

            break;

            case 5:

                flag_ares ? Imprime_Grafo(grafo) : printf("\nCrie arestas primeiro!\n\n");

            break;

            case 6:

                flag_grafo ? Grafo_Complementar(grafo) : printf("\nCrie um grafo primeiro!\n\n");

            break;

            case 7:

                flag_ares ? printf("\nResultado do Passeio: %s Ciclo nesse percurso.\n\n", Passeio(grafo) ? "Ha" : "Nao ha") : printf("\nCrie arestas primeiro!\n\n");

            break;

            case 8:

                flag_ares ? printf("\nResultado da Trilha: %s Ciclo nesse percurso.\n\n", Trilha(grafo) ? "Ha" : "Nao ha") : printf("\nCrie arestas primeiro!\n\n");

            break;

            case 9:

                flag_ares ? printf("\nResultado do Caminho: %s Ciclo nesse percurso.\n\n", Caminho(grafo) ? "Ha" : "Nao ha") : printf("\nCrie arestas primeiro!\n\n");

            break;

            case 10:

                flag_ares ? printf("\nResultado do Ciclo: %s Ciclo nesse percurso.\n\n", Ciclo(grafo) ? "Ha" : "Nao ha") : printf("\nCrie arestas primeiro!\n\n");

            break;


            case 11:

                printf("\nSaindo do programa...");

                end = false;

            break;

            default:

                printf("\nOpcao indisponivel...\n\n");

            break;
        }
    }while(end);
}

#endif