#include <stdio.h>
#include <stdlib.h>
#include "../funcoes/stream.h"
#include "../funcoes/BB_utils.h"

int main() {
    Stream *raiz = NULL;

    // Criando algumas streams
    Stream *s1 = criarStream("Netflix", "www.netflix.com");
    Stream *s2 = criarStream("Amazon Prime", "www.primevideo.com");
    Stream *s3 = criarStream("Disney+", "www.disneyplus.com");
    Stream *s4 = criarStream("HBO Max", "www.hbomax.com");

    // Inserindo na BST
    raiz = inserirStreamBB(raiz, s1);
    raiz = inserirStreamBB(raiz, s2);
    raiz = inserirStreamBB(raiz, s3);
    raiz = inserirStreamBB(raiz, s4);

    // Mostrar todas as streams (ordem alfabética)
    printf("\n--- LISTA DE STREAMS ---\n");
    mostrarStreams(raiz);

    // Testar busca
    printf("\n--- TESTE DE BUSCA ---\n");
    Stream *busca = buscarStream(raiz, "Disney+");
    if (busca) {
        printf("Encontrada: %s (%s)\n", busca->nome, busca->site);
    } else {
        printf("Stream nao encontrada.\n");
    }

    // Teste de busca inexistente
    busca = buscarStream(raiz, "GloboPlay");
    if (busca) {
        printf("Encontrada: %s (%s)\n", busca->nome, busca->site);
    } else {
        printf("Stream nao encontrada.\n");
    }

    // Liberar memória
    liberarStreams(raiz);

    return 0;
}
