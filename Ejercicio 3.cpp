//Ejercicio 3
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Alumno {
    string codigo;
    string nombre;
    double notas[3];
};

double calProm(const Alumno& alumno) {
    double sumaNotas = 0.0;
    for (int i = 0; i < 3; ++i) {
        sumaNotas += alumno.notas[i];
    }
    return sumaNotas / 3.0;
}

int main() {
    vector<Alumno> listaAlumnos;

    while (true) {
        cout << "Menu" << endl;
        cout << "1. Registrar datos de un alumno" << endl;
        cout << "2. Mostrar el promedio" << endl;
        cout << "3. Cantidad de desaprobados" << endl;
        cout << "0. Salir" << endl;

        int opcion;
        cin >> opcion;

        if (opcion == 0) {
            break;
        } else if (opcion == 1) {
            Alumno nuevoAlumno;
            cout << "Ingrese codigo: ";
            cin >> nuevoAlumno.codigo;
            cout << "Ingrese nombre: ";
            cin.ignore(); // Limpiar el buffer
            getline(cin, nuevoAlumno.nombre);
            cout << "Ingrese notas de los tres cursos:" << endl;
            for (int i = 0; i < 3; ++i) {
                cin >> nuevoAlumno.notas[i];
            }
            listaAlumnos.push_back(nuevoAlumno);
        } else if (opcion == 2) {
            cout << "\nPromedios de los estudiantes:\n";
            for (int i = 0; i < listaAlumnos.size(); ++i) {
                cout << "Codigo: " << listaAlumnos[i].codigo << ", Nombre: " << listaAlumnos[i].nombre
                     << ", Promedio: " << calProm(listaAlumnos[i]) << endl;
            }
        } else if (opcion == 3) {
    		int desaprobados = 0;
  			for (int i = 0; i < listaAlumnos.size(); ++i) {
 		       if (calProm(listaAlumnos[i]) < 11.0) {  // Cambio aquí: 11 en lugar de 60
            desaprobados++;
        }
    }
    cout << "\nCantidad de estudiantes desaprobados con promedio menor a 11: " << desaprobados << endl;
}

    }

    return 0;
}


    
