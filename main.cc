/*
 * main.cc
 *
 *  Created on: 8 dic. 2021
 *      Author: Martin del Rio
 */

#include <iostream>
#include <string>
#include "maquina.h"
#include "reserva.h"
#include "usuario.h"

Usuario iniciarSesion();
void mostrarDisponibilidadMaquinas();
void altaUsuario();
void altaMaquina();

int main(){
	int opc;
	Usuario usuario = iniciarSesion();
	Maquina maq;
	Reserva reserva;

	if(usuario.getRol().compare("usuario") == 0){ // Si es igual a 0 son iguales
		do{
			cout << endl <<"Como usuario puede realizar las siguientes operaciones:\n\t1.Mostrar datos personales.\n\t2.Modificar datos personales(no disponible).\n\t3.Mostrar disponibilidad de maquinas.\n\t4.Realizar reserva.\n\t5.Borrar reserva(no disponible).\n\t0.Salir." << endl;
			cout << "Introduce una opcion: ";
			cin >> opc;
			cout << endl;

			switch(opc){
			case 1:
				//Mostrar datos personales
				cout << "\tSe van a mostrar sus datos personales." << endl;
				usuario.mostrarDatosPersonales();
				break;

			//Opcion a implementar opcional
			case 2:
				//Modificar datos personales
				cout << "\tEsta funcion no esta disponible." << endl;
				break;

			case 3:
				//Mostrar disponibilidad de maquinas
				cout << "\tSe va a mostrar la disponibilidad de las maquinas en el sistema." << endl;
				mostrarDisponibilidadMaquinas();
				break;

			case 4:
			{
				//Realizar reserva
				int IDmaquina;
				Maquina maq;

				cout << "\tSe va a realizar una reserva." << endl;
				cout << "\tAntes se va a mostrar la disponibilidad de las maquinas en el sistema." << endl;
				mostrarDisponibilidadMaquinas();

				cout << "\n\t\tIntroduce la ID de la maquina a reservar: ";
				cin >> IDmaquina;

				if(maq.getDatosByID(IDmaquina)){
					if(reserva.realizarReserva(usuario, maq)){
						cout << "\tReserva realizada." << endl;
					}
					else{
					cout << "\tNo se ha podido realizar la reserva." << endl;
					}
				}
			}
				break;

			case 5:
				//Borrar reserva
				cout << "\tEsta funcion no esta disponible." << endl;
				break;
			}
		}while(opc != 0);
	}else if(usuario.getRol().compare("adminUsuarios") == 0){
		do{
			cout << endl << "Como administrador de usuarios puede realizar las siguientes operaciones.\n\t1.Dar usuario de alta.\n\t2.Modificar datos de un usuario(no disponible).\n\t3.Ver datos de un usuario.\n\t4.Mostrar datos personales.\n\t0.Salir." << endl;
			cout << "Introduce una opcion: ";
			cin >> opc;

			switch(opc){
			case 1:
				//Dar usuario de alta
				cout << "\tSe va a dar de alta a un usuario." << endl;
				altaUsuario();
				break;

			//Opcion a implementar opcional
			case 2:
				//Modificar datos de un usuario
				cout << "\tEsta funcion no esta disponible.";
				break;

			case 3:
			{
				//Ver datos de un usuario
				string correo;
				Usuario us;

				cout << "\tSe van  a mostrar los datos de un usuario." << endl;
				cout << "\tIntroduzca el correo del usuario que quiere mostrar: ";
				cin >> correo;

				if(us.getDatosByEmail(correo)){
					cout << "\tUsuario encontrado, se van a mostrar sus datos." << endl;
					us.mostrarDatos(correo);
				}
				else{
					cout << "\tUsuario no encontrado." << endl;
				}
			}
				break;
			case 4:
			{
				//Mostrar datos personales
				cout << "\tSe van a mostrar sus datos personales." << endl;
				usuario.mostrarDatosPersonales();
			}
				break;
			}
		}while (opc != 0);
	}else if(usuario.getRol().compare("adminMaquinas") == 0){
		do{
			cout << endl << "Como administrador de maquinas puede realizar las siguientes operaciones.\n\t1.Aniadir maquinas al sistema.\n\t2.Modificar datos de una maquina(no disponible).\n\t3.Modificar reserva(no disponible).\n\t4.Ver datos de una maquina.\n\t5.Mostrar datos personales.\n\t0.Salir." << endl;
			cout << "Introduce una opcion: ";
			cin >> opc;

			switch(opc){
			case 1:
				//Aniadir maquinas al sistema
				cout << "\tSe va a aniadir una maquina al sistema." << endl;
				altaMaquina();
				break;

			//Opcion a implementar opcional
			case 2:
				//Modificar datos de una maquina
				cout << "\tEsta funcion no esta disponible.";
				break;

			case 3:
				//Modificar reserva
				cout << "\tEsta funcion no esta disponible.";
				break;

			case 4:
			{
				//Ver datos de una maquina
				int ID;
				Maquina maq;

				cout << "\tSe van  a mostrar los datos de una maquina." << endl;
				cout << "\tIntroduzca la ID de la maquina que quiere mostrar: ";
				cin >> ID;

				if(maq.getDatosByID(ID)){
					cout << "\tMaquina encontrada, se van a mostrar sus datos." << endl;
					maq.mostrarDatos(ID);
				}
			}
				break;

			case 5:
				//Mostrar datos personales
				cout << "\tSe van a mostrar sus datos personales." << endl;
				usuario.mostrarDatosPersonales();
				break;
			}
		}while(opc!=0);
	}
}

