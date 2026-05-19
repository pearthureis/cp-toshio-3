#include <stdio.h>
#include <stdlib.h>

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
}