#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../funcoes/categoria.h"
#include "../funcoes/BB_utils.h"
#include "../funcoes/programa.h"

Categoria* criarCategoria(TipoCategoria tipo, const char *nome) {
    Categoria *nova = (Categoria*) malloc(sizeof(Categoria));
    if (!nova) {
        fprintf(stderr, "Erro ao alocar memória para categoria.\n");
        return NULL;
    }
    nova->info.tipo = tipo;
    strcpy(nova->info.nome, nome);
    nova->programas = NULL;
    nova->esq = NULL;
    nova->dir = NULL;
    nova->altura = 1;
    return nova;
}

Categoria* inserirCategoriaBB(Categoria *raiz, Categoria *nova) {
    if (raiz != NULL) {
        int cmp = compararStrings(nova->info.nome, raiz->info.nome);

        if (cmp < 0) {
            raiz->esq = inserirCategoriaBB(raiz->esq, nova);
        } else if (cmp > 0) {
            raiz->dir = inserirCategoriaBB(raiz->dir, nova);
        } else {
            fprintf(stderr, "Categoria '%s' já cadastrada.\n", nova->info.nome);
            free(nova);
        }
        return raiz;
    }
    return nova;
}

Categoria* buscarCategoria(Categoria *raiz, const char *nome) {
    if (raiz != NULL) {
        int cmp = compararStrings(nome, raiz->info.nome);
        if (cmp == 0) {
            return raiz;
        } else if (cmp < 0) {
            return buscarCategoria(raiz->esq, nome);
        } else {
            return buscarCategoria(raiz->dir, nome);
        }
    }
    return NULL;
}

void mostrarCategorias(Categoria *raiz) {
    if (raiz != NULL) {
        mostrarCategorias(raiz->esq);
        printf("Categoria: %s (%s)\n", 
               raiz->info.nome, 
               stringCategoria(raiz->info.tipo));
        mostrarCategorias(raiz->dir);
    }
}
void liberarCategorias(Categoria *raiz) {
    if (raiz != NULL) {
        liberarCategorias(raiz->esq);
        liberarCategorias(raiz->dir);
        liberarProgramas(raiz->programas);
        free(raiz);
    }
}
