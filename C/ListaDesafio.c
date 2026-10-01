//LISTA DE DESAFIOS
//LÓGICA DE PROGRAMAÇÃO
//GUSTAVO DOS SANTOS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <time.h>
#include <ctype.h>


int desafio1() {
    //área retângulo
    float base;
    float altura;
    printf("\nDigite a medida da base:\n");
    scanf("%f", &base);
    printf("\nDigite a medida da altura:\n");
    scanf("%f", &altura);
    printf("\nA área do retângulo é igual: %.2f\n", base * altura);
    return 0;
}


int desafio2() {
    //conversor de temperatura
    float celsius;
    printf("\nDigite a temperatura em graus celsius:\n");
    scanf("%f", &celsius);
    printf("\n%.1f graus celsius equivale a %.1f graus fahrenheit.\n", celsius, celsius * 1.8 + 32);
    return 0;
}


int desafio3() {
    //média ponderada de provas
    int nota[3];
    int soma = 0;
    for(int i = 1; i <= 3; i++) {
        printf("\nDigite a %d° nota:\n", i);
        scanf("%d", &nota[i]);
    }
    printf("\nAs notas do aluno são:\n");
    for(int i = 1; i <= 3; i++) {
        printf("\n%d\n", nota[i]);
    }
    for(int i = 1; i <= 3; i++) {
        soma = soma + nota[i];
    }
    printf("\nA média ponderada do aluno é: %1.f\n", (float)soma / 3);
   
    return 0;
}


int desafio4() {
    //calculadora de desconto
    float valor;
    printf("\nDigite o valor do produto:\n");
    scanf("%f", &valor);
    printf("\nAplicando um desconto de 15 porcento sobre o valor de R$%1.f, o valor final do produto será: R$%1.f, uma economia de R$%1.f\n", valor, valor - (valor * 0.15), valor * 0.15);
    return 0;
}


int desafio5() {
    //conversor de moedas
    float reais;
    printf("\nDigite o valor em reais:\n");
    scanf("%f", &reais);
    printf("\nCom base na atual cotação do dólar(1 USD = BRL 5,12), o valor de R$%1.f equivale a U$$%1.f\n", reais, reais / 5.12);
    return 0;
}


int desafio6() {
    //verificação de paridade
    int numero;
    printf("\nDigite um número inteiro:\n");
    scanf("%d", &numero);
    char *status = (numero%2 == 0) ? "é um número par!" : "é um número impar!";
    printf("\n%d %s\n", numero, status);
    return 0;
}


int desafio7() {
    //maior de dois números
    int valor[2];
    int maior = 0;
    for(int i = 1; i < 3; i++) {
        printf("\nDigite o %d° número:\n", i);
        scanf("%d", &valor[i]);
    }
    for(int i = 1; i < 3; i++) {
        if(maior < valor[i]) {
            maior = valor[i];
        }
    }
    printf("\nO maior valor é: %d\n", maior);
    return 0;
}


int desafio8() {
    //reajuste salarial baseado em faixa
    float salario;
    printf("\nDigite o valor do salário:\n");
    scanf("%f", &salario);
    float reajuste = (salario <= 1500) ? salario + (salario * 0.2) : salario + (salario * 0.1);
    printf("\nO salário de R$%1.f foi reajustado para R$%1.f.\n", salario, reajuste);
    return 0;
}


int desafio9() {
    //cálculo de consumo de combustível
    float distancia;
    float litros;
    printf("\nDigite o valor da distância em quilômetros(km):\n");
    scanf("%f", &distancia);
    printf("\nDigite o valor da gasolina consumida em litros(l):\n");
    scanf("%f", &litros);
    printf("\nO seu veículo consome em média um litro a cada %1.fkm.\n", distancia / litros);
    return 0;
}


int desafio10() {
    //classificação de nadadores por idade
    int idade;
    printf("\nDigite a idade do competidor:\n");
    scanf("%d", &idade);
    if(idade > 18) {
        printf("\nSênior\n");
    } else {
        if(idade >= 5 && idade <= 7) {
            printf("\nInfantil A\n");
        } else {
            if(idade >= 8 && idade <= 10) {
                printf("\nInfantil B\n");
            } else {
                if(idade >= 11 && idade <= 13) {
                    printf("\nJuvenil A\n");
                } else {
                    if(idade >= 14 && idade <= 17) {
                        printf("\nJuvenil B\n");
                    } else {
                        printf("Valor inválido!");
                    }
                }
            }
        }
    }
    return 0;
}


