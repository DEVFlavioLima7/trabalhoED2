#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../funcoes/stream.h"
#include "../funcoes/BB_utils.h"

// Cria uma nova stream
Stream* criarStream(const char *nome, const char *site) {

    Stream *nova = (Stream*)malloc(sizeof(Stream));
    // TODO: alocar memória e inicializar campos
    if (!nova) {
        fprintf(stderr, "Erro ao alocar memória na stream.\n");
        return NULL;
    }
    strcpy(nova->nome, nome);
    strcpy(nova->site, site);

    nova->categorias = NULL; // Inicializa a árvore de categorias como vazia
    nova->esq = NULL; // Inicializa o ponteiro esquerdo como NULL 
    nova->dir = NULL; // Inicializa o ponteiro direito como NULL
    nova->altura = 1; // Inicializa a altura como 1 (árvore AVL)

    return nova;
}


Stream* inserirStreamBB(Stream *raiz, Stream *nova) {
    if (raiz != NULL) {
        int cmp = compararStrings(nova->nome, raiz->nome);

        if (cmp < 0) {
            raiz->esq = inserirStreamBB(raiz->esq, nova);
        } 
        else if (cmp > 0) {
            raiz->dir = inserirStreamBB(raiz->dir, nova);
        } 
        else {
            // Nome duplicado → libera memória
            fprintf(stderr, "Stream '%s' já cadastrada.\n", nova->nome);
            free(nova);
        }
        return raiz;  // retorna a raiz existente
    }

    // Caso base → insere quando chegar em NULL
    return nova;
}

// Busca por nome
Stream* buscarStream(Stream *raiz, const char *nome) {
    if (raiz != NULL) {
        int cmp = compararStrings(nome, raiz->nome);
        if (cmp == 0) {
            return raiz; // Encontrou
        } else if (cmp < 0) {
            return buscarStream(raiz->esq, nome); // Busca à esquerda
        } else {
            return buscarStream(raiz->dir, nome); // Busca à direita
        }
    }
    return NULL; // Não encontrou
}

// Mostra todas as streams
void mostrarStreams(Stream *raiz) {
    if (raiz != NULL) {
        mostrarStreams(raiz->esq); // Percorre a subárvore esquerda
        printf("Nome: %s | Site: %s\n", raiz->nome, raiz->site); // Mostra a stream atual
        mostrarStreams(raiz->dir); // Percorre a subárvore direita
    }
}

// Libera memória
void liberarStreams(Stream *raiz) {
    if (raiz != NULL) {
        liberarStreams(raiz->esq);      // Libera subárvore esquerda
        liberarStreams(raiz->dir);      // Libera subárvore direita
        liberarCategorias(raiz->categorias); // Libera as categorias da stream
        free(raiz);                     // Libera o nó atual
    }
}