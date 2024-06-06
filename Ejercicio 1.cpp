//Ejercicio 1
#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char enfermedades[10][20] = {"gripe", "indigestion", "catarro", "bronquitis", "alergia", "migraña", "gastritis", "amigdalitis", "sinusitis", "COVID-19"};
    string sintomas[10] = {"fiebre", "tos", "dolor de cabeza", "nausea", "dolor de garganta", "congestion", "dificultad para respirar", "fatiga", "dolor muscular", "perdida de apetito"};
    bool sintomatologias[10][10] = {
        {1, 1, 1, 0, 1, 0, 0, 1, 0, 0},// gripe
        {0, 0, 1, 1, 0, 0, 0, 1, 1, 0},// indigestion
        {0, 1, 1, 0, 1, 1, 0, 1, 0, 0},// catarro
        {1, 1, 0, 0, 1, 1, 1, 1, 0, 0},//bronquitis
        {0, 1, 1, 0, 1, 1, 0, 1, 0, 1},//alergia
		{0, 0, 1, 1, 0, 1, 0, 1, 0, 0},//migraña
		{1, 0, 1, 1, 0, 1, 0, 1, 1, 0},//gastritis
		{0, 1, 1, 0, 1, 1, 0, 1, 0, 1},//amigdalitis
		{0, 1, 1, 0, 1, 1, 0, 1, 0, 0},//sinusitis
		{1, 1, 1, 0, 1, 1, 1, 1, 1, 1},//COVID
    };

    bool sintomas_persona[10];
    cout << "Escriba lo conveniente segun sus sintomas (1 = presento este sintoma, 0 = no presento este sintoma):" << endl;
    for (int i = 0; i < 10; ++i) {
        cout << sintomas[i] << ": ";
        cin >> sintomas_persona[i];
    }

    bool encontrado;
    for (int i = 0; i < 10; ++i) {
        encontrado = true;
        for (int j = 0; j < 10; ++j) {
            if (sintomas_persona[j] != sintomatologias[i][j]) {
                encontrado = false;
                break;
            }
        }
        if (encontrado) { 
            cout << "Usted puede haberse enfermado por: " << enfermedades[i] << ",vaya al centro de salud más cercano"<<endl;
            return 0;
        }
    }

    cout << "No podria decirle, vaya con un doctor de INMEDIATO." << endl;
    return 0;
}



