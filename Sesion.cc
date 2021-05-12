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
	BinTree<string> l;
	leer_arbol(l);
	BinTree<string> r;
	leer_arbol(r);
	a = BinTree<string>(x,l,r);
  }
}
list<string> Sesion::recorrer_arbol(const BinTree<string>& a) {
  list<string> l;
  if (not a.empty()) {
    l.splice(l.end(), recorrer_arbol(a.left()));
    l.splice(l.end(), recorrer_arbol(a.right()));
    l.push_back(a.value());
  }
  return l;
}

void Sesion::construir_arbol() {
    leer_arbol(prerequisitos);
}

string Sesion::leer_primer_problema() {
  return this->prerequisitos.value();
}

list<string> Sesion::consultar_problemas() {
  return recorrer_arbol(prerequisitos);
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
  list<string> l = consultar_problemas();
  cout << identificador << ' ' << l.size() << ' ';
  escribir_arbol(prerequisitos);
  cout << endl;

}
