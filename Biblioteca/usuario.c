#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARQUIVO "usuarios.csv"
#define ARQ_TEMP "temp.csv"
#define MAX_NOME 80
#define MAX_CARGO 80

typedef struct {
    int codigo;
    char nome[MAX_NOME];
    int idade;
    char cargo[MAX_CARGO];
} Usuario;

void limpar_tela(void);
void limpar_buffer(void);
void garantir_arquivo(void);
void cadastrar(void);
void consultar(void);
void listar(void);
void excluir(void);
void atualizar(void);

void limpar_tela(void) {
    printf("\033[2J\033[H");
}

void limpar_buffer(void) {
    int b;
    while ((b = getchar()) != '\n' && b != EOF)
        ;
}

void garantir_arquivo(void) {
    FILE *arq = fopen(ARQUIVO, "r");

    if (arq == NULL) {
        arq = fopen(ARQUIVO, "w");
        if (arq != NULL) {
            fprintf(arq, "codigo;nome;idade;cargo\n");
            fclose(arq);
        }
    } else {
        fclose(arq);
    }
}

void cadastrar(void) {
    Usuario a;
    FILE *arq = fopen(ARQUIVO, "a");

    if (arq == NULL) {
        printf("Erro ao abrir o arquivo %s.\n", ARQUIVO);
        return;
    }

    printf("Código: ");
    scanf("%d", &a.codigo);
    limpar_buffer();

    printf("Nome: ");
    fgets(a.nome, MAX_NOME, stdin);
    a.nome[strcspn(a.nome, "\n")] = '\0';

    printf("Idade: ");
    scanf("%d", &a.idade);
    limpar_buffer();

    printf("Cargo: ");
    fgets(a.cargo, MAX_CARGO, stdin);
    a.cargo[strcspn(a.cargo, "\n")] = '\0';

    fprintf(arq, "%d;%s;%d;%s\n", a.codigo, a.nome, a.idade, a.cargo);
    fclose(arq);

    printf("Usuário cadastrado com sucesso!\n");
}

void consultar(void) {
    int mat, achou = 0;
    Usuario a;
    char linha[200];
    FILE *arq = fopen(ARQUIVO, "r");

    if (arq == NULL) {
        printf("Erro ao abrir o arquivo %s.\n", ARQUIVO);
        return;
    }

    printf("Consultar com código: ");
    scanf("%d", &mat);
    limpar_buffer();

    // Descarta o cabeçalho
    fgets(linha, sizeof(linha), arq);

    while (fscanf(arq, "%d;%[^;];%d;%[^\n]\n", &a.codigo, a.nome, &a.idade, a.cargo) == 4) {
        if (a.codigo == mat) {
            printf("\nUsuário encontrado:\n");
            printf("Código: %d\n", a.codigo);
            printf("Nome:   %s\n", a.nome);
            printf("Idade:  %d\n", a.idade);
            printf("Cargo:  %s\n", a.cargo);
            achou = 1;
            break;
        }
    }

    if (!achou)
        printf("Usuário com código %d não encontrado.\n", mat);

    fclose(arq);
}

void listar(void) {
    Usuario a;
    char linha[200];
    int total = 0;
    FILE *arq = fopen(ARQUIVO, "r");

    if (arq == NULL) {
        printf("Erro ao abrir o arquivo %s.\n", ARQUIVO);
        return;
    }

    // Descarta o cabeçalho
    fgets(linha, sizeof(linha), arq);

    printf("\n%-10s %-35s %-10s %-35s\n", "CÓDIGO", "NOME", "IDADE", "CARGO");
    printf("--------------------------------------------------------------------------------\n");

    while (fscanf(arq, "%d;%[^;];%d;%[^\n]\n", &a.codigo, a.nome, &a.idade, a.cargo) == 4) {
        printf("%-10d %-35s %-10d %-35s\n", a.codigo, a.nome, a.idade, a.cargo);
        total++;
    }

    if (total == 0)
        printf("Nenhum usuário cadastrado.\n");

    fclose(arq);
}

