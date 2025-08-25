#include <string.h>
#include <ctype.h>
#include "../funcoes/BB_utils.h"
#include <stdio.h>
#include "../funcoes/tipos.h"

// Compara strings ignorando maiúsculas/minúsculas
int compararStrings(const char *str1, const char *str2) {
    while (*str1 && *str2) {
        char c1 = tolower((unsigned char)*str1);
        char c2 = tolower((unsigned char)*str2);

        if (c1 != c2) {
            return c1 - c2;
        }

        str1++;
        str2++;
    }
    return tolower((unsigned char)*str1) - tolower((unsigned char)*str2);
}

const char* stringPeriodicidade(Periodicidade p) {
    switch (p) {
        case PERIODICIDADE_DIARIO: return "Diário";
        case PERIODICIDADE_SEMANAL: return "Semanal";
        case PERIODICIDADE_MENSAL: return "Mensal";
        default: return "Desconhecido";
    }
}

const char* stringModo(ModoTransmissao m) {
    switch (m) {
        case MODO_AOVIVO: return "Ao Vivo";
        case MODO_SOBDEMANDA: return "Sob Demanda";
        default: return "Desconhecido";
    }
}

const char* stringCategoria(TipoCategoria c) {
    switch (c) {
        case TIPO_NOTICIAS: return "Notícias";
        case TIPO_ESPORTE: return "Esportes";
        case TIPO_ENTRETENIMENTO: return "Entretenimento";
        default: return "Desconhecido";
    }
}
