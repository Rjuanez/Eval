/** @file Cjt_curso.hh
 * @brief Especificacion de un conjunto de Cjt_curso
 */

#ifndef _CJT_CURSO_HH
#define _CJT_CURSO_HH

#ifndef NO_DIAGRAM
#include <vector>
#endif

#include "Curso.hh"
#include "Cjt_problema.hh"



/** @class Cjt_curso
 *  @brief  Representa un conjunto de cursos
 */

class Cjt_curso {

private:

std::vector <Curso> cursos;


public:

    /** @brief Creadora por defecto.
      Se ejecuta automáticamente al declarar un conjunto de cursos.

      \pre <em>cierto</em>
      \post El resultado es un conjunto de cursos vacio
    */
    Cjt_curso();

    /** @brief Destructora por defecto.
      Se ejecuta automáticamente en los objetos locales al salir
      \pre <em>cierto</em>
      \post El resultado es que se elimina el objeto conjunto de cursos
    */
    ~Cjt_curso();

    //Modificadoras

    /** @brief Da de alta a un usuario
      \pre c > 0
      \post El resultado es que se contabiliza un usuario inscrito en el cursoc
    */
    void inscribir_usuario(int c);

    /** @brief Da de baja a un usuario
      \pre c > 0
      \post El resultado es que se contabiliza un usuario dado de baja en el curso c
    */
    void baja_usuario(int c);

    /** @brief Se añade un curso c al conjunto
      \pre c esta inicializado
      \post El resultado es que sse añade un curso c al parametro implicito
    */
    void anadir_curso(Curso c);


    /** @brief Usuario ha completado el curso c
      \pre curso > 0
      \post Se actualizan las estadisticas del curso "curso" para sumarle que un usuario ha completado el curso
    */
    void curso_completo(int curso);

    //Consultoras

    /** @brief Consultora del numero de cursos

      \pre El parámetro implícito está inicializado
      \post El resultado es el numero de cursos que tiene parámetro implícito 
    */
    int num_cursos();
    /** @brief Consultora del numero de sesiones al curso "c"

      \pre c está inicializado
      \post El resultado es el numero de sesiones que tiene el curso "c"
    */
    int num_sesiones(int c);

    /** @brief Consultora de la sesion "i" del curso "c"

      \pre  i >= 0, c > 0
      \post El resultado es la sesion i-essima de las sesiones que pertenecen al parametro implicito
    */
    std::string leer_sesion_curso(int i, int c);

/** @brief Consultora del numero de inscritos al curso "c"

      \pre <em>cierto</em>
      \post El resultado es el numero de inscritos del curso "c"
    */
    int num_inscritos(int c);

    /** @brief Consultora en que sesion se encuentra un problema del curso "curso"

      \pre <em>cierto</em>
      \post El resultado es el nombre de la sesion que contiene el problema "problema", en caso de que
      no exista dicho problema, se devuelve un error indicandolo
    */
    std::string consultar_sesion_problema(std::string problema, int curso, Cjt_problema& prob);

    //Lectura y escritura

    /** @brief Operación de lecutra

      \pre Estan preparados en el canal estandar un numero n de cursos, conjunto sesiones esta inicializado
      \post El parametro implicito pasa a tener tantos cursos como "n"
    */
    void leer_cursos(int n, Cjt_sesion& sesiones);

    /** @brief Operación de escritura

      \pre El parámetro implícito está inicializado
      \post Escribe las propiedades y el contenido del parámetro implícito por el canal estándar de salida 
    */
    void listar_cursos();

    /** @brief Operación de escritura de un curso "id"

      \pre id no es nulo
      \post Escribe las propiedades y el contenido del curso "id" por el canal estándar de salida 
    */
    void listar_curso(int id);

};
#endif
