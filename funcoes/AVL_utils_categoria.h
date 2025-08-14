#ifndef AVL_UTILS_CATEGORIA_H
#define AVL_UTILS_CATEGORIA_H

#include "tipos.h"

int alturaCategoria(Categoria *no);
int fatorBalanceamentoCategoria(Categoria *no);
Categoria* rotacaoDireitaCategoria(Categoria *y);
Categoria* rotacaoEsquerdaCategoria(Categoria *x);
Categoria* rotacaoEsquerdaDireitaCategoria(Categoria *no);
Categoria* rotacaoDireitaEsquerdaCategoria(Categoria *no);

#endif