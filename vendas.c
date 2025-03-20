#include <stdio.h>
#include <stdlib.h>


typedef struct{
    char nomeDoProduto[20];
    float precoDoProduto;
    int estoqueDoProduto;
} Produto;

void inserirSaldoDoCliente(float *saldo){
    float notas[] = {2.0f, 5.0f, 10.0f, 20.0f, 50.0f, 100.0f};
    int qtdDeNotas = sizeof(notas) / sizeof(float); //dividido pelo tamanho de cada float que eh 4

    for (int i = 0; i < qtdDeNotas; i++){
        printf("%d. R$%.2f\n", i + 1, notas[i]);
    }

    *saldo += 10.0f;
}

int main(){

    Produto itens[] = {
        {"Refrigerante", 4.99, 10},
        {"Chocolate Bis", 1.99, 25},
        {"Doritos", 2.78, 10},
        {"Pirulito", 0.99, 55}
    };

    const int QUANTIDADE_DE_PRODUTOS = sizeof(itens) / sizeof(Produto); //isso é pq o C retorna o tamanho dos bytes, que seria 3, entao faco isso dividido pelo tamanho de cada Produto

    Produto * maquina[QUANTIDADE_DE_PRODUTOS];
    for(int i =0; i < QUANTIDADE_DE_PRODUTOS; i++){
        maquina[i] = &itens[i];
    }

    float saldo = 0.0f;

    int opcao = -1;
    while (opcao != 0) {
        inserirSaldoDoCliente(&saldo);

        printf("Saldo atual R$%.2f\n", saldo);
        scanf("%d", &opcao);
    } 

    return 0;
}
