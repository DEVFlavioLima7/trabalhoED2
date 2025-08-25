#ifndef TIPOS_H
#define TIPOS_H

// ---------------- ENUMS ----------------
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

// ---------------- INFO STRUCTS ----------------
// Dados de um programa
typedef struct {
    char nome[100];
    Periodicidade periodicidade;
    int tempo;                 
    char horario_inicio[6];     // Ex: "20:00"
    char dia_semana[15];        // Ex: "Segunda", "Terça"
    ModoTransmissao modo;
    char nome_apresentador[100];
} InfoPrograma;

// Dados de uma categoria
typedef struct {
    TipoCategoria tipo;
    char nome[100];
} InfoCategoria;

// Dados de uma stream
typedef struct {
    char nome[100];
    char site[100];
} InfoStream;

// Histórico de apresentadores
typedef struct {
    char nome[100];
    char data_inicio[11]; 
    char data_fim[11];
} HistoricoStream;

// ---------------- NÓS DAS ESTRUTURAS ----------------

// Programa (nó da árvore de programas)
typedef struct Programa {
    InfoPrograma info;          // Dados do programa
    struct Programa *esq;
    struct Programa *dir;
    int altura; 
} Programa;

// Categoria (nó da árvore de categorias)
typedef struct Categoria {
    InfoCategoria info;         // Dados da categoria
    Programa *programas;        // Árvore de programas
    struct Categoria *esq;
    struct Categoria *dir;
    int altura; 
} Categoria;

// Apresentador (lista duplamente encadeada)
typedef struct ApresentadorInfo {
    char nome[100];
    char categoria[100];
    char stream_atual[100];
    HistoricoStream historico[50];
    int qtd_historico;
} ApresentadorInfo;

typedef struct Apresentador {
    ApresentadorInfo info;  
    struct Apresentador *ant;
    struct Apresentador *prox;
} Apresentador;

// Stream (nó da árvore de streams)
typedef struct Stream {
    InfoStream info;            // Dados da stream
    Categoria *categorias;      // Árvore de categorias
    struct Stream *esq;
    struct Stream *dir;
    int altura; 
} Stream;

#endif
