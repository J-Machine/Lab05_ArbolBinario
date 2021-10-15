#include <iostream>
#include <cstdlib>
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
        else if(p->dato > d)
            return find(d, p->hijo[0]);
        else if(p->dato < d)
            return find(d, p->hijo[1]);
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
    Binary_Tree<int> A;

    cout << "\nEJEMPLO DE ARBOL BINARIO\n";
    A.insert(6);
    A.insert(2);
    A.insert(8);
    A.insert(1);
    A.insert(4);
    A.insert(3);
    A.print();
    cout << endl;

    cout << "\nBuscar elemento 4 en el arbol binario: \n"
         << (A.find(4) ? "Encontrado": "No encontrado")<< endl;

    cout << "\nEliminar elemento 4 del arbol binario: \n";
    A.eliminar(4);
    A.print();
    cout << endl;

    cout << "\nBuscar elemento 4 en el arbol binario: \n"
         << (A.find(4)? "Encontrado": "No encontrado")<< endl;
    cout << endl;

    return 0;
}