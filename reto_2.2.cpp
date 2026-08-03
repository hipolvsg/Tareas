#include <iostream>
using namespace std;
int main(){
    float dosisVacuna, pesoBb, mesesBb = 0;
    cout << "Hola! Muchas gracias por elegirnos." << endl;
    cout << "Por favor digite el peso en kg del bebé: ";
    cin >> pesoBb;
    cout << "Por favor digite la edad del bebé en meses: ";
    cin >> mesesBb;
    dosisVacuna = (((pesoBb + 10)/(mesesBb * 10)) * 8);
    cout << "La dosis de la vacuna es de " << dosisVacuna << "u.";
    return 0;
}