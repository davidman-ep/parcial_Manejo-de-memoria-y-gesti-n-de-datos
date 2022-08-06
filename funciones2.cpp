#include "funciones2.h"
#include <cstring>
#include <iostream>

using namespace std;


void reservarFilasColumnas(char ***p, int filas)
{
    for(int i=0;i<6;i++){
        p[i]=new char*[filas+1];
        for(int j=0;j<filas+1;j++){
            p[i][j]=new char [20]{'\0'};
        }
    }
}

void nuevoRegistroUsuario(char ***p, char categoria[], int m)
{

    for (int i=0;i<int(strlen(categoria));i++) {
        p[0][m][i]=categoria[i];
    }
    cout<<"Nombre: ";
    cin>>categoria;
    for (int i=0;i<int(strlen(categoria));i++) {
        p[1][m][i]=categoria[i];
    }
    cout<<"Apellido: ";
    cin>>categoria;
    for (int i=0;i<int(strlen(categoria));i++) {
        p[2][m][i]=categoria[i];
    }
    cout<<"Nacionalidad: ";
    cin>>categoria;
    for (int i=0;i<int(strlen(categoria));i++) {
        p[3][m][i]=categoria[i];
    }
    cout<<"Telefono: ";
    cin>>categoria;
    for (int i=0;i<int(strlen(categoria));i++) {
        p[4][m][i]=categoria[i];
    }
    cout<<"Fecha de nacimiento: ";
    cin>>categoria;
    for (int i=0;i<int(strlen(categoria));i++) {
        p[5][m][i]=categoria[i];
    }

}

int compararUsuario(char ***p, char dato[], int m)
{

    for(int i=0;i<=m;i++){

        if(strcmp(p[0][i],dato)==0){
            cout<<"Esta identificacion existe!"<<endl;
            return 0;
        }
    }
    return 1;
}

void copiaUsuarios(char ***copia, char ***original, int n)
{

    for (int i=0;i<6;i++) {

        for(int j=0;j<=n;j++){

            for(int k=0;k<int(strlen(original[i][j]));k++){

                copia[i][j][k]=original[i][j][k];
            }
        }
    }


}

void liberarListaUsuarios(char ***p, int n)
{
    for(int i=0;i<6;i++){
        for(int j=0;j<=n;j++){
            delete [] p[i][j];
        }
    }
    delete [] p;
}

void imprimirBasedatos(char ***p, int m)
{
    for(int fila=0; fila<=m;fila++){

        for(int cate=0;cate<6;cate++){

            cout<<p[cate][fila]<<"  ";

        }
        cout<<endl;
    }
}
