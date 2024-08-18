#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "catalogo.h"

Livro criarLivro() {
    static int quantidade = 0; // variavel estatica para gerar chaves unicas
    Livro novoLivro; 

    printf("Digite o titulo do livro:\n");
    fgets(novoLivro.titulo, sizeof(novoLivro.titulo), stdin);
    novoLivro.titulo[strcspn(novoLivro.titulo, "\n")] = 0;

    printf("Digite o autor do livro:\n");
    fgets(novoLivro.autor, sizeof(novoLivro.autor), stdin);
    novoLivro.autor[strcspn(novoLivro.autor, "\n")] = 0;

    printf("Digite o genero do livro:\n");
    fgets(novoLivro.genero, sizeof(novoLivro.genero), stdin);
    novoLivro.genero[strcspn(novoLivro.genero, "\n")] = 0;

    printf("Digite a editora do livro:\n");
    fgets(novoLivro.editora, sizeof(novoLivro.editora), stdin);
    novoLivro.editora[strcspn(novoLivro.editora, "\n")] = 0;

    printf("Digite o ano de publicacao do livro:\n");
    fgets(novoLivro.anoPublicacao, sizeof(novoLivro.anoPublicacao), stdin);
    novoLivro.anoPublicacao[strcspn(novoLivro.anoPublicacao, "\n")] = 0;

    getchar();
    printf("Pode adicionar notas pessoais sobre o livro, se desejar:\n");
    fgets(novoLivro.notasPessoais, sizeof(novoLivro.notasPessoais), stdin);
    novoLivro.notasPessoais[strcspn(novoLivro.notasPessoais, "\n")] = 0;

    novoLivro.chave = quantidade++;
    return novoLivro;
}

NoBST *novoNo(Livro novoLivro, NoBST *esquerda, NoBST *direita) {
    NoBST *no = malloc(sizeof(NoBST));
    no->esquerda = esquerda;
    no->direita = direita;
    no->item = novoLivro;
    return no;
}

NoBST *inserirNo(NoBST *raiz, NoBST *novo) {
    if (raiz == NULL) return novo;
    if (raiz->item.chave > novo->item.chave)
        raiz->esquerda = inserirNo(raiz->esquerda, novo);
    else
        raiz->direita = inserirNo(raiz->direita, novo);
    return raiz;
}

// funcao auxiliar para encontrar o menor no da subarvore
NoBST *encontrarMinimo(NoBST *no) {
    while (no->esquerda != NULL) 
        no = no->esquerda;
    return no;
}

NoBST *excluirNo(NoBST *raiz, tipoT excluir) {
    if(raiz == NULL) return NULL; // se a arvore estiver vazia, nao ha o que excluir 
    if(menor(excluir, chave(raiz->item))) 
        raiz->esquerda = excluirNo(raiz->esquerda, excluir);
    else if(menor(chave(raiz->item), excluir)) 
        raiz->direita = excluirNo(raiz->direita, excluir);
    else {
        // caso o no tenha apenas um ou nenhum filho
        if(raiz->esquerda == NULL) {
            NoBST *temp = raiz->direita;
            free(raiz);
            return temp;
        } 
        
        else if(raiz->direita == NULL) {
            NoBST *temp = raiz->esquerda;
            free(raiz);
            return temp;
        }
        
        // caso o no tenha dois filhos
        NoBST *temp = encontrarMinimo(raiz->direita);
        raiz->item = temp->item;
        raiz->direita = excluirNo(raiz->direita, chave(temp->item));
    }
    return raiz;
}

NoBST *buscarBST(NoBST *raiz, tipoT busca) {
    if(raiz == NULL || igual(busca, chave(raiz->item))) 
        return raiz;   
    
    if(menor(busca, chave(raiz->item))) return buscarBST(raiz->esquerda, busca);
    else return buscarBST(raiz->direita, busca);
}

NoBST *editarNo(NoBST *raiz, Livro livroAtualizado) {
    NoBST *no = buscarBST(raiz, livroAtualizado.chave);
    if(no != NULL) no->item = livroAtualizado;
    return raiz;
}