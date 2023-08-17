///   216623393 LUEVANO MARTINEZ STEVEN
///   219296202 RAMIREZ JUAREZ ANA LIDIA
///   216850837 TORIBIO TORRES MARIFER

///   MATERIA: ESTRUCTURAS DE DATOS 2
///   SECCION: D08

///   PROFESOR: GRACIELA LARA LOPEZ

#ifndef PROPIETARIO_H_INCLUDED
#define PROPIETARIO_H_INCLUDED

class Propietario{
        private:
                /**Atributos que contienen los datos del propietario o la informacion de los campos del registro**/
                char placa[9];
                char nombre[30];
                char domicilio[20];
                char provincia[20];
                /**Atributo que contiene la direccion base que se genero a partir de la placa*/
                int direccionBase;

        public:
                /**Setters y Getters de Atributos**/
                const char* getPlaca() const;
                void setPlaca(const char[]);

                const char* getNombre() const;
                void setNombre(const char[]);

                const char* getDomicilio() const;
                void setDomicilio(const char[]);

                const char* getProvincia() const;
                void setProvincia(const char[]);

                int getDireccionBase() const;
                void setDireccionBase(const int&);

                /**Sobrecarga de operadores**/
                bool operator < (const Propietario &p) const{
                        return direccionBase <  p.direccionBase;
                }

                bool operator == (const Propietario &p) const{
                        return direccionBase == p.direccionBase;
                }

};

#endif // PROPIETARIO_H_INCLUDED
