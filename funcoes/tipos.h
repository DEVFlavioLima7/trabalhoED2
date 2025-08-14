#ifndef TIPOS_H
#define TIPOS_H

typedef enum {
    TIPO_NOTICIAS,
    TIPO_ESPORTE,
    TIPO_ENTRETENIMENTO,
} TipoCategoria;

typedef enum {
    PERIODICIDADE_DIARIO,
    PERIODICIDADE_SEMANAL,
    PERIODICIDADE_MENSAL
} Periodicidade;

typedef enum {
    MODO_AOVIVO,
    MODO_SOBDEMANDA
} ModoTransmissao;


// Programa (nó da árvore de programas)
typedef struct Programa {
    char nome[100];
    Periodicidade periodicidade;
    int tempo;                 
    char horario_inicio[6];     
    ModoTransmissao modo;
    char nome_apresentador[100];
    struct Programa *esq;
    struct Programa *dir;
    int altura; 
} Programa;


// Categoria (nó da árvore de categorias)
typedef struct Categoria {
    TipoCategoria tipo;
    char nome[100];
    Programa *programas;        
    struct Categoria *esq;
    struct Categoria *dir;
    int altura; 
} Categoria;

// Lista de streams que um apresentador já trabalhou
typedef struct HistoricoStream {
    char nome[100];
    char data_inicio[11]; 
    char data_fim[11];
} HistoricoStream;

// Apresentador (lista duplamente encadeada)
typedef struct Apresentador {
    char nome[100];
    char categoria[100];
    char stream_atual[100];
    HistoricoStream historico[50];
    int qtd_historico;
    struct Apresentador *ant;
    struct Apresentador *prox;
} Apresentador;

// Stream (nó da árvore de streams)
typedef struct Stream {
    char nome[100];
    char site[100];
    Categoria *categorias;      // árvore de categorias
    struct Stream *esq;
    struct Stream *dir;
    int altura; // usado para AVL
} Stream;

#endif