#include <stdio.h>
#include <stdlib.h>
#include "catalogo.h"
#include "operacoesArvore.h"

void limpar_terminal() {
    #ifdef _WIN32
        system("cls");
    #elif __linux__
        system("clear");
    #endif
}

int main() {
    int opcao;
    NoBST *catalogoPessoal = NULL;

    do {
        printf("\n--- Menu de Gestao de Livros ---\n");
        printf("1. Inserir Livro\n");
        printf("2. Buscar Livro\n");
        printf("3. Imprimir Catalogo\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
        case 1: {
            limpar_terminal();
            Livro novoLivro = criarLivro();
            NoBST *novo = novoNo(novoLivro, NULL, NULL);
            catalogoPessoal = inserirNo(catalogoPessoal, novo);
            break;
        }

        case 2:
            limpar_terminal();
            buscarLivro(catalogoPessoal);
            break;
        
        case 3:
            limpar_terminal();
            printf("\n--- Catalogo de Livros ---\n");
            imprimirCatalogo(catalogoPessoal);
            break;
        
        case 0:
            printf("Saindo...\n");
            break;

        default:
            printf("Opcao invalida!\n");
        }

    } while (opcao != 0);

    liberarArvore(catalogoPessoal);

return 0;
}