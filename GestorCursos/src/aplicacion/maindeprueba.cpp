#include <iostream>
#include <cstdlib>
#include <string>
#include "../negocio/curso/objeto/Curso.h"
#include "../negocio/usuario/objeto/Usuario.h"
#include "../negocio/usuario/enum/TipoUsuario.h"

using namespace std;

int main(){
	int opcion = 0;




	//system("clear");
	cout<<endl;
	cout<<"\t ___________________________________________________"<<endl;
	cout<<"\t|                                                   |"<<endl;
	cout<<"\t|               ______CURSOS______                  |"<<endl;
	cout<<"\t|  -----------------------------------------------  |"<<endl;
	cout<<"\t|       1.iniciarSesion.                            |"<<endl;
	cout<<"\t|       2.crearUsuario.                             |"<<endl;
	cout<<"\t|       3.modificarClaveAcceso.                     |"<<endl;
	cout<<"\t|       4.modificarUsuario.                         |"<<endl;
	cout<<"\t|       5.verParticipantes.                         |"<<endl;
	cout<<"\t|       6.darDeAlta.                                |"<<endl;
	cout<<"\t|       7.darDeBaja.                                |"<<endl;
	cout<<"\t|       8.editarCurso.                              |"<<endl;
	cout<<"\t|       9.inscribirAlumno.                          |"<<endl;
	cout<<"\t|       10.borrarInscripcion.                       |"<<endl;
	cout<<"\t|       11.verMisCursos.                            |"<<endl;
	cout<<"\t|       12.verCursosVigentes.                       |"<<endl;
	cout<<"\t|       13.asignarPonentes.                         |"<<endl;
	cout<<"\t|       14.quitarPonentes.                          |"<<endl;
	cout<<"\t|       15.verListadoAlumnos.                       |"<<endl;
	cout<<"\t|___________________________________________________|"<<endl;

	if(opcion == 1) {
		Usuario usuario;
		TipoUsuario tipo = usuario.iniciarSesion("46074411Y", "yunes00");
		cout<<"breakpoint";
	}


	if(opcion == 2) {

		Usuario usuario("Youness Bettahi Berdai", "46074411Y", "i82bebey@uco.es", "yunes00" ,TipoUsuario::ADMINISTRADOR);
		bool res = usuario.crearUsuario(usuario);
		cout<<"breakpoint";
	}

	if(opcion == 3) {
		Usuario usuario;
		bool res = usuario.modificarClaveAcceso ("46074411Y", "claveCambiada");
		cout<<"breakpoint";
	}

	if(opcion == 4) {
		Usuario usuario("CAMBIADO CAMBIADO CAMBIADO", "46074411Y", "MODIFICADO", "MODIFICADO" ,TipoUsuario::USUARIO_REGISTRADO);
		bool res = usuario.modificarUsuario(usuario);
		cout<<"breakpoint";
	}
	//HASTA AQUÍ FUNCIONE
	//opcion = 5;
	if(opcion == 5) {
		Curso curso;
		list<string> lista = curso.verListadoAlumnos(1);
		cout<<"breakpoint";
	}

	//opcion = 6;
	if(opcion == 6) {
		list<string> usuarios;
		usuarios.push_back("46074411Y");
		usuarios.push_back("11111111A");
		string uno = "curso de yunes";
		string dos = "este es un curso de yunes";
		string tres = "fecha1";
		string cuatro = "fecha2";
		Curso curso(2,uno,dos,usuarios,usuarios,tres ,cuatro,false,50,100);

		bool res = curso.darDeAlta(curso);
		cout<<"breakpoint";
	}

	//opcion = 7;
	if(opcion == 7) {
		Curso curso;
		bool res = curso.darDeBaja(1);
		cout<<"breakpoint";
	}
	//opcion = 8;
	if(opcion ==8) {
		list<string> usuarios;
		usuarios.push_back("modificado");
		usuarios.push_back("modificado");
		Curso curso(1,"MODIFICADO","MODIFICADO",usuarios,usuarios,"20/12/2022" ,"25/12/2022",true,15,30);
		bool res = curso.editarCurso(curso);
		cout<<"breakpoint";
	}
	//opcion = 9;
	if(opcion == 9) {
		Curso curso;
		bool res = curso.inscribirAlumno(1,"YUNES");
		cout<<"breakpoint";
	}
	opcion = 10;
	if(opcion == 10) {
		Curso curso;
		bool res = curso.borrarInscripcion(1,"YUNES");
		cout<<"breakpoint";
	}
	//opcion = 11;
	if(opcion == 11) {
		Curso curso;
		list<Curso> cursos = curso.verMisCursos("46074411Y");
		for (Curso curso :cursos) {
			cout<<"\n"<<curso.getIdCurso()<<endl;
			cout<<curso.getNombre()<<endl;
			cout<<curso.getDescripcion()<<endl;
			cout<<curso.getFechaInicio()<<endl;
			cout<<curso.getFechaFinal()<<endl;
			cout<<curso.getAforo()<<endl;
			cout<<curso.getNumeroAlumnos()<<endl;
			list<string> listaPonentes = curso.getPonentes();
			list<string> listaUsuarios = curso.getUsuarios();
			int i= 0;
			int x= 0;
			for (string ponente: listaPonentes) {
				cout<<i<<ponente<<endl;
				i++;
			}
			for (string usy: listaUsuarios) {
				cout<<x<<usy<<endl;
				x++;
			}
		}
		cout<<"breakpoint";
	}
	//opcion = 12;
	if(opcion == 12) {
		Curso curso;
		list<Curso> cursos = curso.verCursosVigentes();
		for (Curso curso :cursos) {
			cout<<"\n"<<curso.getIdCurso()<<endl;
			cout<<curso.getNombre()<<endl;
			cout<<curso.getDescripcion()<<endl;
			cout<<curso.getFechaInicio()<<endl;
			cout<<curso.getFechaFinal()<<endl;
			cout<<curso.getAforo()<<endl;
			cout<<curso.getNumeroAlumnos()<<endl;
			list<string> listaPonentes = curso.getPonentes();
			list<string> listaUsuarios = curso.getUsuarios();
			int i= 0;
			int x= 0;
			for (string ponente: listaPonentes) {
				cout<<i<<ponente<<endl;
				i++;
			}
			for (string usy: listaUsuarios) {
				cout<<x<<usy<<endl;
				x++;
			}
		}
		cout<<"breakpoint";
	}
	//opcion = 13;
	if(opcion == 13) {
		Curso curso;
		bool res = curso.asignarPonentes(1,"PONENTEASIGNADO");
		list<string> listaPonentes = curso.getPonentes();
		int i= 0;

		cout<<"breakpoint";
	}
	//opcion = 14;
	if(opcion == 14) {
		Curso curso;
		bool res = curso.quitarPonentes(1,"aa");
		cout<<"breakpoint";
	}
	//opcion = 15;
	if(opcion == 15) {
		Curso curso;
		list<string> listado = curso.verListadoAlumnos(1);
		for(string alu :listado) {
			cout<<alu<<endl;
		}
		cout<<"breakpoint";
	}
	//opcion = 16;
	if (opcion == 16) {
		Curso curso;
		int estadisticas = curso.generaEstadistica(1);
		cout<<estadisticas<<endl;
	}





	return 0;
}
