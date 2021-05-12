#include <iostream>
#include <vector>
using namespace std;

#include "Cjt_problema.hh"
#include "Cjt_sesion.hh"
#include "Cjt_curso.hh"
#include "Cjt_usuario.hh"


int main() {
    Cjt_problema lista_problemas;
    //leemos y guardamos todos los problemas
    int n;
    //leemos y añadimos la cantidad de problemas a añadir a lista_problemas
    cin >> n;
    lista_problemas.leer_problemas(n);

    Cjt_sesion lista_sesiones;
    //leemos y añadimos la cantidad de sesiones a añadir a lista_sesones
    cin >> n;
    lista_sesiones.leer_sesiones(n);

    Cjt_curso lista_cursos;
    //leemos y añadimos la cantidad de cursos a añadir a lista_cursos
    cin >> n;
    lista_cursos.leer_cursos(n, lista_sesiones);


    Cjt_usuario lista_usuarios;
    //leemos y añadimos la cantidad de cursos a añadir a lista_usuarios
    cin >> n;
    lista_usuarios.leer_usuarios(n);

    string comando;
    //leemos el primer comando
    cin >> comando;
    while (comando != "fin") {
      if (comando == "nuevo_problema" or comando == "np") {
          string p; cin >> p;
          cout << '#' << comando << ' ' << p << endl;
          try {
              lista_problemas.anadir_problema(p);
              cout << lista_problemas.num_problemas() << endl;
          } catch (const char* msg) {
              cout << "error: " << msg << endl;
          }
      }
      if (comando == "nueva_sesion" or comando == "ns") {
          string s; cin >> s;
          cout << '#' << comando << ' ' << s << endl;
          try {
              lista_sesiones.anadir_sesion(s);
              cout << lista_sesiones.num_sesiones() << endl;
          } catch (const char* msg) {
              cout << "error: " << msg << endl;
          }
      }
      if (comando == "alta_usuario" or comando == "a") {
          string u; cin >> u;
          cout << '#' << comando << ' ' << u << endl;
          try {
              lista_usuarios.anadir_usuario(u);
              cout << lista_usuarios.num_usuarios() << endl;
          } catch (const char* msg) {
              cout << "error: " << msg << endl;
          }
      }
      if (comando == "baja_usuario" or comando == "b") {
          string u; cin >> u;
            cout << '#' << comando << ' ' << u << endl;
          try {
              lista_usuarios.eliminar_usuario(u, lista_cursos);
              cout << lista_usuarios.num_usuarios() << endl;
          } catch (const char* msg) {
              cout << "error: " << msg << endl;
          }
      }
      if (comando == "inscribir_curso" or comando == "i") {
          string u; int c; cin >> u >> c;
          cout << '#' << comando << ' ' << u << ' ' << c << endl;
          try {
               vector<string> s;
               s = lista_cursos.listar_sesiones(c);
               lista_sesiones.listar_primer_problema(s);
               lista_usuarios.inscribir_curso(u, c, s);
               lista_cursos.inscribir_usuario(c);
               cout << lista_cursos.num_inscritos(c) << endl;

          } catch (const char* msg) {
              cout << "error: " << msg << endl;
          }
      }
      if (comando == "curso_usuario" or comando == "cu") {
          string u; cin >> u;
          cout << '#' << comando << ' ' << u << endl;
          try {
               cout << lista_usuarios.curso_actual(u) << endl;
          } catch (const char* msg) {
              cout << "error: " << msg << endl;
          }
      }
      if (comando == "sesion_problema" or comando == "sp") {
          string p; int c; cin >> c >> p;
          cout << '#' << comando << ' ' << c << ' ' << p << endl;
          try {
               cout << lista_cursos.consultar_sesion_problema(p, c, lista_problemas) << endl;
          } catch (const char* msg) {
              cout << "error: " << msg << endl;
          }
      }
      if (comando == "problemas_resueltos" or comando == "pr") {
          string u; cin >> u;
          cout << '#' << comando << ' ' << u << endl;
          try {
               lista_usuarios.problemas_resueltos(u);
          } catch (const char* msg) {
              cout << "error: " << msg << endl;
          }
      }
      if (comando == "problemas_enviables" or comando == "pe") {
          string u; cin >> u;
          cout << '#' << comando << ' ' << u << endl;
          try {
               lista_usuarios.problemas_enviables(u);
          } catch (const char* msg) {
              cout << "error: " << msg << endl;
          }
      }
      if (comando == "listar_problemas" or comando == "lp") {
        cout << '#' << comando << endl;
          try {
            lista_problemas.listar_problemas();
          } catch (const char* msg) {
              cout << "error: " << msg << endl;
          }
      }
      if (comando == "escribir_problema" or comando == "ep") {
          string p; cin >> p;
          cout << '#' << comando << ' ' << p << endl;
          try {
            lista_problemas.listar_problema(p);
          } catch (const char* msg) {
              cout << "error: " << msg << endl;
          }
      }
      if (comando == "listar_sesiones" or comando == "ls") {
        cout << '#' << comando << endl;
          try {
              lista_sesiones.listar_sesiones();
          } catch (const char* msg) {
              cout << "error: " << msg << endl;
          }
      }
      if (comando == "escribir_sesion" or comando == "es") {
          string s; cin >> s;
          cout << '#' << comando << ' ' << s << endl;
          try {
            lista_sesiones.listar_sesion(s);
          } catch (const char* msg) {
              cout << "error: " << msg << endl;
          }
      }
      if (comando == "listar_cursos" or comando == "lc") {
        cout << '#' << comando << endl;
          try {
              lista_cursos.listar_cursos();
          } catch (const char* msg) {
              cout << "error: " << msg << endl;
          }
      }
      if (comando == "escribir_curso" or comando == "ec") {
          int c; cin >> c;
          cout << '#' << comando << ' ' << c << endl;
          try {
            lista_cursos.listar_curso(c);
          } catch (const char* msg) {
              cout << "error: " << msg << endl;
          }
      }
      if (comando == "listar_usuarios" or comando == "lu") {
        cout << '#' << comando << endl;
          try {
              lista_usuarios.listar_usuarios();
          } catch (const char* msg) {
              cout << "error: " << msg << endl;
          }
      }
      if (comando == "escribir_usuario" or comando == "eu") {
          string u; cin >> u;
          cout << '#' << comando << ' ' << u << endl;
          try {
            lista_usuarios.listar_usuario(u);
          } catch (const char* msg) {
              cout << "error: " << msg << endl;
          }
      }
      cin >> comando;
    }
}
