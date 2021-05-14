#include <iostream>
#include <string>

#include "Sesion.hh"
#include "Cjt_sesion.hh"
#include "BinTree.hh"

using namespace std;

Cjt_sesion::Cjt_sesion() { }
Cjt_sesion::~Cjt_sesion() { }

void Cjt_sesion::leer_sesiones(int n) {
    while (n > 0) {
        string id;
        cin >> id;
        Sesion s(id);
        s.construir_arbol();
        this->sesiones.insert(pair<string, Sesion>(id, s));
        --n;
    }

}

bool Cjt_sesion::existe_sesion(string id) {
    bool existe_sesion = false;
    map<string,Sesion>::iterator it;
    it = sesiones.find(id);
    if (it != sesiones.end()) existe_sesion = true;

    return existe_sesion;
}

int Cjt_sesion::num_sesiones() {
    return sesiones.size();
}

void Cjt_sesion::anadir_sesion(string id) {
  Sesion s(id);
  s.construir_arbol();
  if (not existe_sesion(id)) {
    this->sesiones.insert(pair<string, Sesion>(id, s));
  }
  else {
    throw "la sesion ya existe";
  }
}

string Cjt_sesion::listar_primer_problema(string sesion) {
    return sesiones.find(sesion)->second.leer_primer_problema();
}

list<string> Cjt_sesion::consultar_problemas(string sesion) {
  return sesiones.find(sesion)->second.consultar_problemas();
}

void Cjt_sesion::listar_sesiones() {
  for( auto it = sesiones.begin(); it != sesiones.end(); ++it ) {
    it->second.escribir_sesion();
  }
}

void Cjt_sesion::listar_sesion(string id) {
    if (existe_sesion(id)) {
      sesiones.find(id)->second.escribir_sesion();
    }
    else throw "la sesion no existe";
}

string Cjt_sesion::buscar_nuevo_problema(string p, string sesion, int lado) {
  return sesiones.find(sesion)->second.nuevo_problema(p, lado);
}
