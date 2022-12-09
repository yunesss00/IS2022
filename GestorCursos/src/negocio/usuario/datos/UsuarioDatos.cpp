/*
 * UsuarioDatos.cpp
 *
 *  Created on: 8 dic 2022
 *      Author: youne
 */

#include "UsuarioDatos.h"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <list>
#include <cstring>
#include <vector>
#include <cstdio>
#include <cstring>

static std::string NOMBRE_FICHERO_USUARIOS = "Usuarios.txt";
static std::string NOMBRE_FICHERO_AUXILIAR = "FicheroAuxiliar.txt";

static std::string DNI = "DNI:";
static std::string NOMBRECOMPLETO = "NOMBRECOMPLETO:";
static std::string CORREO = "CORREO:";
static std::string CLAVEACCESO = "CLAVEACCESO:";
static std::string TIPOUSUARIO = "TIPOUSUARIO:";

UsuarioDatos::UsuarioDatos(){

}
UsuarioDatos::~UsuarioDatos() {

}

bool UsuarioDatos::existeUsuario(std::string dniUsuario){
	std::string lineaFichero;
	std::string usuarioBuscar = DNI + dniUsuario;
	std::fstream fichero;
	if (!fichero.is_open()) {
		fichero.open(NOMBRE_FICHERO_USUARIOS,std::ios::in);
		if(!fichero.is_open()) return false;
		else{
			while(getline(fichero,lineaFichero)) {
				if (lineaFichero==usuarioBuscar) {
					fichero.close();
					return true;
				}
			}
		}
	}
	return false;
}

bool UsuarioDatos::insertar(Usuario usuario){
	std::ofstream fichero;
	fichero.open(NOMBRE_FICHERO_USUARIOS.c_str(),std::ios::app);
	if (!fichero.is_open()) return false;
	else {
		fichero<<DNI<<usuario.getDni()<<"\n";
		fichero<<NOMBRECOMPLETO<<usuario.getNombreCompleto()<<"\n";
		fichero<<CORREO<<usuario.getCorreo()<<"\n";
		fichero<<CLAVEACCESO<<usuario.getClaveAcceso()<<"\n";
		fichero<<TIPOUSUARIO<<usuario.getTipoUsuario()<<"\n";
	}
	fichero.close();
	return true;
}

bool UsuarioDatos::modificar(Usuario usuario) {
	std::ifstream ficheroLectura;
		std::ofstream ficheroEscritura;
		std::string lineaFichero;

		if (!existeUsuario(usuario.getDni())) return false;
		else{
			if (!ficheroLectura.is_open()) {
				ficheroLectura.open(NOMBRE_FICHERO_USUARIOS,std::ios::in);
			}
			if (!ficheroEscritura.is_open()) {
				ficheroEscritura.open(NOMBRE_FICHERO_AUXILIAR,std::ios::app);
			}
			while (getline(ficheroLectura,lineaFichero)) {
				ficheroEscritura<<lineaFichero<<"\n";
				if (lineaFichero == usuario.getDni()) {
					getline(ficheroLectura,lineaFichero);
					getline(ficheroLectura,lineaFichero);
					getline(ficheroLectura,lineaFichero);
					getline(ficheroLectura,lineaFichero);
				}
			}
		}
		ficheroEscritura.close();
		ficheroLectura.close();
		std::remove("Usuarios.txt");
		std::rename("FicheroAuxiliar.txt","Usuarios.txt");
		insertar(usuario);
		return true;

}

Usuario UsuarioDatos::buscar(std::string dni) {
	Usuario usuario;
	TipoUsuario tipoUsuario;
	std::string lineaFichero;
	std::ifstream fichero;
	if (existeUsuario(dni)){
		fichero.open(NOMBRE_FICHERO_USUARIOS,std::ios::in);
		while(getline(fichero, lineaFichero)){
			if (lineaFichero==dni) {
				usuario.setDni(dni);
				getline(fichero, lineaFichero);
				lineaFichero = lineaFichero.substr(lineaFichero.find(":"));
				usuario.setNombreCompleto(lineaFichero);
				getline(fichero, lineaFichero);
				lineaFichero = lineaFichero.substr(lineaFichero.find(":"));
				usuario.setCorreo(lineaFichero);
				getline(fichero, lineaFichero);
				lineaFichero = lineaFichero.substr(lineaFichero.find(":"));
				usuario.setClaveAcceso(lineaFichero);
				getline(fichero, lineaFichero);
				lineaFichero = lineaFichero.substr(lineaFichero.find(":"));
				tipoUsuario = TipoUsuario::INCORRECTO;
				usuario.setTipoUsuario(tipoUsuario);
				if(lineaFichero =="USUARIO_INVITADO"){
					tipoUsuario = TipoUsuario::USUARIO_INVITADO;
					usuario.setTipoUsuario(tipoUsuario);
				}
				if (lineaFichero =="USUARIO_REGISTRADO"){
					tipoUsuario = TipoUsuario::USUARIO_REGISTRADO;
					usuario.setTipoUsuario(tipoUsuario);
				}
				if (lineaFichero =="GESTOR_RECURSOS"){
					tipoUsuario = TipoUsuario::GESTOR_RECURSOS;
					usuario.setTipoUsuario(tipoUsuario);
				}
				if (lineaFichero =="GESTOR_CURSOS"){
					tipoUsuario = TipoUsuario::GESTOR_CURSOS;
					usuario.setTipoUsuario(tipoUsuario);
				}
				if (lineaFichero =="ADMINISTRADOR"){
					tipoUsuario = TipoUsuario::ADMINISTRADOR;
					usuario.setTipoUsuario(tipoUsuario);
				}
			}
		}
	}
	fichero.close();
	return usuario;
}

