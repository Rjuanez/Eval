#include <iostream>
#include <string>

#include "Usuario.hh"
#include "Cjt_usuario.hh"
#include "Cjt_curso.hh"

using namespace std;


Cjt_usuario::Cjt_usuario() {}

Cjt_usuario::~Cjt_usuario() {}

void Cjt_usuario::leer_usuarios(int n) {
    while (n > 0) {
        string id;
        cin >> id;
        Usuario u(id);
        this->usuarios.insert(pair<string, Usuario>(id, u));
        --n;

    }
}

bool Cjt_usuario::existe_usuario(string id) {
    bool existe_usuario = false;
    map<string,Usuario>::iterator it;
    it = usuarios.find(id);
    if (it != usuarios.end())
        existe_usuario = true;

    return existe_usuario;
}

int Cjt_usuario::num_usuarios() {
    return usuarios.size();
}

void Cjt_usuario::anadir_usuario(string id) {
  if (not existe_usuario(id)) {
    Usuario u(id);
    this->usuarios.insert(pair<string, Usuario>(id, u));
  }
  else {
    throw "el usuario ya existe";
  }
}

void Cjt_usuario::eliminar_usuario(string id, Cjt_curso& curs) {
  if (existe_usuario(id)) {
    map<string,Usuario>::iterator it;
    it = usuarios.find(id);
    if (it->second.curso_actual() != 0) curs.baja_usuario(it->second.curso_actual());
    usuarios.erase(it);
  }
  else {
    throw "el usuario no existe";
  }
}

void Cjt_usuario::inscribir_curso(string id, int c, vector<std::string> vec_p) {
  if (existe_usuario(id)) {
    try {
      usuarios[id].inscribir_curso(c, vec_p);
    } catch (const char* msg) {
      throw msg;
    }
  }
  else {
    throw "el usuario no existe";
  }
}

int Cjt_usuario::curso_actual(string id) {
  if (existe_usuario(id)) {
    return usuarios.find(id)->second.curso_actual();

  }
  else {
    throw "el usuario no existe";
  }
}

void Cjt_usuario::problemas_enviables(string id) {
  if (existe_usuario(id)) {
    try {
    usuarios.find(id)->second.f_problemas_enviables();
  } catch (const char* msg) {
      throw msg;
  }
  }
  else {
    throw "el usuario no existe";
  }
}

void Cjt_usuario::problemas_resueltos(string id) {
  if (existe_usuario(id)) {
    try {
    usuarios.find(id)->second.f_problemas_resueltos();
  } catch (const char* msg) {
      throw msg;
  }
  }
  else {
    throw "el usuario no existe";
  }
}

void Cjt_usuario::listar_usuarios() {
  for( auto it = usuarios.begin(); it != usuarios.end(); ++it ) {
    it->second.escribir_usuario();
  }
}

void Cjt_usuario::listar_usuario(string id) {
    if (existe_usuario(id)) {
      usuarios.find(id)->second.escribir_usuario();
    }
    else throw "el usuario no existe";
}

void Cjt_usuario::envio_user(string user, string p, int r, Cjt_problema& problemas, Cjt_curso& cursos, Cjt_sesion& sesiones) {
  usuarios.find(user)->second.envio( p,  r, problemas, cursos, sesiones);
}
