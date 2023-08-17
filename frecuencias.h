///   216623393 LUEVANO MARTINEZ STEVEN
///   219296202 RAMIREZ JUAREZ ANA LIDIA
///   216850837 TORIBIO TORRES MARIFER

///   MATERIA: ESTRUCTURAS DE DATOS 2
///   SECCION: D08

///   PROFESOR: GRACIELA LARA LOPEZ

#ifndef FRECUENCIAS_H_INCLUDED
#define FRECUENCIAS_H_INCLUDED

class Frecuencias{
        private:
                /**Atributo que contiene una direccion base**/
                int direccionBase;
                /**Atributo que contiene la frecuencia de esta direccion base**/
                int frecuencia;

        public:
                /**Setters y Getters de Atributos**/
                void setDireccionBase(const int&);
                int getDireccionBase() const;

                void setFrecuencia(const int&);
                int getFrecuencia() const;

                /**Sobrecarga de operadores**/
                bool operator < (const Frecuencias &f) const{
                        return direccionBase <  f.direccionBase;
                }

                bool operator == (const Frecuencias &f) const{
                        return direccionBase == f.direccionBase;
                }

                bool operator > (const Frecuencias &f) const{
                        return direccionBase >  f.direccionBase;
                }
};

#endif // FRECUENCIAS_H_INCLUDED