void excluir(void) {
    int mat, excluido = 0;
    Usuario a;
    char linha[200];
    FILE *arq = fopen(ARQUIVO, "r");
    FILE *temp = fopen(ARQ_TEMP, "w");

    if (arq == NULL || temp == NULL) {
        printf("Erro ao abrir os arquivos.\n");
        if (arq) fclose(arq);
        if (temp) fclose(temp);
        return;
    }

    printf("Código a excluir: ");
    scanf("%d", &mat);
    limpar_buffer();

    // Copia o cabeçalho para o arquivo temporário
    if (fgets(linha, sizeof(linha), arq) != NULL) {
        fputs(linha, temp);
    }

    while (fscanf(arq, "%d;%[^;];%d;%[^\n]\n", &a.codigo, a.nome, &a.idade, a.cargo) == 4) {
        if (a.codigo != mat) {
            fprintf(temp, "%d;%s;%d;%s\n", a.codigo, a.nome, a.idade, a.cargo);
        } else {
            excluido = 1;
        }
    }

    fclose(arq);
    fclose(temp);

    if (excluido) {
        remove(ARQUIVO);
        rename(ARQ_TEMP, ARQUIVO);
        printf("Usuário excluído com sucesso!\n");
    } else {
        remove(ARQ_TEMP);
        printf("Usuário com código %d não encontrado.\n", mat);
    }
}

void atualizar(void) {
    int mat, atualizado = 0;
    Usuario a;
    char linha[200];
    FILE *arq = fopen(ARQUIVO, "r");
    FILE *temp = fopen(ARQ_TEMP, "w");

    if (arq == NULL || temp == NULL) {
        printf("Erro ao abrir os arquivos.\n");
        if (arq) fclose(arq);
        if (temp) fclose(temp);
        return;
    }

    printf("Código a atualizar: ");
    scanf("%d", &mat);
    limpar_buffer();

    // Copia o cabeçalho para o arquivo temporário
    if (fgets(linha, sizeof(linha), arq) != NULL) {
        fputs(linha, temp);
    }

    while (fscanf(arq, "%d;%[^;];%d;%[^\n]\n", &a.codigo, a.nome, &a.idade, a.cargo) == 4) {
        if (a.codigo == mat) {
            printf("Usuário encontrado: %s\n", a.nome);

            printf("Novo nome: ");
            fgets(a.nome, MAX_NOME, stdin);
            a.nome[strcspn(a.nome, "\n")] = '\0';

            printf("Nova idade: ");
            scanf("%d", &a.idade);
            limpar_buffer();

            printf("Novo cargo: ");
            fgets(a.cargo, MAX_CARGO, stdin);
            a.cargo[strcspn(a.cargo, "\n")] = '\0';

            fprintf(temp, "%d;%s;%d;%s\n", a.codigo, a.nome, a.idade, a.cargo);
            atualizado = 1;
        } else {
            fprintf(temp, "%d;%s;%d;%s\n", a.codigo, a.nome, a.idade, a.cargo);
        }
    }

    fclose(arq);
    fclose(temp);

    if (atualizado) {
        remove(ARQUIVO);
        rename(ARQ_TEMP, ARQUIVO);
        printf("Cadastro atualizado com sucesso!\n");
    } else {
        remove(ARQ_TEMP);
        printf("Usuário com código %d não encontrado.\n", mat);
    }
}

int main(void) {
    int opcao;

    garantir_arquivo();

    while (1) {
        printf("\n+++++++++++++ CADASTRO DE USUÁRIOS +++++++++++++\n");
        printf("1 - Cadastrar Usuários\n");
        printf("2 - Consultar Usuários\n");
        printf("3 - Listar Usuários\n");
        printf("4 - Excluir Usuários\n");
        printf("5 - Atualizar cadastro de Usuários\n");
        printf("6 - Sair\n");
        printf("Selecione uma opção: ");

        if (scanf("%d", &opcao) != 1) {
            limpar_buffer();
            printf("Entrada inválida! Digite um número.\n");
            continue;
        }
        limpar_buffer();

        switch (opcao) {
            case 1: cadastrar(); break;
            case 2: consultar(); break;
            case 3: listar();    break;
            case 4: excluir();   break;
            case 5: atualizar(); break;
            case 6:
                printf("Encerrando o programa...\n");
                return 0;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    }

    return 0;
}