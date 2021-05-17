/** @file Usuario.hh
 * @brief Especificacion de usuario
 */

#ifndef _USUARIO_HH
#define _USUARIO_HH

#ifndef NO_DIAGRAM
#include <string>
#include <set>
#endif

#include "Cjt_problema.hh"
#include "Cjt_curso.hh"

/** @class Usuario
 *  @brief Representa un usuario en la plataforma con sus estadisticas de cuantos envios se han hecho,
 * cuantos problemas se han intenado hacer, ademas del curso al que esta inscrito dicho usuario, un identificador
 * unico y dos conjuntos con los problemas que puede enviar y los que ya ha resuelto.
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

    /** @brief Inicia los problemas enviables al inscribirse en un curso
      Se ejecuta automáticamente al declarar un problema

      \pre c > 0, num_sesiones > 0 y los conjuntos de cursos y sesiones estan inicializados
      \post El resultado es un usuario con los conjuntos de problemas enviables inicializados con los problemas,
      del nuevo curso
    */
    void iniciar_enviables(int c, int num_sesiones, Cjt_curso& lista_cursos, Cjt_sesion& lista_sesiones);

    /** @brief Inicia los problemas enviables al hacer un envio
      Se ejecuta automáticamente al declarar un problema

      \pre p y sesion no son nulos, y el conjutno de sesiones esta inicializado
      \post El resultado es un usuario con los conjuntos de problemas enviables actualizados despues del envio
    */
    void actualizar_enviables(std::string p, std::string sesion, Cjt_sesion& sesiones);

public:

     /** @brief Creadora por defecto.
      Se ejecuta automáticamente al declarar un problema

      \pre <em>cierto</em>
      \post El resultado es un usuario no inicializado, con todos los atributos a 0 y los conjuntos vacios
    */
    Usuario();

    /** @brief Creadora con identificador

      \pre id > 0
      \post El resultado es un usuario con con todos los atributos a 0 y con identificador = "id"
    */
    Usuario(std::string id);

    //Destructora

    /** @brief Destructora por defecto.
      Se ejecuta automáticamente en los objetos locales al salir
      \pre <em>cierto</em>
      \post El resultado es que se elimina el objeto usuario
    */
    ~Usuario();

    //Modificadora

    /** @brief Usuario hace envio a un problema de un curso especifico
      \pre p no es nulo, 0 >= r <= 1 y los conjuntos de problemas, cursos y sesiones estan inicializaods
      \post El usuario hace un envio de un problema a un curso especifico actualizando todas sus estadisticas y 
      actualizando los conjuntos de problemas tanto resueltos como enviables del parametro implicito
    */
    void envio(std::string p, int r, Cjt_problema& problemas, Cjt_curso& cursos, Cjt_sesion& sesiones);

    /** @brief Usuario se inscribe en un curso
      \pre c > 0 y los conjuntos de cursos y sesiones estan inicializaods
      \post El usuario se inscribe a un curso actualizando la lista de problemas a los que puede hacer envio,
      en caso de que el usuario ya este escrito en un curso se devuelve un error
    */
    void inscribir_curso(int c, Cjt_curso& lista_cursos, Cjt_sesion& lista_sesiones);

    //Consultoras
    /** @brief Consultora del curso del usuario

      \pre El parámetro implícito está inicializado
      \post El resultado es el curso al que esta inscrito del parámetro implícito 
    */
    int curso_actual();

    //Lectura y escritura

    
    /** @brief Operación de escritura de los problemas a los que se puede hacer envio

      \pre El parámetro implícito está inicializado
      \post Escribe los problemas enviables por el canal estandard de salida, en caso de que el usuario no ese inscrito
      en ningun curso devuevle error
    */
    void f_problemas_enviables();

    /** @brief Operación de escritura de los problemas que ya se han resuelto

      \pre El parámetro implícito está inicializado
      \post Escribe los problemas resueltos por el canal estandard de salida, en caso de que el usuario no ese inscrito
      en ningun curso devuevle error
    */
    void f_problemas_resueltos();

    /** @brief Operación de escritura

      \pre El parámetro implícito está inicializado
      \post Escribe las propiedades y el contenido del parámetro implícito por el canal estándar de salida 
    */
    void escribir_usuario();
    
};
#endif
