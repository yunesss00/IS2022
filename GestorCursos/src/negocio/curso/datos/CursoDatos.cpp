/*
 * CursoDatos.cpp
 *
 *  Created on: 6 dic 2022
 *      Author: youne
 */

#include "CursoDatos.h"
#include "../objeto/Curso.h"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <list>

std::string NOMBRE_FICHERO_CURSOS = "Cursos.txt";

CursoDatos::CursoDatos() {
	// TODO Auto-generated constructor stub

}



bool CursoDatos::insertar(Curso curso){
	std::ofstream fichero;
	fichero.open(NOMBRE_FICHERO_CURSOS.c_str(),std::ios::app);
	if (!fichero.is_open()) return false;
	else {
		fichero<<"IDCURSO:"<<curso.getIdCurso()<<"\n";
		fichero<<"NOMBRE:"<<curso.getNombre()<<"\n";
		fichero<<"DESCRIPCION:"<<curso.getDescripcion()<<"\n";
		fichero<<"FECHAINICIO:"<<curso.getFechaInicio()<<"\n";
		fichero<<"FECHAFINAL:"<<curso.getFechaFinal()<<"\n";
		std::string estado;
		if (curso.isEstado()) estado = "Activo";
		else estado = "Caducado";
		fichero<<"ESTADO:"<<estado<<"\n";
		fichero<<"NUMEROALUMNOS:"<<curso.getNumeroAlumnos()<<"\n";
		fichero<<"AFORO:"<<curso.getAforo()<<"\n";

		std::list<std::string> ponentes = curso.getPonentes();
		std::list<std::string> usuarios = curso.getUsuarios();

		if (ponentes.empty()){
			fichero<<"PONENTES: []";
		}else{
			fichero<<"PONENTES: [";
			for(std::string ponente: ponentes){
				fichero<<ponente<<",";
			}
			fichero<<"]\n";
		}
		if (usuarios.empty()){
			fichero<<"USUARIOS: []";
		}else{
			fichero<<"USUARIOS: [";
			for(std::string usuario: usuarios){
				fichero<<usuario<<",";
			}
			fichero<<"]\n";
		}
	}
	fichero.close();
	return true;
}

Curso CursoDatos::buscar(int idCurso) {
	Curso curso;
	return curso;
}

std::list<Curso> CursoDatos::lectura(){
	std::list<Curso> cursos;
	return cursos;
}

bool CursoDatos::modificar(Curso curso){
	return true;
}

bool CursoDatos::borrar(int idCurso){
	return true;
}

CursoDatos::~CursoDatos() {
	// TODO Auto-generated destructor stub
}

