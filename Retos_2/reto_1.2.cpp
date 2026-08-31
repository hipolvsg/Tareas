#include <iostream>
using namespace std;
int main(){
    int faren, cent = 0;
    cout << "Hola! Muchas gracias por elegirnos." << endl;
    cout << "Por favor digite la temperatura en grados farenheit: ";
    cin >> faren;
    cent = (faren-32)/1.8;
    cout << "La temperatura que ingresó es: " << cent << "C°";
    
    return 0;
}