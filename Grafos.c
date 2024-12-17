#ifndef GRAFO_C
#define GRAFO_C

#include "Assinaturas.h"

void Libera_Memoria(Grafo* grafo) {

    for (int i = 0; i < grafo->vet; i++) {

        free(grafo->matriz[i]);
    }

    free(grafo->matriz);
    free(grafo);
}

Grafo* Reset_Grafo(Grafo* grafo, bool* flag_grafo, bool* flag_vet, bool* flag_ares){

    grafo = nullptr;

    (*flag_vet) = false;
    (*flag_ares) = false;

    return Cria_Grafo(flag_grafo);
}

bool Verifica_Flag(const bool flag_grafo, const bool flag_vet, const bool flag_ares) {

    return (flag_ares && flag_grafo && flag_vet);
}

void Quantidade_Vet_Ares(const Grafo* grafo) {

    printf("\nQuantidade de Vertices: %d\n\nQuantidade de Arestas: %d\n\n", grafo->vet, grafo->ares);
}

Grafo* Cria_Grafo(bool* flag_grafo) {

    //system("cls");

    Grafo* grafo = (Grafo*)malloc(sizeof(Grafo));

    if (grafo == NULL) {

        printf("Erro ao alocar memoria para o grafo.");

        exit(1);
    }

    (*flag_grafo) = true;

    printf("\nGrafo criado com sucesso!\n\n");

    return grafo;
}

void Aloca_Memoria_Vertices(Grafo* grafo) {

    grafo->matriz = (int**)malloc(grafo->vet * sizeof(int*));

    if (grafo->matriz == NULL) {

        printf("Erro ao alocar memoria para os vertices.");

        exit(1);
    }

    for (int i = 0; i < grafo->vet; i++) {

        grafo->matriz[i] = (int*)calloc(grafo->vet, sizeof(int));
    }

    grafo->ares = 0;
}

void Cria_Vertices(Grafo* grafo, bool* flag_vet) {

    //system("cls");

    if((*flag_vet)) {

        printf("\nCrie um novo grafo!\n\n");

        return;
    }

    printf("\nDigite a quantidade de vertices: ");
    scanf("%d", &grafo->vet);

    Aloca_Memoria_Vertices(grafo);

    (*flag_vet) = true;

    printf("\nVertices criados com sucesso!\n\n");
}

void Cria_Arestas(Grafo* grafo, bool* flag_ares) {

    //system("cls");

    if((*flag_ares)) {

        printf("\nCrie um novo grafo!\n\n");

        return;
    }

    srand(time(nullptr));

    for (int i = 0; i < grafo->vet; i++) {
        for (int j = i+1; j < grafo->vet; j++) {

            int aux = rand() % LIMITE;

            if ((aux % 2) == 0) {

                grafo->matriz[i][j] = 1;
                grafo->matriz[j][i] = 1;

                grafo->ares++;
            }
        }
    }

    (*flag_ares) = true;

    printf("\nArestas criadas com sucesso!\n\n");
}

void Imprime_Grafo(Grafo* grafo) {

    //system("cls");

    printf("\n#|  ");

    for (int i = 1; i <= grafo->vet; i++) {

        printf("%d  ", i);
    }

    printf("\n");

    for (int i = 0; i < grafo->vet; i++) {

        printf("%d|  ", (i+1));

        for (int j = 0; j < grafo->vet; j++) {

            printf("%d  ", grafo->matriz[i][j]);
        }

        printf("\n");
    }
}

void Grafo_Complementar(Grafo* grafo) {

    Grafo* complement = (Grafo*)malloc(sizeof(Grafo));

    if (complement == NULL) {

        printf("\nErro ao alocar memoria para o Grafo Complementar!");

        return;
    }

    complement->vet = grafo->vet;

    Aloca_Memoria_Vertices(complement);

    for (int i = 0; i < complement->vet; i++) {
        for (int j = (i+1); j < complement->vet; j++) {

            if (grafo->matriz[i][j] == 0) {

                complement->matriz[i][j] = 1;
                complement->matriz[j][i] = 1;

                complement->ares++;
            }
        }
    }

    Imprime_Grafo(complement);
    Quantidade_Vet_Ares(complement);

    Libera_Memoria(complement);
}

int Tamanho_Percurso() {

    int qtd = 0;

    printf("\nQuantos caminhos voce fara: ");
    scanf("%d", &qtd);

    return qtd;
}

bool Percurso_Valido(const Grafo* grafo, const int vet) {

    if ((vet < 0) || (grafo->vet < vet)) {

        printf("\nValor de percurso invalido, tente novamente!\n");

        return true;
    }

    return false;
}

