#include<stdio.h>

struct No {
    int valor;
    No *prox;
};

struct Lista {
    No *cabeca, *cauda;
    int n;

    Lista() {
        cabeca = cauda = NULL;
        n = 0;
    }

    bool vazia() { // O(1)
        return (cabeca == NULL);
    }

    void inserirInicio(int v) { // O(1)
        No *novo = new No();
        novo->valor = v;
        if (vazia()) {
            novo->prox = NULL;
            cabeca = novo;
            cauda = novo;
        } else {
            novo->prox = cabeca;
            cabeca = novo;
        }
        n++;
    }

    void inserirFinal(int v) { // O(1)
        No *novo = new No();
        novo->valor = v;
        if (vazia()) {
            novo->prox = NULL;
            cabeca = novo;
            cauda = novo;
        } else {
            novo->prox = NULL;
            cauda->prox = novo;
            cauda = novo;
        }
        n++;
    }

    void imprimir() { // O(n)
        No *aux = cabeca;
        while (aux != NULL) {
            printf("%d\n", aux->valor);
            aux = aux->prox;
        }
    }

    int tamanho() { // O(1)
        return n;
    }

    void removerInicio() { // O(1)
        if (!vazia()) {
            if (tamanho() == 1) {
                No *aux = cabeca;
                cabeca = NULL;
                cauda = NULL;
                delete(aux);
            } else {
                No *aux = cabeca;
                cabeca = cabeca->prox;
                delete(aux);
            }
            n--;
        }
    }

    void removerFinal() { // O(n)
        if (!vazia()) {
            if (tamanho() == 1) {
                No *aux = cabeca;
                cabeca = NULL;
                cauda = NULL;
                delete(aux);
            } else {
                No *penultimo = cabeca;
                while (penultimo->prox != cauda) {
                    penultimo = penultimo->prox;
                }
                delete(cauda);
                cauda = penultimo;
                cauda->prox = NULL;
            }
            n--;
        }
    }

    bool elementoExiste(int valor){

        No *aux = cabeca;
        bool existe = false;

        while(aux != NULL){

            if(aux->valor == valor){
                existe = true;
            }
            aux = aux->prox;
        }

        return existe;
    }

    void removerRepetidos(int valor){

        No *atual = cabeca;
        No *anterior = NULL;
        if(!elementoExiste(valor)){
            return;
        }
        else{
            while(atual != NULL){
                if(atual->valor == valor){

                    if(anterior == NULL){

                        cabeca = atual->prox;
                    } 
                    else {

                        anterior->prox = atual->prox;
                    }
                    if(atual == cauda){
                        
                        cauda = anterior;
                    }

                    No *temp = atual;
                    atual = atual->prox;
                    delete temp;
                    n--;
                } 
                else {
                    anterior = atual;
                    atual = atual->prox;
                }
            }
        }
        
    }

    void inserirNaoExistente(int valor){

        if(!elementoExiste(valor)){
            
            inserirFinal(valor);
        }

    }

};

int main() {

    Lista l;
    l.inserirInicio(5);
    l.inserirInicio(7);
    l.inserirInicio(10);
    l.inserirFinal(8);
    l.inserirFinal(2);
    l.inserirFinal(3);
    l.removerInicio();
    l.removerInicio();
    l.removerInicio();
    l.imprimir();
    printf("***********************\n");

    printf("8 existe?\n%s\n", l.elementoExiste(8) ? "true" : "false");
    printf("9 existe?\n%s\n", l.elementoExiste(9) ? "true" : "false");
    printf("***********************\n");

    l.inserirFinal(9);
    l.inserirFinal(9);
    l.inserirFinal(9);
    l.inserirFinal(9);
    l.imprimir();

    printf("***********************\n");

    l.removerRepetidos(9);
    l.imprimir();
    
    printf("***********************\n");

    l.inserirNaoExistente(8);
    l.inserirNaoExistente(4);

    l.imprimir();

    return 0;
}
