#ifndef NO_DIAGRAM
#include <iostream>
#include <string>
#endif

#include "Problema.hh"

using namespace std;

Problema::Problema() {
    envios = 0;
    envios_exitosos = 0;
    ratio = 1;
    identificador = "";
}

Problema::~Problema(){}

int Problema::consultar_envios(){
  return envios;
}

Problema::Problema(string identificador) {
    envios = 0;
    envios_exitosos = 0;
    ratio = 1;
    this->identificador = identificador;
}

void Problema::escribir_problema() {
  cout << identificador << '(' << envios << ',' << envios_exitosos << ',' << ratio << ')' << endl;
}

void Problema::sumar_envio(int r) {
  ++envios;
  if(r == 1) ++envios_exitosos;
  ratio = double(envios + 1.0)/(envios_exitosos + 1.0);
}

double Problema::leer_ratio(){
  return ratio;
}
