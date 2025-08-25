#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../funcoes/apresentador.h"
#include "../funcoes/BB_utils.h"

Apresentador* criarApresentador(const char *nome, const char *categoria, const char *stream_atual) {
    Apresentador *novo = (Apresentador*) malloc(sizeof(Apresentador));
    if (!novo) {
        fprintf(stderr, "Erro ao alocar memoria para apresentador.\n");
        return NULL;
    }
    strncpy(novo->info.nome, nome, sizeof(novo->info.nome));
    strncpy(novo->info.categoria, categoria, sizeof(novo->info.categoria));
    strncpy(novo->info.stream_atual, stream_atual, sizeof(novo->info.stream_atual));
    novo->info.qtd_historico = 0;
    novo->prox = NULL;
    novo->ant = NULL;
    return novo;
}

void inserirApresentadorOrdenado(Apresentador **lista, Apresentador *novo) {
    if (*lista == NULL) {
        *lista = novo;
        return;
    }

    Apresentador *atual = *lista;
    while(atual && strcmp(atual->info.nome, novo->info.nome) < 0) {
        atual = atual->prox;
    }

    if (!atual) {
        Apresentador *ultimo = *lista;
        while(ultimo->prox) {
            ultimo = ultimo->prox;
        }
        ultimo->prox = novo;
        novo->ant = ultimo;
    } else if (!atual->ant) {
        novo->prox = *lista;
        (*lista)->ant = novo;
        *lista = novo;
    } else {
        novo->prox = atual;
        novo->ant = atual->ant;
        atual->ant->prox = novo;
        atual->ant = novo;
    }
}

Apresentador* buscarApresentador(Apresentador *lista, const char *nome) {
    Apresentador *atual = lista;
    while(atual) {
        if (strcmp(atual->info.nome, nome) == 0) {
            return atual;
        }
        atual = atual->prox;
    }
    return NULL;
}

void mostrarApresentadores(Apresentador *lista) {
    Apresentador *atual = lista;
    while (atual) {
        printf("Nome: %s, Categoria: %s, Stream Atual: %s\n",
               atual->info.nome,
               atual->info.categoria,
               atual->info.stream_atual);
        atual = atual->prox;
    }
}

void mostrarApresentadoresPorStream(Apresentador *lista, const char *streamNome) {
    Apresentador *atual = lista;
    while (atual) {
        if (strcmp(atual->info.stream_atual, streamNome) == 0) {
            printf("Apresentador: %s | Categoria: %s\n", 
                   atual->info.nome, atual->info.categoria);
        }
        atual = atual->prox;
    }
}

void mostrarApresentadoresPorCategoria(Apresentador *lista, const char *categoria) {
    Apresentador *atual = lista;
    while (atual) {
        if (strcmp(atual->info.categoria, categoria) == 0) {
            printf("Apresentador: %s | Stream Atual: %s\n", 
                   atual->info.nome, atual->info.stream_atual);
        }
        atual = atual->prox;
    }
}

void liberarApresentadores(Apresentador *lista) {
    Apresentador *atual = lista;
    while(atual) {
        Apresentador *temp = atual;
        atual = atual->prox;
        free(temp);
    }
}