//Inicio de sesion si encuentra el correo en el fichero de usuario y el password es correcto
Usuario iniciarSesion() {
	string correo, password;
	Usuario us;

	cout << "Introduce un correo de la UCO(sin @uco.es): ";
	cin >> correo;
	cout << "Introduce una contrasenia: ";
	cin >> password;

	if(us.getDatosByEmail(correo)){
		if(password == us.getPassword())
			return us;
		else{
			cout << "\tLa contrasenia no corresponde con la del correo introducido." << endl;
			exit(-1);
		}
	}else{
		cout << "\tEl correo no pertenece a ningun usuario." << endl;
		exit(-1);
	}
}

//Recorre el fichero de maquinas y muestra los datos publicos de todas(ID_, tipoCluster_, limiteCPUs-numeroCPUs)
void mostrarDisponibilidadMaquinas(){
	string IDmaquina, tipoCluster, limiteCPUs, numeroCPUs;
	int limCPUs, numCPUs;
	string id, IDmaq, cad;

	ifstream fmaquinas("maquinas.txt");
	if (!fmaquinas)
		exit(-1);

	getline(fmaquinas, IDmaquina, ',');
	while (!fmaquinas.eof()){
		getline(fmaquinas, tipoCluster, ',');
		getline(fmaquinas, limiteCPUs, ',');
		limCPUs = stoi(limiteCPUs);
		getline(fmaquinas, numeroCPUs, '\n');
		numCPUs = stoi(numeroCPUs);

		bool encontrado=false;

		ifstream freservas("reservas.txt");
		if(!freservas)
			exit(-1);

		getline(freservas, IDmaq, ',');

		while(!freservas.eof()){
			if(IDmaquina.compare(IDmaq)==0){
				encontrado = true;
			}
			getline(freservas, cad, '\n');
			getline(freservas, IDmaq, ',');
		}
		freservas.close();

		if(!encontrado)
		cout << "\t\t-->ID: " << IDmaquina << "\tTipo de cluster: " << tipoCluster << "\tCPUs disponibles: " << limCPUs - numCPUs << endl;

		getline(fmaquinas, IDmaquina, ',');
	};
	fmaquinas.close();
}

//Pide los datos por pantalla y guarda el usuario en el fichero de usuarios
void altaUsuario(){
	string correo, DNI, password, nombre, apellidos, rol, limiteCPUs, limiteReservas, limiteTiempo, numeroCPUs, numeroReservas, numeroTiempo, telefono, edad;
	Usuario us;

	cout << "\tIntroduce los datos en el orden indicado." << endl;
	cout << "\t\tCorreo de la UCO (sin @uco.es): ";
	cin >> correo;
	cout << "\t\tDNI: ";
	cin >> DNI;
	cout << "\t\tContrasenia: ";
	cin >> password;
	cout << "\t\tLimite de CPUs: ";
	cin >> limiteCPUs;
	cout << "\t\tLimite de reservas: ";
	cin >> limiteReservas;
	cout << "\t\tLimite de tiempo: ";
	cin >> limiteTiempo;
	cout << "\t\tNumero de CPUs reservados: ";
	cin >> numeroCPUs;
	cout << "\t\tNumero de reservas actuales: ";
	cin >> numeroReservas;
	cout << "\t\tNumero de tiempo reservado: ";
	cin >> numeroTiempo;
	cout << "\t\tNombre: ";
	getline(cin, nombre);
	getline(cin, nombre);
	cout << "\t\tApellidos: ";
	getline(cin, apellidos);
	cout << "\t\tRol: ";
	cin >> rol;
	cout << "\t\tTelefono: ";
	cin >> telefono;
	cout << "\t\tEdad: ";
	cin >> edad;

	if(us.setDatos(correo, DNI, password, limiteCPUs, limiteReservas, limiteTiempo, numeroCPUs, numeroReservas, numeroTiempo, nombre, apellidos, rol, telefono, edad))
		cout << "\tUsuario dado de alta en el sistema." << endl;
	else
		cout << "\tNo se ha podido aniadir el usuario al sistema." << endl;
}

//Pide los datos por pantalla y guarda la maquina en el fichero de maquinas
void altaMaquina(){
	int ID, tipoCluster, limiteCPUs, numeroCPUs;
	Maquina maq;

	cout << "\tIntroduce los datos en el orden indicado." << endl;
	cout << "\t\tID: ";
	cin >> ID;
	cout << "\t\tTipo del cluster: ";
	cin >> tipoCluster;
	cout << "\t\tLimite de CPUs: ";
	cin >> limiteCPUs;
	cout << "\t\tNumero de CPUs reservadas: ";
	cin >> numeroCPUs;

	if(maq.setDatos(ID, tipoCluster, limiteCPUs, numeroCPUs))
		cout << "\tMaquina aniadida al sistema." << endl;
	else
		cout << "\tNo se ha podido aniadir la maquina al sistema." << endl;
}
