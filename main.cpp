#include <iostream>
#include <random>
#include "milibreria.h"

using namespace std;

int main()
{
    int opcion=1;
    while (opcion != 0){

            cout <<endl << "MENU" << endl;
            cout << "1. Combinacion de billetes y monedas" << endl;
            cout << "2. Generar numeros aleatorios e imprimir cuanto se repite una letra" << endl;
            cout << "3. Compare 2 cadenas de caracteres" << endl;
            cout << "4. Cadena de caracteres a numero entero" << endl;
            cout << "5. Numero entero a numero cadena de caracteres" << endl;
            cout << "6. Minusculas por mayusculas" << endl;
            cout << "7. Eliminar los caracteres repetidos de una cadena de caracteres" << endl;
            cout << "8. Separar numeros y letras de una cadena" << endl;
            cout << "9. separar la cadena de caracteres en números de n cifras, sumarlos e imprimir el resultado"<<endl;
            cout << "10. Numeros romanos al sistema arabigo"<<endl;
            cout << "11. Reserva de asientos"<<endl;
            cout << "0. Salir" << endl;
            cout << "Ingrese una opcion: ";cin >> opcion;

            switch (opcion) {
            case 1:{
                int valor;
                int valores[] = {50000,20000,10000,5000,2000,1000,500,200,100,50};
                int cantidad[10];
                cout<<"Ingrese un valor: ";cin>>valor;

                for(int i = 0; i<10;i++){
                    cout<<valores[i]<<" pesos: ";
                    cantidad[i] = valor/valores[i];
                    valor %= valores[i];
                    cout<<cantidad[i]<<endl;
                }
                cout<<"Falta: "<<valor<<" pesos"<<endl;;
                break;
            }

            case 2:{
                char arreglo[200];
                random_device rd;
                mt19937 gen(rd());
                uniform_int_distribution<> dis(65, 90);

                for (int i = 0; i < 200; i++) {
                    arreglo[i] = dis(gen);
                  }

                cout << "Letra aleatorias"<<endl;

                for (int i = 0; i < 200; i++) {
                    cout << arreglo[i] << " ";
                  }cout<<endl;

                contarLetras(arreglo);

                break;
            }

            case 3:{
                char letras1[]= "prueba1";
                char letras2[]= "prueba2";
                bool variable = comparar(letras1, letras2);

                if(variable == true)cout<<"Las cadenas de caracteres son iguales"<<endl;
                else cout<<"Las cadenas de caracteres NO son iguales"<<endl;
                break;}

            case 4:{
                char numeros[]="123";
                int num = convertirnum(numeros);
                cout << "Num: " << num << endl;
                break;
            }

            case 5:{
                int numero = 102030, contador= 0,i = numero ;
                while(i != 0){
                    i = i/10;
                    contador++;
                }
                char num[contador];
                convertirchar(numero, num);
                cout << num << endl;
                break;
            }

            case 6:{
                char caracteres[30];
                cin.ignore();
                cout<<"Ingrese la palabra: ";
                cin.getline(caracteres, 30, '\n');

                MintoMay(caracteres);

                int i = 0;
                while(caracteres[i] != '\0'){
                    cout<<caracteres[i];
                    i++;
                }
                cout<<endl;
                break;
            }

            case 7:{
                char cadena[30];
                cin.ignore();
                cout<<"Ingrese la palabra: ";
                cin.getline(cadena, 30, '\n');

                cout << "Original: " << cadena << ". ";
                eliminarrep(cadena);
                cout<<"Sin repetidos: "<<cadena<<endl;
                break;
            }

            case 8:{
                char cadena[30];
                cin.ignore();
                cout<<"Ingrese la palabra: ";
                cin.getline(cadena, 30, '\n');

                separar(cadena);
                break;
            }

            case 9:{
                int numeros,contador,aux,cifras;
                cout<<"Ingrese un numero: ";cin>>numeros;
                cout<<"Ingrese la cantidad de cifras que lo desea separar: ";cin>>cifras;
                aux = numeros;

                for(contador = 0; aux != 0; contador++ ){//Cuanto las cifras del numero
                        aux /= 10;
                }

                int matriz[contador];
                separarCadena(contador, numeros, matriz, cifras);

                break;
            }

            case 10:{
                char numero[30];
                int size;
                cin.ignore();
                cout <<"Digite un numero romano: ";
                cin.getline(numero, 30, '\n');

                for(int i = 0; numero[i] != '\0'; i++){
                    size = i;
                }
                romToarab(numero, size);
                break;
            }

            case 11:{
                char matriz[15][20] = {};
                int opcion = 1;

                for(int i = 0; i < 15; i++) {//Asigno todos los asientes con '-'
                    for(int j = 0; j < 20; j++) {
                        matriz[i][j] = '-';
                    }
                }

                while(opcion != 0){
                    cout<<endl;
                    cout<<"1. Reservar"<<endl;
                    cout<<"2. Cancelaciones"<<endl;
                    cout<<"3. Asientos disponibles y reservados"<<endl;
                    cout<<"0. Salir"<<endl;
                    cout<<"Elija: ";cin>>opcion;

                    menu(matriz, opcion);
                }

            break;
            }

            case 0 :
                opcion = 0;
                break;
            }
    }
    return 0;
}



