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
	long idCurso_;
	std::string nombre_;
	std::string descripcion_;
	std::list<Ponente> ponentes_;
	std::list<Usuario> usuarios_;
	clock_t fechaInicio_;
	clock_t fechaFinal_;
	bool estado_;
	int numeroAlumnos_;
	int aforo_;



public:
	Curso(int idCurso,std::string nombre,std::string descripcion,std::list<Ponente> ponentes, std::list<Usuario> usuarios,clock_t fechaInicio ,clock_t fechaFinal,bool estado,int numeroAlumnos,int aforo){
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

	}

	virtual ~Curso();


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

	clock_t getFechaFinal() const {
		return fechaFinal_;
	}

	void setFechaFinal(clock_t fechaFinal) {
		fechaFinal_ = fechaFinal;
	}

	clock_t getFechaInicio() const {
		return fechaInicio_;
	}

	void setFechaInicio(clock_t fechaInicio) {
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

	const std::list<Ponente>& getPonentes() const {
		return ponentes_;
	}

	void setPonentes(const std::list<Ponente> &ponentes) {
		ponentes_ = ponentes;
	}

	const std::list<Usuario>& getUsuarios() const {
			return usuarios_;
		}

	void setUsuarios(const std::list<Usuario> &usuarios) {
		usuarios_ = usuarios;
	}

	void darDeAlta(int idCurso);
	void darDeBaja(int idCurso);
	void editarCurso(int idCurso);
	void inscribirAlumno(int idCurso, int idUsuario);
	void borrarInscripcion(int idCurso, int idUsuario);
	std::list<Curso> verMisCursos(int idUsuario);
	void asignarPonentes(int idCurso, Ponente Ponente);
	void quitarPonentes(int idCurso, int idPonente);




};

#endif /* NEGOCIO_CURSO_CURSO_H_ */
