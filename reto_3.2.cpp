#include <iostream>
#include <random>
#include <cctype>
using namespace std;
int main(){
    bool cara = false;
    char eleccionUser;
    bool caraUser = false;
    int random = 0;
    cout << "Hola! Muchas gracias por elegirnos.";
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> distrib(1,2);
    random = distrib(gen);
    if (random == 1){
        cara = true;
    }
    cout << "------- \033[1;32mCARA \033[34m0 \033[32mSELLO\033[0m-------" << endl;
    cout << "Bienvenido a CARA O SELLO, porfavor digita \"c\" para elegir cara o \"s\" para elegir sello: ";
    cin >> eleccionUser;
        for (char &c : eleccionUser){
            c = tolower(c);
        }
    if (cin.fail()){
        cin.clear();
        cin.ignore(1000, '\n');
    }
    if (eleccionUser == 'c'){
        caraUser = true;
    } 
    if (caraUser == cara){
        cout << "\033[32mFELICIDADES! Has ganado." << endl;
    } else{
        cout << "\033[31mHas perdido :(" << endl;
    }
    if(caraUser){
        cout << "Tu elección: CARA" << endl;
    }else{
        cout << "Tu elección: SELLO" << endl;
    }
    if(cara){
        cout << "Moneda: CARA" << endl;
    }else{
        cout << "Moneda: SELLO" << endl;
    }
    return 0;
}