/** @file Cjt_problema.hh
 * @brief Especificacion de un conjunto de Cjt_problema
 */

#ifndef _CJT_PROBLEMA_HH
#define _CJT_PROBLEMA_HH

#ifndef NO_DIAGRAM
#include <map>
#include <vector>
#endif
#include "Problema.hh"


/** @class Cjt_problema
 *  @brief Representa un conjunto de problemas
 *
 */

class Cjt_problema {

private:
    std::map<std::string, Problema> problemas;

public:

  

     /** @brief Creadora por defecto.
      Se ejecuta automáticamente al declarar un conjunto de problemas.

      \pre <em>cierto</em>
      \post El resultado es un conjunto de probelmas vacio
    */
    Cjt_problema();

    /** @brief Destructora por defecto.
      Se ejecuta automáticamente en los objetos locales al salir
      \pre <em>cierto</em>
      \post El resultado es que se elimina el objeto conjunto de problemas
    */
    ~Cjt_problema();


    

    //Modificadoras

    /** @brief Se añade un problema con identificador "id"
      \pre id no es nuelo
      \post El resultado es que se añade un problema con identificador "id" al parametro implicito
    */
    void anadir_problema(std::string id);

    /** @brief Actualiza las estadisticas despues que un usuario haga un envio a un problema
      \pre 0 >= r <= 1  y problema no nulo
      \post Se actualizan las estadisticas del parametro implicito, en caso de que r = 1, se entiende que el
      envio es correcto y el problema queda resuelto para ese usuario
    */
    void sumar_envio(std::string problema, int r );

    /** @brief Se elimina un problema 
      \pre problema no es nuelo 
      \post El resultado es que se elimina un problema con identificador ""problema" al parametro implicito y devuelve el problema
      con dicho identificador como resultado de la funcion
    */
    Problema eliminar_problema(std::string problema);

    /** @brief Se añade un problema p
      \pre problema no es nuelo y p esta inicializado
      \post El resultado es que se añade un problema "p" con identificador "problema" al parametro implicito
    */
    void anadir_problema_objeto(Problema& p, std::string problema);

    //Consultoras

    /** @brief Consultora del numero de problemas

      \pre El parámetro implícito está inicializado
      \post El resultado es el numero de problemas que tiene parámetro implícito 
    */
    int num_problemas();

    /** @brief Consultora de si existe un problema "id"

      \pre El parámetro implícito está inicializado
      \post El resultado es si existe el objeto "id" en el parametro implicito
    */
    bool existe_problema (std::string id);

    /** @brief Consultora del numero de envios de un problema

      \pre <em>cierto</em>
      \post El resultado es el numero de envios del problema "problema", en caso de que el problema no exista
      se devuelve un error
    */
    int envios_problema(std::string problema);


    // Lectura i escriptura

    /** @brief Añade n problemas al parametro implicito
        \pre n > 0 y estan preparados en el canal estandard de entrada n problemas para ser leidos
        \post el parametro implicito pasa a tenr "n" problemas
    */
    void leer_problemas(int n);

    /** @brief Operación de escritura de los envios hechos a todos los problemas

      \pre El parámetro implícito está inicializado
      \post El resultado es el numero de envios de todos los problemas del parámetro implícito 
    */
    void listar_enviables();

    /** @brief Operación de escritura

      \pre El parámetro implícito está inicializado
      \post Escribe las propiedades y el contenido del parámetro implícito por el canal estándar de salida 
    */
    void listar_problemas();

    /** @brief Operación de escritura de un problema 

      \pre id no es nulo
      \post Escribe las propiedades y el contenido del problema "id" por el canal estándar de salida, si el problema
      no existe de devuelve error
    */
    void listar_problema(std::string id);
    
    vector<Problema> listar_problemas(const vector<string>& v);
    
    
    
    
};
#endif
