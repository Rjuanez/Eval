#include <iostream>
#include <string>
#include <map>

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

vector<Problema> Cjt_problema::listar_problemas(const vector<string>& v) {
  int size = v.size();
  vector<Problema> vec_p(size);
  for (int i = 0; i < size; ++i){
    vec_p[i] = problemas.find(v[i])->second;
  }
  return vec_p;
}

void Cjt_problema::listar_enviables() {
  for( auto it = problemas.begin(); it != problemas.end(); ++it ) {
    cout << it->first << '(' << it->second.consultar_envios() << ')' << endl;
  }
}

void Cjt_problema::listar_problemas() {
  //esto esta mal, como todos los ratios son 1 pq no se puede hacer envios, recorro el map normal por id y ya (CAMBIAR)
  for( auto it = problemas.begin(); it != problemas.end(); ++it ) {
    it->second.escribir_problema();
  }
}

void Cjt_problema::listar_problema(string id) {
    if (existe_problema(id)) {
      problemas[id].escribir_problema();
    }
    else throw "el problema no existe";
}
