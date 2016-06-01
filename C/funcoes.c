char* mascarar(char* palavra, int* mascaraPalavra, int tam){
    char* mascara = (char*)malloc(sizeof(char)*(tam+1));
    int i;
    for(i = 0; i < tam; i++){
        if(mascaraPalavra[i] == 0){
            mascara[i] = '*';
        }else{
            mascara[i] = palavra[i];
        }
    }
    mascara[i] = '\0';
    return mascara;
}

int acertouPalavra(int* mascara, int tam){
    for(int i = 0; i < tam; i++){
        if(mascara[i] == 0)return 0;
    }
    return 1;
}
