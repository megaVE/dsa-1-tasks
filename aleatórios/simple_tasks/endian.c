#include <stdio.h>

int contadig (int c){
    int r;
    for(r = 0; c > 0; r++)
        c = c / 10;
    return r;
}

int pot(int p, int e){
    for(;e > 1; e--)
        p = p * p;
    return p;
}

int inv(int i, int n){
    int r = 0;
    for(;i > 0; n = n / 10, i--)
        r = r * 10 + n % 10;
    return r;
}

int main(){
    int endian, cendian = 0, i, t;
    printf("Informe o Valor (Decimal) Armazenado: ");
    scanf("%d", &endian);
    for(int j = 0; cendian < endian; j++){
        printf("Informe o Valor do %dº Endereço: ", j+1);
        scanf("%d", &t);
        i = contadig(t);
        cendian = cendian * pot(10, i) + t;
    }
    if(cendian == endian)
        printf("O mapeamento usado é big-endian\n");
    else
        if(cendian == inv(contadig(endian), endian))
            printf("O mapeamento usado é little-endian\n");
        else
            printf("Mapeamento incorreto ou não reconhecido\n");
    return 0;
}