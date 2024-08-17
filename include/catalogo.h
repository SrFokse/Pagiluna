#ifndef CATALOGO_H
#define CATALOGO_H

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

Livro criarLivro();
NoBST *novoNo(Livro novoLivro, NoBST *esquerda, NoBST *direita);
NoBST *inserirNo(NoBST *raiz, NoBST *novo);
NoBST *editarNo(NoBST *raiz, Livro livroAtualizado);
NoBST *excluirNo(NoBST *raiz, tipoT excluir);
NoBST *buscarBST(NoBST *no, tipoT busca);

#endif