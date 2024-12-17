#ifndef ASSINATURAS_H
#define ASSINATURAS_H

#define LIMITE 100

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

typedef struct {

    int** matriz;
    int vet,ares;

}Grafo;

Grafo* Cria_Grafo(bool* flag_grafo);
Grafo* Reset_Grafo(Grafo* grafo, bool* flag_grafo, bool* flag_vet, bool* flag_ares);

int Passeio(const Grafo* grafo);
int Trilha(const Grafo* grafo);
int Caminho(const Grafo* grafo);
int Ciclo(const Grafo* grafo);
int Menu();
int Tamanho_Percurso();
int Percurso(const Grafo* grafo, int* vet, const int tam);

bool Percurso_Valido(const Grafo* grafo, const int vet);
bool Verifica_Flag(bool flag_grafo, bool flag_vet, bool flag_ares);

void Selection(Grafo* grafo);
void Aloca_Memoria_Vertices(Grafo* grafo);
void Cria_Vertices(Grafo* grafo, bool* flag_vet);
void Cria_Arestas(Grafo* grafo, bool* flag_ares);
void Quantidade_Vet_Ares(const Grafo* grafo);
void Imprime_Grafo(Grafo* grafo);
void Grafo_Complementar(Grafo* grafo);
void Libera_Memoria(Grafo* grafo);

#endif //ASSINATURAS_H