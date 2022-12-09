 include <iostream>
# include <string>
# include <ctime>
# include <iostream>
# include <cstdlib>
# include <cstdio>
# include <list>
# include "Curso.h"
# include "Usuario.h"
# include "CursoDatos.h"

using namespace std;

void llamada(int op){
	switch(op){
	case 1:	//cambiar contraseña
		Usuario::modificarClaveAcceso(dniUsuario, claveAcceso);
		break;

	case 2: //buscar cursos
		CursoDatos::buscar(idCurso);
		break;

	case 3:	//editar curso
		Curso::editarCurso(curso);
		break;

	case 4:	//ver participantes
		Usuario::verParticipantes(idCurso);
		break;

	case 5: //generar estadisticas

		break;

	case 6: //dar de alta un curso
		Curso::darDeAlta(curso);
		break;

	case 7:	//dar de baja un curso
		Curso::darDeBaja(idCurso);
		break;

	case 8:	//asignar ponentes
		Curso::asignarPonentes(idCurso, Ponente);
		break;

	case 9:	//quitar ponentes
		Curso::quitarPonentes(idCurso, idPonente);
		break;

	case 10://quitar recursos

		break;

	case 11://asignar recursos

		break;

	case 12://ver mis cursos
		Curso::verMisCursos(idUsuario);
		break;

	case 13://inscribirse a un curso
		Curso::inscribirAlumno(idCurso, idUsuario);
		break;

	case 14://abandonar inscripcion
		Curso::borrarInscripcion(idCurso, idUsuario);
		break;

	}
}


int main () {
	int op_inicio_sesion, usuario, opcion, op_def;
	string dni, clave, tipo_usuario;
	do{
		system("cls");
		cout << "1. Ver cursos como usuario invitado" << endl;
		cout << "2. Iniciar sesion" << endl;
		cin >> op_inicio_sesion;
		if (op_inicio_sesion != 1 and op_inicio_sesion != 2){
			cout << "Esa no es una opcion valida. Por favor elija de nuevo...";
			system("pause");
		}
	} while (op_inicio_sesion != 1 and op_inicio_sesion != 2);


	if(op_inicio_sesion == 1) {
		Curso::verMisCursos(0); //CAMBIAR
	}


	do{
		if(op_inicio_sesion == 2){
			cout << "Introduzca su dni: ";
			cin >> dni;
			cout << "Introduzca su clave: ";
			cin >> clave;
			tipo_usuario = Usuario::iniciarSesion(dni, clave);
			if(tipo_usuario == "INCORRECTO") cout << "La contraseña es incorrecta. Intentelo de nuevo." << endl;
		}
	}while (tipo_usuario == "INCORRECTO");


	if(tipo_usuario == "ADMINISTRADOR") usuario = 0;
	if(tipo_usuario == "GESTOR_RECURSOS") usuario = 1;
	if(tipo_usuario == "GESTOR_CURSOS") usuario = 2;
	if(tipo_usuario == "USUARIO_REGISTRADO") usuario = 3;


	opcion = 0;
	switch(usuario){
	case 0:
		do{
			system("cls");
			cout << "1. Cambiar contraseña" << endl;
			cout << "2. Buscar cursos" << endl;
			cout << "3. Editar curso" << endl;
			cout << "4. Ver participantes de un curso" << endl;
			cout << "5. Generar estadísticas de un curso" << endl;
			cout << "6. Dar de alta un curso" << endl;
			cout << "7. Dar de baja un curso" << endl;
			cout << "8. Asignar ponentes a un curso" << endl;
			cout << "9. Quitar ponentes de un curso" << endl;
			cout << "10. Quitar recursos de un curso" << endl;
			cout << "11. Asignar recursos a un curso" << endl;
			cin >> opcion;
			if(opcion<1 or opcion>11) cout << "La opcion elegida no es valida. Vuelva a elegir...";
			system("pause");
		}while(opcion<1 or opcion>11);
		op_def = opcion;
		llamada(op_def);
		break;

	case 1:
		do{
			system("cls");
			cout << "1. Cambiar contraseña" << endl;
			cout << "2. Buscar cursos" << endl;
			cout << "3. Quitar recursos de un curso" << endl;
			cout << "4. Asignar recursos a un curso" << endl;
			cin >> opcion;
			if(opcion<1 or opcion>4) cout << "La opcion elegida no es valida. Vuelva a elegir...";
			system("pause");
		}while(opcion<1 or opcion>4);
		if(opcion == 1 or opcion == 2) op_def = opcion;
		else op_def = opcion + 7;
		llamada(op_def);
		break;

	case 2:
		do{
			system("cls");
			cout << "1. Cambiar contraseña" << endl;
			cout << "2. Buscar cursos" << endl;
			cout << "3. Editar curso" << endl;
			cout << "4. Ver participantes de un curso" << endl;
			cout << "5. Generar estadísticas de un curso" << endl;
			cout << "6. Dar de alta un curso" << endl;
			cout << "7. Dar de baja un curso" << endl;
			cout << "8. Asignar ponentes a un curso" << endl;
			cout << "9. Quitar ponentes de un curso" << endl;
			cin >> opcion;
			if(opcion<1 or opcion>9) cout << "La opcion elegida no es valida. Vuelva a elegir...";
			system("pause");
		}while(opcion<1 or opcion>9);
		op_def = opcion;
		llamada(op_def);
		break;

	case 3:
		do{
			system("cls");
			cout << "1. Cambiar contraseña" << endl;
			cout << "2. Buscar cursos" << endl;
			cout << "3. Ver mis cursos" << endl;
			cout << "4. Inscribirse a un curso" << endl;
			cout << "5. Abandonar inscripcion a un curso" <<endl;
			cin >> opcion;
			if(opcion<1 or opcion>5) cout << "La opcion elegida no es valida. Vuelva a elegir...";
			system("pause");
		}while(opcion<1 or opcion>5);
		if(opcion == 1 or opcion == 2) op_def = opcion;
		else op_def = opcion + 9;
		llamada(op_def);
		break;
	}

return 0;
}
