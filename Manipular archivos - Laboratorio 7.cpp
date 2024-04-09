#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

//Para empezar este programa necesitamos definir la clase persona, que tenga atributos como nombre, edad, y ocupaci�n.
class Persona {
protected:
    string nombre;
    int edad;
    string ocupacion;
//luego de que el usuario ingrese los datos, estos se devuelven con un return, y son asignados a las variables correspondietes
public:

    Persona(string _nombre, int _edad, string _ocupacion) : nombre(_nombre), edad(_edad), ocupacion(_ocupacion) {}

    string getNombre() const {
        return nombre;
    }

    int getEdad() const {
        return edad;
    }

    string getOcupacion() const {
        return ocupacion;
    }

// con esto se muestra la informaci�n dentro del progama 
    virtual void mostrarInfo() const {
        cout << "Nombre: " << nombre << endl;
        cout << "Edad: " << edad << endl;
        cout << "Ocupaci�n: " << ocupacion << endl;
    }
};

//Luego definimos la clase estudiante
class Estudiante : public Persona {
private:
    int numeroEstudiante;
    float promedioCalificaciones;

public:
   //el constructor de estudiante est� formado por todos los datos de la clase heredada de persona.
    Estudiante(string _nombre, int _edad, string _ocupacion, int _numeroEstudiante, float _promedioCalificaciones) : 
        Persona(_nombre, _edad, _ocupacion), numeroEstudiante(_numeroEstudiante), promedioCalificaciones(_promedioCalificaciones) {}

    // estos son los m�todos para establecer los valores de los atributos espec�ficos de los estudiantes
    void setNumeroEstudiante(int _numeroEstudiante) {
        numeroEstudiante = _numeroEstudiante;
    }

    void setPromedioCalificaciones(float _promedioCalificaciones) {
        promedioCalificaciones = _promedioCalificaciones;
    }

    int getNumeroEstudiante() const {
        return numeroEstudiante;
    }

    float getPromedioCalificaciones() const {
        return promedioCalificaciones;
    }

// se muestra la informaci�n dentro del programa.
    void mostrarInfo() const override {
        Persona::mostrarInfo();
        cout << "N�mero de estudiante: " << numeroEstudiante << endl;
        cout << "Promedio de calificaciones: " << promedioCalificaciones << endl;
    }
};

// se ingresan los datos al archivo de texto gracias a fstream, se a�adio un extra que es fecha de cumplea�os
void ingresarDatos(ofstream &archivo) {
    string nombre, fechaCumple;
    int edad;

    cout << "Ingrese el nombre (o escriba 'fin' para terminar): ";
    cin >> nombre;
// para ejecutar el fin de los datos se coloca la palabra "fin" y se cierra el programa
// de lo contrario se pueden ingresar cuantos datos quieran.
    while (nombre != "fin") {
        cout << "Ingrese la edad de " << nombre << ": ";
        cin >> edad;
        cout << "Ingrese la fecha de cumplea�os de " << nombre << " (dd/mm/yyyy): ";
        cin >> fechaCumple;

        archivo << nombre << " " << edad << " " << fechaCumple << endl;

        cout << "Ingrese el nombre (o escriba 'fin' para terminar): ";
        cin >> nombre;
    }
}

// Esta funcion de entrada nos ayuda a mostrar los datos en el archivo de texto.
void mostrarDatos(ifstream &archivo) {
    string nombre, fechaCumple;
    int edad;

    cout << "Datos almacenados en el archivo:" << endl;
    while (archivo >> nombre >> edad >> fechaCumple) {
        cout << "Nombre: " << nombre << ", Edad: " << edad << ", Fecha de Cumplea�os: " << fechaCumple << endl;
    }
}

// La funci�n principal nos ayuda a asignar los datos al archivo con el nombre de datos.txt
int main() {
    // se crea dicho archivo
    ofstream archivoSalida("datos.txt");

    // Verificaci�n de si el archivo se ha abierto correctamente
    if (!archivoSalida) {
        cerr << "Error al abrir el archivo." << endl;
        return 1;
    }

    // Llamada a la funci�n para ingresar datos
    ingresarDatos(archivoSalida);

    // Se cierra el archivo.
    archivoSalida.close();

    // Apertura del archivo para lectura
    ifstream archivoEntrada("datos.txt");

    // Se verifica si el archivo est� abierto correctamente.
    if (!archivoEntrada) {
        cerr << "Error al abrir el archivo." << endl;
        return 1;
    }

    // se muestran los datos
    mostrarDatos(archivoEntrada);

    // Cierre del archivo
    archivoEntrada.close();

    // Uso de la clase Estudiante
    string nombre;
    int edad;
    string ocupacion;
    int numeroEstudiante;
    float promedioCalificaciones;

    cout << "\nIngrese los datos del estudiante:" << endl;
    cout << "Nombre: ";
    cin >> nombre;
    cout << "Edad: ";
    cin >> edad;
    cout << "Ocupaci�n: ";
    cin >> ocupacion;
    cout << "N�mero de estudiante: ";
    cin >> numeroEstudiante;
    cout << "Promedio de calificaciones: ";
    cin >> promedioCalificaciones;

    // Creaci�n de un objeto de la clase Estudiante
    Estudiante estudiante(nombre, edad, ocupacion, numeroEstudiante, promedioCalificaciones);

    // Mostrar la informaci�n del estudiante
    cout << "\nInformaci�n del estudiante:" << endl;
    estudiante.mostrarInfo();

    return 0;
}


