#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../funcoes/programa.h"

Programa* criarPrograma(const char *nome, Periodicidade periodicidade, int tempo, const char *horario_inicio, ModoTransmissao modo, const char *nome_apresentador) {
    // TODO: alocar memória e inicializar campos
    return NULL;
}

Programa* inserirProgramaBB(Programa *raiz, Programa *novo) {
    // TODO: inserir como BB
    return raiz;
}

Programa* buscarPrograma(Programa *raiz, const char *nome) {
    // TODO: busca binária
    return NULL;
}

void mostrarProgramas(Programa *raiz) {
    // TODO: percurso in-order
}

void liberarProgramas(Programa *raiz) {
    // TODO: liberar memória
}