int desafio11() {
    //classificador completo de triângulos
    int valor[3];
    int valor1, valor2, valor3;
    int eValido = 0;
    for(int i = 1; i <= 3; i++) {
        printf("\nDigite o %d° valor:\n", i);
        scanf("%d", &valor[i]);
        if(i == 0) {
            valor[i] = valor1;
        } else if(i == 1) {
            valor[i] = valor2;
        } else if(i == 2) {
            valor[i] = valor3;
        }
    }
    printf("\nOs valores digitados foram:\n");
    for(int i = 0; i < 3; i++) {
        printf("\n%d\n", valor[i]);
    }
    if(valor[0] == valor[1] && valor[1] == valor[2]) {
        printf("\nAs medidas informadas correspondem a um triângulo equilátero!\n");
    } else {
        char *tipo = (valor[0] != valor[1] && valor[1] != valor[2]) ? "\nAs medidas informadas correspondem a um triângulo escaleno!\n" : "\nAs medidas informadas correspondem a um triângulo isósceles!\n";
        printf("\n%s\n", tipo);
    }
    return 0;
}


int desafio12() {
    //calculadora multifuncional com menu
    int opcao;
    float valor1, valor2;
    printf(
        "\nDigite uma opção:\n"
        "\n1.Soma\n"
        "\n2.Subtração\n"
        "\n3.Multiplicação\n"
        "\n4.Divisão\n"
    );
    scanf("%d", &opcao);
    switch(opcao) {
        case 1:
        printf("\nDigite o valor1:\n");
        scanf("%f", &valor1);
        printf("\nDigite o valor2:\n");
        scanf("%f", &valor2);
        printf("\nA soma de %1.f e %1.f é igual a %1.f.\n", valor1, valor2, valor1 + valor2);
        break;
        case 2:
        printf("\nDigite o valor1:\n");
        scanf("%f", &valor1);
        printf("\nDigite o valor2:\n");
        scanf("%f", &valor2);
        printf("\nA subtração de %1.f e %1.f é igual a %1.f.\n", valor1, valor2, valor1 - valor2);
        break;
        case 3:
        printf("\nDigite o valor1:\n");
        scanf("%f", &valor1);
        printf("\nDigite o valor2:\n");
        scanf("%f", &valor2);
        printf("\nA multiplicação de %1.f e %1.f é igual a %1.f.\n", valor1, valor2, valor1 * valor2);
        break;
        case 4:
        printf("\nDigite o valor1:\n");
        scanf("%f", &valor1);
        printf("\nDigite o valor2:\n");
        scanf("%f", &valor2);
        if(valor2 == 0) {
            printf("Divisão por zero não permitida!");
        } else {
            printf("\nA divisão de %1.f e %1.f é igual a %1.f.\n", valor1, valor2, valor1 / valor2);
        }
        break;
    }
    return 0;
}


int desafio13() {
    //tabuada personalizada com laço
    int numero;
    printf("\nDigite um número de 1 a 10:\n");
    scanf("%d", &numero);
    for(int i = 1; i <= 10; i++) {
        printf("\n%d X %d = %d\n", numero, i, numero * i);
    }


    return 0;
}


int desafio14() {
    //contagem regressiva e detecção de múltiplos
    int numero = 10;
    while(numero >= 0) {
        char *status = (numero % 3 == 0 && numero != 0) ? "é múltiplo de 3" : "não é múltiplo de 3";
        printf("%d %s\n", numero, status);
        numero = numero - 1;
        fflush(stdout);
        sleep(1);
    }
    printf("\nFIM!\n");


    return 0;
}


