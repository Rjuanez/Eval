/** @file Cjt_sesion.hh
 * @brief Especificacion de un conjunto de sesiones
 */

#ifndef _CJT_SESION_HH
#define _CJT_SESION_HH

#ifndef NO_DIAGRAM
#include <map>
#endif

#include "Sesion.hh"

/** @class Cjt_sesion
 *  @brief Representa un conjunto de sesiones
 *
 */

class Cjt_sesion {

private:
    map <std::string, Sesion> sesiones;
    
    /** @brief Consultora de si existe una sesiones 

      \pre El parámetro implícito está inicializado
      \post El resultado es si existe el objeto "id" en el parametro implicito
    */
    bool existe_sesion (std::string id);

public:

    /** @brief Creadora por defecto.
      Se ejecuta automáticamente al declarar un conjunto de sesiones.

      \pre <em>cierto</em>
      \post El resultado es un conjunto de sesiones vacio
    */
    Cjt_sesion();
    
    /** @brief Destructora por defecto.
      Se ejecuta automáticamente en los objetos locales al salir
      \pre <em>cierto</em>
      \post El resultado es que se elimina el objeto conjunto de sesiones
    */
    ~Cjt_sesion();

    //Modificadoras
    /** @brief Se añade una sesiones con identificador "id"
      \pre id no es nuelo
      \post El resultado es que sse añade una sesion con identificador "id" al parametro implicito
    */
    void anadir_sesion(std::string id);

    //Consultoras

    /** @brief Consultora del numero de sesiones

      \pre El parámetro implícito está inicializado
      \post El resultado es el numero de sesiones que tiene parámetro implícito 
    */
    int num_sesiones();

    /** @brief Consultora del primer problema de la sesion "sesion"

      \pre El parámetro implícito está inicializado
      \post El resultado es el primer problema de la sesion "sesion", en caso de que "sesion" no exista, se
      devuelve error
    */
    std::string listar_primer_problema(std::string sesion);

    /** @brief Consultora del problema hijo de un problema de la sesion "sesione"

      \pre El parámetro implícito está inicializado, p y sesion no son nulos y 0 >= lado <= 1
      \post El resultado es el hijo izquierdo del problema "p"  de la sesion "sesion", en caso que "lado" = 0 y el hijo derecho del 
      problema "p" en caso que "lado" = 1 
    */
    std::string buscar_nuevo_problema(std::string p, std::string sesion, int lado);

    /** @brief Consultora del numero de problemas de una sesion 

      \pre El parámetro implícito está inicializado
      \post El resultado es el numero de problemas de la sesion "sesion", en caso de que "sesion" no exista, se
      devuelve error
    */
    int num_problemas_sesion(std::string sesion);

    /** @brief Consultora del problema i de una sesion 

      \pre El parámetro implícito está inicializado, i >= 0 y sesion no es nuelo
      \post El resultado es el problema i-essimo del vector de problemas de la sesion "sesion", en caso de que "sesion" no exista, se
      devuelve error
    */
    std::string consultar_problema_sesion(string sesion, int i);


    //Lectura y escritura

    /** @brief Añade n sesiones al parametro implicito
        \pre n > 0 y estan preparados en el canal estandard de entrada n sesiones para ser leidas
        \post el parametro implicito pasa a tenr "n" sesiones
    */
    void leer_sesiones (int n);

    /** @brief Operación de escritura

      \pre El parámetro implícito está inicializado
      \post Escribe las propiedades y el contenido del parámetro implícito por el canal estándar de salida 
    */
    void listar_sesiones();

    /** @brief Operación de escritura de una sesion 
      \pre id no es nulo
      \post Escribe las propiedades y el contenido de la sesion "id" por el canal estándar de salida, si la sesion
      no existe de devuelve error
    */
    void listar_sesion(std::string id);
    

};
#endif
