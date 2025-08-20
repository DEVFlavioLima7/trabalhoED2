#ifndef STREAM_H
#define STREAM_H
#include "tipos.h"
#include "categoria.h"
typedef struct stream {
    char nome[100];
    char site[100];
    struct categoria *categorias; 
    struct stream *esq;
    struct stream *dir;
    int altura; 
} Stream;


Stream* criarStream(const char *nome, const char *site);
Stream* inserirStreamBB(Stream *raiz, Stream *nova);
Stream* inserirStreamAVL(Stream *raiz, Stream *nova);
Stream* buscarStream(Stream *raiz, const char *nome);
void mostrarStreams(Stream *raiz);
void liberarStreams(Stream *raiz);

#endif