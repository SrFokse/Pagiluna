#ifndef CATALOGO_H
#define CATALOGO_H

//macros para comparacao e acesso a chave
#define chave(A) (A.chave)
#define menor(A, B) ((A) < (B))
#define igual(A, B) ((A) == (B))

typedef int tipoT;
typedef struct Livro {
    tipoT chave;
    char titulo[100];
    char autor[30];
    char genero[20];
    char editora[30];
    char anoPublicacao[5];
    char notasPessoais[100];
} Livro;

typedef struct No {
    Livro item;
    struct No *esquerda, *direita;
} NoBST;

//funcoes para manipulacao e gerenciamento do catalogo de livros
Livro criarLivro(); //cria um livro com os dados inseridos pelo usuario
void buscarLivro(NoBST *raiz); //busca um livro e exibe os dados
void imprimirCatalogo(NoBST *raiz); //imprime o catalogo de livros
void liberarArvore(NoBST *raiz); //libera a memoria alocada para a arvore

#endif