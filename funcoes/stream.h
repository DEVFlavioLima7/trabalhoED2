#ifndef STREAM_H
#define STREAM_H
#include "tipos.h"
#include "categoria.h"


Stream* criarStream(const char *nome, const char *site);
Stream* inserirStreamBB(Stream *raiz, Stream *nova);
Stream* inserirStreamAVL(Stream *raiz, Stream *nova);
Stream* buscarStream(Stream *raiz, const char *nome);
void mostrarStreams(Stream *raiz);
void liberarStreams(Stream *raiz);

#endif