int Percurso(const Grafo* grafo, int* vet, const int tam) {

    int i;

    for(i = 0; i < tam; i++) {

        do{

            printf("\nDigite o percurso [%d] (Digite '0' caso queria usar menos caminhos): ", (i+1));
            scanf("%d", &vet[i]);

        }while(Percurso_Valido(grafo, vet[i]));

        if (vet[i] == 0) {

            break;
        }
    }

    return i;
}

int Passeio(const Grafo* grafo) {

    const int tam = Tamanho_Percurso();

    if (tam < 2) {

        printf("\n\nTamanho insuficiente!\n\n");

        return 0;
    }

    int vet[tam];

    memset(vet, 0, sizeof(vet));

    const int cont = Percurso(grafo, vet, tam);

    if (cont == 0) {

        return 0;
    }

    for (int n = 0; n < (cont - 1); n++) {// 1 2 3

        if (vet[(n+1)] == 0) {

            break;
        }

        int i = (vet[n] - 1), j = (vet[(n+1)] - 1);

        if (grafo->matriz[i][j] == 0) {

            return 0;
        }
    }

    return 1;
}

int Trilha(const Grafo* grafo) {

    const int tam = Tamanho_Percurso();

    if(tam < 2) {

        printf("\n\nTamanho insuficiente!\n\n");

        return 0;
    }

    int vet[tam], edges_Used[grafo->vet][grafo->vet];

    memset(edges_Used, 0, sizeof(edges_Used)); // '0' signfica que nn foi utilizada a aresta.
    memset(vet, 0, sizeof(vet));

    const int cont = Percurso(grafo, vet, tam);

    if (cont == 0) {

        return 0;
    }

    for (int n = 0; n < (cont - 1); n++) { //1 > 2 > 3 > 4 > 2 > 0

        if (vet[(n+1)] == 0) {

            break;
        }

        int i = (vet[n] - 1), j = (vet[(n+1)] - 1);

        if((edges_Used[i][j] == 1) || (edges_Used[j][i] == 1) || (grafo->matriz[i][j] == 0)) {

            return 0;
        }

        edges_Used[i][j] = 1;
        edges_Used[j][i] = 1;
    }

    return 1;
}

int Caminho(const Grafo* grafo){

    const int tam = Tamanho_Percurso();

    if(tam < 2) {

        printf("\n\nTamanho insuficiente!\n\n");

        return 0;
    }

    int vet[tam], vet_Used[grafo->vet];

    memset(vet, 0, sizeof(vet));
    memset(vet_Used, 0, sizeof(vet_Used));

    const int cont_Route = Percurso(grafo, vet, tam);

    if(cont_Route == 0) {

        return 0;
    }

    int n;

    for (n = 0; n < (cont_Route - 1); n++) {

        /*if(vet[(n+1)] == 0) { //1 > 2 > 5 > 4

            break;
        }*/

        for(int k = 0; k < n; k++) {

            if(vet_Used[k] == vet[n]) {

                return 0;
            }
        }

        int i = (vet[n] - 1), j = (vet[(n+1)] - 1);

        if(grafo->matriz[i][j] == 0) {

            return 0;
        }

        vet_Used[n] = vet[n];
    }

    for(int i = 0; i < n; i++) {

        if(vet_Used[i] == vet[(cont_Route - 1)]) {

            return 0;
        }
    }

    return 1;
}

int Ciclo(const Grafo* grafo) {

    const int tam = Tamanho_Percurso();

    if(tam < 4) {

        printf("\nTamanho insuficiente!\n");

        return 0;
    }

    int vet[tam], vet_Used[grafo->vet];

    memset(vet, 0, sizeof(vet));
    memset(vet_Used, 0, sizeof(vet_Used));

    const int cont_Route = Percurso(grafo, vet, tam);

    if(cont_Route < 4) {

        return 0;
    }

    if(vet[0] != vet[(cont_Route - 1)]) {

        printf("\n\nPrimeiro elemento e diferente do ultimo!\n\n");

        return 0;
    }

    for(int n = 0; n < (cont_Route - 1); n++) {

        /*if(vet[(n+1)] == 0) { //4 > 2 > 5 > 4

            break;
        }*/

        for(int k = 0; k < n; k++) {

            if(vet_Used[k] == vet[n]){

                return 0;
            }
        }

        int i = (vet[n] - 1), j = (vet[(n+1)] - 1);

        if(grafo->matriz[i][j] == 0) {

            return 0;
        }

        vet_Used[n] = vet[n];
    }

    return 1;
}

#endif