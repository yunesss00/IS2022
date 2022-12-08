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
#include <cstring>
#include <vector>
#include <cstdio>

static std::string NOMBRE_FICHERO_CURSOS = "Cursos.txt";
static std::string NOMBRE_FICHERO_AUXILIAR = "FicheroAuxiliar.txt";
static std::string IDCURSO = "IDCURSO:";
static std::string NOMBRE = "NOMBRE:";
static std::string DESCRIPCION = "DESCRIPCION:";
static std::string FECHAINICIO = "FECHAINICIO";
static std::string FECHAFINAL = "FECHAFINAL:";
static std::string ESTADO = "ESTADO:";
static std::string NUMEROALUMNOS = "NUMEROALUMNOS:";
static std::string AFORO = "AFORO:";
static std::string PONENTES = "PONENTES:";
static std::string USUARIOS = "USUARIOS:";


CursoDatos::CursoDatos() {
	// TODO Auto-generated constructor stub

}

std::list<std::string> split (std::string s, std::string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    std::string token;
    std::list<std::string> res;

    while ((pos_end = s.find (delimiter, pos_start)) != std::string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back (s.substr (pos_start));
    return res;
}


bool CursoDatos::insertar(Curso curso){
	std::ofstream fichero;
	fichero.open(NOMBRE_FICHERO_CURSOS.c_str(),std::ios::app);
	if (!fichero.is_open()) return false;
	else {
		fichero<<IDCURSO<<curso.getIdCurso()<<"\n";
		fichero<<NOMBRE<<curso.getNombre()<<"\n";
		fichero<<DESCRIPCION<<curso.getDescripcion()<<"\n";
		fichero<<FECHAINICIO<<curso.getFechaInicio()<<"\n";
		fichero<<FECHAFINAL<<curso.getFechaFinal()<<"\n";
		std::string estado;
		if (curso.isEstado()) estado = "Activo";
		else estado = "Caducado";
		fichero<<ESTADO<<estado<<"\n";
		fichero<<NUMEROALUMNOS<<curso.getNumeroAlumnos()<<"\n";
		fichero<<AFORO<<curso.getAforo()<<"\n";

		std::list<std::string> ponentes = curso.getPonentes();
		std::list<std::string> usuarios = curso.getUsuarios();

		if (ponentes.empty()){
			fichero<<PONENTES<<"[]";
		}else{
			fichero<<PONENTES<<"[";
			for(std::string ponente: ponentes){
				fichero<<ponente<<",";
			}
			fichero<<"]\n";
		}
		if (usuarios.empty()){
			fichero<<USUARIOS<<"[]";
		}else{
			fichero<<USUARIOS<<"[";
			for(std::string usuario: usuarios){
				fichero<<usuario<<",";
			}
			fichero<<"]\n";
		}
	}
	fichero.close();
	return true;
}

bool existeCurso(int idCurso) {

	std::string lineaFichero;
	std::string cursoBuscar = IDCURSO + std::to_string(idCurso);
	std::fstream fichero;
	if (!fichero.is_open()) {
		fichero.open(NOMBRE_FICHERO_CURSOS,std::ios::in);
		if(!fichero.is_open()) return false;
		else{
			while(getline(fichero,lineaFichero)) {
				if (lineaFichero==cursoBuscar) {
					fichero.close();
					return true;
				}
			}
		}
	}
	return false;
}

Curso CursoDatos::buscar(int idCurso) {
	Curso curso;
	std::string lineaFichero;
	std::ifstream fichero;
	if (existeCurso(idCurso)){
		fichero.open(NOMBRE_FICHERO_CURSOS,std::ios::in);
		while(getline(fichero, lineaFichero)){
			if (lineaFichero==std::to_string(idCurso)) {
				curso.setIdCurso(idCurso);
				lineaFichero = lineaFichero.substr(lineaFichero.find(":"));
				curso.setNombre(lineaFichero);
				getline(fichero, lineaFichero);
				lineaFichero = lineaFichero.substr(lineaFichero.find(":"));
				curso.setDescripcion(lineaFichero);
				getline(fichero, lineaFichero);
				lineaFichero = lineaFichero.substr(lineaFichero.find(":"));
				curso.setFechaInicio(lineaFichero);
				getline(fichero, lineaFichero);
				lineaFichero = lineaFichero.substr(lineaFichero.find(":"));
				curso.setFechaFinal(lineaFichero);
				getline(fichero, lineaFichero);
				lineaFichero = lineaFichero.substr(lineaFichero.find(":"));
				curso.setFechaFinal(lineaFichero);
				getline(fichero, lineaFichero);
				lineaFichero = lineaFichero.substr(lineaFichero.find(":"));
				curso.setFechaFinal(lineaFichero);
				getline(fichero, lineaFichero);
				lineaFichero = lineaFichero.substr(lineaFichero.find(":"));
				curso.setFechaFinal(lineaFichero);
				getline(fichero, lineaFichero);
				lineaFichero = lineaFichero.substr(lineaFichero.find(":"));
				curso.setFechaFinal(lineaFichero);
				getline(fichero, lineaFichero);
				lineaFichero = lineaFichero.substr(lineaFichero.find("["),lineaFichero.find("]"));
				curso.setPonentes(split(lineaFichero, ","));
				getline(fichero, lineaFichero);
				lineaFichero = lineaFichero.substr(lineaFichero.find("["),lineaFichero.find("]"));
				curso.setPonentes(split(lineaFichero, ","));
			}
		}
	}
	fichero.close();
	return curso;
}

std::list<Curso> CursoDatos::lectura(){
	std::list<Curso> cursos;
	std::string lineaFichero;
	std::ifstream fichero;
	Curso cursoAux;
	if (!fichero.is_open()) {
		fichero.open(NOMBRE_FICHERO_CURSOS,std::ios::in);
	}
	while(getline(fichero, lineaFichero)){
		lineaFichero = lineaFichero.substr(lineaFichero.find(":"));
		cursoAux.setIdCurso(std::stol(lineaFichero));
		getline(fichero, lineaFichero);
		lineaFichero = lineaFichero.substr(lineaFichero.find(":"));
		cursoAux.setNombre(lineaFichero);
		getline(fichero, lineaFichero);
		lineaFichero = lineaFichero.substr(lineaFichero.find(":"));
		cursoAux.setDescripcion(lineaFichero);
		getline(fichero, lineaFichero);
		lineaFichero = lineaFichero.substr(lineaFichero.find(":"));
		cursoAux.setFechaInicio(lineaFichero);
		getline(fichero, lineaFichero);
		lineaFichero = lineaFichero.substr(lineaFichero.find(":"));
		cursoAux.setFechaFinal(lineaFichero);
		getline(fichero, lineaFichero);
		lineaFichero = lineaFichero.substr(lineaFichero.find(":"));
		cursoAux.setFechaFinal(lineaFichero);
		getline(fichero, lineaFichero);
		lineaFichero = lineaFichero.substr(lineaFichero.find(":"));
		cursoAux.setFechaFinal(lineaFichero);
		getline(fichero, lineaFichero);
		lineaFichero = lineaFichero.substr(lineaFichero.find(":"));
		cursoAux.setFechaFinal(lineaFichero);
		getline(fichero, lineaFichero);
		lineaFichero = lineaFichero.substr(lineaFichero.find(":"));
		cursoAux.setFechaFinal(lineaFichero);
		getline(fichero, lineaFichero);
		lineaFichero = lineaFichero.substr(lineaFichero.find("["),lineaFichero.find("]"));
		cursoAux.setPonentes(split(lineaFichero, ","));
		getline(fichero, lineaFichero);
		lineaFichero = lineaFichero.substr(lineaFichero.find("["),lineaFichero.find("]"));
		cursoAux.setPonentes(split(lineaFichero, ","));
		cursos.push_back(cursoAux);
	}
	fichero.close();
	return cursos;
}

bool CursoDatos::modificar(Curso curso){
	std::ifstream ficheroLectura;
	std::ofstream ficheroEscritura;
	std::string lineaFichero;

	if (!existeCurso(curso.getIdCurso())) return false;
	else{
		if (!ficheroLectura.is_open()) {
			ficheroLectura.open(NOMBRE_FICHERO_CURSOS,std::ios::in);
		}
		if (!ficheroEscritura.is_open()) {
			ficheroEscritura.open(NOMBRE_FICHERO_AUXILIAR,std::ios::app);
		}
		while (getline(ficheroLectura,lineaFichero)) {
			ficheroEscritura<<lineaFichero<<"\n";
			if (lineaFichero == std::to_string(curso.getIdCurso())) {
				getline(ficheroLectura,lineaFichero);
				getline(ficheroLectura,lineaFichero);
				getline(ficheroLectura,lineaFichero);
				getline(ficheroLectura,lineaFichero);
				getline(ficheroLectura,lineaFichero);
				getline(ficheroLectura,lineaFichero);
				getline(ficheroLectura,lineaFichero);
				getline(ficheroLectura,lineaFichero);
				getline(ficheroLectura,lineaFichero);
			}
		}
	}
	ficheroEscritura.close();
	ficheroLectura.close();
	std::remove("Cursos.txt");
	std::rename("FicheroAuxiliar.txt","Cursos.txt");
	insertar(curso);
	return true;
}

bool CursoDatos::borrar(int idCurso){
	//No se borran cursos
	return true;
}

CursoDatos::~CursoDatos() {
	// TODO Auto-generated destructor stub
}

