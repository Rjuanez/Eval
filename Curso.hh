/** @file Curso.hh
 * @brief Especificacion de curso
 */

#ifndef _CURSO_HH
#define _CURSO_HH

#ifndef NO_DIAGRAM
#include <string>
#include <map>
#include <vector>
#include <list>
#endif

#include "Cjt_sesion.hh"

/** @class Curso
 *  @brief
 *
 */

class Curso {

private:
  int identificador;
  std::vector<std::string> sesiones;
  int usuarios_completados;
  int usuarios_inscritos;
  std::map<std::string, std::string> lista_problemas_sesiones;

  bool existe_problema(string id);

public:
    /** @file Sesion.hh
 * @brief Especificacion de sesion
 */

    /** @brief Creadora por defecto.

      Se ejecuta automáticamente al declarar un probelma.
      \pre id > 0
      \post El resultado es un problema con identificador "id"
    */
    Curso();

    Curso(int id);

    //Destructora

    /** @brief Destructora por defecto.

      Se ejecuta automáticamente al destruir un problema.
      \pre id > 0
      \post El problema ya no existe
    */
    ~Curso();

    void leer_sesiones(Cjt_sesion& ses);


    //mierda
    std::vector<std::string> listar_sesiones();

    void inscribir_usuario();
    void baja_usuario();

    int num_inscritos();

    std::string consultar_sesion_problema(std::string problema);

    void escribir_curso();

    void identificar(int i);


};
#endif
