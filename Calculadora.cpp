#include <iostream>
#include <cmath>

using namespace std;

int main(){
    float num1, num2, suma, resta, prod, div, sqr, pot = 0;
    cout << "Gracias por preferirnos.";
    cout << "----\033[1mCALCULADORA\033[0m----"<< endl;
    cout << "Los dos numeros que digite, seran operados en suma, resta, multiplicacion, division, raiz cuadrada y potenciacion." << endl;
    cout << "Por favor digite el primer numero: ";
    cin >> num1;
    cout << "Por favor digite el segundo numero: ";
    cin >> num2;
    suma = num1 + num2;
    resta = num1 - num2;
    prod = num1 * num2;
    div = num1 / num2;
    sqr = pow(num1, (1.0/num2));
    pot = pow(num1, num2);
    cout << "El resultado de:" << endl;
    cout << num1 << " + " << num2 << " = " << suma << endl;
    cout << num1 << " - " << num2 << " = " << resta << endl;
    cout << num1 << " * " << num2 << " = " << prod << endl;
    cout << num1 << " / " << num2 << " = " << div << endl;
    cout << num2 << "th root of " << num1 << " = " << sqr << endl;
    cout << num1 << " ^ " << num2 << " = " << pot << endl;
    return 0;
}