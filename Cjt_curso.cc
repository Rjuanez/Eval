#include <iostream>
#include <string>
#include <vector>

#include "Curso.hh"
#include "Cjt_curso.hh"
#include "Cjt_problema.hh"

using namespace std;

Cjt_curso::Cjt_curso() {
  //para que empieze en el 1
  Curso c;
  cursos.push_back(c);
}

Cjt_curso::~Cjt_curso() {}

void Cjt_curso::leer_cursos(int n, Cjt_sesion& sesiones) {
  for (int i = 1; i <= n; ++i){
   Curso curso(i);
   curso.leer_sesiones(sesiones);
   cursos.push_back(curso);
 }
}

vector<string> Cjt_curso::listar_sesiones(int curso) {
  if (curso < cursos.size()) {
    return cursos[curso].listar_sesiones();
  }
  else {
    throw "el curso no existe";
  }
}

void Cjt_curso::inscribir_usuario(int c) {
  if (c < cursos.size()) {
    cursos[c].inscribir_usuario();
  }
  else {
    throw "el curso no existe";
  }
}

void Cjt_curso::baja_usuario(int c) {
  if (c < cursos.size()) {
    cursos[c].baja_usuario();
  }
  else {
    throw "el curso no existe";
  }
}

int Cjt_curso::num_inscritos(int c) {
  if (c < cursos.size()) {
     return cursos[c].num_inscritos();
  }
  else {
    throw "el curso no existe";
  }
}

string Cjt_curso::consultar_sesion_problema(string problema, int curso, Cjt_problema& prob) {
  if (curso != 0 and curso < cursos.size()) {
    if (prob.existe_problema(problema)) {
      try {
       return cursos[curso].consultar_sesion_problema(problema);
     } catch (const char* msg) {
         throw msg;
     }
   } else throw "el problema no existe";
  } else throw "el curso no existe";

}

void Cjt_curso::listar_cursos() {
  int size = cursos.size();
  for (int i = 1; i < size; ++i) cursos[i].escribir_curso();
}

void Cjt_curso::listar_curso(int id) {

    if (id != 0 and id < cursos.size()) {
      cursos[id].escribir_curso();
    }
    else throw "el curso no existe";
}

void Cjt_curso::anadir_curso(Curso c) {
  c.identificar(cursos.size());
  cursos.push_back(c);
}

int Cjt_curso::num_cursos() {
  return cursos.size() - 1;
}
