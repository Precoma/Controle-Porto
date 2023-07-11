#include "container.h"
#include <stdio.h>
#include <stdlib.h>

PortoSeco* CriarPorto()
{

    Pilha* aux;

    PortoSeco* Porto = (PortoSeco*) malloc(sizeof(PortoSeco));

    Porto->pilhas = (Pilha*) malloc(sizeof(Pilha));
    Porto->pilhas->topo = NULL;
    Porto->pilhas->qtd = 0;
    Porto->pilhas->next = NULL;

    for(int i=0;i<3;i++){
        aux = (Pilha*) malloc(sizeof(Pilha));
        aux->topo = NULL;
        aux->qtd = 0;

        if(Porto->pilhas->next == NULL)
        {
            aux->next = NULL;
            Porto->pilhas->next = aux;
        } else {
            aux->next = Porto->pilhas->next;
            Porto->pilhas->next = aux;
        }
    }


return Porto;
}

void Inserir(PortoSeco* Porto, int codigo) {

    if(EncontrarRepetido(Porto, codigo)){
        printf("Codigo Invalido!\n\n");
        return;
    }

    Pilha* pilhaAtual = Porto->pilhas;
    Pilha* menorPilha = pilhaAtual;

    int menor = menorPilha->qtd;

    while (pilhaAtual != NULL) { // procura menor pilha
        if (pilhaAtual->qtd < menor) {
            menor = pilhaAtual->qtd;
            menorPilha = pilhaAtual;
        }
        pilhaAtual = pilhaAtual->next;
    }


    if(menor >= 3){ //verifica se todas pilhas ja estao cheias
        printf("Impossivel Empilhar!\n\n");
        return;
    }

    Container* novo = (Container*)malloc(sizeof(Container));
    novo->codigo = codigo;

    //insere novo elemento sempre no começo
    if(menorPilha->topo == NULL) {
        novo->next = NULL;
        menorPilha->topo = novo;
    } else {
        novo->next = menorPilha->topo;
        menorPilha->topo = novo;
    }
    menorPilha->qtd++;

    printf("Container Inserido com sucesso!\n\n");
}


int EncontrarRepetido(PortoSeco* Porto, int codigo)
{
    Pilha* pilhaAtual = Porto->pilhas;
    while(pilhaAtual != NULL){


        Container* aux = pilhaAtual->topo;
        while(aux != NULL){
            if (aux->codigo == codigo)
                return 1;
            aux = aux->next;
        }


    pilhaAtual = pilhaAtual->next;

    }
    return 0;
}

void removerContainer(PortoSeco* Porto, int codigo)
{
    if(!EncontrarRepetido(Porto, codigo)){ //verifica se o codigo está nas pilhas
        printf("Codigo Invalido!\n\n");
        return;
    }


    Pilha* pilhaAtual = Porto->pilhas;
    Pilha* pilhaRemover = NULL;

    while (pilhaAtual != NULL) { // procura se o container desejado esta no topo de uma das pilhas
        if (pilhaAtual->topo->codigo == codigo) {
            pilhaRemover = pilhaAtual;
            break;
        }
        pilhaAtual = pilhaAtual->next;
    }



    if(pilhaRemover == NULL){
        printf("Impossivel desempilhar!\n\n");
        return;
    }

    Container* topo_Temp = pilhaRemover->topo; //cria variavel aux para nao perder endereço e dar free
    pilhaRemover->topo = topo_Temp->next;
    free(topo_Temp);
    pilhaRemover->qtd--;

    printf("Container removido com sucesso!\n\n");
}

void Imprimir(PortoSeco* Porto) {
    Pilha* pilhaAtual = Porto->pilhas;
    int pilha = 1;
    while (pilhaAtual != NULL) {
        Container* aux = pilhaAtual->topo;
        printf("Pilha %d: ", pilha);
        while (aux != NULL) {
            printf("%d ", aux->codigo);
            aux = aux->next;
        }
        printf("\n");
        pilhaAtual = pilhaAtual->next;
        pilha++;
    }
    printf("\n");
}



void LiberarMemoria(PortoSeco* Porto) {
    Pilha* pilhaAtual = Porto->pilhas;
    while (pilhaAtual != NULL) {
        Container* containerAtual = pilhaAtual->topo;
        while (containerAtual != NULL) {
            Container* containerTemp = containerAtual;
            containerAtual = containerAtual->next;
            free(containerTemp);
        }
        Pilha* pilhaTemp = pilhaAtual;
        pilhaAtual = pilhaAtual->next;
        free(pilhaTemp);
    }
    free(Porto);
}
