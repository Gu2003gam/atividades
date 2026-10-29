//Exercícios de Lógica de Programação
//Gustavo dos Santos
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>
#include <math.h>
#include <stdlib.h>



void inverter(char * str) {
   int inicio = 0;
   int fim = strlen(str) - 1;
   char temp;




   while (inicio < fim){
       temp = str[inicio];
       str[inicio] = str[fim];
       str[fim] = temp;
       inicio++;
       fim--;
   }
}

int questao1() {
   int inteira;
   float flutuante;
   char caractere;
   printf("Digite um valor inteiro, um flutuante e um caractere:\n");
   for(int i = 1; i <= 3; i++) {
       switch (i) {
           case 1:
           scanf(" %d", &inteira);
           break;
           case 2:
           scanf(" %f", &flutuante);
           break;
           case 3:
           scanf(" %c", &caractere);
       }
   }
   printf(
       "A variável inteira %d\n"
       "A variável flutuante %.1f\n"
       "A variável caractere %c\n"
       , inteira, flutuante, caractere
       );
   return 0;
}

int questao2() {
    float cateto1;
    float cateto2;
    float hipotenusa;
    printf("Digite o valor do cateto 1:\n");
    scanf("%f", &cateto1);
    printf("Digite o valor do cateto 2:\n");
    scanf("%f", &cateto2);
    hipotenusa = sqrt(pow(cateto1, 2) + pow(cateto2, 2));

    printf("O valor da hipotenusa é %.2f\n", hipotenusa);

    return 0;
}

int questao3() {
    int tempo;
    printf("Digite um valor em segundos:\n");
    scanf(" %d", &tempo);
    int hora;
    hora = tempo / 3600;
    int minutos;
    minutos = (tempo % 3600) / 60;
    int segundos = (tempo % 3600) % 60;

    printf("O valor de %d segundos equivale a %d hora %d minutos e %d segundos\n", tempo, hora, minutos, segundos);
    return 0;
}

int questao4() {
    int a;
    int b;
    printf("Digite o primeiro número:\n");
    scanf("%d", &a);
    printf("Digite o segundo número:\n");
    scanf("%d", &b);
    printf(
        "A soma dos dois números é: %d\n"
        "O produto dos dois números é: %d\n"
        "O quociente dos dois números é: %.1f\n"
        "O resto da divisão dos dois números é: %d\n"
        , a + b, a * b, (float)a / b, a % b
    );

    return 0;
}

int questao5() {
    char caractere;
    printf("Digite um caractere:\n");
    scanf("%c", &caractere);
    printf(
        "O caractere digitado foi '%c'\n"
        "O código correspondente ao caractere '%c' é '%d'\n"
        , caractere, caractere, caractere
    );

    return 0;
}

int questao6() {
    int idade;
    printf("Digite a sua idade:\n");
    scanf("%d", &idade);
    if(idade<18) {
        printf("Você é menor de idade!\n");
    } else {
        char *status = (idade>=18 && idade<60) ? "Você é um adulto\n" : "Você é um idoso\n";
        printf("%s", status);
    }
    return 0;
}

int questao7() {
    int numero1;
    int numero2;
    int opcao;
    while (true){
        printf(
            "CALCULADORA\n\n"
            "Digite o número correspondente a opção desejada:\n"
            "1.Digite '1' para Soma\n"
            "2.Digite '2' para Subtração\n"
            "3.Digite '3' para Multiplicação\n"
            "4.Digite '4' para Divisão\n"
            "5.Digite '5' para Sair\n"
        );
        scanf("%d", &opcao);
        if(opcao == 5) {
            printf("Saindo do programa...\n");
            break;
        }
        printf("Digite o primeiro número:\n");
        scanf("%d", &numero1);
        printf("Digite o segundo número:\n");
        scanf("%d", &numero2);
        switch (opcao){
            case 1:
            printf("A soma de %d e %d é igual a: %d\n", numero1, numero2, numero1 + numero2);
            break;
            case 2:
            printf("A subtração de %d e %d é igual a: %d\n", numero1, numero2, numero1 - numero2);
            break;
            case 3:
            printf("A multiplicação de %d e %d é igual a: %d\n", numero1, numero2, numero1 * numero2);
            break;
            case 4:
            if(numero1 == 0 || numero2 == 0) {
                printf("Divisão por zero não permitida!\n\n");
            } else {
                printf("A divisão de %d e %d é igual a: %.1f\n", numero1, numero2, (float)numero1 / numero2);
            }
            break;
            default:
            printf("Opção Inválida");
            break;
        }
    }
    return 0;
}

