#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void exibirMenu();
void consultarSaldo(float saldo);
float realizarSaque(float saldo);
float realizarDeposito(float saldo);
void mostrarExtrato(float saldo);
void registraroperacao(char operacao[]);
int totalOperacoes = 0;
char historico[3][100];

int main() {
    int opcao;
    float saldo = 420.0; 

    do {
        system("cls"); 
        exibirMenu();
        scanf("%d", &opcao);
        
        
        while (getchar() != '\n');

        
        switch(opcao) {
            case 1:
                consultarSaldo(saldo);
                break;
            case 2:
                saldo = realizarSaque(saldo);
                break;
            case 3:
                saldo = realizarDeposito(saldo);
                break;
            case 4:
                system("cls");
                mostrarExtrato(saldo);
                break;
            case 0:
                printf("\nSaindo... Obrigado por usar nosso ATM!\n");
                break;
            default:
                printf("\nOpcao Invalida! Tente novamente.\n");
                system("pause"); 
                break;
        }
        
    } while(opcao != 0); 

    return 0;
}



void exibirMenu() {
    printf("\n========================\n");
    printf("    CAIXA ELETRONICO    \n");
    printf("========================\n");
    printf("1 - Consultar Saldo\n");
    printf("2 - Realizar Saque\n");
    printf("3 - Realizar Deposito\n");
    printf("4 - Exibir extrato\n");
    printf("0 - Sair\n");
    printf("========================\n");
    printf("Escolha uma opcao: ");
}

void consultarSaldo(float saldo) {
    printf("\n--- SALDO ATUAL ---\n");
    printf("R$ %.2f\n", saldo); 
    printf("-------------------\n");
    system("pause"); 
}

float realizarSaque(float saldo) {
    float valor;
    printf("\nValor do saque: ");
    scanf("%f", &valor);
    
    
    if (valor <= saldo && valor > 0) {
        saldo -= valor;
        printf("Saque realizado com sucesso!\n");
    } else {
        printf("Saldo insuficiente ou valor invalido!\n");
    }
    
    system("pause"); 
    return saldo;
}

float realizarDeposito(float saldo) {
    float valor;
    printf("\nDigite o valor do deposito: ");
    scanf("%f", &valor);
    
    
    if (valor > 0) {
        saldo += valor;
        printf("Deposito realizado com sucesso!\n");
    } else {
        printf("Valor invalido!\n");
    }
    
    system("pause"); 
    return saldo;
}

void registrarOperacao(char operacao[]) {
 
    if(totalOperacoes == 3) {
        strcpy(historico[0], historico[1]);
        strcpy(historico[1], historico[2]);
        strcpy(historico[2], operacao);
    } else {
        strcpy(historico[totalOperacoes], operacao);
        totalOperacoes++;
    }
    system("pause");
}
void mostrarExtrato(float saldo) {
 
    int i;
 
    printf("\n--------- EXTRATO ----------\n");
 
    if(totalOperacoes == 0) {
 
        printf("Nenhuma operacao realizada.\n");
 
    } else {
 
        for(i = 0; i < totalOperacoes; i++) {
 
            printf("%d. %s\n", i + 1, historico[i]);
        }
    }
 
    printf("\nSaldo atual: R$ %.2f\n", saldo);
    printf("-----------------------------\n");
    system("pause");
}
