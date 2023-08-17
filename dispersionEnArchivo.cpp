///   216623393 LUEVANO MARTINEZ STEVEN
///   219296202 RAMIREZ JUAREZ ANA LIDIA
///   216850837 TORIBIO TORRES MARIFER

///   MATERIA: ESTRUCTURAS DE DATOS 2
///   SECCION: D08

///   PROFESOR: GRACIELA LARA LOPEZ

#include <fstream>
#include <cstring>
#include <iostream>

#include "dispersionEnArchivo.h"
#include "frecuencias.h"

#define ArchivoPropietario "AUTOS_PRO.txt" /**Archivo que guarda los 30 registros**/
#define ArchivoDireccionBase "DIRECCION_BASE.txt" /**Archivo que guarda los registros en su correspondiente direccion base**/
#define ArchivoFrecuencias "FRECUENCIAS.txt" /**Archivo que guarda la frecuencia de cada direccion (0-99)**/

#define Barra "|"
#define SaltoLinea "\n"
#define Espacio " "

using namespace std;

/**Metodo que lee el archivo que contiene los 30 registros, llama al metodo encargado de generar una
direccion base de la placa de cada registro y llama a los metodos para escribir en los archivos correspondientes**/
void DispersionEnArchivo::leerArchivoPro(){
        ifstream archivoPro;
        archivoPro.open(ArchivoPropietario, ios::in); /**Abrir el archivo en modo entrada**/

        if(!archivoPro.is_open()){ /**Error al abrir el archivo, mostrar mensaje de error**/
                cout << "No Se Pudo Abrir El Archivo Solicitado" << endl;
        }

        else{
                Propietario propietario; /**Objeto que se insertara, en el caso de ser necesario, en el arreglo que guarda la informacion de los registros y su direccion base**/

                string texto; /**Variable que guarda la informacion de cada campo de un registro cuando se va leyendo del archivo**/

                int campo(1); /**Varible que representa el campo del registro que se esta leyendo del archivo**/
                int dir_base(0); /**Variable para guardar la direccion base que la placa de cada registro genera**/
                int pos(0); /**Variable para guardar lo que retorne el metodo buscarDato de la clase Arreglo al momento de
                realizar una busqueda en el arreglo de frecuencias, y segun sea el valor que retorne, se insertara un elemento en
                el arreglo Propietario**/

                while(!archivoPro.eof()){ /**Mientras no sea fin de archivo**/
                        if(archivoPro.eof()){
                                break;
                        }

                        if(campo < 5 ){ /**Condicional para procurar la lectura de los 4 campos del registro**/
                                getline(archivoPro,texto, '|'); /**Leer hasta encontrar la barra**/
                                if(campo == 1){
                                        propietario.setPlaca(texto.c_str()); /**Guardar en atributo "placa" el campo "placa" del registro que se lee del archivo**/
                                        /**Llamar el metodo para ejecutar la funcion de dispersion y guardar en variable dir_base la direccion que el metodo retorne**/
                                        dir_base = ejecutarFuncionDispersion(texto);

                                        Frecuencias f;
                                        f.setDireccionBase(dir_base);
                                        pos = arregloFrecuencias.buscarDato(f);
                                        /**Buscar en el arreglo que guarda las direcciones base y su respectiva frecuencia, el elemento que tenga la direccion base que se genero antes a partir de
                                        la placa del registro que se esta leyendo del archivo y se guarda en "pos" lo que retorne la busqueda.
                                        En caso de que si se encuentre, en "pos" se guardara la posicion del elemento encontrado en el arreglo.
                                        En el caso de que no se haya encontrado, en "pos" se guardara -1, y esto es importante para el metodo "insertarFrecuencia"**/

                                        insertarFrecuencia(pos, dir_base); /**Llamar el metodo insertarFrecuencia, ya sea para se agregue un nuevo objeto de la clase
                                        Frecuencias (con la correspondiente direccion base y frecuencia de esta) en arreglo de frecuencias o modificar un elemento del arreglo**/

                                        campo++; /**Se debe incrementar para continuar leyendo los demas campos del registro y guardar la informacion en el atributo
                                        correspondiente**/
                                }

                                else if(campo == 2){
                                        propietario.setNombre(texto.c_str()); /**Guardar en atributo "nombre" el campo "nombre" del registro que se lee del archivo**/
                                        campo++;
                                }


                                else if(campo == 3){
                                        propietario.setDomicilio(texto.c_str()); /**Guardar en atributo "domicilio" el campo "domicilio" del registro que se lee del archivo**/
                                        campo++;
                                }

                                else if(campo == 4){
                                        propietario.setProvincia(texto.c_str()); /**Guardar en atributo "provincia" el campo "provincia" del registro que se lee del archivo**/
                                        propietario.setDireccionBase(dir_base); /**Guardar en atributo "direccionBase" la direccion base que se genero previamente de la placa del registro que se lee del archivo**/

                                        if(pos == -1){ /**Si "pos" es igual a -1, significa que no existe en el arreglo de frecuencias, un objeto que tenga en el atributo "direccionBase" esa direccion base,
                                                        lo que quiere decir que ninguna placa de los registros que hasta ahora se han leido del archivo ha generado esa direccion base y tambien que en el arreglo "Propietario" no hay ningun registro
                                                        con esa direccion base. Por lo que, este registro que genero esta direccion base se escribira en el archivo**/

                                                arregloPropietario.insertarDato(arregloPropietario.obtenerUltimaPos(), propietario);
                                                /**Se inserta en el arreglo "Propietario" el objeto con la informacion de cada campo del registro que se leyo antes y la direccion base que se genero a partir de la placa**/
                                        }

                                        campo++;
                                        getline(archivoPro, texto, '\n'); /**Leer el salto de linea que se encuentra al final del registro
                                        en el archivo y asi, poder leer el siguiente registro**/
                                }
                        }

                        if(campo == 5){ /**Para leer el siguiente registro del archivo**/
                               campo = 1;
                        }
                }

                archivoPro.close();

                acomodarRegistrosDirBaseArchivo(); /**Llamar metodo para guardar en un archivo los registros en su direccion base**/
                escribirFrecuenciasArchivo(); /**Llamar metodo para guardar en un archivo la frecuencia de cada direccion**/

                cout << endl << endl;
                cout << " FUNCION EJECUTADA !!" << endl;
        }
        system("pause");
}


