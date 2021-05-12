#include <iostream>
#include <string>
#include <set>

#include "Usuario.hh"
#include "Cjt_problema.hh"

using namespace std;


Usuario::Usuario() {
  curso = 0;
  envios = 0;
  problemas_intentados = 0;
}

Usuario::Usuario(string id) {
  this->identificador = id;
  curso = 0;
  envios = 0;
  problemas_intentados = 0;
}

Usuario::~Usuario() {}

void Usuario::inscribir_curso(int c, vector<std::string> vec_p) {
  if (this->curso == 0) {
    this->curso = c;
    iniciar_enviables(vec_p);

  }
  else {
    if (problemas_enviables.num_problemas() == 0) { //soluciona
      this->curso = c;
      iniciar_enviables(vec_p);
    }
    else {
      throw "usuario inscrito en otro curso";
    }
  }
}

void Usuario::iniciar_enviables(vector<std::string> vec_p) {
  int size = vec_p.size();
  for (int i = 0; i < size; ++i) {
    problemas_enviables.anadir_problema(vec_p[i]);
  }

}

int Usuario::curso_actual(){
  return this->curso;
}

void Usuario::f_problemas_enviables() {
  if(curso > 0) {
    problemas_enviables.listar_enviables();
  }
  else throw "usuario no inscrito en ningun curso";

}
void Usuario::f_problemas_resueltos() {
  if(curso > 0) {

  }
  else throw "usuario no inscrito en ningun curso";

}

void Usuario::escribir_usuario() {
  cout << identificador << '(' << envios << ',' << problemas_resueltos.num_problemas()
  << ',' << problemas_intentados << ',' << curso << ')' << endl;
}
