#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void convertebinario(int vetor[], int chave){
    printf("Chave %i em binario: ", chave);
    for (int aux = 9; aux >= 0; aux--){
        if (chave % 2 == 0){
            vetor[aux] = 0;
        }else{
            vetor[aux] = 1;
        }
        chave = chave / 2;
    }
    for(int i=0; i<=9; i++){
        printf("%i, ", vetor[i]);
    }
}

int converteInteiro(int vetor[]){
    int soma = 0;
    int potencia = 0;
    for(int i=4; i>=0; i--){
        if(vetor[i] == 1){
            soma += pow(2, potencia);
        }
        potencia++;
    }
    return soma;
}

void and(int vetorEntrada[], int vetorSaida[]){
    for(int i=0; i<=4; i++){
        if((vetorEntrada[i] == 1 && vetorEntrada[i+5] == 1)){
            vetorSaida[i] = 1;
        }else{
            vetorSaida[i] = 0;
        }
    }
}

void or(int vetorEntrada[], int vetorSaida[]){
    for(int i=0; i<=4; i++){
        if((vetorEntrada[i] == 0 && vetorEntrada[i+5] == 0)){
            vetorSaida[i] = 0;
        }else{
            vetorSaida[i] = 1;
        }
    }
}

void xor(int vetorEntrada[], int vetorSaida[]){
    for(int i=0; i<=4; i++){
        if((vetorEntrada[i] == 0 && vetorEntrada[i+5] == 1) || (vetorEntrada[i] == 1 && vetorEntrada[i+5] == 0)){
            vetorSaida[i] = 1;
        }else{
            vetorSaida[i] = 0;
        }
    }
}

int metodoDobra(int chave){
    int vetor[10];
    convertebinario(vetor, chave);
    int vetResult[5];
    xor(vetor, vetResult);
    int retorno;
    retorno = converteInteiro(vetResult);
    return retorno;
}

int metodoDivisao(int chave){
    return chave % 23;
}

int metodoMultiplicacao(int chave, int tamTabela){
    //int retorno = (int) (tamTabela * (( (int) chave*0.61803) % 1));
    int aux = (int) chave * 0.61803981;
    float aux2 = chave * 0.61803981;
    float result = aux2 - aux;
    int retorno = (int) tamTabela * result;
    return retorno;
}

double calcSoma(int qtdDigito, int tamVetor){
    double aux = qtdDigito;
    double aux2 = tamVetor;
    double retorno;
    retorno = (double) aux - (aux2/10);
    if(retorno < 0){
        retorno = retorno * -1;
    }
    return retorno;
}

double contaDigitos(int vetor[], int tamVetor){
    int dig0 = 0;
    int dig1 = 0;
    int dig2 = 0;
    int dig3 = 0;
    int dig4 = 0;
    int dig5 = 0;
    int dig6 = 0;
    int dig7 = 0;
    int dig8 = 0;
    int dig9 = 0;

    for(int i=0; i<tamVetor; i++){
        if(vetor[i] == 0){
            dig0++;
        }else if(vetor[i] == 1){
            dig1++;
        }else if(vetor[i] == 2){
            dig2++;
        }else if(vetor[i] == 3){
            dig3++;
        }else if(vetor[i] == 4){
            dig4++;
        }else if(vetor[i] == 5){
            dig5++;
        }else if(vetor[i] == 6){
            dig6++;
        }else if(vetor[i] == 7){
            dig7++;
        }else if(vetor[i] == 8){
            dig8++;
        }else if(vetor[i] == 9){
            dig9++;
        }
    }

    double somadig0 = calcSoma(dig0, tamVetor);
    double somadig1 = calcSoma(dig1, tamVetor);
    double somadig2 = calcSoma(dig2, tamVetor);
    double somadig3 = calcSoma(dig3, tamVetor);
    double somadig4 = calcSoma(dig4, tamVetor);
    double somadig5 = calcSoma(dig5, tamVetor);
    double somadig6 = calcSoma(dig6, tamVetor);
    double somadig7 = calcSoma(dig7, tamVetor);
    double somadig8 = calcSoma(dig8, tamVetor);
    double somadig9 = calcSoma(dig9, tamVetor);

    double soma = somadig0 + somadig1 + somadig2 + somadig3 + somadig4 + somadig5 + somadig6 + somadig7 + somadig8 + somadig9;

    return soma;
}

