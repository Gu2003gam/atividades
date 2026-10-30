#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int opcao = 0;
//SISBB

int main() {
    while(opcao != 6) {
        printf(
            "+++++++++++++++++++++++++++++++++++++++\n"
            "SISBB - SISTEMA DE GESTÃO DE BIBLIOTECAS\n"
            "+++++++++++++++++++++++++++++++++++++++\n\n"

            "1 - Gestão de Livros\n"
            "2 - Gestão de Autores\n"
            "3 - Gestão de Usuários\n"
            "4 - Gestão de Empréstimos\n"
            "5 - Relatórios\n"
            "6 - Sair.\n\n"

            "Escolha uma opção:\n"
        );
        scanf("%d", &opcao);
        switch(opcao) {
            case 1:
            printf(
                    "\nGESTÃO DE LIVROS\n"
                    "1 - Adicionar Autor\n"
                    "2 - Exibir Autores\n"
                    "3 - Atualizar Livro\n"
                    "4 - Excluir Livro\n"
                    "5 - Voltar ao Menu Principal.\n"
                );
                scanf("%d", &opcao);
                switch(opcao) {

                }
            break;
            case 2:
            printf(
                    "\nGESTÃO DE LIVROS\n"
                    "1 - Adicionar Livro\n"
                    "2 - Exibir Livros\n"
                    "3 - Atualizar Livro\n"
                    "4 - Excluir Livro\n"
                    "5 - Voltar ao Menu Principal.\n"
                );
                scanf("%d", &opcao);
                switch(opcao) {
                    
                }
            break;
            case 3:
            printf("\n+++++++++++++ CADASTRO DE USUÁRIOS +++++++++++++\n");
            printf("1 - Cadastrar Usuários\n");
            printf("2 - Consultar Usuários\n");
            printf("3 - Listar Usuários\n");
            printf("4 - Excluir Usuários\n");
            printf("5 - Atualizar cadastro de Usuários\n");
            printf("6 - Sair\n");
            printf("Selecione uma opção: ");
                scanf("%d", &opcao);
                switch(opcao) {
                    
                }
            break;
            case 4:
            printf(
                    "\nGESTÃO DE LIVROS\n"
                    "1 - Adicionar Livro\n"
                    "2 - Exibir Livros\n"
                    "3 - Atualizar Livro\n"
                    "4 - Excluir Livro\n"
                    "5 - Voltar ao Menu Principal.\n"
                );
                scanf("%d", &opcao);
                switch(opcao) {
                    
                }
            break;
            case 5:
            printf(
                    "\nGESTÃO DE LIVROS\n"
                    "1 - Adicionar Livro\n"
                    "2 - Exibir Livros\n"
                    "3 - Atualizar Livro\n"
                    "4 - Excluir Livro\n"
                    "5 - Voltar ao Menu Principal.\n"
                );
                scanf("%d", &opcao);
                switch(opcao) {
                    
                }
            break;
            case 6:
            break;
        }
    }
    return 0;
}