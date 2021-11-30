#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

struct nodo
{
    int dato;
    struct nodo *sig;
}*ultimo;
 
class lista_circular
{
    public:
        void crear_nodo(int valor);
        void insertar_inicio(int valor);
        void insertar_pos(int valor, int pos);
        void eliminar(int valor);
        void buscar(int valor);
        void imprimir();
        void actualizar_elemento();
        void recorrer();
        lista_circular()
        {
            ultimo = NULL;           
        }
};
 
int main()
{
    int opc, elemento, pos;
    lista_circular lc;
    while (1)
    {
        cout<<endl<<"---------------------------------"<<endl;
        cout<<endl<<"Lista Circular Simplemente Ligada"<<endl;
        cout<<endl<<"---------------------------------"<<endl;     
        cout<<"1. Crear Nodo"<<endl;
        cout<<"2. Insertar al inicio"<<endl;
        cout<<"3. Insertar por posicion"<<endl;
        cout<<"4. Eliminar"<<endl;
        cout<<"5. Buscar"<<endl;
        cout<<"6. Imprimir"<<endl;
        cout<<"7. Actualizar elemento"<<endl;
        cout<<"8. Recorrer"<<endl;
        cout<<"9. Salir"<<endl;
        cout<<"Seleccionar opcion: ";
        cin>>opc;
        switch(opc)
        {
        case 1:
            cout<<"Ingresa el elemento: ";
            cin>>elemento;
            lc.crear_nodo(elemento);
            cout<<endl;
            break;
        case 2:
            cout<<"Ingresa el elemento: ";
            cin>>elemento;
            lc.insertar_inicio(elemento);
            cout<<endl;
            break;
        case 3:
            cout<<"Ingresa el elemento: ";
            cin>>elemento;
            cout<<"Inserta el elemento despues de la posicion: ";
            cin>>pos;
            lc.insertar_pos(elemento, pos);
            cout<<endl;
            break;
        case 4:
            if (ultimo == NULL)
            {
                cout<<"La lista esta VACIA, no hay nada que eliminar"<<endl;
                break;
            }
            cout<<"Ingresa el elemento a eliminar: ";
            cin>>elemento;
            lc.eliminar(elemento);
            cout<<endl;
            break;
        case 5:
            if (ultimo == NULL)
            {
                cout<<"La lista esta VACIA, no hay nada que buscar"<<endl;
                break;
            }
            cout<<"Ingresa el elemento a buscar: ";
            cin>>elemento;
            lc.buscar(elemento);
            cout<<endl;
            break;
        case 6:
            lc.imprimir();
            break;
        case 7:
            lc.actualizar_elemento();
            break;
        case 8:
            lc.recorrer();
            break;                      
        case 9:
            exit(1);
            break;
        default:
            cout<<"Opcion no valida"<<endl;
        }
    }
    return 0;
}
 
void lista_circular::crear_nodo(int valor)
{
    struct nodo *temp;
    temp = new(struct nodo);
    temp->dato = valor;
    if (ultimo == NULL)
    {
        ultimo = temp;
        temp->sig = ultimo;   
    }
    else
    {
        temp->sig = ultimo->sig; 
        ultimo->sig = temp;
        ultimo = temp;
    }
}
 
void lista_circular::insertar_inicio(int valor)
{
    if (ultimo == NULL)
    {
        cout<<"Para utilizar esta funcion primero crea una lista."<<endl;
        return;
    }
    struct nodo *temp;
    temp = new(struct nodo);
    temp->dato = valor;
    temp->sig = ultimo->sig;
    ultimo->sig = temp;
}
 
