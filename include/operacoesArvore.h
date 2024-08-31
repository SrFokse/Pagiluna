#ifndef OPERACOES_ARVORE_H
#define OPERACOES_ARVORE_H

#include "catalogo.h"

// Funções de manipulação internas da árvore
NoBST *novoNo(Livro novoLivro, NoBST *esquerda, NoBST *direita);
NoBST *inserirNo(NoBST *raiz, NoBST *novo);
NoBST *excluirNo(NoBST *raiz, tipoT excluir);
NoBST *editarNo(NoBST *raiz, Livro livroAtualizado);
NoBST *encontrarMinimo(NoBST *no);
NoBST *buscarBST(NoBST *raiz, tipoT busca);

#endif
