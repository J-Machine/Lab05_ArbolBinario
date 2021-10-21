#include <bits/stdc++.h>
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
class ArbolBinarioBusqueda
{
public:
    Nodo<T> *raiz;

public:
    /////////////////////CONSTRUCTOR//////////////////////////////////
    ArbolBinarioBusqueda() : raiz(0){};

    /////////////////////INSERTAR//////////////////////////////////
    void insert(const T &d)
    {

        Nodo<T> *aux = raiz;
        while (aux != nullptr)
        {

            if (aux->dato == d)
            {
                return;
            }
            else if (aux->hijo[aux->dato < d])
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
        else
        {
            Nodo<T> *newnodo = new Nodo<T>(d);
            aux->hijo[aux->dato < d] = newnodo;
        }
    }

    //////////////////////BUSCAR//////////////////////////////////
    bool find(const T &d, Nodo<T> *p)
    {
        if (p == nullptr)
            return false;
        if (p->dato == d)
            return true;
        else if (p->dato > d)
            return find(d, p->hijo[0]);
        else if (p->dato < d)
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

    //////////////////////ELIMINAR//////////////////////////////////
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

    //////////////////////ELIMINAR//////////////////////////////////
    bool eliminar(const T &x)
    {
        if (find(x))
        {
            remove(x, raiz);
            return true;
        }
        else
        {
            return false;
        }
    }

    //////////////////////INORDER//////////////////////////////////
    void inorder(Nodo<T> *tmp)
    {
        if (!tmp)
            return;
        inorder(tmp->hijo[0]);
        cout << tmp->dato << " ";
        inorder(tmp->hijo[1]);
    }

    //////////////////////PREORDER//////////////////////////////////
    void preorder(Nodo<T> *tmp)
    {
        if (!tmp)
            return;
        cout << tmp->dato << " ";
        preorder(tmp->hijo[0]);
        preorder(tmp->hijo[1]);
    }

    //////////////////////POSTORDER//////////////////////////////////
    void postorder(Nodo<T> *tmp)
    {
        if (!tmp)
            return;
        postorder(tmp->hijo[0]);
        postorder(tmp->hijo[1]);
        cout << tmp->dato << " ";
    }

    void inorder()
    {
        inorder(raiz);
    }
    void preorder()
    {
        preorder(raiz);
    }
    void postorder()
    {
        postorder(raiz);
    }

    ///////////////////////// CLEAR TREE /////////////////////////
    void clearNodes(Nodo<T> *_node)
    {
        if (_node == nullptr)
            return;
        clearNodes(_node->hijo[0]);
        clearNodes(_node->hijo[1]);
        cout << "\n Eliminando nodo: " << _node->dato;
        if (_node == raiz)
            raiz = 0;
        else
            delete _node;
    }

    void clear()
    {
        clearNodes(raiz);
    }
    //////////////////////PRINT//////////////////////////////////
    void print()
    {
        if (raiz == nullptr)
            cout << "El árbol esta vacío \n";
        else
            inorder(raiz);
    }

    //////////////////////GRAFICAR//////////////////////////////////
    void escribirdot(ofstream &archivo, Nodo<T> *ARBOL, int i)
    {
        if (ARBOL)
        {
            i++;
            if (ARBOL->hijo[0])
            {
                archivo << ARBOL->dato << " -> " << ARBOL->hijo[0]->dato << "\n";
            }
            else
            {
                archivo << "izq" << i << " [width=.1,style=invis]";
                archivo << ARBOL->dato << " -> izq" << i << " [style=invis]"
                        << "\n";
            }
            if (ARBOL->hijo[1])
            {
                archivo << ARBOL->dato << " -> " << ARBOL->hijo[1]->dato << "\n";
            }
            else
            {
                archivo << "der" << i << " [width=.1,style=invis]";
                archivo << ARBOL->dato << " -> der" << i << " [style=invis]"
                        << "\n";
            }

            escribirdot(archivo, ARBOL->hijo[0], i); // recorrer por la derecha
            escribirdot(archivo, ARBOL->hijo[1], i); // recorrer por la izquierda
        }
    }

    void graficar()
    {
        ofstream archivo;
        archivo.open("D:\\Graphviz\\bin\\arbolito.dot");
        if (archivo.is_open())
        {
            archivo << "digraph C { \n";
            escribirdot(archivo, raiz, 0);
            archivo << "}\n";
            archivo.close();
            system("dot -Tpdf D:\\Graphviz\\bin\\arbolito.dot -o D:\\Graphviz\\bin\\arbolito.pdf ");
        }
        else
        {
            cout << "error al crear archivo";
        }
    }
};

int main()
{
    ArbolBinarioBusqueda<int> A;

    cout << "\nEJEMPLO DE ARBOL BINARIO\n";
    A.insert(6);
    A.insert(5);
    A.insert(5);
    A.insert(5);
    A.insert(8);
    A.insert(1);
    A.insert(4);
    A.insert(3);
    A.inorder();
    cout << endl;

    cout << "\nBuscar elemento 4 en el arbol binario: \n"
         << (A.find(4) ? "Encontrado" : "No encontrado") << endl;

    cout << "\nEliminar elemento 4 del arbol binario: \n";
    A.eliminar(4);
    A.inorder();
    cout << endl;

    cout << "\nBuscar elemento 4 en el arbol binario: \n"
         << (A.find(4) ? "Encontrado" : "No encontrado") << endl;
    cout << endl;

    cout << "Arbol en InOrden: ";
    A.inorder();
    cout << endl;
    cout << "Arbol en PostOrden: ";
    A.postorder();
    cout << endl;
    cout << "Arbol en PreOrden: ";
    A.preorder();
    cout << endl;

    cout << "\nEliminar nodos del arbol binario: \n";
    A.clear();    
    cout << endl;
    A.print();
    cout << endl;

    cout << "Grafico del arbol: ";
    A.graficar();
    system("D:\\Graphviz\\bin\\arbol.png");

    return 0;
}