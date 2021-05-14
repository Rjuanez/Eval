#include <iostream>
#include <string>
#include <set>
#include <list>

#include "Curso.hh"

using namespace std;

Curso::Curso() {
  usuarios_completados = 0;
  usuarios_inscritos = 0;
}

Curso::Curso(int id) {
  usuarios_completados = 0;
  usuarios_inscritos = 0;
  identificador = id;
}

Curso::~Curso() {}
//posible problema de rendimiento
void Curso::leer_sesiones(Cjt_sesion& ses) {
  int n;
  cin >> n;
  //legir identificadors en un vector
  vector<string> nuevas_sesiones;
  while (n > 0){
    string s;
    cin >> s;
    nuevas_sesiones.push_back(s);
     --n;
  }
  for (int i = 0; i < nuevas_sesiones.size(); ++i) {
    //añadimos la sesion al vector de sesiones
    sesiones.push_back(nuevas_sesiones[i]);
    list<string> l;
    //devuelve la lista de todos los probelmas de la sesion
    l = ses.consultar_problemas(nuevas_sesiones[i]);
    //recorrer la lista de todos los problemas de cada sesion
    for( auto it = l.begin(); it != l.end(); ++it ) {
      //comprobar si el probelma existe VA A DAR FALLO DE EFICICIENCIA
      if (not existe_problema(*it)) {
        lista_problemas_sesiones.insert(make_pair(*it, nuevas_sesiones[i]));
      }
      else throw "curso mal formado";
    }
  }

}

vector<string> Curso::listar_sesiones() {
  return sesiones;
}

void Curso::inscribir_usuario() {
  ++usuarios_inscritos;
}

void Curso::baja_usuario() {
  --usuarios_inscritos;
}

int Curso::num_inscritos() {
  return usuarios_inscritos;
}

string Curso::consultar_sesion_problema(string problema) {
  if (existe_problema(problema)) {
    return lista_problemas_sesiones.find(problema)->second;
  }
  else {
    throw "el problema no pertenece al curso";
  }
}

bool Curso::existe_problema(string id) {
    bool existe_problema = false;
    map<string,string>::iterator it;
    it = lista_problemas_sesiones.find(id);
    if (it != lista_problemas_sesiones.end()) existe_problema = true;
    return existe_problema;
}

void Curso::escribir_curso() {
  int size = sesiones.size();
  cout << identificador << ' ' << usuarios_completados << ' '
  << usuarios_inscritos << ' ' << size << " (";
  for (int i = 0; i < size; ++i) {
    cout << sesiones[i];
    if (i < size - 1) cout << ' ';
  }

  cout << ')' << endl;
}

void Curso::identificar(int i) {
  identificador = i;
}

void Curso::completado(){
  --usuarios_inscritos;
  ++usuarios_completados;
}
