#ifndef APRESENTADOR_H
#define APRESENTADOR_H

#include "tipos.h"

Apresentador* criarApresentador(const char *nome, const char *categoria, const char *stream_atual);
void inserirApresentadorOrdenado(Apresentador **lista, Apresentador *novo);
Apresentador* buscarApresentador(Apresentador *lista, const char *nome);
void mostrarApresentadores(Apresentador *lista);
void liberarApresentadores(Apresentador *lista);

#endif