/** @file Problema.hh
 * @brief Especificacion de problema con letra
 */

#ifndef _PROBLEMA_HH
#define _PROBLEMA_HH

#ifndef NO_DIAGRAM
#include <string>
#endif
using namespace std;
/** @class Problema
 *  @brief
 *
 */

class Problema {

private:

    string identificador;
    int envios;
    int envios_exitosos;
    int ratio;

public:

    /** @brief Creadora por defecto.

      Se ejecuta automáticamente al declarar un probelma.
      \pre id > 0
      \post El resultado es un problema vacio sin identificador
    */
    Problema();

    /** @brief Creadora con identificador
      \pre id > 0
      \post El resultado es un problema con identificador "id"
    */
    Problema(string id);

    //Destructora

    /** @brief Destructora por defecto.

      Se ejecuta automáticamente al destruir un problema.
      \pre id > 0
      \post El problema ya no existe
    */
    ~Problema();

    int consultar_envios();

    void escribir_problema();


};
#endif
