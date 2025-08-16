#ifndef AVL_UTILS_PROGRAMA_H
#define AVL_UTILS_PROGRAMA_H

#include "tipos.h"

int alturaPrograma(Programa *no);
int fatorBalanceamentoPrograma(Programa *no);
Programa* rotacaoDireitaPrograma(Programa *y);
Programa* rotacaoEsquerdaPrograma(Programa *x);
Programa* rotacaoEsquerdaDireitaPrograma(Programa *no);
Programa* rotacaoDireitaEsquerdaPrograma(Programa *no);

#endif