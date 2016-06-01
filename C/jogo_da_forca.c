#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>
#include "funcoes.c"

int main()
{

    srand(time(NULL));

    //Definição das palavras
    char* palavras[] = {"cachorro", "goiaba", "arroz", "pizza", "cavalo"};
    char* dicas[] = {"animal", "fruta", "comida", "comida", "animal"};
    int qtdPalavras = 5;

    char letra;

    int palavraEscolhida =  rand() % qtdPalavras;

    //Inicializando máscara da palavra
    int mascaraPalavra[strlen(palavras[palavraEscolhida])];
    int tam = strlen(palavras[palavraEscolhida]);

    //Chances do jogador
    int qtdChances = 2*tam;

    for(int i = 0; i<tam; i++){
        mascaraPalavra[i] = 0;
    }

    while(qtdChances > 0 && !acertouPalavra(mascaraPalavra, tam)){

        printf("%d\n", qtdChances);
        printf("PALAVRA: %s\n", mascarar(palavras[palavraEscolhida], mascaraPalavra, tam));
        printf("DICA: %s\n", dicas[palavraEscolhida]);

        printf("CHUTE UMA LETRA!\n");
        scanf("%c", &letra);
        fflush(stdin);

        for(int i = 0; i<tam; i++){
            if(palavras[palavraEscolhida][i] == letra){
                mascaraPalavra[i] = 1;
            }
        }

        qtdChances--;

        //Limpa a tela
        system("clear");
    }

    if(acertouPalavra(mascaraPalavra, tam))
        printf("\nPARABÉNS!!! A PALAVRA ERA %s. VOCÊ ACERTOU!!!\n", palavras[palavraEscolhida]);
    else
        printf("\nVOCÊ ERROU... A PALAVRA ERA %s.\n", palavras[palavraEscolhida]);
}
