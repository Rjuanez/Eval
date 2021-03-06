
#ifndef NO_DIAGRAM
#include <iostream>
#include <string>
#include <map>
#endif

#include "Problema.hh"
#include "Cjt_problema.hh"

using namespace std;

Cjt_problema::Cjt_problema() {}

Cjt_problema::~Cjt_problema() {}

void Cjt_problema::leer_problemas(int n) {
    while (n > 0) {
        string id;
        cin >> id;
        Problema p(id);
        problemas.insert(make_pair(id, p));
        --n;
    }
}

bool Cjt_problema::existe_problema(string id) {
    bool existe_problema = false;
    map<string,Problema>::iterator it;
    it = problemas.find(id);
    if (it != problemas.end()) existe_problema = true;

    return existe_problema;
}

int Cjt_problema::num_problemas() {
    return problemas.size();
}

void Cjt_problema::anadir_problema(string id) {
  if (not existe_problema(id)) {
    Problema p(id);
    this->problemas.insert(pair<string, Problema>(id, p));
  }
  else {
    throw "el problema ya existe";
  }
}


void Cjt_problema::listar_enviables() {
  for( auto it = problemas.begin(); it != problemas.end(); ++it ) {
    cout << it->first << '(' << it->second.consultar_envios() << ')' << endl;
  }
}

void Cjt_problema::listar_problemas() {
  //esto esta mal, como todos los ratios son 1 pq no se puede hacer envios, recorro el map normal por id y ya (CAMBIAR)
  map< pair<double, string> , Problema> p_ordenados_ratio;
  for( auto it = problemas.begin(); it != problemas.end(); ++it ) {
    p_ordenados_ratio.insert(make_pair(make_pair(it->second.leer_ratio(), it->first),it->second));
  }
  for( auto it = p_ordenados_ratio.begin(); it != p_ordenados_ratio.end(); ++it ) {
    it->second.escribir_problema();
  }
}

void Cjt_problema::listar_problema(string id) {
    if (existe_problema(id)) {
      problemas[id].escribir_problema();
    }
    else throw "el problema no existe";
}

void Cjt_problema::sumar_envio(string problema, int r) {
  problemas.find(problema)->second.sumar_envio(r);

}

int Cjt_problema::envios_problema(string problema) {
  return problemas.find(problema)->second.consultar_envios();
}


Problema Cjt_problema::eliminar_problema(string problema) {
  map<string,Problema>::iterator it;
  it = problemas.find(problema);
  Problema p = it->second;
  problemas.erase(it);
  return p;
}

void Cjt_problema::anadir_problema_objeto(Problema& p, string problema) {
  this->problemas.insert(make_pair(problema, p));
}
