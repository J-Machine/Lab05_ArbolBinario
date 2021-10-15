#include <iostream>
using namespace std;

using namespace std;
struct nodo
{
    int nro;
    struct nodo *izq, *der;
};

typedef struct nodo *ArbolBinario;

// Crear Nodo
ArbolBinario crearNodo(int x)
{
    ArbolBinario nuevoNodo = new (struct nodo);
    nuevoNodo->nro = x;
    nuevoNodo->izq = nullptr;
    nuevoNodo->der = nullptr;
    return nuevoNodo;
}

// Insertar nodo
void insertar(ArbolBinario &arbol, int x)
{
    if (arbol == nullptr)
        arbol = crearNodo(x);
    else if (x < arbol->nro)
        insertar(arbol->izq, x);
    else if (x > arbol->nro)
        insertar(arbol->der, x);
}

// Buscar valor en los nodos
bool busqueda(ArbolBinario &arbol, int x)
{
    if (arbol == nullptr)
        return false;
    else if (x == arbol->nro)
        return true;
    else if (x < arbol->nro)
        return busqueda(arbol->izq, x);
    else if (x >  arbol->nro)
        return busqueda(arbol->der, x);
}

// Recorrido PreOrden
void preOrden(ArbolBinario arbol)
{
    if (arbol != nullptr)
    {
        cout << arbol->nro << " ";
        preOrden(arbol->izq);
        preOrden(arbol->der);
    }
}

// Recorrido EnOrden
void enOrden(ArbolBinario arbol)
{
    if (arbol != nullptr)
    {
        enOrden(arbol->izq);
        cout << arbol->nro << " ";
        enOrden(arbol->der);
    }
}
// Recorrido PostOrden
void postOrden(ArbolBinario arbol)
{
    if (arbol != nullptr)
    {
        postOrden(arbol->izq);
        postOrden(arbol->der);
        cout << arbol->nro << " ";
    }
}
int main()
{
    ArbolBinario arbol = nullptr;
    cout << "\n ...EJEMPLO DE ARBOL BINARIO... \n";
    insertar(arbol, 4);
    insertar(arbol, 8);
    insertar(arbol, 2);
    insertar(arbol, 9);
    insertar(arbol, 3);
    insertar(arbol, 6);
    insertar(arbol, 1);
    insertar(arbol, 7);
    insertar(arbol, 5);
    cout << "\nRecorridos del ArbolBinario\n";
    cout << "\nEn orden : ";
    enOrden(arbol);
    cout << "\nPre Orden : ";
    preOrden(arbol);
    cout << "\nPost Orden : ";
    postOrden(arbol);
    cout << endl;
    cout << "\nBúsqueda de 0 en ArbolBinario\n";
    cout << ((busqueda(arbol, 0))? "Encontrado": "No encontrado")<< endl;

    return 0;
}