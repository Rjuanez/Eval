/** @file Cjt_sesion.hh
 * @brief Especificacion de un conjunto de Cjt_sesion
 */

#ifndef _CJT_SESION_HH
#define _CJT_SESION_HH

#ifndef NO_DIAGRAM
#include <map>
#include <vector>
#endif

#include "Sesion.hh"

/** @class Cjt_sesion
 *  @brief
 *
 */

class Cjt_sesion {

private:
    map <std::string, Sesion> sesiones;

    bool existe_sesion (std::string id);

public:

    /** @brief Creadora por defecto.

      Se ejecuta automáticamente al declarar un probelma.
      \pre
      \post El resultado es un mapa de sesiones vacio
    */
    Cjt_sesion();

    ~Cjt_sesion();

    void anadir_sesion(std::string id);

    //Consultoras

    int num_sesiones();

    std::string listar_primer_problema(std::string sesion);

    int num_problemas_sesion(std::string sesion);
    std::string consultar_problema_sesion(string sesion, int i);

    //Lectura y escritura

    /** @brief Añade sesiones
        \pre n > 0
        \post Se le añaden al parametro implicito un numero n de sesiones
    */
    void leer_sesiones (int n);

    void listar_sesiones();
    void listar_sesion(std::string id);
    std::string buscar_nuevo_problema(std::string p, std::string sesion, int lado);

};
#endif
