/*En Supermercados Noé estamos de aniversario y te obsequiamos un
descuento en el valor de tu compra, si ésta es mayor a 50.000 y
dependiendo de tu suerte:
❑ Si sacas la bolita roja obtienes 10% en el valor de tu compra
❑ Si sacas la bolita azul obtienes un 30% en el valor de tu compra
❑ Si sacas la bolita amarilla obtienes un 50% en el valor de tu compra
❑ Si sacas la bolita blanca te llevas tu compra gratis
Permítale a un cliente del supermercado Noé saber si su compra ha sido
beneficiada con su promoción de aniversario, indique acorde a la bolita
obtenida de forma aleatoria qué valor de descuento ha ganado y cual sería
su valor final a pagar. */
#include <iostream>
#include <random>
#include <string>

using namespace std;

int main(){
    float totalCompra, valorAPagar = 0;
    int random, descuento = 0;
    bool gratis = false;
    string bolita;
    cout << "Gracias por preferirnos!" << endl;
    //Entrada datos.
    cout << "Porfavor digita el valor total de la compra del cliente: ";
    cin >> totalCompra;
    //Si el valor no es mayor a 50000, evitar consumir recursos.
    if (totalCompra >= 50000){
        //Obtencion número a partir de cualquier elemento de el hardware.
        random_device rd;
        //Genera un número de 32-bits a partir random_device rd;de algoritmos complejos.
        mt19937 gen(rd());
        //Devuelve a partir del número anterior un número entero <int> del 1 al 4 (1, 2, 3, 4).
        uniform_int_distribution<int> distrib(1, 4);
        random = distrib(gen);
        //Aplicación de condiciones al valor random y total de la compra.
        switch ((random)){
            case 1:
                valorAPagar = totalCompra * 0.9 ;
                bolita = "roja";
                descuento = 10;
                break;
            case 2:
                valorAPagar = totalCompra * 0.7;
                bolita = "azul";
                descuento = 30;
                break;
            
            case 3:
                valorAPagar = totalCompra * 0.5;
                bolita = "amarilla";
                descuento = 50;
                break;
            
            case 4:
                valorAPagar = 0;
                bolita = "blanca";
                gratis = true;
                descuento = 100;
                break;
            
            default:
            //En caso de fallo del generador aplica el descuento más bajo.
                valorAPagar = totalCompra * 0.9;
                descuento = 10;
                bolita = "roja";
                break;
            
        }
        //SALIDAS
        cout << "\033[1;92m¡¡En Supermercados Noé estamos de aniversario y te obseqrandomuiamos un \ndescuento en el valor de tu compra, si ésta es mayor a 50.000 y\ndependiendo de tu suerte. \nBUENA SUERTE!!!\033[0m]" << endl;
        cout << "\033[1mHas obtenido la bolita " << bolita << "!\033[0m" <<endl; 
        if (gratis){
        cout << "\033[1;92m\t\t\t¡¡JACKPOT!!\033[0m]" << endl;
        }
        cout << "\t\033[1mObtuviste un \033[93m\t" << descuento << "\%\tde descuento!!\033[0m" << endl;
    } else{
        valorAPagar = totalCompra;
    }
    cout << "El valor total a pagar por tu compra es de: " <<valorAPagar << "." << endl;
    return 0;
}