/** @file Curso.hh
 * @brief Especificacion de curso
 */

#ifndef _CURSO_HH
#define _CURSO_HH

#ifndef NO_DIAGRAM
#include <string>
#include <map>
#endif

#include "Cjt_sesion.hh"

/** @class Curso
 *  @brief Representa un curso en la plataforma con un numero de sesiones y sus estadisticas de cuantos usuarios
 * estan escritos y cuantos han completado el curso y un identificador unico.
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
      Se ejecuta automáticamente al declarar un curso

      \pre <em>cierto</em>
      \post El resultado es un curso sin sesiones ni usuarios
    */
    Curso();

    /** @brief Creadora con identificador
      Se ejecuta automáticamente al declarar un curso

      \pre id > 0
      \post El resultado es un curso sin sesiones ni usuarios con el id = id
    */
    Curso(int id);

    //Destructora

    /** @brief Destructora por defecto.
      Se ejecuta automáticamente en los objetos locales al salir
      \pre <em>cierto</em>
      \post El resultado es que se elimina el objeto curso
    */
    ~Curso();

    //Modificadoras

    /** @brief Da de alta a un usuario
      \pre <em>cierto</em>
      \post El resultado es que se le suma 1 al atributo implicito usuarios_inscritos
    */
    void inscribir_usuario();

    /** @brief Da de baja a un usuario
      \pre <em>cierto</em>
      \post El resultado es que se le resta 1 al atributo implicito usuarios_inscritos
    */
    void baja_usuario();

    /** @brief Añade indentificador al curso
      \pre el parametro implicito no tiene identificador, 0 = "identificador"
      \post El identificador del parametro implicito pasa a ser "i"
    */
    void identificar(int i);

    /** @brief Actualiza las estadisticas despues que un usuario complete el curso
      \pre <em>cierto</em>
      \post El identificador del parametro implicito pasa a ser "i"
    */
    void completado();

    //Consultoras
   
    /** @brief Consultora del numero de inscritos al curso

      \pre El parámetro implícito está inicializado
      \post El resultado es el numero de inscritos del parámetro implícito 
    */
    int num_inscritos();

    /** @brief Consultora del numero de sesiones al curso

      \pre El parámetro implícito está inicializado
      \post El resultado es el numero de sesiones que tiene parámetro implícito 
    */
    int num_sesiones();

    /** @brief Consultora de la sesion "i" del curso

      \pre El parámetro implícito está inicializado y i >= 0
      \post El resultado es la sesion i-essima de las sesiones que pertenecen al parametro implicito
    */
    std::string leer_sesion(int i);

    /** @brief Consultora en que sesion se encuentra un problema 

      \pre El parámetro implícito está inicializado 
      \post El resultado es el nombre de la sesion que contiene el problema "problema", en caso de que
      no exista dicho problema, se devuelve un error indicandolo
    */
    std::string consultar_sesion_problema(std::string problema);

    //Lectura y escritura

    /** @brief Operación de lecutra

      \pre Estan preparados en el canal estandar un int n con el numero de sesiones y tantos nombre de sesiones 
      como n
      \post El parametro implicito pasa a tener los atributos leidos por el canar estandard de entrada, si
      hay problemas repetidos no se leen los cursos y se devuelve un error
    */
    void leer_sesiones(Cjt_sesion& ses);

    /** @brief Operación de escritura

      \pre El parámetro implícito está inicializado
      \post Escribe las propiedades y el contenido del parámetro implícito por el canal estándar de salida 
    */
    void escribir_curso();

    


};
#endif
