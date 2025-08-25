#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../funcoes/programa.h"
#include "../funcoes/BB_utils.h"

Programa* criarPrograma(const char *nome, Periodicidade periodicidade, int tempo,
                        const char *horario_inicio, const char *dia_semana,
                        ModoTransmissao modo, const char *nome_apresentador) {
    Programa *novo = (Programa*) malloc(sizeof(Programa));
    if (!novo) {
        fprintf(stderr, "Erro ao alocar memória para programa.\n");
        return NULL;
    }
    strcpy(novo->info.nome, nome);
    novo->info.periodicidade = periodicidade;
    novo->info.tempo = tempo;
    strcpy(novo->info.horario_inicio, horario_inicio);
    strcpy(novo->info.dia_semana, dia_semana);
    novo->info.modo = modo;
    strcpy(novo->info.nome_apresentador, nome_apresentador);

    novo->esq = novo->dir = NULL;
    novo->altura = 1;
    return novo;
}

Programa* inserirProgramaBB(Programa *raiz, Programa *novo) {
    if (raiz != NULL) {
        int cmp = compararStrings(novo->info.nome, raiz->info.nome);

        if (cmp < 0) {
            raiz->esq = inserirProgramaBB(raiz->esq, novo);
        } else if (cmp > 0) {
            raiz->dir = inserirProgramaBB(raiz->dir, novo);
        } else {
            fprintf(stderr, "Programa '%s' ja cadastrado.\n", novo->info.nome);
            free(novo);
        }
        return raiz;
    }
    return novo;
}

Programa* buscarPrograma(Programa *raiz, const char *nome) {
    if (raiz != NULL) {
        int cmp = compararStrings(nome, raiz->info.nome);
        if (cmp == 0) {
            return raiz;
        } else if (cmp < 0) {
            return buscarPrograma(raiz->esq, nome);
        } else {
            return buscarPrograma(raiz->dir, nome);
        }
    }
    return NULL;
}

void mostrarProgramas(Programa *raiz) {
    if (raiz != NULL) {
        mostrarProgramas(raiz->esq);
        printf("Programa: %s, Periodicidade: %s, Tempo: %d min, Horario: %s, Modo: %s, Apresentador: %s\n",
               raiz->info.nome,
               stringPeriodicidade(raiz->info.periodicidade),
               raiz->info.tempo,
               raiz->info.horario_inicio,
               stringModo(raiz->info.modo),
               raiz->info.nome_apresentador);
        mostrarProgramas(raiz->dir);
    }
}

void mostrarProgramasPorDiaHorario(Programa *raiz, const char *dia, const char *horario) {
    if (!raiz) return;
    mostrarProgramasPorDiaHorario(raiz->esq, dia, horario);

    if (strcmp(raiz->info.dia_semana, dia) == 0 &&
        strcmp(raiz->info.horario_inicio, horario) == 0) {
        printf("Programa: %s (%s às %s)\n", raiz->info.nome, dia, horario);
    }

    mostrarProgramasPorDiaHorario(raiz->dir, dia, horario);
}

void mostrarProgramasPorDiaCategoria(Programa *raiz, const char *dia) {
    if (!raiz) return;
    mostrarProgramasPorDiaCategoria(raiz->esq, dia);

    if (strcmp(raiz->info.dia_semana, dia) == 0) {
        printf("Programa: %s (%s às %s)\n", raiz->info.nome, dia, raiz->info.horario_inicio);
    }

    mostrarProgramasPorDiaCategoria(raiz->dir, dia);
}

void liberarProgramas(Programa *raiz) {
    if (raiz != NULL) {
        liberarProgramas(raiz->esq);
        liberarProgramas(raiz->dir);
        free(raiz);
    }
}
