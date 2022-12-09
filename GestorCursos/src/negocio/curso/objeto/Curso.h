/*
 * Curso.h
 *
 *  Created on: 3 dic 2022
 *      Author: youne
 */

#ifndef NEGOCIO_CURSO_CURSO_H_
#define NEGOCIO_CURSO_CURSO_H_
#include <string>
#include <list>
#include <ctime>
#include <iostream>
#include <cstdlib>
#include <vector>
#include "../../ponente/objeto/Ponente.h"
#include "../../usuario/objeto/Usuario.h"


class Curso {

private:
	long idCurso_ = 0;
	std::string nombre_ = "";
	std::string descripcion_ = "";
	std::list<std::string> ponentes_ = {};
	std::list<std::string> usuarios_ = {};
	std::string fechaInicio_ = 0;
	std::string fechaFinal_ = 0;
	bool estado_ = false;
	int numeroAlumnos_ = 0;
	int aforo_ = 0;



public:
	Curso() = default;
	Curso(int idCurso,std::string nombre,std::string descripcion,std::list<std::string> ponentes, std::list<std::string> usuarios,std::string fechaInicio ,std::string fechaFinal,bool estado,int numeroAlumnos,int aforo){
		idCurso_ = idCurso;
		nombre_ = nombre;
		descripcion_ = descripcion;
		ponentes_ = ponentes;
		fechaInicio_ = fechaInicio;
		fechaFinal_ = fechaFinal;
		estado_ = estado;
		numeroAlumnos_ = numeroAlumnos;
		aforo_ = aforo;
		usuarios_ = usuarios;

	};



	int getAforo() const {
		return aforo_;
	}

	void setAforo(int aforo) {
		aforo_ = aforo;
	}

	const std::string& getDescripcion() const {
		return descripcion_;
	}

	void setDescripcion(const std::string &descripcion) {
		descripcion_ = descripcion;
	}

	bool isEstado() const {
		return estado_;
	}

	void setEstado(bool estado) {
		estado_ = estado;
	}

	std::string getFechaFinal() const {
		return fechaFinal_;
	}

	void setFechaFinal(std::string fechaFinal) {
		fechaFinal_ = fechaFinal;
	}

	std::string getFechaInicio() const {
		return fechaInicio_;
	}

	void setFechaInicio(std::string fechaInicio) {
		fechaInicio_ = fechaInicio;
	}

	long getIdCurso() const {
		return idCurso_;
	}

	void setIdCurso(long idCurso) {
		idCurso_ = idCurso;
	}

	const std::string& getNombre() const {
		return nombre_;
	}

	void setNombre(const std::string &nombre) {
		nombre_ = nombre;
	}

	int getNumeroAlumnos() const {
		return numeroAlumnos_;
	}

	void setNumeroAlumnos(int numeroAlumnos) {
		numeroAlumnos_ = numeroAlumnos;
	}

	const std::list<std::string>& getPonentes() const {
		return ponentes_;
	}

	void setPonentes(const std::list<std::string> &ponentes) {
		ponentes_ = ponentes;
	}

	const std::list<std::string>& getUsuarios() const {
			return usuarios_;
		}

	void setUsuarios(const std::list<std::string> &usuarios) {
		usuarios_ = usuarios;
	}

	bool darDeAlta(Curso curso);
	bool darDeBaja(int idCurso);
	bool editarCurso(Curso curso);
	bool inscribirAlumno(int idCurso, std::string idUsuario);
	bool borrarInscripcion(int idCurso, std::string idUsuario);
	std::list<Curso> verMisCursos(std::string idUsuario);
	std::list<Curso> verCursosVigentes();
	bool asignarPonentes(int idCurso, std::string Ponente);
	bool quitarPonentes(int idCurso, std::string idPonente);
	std::list<std::string> verListadoAlumnos(int idCurso);




};

#endif /* NEGOCIO_CURSO_CURSO_H_ */
