#include <stdio.h>
#include <stdlib.h>
#include "container.h"

int main()
{
    PortoSeco* Porto = CriarPorto();
    int opcao;
    int codigo;

    do {

        printf("========== Menu ==========\n");
        printf("1. Inserir container\n");
        printf("2. Remover container\n");
        printf("3. Imprimir pilhas\n");
        printf("4. Sair\n");
        printf("==========================\n");
        printf("Digite uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o codigo do container: ");
                scanf("%d", &codigo);
                Inserir(Porto, codigo);
                break;
            case 2:
                printf("Digite o codigo do container: ");
                scanf("%d", &codigo);
                removerContainer(Porto, codigo);
                break;
            case 3:
                Imprimir(Porto);
                break;
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }


    } while (opcao != 4);

    LiberarMemoria(Porto);

    return 0;
}