/**Metodo que mientras escribe las direcciones (0-99) en el archivo, en el caso de ser necesario,
escribe el registro completo, ya que a partir de la placa del registro dicha direccion se genero**/
void DispersionEnArchivo::acomodarRegistrosDirBaseArchivo(){
        ofstream archivoDir;
        archivoDir.open(ArchivoDireccionBase, ios::out); /**Abrir archivo en modo salida**/

        for(int i = 0; i < 100; i++){ /**Para escribir en el archivo las 100 direcciones (0-99)**/
                Propietario propietario;
                propietario.setDireccionBase(i);
                int pos(arregloPropietario.buscarDato(propietario)); /**Se busca en el arreglo "Propietario" si existe esta direccion (Significa que alguna placa de algun registro genero esta direccion)**/

                if(pos != -1){ /**En el arreglo existe esta direccion**/
                        propietario = arregloPropietario.recuperar(pos);
                        /**Se escribe la direccion y cada campo del registro (registro del cual a partir de su campo "placa" se genero dicha direccion) separado por una barra**/
                        archivoDir << i << Espacio << propietario.getPlaca() << Barra
                                   << propietario.getNombre() << Barra
                                   << propietario.getDomicilio() << Barra
                                   << propietario.getProvincia() << Barra
                                   << SaltoLinea;
                }

                else{ /**Ninguna placa de ningun registro genero esta direccion.Es por ello que solo se escribe la direccion**/
                        archivoDir << i << SaltoLinea;
                }
        }

        archivoDir.close(); /**Cerrar archivo**/
}

/**Metodo que escribe las direcciones (0-99) en el archivo y su frecuencia**/
void DispersionEnArchivo::escribirFrecuenciasArchivo(){
        ofstream archivoFrec;
        archivoFrec.open(ArchivoFrecuencias, ios::out); /**Abrir archivo en modo salida**/

        for(int i = 0; i < 100; i++){ /**Para escribir en el archivo las 100 direcciones (0-99)**/
                Frecuencias f;
                f.setDireccionBase(i);
                int pos(arregloFrecuencias.buscarDato(f)); /**Se busca en el arreglo un objeto que tenga en el atributo "direccionBase" esta direccion**/

                if(i < 10) /**Para procurar que la frecuencia de todas las direcciones aparezcan en una sola columna**/
                        archivoFrec << i << Espacio << Espacio; /**Escribir direccion en el archivo**/

                else
                        archivoFrec << i << Espacio; /**Escribir direccion en el archivo**/

                if(pos != -1){ /**Se encontro un objeto que tiene en el atributo "direccionBase" esta direccion. Es decir, una o mas placas de un registro
                                generaron esta direccion base**/
                        f = arregloFrecuencias.recuperar(pos); /**Recuperar objeto del arreglo**/

                        archivoFrec << "(" << f.getFrecuencia() << ")" << SaltoLinea; /**Escribir en el archivo la frecuencia de la direccion**/
                }

                else{ /**Ninguna placa de ningun registro genero esta direccion. Por lo tanto, su frecuencia es cero**/
                        archivoFrec << "(0)" << SaltoLinea; /**Escribir en el archivo frecuencia de la direccion**/
                }
        }

        archivoFrec.close(); /**Cerrar archivo**/
}

