#include <stdio.h>
#include <stdlib.h>

void consultarSaldo(float saldo) {
printf("\n--- SALDO ATUAL ---\n");
printf("R$ %.2f\n", saldo);
printf("-------------------\n");
}

void exibirMenu() {
printf("\n========================\n");
printf(" CAIXA ELETRONICO \n");
printf("========================\n");
printf("1 - Consultar Saldo\n");
printf("2 - Realizar Saque\n");
printf("3 - Realizar Deposito\n");
printf("0 - Sair\n");
printf("========================\n");
printf("Escolha uma opcao: ");
}

int main(){
    int opcao;
    float saldo = 420;
    do {
    system("cls");
    exibirMenu();
    scanf("%d", &opcao);
    } while(opcao >=0 && opcao <= 3);
    if (opcao > 3 || opcao < 0){
        system("cls");
        printf("valor digitado invalido!! \n");
        exibirMenu();
        scanf("%d", &opcao);
    }
    switch(opcao) {
        case 1:
        consultarSaldo(saldo);
        break;
        case 2:
        saldo = realizarSaque(saldo);
        break;
        case 0:
        printf("Saindo...\n");
        break;
        default:
        printf("Opcao Invalida!\n");
        }
}