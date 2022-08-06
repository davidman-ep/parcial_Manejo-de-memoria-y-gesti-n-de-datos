#include "funciones3.h"
#include <cstring>
#include <ctime>

#include <iostream>
using namespace std;


void reservarFilasColumnasTran(char ***p, int filas)
{
    for(int i=0;i<3;i++){
        p[i]=new char*[filas+1];
        for(int j=0;j<filas+1;j++){
            p[i][j]=new char [20]{'\0'};
        }
    }
}
void nuevoTransaccion(char ***p, char categoria[], int m)
{
    //fecha
    fecha(categoria);
    for (int i=0;i<int(strlen(categoria));i++) {
        p[0][m][i]=categoria[i];
    }
    //hora    
    hora(categoria);
    for (int i=0;i<int(strlen(categoria));i++) {
        p[1][m][i]=categoria[i];
    }
    //monto    
    cin>>categoria;
    for (int i=0;i<int(strlen(categoria));i++) {
        p[2][m][i]=categoria[i];
    }

}
void fecha(char fecha[])
{    
    time_t now= time(0);
    tm *time=localtime(&now);
    char d[2]{'\0'};
    char m[2]{'\0'};
    char a[4]{'\0'};
    int dia,mes,anio;
    dia=time->tm_mday;    
    mes=time->tm_mon+1;    
    anio=time->tm_year+1900;

    conv(d,dia);
    invertir_array(d,2);
    fecha[0]=d[0];
    fecha[1]=d[1];
    conv(m,mes);
    invertir_array(m,2);
    fecha[2]='/';
    fecha[3]=m[0];
    fecha[4]=m[1];
    conv(a,anio);
    invertir_array(a,4);
    fecha[5]='/';
    fecha[6]=a[0];
    fecha[7]=a[1];
    fecha[8]=a[2];
    fecha[9]=a[3];
    fecha[10]='\0';

}

void hora(char hour[])
{
    time_t now= time(0);
    tm *time=localtime(&now);
    char h[2]{'\0'};
    char m[2]{'\0'};
    char s[2]{'\0'};
    int hora,minuto,seg;

    hora=time->tm_hour;
    minuto=time->tm_min;
    seg=time->tm_sec;

    conv(h,hora);
    invertir_array(h,2);
    hour[0]=h[0];
    hour[1]=h[1];
    conv(m,minuto);
    invertir_array(m,2);
    hour[2]=':';
    hour[3]=m[0];
    hour[4]=m[1];
    conv(s,seg);
    invertir_array(s,2);
    hour[5]=':';
    hour[6]=s[0];
    hour[7]=s[1];
    hour[8]='\0';


}

void invertir_array(char a[],int cant){
    char aux;
    for(int i=0;i<(cant/2);i++){
        aux=a[i];
        a[i]=a[cant-1-i];
        a[cant-1-i]=aux;
    }
}

void conv(char array[], int num)
{
    int i=0;
    if(num<10){
        array[1]='0';
        array[0]=(num%10)+48;
    }
    else {
        while (num>0) {
               array[i]=(num%10)+48;
               num/=10;
               i++;
           }
    }
}



void copiaTran(char ***copia, char ***original, int t)
{

    for (int i=0;i<3;i++) {

        for(int j=0;j<=t;j++){

            for(int k=0;k<int(strlen(original[i][j]));k++){

                copia[i][j][k]=original[i][j][k];
            }
        }
    }

}

void liberarListaTran(char ***p, int n)
{
    for(int i=0;i<3;i++){
        for(int j=0;j<=n;j++){
            delete [] p[i][j];
        }
    }
    delete [] p;
}
void imprimirBasedatosTran(char ***p, int m)
{
    for(int fila=0; fila<=m;fila++){

        for(int cate=0;cate<3;cate++){

            cout<<p[cate][fila]<<"  ";

        }
        cout<<endl;
    }
}
