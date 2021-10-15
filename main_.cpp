#include <iostream>

using namespace std;
struct nodo
{
    int nro;
    struct nodo *izq, *der, *padre;
};

typedef struct nodo *ArbolBinario;

// Crear Nodo
ArbolBinario crearNodo(int x, ArbolBinario padre)
{
    ArbolBinario nuevoNodo = new (struct nodo);
    nuevoNodo->nro = x;
    nuevoNodo->izq = nullptr;
    nuevoNodo->der = nullptr;
    nuevoNodo->padre = padre;
    return nuevoNodo;
}

// Insertar nodo
void insertar(ArbolBinario &arbol, ArbolBinario padre, int x)
{
    if (arbol == nullptr)
        arbol = crearNodo(x, padre); // min 2.57
    else if (x < arbol->nro)
        insertar(arbol->izq, arbol, x);
    else if (x > arbol->nro)
        insertar(arbol->der, arbol, x);
}

// ** ELIMINAR NODO **
// Func. aux. Destruir nodo
void destruirNodo(ArbolBinario &nodo)
{
    nodo->izq = nullptr;
    nodo->der = nullptr;
    delete nodo;
}
// Función aux. encontrar mínimo de una rama
ArbolBinario nodoMinimo(ArbolBinario &arbol)
{
    if(arbol == nullptr) 
        return nullptr;
    else if (arbol->izq)
        return nodoMinimo(arbol->izq);
    else 
        return arbol;

}
void reemplazar(ArbolBinario &arbol, ArbolBinario &nuevoNodo)
{

}
// Función aux. Eliminar nodo específico
void eliminarNodo(ArbolBinario &arbol)
{
    if(arbol->der && arbol->izq)            // Tiene 2 hijos
    {

    }   
    else if (arbol->izq)                    // Tiene 1 hijo izquierdo
    {
        // reemplazar(arbol, arbol->izq)
        // destruirNodo(arbol)

    } 
    else if (arbol->der)                    // Tiene 1 hijo derecho
    {
        // reemplazar(arbol, arbol->der)
        // destruirNodo(arbol)
    } 
    else                                    // No tiene hijos
    {
        // reemplazar(arbol, nullptr)
        // destruirNodo(arbol)
    }
}
//* Eliminar nodo (de acuerdo a valor que contiene)
void eliminar(ArbolBinario &arbol, int x)
{
    if(arbol == nullptr)
        return;
    else if(x < arbol->nro)
        eliminar(arbol->izq, x);
    else if (x > arbol->nro)
        eliminar(arbol->der, x);
    else                            // x es igual al valor del nodo arbol
    {
        eliminarNodo(arbol);
    }
    
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
    cout << "\nEJEMPLO DE ARBOL BINARIO\n";
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