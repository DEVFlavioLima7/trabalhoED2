#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../funcoes/stream.h"

// Cria uma nova stream
Stream* criarStream(const char *nome, const char *site) {
    // TODO: alocar memória e inicializar campos
    return NULL;
}

// Insere na BST
Stream* inserirStreamBB(Stream *raiz, Stream *nova) {
    // TODO: implementar inserção na BST (ordenado pelo nome)
    return raiz;
}

// Busca por nome
Stream* buscarStream(Stream *raiz, const char *nome) {
    // TODO: busca binária
    return NULL;
}

// Mostra todas as streams
void mostrarStreams(Stream *raiz) {
    // TODO: percurso in-order
}

// Libera memória
void liberarStreams(Stream *raiz) {
    // TODO: liberar categorias e a própria stream
}