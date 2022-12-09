# include <iostream>
# include <string>
#include <list>


using namespace std ;

int main () {
	int usuario, opcion;
	usuario = 0;
	while(usuario<1 or usuario>4){		//Elige el tipo de usuario y le salta su menú correspondiente
		system("cls");
		cout << "Elija el tipo de usuario: " << endl;
		cout << "	1. Usuario invitado" << endl;
		cout << "	2. Usuario registrado" << endl;
		cout << "	3. Gestor de recursos (Admin)" << endl;
		cout << "	4. Gestor de cursos (Admin)" << endl;
		cin >> usuario;
		if(usuario<1 or usuario>4){
			cout << "El tipo de usuario elegido no es correcto. Elija de nuevo." << endl;
			system("pause");
		}
	}
	opcion = 0;
	switch(usuario)
	{
	case 1:
		while(opcion!=1){
			system("cls");
			cout << "	1. Buscar cursos" <<endl;
			cin >> opcion;
			if(opcion!=1){
				cout << "La opcion elegida no se encuentra en el menu. Elija de nuevo." << endl;
				system("pause");
			}
		}
		//Aquí mandarle a la función que corresponda

		break;
	case 2:
		while(opcion<1 or opcion>7){
			system("cls");
			cout << "	1. Buscar cursos" <<endl;
			cout << "	2. Iniciar sesion" <<endl;
			cout << "	3. Cerrar sesion" <<endl;
			cout << "	4. Cambiar contraseña" <<endl;
			cout << "	5. Ver mis cursos" <<endl;
			cout << "	6. Inscribirse a un curso" <<endl;
			cout << "	7. Abandonar inscripción" <<endl;
			cin >> opcion;
			if(opcion<1 or opcion>7){
				cout << "La opcion elegida no se encuentra en el menu. Elija de nuevo." << endl;
				system("pause");
			}
		}
		//Hacer el switch con los 7 casos y las funciones
		switch(opcion){
		case 1:

			break;
		case 2:

			break;
		case 3:

			break;
		case 4:

			break;
		case 5:

			break;
		case 6:

			break;
		case 7:

			break;
		default:
			break;
		}
		break;
	case 3:
		while(opcion<1 or opcion>6){
			system("cls");
			cout << "	1. Buscar cursos" <<endl;
			cout << "	2. Iniciar sesión" <<endl;
			cout << "	3. Cerrar sesion" <<endl;
			cout << "	4. Cambiar contraseña" <<endl;
			cout << "	5. Quitar recursos" <<endl;
			cout << "	6. Asignar recursos" <<endl;
			cin >> opcion;
			if(opcion<1 or opcion>6){
				cout << "La opcion elegida no se encuentra en el menu. Elija de nuevo." << endl;
				system("pause");
			}
		}
		//Hacer el switch con los 6 casos y las funciones
		switch(opcion){
				case 1:

					break;
				case 2:

					break;
				case 3:

					break;
				case 4:

					break;
				case 5:

					break;
				case 6:

					break;
				default:
					break;
				}
		break;
	case 4:
		while(opcion<1 or opcion>10){
			system("cls");
			cout << "	1. Buscar cursos" <<endl;
			cout << "	2. Iniciar sesion" <<endl;
			cout << "	3. Cerrar sesion" <<endl;
			cout << "	4. Editar curso" <<endl;
			cout << "	5. Ver participantes de un curso" <<endl;
			cout << "	6. Generar estadísticas de un curso" <<endl;
			cout << "	7. Dar de alta un curso" <<endl;
			cout << "	8. Dar de baja un curso" <<endl;
			cout << "	9. Asignar ponentes" <<endl;
			cout << "	10. Quitar ponentes" <<endl;
			cin >> opcion;
			if(opcion<1 or opcion>10){
				cout << "La opcion elegida no se encuentra en el menu. Elija de nuevo." << endl;
				system("pause");
			}
		}
		//Hacer el switch con los 10 casos y las funciones
		switch(opcion){
				case 1:

					break;
				case 2:

					break;
				case 3:

					break;
				case 4:

					break;
				case 5:

					break;
				case 6:

					break;
				case 7:

					break;
				case 8:

					break;
				case 9:

					break;
				case 10:

					break;
				default:
					break;
				}
		break;
	default:

		break;
	}
return 0;
}
