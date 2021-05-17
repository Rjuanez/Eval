#include <iostream>
#include <string>

#include "Sesion.hh"
#include "BinTree.hh"

using namespace std;

Sesion::Sesion(string identificador) {
    this->identificador = identificador;
}
Sesion::~Sesion() {}

void Sesion::leer_arbol(BinTree<string>& a) {
  string x;
  cin >> x;
  if (x!="0"){
  problemas.push_back(x);
	BinTree<string> l;
	leer_arbol(l);
	BinTree<string> r;
	leer_arbol(r);
	a = BinTree<string>(x,l,r);


  //first = 1 = right, second = 0 = left
  if (r.empty() and l.empty()) problemas_ordenados.insert(make_pair(x, make_pair("0", "0")));
  else if (r.empty()) problemas_ordenados.insert(make_pair(x, make_pair("0", l.value())));
  else if (l.empty()) problemas_ordenados.insert(make_pair(x, make_pair(r.value(), "0")));
  else problemas_ordenados.insert(make_pair(x, make_pair(r.value(), l.value())));
  }
}

void Sesion::construir_arbol() {
    leer_arbol(prerequisitos);
}

string Sesion::leer_primer_problema() {
  return this->prerequisitos.value();
}

void Sesion::escribir_arbol(const BinTree<string>& a) {
  if (not a.empty()) {
    cout << '(';
		escribir_arbol(a.left());
		escribir_arbol(a.right());
    cout << a.value() << ')';
  }
}

void Sesion::escribir_sesion() {
  cout << identificador << ' ' << problemas.size() << ' ';
  escribir_arbol(prerequisitos);
  cout << endl;

}

string Sesion::nuevo_problema(string p, int lado) {
  if (lado == 0) {
    return problemas_ordenados.find(p)->second.second;
  }
  else {
    return problemas_ordenados.find(p)->second.first;
  }
}

int Sesion::num_problemas() {
  return problemas.size();
}

string Sesion::consultar_problema(int i) {
  return problemas[i];
}
