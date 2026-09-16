#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
/*
Escreva um programa em C que receba três notas parciais de um aluno.
O programa  deve calcular a média aritmética simples dessas notas, mostrar a média calculada e  classificar o aluno de acordo com a tabela a seguir:
• Média de 7.0 a 10.0: Aprovado
• Média de 3.0 a 6.9: Exame
• Média de 0.0 a 2.9: Reprovado
Se o aluno ficar em exame, calcule e exiba a nota mínima que ele precisará tirar na  prova final para ser aprovado,
sabendo que a nota do exame necessária é dada pela  fórmula: NotaExame = 12.0 – Media (onde a média exigida final após exame é 6.0).
*/

int exercicioMedia() {
	float nota1, nota2, nota3;
	printf("Digite a primeira nota:\n");
	scanf(" %f", &nota1);
	printf("Digite a segunda nota:\n");
	scanf(" %f", &nota2);
	printf("Digite a terceira nota:\n");
	scanf(" %f", &nota3);

	float media = (nota1 + nota2 + nota3) / 3;
	float notaExame = 12.0 - media;
	if(media >= 0.0 && media <= 2.9) {
		printf("O aluno foi reprovado com uma média final de %.1f\n", media);
	} else if(media >= 3.0 && media <= 6.9) {
		printf("O aluno obteve uma média final de %.1f, portanto, terá que obter uma nota mínima de %.1f\n", media, notaExame);
	} else if(media >= 7.0 && media <= 10.0) {
		printf("O aluno foi aprovado com uma média de %.1f\n", media);
	} else {
		printf("Valores incompatíveis");
	}
	return 0;
}

int exercicioTemperatura() {
	float fahrenheit;
	float celcius;

	printf("Digite um valor de temperatura em Fahrenheit:\n");
	scanf(" %f", &fahrenheit);
	celcius = (fahrenheit - 32) / 1.8;
	printf("%.1f graus Fahrenheit equivale a %.1f graus celcius\n", fahrenheit, celcius);

	return 0;
}

int exercicioAno () {
	int ano;
	printf("Digite um ano:\n");
	scanf(" %d", &ano);
	int bi;
	bi = ano % 4;
	if(bi == 0 || ano % 100 == 0 || ano % 400 == 0) {
		printf("%d é um ano bissexto\n", ano);
	} else {
	    printf("%d não é um ano bissexto\n", ano);
	}
	return 0;
}

int exercicioPrimo() {
    int numero;
    int ehPrimo = 1;

    printf("Digite um numero inteiro: \n");
    scanf("%d", &numero);

    if (numero <= 1) {
        ehPrimo = 0;
    } else {
        for (int i = 2; i <= numero / 2; i++) {
            if (numero % i == 0) {
                ehPrimo = 0;
                break;
            }
        }
    }

    if (ehPrimo == 1) {
        printf("O numero %d é primo!\n", numero);
    } else {
        printf("O numero %d não é primo!\n", numero);
    }

    return 0;
}

int exercicioVogal() {
    char letra;
    printf("Digite uma letra qualquer:\n");
    scanf(" %c", &letra);

	if(islower(letra)) {
		printf("%c é minúscula\n", letra);
		char letraMinuscula = tolower(letra);
	if( letraMinuscula == 'a' || letraMinuscula == 'e' || letraMinuscula == 'i' || letraMinuscula == 'o' || letraMinuscula == 'u') {
		printf("A letra %c é uma vogal!\n", letraMinuscula);
	} else {
		printf("%c não é uma vogal!\n", letraMinuscula);
	}
	} else {
		printf("%c é maiúscula\n", letra);
		char letraMinuscula = tolower(letra);
	if( letraMinuscula == 'a' || letraMinuscula == 'e' || letraMinuscula == 'i' || letraMinuscula == 'o' || letraMinuscula == 'u') {
		printf("A letra %c é uma vogal!\n", letraMinuscula);
	} else {
		printf("%c não é uma vogal!\n", letraMinuscula);
	}
	}
    return 0;
}

int main() {
	exercicioVogal();
	return 0;
}