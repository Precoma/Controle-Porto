#ifndef CONTAINER_H_INCLUDED
#define CONTAINER_H_INCLUDED

typedef struct{
    int codigo;
    struct Container* next;
}Container;

typedef struct{
    Container* topo;
    int qtd;
    struct Pilha* next;
}Pilha;

typedef struct{
    Pilha* pilhas;
}PortoSeco;

PortoSeco* CriarPorto();
void Inserir(PortoSeco* Porto, int codigo);
int EncontrarRepetido(PortoSeco* Porto, int codigo);
void removerContainer(PortoSeco* Porto, int codigo);
void Imprimir(PortoSeco* Porto);
void LiberarMemoria(PortoSeco* Porto);


#endif // CONTAINER_H_INCLUDED
