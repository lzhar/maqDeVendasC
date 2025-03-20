#include <stdio.h>
#include <stdlib.h>

#ifdef WINDOWS 
#define CLEAR 'cls'
#else 
#define CLEAR "clear"
#endif

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

    printf("Escolha uma nota para inserir ou zero para sair da maquina: ");
    int escolha;
    scanf("%d", &escolha);

    if(escolha == 0){
        return;
    }else if(escolha >= 1 && escolha <= qtdDeNotas){
        *saldo += notas[escolha - 1];
    }else{
        printf("Valor invalido!\n");
    }
    
}

void exibirMenuDeProdutos(Produto *maquina[], int tamanho,float saldo){
    system(CLEAR);
    printf("=====maquina de vendas de comida=====\n");
    printf("Saldo atual R$%.2f\n\n", saldo);

    for(int i = 0; i < tamanho; i++){
        printf("%d. %s\t- R$%.2f (em estoque: %d)\n", i + 1,
             maquina[i]->nomeDoProduto, maquina[i]->precoDoProduto, maquina[i]->estoqueDoProduto);
    }
   
    printf("\n0. sair\n");
}

void vender(Produto* produto, float * saldo){
    produto->estoqueDoProduto--;
    *saldo -= produto->precoDoProduto;
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
        system(CLEAR);
        inserirSaldoDoCliente(&saldo);
        exibirMenuDeProdutos(maquina, QUANTIDADE_DE_PRODUTOS, saldo);

        scanf("%d", &opcao);
        if(opcao == 0){
            break;
        }else if(opcao >= 1 && opcao <= QUANTIDADE_DE_PRODUTOS){
            vender(maquina[opcao - 1], &saldo);
        }
        
    } 

    return 0;
}
