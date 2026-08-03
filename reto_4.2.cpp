#include <iostream>
#include <random>
#include <string>
#include <cctype>
using namespace std;
int juego(){
    string eleccionpc, eleccionUser;
    int random = 0;
    char continuar;
    bool error = true;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> distrib(1,3);
    random = distrib(gen);
    if (random == 1){
        eleccionpc = "piedra";
    }else if (random == 2){
        eleccionpc = "papel";
    }else{
        eleccionpc = "tijera";
    }
    cout << "------- \033[1;32mPIEDRA\033[0m, \033[1;32mPAPEL \033[34m0 \033[1;32mTIJERA\033[0m-------" << endl;
    cout << "Bienvenido a PIEDRA, PAPEL O TIJERA."<< endl;
    while (error){
        cout << "Por favor digita \"piedra\" para elegir piedra, \"papel\" para elegir papel o \"tijera\" para elegir tijera: ";
        cin >> eleccionUser;
        for (char &c : eleccionUser){
            c = tolower(c);
        }
        if (cin.fail()){
            cin.clear();
            cin.ignore(1000, '\n');
        }
        if (eleccionUser != "piedra" && eleccionUser != "papel" && eleccionUser != "tijera"){
            cout << "Error, digite bien su opción";
        } else {
            error = false;
        }
    }
    if (eleccionpc == eleccionUser){
        cout << "CERCA! es un empate,puedes seguir intentando." << endl;
        cout << "Te gustaría continuar? (y) si, (n) no";
        cin >> continuar;
        continuar = tolower(continuar);
        if (cin.fail()){
            cin.clear();
            cin.ignore(1000, '\n');
        }
        if (continuar == 'n'){
            return 0;
        } else {
            juego();
        }
    } else if(eleccionpc == "papel"){
        if (eleccionUser == "piedra"){
            cout << "\033[31mHas perdido :(" << endl;
        } else if (eleccionUser == "tijera"){
            cout << "\033[32mFELICIDADES! Has ganado." << endl;
        } else {
            cout << "error, elección inválida." << endl;
            juego();
        }
    } else if(eleccionpc == "piedra"){
        if (eleccionUser == "tijera"){
            cout << "\033[31mHas perdido :(" << endl;
        } else if(eleccionUser == "papel"){
            cout << "\033[32mFELICIDADES! Has ganado." << endl;
        } else{
            cout << "error, elección inválida." << endl;
            juego();
        }
    } else{
        if (eleccionUser == "papel"){
            cout << "\033[31mHas perdido :(" << endl;
        } else if (eleccionUser == "piedra"){
            cout << "\033[32mFELICIDADES! Has ganado." << endl;
        } else {
            cout << "error, elección inválida." << endl;
            juego();
        }
    }
        cout << "Tu elección: " << eleccionUser << endl;
        cout << "Elección pc: " << eleccionpc << endl;
    return 0;
}
int main(){
    cout << "Hola! Muchas gracias por elegirnos.";
    juego();
    return 0;
}