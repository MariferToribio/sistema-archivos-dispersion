///   216623393 LUEVANO MARTINEZ STEVEN
///   219296202 RAMIREZ JUAREZ ANA LIDIA
///   216850837 TORIBIO TORRES MARIFER

///   MATERIA: ESTRUCTURAS DE DATOS 2
///   SECCION: D08

///   PROFESOR: GRACIELA LARA LOPEZ

#include <cstring>

#include "propietario.h"

const char* Propietario::getPlaca() const{
        return &placa[0];
}

void Propietario::setPlaca(const char cadena[]){
        strcpy(placa, cadena);
}

const char* Propietario::getNombre() const{
        return &nombre[0];
}

void Propietario::setNombre(const char cadena[]){
        strcpy(nombre, cadena);
}

const char* Propietario::getDomicilio() const{
        return &domicilio[0];
}

void Propietario::setDomicilio(const char cadena[]){
        strcpy(domicilio, cadena);
}

const char* Propietario::getProvincia() const{
        return &provincia[0];
}

void Propietario::setProvincia(const char cadena[]){
        strcpy(provincia, cadena);
}

int Propietario::getDireccionBase() const{
        return direccionBase;
}

void Propietario::setDireccionBase(const int &valor){
        direccionBase = valor;
}
