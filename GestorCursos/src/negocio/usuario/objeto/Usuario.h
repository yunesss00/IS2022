/*
 * Usuario.h
 *
 *  Created on: 4 dic 2022
 *      Author: youne
 */

#ifndef NEGOCIO_USUARIO_OBJETO_USUARIO_H_
#define NEGOCIO_USUARIO_OBJETO_USUARIO_H_
#include <string>
#include <vector>
#include <ctime>
#include <iostream>
#include <cstdlib>
#include <list>
#include "../enum/TipoUsuario.cpp"

class Usuario {
private:
	std::string nombreCompleto_;
	std::string dni_;
	std::string correo_;
	std::string claveAcceso_;
	TipoUsuario tipoUsuario_;


public:
	Usuario(std::string nombreCompleto, std::string dni, std::string correo,std::string claveAcceso, TipoUsuario tipoUsuario){
		nombreCompleto_ = nombreCompleto;
		dni_ = dni;
		correo_ = correo;
		claveAcceso_ = claveAcceso;
		tipoUsuario_ = tipoUsuario;
	}


	virtual ~Usuario();

	const std::string& getCorreo() const {
		return correo_;
	}

	void setCorreo(const std::string &correo) {
		correo_ = correo;
	}

	const std::string& getDni() const {
		return dni_;
	}

	void setDni(const std::string &dni) {
		dni_ = dni;
	}

	const std::string& getNombreCompleto() const {
		return nombreCompleto_;
	}

	void setNombreCompleto(const std::string &nombreCompleto) {
		nombreCompleto_ = nombreCompleto;
	}

	std::list<Usuario> verParticipantes(int idCurso);

	TipoUsuario getTipoUsuario() const {
		return tipoUsuario_;
	}

	void setTipoUsuario(TipoUsuario tipoUsuario) {
		tipoUsuario_ = tipoUsuario;
	}

	void crearUsuario(Usuario usuario);
	void modificarClaveAcceso(int idUsuario, std::string claveAcceso);

	const std::string& getClaveAcceso() const {
		return claveAcceso_;
	}

	void setClaveAcceso(const std::string &claveAcceso) {
		claveAcceso_ = claveAcceso;
	}
};

#endif /* NEGOCIO_USUARIO_OBJETO_USUARIO_H_ */
