#include "funciones.h"
#include <cstring>

#include <iostream>

using namespace std;


void reservarFilas(char **p, int n)
{
    for (int i=0;i<=n;i++ ) {
        p[i]=new char [15]{'\0'};
    }
}

void imprimirMatriz(char **p, int n)
{
        for (int i=0;i<n+1;i++ ) {
            cout<<p[i]<<endl;
        }
}

void copiaMatriz(char **copia, char **original, int n)
{
    for(int k=0;k<=n;k++){
        for(int j=0;j<int(strlen(original[k]));j++){
            copia[k][j]=original[k][j];
        }
    }
}
void nuevoRegistro(char **p, char categoria[], int n)
{
    for (int i=0;i<int(strlen(categoria)) ;i++ ) {
         p[n][i]=categoria[i];
    }
}
void liberarMemoria(char **p, int n)
{
    for(int i=0;i<=n;i++){
        delete [] p[i];
    }
    delete []p;
}
bool categoriaRepetida(char **lista, char categoria[], int n)
{
    bool iso=false;
    int len=0;
    if(n==0){
        return iso;
    }

    for (int i=0;i<n;i++ ){

        cout<<"lista: "<<strlen(lista[i])<<endl;
        cout<<"categoria: "<<strlen(categoria)<<endl;
        if(int(strlen(lista[i]))==int(strlen(categoria))){
            for(int j=0;j<int(strlen(lista[i]));j++){
                if(lista[i][j]!=categoria[j]){
                    len++;
                }
                if(len==int(strlen(categoria))){
                    iso=true;
                    return iso;
                }
                len=0;
            }
        }
    }


    return iso;
}

int comparar(char **p,char categ[] , int n)
{
    for(int i=0;i<=n;i++){
        if(strcmp(p[i],categ)==0){
            cout<<"esta categoria existe"<<endl;
            return 0;
        }
    }
    return 1;
}