int questao8() {
    const int VALOR = 6;
    int tentativa = 10;
    int numero;
    while (tentativa > 0) {
        printf("Você tem %d tentativas!\n", tentativa);
        printf("Digite um número de '1' a '10'\n");
        scanf("%d", &numero);
        if(numero>=1&&numero<=10) {
            if(numero == VALOR) {
                printf("Parabéns!, a resposta é '6'!\n\n");
                break;
            } else {
                if(numero < VALOR) {
                    printf("O número é maior que %d!\n", numero);
                } else {
                    printf("O número é menor que %d!\n", numero);
                }
                tentativa--;
            }
        } else {
            printf("Número inválido!\n\n");
        }
        if(tentativa < 1) {
            printf("Suas tentativas acabaram!");
            break;
        }
    }
    

    return 0;
}
void repetir(char c, int vezes, char *resultado) {
    int i;
    for(i = 0; i < vezes; i++) {
        resultado[i] = c;
    }
    resultado[vezes] = '\0';

}

int questao9() {
    int numero;
    int soma = 0;
    printf("Digite um número:\n");
    scanf("%d", &numero);
    for(int i = 0; i <= numero; i++) {
        soma = soma + 1;
        for(int j = 0; j < soma; j++) {
            printf("*");
        }
        printf("\n");
    }
    printf("\n");
    for(int w = 1; w <= 10; w++) {
        printf("%d X %d = %d\n", numero, w, numero * w);
    }
    return 0;
}

int questao10() {
    int numero;
    int lista[10];
    int soma = 0;
    int maior;
    int indice = 9;
    printf("Digite 10 valores:\n");
    for(int i = 0; i < 10; i++) {
        scanf("%d", &numero);
        lista[i] = numero;
    }
    system("cls");
    system("clear");
    printf("Os valores da lista são:\n\n");
    for(int j = 0; j < 10; j++) {
        printf("%d ,", lista[j]);
    }
    printf("\n");
    for(int k = 0; k < 10; k++) {
        soma = soma + lista[k];
    }
    printf("\nA soma de todos os valores da lista é: %d\n", soma);
    maior = lista[0];
    for(int m = 0; m < 10; m++) {
        if(lista[m] > maior) {
            maior = lista[m];
        }
    }
    printf("\n");
    printf("O maior valor da lista é: %d\n", maior);
    printf("\nLista invertida:\n\n");
    for(int n = 0; n < 10; n++) {
        printf("%d ,", lista[indice]);
        if(indice >= 0) {
            indice = indice - 1;
        }
    }
    fflush(stdin);
    return 0;
}


int questao11() {
   char frase[100];
   char fraseSemEspaco[100];
   char vogais[6] = {'a', 'e', 'i', 'o', 'u', '\0'};




   printf("Digite uma frase:\n");
   fgets(frase, sizeof(frase), stdin);
   printf("A frase digitada foi: %s\n", frase);
   int tamanho;
   tamanho = strlen(frase);
   int j = 0;
   int numeroVogais = 0;
   int numeroConsoantes = 0;
   fraseSemEspaco[j] = '\0';
   for(int i = 0; i < tamanho; i++) {
       if(frase[i] != ' ' && frase[i] != '\n' && frase[i] != '\0' ) {
           fraseSemEspaco[j] = frase[i];
           j++;
       }
   }
   int tamanhoReal = strlen(fraseSemEspaco);




   for(int v = 0; v < tamanhoReal; v++) {
       char c = fraseSemEspaco[v];
       if(isalpha(c)) {
           if(strchr(vogais, c) != NULL) {
               numeroVogais++;
           } else {
               numeroConsoantes++;
           }
       }
   }




   inverter(fraseSemEspaco);
   printf(
       "A frase contém %d caracteres\n"
       "A frase contém %d vogais\n"
       "A frase contém %d consoantes\n"
       "A frase invertida é %s\n",
       tamanhoReal, numeroVogais, numeroConsoantes, fraseSemEspaco
   );




   return 0;
}

int questao12() {
    int matriz[3][3];
    int contador = 1;
    int soma = 0;
    int linhas = 0, colunas = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf("\nDigite o %d° número:\n", contador);
            scanf("%d", &matriz[i][j]);
            contador++;
        }
    }
    system("clear");
    printf("\nAqui está a matriz:\n");
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            printf("%d|", matriz[i][j]);
        }
        printf("\n");
    }
    for(int i = 0; i < 3; i++) {
        if(linhas < 3 && colunas < 3) {
            soma = soma + matriz[linhas][colunas];
            linhas++;
            colunas++;
        }
    }
    printf("\nA soma da diagonal principal '%d, %d, %d' é: %d\n", matriz[0][0], matriz[1][1], matriz[2][2], soma);
    char *status = (matriz[0][2]==matriz[2][0]) ? "\nA matriz é simétrica!\n" : "\nA matriz não é simétrica!\n";
    printf("%s", status);
    return 0;
}

int somatorio() {
    int soma = 0;
    int num;
    printf("Digite um número:\n");
    scanf("%d", &num);
    for(int i = 0; i <= num; i++) {
        soma = soma + i;
    }
    printf("%d", soma);
}




int main() {
   setlocale(LC_ALL, "Portuguese");
   questao12();


   return 0;
}