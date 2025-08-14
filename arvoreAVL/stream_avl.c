#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../funcoes/stream.h"

// Cria nova stream (mesmo da BST)
Stream* criarStream(const char *nome, const char *site) {
    // TODO: alocar memória e inicializar campos
    return NULL;
}

// Funções auxiliares AVL (altura, rotação simples/d dupla) vão no avl_utils.c

// Insere na AVL
Stream* inserirStreamAVL(Stream *raiz, Stream *nova) {
    // TODO: inserir como BST + balancear
    return raiz;
}

// Busca
Stream* buscarStream(Stream *raiz, const char *nome) {
    // TODO: busca binária
    return NULL;
}

// Mostrar
void mostrarStreams(Stream *raiz) {
    // TODO: percurso in-order
}

// Liberar
void liberarStreams(Stream *raiz) {
    // TODO: liberar categorias e a própria stream
}