int desafio15() {
    //validador e média de notas
    float nota1 = 11.0, nota2 = 11.0;
    while((nota1 > 10.0 || nota1 < 0.0) && (nota2 > 10.0 || nota2 < 0.0)) {
        for(int i = 1; i < 3; i++) {
            printf("\nDigite a %d° nota:\n", i);
            if(i == 1) {
                scanf("%f", &nota1);
            } else {
                scanf("%f", &nota2);
            }
        }
        if((nota1 > 10.0 || nota1 < 0.0) && (nota2 > 10.0 || nota2 < 0.0)) {
            printf("\nNota inválida!, o valor de cada nota precisa estar entre '0.0' e '10.0'\n");
        }
    }
    printf("\nA média aritmética das notas '%1.f' e '%1.f' é '%1.f'.\n", nota1, nota2, (nota1 + nota2) / 2);


    return 0;
}


int desafio16() {
    //análise de 10 valores inteiros
    int numeros[10];
    int maior;
    int menor;
    int soma = 0;
    for(int i = 1; i <=10; i++) {
        printf("\nDigite o %d° número:\n", i);
        scanf("%d", &numeros[i]);
    }
    for(int i = 1; i <=10; i++) {
        printf("\n%d, \n", numeros[i]);
    }
    for(int i = 1; i <= 10; i++) {
        soma = soma + numeros[i];
        if(maior < numeros[i]) {
            maior = numeros[i];
        } else if(menor > numeros[i]) {
            menor = numeros[i];
        }
    }
    printf(
        "\nO maior valor digitado foi '%d'\n"
        "\nO menor valor digitado foi '%d'\n"
        "\nA média aritmética dos 10 valores foi '%d'\n",
        maior, menor, soma/10
    );
    return 0;
}


int desafio17() {
    //soma de ímpares em um intervalo
    int valor1 = 2, valor2 = 1, soma = 0;
    while(valor2 < valor1) {
        for(int i = 1; i < 3; i++) {
        printf("\nDigite o %d° valor:\n", i);
        if(i == 1) {
            scanf("%d", &valor1);
        } else {
            scanf("%d", &valor2);
        }
    }
    if(valor2 < valor1) {
        printf("\nIntervalo de valores inválido!\n");
    }
}
for(int i = valor1; i <= valor2; i++) {
    printf("%d, ", i);
    if(i % 2 != 0) {
        soma = soma + i;
    }
}
printf("\nA soma dos números ímpares do intervalo é: %d\n", soma);
    return 0;
}


int desafio18() {
    //sequência de Fibonacci iterativa
    int numero, t1 = 0, t2 = 1, proximoTermo;
    printf("\nDigite o número de elementos da sequência de Fibonacci:\n");
    scanf("%d", &numero);
    for(int i = 1; i <= numero; i++) {
        printf("%d, ", t1);
        proximoTermo = t1 + t2;
        t1 = t2;
        t2 = proximoTermo;
    }
    return 0;
}


int desafio19() {
    //cálculo de logaritmo com validação
    int numero = -1;
    while(numero < 0 || numero == 0) {
        printf("\nDigite um número positivo:\n");
        scanf("%d", &numero);


        if(numero < 0 || numero == 0) {
            printf("\nNúmero inválido!\n");
        }
    }
    printf("\nO logaritmo decimal de '%d' é igual a %.2f.\n", numero, log10(numero));
    return 0;
}


int desafio20() {
    //algoritmo de truncamento de notas
    float nota;
    printf("\nDigite uma nota fracionária:\n");
    scanf("%f", &nota);
    printf("\n%f é a nota original.\n", nota);
    int inteira = (int)nota;
    printf("\n%d é a nota truncada.\n", inteira);
    return 0;
}


int desafio21() {
    srand(time(NULL));
    int numero = rand() % 101;
    int valor = -1;
    int tentativas = 7;
    while(numero != valor) {
        printf(
            "\nAdivinhe um número entre '0' e '100:'\n"
            "\nVocê ainda tem %d tentativas.\n", tentativas
        );
        scanf("%d", &valor);
        if(valor == numero) {
            printf("\nMeus parabéns!, a resposta era '%d'.\n", numero);
        } else {
            char *qual = (valor > numero) ? "O número é menor do que" : "O número é maior do que";
            printf("\n%s %d\n", qual, valor);
        }
        tentativas--;
        if(tentativas < 1) {
            printf(
                "\nSuas chances acabaram!\n"
                "\nA resposta era '%d'.\n",
                numero
            );
            break;
        }
    }
    return 0;
}


