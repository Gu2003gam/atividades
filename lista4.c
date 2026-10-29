#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>

#ifndef PI
#define PI 3.14159265358979323846
#endif

#define MAX_ANIVERSARIANTES 15

typedef struct {
    char nome[50];
    int dia;
    int mes;
} Agenda;

Agenda aniversariantes[MAX_ANIVERSARIANTES];

void removerQuebraLinha(char *str) {
    size_t len = strlen(str);
    if(len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

void limparBuffer() {
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

void converterParaMinusculo(char *str) {
    for(int i = 0; str[i]; i++) {
        str[i] = (char)tolower((unsigned char)str[i]);
    }
}

int desafio1() {
    float diametro, area;
    printf("\nDigite o diâmetro do alvo: ");
    scanf("%f", &diametro);
    area = PI * pow((diametro / 2.0f), 2);
    printf("\nÁrea do alvo: %.1f\n", area);
    printf("O total de papelão necessário será: %.1f\n", area * 5000);
    return 0;
}

int desafio2() {
    float altura, degraus;
    printf("\nDigite a altura em que o prego está do chão (em cm): ");
    scanf("%f", &altura);
    degraus = altura / 30.0f;
    printf("\nSerá necessária uma escada de %.0f degraus para atingir a altura do prego.\n", ceil(degraus));
    return 0;
}

int desafio3() {
    int opcao = 0, pessoas = 0, opcao2 = 0, dia, mes;
    char nome[50], inicial;
    
    while(opcao != 9) {
        printf("\n--- MENU AGENDA ---\n"
               "1. Cadastrar pessoas\n"
               "2. Excluir pessoa pelo nome\n"
               "3. Alterar dia ou mês pelo nome\n"
               "4. Consultar por data (dia e mês)\n"
               "5. Consultar por mês\n"
               "6. Consultar pela inicial do nome\n"
               "7. Mostrar toda a agenda ordenada por nome\n"
               "8. Mostrar toda a agenda ordenada por mês\n"
               "9. Sair\n"
               "Escolha uma opção: ");
        scanf("%d", &opcao);
        limparBuffer();

        switch(opcao) {
            case 1: {
                int qtd_novas;
                printf("\nQuantidade de pessoas a cadastrar: ");
                scanf("%d", &qtd_novas);
                limparBuffer();
                
                for(int i = 0; i < qtd_novas && pessoas < MAX_ANIVERSARIANTES; i++) {
                    printf("\nNome do %d° aniversariante: ", pessoas + 1);
                    fgets(aniversariantes[pessoas].nome, sizeof(aniversariantes[pessoas].nome), stdin);
                    removerQuebraLinha(aniversariantes[pessoas].nome);

                    printf("Dia de nascimento: ");
                    scanf("%d", &aniversariantes[pessoas].dia);
                    printf("Mês de nascimento: ");
                    scanf("%d", &aniversariantes[pessoas].mes);
                    limparBuffer();

                    pessoas++;
                    printf("Aniversariante cadastrado com sucesso!\n");
                }
                break;
            }
            case 2: {
                printf("\nNome do aniversariante a excluir: ");
                fgets(nome, sizeof(nome), stdin);
                removerQuebraLinha(nome);

                int encontrado = 0;
                for(int i = 0; i < pessoas; i++) {
                    char temp_nome[50], busca_nome[50];
                    strcpy(temp_nome, aniversariantes[i].nome);
                    strcpy(busca_nome, nome);
                    converterParaMinusculo(temp_nome);
                    converterParaMinusculo(busca_nome);

                    if(strcmp(temp_nome, busca_nome) == 0) {
                        for(int k = i; k < pessoas - 1; k++) {
                            aniversariantes[k] = aniversariantes[k + 1];
                        }
                        pessoas--;
                        encontrado = 1;
                        printf("\nAniversariante excluído com sucesso!\n");
                        break;
                    }
                }
                if(!encontrado) printf("\nAniversariante não encontrado.\n");
                break;
            }
            case 3: {
                printf("\nNome do aniversariante: ");
                fgets(nome, sizeof(nome), stdin);
                removerQuebraLinha(nome);

                int encontrado = 0;
                for(int i = 0; i < pessoas; i++) {
                    char temp_nome[50], busca_nome[50];
                    strcpy(temp_nome, aniversariantes[i].nome);
                    strcpy(busca_nome, nome);
                    converterParaMinusculo(temp_nome);
                    converterParaMinusculo(busca_nome);

                    if(strcmp(temp_nome, busca_nome) == 0) {
                        encontrado = 1;
                        printf("\n1. Alterar dia\n2. Alterar mês\nEscolha: ");
                        scanf("%d", &opcao2);
                        limparBuffer();

                        if(opcao2 == 1) {
                            printf("Novo dia: ");
                            scanf("%d", &aniversariantes[i].dia);
                            printf("Dia atualizado com sucesso!\n");
                        } else if(opcao2 == 2) {
                            printf("Novo mês: ");
                            scanf("%d", &aniversariantes[i].mes);
                            printf("Mês atualizado com sucesso!\n");
                        }
                        limparBuffer();
                        break;
                    }
                }
                if(!encontrado) printf("\nAniversariante não encontrado.\n");
                break;
            }
            case 4: {
                printf("\nDigite o dia: ");
                scanf("%d", &dia);
                printf("Digite o mês: ");
                scanf("%d", &mes);
                limparBuffer();

                int achou = 0;
                for(int i = 0; i < pessoas; i++) {
                    if(aniversariantes[i].dia == dia && aniversariantes[i].mes == mes) {
                        printf("Aniversariante: %s (%02d/%02d)\n", aniversariantes[i].nome, dia, mes);
                        achou = 1;
                    }
                }
                if(!achou) printf("Nenhum aniversariante encontrado para essa data.\n");
                break;
            }
            case 5: {
                printf("\nDigite o mês: ");
                scanf("%d", &mes);
                limparBuffer();

                int achou = 0;
                for(int i = 0; i < pessoas; i++) {
                    if(aniversariantes[i].mes == mes) {
                        printf("Aniversariante: %s - Dia: %d\n", aniversariantes[i].nome, aniversariantes[i].dia);
                        achou = 1;
                    }
                }
                if(!achou) printf("Nenhum aniversariante encontrado neste mês.\n");
                break;
            }
            case 6: {
                printf("\nInicial do aniversariante: ");
                scanf(" %c", &inicial);
                limparBuffer();

                int achou = 0;
                for(int i = 0; i < pessoas; i++) {
                    if(tolower((unsigned char)aniversariantes[i].nome[0]) == tolower((unsigned char)inicial)) {
                        printf("Encontrado: %s (%02d/%02d)\n", aniversariantes[i].nome, aniversariantes[i].dia, aniversariantes[i].mes);
                        achou = 1;
                    }
                }
                if(!achou) printf("Nenhum aniversariante encontrado com essa inicial.\n");
                break;
            }
            case 7: {
                for(int i = 0; i < pessoas - 1; i++) {
                    for(int j = i + 1; j < pessoas; j++) {
                        if(strcmp(aniversariantes[i].nome, aniversariantes[j].nome) > 0) {
                            Agenda aux = aniversariantes[i];
                            aniversariantes[i] = aniversariantes[j];
                            aniversariantes[j] = aux;
                        }
                    }
                }
                printf("\nAgenda Ordenada por Nome:\n");
                for(int i = 0; i < pessoas; i++) {
                    printf("%s - %02d/%02d\n", aniversariantes[i].nome, aniversariantes[i].dia, aniversariantes[i].mes);
                }
                break;
            }
            case 8: {
                for(int i = 0; i < pessoas - 1; i++) {
                    for(int j = i + 1; j < pessoas; j++) {
                        if(aniversariantes[i].mes > aniversariantes[j].mes) {
                            Agenda aux = aniversariantes[i];
                            aniversariantes[i] = aniversariantes[j];
                            aniversariantes[j] = aux;
                        }
                    }
                }
                printf("\nAgenda Ordenada por Mês:\n");
                for(int i = 0; i < pessoas; i++) {
                    printf("Mês %02d: %s (Dia %02d)\n", aniversariantes[i].mes, aniversariantes[i].nome, aniversariantes[i].dia);
                }
                break;
            }
            case 9:
                printf("\nSaindo da agenda...\n");
                break;
            default:
                printf("\nOpção inválida!\n");
        }
    }
    return 0;
}

int desafio4() {
    int quantidade = 10, opcao = 0, valor = 0, tam = 0;
    int vetor[10];

    while(opcao != 6) {
        printf("\n--- MENU VETOR ---\n"
               "1. Incluir números no vetor\n"
               "2. Consultar todos os números\n"
               "3. Consultar um número\n"
               "4. Excluir um número\n"
               "5. Esvaziar o vetor\n"
               "6. Sair\n"
               "Escolha uma opção: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                printf("\nQuantos valores deseja adicionar (máx %d)? ", quantidade - tam);
                int qtd_add;
                scanf("%d", &qtd_add);
                for(int i = 0; i < qtd_add && tam < quantidade; i++) {
                    printf("Digite o valor %d: ", tam + 1);
                    scanf("%d", &vetor[tam]);
                    tam++;
                }
                break;
            case 2:
                printf("\nConteúdo do vetor: ");
                if(tam == 0) printf("Vetor vazio.");
                for(int i = 0; i < tam; i++) {
                    printf("%d ", vetor[i]);
                }
                printf("\n");
                break;
            case 3:
                printf("\nDigite o valor que deseja consultar: ");
                scanf("%d", &valor);
                {
                    int achou = 0;
                    for(int i = 0; i < tam; i++) {
                        if(vetor[i] == valor) {
                            printf("O valor %d existe na posição %d.\n", valor, i);
                            achou = 1;
                        }
                    }
                    if(!achou) printf("O valor %d NÃO existe no vetor.\n", valor);
                }
                break;
            case 4:
                printf("\nDigite o valor para excluir: ");
                scanf("%d", &valor);
                {
                    int pos = -1;
                    for(int i = 0; i < tam; i++) {
                        if(vetor[i] == valor) {
                            pos = i;
                            break;
                        }
                    }
                    if(pos != -1) {
                        for(int i = pos; i < tam - 1; i++) {
                            vetor[i] = vetor[i + 1];
                        }
                        tam--;
                        printf("Valor excluído com sucesso!\n");
                    } else {
                        printf("Valor não encontrado.\n");
                    }
                }
                break;
            case 5:
                tam = 0;
                printf("\nVetor esvaziado com sucesso!\n");
                break;
            case 6:
                printf("\nSaindo...\n");
                break;
        }
    }
    return 0;
}

#define MAX_CURSOS 100

typedef struct {
    int id;
    char descricao[100];
    int qtd_alunos;
    float valor_da_mensalidade;
} Curso;

Curso registros[MAX_CURSOS];

int desafio5() {
    int qtd = 0, soma_alunos = 0;
    float receita = 0, maior_receita = -1.0f;

    printf("\nInforme quantos cursos deseja cadastrar: ");
    scanf("%d", &qtd);
    limparBuffer();

    for(int i = 0; i < qtd; i++) {
        registros[i].id = i + 1;

        printf("\nInforme a descrição do %dº curso: ", i + 1);
        fgets(registros[i].descricao, sizeof(registros[i].descricao), stdin);
        removerQuebraLinha(registros[i].descricao);

        printf("Informe a quantidade de alunos: ");
        scanf("%d", &registros[i].qtd_alunos);

        printf("Informe o valor da mensalidade: ");
        scanf("%f", &registros[i].valor_da_mensalidade);
        limparBuffer();

        soma_alunos += registros[i].qtd_alunos;

        receita = registros[i].qtd_alunos * registros[i].valor_da_mensalidade;
        if(receita > maior_receita) {
            maior_receita = receita;
        }
    }

    printf("\n--- CURSOS CADASTRADOS ---");
    for(int i = 0; i < qtd; i++) {
        printf("\nID: %d | Descrição: %s | Alunos: %d | Mensalidade: R$%.2f",
               registros[i].id, registros[i].descricao, registros[i].qtd_alunos, registros[i].valor_da_mensalidade);
    }

    printf("\n\n--- CURSO(S) COM MAIOR RECEITA ---");
    for(int i = 0; i < qtd; i++) {
        receita = registros[i].qtd_alunos * registros[i].valor_da_mensalidade;
        if(receita == maior_receita) {
            printf("\n%s (Receita: R$%.2f)", registros[i].descricao, receita);
        }
    }

    if(qtd > 0) {
        printf("\n\nMédia de alunos por curso: %.1f\n", (float)soma_alunos / qtd);
    }
    return 0;
}

int main() {
    desafio5();
    return 0;
}