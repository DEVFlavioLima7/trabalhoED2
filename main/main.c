#include <stdio.h>
#include <stdlib.h>
#include "../funcoes/stream.h"
#include "../funcoes/categoria.h"
#include "../funcoes/BB_utils.h"

int main() {
    // Criar algumas streams
    Stream *raiz = NULL;
    raiz = inserirStreamBB(raiz, criarStream("Netflix", "www.netflix.com"));
    raiz = inserirStreamBB(raiz, criarStream("Disney+", "www.disneyplus.com"));
    raiz = inserirStreamBB(raiz, criarStream("Amazon Prime", "www.primevideo.com"));

    printf("\n--- LISTA DE STREAMS ---\n");
    mostrarStreams(raiz);

    // Buscar uma stream
    printf("\n--- TESTE BUSCA STREAM ---\n");
    Stream *buscaStream = buscarStream(raiz, "Disney+");
    if (buscaStream) {
        printf("Encontrada: %s (%s)\n", buscaStream->nome, buscaStream->site);
    } else {
        printf("Stream nao encontrada.\n");
    }

    // Inserir categorias dentro da Netflix
    Stream *netflix = buscarStream(raiz, "Netflix");
    if (netflix) {
        netflix->categorias = inserirCategoriaBB(netflix->categorias, criarCategoria(TIPO_ESPORTE, "Esportes"));
        netflix->categorias = inserirCategoriaBB(netflix->categorias, criarCategoria(TIPO_ENTRETENIMENTO, "Filmes e Séries"));
        netflix->categorias = inserirCategoriaBB(netflix->categorias, criarCategoria(TIPO_NOTICIAS, "Notícias"));

        printf("\n--- Categorias da Netflix ---\n");
        mostrarCategorias(netflix->categorias);

        // Buscar uma categoria
        printf("\n--- TESTE BUSCA CATEGORIA ---\n");
        Categoria *buscaCat = buscarCategoria(netflix->categorias, "Esportes");
        if (buscaCat) {
            printf("Categoria encontrada: %s (tipo %d)\n", buscaCat->nome, buscaCat->tipo);
        } else {
            printf("Categoria nao encontrada.\n");
        }
    }

    // Liberar memória
    liberarStreams(raiz);

    return 0;
}
