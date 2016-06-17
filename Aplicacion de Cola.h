#include <iostream>
using namespace std;
 
 
struct nodo
{
    char nro[10];
    struct nodo *sgte;
};
 
 

struct cola
{
    nodo *delante;
    nodo *atras  ;
};
 
 

void encolar[10]( struct cola &q, char valor[10] )
{
     struct nodo *aux = new(struct nodo);
     
     aux->nro[10] = valor;
     aux->sgte = NULL;
    
     if( q.delante == NULL)
         q.delante = aux;   
     else
         (q.atras)->sgte = aux;
         
     q.atras = aux;        
     
}
 

char desencolar[10]( struct cola &q )
{
     char num ;
     struct nodo *aux ;
     
     aux = q.delante;      
     num = aux->nro;
     q.delante = (q.delante)->sgte;
     delete(aux);          
     
     return num;
}
 

void muestraCola( struct cola q )
{
     struct nodo *aux;
     
     aux = q.delante;
         
     while( aux != NULL )
     {
            cout<<"   "<< aux->nro ;
            aux = aux->sgte;
     }    
}
 

void vaciaCola( struct cola &q)
{
     struct nodo *aux;
     
     while( q.delante != NULL)
     {
            aux = q.delante;
            q.delante = aux->sgte;
            delete(aux);
     }
     q.delante = NULL;
     q.atras   = NULL;
     
}
 

void menu()
{
    cout<<"\n\t APLICACION DE COLAS \n\n";
    cout<<" 1. Push                              "<<endl;
    cout<<" 2. Poop                            "<<endl;
    cout<<" 3. Imprimir                          "<<endl;
    cout<<" 4. Borrar                           "<<endl;
    cout<<" 5. SALIR                                 "<<endl;
 
    cout<<"\n INGRESAR OPCION: ";
}
 
 
char main()
{
    struct cola q;
   
    q.delante = NULL;
    q.atras   = NULL;

   
   
    char dato; 
    int op;    
    char x ;    
   
    system("color 07");
 
    do
    {
        menu();  cin>> op;
 
        switch(op)
        {
            case 1:
 
                 cout<< "\n Ingresar: "; cin>> dato;
                 encolar( q, dato);
                 cout<<"\n\n\t\tNumero " << dato << " ingresado\n\n";
            break;
 
 
            case 2:
 
                 x = desencolar( q );
                 cout<<"\n\n\t\tNumero "<< x <<" borrado\n\n";
            break;
                 
 
            case 3:
 
                 cout << "\n\n Impreso\n\n";
                 if(q.delante!=NULL) muestraCola( q );
                 else   cout<<"\n\n\tCola vacia"<<endl;
            break;
 
 
            case 4:
 
                 vaciaCola( q );
                 cout<<"\n\n\t\tCola Borrada\n\n";
            break;
           
         }
 
        cout<<endl<<endl;
        system("pause");  system("cls");
 
    }while(op!=5);
   
   
    return 0;
}
