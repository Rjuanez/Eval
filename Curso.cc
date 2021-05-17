#ifndef NO_DIAGRAM
#include <iostream>
#include <string>
#endif

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

void Curso::inscribir_usuario() {
  ++usuarios_inscritos;
}
void Curso::baja_usuario() {
  --usuarios_inscritos;
}

void Curso::completado(){
  --usuarios_inscritos;
  ++usuarios_completados;
}


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
    //pedir numero de probelmas en la lista
    int num_problemas = ses.num_problemas_sesion(nuevas_sesiones[i]);
    //recorrer la lista de todos los problemas de cada sesion
    for(int j = 0; j < num_problemas; ++j ) {
      //comprobar si el probelma existe VA A DAR FALLO DE EFICICIENCIA
      string nuevo_problema = ses.consultar_problema_sesion(nuevas_sesiones[i], j);
      if (not existe_problema(nuevo_problema)) {
        lista_problemas_sesiones.insert(make_pair(nuevo_problema, nuevas_sesiones[i]));
      }
      else throw "curso mal formado";
    }
  }

}






int Curso::num_inscritos() {
  return usuarios_inscritos;
}

int Curso::num_sesiones() {
  return sesiones.size();
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



string Curso::leer_sesion(int i) {
  return sesiones[i];
}
