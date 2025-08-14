#ifndef CATEGORIA_H
#define CATEGORIA_H

#include "tipos.h"

Categoria* criarCategoria(TipoCategoria tipo, const char *nome);
Categoria* inserirCategoriaABB(Categoria *raiz, Categoria *nova);
Categoria* inserirCategoriaAVL(Categoria *raiz, Categoria *nova);
Categoria* buscarCategoria(Categoria *raiz, const char *nome);
void mostrarCategorias(Categoria *raiz);
void liberarCategorias(Categoria *raiz);

#endif