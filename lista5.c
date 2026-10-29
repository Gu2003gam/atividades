#include <stdio.h>
#include <string.h>
//1. Sistema de Controle de Estoque Simplificado
typedef struct {
    int codigo;
    int qtd;
    float preco;
} Produto;

Produto estoque[5];
void programa1() {
    float soma = 0, maior = 0;

    for(int i = 0; i < 5; i++) {
        printf("\nInforme o código do %d° produto:\n", i + 1);
        scanf("%d", &estoque[i].codigo);

        printf("\nInforme a quantidade do %d° produto:\n", i + 1);
        scanf("%d", &estoque[i].qtd);

        printf("\nInforme o preço do %d° produto:\n", i + 1);
        scanf("%f", &estoque[i].preco);

        soma = soma + ((estoque[i].preco) * (estoque[i].qtd));
    }
    printf("\nProdutos:\n");
    for(int i = 0; i < 5; i++) {
         printf(
            "\n%d - Produto\n"
            "\nCódigo: %d\n"
            "\nQuantidade: %d\n"
            "\nPreço: R$%1.f\n",
            i + 1, estoque[i].codigo, estoque[i].qtd, estoque[i].preco
         );
    }
    int menor = estoque[0].qtd;
    for(int i = 1; i < 5; i++) {
        if(estoque[i].qtd < menor) {
            menor = estoque[i].qtd;
        }
    }
    for(int i = 0; i < 5; i++) {
        if(menor == estoque[i].qtd) {
            printf("\nO código do produto com menor quantidade é: '%d'.\n", estoque[i].codigo); 
        }
    }
    printf("\nTotal: R$%.1f\n", soma);
}

//2. Validador de Senha de Usuário com Tentativas
typedef struct{
    int id;
    int senha_pin;
} Usuario;
int id = 0, senha_pin = 0, tentativas = 3;
Usuario user;
void programa2() {
    user.id = 101;
    user.senha_pin = 4321;
    while(id != user.id && senha_pin != user.senha_pin) {
        printf("\nDigite o ID do usuário\n");
        scanf("%d", &id);
        printf("\nDigite a Senha do usuário\n");
        scanf("%d", &senha_pin);
        if(id != user.id && senha_pin != user.senha_pin && tentativas > 0) {
            tentativas--;
            printf("\nCredenciais incorretas, você tem mais '%d' tentativas.\n", tentativas);
        } else {
            printf("\nAcesso Concedido!\n");
        }
        if(tentativas == 0) {
            printf("\nAcesso Bloqueado!\n");
            break;
        }
    }

}

int main() {
    programa2();
    return 0;
}