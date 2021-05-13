/** @file Cjt_problema.hh
 * @brief Especificacion de un conjunto de Cjt_problema
 */

#ifndef _CJT_PROBLEMA_HH
#define _CJT_PROBLEMA_HH

#ifndef NO_DIAGRAM
#include <map>
#include <vector>
#endif
#include "Problema.hh"


/** @class Cjt_problema
 *  @brief
 *
 */

class Cjt_problema {

private:
    //faltan cosas
    std::map<std::string, Problema> problemas;



public:
  bool existe_problema (std::string id);
    /** @brief Creadora por defecto.
        Se ejecuta automáticamente al declarar un probelma.
      \pre Cierto
      \post El resultado es un mapa de probelmas vacio
    */
    Cjt_problema();

    ~Cjt_problema();

    void anadir_problema(std::string id);

    //Consultoras

    int num_problemas();


    // Lectura i escriptura

    /** @brief Añade n problemas al parametro implicito
        \pre num_problemas > 0 y estan preparados en el canal estandard de entrada n string
     que llegirem, i les dades de tal nombre d'estudiants diferent
        \post Se le añaden al parametro implicito un numero n de problemas identificados por id
    */
    void leer_problemas(int n);

    //mierda
    std::vector<Problema> listar_problemas(const std::vector<std::string>& v);

    void listar_enviables();

    void listar_problemas();
    void listar_problema(std::string id);

};
#endif