/**Metodo que recibe por parametro la placa y retorna la direccion base que se genero a partir de la placa utilizando
una Funcion de Dispersion**/
int DispersionEnArchivo::ejecutarFuncionDispersion(string placa){
        char caracter;
        int codigo(0);
        int codigos[8];

        /**REPRESENTAR LA LLAVE EN FORMA NUMERICA**/
        /**Recorrer los caracteres de la placa y guardar en un arreglo de enteros el codigo ascii de cada caracter**/
        for(int i = 0; i <= placa.size(); i++){
                caracter = placa[i];   /**Guardar en variable "caracter" el caracter que se esta leyendo de la placa**/
                codigo = caracter; /**Guardar en variable "codigo" el codigo ascii del caracter que esta en variable "caracter"**/

                if(i < placa.size()){
                        codigos[i] = codigo; /**Guardar en el arreglo de enteros "codigos" el codigo ascii del caracter que se esta leyendo de la placa**/
                }
        }

        int suma(0);
        int j(0);
        int num(0);

        /**DESGLOSAR Y SUMAR**/
        while(j < 8){
                num = 100*codigos[j] + codigos[j+1]; /**Se toman dos elementos del arreglo de codigos ascii, se juntan y se guarda en variable "num"**/
                suma = (suma + num)%20000; /**Se realiza una suma entre "suma" y "num" y despues, se guarda en "suma" el residuo de la division del resultado de la suma entre 20000**/
                j = j + 2; /**Se debe incrementar en dos, para leer los siguientes codigos ascii del arreglo**/
        }

        /**DIVIDIR ENTRE UN NUMERO PRIMO Y Y USAR EL RESIDUO COMO DIRECCION**/
        int direccion = suma%101; /**Se guarda en "direccion" el residuo de la division de variable "suma" entre el numero primo 101 y se usa el residuo como
                                    direccion**/

        return direccion; /**Retornar direccion**/
}

/**Metodo que segun sea el valor de la variable "pos" que recibe por parametro, toma la decision de si en el arreglo se inserta un nuevo objeto de clase Frecuencias
con una correspondiente direccion base y su frecuencia o si se modifica la frecuencia de un objeto ya existente**/
void DispersionEnArchivo::insertarFrecuencia(int pos, int dir_base){
        Frecuencias dirBaseFrecuencia;
        dirBaseFrecuencia.setDireccionBase(dir_base);

        if(pos == -1){ /**Se agrega un nuevo objeto en el arreglo con la direccion base que recibio por parametro y con frecuencia 1**/
                dirBaseFrecuencia.setFrecuencia(1);
                arregloFrecuencias.insertarDato(arregloFrecuencias.obtenerUltimaPos(), dirBaseFrecuencia);
        }

        else{ /**Se modifica la frecuencia de un objeto que ya existe en el arreglo (se incrementa la frecuencia)**/
                Frecuencias  f = arregloFrecuencias.recuperar(pos);
                dirBaseFrecuencia.setDireccionBase(dir_base);
                 /**Se recupera el objeto del arreglo y se modifica su frecuencia**/
                dirBaseFrecuencia.setFrecuencia(f.getFrecuencia()+1);
                arregloFrecuencias.modificarDato(pos, dirBaseFrecuencia);
        }
}

void DispersionEnArchivo::mostrarResultado(){
        ifstream Archivo;
        string linea;   //se crea un string que guarde cada linea del archivo
        Archivo.open(ArchivoDireccionBase,ios::in); //abre el archivo
            if (!Archivo.good())    //si el archivo no se abre se detiene la funcion
            {
                cout << "No Se Pudo Abrir El Archivo Solicitado\n ";
                system("Pause");
            }
            else
            {
                system("cls");
                cout << "\n\n          R E S U L T A D O   D E   L A   F U N C I O N   D E   D I S P E R S I O N" << endl;
                cout << " -------------------------------------------------------------------------------------------" << endl << endl;

                while (!Archivo.eof())// mientras el archivo no llegue a su fin
                {

                    if (Archivo.eof()){ //si el archivo llega a su fin se detiene la funcion
                        break;
                    }
                    while(getline (Archivo,linea)){ //obtiene cada linea del archivo y lo guarda en la variable linea

                        cout<< " " << linea<<endl; //imprime la variable linea
                    }
                }
            Archivo.close();    //cierra el archivo
            system("Pause");
    }
}

//agregar la funcion de mostrar Frecuencias
void DispersionEnArchivo::mostrarFrecuencias(){
	//Declaracion de la variable frecuencia
    string frecuencia;
    //Declaracion del archivo
    ifstream frecuencias;
    //Apertura de archivo
	frecuencias.open(ArchivoFrecuencias, ios::in);
	//Validacion del archivo con good()
	if(frecuencias.good()){
                system("cls");
                cout << "\n\n          N U M E R O   D E   F R E C U E N C I A S" << endl;
                cout << " -----------------------------------------------------------" << endl << endl;
		// Lee cada línea
	  	while (getline(frecuencias, frecuencia)) {
	  		//Imprime cada linea
	    cout << " " << frecuencia << "\n";
	  	}
    }else{
    	//muestra un mensaje de error en dado caso que el archivo no se logre abrir
    	cout << "No Se Pudo Abrir El Archivo Solicitado\n ";
        system("Pause");
	}
	//Cerrar el archivo
	frecuencias.close();
    system("Pause");
}
