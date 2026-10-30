#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int total_livros;
    int total_usuarios;
    int livros_emprestados;
    int livros_disponiveis;
    int total_emprestimos_realizados;
    int livros_em_atraso;
    float total_multas_pendentes;
} Relatorio;

void exibirRelatorio() {
    FILE *arquivo = fopen("relatorio.txt", "r");

    if(arquivo == NULL) {
        printf("Houve um erro durante a abertura do arquivo!\n");
        return;
    }

    char cabecalho[1024];
    if (fgets(cabecalho, sizeof(cabecalho), arquivo) == NULL) {
        printf("\nArquivo vazio ou erro ao ler cabeçalho!\n");
        fclose(arquivo);
        return;
    }

    Relatorio r;
    printf("\nDADOS DOS RELATÓRIOS:\n");

    while(fscanf(arquivo, "%d, %d, %d, %d, %d, %d, %f",
        &r.total_livros,
        &r.total_usuarios,
        &r.livros_emprestados,
        &r.livros_disponiveis,
        &r.total_emprestimos_realizados,
        &r.livros_em_atraso,
        &r.total_multas_pendentes
    ) == 7) {
        printf(
            "Total de Livros: %d\n"
            "Total de Usuários: %d\n"
            "Livros emprestados: %d\n"
            "Livros disponíveis: %d\n"
            "Total de empréstimos realizados: %d\n"
            "Livros em atraso: %d\n"
            "Total de multas pendentes: %.1f\n\n", 
            r.total_livros, r.total_usuarios, r.livros_emprestados, 
            r.livros_disponiveis, r.total_emprestimos_realizados, 
            r.livros_em_atraso, r.total_multas_pendentes
        );
    }

    fclose(arquivo);
}

void atualizarRelatorio() {
    Relatorio a;
    FILE *arquivo = fopen("relatorio.txt", "a");

    if(arquivo == NULL) {
        printf("\nHouve um erro durante a abertura do arquivo!\n");
        return;
    }

    printf("\nInforme o total de livros:\n");
    scanf("%d", &a.total_livros);

    printf("Informe o total de usuários:\n");
    scanf("%d", &a.total_usuarios);

    printf("Informe o total de livros emprestados:\n");
    scanf("%d", &a.livros_emprestados);
    
    printf("Informe o total de livros disponíveis:\n");
    scanf("%d", &a.livros_disponiveis);

    printf("Informe o total de empréstimos realizados:\n");
    scanf("%d", &a.total_emprestimos_realizados);

    printf("Informe o total de livros em atraso:\n");
    scanf("%d", &a.livros_em_atraso);

    printf("Informe o total de multas pendentes:\n");
    scanf("%f", &a.total_multas_pendentes);

    fprintf(arquivo, "%d, %d, %d, %d, %d, %d, %.2f\n",
        a.total_livros,
        a.total_usuarios,
        a.livros_emprestados,
        a.livros_disponiveis,
        a.total_emprestimos_realizados,
        a.livros_em_atraso,
        a.total_multas_pendentes
    );

    fclose(arquivo);
    printf("\nOs dados do relatório foram atualizados com sucesso!\n");
}

void excluirRelatorio() {
    FILE *arquivo = fopen("relatorio.txt", "w");

    if(arquivo == NULL) {
        printf("\nHouve um erro ao tentar limpar o arquivo!\n");
        return;
    }

    fprintf(arquivo, "total_livros, total_usuarios, livros_emprestados, livros_disponiveis, total_emprestimos_realizados, livros_em_atraso, total_multas_pendentes\n");

    fclose(arquivo);
    printf("\nTodos os registros do relatório foram excluídos com sucesso!\n");
}

int main() {
    excluirRelatorio();
    return 0;
}