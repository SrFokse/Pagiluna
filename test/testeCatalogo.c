#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "catalogo.h"

void liberarArvore(NoBST *raiz) {
    if (raiz != NULL) {
        liberarArvore(raiz->esquerda); 
        liberarArvore(raiz->direita);  
        free(raiz);                
    }
}

// Função para criar um livro de teste
Livro criarLivroTeste(int chave, char *titulo) {
    Livro livro;
    livro.chave = chave;
    snprintf(livro.titulo, sizeof(livro.titulo), "%s", titulo);
    snprintf(livro.autor, sizeof(livro.autor), "Autor Teste");
    snprintf(livro.genero, sizeof(livro.genero), "Gênero Teste");
    snprintf(livro.editora, sizeof(livro.editora), "Editora Teste");
    snprintf(livro.anoPublicacao, sizeof(livro.anoPublicacao), "2024");
    snprintf(livro.notasPessoais, sizeof(livro.notasPessoais), "Notas Teste");
    return livro;
}

// Teste de inserção e busca
void testeInsercaoBusca() {
    NoBST *raiz = NULL;
    
    // Inserir livros
    Livro livro1 = criarLivroTeste(1, "Livro 1");
    Livro livro2 = criarLivroTeste(2, "Livro 2");
    Livro livro3 = criarLivroTeste(3, "Livro 3");
    
    NoBST *no1 = novoNo(livro1, NULL, NULL);
    NoBST *no2 = novoNo(livro2, NULL, NULL);
    NoBST *no3 = novoNo(livro3, NULL, NULL);
    
    raiz = inserirNo(raiz, no1);
    raiz = inserirNo(raiz, no2);
    raiz = inserirNo(raiz, no3);
    
    // Buscar livros
    NoBST *resultado = buscarBST(raiz, 1);
    assert(resultado != NULL);
    assert(strcmp(resultado->item.titulo, "Livro 1") == 0);
    
    resultado = buscarBST(raiz, 2);
    assert(resultado != NULL);
    assert(strcmp(resultado->item.titulo, "Livro 2") == 0);

    resultado = buscarBST(raiz, 3);
    assert(resultado != NULL);
    assert(strcmp(resultado->item.titulo, "Livro 3") == 0);
    
    liberarArvore(raiz);
}

// Teste de exclusão
void testeExclusao() {
    NoBST *raiz = NULL;
    
    Livro livro1 = criarLivroTeste(1, "Livro 1");
    Livro livro2 = criarLivroTeste(2, "Livro 2");
    Livro livro3 = criarLivroTeste(3, "Livro 3");
    
    NoBST *no1 = novoNo(livro1, NULL, NULL);
    NoBST *no2 = novoNo(livro2, NULL, NULL);
    NoBST *no3 = novoNo(livro3, NULL, NULL);
    
    raiz = inserirNo(raiz, no1);
    raiz = inserirNo(raiz, no2);
    raiz = inserirNo(raiz, no3);
    
    raiz = excluirNo(raiz, 2);
    
    NoBST *resultado = buscarBST(raiz, 2);
    assert(resultado == NULL); 
    
    resultado = buscarBST(raiz, 1);
    assert(resultado != NULL); 
    assert(strcmp(resultado->item.titulo, "Livro 1") == 0);
    
    resultado = buscarBST(raiz, 3);
    assert(resultado != NULL); 
    assert(strcmp(resultado->item.titulo, "Livro 3") == 0);
    
    liberarArvore(raiz);
}

// Teste de edição
void testeEdicao() {
    NoBST *raiz = NULL;
    
    // Inserir livros
    Livro livro1 = criarLivroTeste(1, "Livro 1");
    Livro livro2 = criarLivroTeste(2, "Livro 2");
    Livro livro3 = criarLivroTeste(3, "Livro 3");
    
    NoBST *no1 = novoNo(livro1, NULL, NULL);
    NoBST *no2 = novoNo(livro2, NULL, NULL);
    NoBST *no3 = novoNo(livro3, NULL, NULL);
    
    raiz = inserirNo(raiz, no1);
    raiz = inserirNo(raiz, no2);
    raiz = inserirNo(raiz, no3);
    
    // Atualiza um livro
    Livro livroAtualizado = livro1;
    strcpy(livroAtualizado.titulo, "Titulo Atualizado");
    strcpy(livroAtualizado.editora, "Editora Atualizada");
    strcpy(livroAtualizado.notasPessoais, "Notas Atualizadas");
    raiz = editarNo(raiz, livroAtualizado);
    
    // Verificar atualização
    NoBST *resultado = buscarBST(raiz, livro1.chave);
    assert(resultado != NULL);
    assert(strcmp(resultado->item.titulo, "Titulo Atualizado") == 0);
    assert(strcmp(resultado->item.editora, "Editora Atualizada") == 0);
    assert(strcmp(resultado->item.notasPessoais, "Notas Atualizadas") == 0);
    
    liberarArvore(raiz);
}

// Função principal para rodar todos os testes
int main() {
    testeInsercaoBusca();
    testeExclusao();
    testeEdicao();
    
    printf("-- todos os testes passaram --\n"); 
    
    return 0;
}


