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
NoBST *novoNo(Livro novoLivro, NoBST *esquerda, NoBST *direita); //cria um novo no para a arvore
NoBST *inserirNo(NoBST *raiz, NoBST *novo); //insere novo no na arvore
NoBST *editarNo(NoBST *raiz, Livro livroAtualizado); //edita um livro existente
NoBST *excluirNo(NoBST *raiz, tipoT excluir); //exclui um livro da arvore
NoBST *buscarBST(NoBST *raiz, tipoT busca); //busca um livro

#endif