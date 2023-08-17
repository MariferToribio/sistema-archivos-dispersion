///   216623393 LUEVANO MARTINEZ STEVEN
///   219296202 RAMIREZ JUAREZ ANA LIDIA
///   216850837 TORIBIO TORRES MARIFER

///   MATERIA: ESTRUCTURAS DE DATOS 2
///   SECCION: D08

///   PROFESOR: GRACIELA LARA LOPEZ

#include "frecuencias.h"

void Frecuencias::setDireccionBase(const int &valor){
        direccionBase = valor;
}

int Frecuencias::getDireccionBase() const{
        return direccionBase;
}

void Frecuencias::setFrecuencia(const int &valor){
        frecuencia = valor;
}

int Frecuencias::getFrecuencia() const{
        return frecuencia;
}
