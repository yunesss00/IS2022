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

std::string NOMBRE_FICHERO_CURSOS = "Cursos.txt";
std::string IDCURSO = "IDCURSO:";
std::string NOMBRE = "NOMBRE:";
std::string DESCRIPCION = "DESCRIPCION:";
std::string FECHAINICIO = "FECHAINICIO";
std::string FECHAFINAL = "FECHAFINAL:";
std::string ESTADO = "ESTADO:";
std::string NUMEROALUMNOS = "NUMEROALUMNOS:";
std::string AFORO = "AFORO:";
std::string PONENTES = "PONENTES:";
std::string USUARIOS = "USUARIOS:";


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
	std::fstream fichero;
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
	std::fstream fichero;
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

