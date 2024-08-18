#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "catalogo.h"

void liberarArvore(NoBST *raiz) {
    if (raiz != NULL) {
        liberarArvore(raiz->esquerda); 
        liberarArvore(raiz->direita);  
        free(raiz);                
    }
}

void imprimirLivro(Livro livro) {
    printf("Chave: %d\n", livro.chave);
    printf("Titulo: %s\n", livro.titulo);
    printf("Autor: %s\n", livro.autor);
    printf("Genero: %s\n", livro.genero);
    printf("Editora: %s\n", livro.editora);
    printf("Ano de Publicacao: %s\n", livro.anoPublicacao);
    printf("Notas Pessoais: %s\n\n", livro.notasPessoais);
}

void imprimirArvore(NoBST *raiz) {
    if (raiz != NULL) {
        imprimirArvore(raiz->esquerda);
        imprimirLivro(raiz->item);
        imprimirArvore(raiz->direita);
    }
}

int main() {
    NoBST *raiz = NULL;

    // Cria e insere livros
    printf("----- Livro 1: -------\n");
    Livro livro1 = criarLivro();
    printf("\n----- Livro 2: -------\n");
    Livro livro2 = criarLivro();
    printf("\n----- Livro 3: -------\n");
    Livro livro3 = criarLivro();

    raiz = inserirNo(raiz, novoNo(livro1, NULL, NULL));
    raiz = inserirNo(raiz, novoNo(livro2, NULL, NULL));
    raiz = inserirNo(raiz, novoNo(livro3, NULL, NULL));

    printf("----- Arvore apos insercao: -------\n");
    imprimirArvore(raiz);

    // Atualiza um livro
    Livro livroAtualizado = livro1;
    strcpy(livroAtualizado.titulo, "Titulo Atualizado");
    strcpy(livroAtualizado.editora, "Editora Atualizada");
    strcpy(livroAtualizado.notasPessoais, "Notas Atualizadas");
    raiz = editarNo(raiz, livroAtualizado);

    printf("----- Arvore apos edicao: -------\n");
    imprimirArvore(raiz);

    // Exclui um livro
    raiz = excluirNo(raiz, livro2.chave);

    printf("----- Arvore apos exclusao: -------\n");
    imprimirArvore(raiz);

    // Busca um livro
    NoBST *resultado = buscarBST(raiz, livro1.chave);
    if (resultado != NULL) {
        printf("Livro encontrado:\n");
        imprimirLivro(resultado->item);
    }
    else printf("Livro com chave %d nao encontrado.\n", livro1.chave);

    liberarArvore(raiz);
    
    return 0;
}
