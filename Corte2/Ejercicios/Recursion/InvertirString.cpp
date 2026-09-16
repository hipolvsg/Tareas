#include <iostream>
#include <string>
using namespace std;

string invertirString(string str, string newstring = "") {
    //caso base 
    if (str.empty() && newstring.empty()) {
        return newstring;
    }
    //caso recursivo
    if (str.empty()){
        return newstring;
    }
    newstring.push_back(str[str.size() - 1]);
    str.pop_back();
    return invertirString(str, newstring);
}
int main(){
    string str = "hola mundo";
    string resultado = invertirString(str);
    cout << "El string invertido es: " << resultado << endl;
}