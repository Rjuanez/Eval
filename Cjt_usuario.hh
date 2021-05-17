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
 *  @brief Representa un conjunto de usuarios
 *
 */

class Cjt_usuario {

private:
    std::map <std::string, Usuario> usuarios;

public:

    /** @brief Creadora por defecto.
      Se ejecuta automáticamente al declarar un conjunto de usuarios.

      \pre <em>cierto</em>
      \post El resultado es un conjunto de usuarios vacio
    */
    Cjt_usuario();

    /** @brief Destructora por defecto.
      Se ejecuta automáticamente en los objetos locales al salir
      \pre <em>cierto</em>
      \post El resultado es que se elimina el objeto conjunto de usuaiors
    */
    ~Cjt_usuario();

    //Modificadoras

    /** @brief Se añade un usuario con identificador "id"
      \pre id no es nuelo
      \post El resultado es que sse añade un usuario con identificador "id" al parametro implicito
    */
    void anadir_usuario(std::string id);

    /** @brief Se elimina un usuario con identificador "id"
      \pre id no es nuelo y el conjunto de cursos esta inicializado
      \post El resultado es que se elimina un usuario con identificador "id" al parametro implicito y se resta
      de las estadisticas del curso al que esta inscrito
    */
    void eliminar_usuario(std::string id, Cjt_curso& curs);

    /** @brief Un usuario se inscribe en un curso
      \pre c > 0, id no nulo y los conjuntos de cursos y sesiones estan inicializaods
      \post El usuario "id" se inscribe a un curso actualizando la lista de problemas a los que puede hacer envio,
      en caso de que el usuario ya este escrito en un curso se devuelve un error
    */
    void inscribir_curso(std::string id, int c, Cjt_curso& lista_cursos, Cjt_sesion& lista_sesiones);

    /** @brief Un usuario hace envio a un problema de un curso especifico
      \pre p y user no son nulos, 0 >= r <= 1 y los conjuntos de problemas, cursos y sesiones estan inicializaods
      \post Un usuario hace un envio de un problema a un curso especifico actualizando todas sus estadisticas y 
      actualizando los conjuntos de problemas tanto resueltos como enviables del usuario
    */
    void envio_user (std::string user, std::string p, int r, Cjt_problema& problemas, Cjt_curso& cursos, Cjt_sesion& sesiones);


    //Consultoras

    /** @brief Consultora del numero de usuarios

      \pre El parámetro implícito está inicializado
      \post El resultado es el numero de usuarios que tiene parámetro implícito 
    */
    int num_usuarios();

    /** @brief Consultora del curso de un usuario

      \pre <em>cierto</em>
      \post El resultado es el curso al que esta inscrito el usuario "id", en caso que el usuario "id" no exista
      devuelve error
    */
    int curso_actual(std::string id);

    /** @brief Consultora de si existe un usuario 

      \pre El parámetro implícito está inicializado
      \post El resultado es si existe el objeto "id" en el parametro implicito
    */
    bool existe_usuario (std::string id);

    //Lectura y escritura

    /** @brief Añade n usuarios al parametro implicito
        \pre n > 0 y estan preparados en el canal estandard de entrada n usuarios para ser leidos
        \post el parametro implicito pasa a tenr "n" usuarios
    */
    void leer_usuarios (int n);

    /** @brief Operación de escritura de los problemas a los que el usuario "id" puede hacer envio

      \pre id no es nuelo
      \post Escribe los problemas enviables del usuario "id" por el canal estandard de salida, en caso de que el usuario no ese inscrito
      en ningun curso devuevle error
    */
    void problemas_enviables(std::string id);

    /** @brief Operación de escritura de los problemas del usuario "id" que ya se han resuelto

      \pre  id no es nuelo
      \post Escribe los problemas resueltos del usuario "id" por el canal estandard de salida, en caso de que el usuario no ese inscrito
      en ningun curso devuevle error
    */
    void problemas_resueltos(std::string id);

    /** @brief Operación de escritura

      \pre El parámetro implícito está inicializado
      \post Escribe las propiedades y el contenido del parámetro implícito por el canal estándar de salida 
    */
    void listar_usuarios();

    /** @brief Operación de escritura de un usuario
      \pre id no es nulo
      \post Escribe las propiedades y el contenido del usuario "id" por el canal estándar de salida, si el usuario
      no existe de devuelve error
    */
    void listar_usuario(std::string id);
    
    
};
#endif
