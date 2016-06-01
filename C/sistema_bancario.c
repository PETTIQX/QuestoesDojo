#include <stdio.h>

int main(){
    int operacao,indice;
    char nomes[100][100];
    float saldo[100];
    int qnt=0;
    int indiceDestino;
    float deposito;
    float saque,trans;



    do{
    printf("digite:\n");
    printf("1 para deposito \n");
    printf("2 para saque \n");
    printf("3 para transferencia \n");
    printf("4 para abrir nova conta \n");
    printf("5 para consultar conta\n");
    printf("6 para sair \n");

    scanf("%d",&operacao);

    switch (operacao) {
    case 1:
        printf("Número da conta: \n");
        scanf("%d",&indice);
        if(indice<qnt&&indice>=0){
           printf("Valor do depósito: \n");
           scanf("%f", &deposito);
           if(deposito>=0){
               saldo[indice]+=deposito;
               printf("deposito realizado com sucesso!\n");
           }
           else{
               printf("erro ao efetuar deposito.\n");
           }
        }
        break;

    case 2:
        printf("Número da conta: \n");
        scanf("%d",&indice);
        if(indice<qnt&&indice>=0){
           printf("Valor a ser sacado: \n");
           scanf("%f", &saque);
           if(saque >0){
               if(saque<=saldo[indice]){
                   saldo[indice]-=saque;
                   printf("Saque realizado com sucesso!");
               }
               else{
                   printf("Saldo insuficiente!\n");
               }
           }
           else{
               printf("Valor invalido!\n");
           }
        }
            break;
        case 3:
        printf("Número da conta origem: \n");
        scanf("%d",&indice);

        printf("Número da conta destino: \n");
        scanf("%d",&indiceDestino);

         if(indice<qnt&&indice>=0 && indiceDestino<qnt&&indiceDestino>=0){
           printf("Valor a ser transferido: \n");
           scanf("%f", &trans);
           if(trans >0){
               if(trans<=saldo[indice]){
                   saldo[indice]-=trans;
                   saldo[indiceDestino]= saldo[indiceDestino]+trans;
               }
               else{
                   printf("Saldo insuficiente!\n");
               }
           }
           else{
               printf("Valor invalido!\n");
           }
          }
        break;
    case 4:
        if(qnt<100){
        printf("Digite o nome do cliente\n");
        scanf("%s", nomes[qnt]);
        saldo[qnt] = 0;
        printf("O numero da sua conta é %d\n", qnt);
        qnt++;

        }
        else{
            printf("Banco de dados lotado\n");
        }
        break;
    case 5:
        printf("Digite o numero da conta\n");
        scanf("%d", &indice);
        printf("Nome: %s\n", nomes[indice]);
        printf("Saldo: %f\n",saldo[indice]);
        break;
    default:
        printf("Operação Inválida\n");

        break;
    }


    } while (operacao!=6);



    return 0;
}

