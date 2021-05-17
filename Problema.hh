/** @file Problema.hh
 * @brief Especificacion de problema 
 */

#ifndef _PROBLEMA_HH
#define _PROBLEMA_HH

#ifndef NO_DIAGRAM
#include <string>
#endif
using namespace std;
/** @class Problema
 *  @brief Representa un problema en la plataforma con sus estadisticas de cuantos envios se han hecho,
 * cuantos envios exitosos y el ratio de envios/envios_exitosos del problema.  Ademas de un identificador unico.
 *
 */
class Problema {

private:

    string identificador;
    int envios;
    int envios_exitosos;
    double ratio;

public:

    /** @brief Creadora por defecto.
      Se ejecuta automáticamente al declarar un problema

      \pre <em>cierto</em>
      \post El resultado es un problema no inicializado, con todos los atributos a 0 menos ratio, que sera 
      igual a 1
    */
    Problema();

    /** @brief Creadora con identificador

      \pre id > 0
      \post El resultado es un problema con con todos los atributos a 0 menos ratio, que sera 
      igual a 1 y  con el id = id
    */
    Problema(string id);

    //Destructora

    /** @brief Destructora por defecto.
      Se ejecuta automáticamente en los objetos locales al salir
      \pre <em>cierto</em>
      \post El resultado es que se elimina el objeto problema
    */
    ~Problema();

    //Modificadoras

    /** @brief Actualiza las estadisticas despues que un usuario haga un envio a este problema
      \pre 0 >= r <= 1 
      \post Se actualizan las estadisticas del parametro implicito, en caso de que r = 1, se entiende que el
      envio es correcto y el problema queda resuelto para ese usuario
    */
    void sumar_envio(int r);

    //consultoras
    /** @brief Consultora del numero de envios

      \pre El parámetro implícito está inicializado
      \post El resultado es el numero de envios del parámetro implícito 
    */
    int consultar_envios();

    /** @brief Consultora del numero de ratio

      \pre El parámetro implícito está inicializado
      \post El resultado es el ratio del parámetro implícito 
    */
    double leer_ratio();

    //Lectura y escritura

    /** @brief Operación de escritura

      \pre El parámetro implícito está inicializado
      \post Escribe las propiedades y el contenido del parámetro implícito por el canal estándar de salida 
    */
    void escribir_problema();
    

    

    


};
#endif
