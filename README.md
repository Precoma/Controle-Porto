# Controle-Porto

Uma pequena empresa de logística pretende implementar um porto seco para armazenar containers e precisa para um programa simples para gerenciar seu porto.

Dado o tamanho da empresa, essa possui apenas 4 locais onde pode empilhar os containers e seu equipamento permite empilhar no máximo 3 containers.

Por política da empresa, um novo container deve ser colocado no local com a pilha mais baixa disponível (se mais de um local tiver a mesma quantidade de containers, tanto faz em que pilha será adicionado).

Cada container é adicionado a partir de um código informado e o sistema não pode permitir códigos repetidos. Para  remoção também é preciso informar o código do container, mas o mesmo somente será removido se estiver no topo da pilha.

### O algoritmo deve mostrar as seguintes mensagens:


### **Codigo invalido!:**
quando for fornecido um valor já existe no momento de inserção e quando for fornecido um valor não existente no momento de remoção.

### **Impossivel empilhar!:** 
quando não for mais possível adicionar containers nas pilhas.

### **Impossivel desempilhar!:** 
quando não for possível remover um container, ou por não existir mais containers ou por ele não estar no topo da pilha.
