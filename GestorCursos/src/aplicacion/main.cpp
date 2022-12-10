#include <iostream>
# include <string>
# include <ctime>
# include <iostream>
# include <cstdlib>
# include <cstdio>
# include <list>
# include "../negocio/curso/objeto/Curso.h"
# include "../negocio/usuario/objeto/Usuario.h"
# include "../negocio/curso/datos/CursoDatos.h"

using namespace std;

void llamada(int op, int us){
	Usuario user;
	Curso cu;
	bool cambioClave, editarCurso, darAlta, darBaja, asigPonente, quitPonente, inscribirAl, borrarIns, estadoCurso;
	string dniUser, claveNueva, idPonente, idUsuario, nombreCurso, descripcionCurso, fechaIni, fechaFin;
	int estadistica, numAlumnos, aforoCurso, estCurso;
	long idCurso;
	std::list<string> usuariosCurso;
	std::list<string> ponentesCurso;
	switch(op){
	case 1:	//cambiar contraseña
		system("cls");
		cout << "Introduzca su dni: ";
		cin >> dniUser;
		cout >> "Introduzca la nueva clave: ";
		cin >> claveNueva;
		cambioClave = user.modificarClaveAcceso(dniUser, claveNueva);
		if (cambioClave) cout << "Se ha cambiado la contraseña con exito." << endl;
		else cout << "No se ha podido modificar la contraseña" << endl;
		system("pause");
		break;

	case 2: //buscar cursos
		system("cls");
		std::list<cu> cursosVigentes;
		std::list<cu> cursosCompletos;
		std::list<cu> iterator;
		std::list<cu> iterator2;
		if(us == 0 or us == 2){
			//mostrar cursos vigentes y no vigentes
		}else {
			cursosVigentes = cu.verCursosVigentes();
			iterator = cursosVigentes.begin();
			cout<<"Introduzca la ID del curso que quiere buscar: ";
			cin >> idCurso;
			system("cls");
			while(iterator != cursosVigentes.end()){
				if(cu.getIdCurso() == idCurso){
					nombreCurso = cu.getNombre();
					descripcionCurso = cu.getDescripcion();
					ponentesCurso = cu.getPonentes();
					iterator2 = ponentesCurso.begin();
					fechaIni = cu.getFechaInicio();
					fechaFin = cu.getFechaFinal();
					aforoCurso = cu.getAforo();
					cout << "Nombre: " << nombreCurso << endl;
					cout << "ID: " << idCurso << endl;
					cout << "Descripcion: " << descripcionCurso << endl;
					cout << "Ponentes: ";
					while(iterator2 != ponentesCurso.end()){
						cout << "Ponente " << iterator2 << ": " << iterator2.idPonente << endl;
						iterator2 ++;
					}
					cout << "Fecha de inicio: " << fechaIni << endl;
					cout << "Fecha de fin: " << fechaFin << endl;
					cout << "Aforo: " << aforoCurso << endl;

				}
				iterator ++;
			}
		}
		system("pause");

		break;

	case 3:	//editar curso
		system("cls");
		Curso cursoEditado;
		cout << "Introduzca la nueva ID: ";
		cin >> idCurso;
		cout << "Introduzca el nuevo nombre: ";
		cin >> nombreCurso;
		cout << "Introduzca la nueva descripcion: ";
		cin >> descripcionCurso;
		cout << "Introduzca el nuevo numero de alumnos: ";
		cin >> numAlumnos;
		cout << "Introduzca la nueva fecha de inicio: ";
		cin >> fechaIni;
		cout << "Introduzca la nueva fecha de finalizacion: ";
		cin >> fechaFin;
		cout << "Introduzca el nuevo aforo: ";
		cin >> aforoCurso;
		cursoEditado.setIdCurso(idCurso);
		cursoEditado.setNombre(nombreCurso);
		cursoEditado.setDescripcion(descripcionCurso);
		cursoEditado.setNumeroAlumnos(numAlumnos);
		cursoEditado.setFechaInicio(fechaIni);
		cursoEditado.setFechaFinal(fechaFin);
		cursoEditado.setAforo(aforoCurso);
		editarCurso = cu.editarCurso(cursoEditado);
		if (editarCurso) cout << "Se ha editado el curso con exito." << endl;
		else cout << "No se ha podido editar el curso." << endl;
		system("pause");
		break;

	case 4:	//ver participantes
		system("cls");
		std::list<cu> Listado;
		std::list<cu> iterator3;
		cout << "Introduzca la ID del curso: ";
		cin >> idCurso;
		Listado = cu.verListadoAlumnos(idCurso);
		iterator3 = Listado.begin();
		while(iterator3 != Listado.end()){
			cout << "Alumno " << iterator3 << ": " << iterator3.idUsuario << endl;
			iterator3 ++;
		}
		system("pause");
		break;

	case 5: //generar estadisticas
		system("cls");
		cout << "Introduzca la ID del curso: ";
		cin >> idCurso;
		estadistica = cu.generaEstadistica(idCurso);
		cout << "El porcentaje de ocupacion del curso es de " << estadistica << "%" <<endl;
		system("pause");
		break;

	case 6: //dar de alta un curso
		system("cls");
		cout << "Introduzca el nombre del curso: ";
		cin >> curso;
		darAlta = cu.darDeAlta(curso);
		if(darAlta) cout << "Curso creado con exito." << endl;
		else cout << "No se ha podido crear el curso" << endl;
		system("pause");
		break;

	case 7:	//dar de baja un curso
		system("cls");
		cout << "Introduzca la ID del curso: ";
		cin >> idCurso;
		darBaja = cu.darDeBaja(idCurso);
		if (darBaja) cout << "Se ha cambiado el estado del curso con exito." << endl;
		else cout << "No se ha podido cambiar el estado del curso." << endl;
		system("pause");
		break;

	case 8:	//asignar ponentes
		system("cls");
		cout << "Introduzca la ID del curso: ";
		cin >> idCurso;
		cout << "Introduzca la ID del ponente: ";
		cin >> idPonente;
		asigPonente = cu.asignarPonentes(idCurso, idPonente);
		if(asigPonente) cout << "Se ha asignado el ponente con exito." << endl;
		else cout << "No se ha podido asignar el ponente." << endl;
		system("pause");
		break;

	case 9:	//quitar ponentes
		system("cls");
		cout << "Introduzca la ID del curso: ";
		cin >> idCurso;
		cout << "Introduzca la ID del ponente: ";
		cin >> idPonente;
		quitPonente = cu.quitarPonentes(idCurso, idPonente);
		if(quitPonente) cout << "Se ha quitado al ponente con exito." << endl;
		else cout << "No se ha podido quitar el ponente." << endl;
		system("pause");
		break;

	case 10://quitar recursos

		break;

	case 11://asignar recursos

		break;

	case 12://ver mis cursos
		system("cls");
		std::list<cu> listaCursos;
		std::list<cu> iterator4;
		cout << "Introduzca la ID del usuario: ";
		cin >> idUsuario;
		listaCursos = cu.verMisCursos(idUsuario);
		iterator4 = listaCursos.begin();
		while(iterator4 != listaCursos.end()){
			cout<< "Curso " << iterator4 << ": " << iterator4.idCurso << endl;
			iterator4 ++;
		}
		system("pause");
		break;

	case 13://inscribirse a un curso
		system("cls");
		cout << "Introduzca la ID del curso: ";
		cin >> idCurso;
		cout << "Introduzca la ID del usuario: ";
		cin >> idUsuario;
		inscribirAl = cu.inscribirAlumno(idCurso, idUsuario);
		if(inscribirAl) cout << "Alumno inscrito con exito." << endl;
		else cout << "No se ha podido inscribir al alumno." << endl;
		system("pause");
		break;

	case 14://abandonar inscripcion
		system("cls");
		cout << "Introduzca la ID del curso: ";
		cin >> idCurso;
		cout << "Introduzca la ID del usuario: ";
		cin >> idUsuario;
		borrarIns = cu.borrarInscripcion(idCurso, idUsuario);
		if(borrarIns) cout << "Alumno borrado con exito." << endl;
		else cout << "No se ha podido borrar al alumno." << endl;
		system("pause");
		break;

	}
}


int main () {
	Curso curso;
	Usuario user;
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
		curso.verCursosVigentes(); //FALTA SACAR LA LISTA
	}


	do{
		if(op_inicio_sesion == 2){
			cout << "Introduzca su dni: ";
			cin >> dni;
			cout << "Introduzca su clave: ";
			cin >> clave;
			tipo_usuario = user.iniciarSesion(dni, clave);
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
		llamada(op_def, usuario);
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
		llamada(op_def, usuario);
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
		llamada(op_def, usuario);
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
		llamada(op_def, usuario);
		break;
	}

return 0;
}
