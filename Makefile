OPCIONES = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra  -Wno-sign-compare -std=c++11

program.exe: program.o Cjt_curso.o Cjt_sesion.o Cjt_usuario.o Cjt_problema.o Curso.o Sesion.o Usuario.o Problema.o
	g++ -o program.exe program.o Cjt_curso.o Cjt_sesion.o Cjt_usuario.o Cjt_problema.o Curso.o Sesion.o Usuario.o Problema.o

program.o: program.cc Cjt_curso.hh Cjt_sesion.hh Cjt_usuario.hh Cjt_problema.hh
	g++ -c program.cc $(OPCIONES)

Cjt_curso.o: Cjt_curso.cc Cjt_curso.hh Curso.hh Cjt_sesion.hh Sesion.hh Cjt_problema.hh Problema.hh
	g++ -c Cjt_curso.cc $(OPCIONES)


Curso.o: Curso.cc Curso.hh Cjt_sesion.hh Sesion.hh
	g++ -c Curso.cc $(OPCIONES)


Cjt_problema.o: Cjt_problema.cc Cjt_problema.hh Problema.hh
	g++ -c Cjt_problema.cc $(OPCIONES)


Problema.o: Problema.cc Problema.hh
	g++ -c Problema.cc $(OPCIONES)

Cjt_sesion.o: Cjt_sesion.cc Cjt_sesion.hh Sesion.hh
	g++ -c Cjt_sesion.cc $(OPCIONES)


Sesion.o: Sesion.cc Sesion.hh
	g++ -c Sesion.cc $(OPCIONES)


Cjt_usuario.o: Cjt_usuario.cc Cjt_usuario.hh Usuario.hh
	g++ -c Cjt_usuario.cc $(OPCIONES)


Usuario.o: Usuario.cc Usuario.hh Cjt_problema.hh
	g++ -c Usuario.cc $(OPCIONES)

clean:
	rm -f *.o
	rm -f *.exe

practica.tar: Makefile  program.cc Cjt_curso.cc Cjt_curso.hh Cjt_sesion.cc Cjt_sesion.hh Cjt_usuario.cc Cjt_usuario.hh Cjt_problema.cc Cjt_problema.hh Curso.cc Curso.hh Sesion.cc Sesion.hh Usuario.cc Usuario.hh Problema.cc Problema.hh
	tar -cvf practica.tar Makefile  program.cc Cjt_curso.cc Cjt_curso.hh Cjt_sesion.cc Cjt_sesion.hh Cjt_usuario.cc Cjt_usuario.hh Cjt_problema.cc Cjt_problema.hh Curso.cc Curso.hh Sesion.cc Sesion.hh Usuario.cc Usuario.hh Problema.cc Problema.hh