void lista_circular::insertar_pos(int valor, int pos)
{
    if (ultimo == NULL)
    {
        cout<<"Para utilizar esta funcion primero crea una lista."<<endl;
        return;
    }
    struct nodo *temp, *s;
    s = ultimo->sig;
    for (int i = 0;i < pos-1;i++)
    {
        s = s->sig;
        if (s == ultimo->sig)
        {
            cout<<"Hay menos de ";
            cout<<pos<<" en la lista"<<endl;
            return;
        }
    }
    temp = new(struct nodo);
    temp->sig = s->sig;
    temp->dato = valor;
    s->sig = temp;
 
    if (s == ultimo)
    { 
        ultimo=temp;
    }
}
 
void lista_circular::eliminar(int valor)
{
    struct nodo *temp, *s;
    s = ultimo->sig;

    if (ultimo->sig == ultimo && ultimo->dato == valor)  
    {
        temp = ultimo;
        ultimo = NULL;
        free(temp);
        return;
    }
    if (s->dato == valor) 
    {
        temp = s;
        ultimo->sig = s->sig;
        free(temp);
        return;
    }
    while (s->sig != ultimo)
    {
        if (s->sig->dato == valor)    
        {
            temp = s->sig;
            s->sig = temp->sig;
            free(temp);
            cout<<"Elemento "<<valor;
            cout<<" eliminado de la lista"<<endl;
            return;
        }
        s = s->sig;
    }

    if (s->sig->dato == valor)    
    {
        temp = s->sig;
        s->sig = ultimo->sig;
        free(temp);		
        ultimo = s;
        return;
    }
    cout<<"Elemento "<<valor<<" no encontrado en la lista"<<endl;
}
 
void lista_circular::buscar(int valor)
{
    struct nodo *s;
    int cont = 0;
    s = ultimo->sig;
    while (s != ultimo)
    {
        cont++;
        if (s->dato == valor)    
        {
            cout<<"Elemento "<<valor; 
            cout<<" encontrado en la posicion "<<cont<<endl;
            return;
        }
        s = s->sig;
    }
    if (s->dato == valor)    
    {
        cont++;             
        cout<<"Elemento "<<valor;
        cout<<" encontrado en la posicion "<<cont<<endl;
        return;
    }
    cout<<"Elemento "<<valor<<" no encontrado en la lista"<<endl;
}
 
void lista_circular::imprimir()
{
    struct nodo *s;
    if (ultimo == NULL)
    {
        cout<<"La lista esta VACIA, no hay nada que imprimir"<<endl;
        return;
    }
    s = ultimo->sig;
    cout<<"Lista Circular Ligada: "<<endl;
    while (s != ultimo)
    {
        cout<<s->dato<<"->";
        s = s->sig;
    }
    cout<<s->dato<<endl;
}
 
void lista_circular::actualizar_elemento()
{
    int valor, pos, i;
    if (ultimo == NULL)
    {
        cout<<"La lista esta VACIA, no hay nada que actualizar"<<endl;
        return;
    }
    cout<<"Ingresa la posicion del nodo a actualizar: ";
    cin>>pos;
    cout<<"Ingresa el nuevo valor: ";
    cin>>valor;
    struct nodo *s;
    s = ultimo->sig;
    for (i = 0;i < pos - 1;i++)
    {
        if (s == ultimo)
        {
            cout<<"Hay menos de "<<pos<<" elementos.";
            cout<<endl;
            return;
        }
        s = s->sig;
    }
    s->dato = valor;  
    cout<<"Nodo actualizado"<<endl;
} 
 
void lista_circular::recorrer()
{
    struct nodo *s, *ptr;
    int temp;
    if (ultimo == NULL) 
    {
        cout<<"La lista esta VACIA, no hay nada que recorrer"<<endl;
        return;
    }
    s = ultimo->sig;
    while (s != ultimo)
    {
        ptr = s->sig;
        while (ptr != ultimo->sig)
        {
            if (ptr != ultimo->sig)
            {
                if (s->dato > ptr->dato)
                {
                    temp = s->dato;
                    s->dato = ptr->dato;
                    ptr->dato = temp;
                }
            }
            else
            {
                break;
            }
            ptr = ptr->sig;    
        }
        s = s->sig;         
    }
}