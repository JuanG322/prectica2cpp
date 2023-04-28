#include <iostream>
using namespace std;

//Ejercicio 2
bool contarLetras(char arreglo[]){

    int frecuencia[26] = {0};
    for (int i = 0; i < 200; i++) {//Ejemplo si arreglo[i] = A - A por el codigo ASCII es = 0
        int indice = arreglo[i] - 'A';
        frecuencia[indice]++;//Se suma 1 al indice que se indique
    }

    cout << "Veces que se repite cada letra:" << endl;

    for (int i = 0; i < 26; i++) {
        cout << (char)(i+'A') << ": " << frecuencia[i] << endl;// i+'A' para imprimir la letra
    }

}

//Ejercicio 3
bool comparar(char a[], char b[]){
    int i = 0;
    while(a[i] != '\0' && b[i] != '\0'){
        if(a[i] != b[i]) return false;
        i++;
    }
    return a[i] == b[i];
    //if(a[i] == b[i]) return true;
}

//Ejercicio 4
int convertirnum(char a[]){
    int num = 0, i = 0;
    while(a[i] != '\0'){
        switch(a[i]){
            case '0':
                num = num = (num*10);
                break;
            case '1':
                num = (num*10)+ 1;
                break;
            case '2':
                num = (num*10)+ 2;
                break;
            case '3':
                num = (num*10)+ 3;
                break;
            case '4':
                num = (num*10)+ 4;
                break;
            case '5':
                num = (num*10)+ 5;
                break;
            case '6':
                num = (num*10)+ 6;
                break;
            case '7':
                num = (num*10)+ 7;
                break;
            case '8':
                num = (num*10)+ 8;
                break;
            case '9':
                num = (num*10)+ 9;
                break;
        }
        i++;
    }
    return num;
}

//Ejercicio 5
void convertirchar(int a, char b[]){
    int i = 0, aux = 0, unidadad = 0;

    while(a>0){
        unidadad = a%10;
        aux = (aux*10)+unidadad;
        a /= 10;
    }

    while(aux != 0){
        b[i] = '0'+(aux%10);
        aux /= 10;
        i++;
    }

}

//Ejercicio 6
void MintoMay(char a[]){

    int i = 0;
    while(a[i] != '\0'){
        if( (a[i] >= 65 && a[i] <= 90) || (a[i] >= 97 && a[i] <= 122)){
            if(a[i] >= 97 && a[i] <= 122){
                a[i] -= 32;
            }
        }
        i++;
    }
}

//Ejercicio 7
void eliminarrep(char cadena[]){

    int i = 0,a = 0,aux=0;
    while(cadena[i] != '\0'){
        a = i+1;
        while(cadena[a] != '\0'){
            if(cadena[i] == cadena[a]){//compara si la posicion i se repite en la cadena
                aux = a;
                while(cadena[aux+1] != '\0'){
                    cadena[aux] = cadena[aux+1];
                    aux++;
                    if(cadena[aux+1] == '\0')cadena[aux] = '\0';
                }
            }
            a++;
        }
        i++;
    }
}

//Ejercicio 8
void separar(char cadena[]){
    int i = 0,a = 0,b = 0;
    char cadenaletras[] = "Ejemplo";
    char cadenanum[] = "Ejemplo";

    while(cadena[i] != '\0'){
        if( (cadena[i] >= 65 && cadena[i] <= 90) || (cadena[i] >= 97 && cadena[i] <= 122)){
            cadenaletras[a] = cadena[i];
            a++;
            i++;
        }
        else if(cadena[i] >= 48 && cadena[i] <= 57){
            cadenanum[b] = cadena[i];
            b++;
            i++;
        }
    }
    cadenaletras[a] = '\0';
    cadenanum[b] = '\0';
    cout<<cadenaletras<<endl;
    cout<<cadenanum<<endl;
}

//Ejercicio 9
void separarCadena(int contador, int numero, int matriz[], int cifras){
    bool bandera = false;
    int aux = 0,suma = 0;

    while(bandera == false){
        if(contador % cifras == 0) bandera = true;
        else{
            contador++;
        }
    }

    cout<<"Original: "<<numero<<endl;
    cout<<"Modificada: ";

    for(int i = contador; i > 0; i--){//Ingresa los numero en el arreglo desde la ultima posicion hasta la primero
        matriz[i-1] = numero % 10;
        numero /= 10;
    }

    for (int i = 0; i < contador; i++) {//Imprime la modificada
        cout<<matriz[i];
    }

    for(int i = 0; i < contador; i += cifras){
        for(int j = i; j < cifras + i; j++){
            aux = aux * 10 + matriz[j];
        }
        suma += aux;
        aux = 0;
    }
    cout<<endl<<"Suma: "<<suma<<endl;
}

//Ejercicio 10
void romToarab (char numero[], int size){
    int valor = 0;
    for(int i = 0; i<size+1; i++){
        switch(numero[i]){
            case 'M':{
                valor += 1000;
                break;
            }
            case 'D':{
                if(numero[i+1] != 'M') valor += 500;
                else valor -= 500;
                break;
            }
            case 'C':{
                if(numero[i+1] != 'M' && numero[i+1] != 'D') valor += 100;
                else valor -= 100;
                break;
            }
            case 'L':{
                if(numero[i+1] != 'M' && numero[i+1] != 'D' && numero[i+1] != 'C') valor += 50;
                else valor -= 50;
                break;
            }
            case 'X':{
                if(numero[i+1] != 'I' && numero[i+1] != 'V' && numero[i+1] != 'X' && numero[i+1] != '\0' ) valor -= 10;
                else valor += 10;
                break;
            }
            case 'V':{
                if(numero[i+1] != 'I' && numero[i+1] != 'V' && numero[i+1] != '\0') valor -= 5;
                else valor += 5;
                break;
            }
            case 'I':{
                if(numero[i+1] != 'I') valor -= 1;
                else valor += 1;
                break;
            }
        }
    }
    cout<<"El numero ingresado fue: "<<numero<<" Que corresponde a: "<<valor;

}

//Ejercicio 11
void menu(char matriz[15][20], int opcion){

    int reservar,fila,columna;

    switch(opcion){
        case 1:{
            cout<<"Cuentos asientos desea reservar: ";cin>>reservar;
            while(reservar > 0){
                cout<<"Filas 1->15, columnas 1->20"<<endl;
                cout<<"Cual asiento desea reservar: "<<endl;
                cout<<"Fila: ";cin>>fila;
                cout<<"Columna: ";cin>>columna;
                reservar --;
                matriz[fila-1][columna-1] = '+';
            }
            break;
        }

        case 2:{
            cout<<"Cuentos asientos desea cancelar: ";cin>>reservar;
            while(reservar > 0){
                cout<<"Filas 1->15, columnas 1->20"<<endl;
                cout<<"Cual asiento desea cancelar: "<<endl;
                cout<<"Fila: ";cin>>fila;
                cout<<"Columna: ";cin>>columna;
                reservar --;
                matriz[fila-1][columna-1] = '-';
            }
            break;
        }

        case 3:{
            for(int i = 0; i < 15; i++){
                for(int j = 0; j < 20; j++){
                    cout << matriz[i][j] << " ";
                }
                cout<<endl;
            }
            break;
        }
    }
}
