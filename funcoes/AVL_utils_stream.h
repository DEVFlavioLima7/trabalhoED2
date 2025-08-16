#ifndef AVL_UTILS_STREAM_H
#define AVL_UTILS_STREAM_H

#include "tipos.h"

int alturaStream(Stream *no);
int fatorBalanceamentoStream(Stream *no);
Stream* rotacaoDireitaStream(Stream *y);
Stream* rotacaoEsquerdaStream(Stream *x);
Stream* rotacaoEsquerdaDireitaStream(Stream *no);
Stream* rotacaoDireitaEsquerdaStream(Stream *no);

#endif