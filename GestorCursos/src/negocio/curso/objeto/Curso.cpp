/*
 * Curso.cpp
 *
 *  Created on: 3 dic 2022
 *      Author: youne
 */

#include "Curso.h"
#include "../../usuario/objeto/Usuario.h"
#include "../datos/CursoDatos.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <list>
#include <fstream>
#include <ctime>
#include <vector>
#include <cstring>
#include <iterator>

CursoDatos cursoDatos;


bool Curso::darDeAlta(Curso curso){
	if (cursoDatos.insertar(curso)) return true;
	else return false;
}


bool Curso::darDeBaja(int idCurso){
	if (cursoDatos.borrar(idCurso)) return true;
		else return false;
}

bool Curso::editarCurso(Curso curso){
	if (cursoDatos.modificar(curso)) return true;
			else return false;
}

bool Curso::inscribirAlumno(int idCurso, std::string idUsuario){
	Curso curso = cursoDatos.buscar(idCurso);
	std::list<std::string> usuarios = curso.getUsuarios();
	usuarios.push_back(idUsuario);
	curso.setUsuarios(usuarios);

	if (cursoDatos.modificar(curso)) return true;
	else return false;
}

bool Curso::borrarInscripcion(int idCurso, std::string idUsuario) {
	Curso curso = cursoDatos.buscar(idCurso);
	std::list<std::string> usuarios = curso.getUsuarios();
	for (std::string usuario: usuarios) {
		if (usuario == idUsuario){
			usuarios.remove(idUsuario);
		}
	}
	curso.setUsuarios(usuarios);

	if (cursoDatos.modificar(curso)) return true;
		else return false;
}

std::list<Curso> Curso::verMisCursos (std::string idUsuario){
	std::list<Curso> listadoCompletoCursos = cursoDatos.lectura();
	std::list<Curso> listadoMisCursos;
	for (Curso curso: listadoCompletoCursos) {
		std::list<std::string> usuarios = curso.getUsuarios();
		for (std::string usuario:usuarios){
			if (usuario == idUsuario){
				listadoMisCursos.push_back(curso);
			}
		}
	}
	return listadoMisCursos;
}

bool Curso::asignarPonentes(int idCurso, std::string idPonente){
	Curso curso = cursoDatos.buscar(idCurso);
	std::list<std::string> ponentes = curso.getPonentes();
	ponentes.push_back(idPonente);
	curso.setPonentes(ponentes);

	if (cursoDatos.modificar(curso)) return true;
	else return false;
}

bool Curso::quitarPonentes(int idCurso, std::string idPonente){
	Curso curso = cursoDatos.buscar(idCurso);
		std::list<std::string> ponentes = curso.getUsuarios();
		for (std::string ponente: ponentes) {
			if (ponente == idPonente){
				ponentes.remove(idPonente);
			}
		}
		curso.setPonentes(ponentes);

		if (cursoDatos.modificar(curso)) return true;
			else return false;
}


