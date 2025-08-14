#ifndef PROGRAMA_H
#define PROGRAMA_H

#include "tipos.h"

Programa* criarPrograma(const char *nome, Periodicidade periodicidade, int tempo, const char *horario_inicio, ModoTransmissao modo, const char *nome_apresentador);
Programa* inserirProgramaBB(Programa *raiz, Programa *novo);
Programa* inserirProgramaAVL(Programa *raiz, Programa *novo);
Programa* buscarPrograma(Programa *raiz, const char *nome);
void mostrarProgramas(Programa *raiz);
void liberarProgramas(Programa *raiz);

#endif