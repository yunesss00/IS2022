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
	return true;
}
bool UsuarioDatos::insertar(Usuario usuario){
	return true;
}

bool UsuarioDatos::modificar(Usuario usuario) {
	return true;
}

Usuario UsuarioDatos::buscar(std::string dni) {
	Usuario usuario;

	return usuario;
}