int desafio22() {
    //distribuidor de cédulas automático
    int cem, cinquenta, vinte, dez, cinco, dois, um, saque;
    printf("\nDigite um valor em reais:\n");
    scanf("%d", &saque);
    cem = saque % 1000;
    cinquenta = cem % 100;
    vinte = cinquenta % 50;
    dez = vinte % 20;
    cinco = dez % 10;
    dois = cinco % 5;
    um = dois % 2;
    printf("\nTotal:\n"
        "%d cédulas de R$100,\n"
        "%d cédulas de R$50,\n"
        "%d cédulas de R$20,\n"
        "%d cédulas de R$10,\n"
        "%d cédulas de R$5,\n"
        "%d cédulas de R$2,\n"
        "%d cédulas de R$1.\n",
        cem / 100, cinquenta / 50, vinte / 20, dez / 10, cinco / 5, dois / 2, um / 1
    );
    return 0;
}


int desafio23() {
    //conversor de base decimal para binário
    int valor;
    int binario[8];
    int soma = 0;
    printf("\nDigite um número:\n");
    scanf("%d", &valor);
    int octeto[8] = {128, 64, 32, 16, 8, 4, 2, 1};
    for(int i = 0; i < 8; i ++) {
        if(soma += octeto[i] <= valor) {
            soma += octeto[i];
            binario[i] = 1;
        } else {
            binario[i] = 0;
        }
    }
    for(int i = 0; i < 8; i++) {
        printf("%d", binario[i]);
    }
    return 0;
}


int desafio24() {
    //verificador de números primos
    int numero, eh_primo = 1;
    printf("\nDigite um número:\n");
    scanf("%d", &numero);

    if(numero <= 1) {
        eh_primo = 0;
    } else {
        for(int i = 2; i * i <= numero; i++) {
            if(numero % i == 0) {
                eh_primo = 0;
                break;
            }
        }
    }

    char *status = (eh_primo == 1) ? "é primo!" : "não é primo";
    printf("\n%d %s\n", numero, status);
    return 0;
}

int desafio25() {
    //estatística e desvio padrão populacional
    int valores[10];
    float soma = 0, soma_desvios = 0;
    float media, variancia, desvio_padrao;

    for(int i = 0; i < 10; i++){
        printf("\nDigite o %d valor:\n", i + 1);
        scanf("%d", &valores[i]);
        soma = soma + valores[i];
    }
    printf("\nOs valores digitados foram:\n");
    for(int i = 0; i < 10; i++) {
        printf("%d, ", valores[i]);
    }
    media = soma / 10;
    printf("\nA média dos 10 valores é igual a: %.1f\n", media);
    for(int i = 0; i < 10; i++) {
        float desvio = valores[i] - media;
        soma_desvios = soma_desvios + pow(desvio, 2);
    }
    variancia = soma_desvios / 10;
    desvio_padrao = sqrt(variancia);
    printf(
        "\nA variância equivale a: %.1f\n"
        "\nO desvio padrão equivale a: %.1f\n",
        variancia, desvio_padrao
    );

    return 0;
}

int desafio26() {
    //criptografia com cifra de césar
    char texto[100], c;
    int chave, acao;
    printf("\nDigite a frase:\n");
    getchar();
    fgets(texto, sizeof(texto), stdin);
    printf(
        "\nDigite a ação:\n"
        "\n1.Digite '1' para criptografar.\n"
        "\n2.Digite '2' para descriptografar.\n"
    );
    scanf("%d", &acao);
    printf("\nDigite o valor da chave:\n");
    scanf("%d", &chave);
    if (acao == 2) {
        chave = -chave;
    }
    for(int i = 0; texto[i] != '\0'; i++) {
        c = texto[i];

        if(isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            texto[i] = (c - base + chave % 26 + 26) % 26 + base;
        }
    }
    printf("\nTexto criptografado: %s\n", texto);
    return 0;
}

