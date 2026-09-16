#include <stdio.h>
#include <string.h>
#include <stdbool.h>

float imc(float peso, float altura) {
    float imc = peso / (altura * altura);
    return imc;
}
int main() {
    float peso;
    float altura;
    printf("Digite o seu peso em quilogramas:\n");
    scanf(" %f", &peso);
    printf("Digite a sua altura em metros:\n");
    scanf(" %f", &altura);
    printf("O seu imc é %.1f\n", imc(peso, altura));
    if(imc(peso, altura) < 18.5) {
        printf("Você está abaixo do peso 😐\n");
    } else if(imc(peso, altura) >= 18.5 && imc(peso, altura) <= 24.9) {
        printf("Você está no peso ideal (parabéns)😄\n");
    } else if(imc(peso, altura) >= 25.0 && imc(peso, altura) <= 29.9) {
        printf("Você está levemente acima do peso 😅\n");
    } else if(imc(peso, altura) >= 30.0 && imc(peso, altura) <= 34.9) {
        printf("Você tem Obesidade grau I 😮\n");
    } else if(imc(peso, altura) >= 35.0 && imc(peso, altura) <= 39.9) {
        printf("Você tem Obesidade grau II (severa)😨\n");
    } else if(imc(peso, altura) > 40.00) {
        printf("Você tem Obesidade grau III (mórbida)😱\n");
    } else {
        printf("Procure um médico urgentemente!⚠️\n");
    }
    return 0;
}