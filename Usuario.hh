/** @file Usuario.hh
 * @brief Especificacion de sesion
 */

#ifndef _USUARIO_HH
#define _USUARIO_HH

#ifndef NO_DIAGRAM
#include <string>
#include <set>
#endif

#include "Cjt_problema.hh"
#include "Cjt_curso.hh"

/** @class Sesion
 *  @brief
 *
 */

class Usuario {

private:
    Cjt_problema problemas_enviables;
    Cjt_problema problemas_resueltos;
    int envios;
    int problemas_intentados;
    std::string identificador;
    int curso;

    void iniciar_enviables(std::vector<std::string> vec_p);

public:

    /** @brief Creadora por defecto.

      Se ejecuta automáticamente al declarar un probelma.
      \pre id > 0
      \post El resultado es un problema con identificador "id"
    */
    Usuario();

    /** @brief Creadora por defecto.

      Se ejecuta automáticamente al declarar un probelma.
      \pre id > 0
      \post El resultado es un problema con identificador "id"
    */
    Usuario(std::string id);

    //Destructora

    /** @brief Destructora por defecto.

      Se ejecuta automáticamente al destruir un problema.
      \pre id > 0
      \post El problema ya no existe
    */
    ~Usuario();

    void inscribir_curso(int c, std::vector<std::string> vec_p);

    int curso_actual();

    void f_problemas_enviables();
    void f_problemas_resueltos();

    void escribir_usuario();

};
#endif