int desafio27() {
    //cálculo de equações do segundo grau
    int a, b, c;
    float delta, raiz1, raiz2;
    for(int i = 0; i < 3; i ++) {
        printf("\nDigite o %d° valor:\n", i + 1);
        if(i == 0) {
            scanf("%d", &a);
        } else if(i == 1) {
            scanf("%d", &b);
        } else {
            scanf("%d", &c);
        }
    }
    if(a != 0) {
        delta = pow(b, 2) -4*(a*c);
        printf("\nO valor de delta é: %1.f\n", delta);
    } else {
        printf("\nO valor de 'a' precisa ser diferente de zero!.\n");
    }
    if(delta < 0) {
        printf("\nNão existem raízes reais.\n");
    } else if(delta == 0) {
        raiz1 = (-(b)) / (2*a);
        printf("\nA raíz real é: %1.f\n", raiz1);
    } else if(delta > 0) {
        raiz1 = ((-(b)) + sqrt(delta)) / (2*a);
        raiz2 = ((-(b)) - sqrt(delta)) / (2*a);
        printf("\nO valor da primeira raiz é '%1.f' e o da segunda é '%1.f'.\n", raiz1, raiz2);
    }
    return 0;
}

int desafio28() {
    //menor número divisível
    int primos[4] = {2, 3, 5, 7}, potencias[4], imc = 1;
    for(int i = 0; i < 4; i++) {
        if(i == 0) {
            potencias[i] = (int)pow(primos[i], 3);
        } else if(i == 1) {
            potencias[i] = (int)pow(primos[i], 2);
        } else {
            potencias[i] = primos[i];
        }
        imc *= potencias[i];
    }
    printf("\n%d X %d X %d X %d = %d\n", potencias[0], potencias[1], potencias[2], potencias[3], imc);
    return 0;
}

int desafio29() {
    //validador completo de datas com anos bissextos
    int dia, mes, ano;
    int eh_valido = 0;
    printf("\nDigite o valor de dia:\n");
    scanf("%d", &dia);
    printf("\nDigite o valor de mês:\n");
    scanf("%d", &mes);
    printf("\nDigite o valor de ano:\n");
    scanf("%d", &ano);
    if(ano % 4 == 0 || ano % 400 == 0) {
        //ano bissexto
        if(mes >= 1 && mes <= 12) {
            if(mes == 2) {
                if(dia >= 1 && dia <= 29) {
                    eh_valido++;
                }
        } else {
                    int trinta_trinta_um = (mes != 4 && mes != 6 && mes != 9 && mes != 11) ? 1 : 2;
                    if(trinta_trinta_um == 1) {
                        if(dia >= 1 && dia <= 31) {
                            eh_valido++;
                        }
                    } else if(trinta_trinta_um == 2) {
                        if(dia >= 1 && dia <= 30) {
                            eh_valido++;
                    }
                }
            }
    }
} else {
    //ano comum
    if(mes >= 1 && mes <= 12) {
            if(mes == 2) {
                if(dia >= 1 && dia <= 28) {
                    eh_valido++;
                }
        } else {
                    int trinta_trinta_um = (mes != 4 && mes != 6 && mes != 9 && mes != 11) ? 1 : 2;
                    if(trinta_trinta_um == 1) {
                        if(dia >= 1 && dia <= 31) {
                            eh_valido++;
                        }
                    } else if(trinta_trinta_um == 2) {
                        if(dia >= 1 && dia <= 30) {
                            eh_valido++;
                    }
                }
            }
    }
}
if (eh_valido == 1) {
    printf("\nA data %d/%d/%d é válida!\n", dia, mes, ano);
} else {
    printf("\nA data %d/%d/%d NÃO é válida!\n", dia, mes, ano);
}
    return 0;
}


int desafio30() {
    int salario;
    printf("\nDigite o valor do salário:\n");
    scanf("%d", &salario);
    if(salario <= 24000) {
        printf("\nSalário de %d recebe isenção\n", salario);
    } else if(salario > 24000 && salario <= 50000) {
        printf("\nSalário de R$%d recebe uma alíquota de 15 porcento equivalente a %1.f\n", salario, salario * 0.15);
    } else if(salario > 50000) {
        printf("\nSalário de R$%d recebe uma alíquota de 27,5 porcento + R$3.900, equivalente a %1.f\n", salario, 3900 + (float)((salario * 0.27) + (salario * 0.005)));
    }
    return 0;
}


int main() {
    desafio23();


    return 0;
}