//Apresentação 'Gustavo dos Santos'
#include <string.h>
#include <stdio.h>

void limparBuffer() {
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

//Atualização de Status de Pedido:
typedef struct{
    int codigo;
    float valor;
} Pedido;

int programa1() {
    Pedido produto;
    printf("\nDigite o código do produto:\n");
    scanf("%d", &produto.codigo);
    printf("\nDigite o valor do produto:\n");
    scanf("%f", &produto.valor);
    printf(
        "\nProduto\n"
        "\nCódigo: %d\n"
        "\nValor: R$%1.f\n"
        , produto.codigo, produto.valor
    );
    switch(produto.codigo) {
        case 1:
        printf("\nO produto obteve um desconto de 10%% porcento, valor final: R$%1.f\n", produto.valor - (produto.valor * 0.1));
        break;
        case 2:
        printf("\nO produto obteve um desconto de 20%% porcento, valor final: R$%1.f\n", produto.valor - (produto.valor * 0.2));
        break;
        case 3:
        printf("\nO produto obteve um desconto de 30%% porcento, valor final: R$%1.f\n", produto.valor - (produto.valor * 0.3));
        break;
    }
    return 0;
}

//Busca de Valor em Vetor via Função:
int buscarValor(int vetor[], int x, int numero) {
    int encontrado = 0;
    for(int w = 0; w < x; w++) {
        if(vetor[w] == numero) {
            printf("\nO valor %d foi encontrado no índice %d.\n", numero, w);
            return w;
        }
    }
    printf("\nO valor %d não foi encontrado no vetor, retorno: -1.\n", numero);
    return -1;
}

int programa2() {
    int tamanho = 0, valor;
    printf("\nInforme o tamanho do vetor:\n");
    scanf("%d", &tamanho);
    int valores[tamanho];
    for(int i = 0; i < tamanho; i++) {
        printf("\nDigite o %d° valor do vetor:\n", i + 1);
        scanf("%d", &valores[i]);
        limparBuffer();
    }
    printf("\nOs valores digitados foram:\n");
    for(int j = 0; j < tamanho; j++) {
        if(j == 0 ) {
            printf("\n[ %d, ", valores[j]);
        } else if(j == (tamanho - 1)) {
            printf(" %d ]\n", valores[j]);
        } else {
            printf("%d, ", valores[j]);
        }
    }
    printf("\nInforme o valor que deseja buscar:\n");
    scanf("%d", &valor);
    buscarValor(valores, tamanho, valor);

    return 0;
}

int main() {
    //Execute aqui
    programa2();
    return 0;
}