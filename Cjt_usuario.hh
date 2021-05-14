/** @file Cjt_usuario.hh
 * @brief Especificacion de un conjunto de Cjt_usuario
 */

#ifndef _CJT_USUARIO_HH
#define _CJT_USUARIO_HH

#ifndef NO_DIAGRAM
#include <map>
#endif

#include "Usuario.hh"


/** @class Cjt_usuario
 *  @brief
 *
 */

class Cjt_usuario {

private:
    std::map <std::string, Usuario> usuarios;


public:

    /** @brief Creadora por defecto.

      Se ejecuta automáticamente al declarar un probelma.
      \pre
      \post El resultado es un mapa de sesiones vacio
    */
    Cjt_usuario();

    ~Cjt_usuario();

    void anadir_usuario(std::string id);

    void eliminar_usuario(std::string id, Cjt_curso& curs);
    //Consultoras

    int num_usuarios();
    //Lectura y escritura

    /** @brief Añade sesiones
        \pre n > 0
        \post Se le añaden al parametro implicito un numero n de sesiones
    */
    void leer_usuarios (int n);

    void inscribir_curso(std::string id, int c, Cjt_curso& lista_cursos, Cjt_sesion& lista_sesiones);

    int curso_actual(std::string id);

    void problemas_enviables(std::string id);
    void problemas_resueltos(std::string id);

    void listar_usuarios();
    void listar_usuario(std::string id);
    bool existe_usuario (std::string id);
    void envio_user (std::string user, std::string p, int r, Cjt_problema& problemas, Cjt_curso& cursos, Cjt_sesion& sesiones);
};
#endif
