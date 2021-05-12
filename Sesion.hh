/** @file Sesion.hh
 * @brief Especificacion de sesion
 */

#ifndef _SESION_HH
#define _SESION_HH

#ifndef NO_DIAGRAM
#include <string>
#include <list>
#endif

#include "BinTree.hh"

/** @class Sesion
 *  @brief
 *
 */

class Sesion {

private:

    string identificador;
    BinTree<string> prerequisitos;

    /** @brief Lectura de un arbol binario de strings.  Los elementos
 se introducen en preordren: primero la raiz, despues el subarbol
 izquierdo i por ultimo el derecho. Los arbres vacios se
 representan con un 0.

      \pre a esta vacio; el canal estandard de entrada contiene el recorrido en preordren
   de un arbol binario A de enteros
      \post a = A
    */
    void leer_arbol(BinTree<string>& a);

    std::list<std::string> recorrer_arbol(const BinTree<string>& a);



public:

    /** @brief Creadora por defecto.

      Se ejecuta automáticamente al declarar un probelma.
      \pre id > 0
      \post El resultado es un problema con identificador "id"
    */
    Sesion();

    /** @brief Creadora por defecto.

      Se ejecuta automáticamente al declarar un probelma.
      \pre id > 0
      \post El resultado es un problema con identificador "id"
    */
    Sesion(string id);

    //Destructora

    /** @brief Destructora por defecto.

      Se ejecuta automáticamente al destruir un problema.
      \pre id > 0
      \post El problema ya no existe
    */
    ~Sesion();

     /** @brief Lectura de un arbol binario de strings.  Los elementos
 se introducen en preordren: primero la raiz, despues el subarbol
 izquierdo i por ultimo el derecho. Los arbres vacios se
 representan con un 0.

      \pre a esta vacio; el canal estandard de entrada contiene el recorrido en preordren
   de un arbol binario A de enteros
      \post el parametro implicito es igual a c
    */
    void construir_arbol();

    string leer_primer_problema();

    std::list<std::string> consultar_problemas();

    void escribir_sesion();

    void escribir_arbol(const BinTree<string>& a);

};
#endif
