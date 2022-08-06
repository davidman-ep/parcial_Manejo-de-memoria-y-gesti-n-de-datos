#include <iostream>
#include <cstring>
#include <string.h>
#include <ctime>
#include "funciones.h"
#include "funciones2.h"
#include "funciones3.h"

using namespace std;

int main()
{
     //modulo 1________________________________________

    int n=0;//#filas actual
    int opcion=0;
    char cat[20];
    char **p=nullptr;
    char **c=nullptr;

    c=new char*[n+1];
    reservarFilas(c,n);

    while (opcion!=3) {
        //
        cout<<"\n****OPCIONES****"<<endl;
        cout<<"1.Agregar nueva categoria:\n2.visualizar registro\n3.desea salir\n";
        cin>>opcion;
        switch (opcion) {
        case 1:
            p=new char*[n+1];//reseva de memoria dinamica
            reservarFilas(p,n);//reserva de las filas

            if(n!=0){//este if, no opera en la primera iteracion
                copiaMatriz(p,c,n-1);// se copia informacion de la matriz copia a original
                c=new char*[n+1];// se reserva memoria dinamica de copia
                reservarFilas(c,n);//reserva de filas + 1
            }

            do {
                cout<<"nueva categoria: ";
                cin>>cat;//ingreso de nueva categoria al registro
            } while (comparar(p,cat,n)==0);//si funcion retorna 0, existe categoria
            //permanece en el bucle, si !=0 sale del bu


            nuevoRegistro(p,cat,n);//se ingresa categoria en la fila #n
            copiaMatriz(c,p,n);//se copia informacion desde la original
            liberarMemoria(p,n);//se libera memoria de original
            n++;

            break;
        case 2:
            if(n!=0){
                imprimirMatriz(c,n-1);
            }
            break;
        case 3:
            cout<<"registro actualizado"<<endl<<endl;
            break;
        default:
            cout<<"****opcion incorrecta****"<<endl;

        }


    }
    //modulo 2_______________________________________________
    cout<<"\n***Registro de Usuario**"<<endl<<endl;

    int m=0;//#de filas de la matriz 3d
    opcion=0;
    char ***p2=nullptr;
    char ***c2=nullptr;

    c2=new char **[6];
    reservarFilasColumnas(c2,m);

    while (opcion!=3) {
        //
        cout<<"\n****OPCIONES****"<<endl;
        cout<<"1.Agregar nueva usuario:\n2.Visualizar base de datos\n3.Desea salir\n";
        cin>>opcion;
        switch (opcion) {
        case 1:
            p2=new char**[6];//reseva de memoria dinamica
            reservarFilasColumnas(p2,m);

            if(m!=0){
                copiaUsuarios(p2,c2,m-1);// se copia informacion de la matriz copia a original
                c2=new char**[6];// se reserva memoria dinamica de copia
                reservarFilasColumnas(c2,m);//reserva de filas + 1
            }
            do {
                cout<<"Nueva identificacion: ";
                cin>>cat;
            } while (compararUsuario(p2,cat,m)==0);

            nuevoRegistroUsuario(p2,cat,m);
            copiaUsuarios(c2,p2,m);
            liberarListaUsuarios(p2,m);

            m++;

            break;
        case 2:
            if(m!=0){
                imprimirBasedatos(c2,m-1);
            }
            break;
        case 3:
            cout<<"registro actualizado"<<endl;
            break;
        default:
            cout<<"****opcion incorrecta****"<<endl;

        }


    }

    //modulo 3__________________________________________________
//    cout<<"****Registro de Transacciones****"<<endl<<endl;

//    int t=0;
//    char ***trasc=nullptr;
//    char ***historial=nullptr;

//    historial=new char **[3];
//    reservarFilasColumnasTran(historial,t);

//    while (opcion!=3) {
//        //
//        cout<<"\n****OPCIONES****"<<endl;
//        cout<<"1.Nueva transaccion\n2.Visualizar movimientos\n3.Desea salir\n";
//        cin>>opcion;
//        switch (opcion) {
//        case 1:
//            trasc=new char**[3];
//            reservarFilasColumnasTran(trasc,t);

//            if(t!=0){
//                copiaTran(trasc,historial,t-1);
//                historial=new char**[3];
//                reservarFilasColumnasTran(historial,t);
//            }

//            cout<<"Ingrese vallor de transaccion:  ";
//            nuevoTransaccion(trasc,cat,t);
//            copiaTran(historial,trasc,t);
//            liberarListaTran(trasc,t);
//            t++;


//            break;
//        case 2:
//            if(t!=0){
//                imprimirBasedatosTran(historial,t-1);
//            }
//            break;
//        case 3:
//            cout<<"***fin de transacciones***"<<endl;
//            break;
//        default:
//            cout<<"****opcion incorrecta****"<<endl;

//        }
//    }



    //modulo 4___________________________________________________________


    int cont=0;

    cout<<"***Aplicacion para listar busqueda**"<<endl<<endl;
    opcion =0;

    while (opcion!=3) {
        cout<<"Ingrese criterio de busqueda: ";
        cin>>cat;
        cout<<"**listas de busqueda**"<<endl;
        cout<<"1.primer registro\n2.segundo registro\n3.salir de la busqueda"<<endl;
        cin>>opcion;

        switch (opcion) {
        case 1:

            for(int i=0;i<n;i++){

                for(int j=0;j<=int(strlen(c[i]))-int(strlen(cat))+1;j++){

                    for(int k=0;k<int(strlen(cat));k++){

                        if(c[i][j+k]!=cat[k]){
                            break;
                        }
                        else {
                            cont++;
                        }
                    }
                    if(cont==int(strlen(cat))){
                        cout<<c[i]<<endl;
                        cont=0;
                        break;
                    }
                    cont=0;
                }
            }

            break;

        case 2:
            for(int i=0;i<m; i++){

                for(int j=0;j<6;j++){

                    for(int k=0;k<int(strlen(c2[j][i]))-int(strlen(cat))+1;k++){

                        for(int l=0;l<int(strlen(cat));l++){
                            if(c2[j][i][l+k]!=cat[l]){
                                break;
                            }
                            else {
                                cont++;
                            }
                        }
                        if(cont==int(strlen(cat))){
                            break;
                        }
                        cont=0;
                    }
                    if(cont==int(strlen(cat))){
                        for(int c=0;c<6;c++){
                            cout<<c2[c][i]<<" ";
                        }
                        cout<<endl;
                        cont=0;
                        break;
                    }
                }
            }

            break;
        case 3:
            cout<<"**fin de busquedas**"<<endl;
            break;
        default:
            cout<<"****opcion incorrecta****"<<endl;


    }


    }

//modulo 5

  liberarMemoria(c,n);
  liberarListaUsuarios(c2,m);
  //liberarListaTran(historial,t);



    return 0;
}

