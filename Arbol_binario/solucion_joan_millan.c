#include <stdlib.h>

typedef struct nodo {
    int valor;
    struct nodo *izq;
    struct nodo *der;
} Nodo;

int buscar(const int *in, int inicio, int fin, int valor) {
    for (int i = inicio; i <= fin; i++) {
        if (in[i] == valor)
            return i;
    }
    return -1;
}

Nodo* reconstruir(const int *pre, const int *in, int inicio, int fin, int *pre_idx) {
    if (inicio > fin)
        return NULL;
    
    Nodo *raiz = (Nodo*)malloc(sizeof(Nodo));
    raiz->valor = pre[*pre_idx];
    raiz->izq = NULL;
    raiz->der = NULL;
    
    (*pre_idx)++;
    
    if (inicio == fin)
        return raiz;
    
    int in_idx = buscar(in, inicio, fin, raiz->valor);
    
    raiz->izq = reconstruir(pre, in, inicio, in_idx - 1, pre_idx);
    raiz->der = reconstruir(pre, in, in_idx + 1, fin, pre_idx);
    
    return raiz;
}

Nodo* construir(const int *pre, const int *in, int n) {
    if (n == 0)
        return NULL;
    
    int pre_idx = 0;
    return reconstruir(pre, in, 0, n - 1, &pre_idx);
}
