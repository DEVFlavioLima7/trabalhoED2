#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../funcoes/categoria.h"
#include "../funcoes/programa.h"
#include "../funcoes/BB_utils.h"

Categoria* criarCategoria(TipoCategoria tipo, const char *nome) {
    Categoria *nova = (Categoria*) malloc(sizeof(Categoria));
    if (nova != NULL) {
        nova->tipo = tipo;
        strcpy(nova->nome, nome);

        nova->programas = NULL; // árvore de programas começa vazia
        nova->esq = NULL;
        nova->dir = NULL;
        nova->altura = 1; // compatível com AVL
    } else {
        fprintf(stderr, "Erro ao alocar memória para Categoria.\n");
    }
    return nova;
}

Categoria* inserirCategoriaBB(Categoria *raiz, Categoria *nova) {
    
    if (raiz != NULL) {
        int cmp = compararStrings(nova->nome, raiz->nome);

        if (cmp < 0) {
            raiz->esq = inserirCategoriaBB(raiz->esq, nova);
        } else if (cmp > 0) {
            raiz->dir = inserirCategoriaBB(raiz->dir, nova);
        } else {
            // Nome duplicado → libera memória
            fprintf(stderr, "Categoria '%s' já cadastrada.\n", nova->nome);
            free(nova);
        }
        return raiz;  // retorna a raiz existente
    }
    return nova;
}

Categoria* buscarCategoria(Categoria *raiz, const char *nome) {
    if (raiz != NULL) {
        int cmp = compararStrings(nome, raiz->nome);
        if (cmp == 0) {
            return raiz; // Encontrou
        } else if (cmp < 0) {
            return buscarCategoria(raiz->esq, nome); // Busca à esquerda
        } else {
            return buscarCategoria(raiz->dir, nome); // Busca à direita
        }
    }
    return NULL;
}

void mostrarCategorias(Categoria *raiz) {
    // percurso in-order
    if (raiz != NULL) {
        mostrarCategorias(raiz->esq); // Visita esquerda
        printf("Categoria: %s\n", raiz->nome); // Imprime nome da categoria
        mostrarCategorias(raiz->dir); // Visita direita
    }
}

void liberarCategorias(Categoria *raiz) {
    //libera em post-order
    if (raiz != NULL) {
        liberarCategorias(raiz->esq);      // Libera subárvore esquerda
        liberarCategorias(raiz->dir);      // Libera subárvore direita
        //liberarProgramas(raiz->programas); // Libera a árvore de programas
        free(raiz);                         // Libera o nó atual
    }
}
