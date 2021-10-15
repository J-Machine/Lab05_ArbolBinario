// UNSA - Ciencia de la Computación
// Algoritmos y Estructura de Datos
// Martes 12 de Octubre del 2021
// 7 : 15 de la mañana
// Primer examen parcial
// NOMBRES: Fiorela Estefany Villarroel Ramos
// APELLIDOS: Villarroel Ramos
// Link de Respuetas: https://docs.google.com/forms/d/e/1FAIpQLSdQkwgHGmSo_4BSOgXAjOojj8MgK41pqCQCwWjTL7dkw8Yy1w/viewform

#include <iostream>
#include <cstdlib>
#include <stack>
using namespace std;

template <class T>
class Nodo
{
public:
    T dato;
    Nodo<T> *hijo[2];

    Nodo(T d)
    {
        dato = d;
        hijo[0] = 0;
        hijo[1] = 0;
    }
};

template <class T>
class Binary_Tree
{
public:
    Nodo<T> *raiz;

public:
    Binary_Tree() : raiz(0){};

    void insert(const T &d)
    {

        Nodo<T> *aux = raiz;
        while (aux != nullptr)
        {
            if (aux->hijo[aux->dato < d])
            {
                aux = aux->hijo[aux->dato < d];
            }
            else
            {
                break;
            }
        }

        if (raiz == nullptr)
        {
            Nodo<T> *newnodo = new Nodo<T>(d);
            raiz = newnodo;
        }
        else if (aux->dato == d)
        {
        }
        else
        {
            Nodo<T> *newnodo = new Nodo<T>(d);
            aux->hijo[aux->dato < d] = newnodo;
        }
    }

    bool find(const T &d, Nodo<T> *p)
    {
        if (p == nullptr)
            return false;
        if (p->dato == d)
            return true;
        return finds(d, p->hijo[p->dato > d]);
    }

    bool find(const T &d)
    {
        return find(d, raiz);
    }

    Nodo<T> *findMin(Nodo<T> *t) const
    {
        if (t == nullptr)
            return nullptr;
        if (t->hijo[0] == nullptr)
            return t;
        return findMin(t->hijo[0]);
    }

    void remove(const T &x, Nodo<T> *&t)
    {
        if (t == nullptr)
            return;
        if (x < t->dato)
            remove(x, t->hijo[0]);
        else if (t->dato < x)
            remove(x, t->hijo[1]);
        else if (t->hijo[0] != nullptr && t->hijo[1] != nullptr)
        {
            t->dato = findMin(t->hijo[1])->dato;
            remove(t->dato, t->hijo[1]);
        }
        else
        {
            Nodo<T> *aux = t;
            t = (t->hijo[0] != nullptr) ? t->hijo[0] : t->hijo[1];
            delete aux;
        }
    }

    void eliminar(const T &x)
    {
        remove(x, raiz);
    }

    void inorder(Nodo<T> *tmp)
    {
        if (!tmp)
            return;
        inorder(tmp->hijo[0]);
        cout << tmp->dato << " ";
        inorder(tmp->hijo[1]);
    }

    void print()
    {
        inorder(raiz);
    }
};

int main()
{
    srand(9);
    Binary_Tree<int> A;

    A.insert(6);
    A.insert(2);
    A.insert(8);
    A.insert(1);
    A.insert(4);
    A.insert(3);
    A.print();
    A.eliminar(4);
    cout << endl;
    A.print();

    return 1;
}