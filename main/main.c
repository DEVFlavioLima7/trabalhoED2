#include <stdio.h>
#include <stdlib.h>
#include "../funcoes/stream.h"
#include "../funcoes/categoria.h"
#include "../funcoes/programa.h"
#include "../funcoes/apresentador.h"
#include "../funcoes/BB_utils.h"

// Funções extras
void mostrarStreamsComCategoria(Stream *raiz, const char *categoriaNome);
void mostrarProgramasPorDiaHorario(Programa *raiz, const char *dia, const char *horario);
void mostrarStreamsPorTipoCategoria(Stream *raiz, TipoCategoria tipo);
void mostrarProgramasPorDiaCategoria(Programa *raiz, const char *dia);
void mostrarApresentadoresPorStream(Apresentador *lista, const char *streamNome);
void mostrarApresentadoresPorCategoria(Apresentador *lista, const char *categoria);

int main() {
    // ================= STREAMS =================
    printf("\n--- LISTA DE STREAMS ---\n");
    Stream *streams = NULL;
    streams = inserirStreamBB(streams, criarStream("Netflix", "www.netflix.com"));
    streams = inserirStreamBB(streams, criarStream("Amazon Prime", "www.primevideo.com"));
    streams = inserirStreamBB(streams, criarStream("Disney+", "www.disneyplus.com"));
    mostrarStreams(streams);

    // ================= CATEGORIAS =================
    printf("\n--- Categorias da Netflix ---\n");
    Stream *netflix = buscarStream(streams, "Netflix");
    if (netflix) {
        netflix->categorias = inserirCategoriaBB(netflix->categorias, criarCategoria(TIPO_ESPORTE, "Esportes"));
        netflix->categorias = inserirCategoriaBB(netflix->categorias, criarCategoria(TIPO_ENTRETENIMENTO, "Filmes e Séries"));
        netflix->categorias = inserirCategoriaBB(netflix->categorias, criarCategoria(TIPO_NOTICIAS, "Notícias"));
        mostrarCategorias(netflix->categorias);
    }

    // ================= PROGRAMAS =================
    printf("\n--- Programas em Esportes ---\n");
    Categoria *esportes = buscarCategoria(netflix->categorias, "Esportes");
    if (esportes) {
        esportes->programas = inserirProgramaBB(esportes->programas,
                            criarPrograma("Futebol ao Vivo", PERIODICIDADE_SEMANAL, 120, "20:00", "Domingo", MODO_AOVIVO, "João Silva"));
        esportes->programas = inserirProgramaBB(esportes->programas,
                            criarPrograma("Bola na Rede", PERIODICIDADE_DIARIO, 60, "18:00", "Segunda", MODO_SOBDEMANDA, "Maria Souza"));
        mostrarProgramas(esportes->programas);
    }

    // ================= APRESENTADORES =================
    printf("\n--- Apresentadores ---\n");
    Apresentador *apresentadores = NULL;
    inserirApresentadorOrdenado(&apresentadores, criarApresentador("Carlos Mendes", "Esporte", "Netflix"));
    inserirApresentadorOrdenado(&apresentadores, criarApresentador("Ana Paula", "Notícias", "Disney+"));
    inserirApresentadorOrdenado(&apresentadores, criarApresentador("Beatriz Lima", "Entretenimento", "Amazon Prime"));
    mostrarApresentadores(apresentadores);

    // ================= TESTES DOS REQUISITOS NOVOS =================

    // (viii) Streams que têm a categoria "Esportes"
    printf("\n--- Streams com categoria 'Esportes' ---\n");
    mostrarStreamsComCategoria(streams, "Esportes");

    // (ix) Programas em Esportes na Netflix que acontecem Segunda às 18:00
    printf("\n--- Programas na categoria 'Esportes' da Netflix em Segunda às 18:00 ---\n");
    mostrarProgramasPorDiaHorario(esportes->programas, "Segunda", "18:00");

    // (x) Streams que têm tipo de categoria ESPORTE
    printf("\n--- Streams com tipo de categoria ESPORTE ---\n");
    mostrarStreamsPorTipoCategoria(streams, TIPO_ESPORTE);

    // (xi) Programas de Segunda em Esportes da Netflix
    printf("\n--- Programas de Segunda em Esportes da Netflix ---\n");
    mostrarProgramasPorDiaCategoria(esportes->programas, "Segunda");

    // (xii) Apresentadores da Netflix
    printf("\n--- Apresentadores da Netflix ---\n");
    mostrarApresentadoresPorStream(apresentadores, "Netflix");

    // (xiii) Apresentadores da categoria Notícias
    printf("\n--- Apresentadores da categoria Notícias ---\n");
    mostrarApresentadoresPorCategoria(apresentadores, "Notícias");

    // ================= LIBERAR MEMÓRIA =================
    liberarStreams(streams);
    liberarApresentadores(apresentadores);

    return 0;
}