double analiseDigitos(int casaDecimal, int vetor[], int tamVetor){
    int aux = casaDecimal;
    int vetorAux[tamVetor];
    double vetorResult[casaDecimal];
    int contador = 0;
    double soma;
    while(aux != 0){
        for(int i=0; i<tamVetor; i++){
            vetorAux[i] = (vetor[i] % 10);
        }
        for(int i=0; i<tamVetor; i++){
            vetor[i] = vetor[i] / 10;
        }
        soma = contaDigitos(vetorAux, tamVetor);
        vetorResult[contador] = soma;
        contador++;
        aux--;
    }
    int b = tamVetor;
    int tamSomatorios = -1;
    while(b > 0){
        b = b/10;
        tamSomatorios++;
    }
    printf("Tanto de somatorios q devemos pegar: %i \n", tamSomatorios);

    double menorResult = vetorResult[0];
    printf("%f \n", vetorResult[0]);
    for(int i=1; i<casaDecimal; i++){
        printf("%f \n", vetorResult[i]);
        if(menorResult > vetorResult[i]){
            menorResult = vetorResult[i];
        }
    }
    int gambiarra = 0;
    for(int i=casaDecimal-1; i>=0; i--){
        if(vetorResult[i] == menorResult){
            break;
        }
        gambiarra++;
    }
    return gambiarra+1;
}

int aux(int numero, int casaDecimal, int digito){
    int aux = numero;
    int aux1 = casaDecimal;
    int aux2 = digito;
    int retorno = 0;

    while(aux > 0){
        if(casaDecimal == digito){
            retorno = aux % 10;
            return retorno;
        }
        aux = aux / 10;
        casaDecimal--;
    }
}

int verificaTamHash(float tamHash){
    float x;
    for(int i=1; i<=20; i++){
        x = pow(10, i);
        if(x == tamHash){
            return 1;
        }
    }
    return -1;
}

int mult(int chave, int tamHash){
    int auxiliar = tamHash;
    int contador = 0;
    while(auxiliar > 0){
        auxiliar = auxiliar/10;
        contador++;
    }
    float verificador = tamHash;
    int isPotencia = verificaTamHash(verificador);
    if(isPotencia == 1){
        contador--;
    }

    //printf("qtd de digitos pra pegar do vetor final: %i \n", contador);

    int auxChave = chave * chave;
    int contador2 = 0;
    while(auxChave > 0){
        auxChave = auxChave/10;
        contador2++;
    }
    //printf("tamanho do vetor: %i \n", contador2);
    int vetorResult[contador2];
    int auxiliar3 = chave*chave;
    int x = 0;
    for(int i=contador2-1; i>=0; i--){
        x = auxiliar3 % 10;
        vetorResult[i] = x;
        auxiliar3 = auxiliar3/10;
    }
    for(int i=0; i<contador2; i++){
        //printf("Posicao %i do vetor: %i \n", i, vetorResult[i]);
    }

    int retorno = chave*chave;
    if(retorno < tamHash){
        return retorno;
    }else{
        int vetor[contador];
        int x = contador;
        int aux = 0;
        int i = contador2/2;
        //printf("Valor original do i: %i \n", i);
        if(contador2 % 2 == 0){
            i--;
        }
        //printf("Valor do i: %i \n", i);
        while(x > 0){
            vetor[aux] = vetorResult[i];
            i++;
            x--;
            aux++;
        }
        printf("\n \n");
        for(int i=0; i<contador; i++){
            printf("%i \n", vetor[i]);
        }
        printf("\n \n");
        if(contador == 1){
            //printf("hahaha: %i \n", vetor[0]);
            return vetor[0];
        }else{
            int result = 0;
            int m = 1;
            for(int i=contador-1; i>=0; i--){
                result = result + (vetor[i] * m);
                //printf("Valor do mult q vai almentando: %i \n", result);
                m = m*10;

            }
            //printf("Add na posicao: %i \n", result);
            return result;
        }

    }


}

void main(){
    //int result = divisao(79);
    //printf("%i", result);
    //int x = metodoDobra(371);
    //printf("\n");
    //printf("Adicionar a chave na posicao %i do vetor", x);
    //int i = metodoMultiplicacao(371, 100);
    //printf("\n");
    //printf("Adicionar a chave na posicao %i do vetor", i);
    //printf("\n");
    //printf("Adicionar a chave na posicao %f do vetor", i);

    /*int v[6];
    v[0] = 44;
    v[1] = 46;
    v[2] = 49;
    v[3] = 68;
    v[4] = 71;
    v[5] = 87;



    int result = analiseDigitos(2, v, 6);
    printf("Add na hash no digito: %i \n", result);
    int pos;
    pos = aux(4932, 4, 4);
    printf("retornei o: %i", pos);
    */
    int x = mult(652, 10);
    printf("add na posicao: %i", x);
}
