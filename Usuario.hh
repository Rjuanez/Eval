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

    void iniciar_enviables(int c, int num_sesiones, Cjt_curso& lista_cursos, Cjt_sesion& lista_sesiones);

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

    void inscribir_curso(int c, Cjt_curso& lista_cursos, Cjt_sesion& lista_sesiones);

    int curso_actual();

    void f_problemas_enviables();
    void f_problemas_resueltos();

    void escribir_usuario();
    void envio(std::string p, int r, Cjt_problema& problemas, Cjt_curso& cursos, Cjt_sesion& sesiones);
    void actualizar_enviables(std::string p, std::string sesion, Cjt_sesion& sesiones);
};
#endif
