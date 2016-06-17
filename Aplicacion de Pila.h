#include <iostream>
using namespace std;
 
struct nodo{
    int nro;
    struct nodo *sgte;
};
 
typedef nodo *ptrPila;   
 
void push( ptrPila &p, int valor )
{
     ptrPila aux;
     aux = new(struct nodo);  
     aux->nro = valor;
     
     aux->sgte = p ;
     p = aux ;
}
 
int pop( ptrPila &p )
{
     int num ;
     ptrPila aux;
     
     aux = p ;
     num = aux->nro;  
     
     p = aux->sgte ;
     delete(aux);
     
     return num;
}
 

void mostrar_pila( ptrPila p )
{
     ptrPila aux;
     aux = p;     
     
     while( aux !=NULL )
     {
            cout<<"\t"<< aux->nro <<endl;
            aux = aux->sgte;
     }    
}
 

void destruir_pila( ptrPila &p)
{
     ptrPila aux;
     
     while( p != NULL)
     {
           aux = p;
           p = aux->sgte;
           delete(aux);
     }
}
 

void menu()
{
    cout<<"\n\t APLICACION DE PILA\n\n";
    cout<<" 1. Pushs                            "<<endl;
    cout<<" 2. Poop                             "<<endl;
    cout<<" 3. Imprimir                         "<<endl;
    cout<<" 4. Eliminar                         "<<endl;
    cout<<" 5. SALIR                            "<<endl;
 
    cout<<"\n INGRESAR OPCION: ";
}
 

int main()
{
    ptrPila p = NULL; 
    int dato;
    int op;
    int x ; 
   
    system("color 07");
 
    do
    {
        menu();  cin>> op;
 
        switch(op)
        {
            case 1:
 
                 cout<< "\n Ingrese Numero: "; cin>> dato;
                 push( p, dato );
                 cout<<"\n\n\t\tNumero " << dato << " Ingresado\n\n";
            break;
 
 
            case 2:
 
                 x = pop( p );
                 cout<<"\n\n\t\tNumero "<< x <<" Borrado\n\n";
            break;
                 
 
            case 3:
 
                 cout << "\n\n Mostrar Numeros\n\n";
                 if(p!=NULL)
                    mostrar_pila( p );
                 else
                    cout<<"\n\n\tPila vacia"<<endl;
            break;
 
 
            case 4:
 
                 destruir_pila( p );
                 cout<<"\n\n\t\tPila Borrada\n\n";
            break;
           
         }
 
        cout<<endl<<endl;
        system("pause");  system("cls");
 
    }while(op!=5);
   
   
    return 0;
}
