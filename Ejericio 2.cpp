//Ejercicio 2
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Alumno {
    string codigo;
    string nombre;
    char genero;
    int edad;
    double notas[3];
};

double hallarPromedio(const Alumno& alumno) {
    double sumaNotas = 0.0;
    for (int i = 0; i < 3; ++i) {
        sumaNotas += alumno.notas[i];
    }
    return sumaNotas / 3.0;
}

int main() {
    vector<Alumno> listaAlumnos;

    while (true) {
        cout << "Menu:" << endl;
        cout << "1. Registrar datos de un alumno" << endl;
        cout << "2. Ver lista de alumnos" << endl;
        cout << "3. Ver notas por asignatura" << endl;
        cout << "4. Calcular promedio de notas" << endl;
        cout << "5. Mostrar primer y ultimo alumno" << endl;
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
            cin >> nuevoAlumno.nombre;
            cout << "Ingrese genero (M/F): ";
            cin >> nuevoAlumno.genero;
            cout << "Ingrese edad: ";
            cin >> nuevoAlumno.edad;
            cout << "Ingrese notas de los tres cursos:" << endl;
            for (int i = 0; i < 3; ++i) {
                cin >> nuevoAlumno.notas[i];
            }
            listaAlumnos.push_back(nuevoAlumno);
        } else if (opcion == 2) {
            cout << "Lista de alumnos:" << endl;
            for (size_t i = 0; i < listaAlumnos.size(); ++i) {
                cout << listaAlumnos[i].nombre <<","<< listaAlumnos[i].codigo << endl;
            }
        } else if (opcion == 3) {
            cout << "Ingrese codigo o nombre del alumno: ";
            string consulta;
            cin >> consulta;
            bool encontrado = false;
            for (size_t i = 0; i < listaAlumnos.size(); ++i) {
                if (listaAlumnos[i].codigo == consulta || listaAlumnos[i].nombre == consulta) {
                    cout << "Notas de " << listaAlumnos[i].nombre << ":" << endl;
                    for (int j = 0; j < 3; ++j) {
                        cout << "Curso " << j + 1 << ": " << listaAlumnos[i].notas[j] << endl;
                    }
                    encontrado = true;
                    break;
                }
            }
            if (!encontrado) {
                cout << "Alumno no encontrado." << endl;
            }
        } else if (opcion == 4) {
            cout << "Ingrese codigo o nombre del alumno: ";
            string consulta;
            cin >> consulta;
            bool encontrado = false;
            for (size_t i = 0; i < listaAlumnos.size(); ++i) {
                if (listaAlumnos[i].codigo == consulta || listaAlumnos[i].nombre == consulta) {
                    cout << "Promedio de notas de " << listaAlumnos[i].nombre << ": " << hallarPromedio(listaAlumnos[i]) << endl;
                    encontrado = true;
                    break;
                }
            }
            if (!encontrado) {
                cout << "Alumno no registrado, comuniquese con la central" << endl;
            }
        } else if (opcion == 5) {
            if (!listaAlumnos.empty()) {
                cout << "Primer alumno: " << listaAlumnos.front().nombre << endl;
                cout << "Ultimo alumno: " << listaAlumnos.back().nombre << endl;
            } else {
                cout << "No hay alumnos registrados" << endl;
            }
        } else {
            cout << "No puedes hacer eso, intenta otra cosa" << endl;
        }
    }

    return 0;
}

