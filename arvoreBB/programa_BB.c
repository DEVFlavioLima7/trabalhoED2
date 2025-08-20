#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../funcoes/programa.h"

Programa* criarPrograma(const char *nome, Periodicidade periodicidade, int tempo, const char *horario_inicio, ModoTransmissao modo, const char *nome_apresentador) {
    // TODO: alocar memória e inicializar campos
    Programa *novo = (Programa*) malloc(sizeof(Programa));
    if (!novo) {
        fprintf(stderr, "Erro ao alocar memória para programa.\n");
        return NULL;
    }

    strcpy(novo->nome, nome);
    novo->periodicidade = periodicidade;
    novo->tempo = tempo;
    strcpy(novo->horario_inicio, horario_inicio);
    novo->modo = modo;
    strcpy(novo->nome_apresentador, nome_apresentador);

    novo->apresentadores = NULL; // árvore de apresentadores ainda vazia
    novo->esq = NULL;
    novo->dir = NULL;
    novo->altura = 1; // inicializado com 1 (para futura AVL)

    return novo;
}

Programa* inserirProgramaBB(Programa *raiz, Programa *novo) {
    
    if (raiz != NULL) {
        int cmp = compararStrings(novo->nome, raiz->nome);

        if (cmp < 0) {
            raiz->esq = inserirProgramaBB(raiz->esq, novo);
        } else if (cmp > 0) {
            raiz->dir = inserirProgramaBB(raiz->dir, novo);
        } else {
            // Nome duplicado → libera memória
            fprintf(stderr, "Programa '%s' já cadastrado.\n", novo->nome);
            free(novo);
        }
        return raiz;  // retorna a raiz existente
    }
    return novo;
}

Programa* buscarPrograma(Programa *raiz, const char *nome) {
    
    if (raiz != NULL) {
        int cmp = compararStrings(nome, raiz->nome);
        if (cmp == 0) {
            return raiz; // Encontrou
        } else if (cmp < 0) {
            return buscarPrograma(raiz->esq, nome); // Busca à esquerda
        } else {
            return buscarPrograma(raiz->dir, nome); // Busca à direita
        }
    }
    return NULL;
}

void mostrarProgramas(Programa *raiz) {
    // TODO: percurso in-order
    if (raiz != NULL) {
        mostrarProgramas(raiz->esq); // Visita esquerda
        printf("Programa: %s, Periodicidade: %d, Tempo: %d, Horário: %s, Modo: %d, Apresentador: %s\n",
               raiz->nome, raiz->periodicidade, raiz->tempo, raiz->horario_inicio, raiz->modo, raiz->nome_apresentador);
        mostrarProgramas(raiz->dir); // Visita direita
    }
}

void liberarProgramas(Programa *raiz) {
    if (raiz != NULL) {
        liberarProgramas(raiz->esq); // Libera subárvore esquerda
        liberarProgramas(raiz->dir); // Libera subárvore direita
        free(raiz);                  // Libera o nó atual
    }
}