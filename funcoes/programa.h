#ifndef PROGRAMA_H
#define PROGRAMA_H
#include "tipos.h"

typedef struct programa {
    char nome[100];
    Periodicidade periodicidade;
    int tempo;                   // duração em minutos
    char horario_inicio[20];
    ModoTransmissao modo;
    char nome_apresentador[100];

    struct apresentador *apresentadores; // ainda vai ser implementado

    struct programa *esq;
    struct programa *dir;
    int altura;
} Programa;

Programa* criarPrograma(const char *nome, Periodicidade periodicidade, int tempo, const char *horario_inicio, ModoTransmissao modo, const char *nome_apresentador);
Programa* inserirProgramaBB(Programa *raiz, Programa *novo);
Programa* inserirProgramaAVL(Programa *raiz, Programa *novo);
Programa* buscarPrograma(Programa *raiz, const char *nome);
void mostrarProgramas(Programa *raiz);
void liberarProgramas(Programa *raiz);

#endif