#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../funcoes/stream.h"
#include "../funcoes/BB_utils.h"

Stream* criarStream(const char *nome, const char *site) {
    Stream *nova = (Stream*) malloc(sizeof(Stream));
    if (!nova) {
        fprintf(stderr, "Erro ao alocar memória na stream.\n");
        return NULL;
    }
    strcpy(nova->info.nome, nome);
    strcpy(nova->info.site, site);

    nova->categorias = NULL;
    nova->esq = NULL;
    nova->dir = NULL;
    nova->altura = 1;
    return nova;
}

Stream* inserirStreamBB(Stream *raiz, Stream *nova) {
    if (raiz != NULL) {
        int cmp = compararStrings(nova->info.nome, raiz->info.nome);

        if (cmp < 0) {
            raiz->esq = inserirStreamBB(raiz->esq, nova);
        } else if (cmp > 0) {
            raiz->dir = inserirStreamBB(raiz->dir, nova);
        } else {
            fprintf(stderr, "Stream '%s' já cadastrada.\n", nova->info.nome);
            free(nova);
        }
        return raiz;
    }
    return nova;
}

Stream* buscarStream(Stream *raiz, const char *nome) {
    if (raiz != NULL) {
        int cmp = compararStrings(nome, raiz->info.nome);
        if (cmp == 0) {
            return raiz;
        } else if (cmp < 0) {
            return buscarStream(raiz->esq, nome);
        } else {
            return buscarStream(raiz->dir, nome);
        }
    }
    return NULL;
}

void mostrarStreams(Stream *raiz) {
    if (raiz != NULL) {
        mostrarStreams(raiz->esq);
        printf("Nome: %s | Site: %s\n", raiz->info.nome, raiz->info.site);
        mostrarStreams(raiz->dir);
    }
}

void mostrarStreamsComCategoria(Stream *raiz, const char *categoriaNome) {
    if (!raiz) return;
    mostrarStreamsComCategoria(raiz->esq, categoriaNome);

    if (buscarCategoria(raiz->categorias, categoriaNome)) {
        printf("Stream: %s\n", raiz->info.nome);
    }

    mostrarStreamsComCategoria(raiz->dir, categoriaNome);
}

void mostrarStreamsPorTipoCategoria(Stream *raiz, TipoCategoria tipo) {
    if (!raiz) return;
    mostrarStreamsPorTipoCategoria(raiz->esq, tipo);

    Categoria *atual = raiz->categorias;
    while (atual) {
        if (atual->info.tipo == tipo) {
            printf("Stream: %s tem categoria %s\n", raiz->info.nome, atual->info.nome);
            break;
        }
        atual = atual->esq; // percorre subárvore esquerda
    }

    mostrarStreamsPorTipoCategoria(raiz->dir, tipo);
}

void liberarStreams(Stream *raiz) {
    if (raiz != NULL) {
        liberarStreams(raiz->esq);
        liberarStreams(raiz->dir);
        liberarCategorias(raiz->categorias);
        free(raiz);
    }
}
