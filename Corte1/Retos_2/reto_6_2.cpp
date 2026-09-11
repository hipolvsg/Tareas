/*Una tienda necesita un programa que calcule el valor a pagar por la compra de
varios productos.
El programa debe:
Solicitar al usuario cuántos productos va a comprar.
Utilizar un ciclo para registrar cada producto:
Nombre del producto.
Precio unitario.
Cantidad comprada.
Calcular el subtotal de cada producto.
Acumular el valor total de la compra.
Al finalizar:Si el total supera los $300.000, aplicar un descuento del 10%.Si el total
está entre $150.000 y $300.000, aplicar un descuento del 5%.
En cualquier otro caso, no aplicar descuento.
Mostrar:
Total antes del descuento.
Descuento aplicado.
Total a pagar.*/

#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

int main(){
    
    int productsQuantity = 0;
    float totalCompra = 0.0;
    int descuento = 0;
    float totalPago = 0.0;
    string tempName;
    int tempCant, tempPrecioU;
    vector<string> productName;
    vector<int> precioUnitario;
    vector<int> cantidadComprada;
    vector<int> subtotalProducto;
    int position = -1;
    bool verif = false;
    //ENTRADA CICLO
    cout << "Digite cúantos productos va a comprar: ";
    cin >> productsQuantity;
    for (; productsQuantity > 0; productsQuantity--){
        //ENTRADA
        cout << "Digite el nombre del producto: ";
        cin >> tempName;
        cout << "Digite el precio del producto: ";
        cin >> tempPrecioU;
        if (cin.fail()){
            cin.clear();
            cin.ignore(1000, '\n');
        }
        cout << "Digite cúanta cantidad de este produtco va a comprar: ";
        cin >> tempCant;
        if (cin.fail()){
            cin.clear();
            cin.ignore(1000, '\n');
        }
        //VOLVER TODO A MINUSCULAS
        for (char &c: tempName){
            c = tolower(c);
        }
        //CALCULO + VERIFICACIÓN REPETIDOS
        for (size_t i = 0; i < cantidadComprada.size(); i++) {
            if (tempName == productName[i] ){
                cantidadComprada[i] = cantidadComprada[i] + tempCant;
                verif = true;
                break;
            }else{
                verif = false;
            }
        }
        //PROCESAMIENTO ENTRADA A UN ARREGLO
        if (!verif){
            productName.push_back(tempName);
            precioUnitario.push_back(tempPrecioU);
            cantidadComprada.push_back(tempCant);
        }
        verif = false;
        tempName = "";
        tempPrecioU = 0;
        tempCant = 0;
    }
    //CALCULO SUBTOTAL PRODUCTO Y SALIDA
    for(string producto : productName){
        position++;
        subtotalProducto.push_back((precioUnitario[position])*(cantidadComprada[position]));
        cout << "Subtotal " << productName[position] << ": $" << subtotalProducto[position] << "." <<endl;
    }
    //ERROR NO COMPRA
    if (productName.empty()) {
        cout << "El carrito de compras está vacío." << endl;
        cout << "El valor total de los elementos registrados es de: " << totalCompra << ", usted obtuvo un descuento del \033[1;93m" << descuento <<"%\033[0m\nPor lo que su total a pagar será de: \033[1m" << totalPago << "!!\033[0m" <<endl;
        return 0;
    }
    //CALCULO PRECIO TOTAL
    for (size_t i = 0; i < cantidadComprada.size(); i++){
        totalCompra = totalCompra + (cantidadComprada[i] * precioUnitario[i]);
    }
    //APLICACIÓN RESPECTIVA DESCUENTOS
    if (totalCompra > 300000){
        totalPago = totalCompra * 0.9;
        descuento = 10;
    }else if(totalCompra >= 150000 && totalCompra <=300000){
        totalPago = totalCompra * 0.95;
        descuento = 5;
    }else{
        totalPago = totalCompra;
        descuento = 0;
    }
    //SALIDAS DESCUENTO Y VALORES FINALES
    position = -1;
    cout << "El valor total de los elementos registrados es de: " << totalCompra << ", usted obtuvo un descuento del \033[1;93m" << descuento <<"%\033[0m\nPor lo que su total a pagar será de: \033[1m" << totalPago << "!!\033[0m" <<endl;
    return 0;
}