///   216623393 LUEVANO MARTINEZ STEVEN
///   219296202 RAMIREZ JUAREZ ANA LIDIA
///   216850837 TORIBIO TORRES MARIFER

///   MATERIA: ESTRUCTURAS DE DATOS 2
///   SECCION: D08

///   PROFESOR: GRACIELA LARA LOPEZ

#ifndef DISPERSIONENARCHIVO_H_INCLUDED
#define DISPERSIONENARCHIVO_H_INCLUDED

#include "arreglo.h"
#include "frecuencias.h"
#include "propietario.h"

class DispersionEnArchivo{
        private:
                /**Arreglo que contiene la informacion de cada campo de los registros y su direccion base**/
                Arreglo <Propietario> arregloPropietario;
                /**Arreglo que contiene direcciones base y sus frecuencias**/
                Arreglo <Frecuencias> arregloFrecuencias;

                int ejecutarFuncionDispersion(std::string);
                void insertarFrecuencia(int, int);
                void acomodarRegistrosDirBaseArchivo();
                void escribirFrecuenciasArchivo();

        public:
                void leerArchivoPro();
                void mostrarResultado();
                //Agregar funcion para mostrar Frecuencias_Lidia
                void mostrarFrecuencias();
};

#endif // DISPERSIONENARCHIVO_H_INCLUDED
