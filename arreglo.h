///   216623393 LUEVANO MARTINEZ STEVEN
///   219296202 RAMIREZ JUAREZ ANA LIDIA
///   216850837 TORIBIO TORRES MARIFER

///   MATERIA: ESTRUCTURAS DE DATOS 2
///   SECCION: D08

///   PROFESOR: GRACIELA LARA LOPEZ

#ifndef ARREGLO_H_INCLUDED
#define ARREGLO_H_INCLUDED

template <class T,int ARRAYSIZE = 30>
class Arreglo{
        private:
                T arreglo[ARRAYSIZE];
                int ultimo;

        public:
                Arreglo();

                int obtenerUltimaPos();
                void insertarDato(const int&, const T&);
                int buscarDato(T);
                T recuperar(const int&);
                void modificarDato(const int&, const T&);
};

template <class T, int ARRAYSIZE>
Arreglo<T, ARRAYSIZE>::Arreglo(){
        ultimo = -1;
}

/**Metodo que retorna la ultima posicion con datos del arreglo**/
template <class T, int ARRAYSIZE>
int Arreglo<T, ARRAYSIZE>::obtenerUltimaPos(){
        return ultimo+1;
}

/**Metodo que recibe por parametro el dato que se insertara y la posicion del arreglo donde se insertara el dato**/
template <class T, int ARRAYSIZE>
void Arreglo<T, ARRAYSIZE>::insertarDato(const int &i, const T &dato){
        arreglo[i] = dato;
        ultimo++;
}

/**Metodo que recibe por parametro una posicion y un elemento, el cual sera el reemplazo del elemento que se encuentra en esa posicion**/
template <class T, int ARRAYSIZE>
void Arreglo<T, ARRAYSIZE>::modificarDato(const int &i, const T &dato){
        arreglo[i] = dato;
}

/**Metodo que recibe por parametro el dato que se busca en el arreglo y realiza una busqueda lineal**/
template <class T, int ARRAYSIZE>
int Arreglo<T, ARRAYSIZE>::buscarDato(T elemento){
        int i(0);

        while (i <= ultimo){
                if (arreglo[i] == elemento){
                       return i;
                }
              i++;
        }

        return -1;
}

/**Metodo que recibe por parametro una posicion del arreglo y retorna el dato que se encuentra en esa posicion**/
template <class T, int ARRAYSIZE>
T Arreglo<T, ARRAYSIZE>::recuperar(const int &posicion){
        return arreglo[posicion];
}

#endif // ARREGLO_H_INCLUDED
