/** @file Sesion.hh
 * @brief Especificacion de sesion
 */

#ifndef _SESION_HH
#define _SESION_HH

#ifndef NO_DIAGRAM
#include <string>
#include <vector>
#include <map>
#endif

#include "BinTree.hh"

/** @class Sesion
 *  @brief Representa una sesion de la plataforma con un arbol binario indicando los pre requisitos para poder realizar un
 * envio a un problema, un mapa con todos los problemas y un identificador unico
 *
 */

class Sesion {

private:

    string identificador;
    BinTree<string> prerequisitos;
    std::vector<string> problemas;
    std::map <string, std::pair<string, string> > problemas_ordenados;

    /** @brief Lectura de un arbol binario de enteros.  Los elementos
 se introducen en preordren: primero la raiz, despues el subarbol
 izquierdo i por ultimo el derecho. Los arbres vacios se
 representan con un 0.
      \pre a esta vacio; el canal estandard de entrada contiene el recorrido en preordren
   de un arbol binario A de enteros
      \post a = A
    */
    void leer_arbol(BinTree<string>& a);

    /** @brief Escritura de un arbol binario de enteros
      \pre el parametro implicito esta inicializado
      \post Escribe los problemas del arbol de enteros en post-orden
    */
    void escribir_arbol(const BinTree<string>& a);



public:

    /** @brief Creadora por defecto.
      Se ejecuta automáticamente al declarar un problema

      \pre <em>cierto</em>
      \post El resultado es una sesion no inicializada, con todos los atributos a 0 y los conjuntos vacios
    */
    Sesion();

    /** @brief Creadora con identificador

      \pre id > 0
      \post El resultado es una sesion con con identificador = "id"
    */
    Sesion(string id);

    //Destructora

    /** @brief Destructora por defecto.

      Se ejecuta automáticamente al destruir un problema.
      \pre id > 0
      \post El problema ya no existe
    */
    ~Sesion();


    //Consultoras

    /** @brief Consultora del primer problema de la sesion

      \pre El parámetro implícito está inicializado
      \post El resultado es el primer problema de la sesion del parámetro implícito 
    */
    std::string leer_primer_problema();

    /** @brief Consultora del problema hijo de un problema

      \pre El parámetro implícito está inicializado, p no es nulo y 0 >= lado <= 1
      \post El resultado es el hijo izquierdo del problema "p" en caso que "lado" = 0 y el hijo derecho del 
      problema "p" en caso que "lado" = 1 
    */
    std::string nuevo_problema(std::string p, int lado);

    /** @brief Consultora del problema i de la sesion

      \pre El parámetro implícito está inicializado y i >= 0
      \post El resultado es el problema i-essimo del vector de problemas del parametro implicito
    */
    std::string consultar_problema(int i);

    /** @brief Consultora del numero de problemas de la sesion

      \pre El parámetro implícito está inicializado
      \post El resultado es el numero de problemas del parámetro implícito 
    */
    int num_problemas();


     /** @brief Lectura de un arbol binario de enteros.  Los elementos
 se introducen en preordren: primero la raiz, despues el subarbol
 izquierdo i por ultimo el derecho. Los arbres vacios se
 representan con un 0.
      \pre a esta vacio; el canal estandard de entrada contiene el recorrido en preordren
   de un arbol binario A de enteros
      \post el parametro implicito es igual a c
    */
    void construir_arbol();

    /** @brief Operación de escritura

      \pre El parámetro implícito está inicializado
      \post Escribe las propiedades y el contenido del parámetro implícito por el canal estándar de salida 
    */
    void escribir_sesion();

    

    

    


};
#endif
