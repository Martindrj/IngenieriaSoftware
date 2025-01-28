/*
 * Usuario.cpp
 *
 *  Created on: 6 dic. 2021
 *      Author: Martin del Rio
 */

#include "usuario.h"

#include <iostream>
#include <string>
#include <fstream>

//Constructor por defecto
Usuario::Usuario(){
	correo_ = "";
	DNI_ = "";
	password_ = "";
	limiteCPUs_ = 0;
	limiteReservas_ = 0;
	limiteTiempo_= 0;
	numeroCPUs_= 0;
	numeroReservas_ = 0;
	numeroTiempo_ = 0;
	nombre_ = "";
	apellidos_ = "";
	rol_ = "";
	telefono_ = 0;
	edad_ = 0;
}

//Constructor con parametros
Usuario::Usuario(string correo, string DNI, string password, int limiteCPUs, int limiteReservas, int limiteTiempo, int numeroCPUs, int numeroReservas, int numeroTiempo, string nombre, string apellidos, string rol, int telefono, int edad){
	correo_ = correo;
	DNI_ = DNI;
	password_ = password;
	limiteCPUs_ = limiteCPUs;
	limiteReservas_ = limiteReservas;
	limiteTiempo_= limiteTiempo;
	numeroCPUs_= numeroCPUs;
	numeroReservas_ = numeroReservas;
	numeroTiempo_ = numeroTiempo;
	nombre_ = nombre;
	apellidos_ = apellidos;
	rol_ = rol;
	telefono_ = telefono;
	edad_ = edad;
}

//Muestra por pantalla los datos personales del usuario
void Usuario::mostrarDatosPersonales(){
	cout << "\t\t-> Correo: " << correo_ << endl;
	cout << "\t\t-> DNI: " << DNI_ << endl;
	cout << "\t\t-> Contrasenia: " << password_ << endl;
	cout << "\t\t-> Nombre: " << nombre_ << endl;
	cout << "\t\t-> Apellidos: " << apellidos_ << endl;
	cout << "\t\t-> Rol: " << rol_ << endl;
	cout << "\t\t-> Telefono: " << telefono_ << endl;
	cout << "\t\t-> Edad: " << edad_ << endl << endl;
}

//Muestra por pantalla los datos del usuario
void Usuario::mostrarDatos(string correo){
	string email, DNI, password, limCPUs, limReservas, limTiempo, numCPUs, numReservas, numTiempo, nombre, apellidos, rol, telefono, edad;
	string cad;

	ifstream fusuarios("usuarios.txt");
		if(!fusuarios)
			exit(-1);

	getline(fusuarios, email, ',');

	while (!fusuarios.eof()){
		if((correo == email)){
			getline(fusuarios, DNI, ',');
			getline(fusuarios, password, ',');
			getline(fusuarios, limCPUs, ',');
			getline(fusuarios, limReservas , ',');
			getline(fusuarios, limTiempo, ',');
			getline(fusuarios, numCPUs, ',');
			getline(fusuarios, numReservas, ',');
			getline(fusuarios, numTiempo, ',');
			getline(fusuarios, nombre, ',');
			getline(fusuarios, apellidos, ',');
			getline(fusuarios, rol, ',');
			getline(fusuarios, telefono, ',');
			getline(fusuarios, edad, '\n');

			cout << "\t\t-> Correo: " << email << endl;
			cout << "\t\t-> DNI: " << DNI << endl;
			cout << "\t\t-> Contrasenia: " << password << endl;
			cout << "\t\t-> Limite CPUs: " << limCPUs << endl;
			cout << "\t\t-> Limite Reservas: " << limReservas << endl;
			cout << "\t\t-> Limite Tiempo: " << limTiempo << endl;
			cout << "\t\t-> Numero CPUs: " << numCPUs << endl;
			cout << "\t\t-> Numero Reservas: " << numReservas << endl;
			cout << "\t\t-> Numero Tiempo: " << numTiempo << endl;
			cout << "\t\t-> Nombre: " << nombre << endl;
			cout << "\t\t-> Apellidos: " << apellidos << endl;
			cout << "\t\t-> Rol: " << rol << endl;
			cout << "\t\t-> Telefono: " << telefono << endl;
			cout << "\t\t-> Edad: " << edad << endl;

			fusuarios.close();
		}
		getline(fusuarios, cad, '\n');
		getline(fusuarios, email, ',');
	}
	fusuarios.close();
}

//Permite crear un nuevo usuario y lo almacena en el fichero de usuarios
bool Usuario::setDatos(string correo, string DNI, string password, string limiteCPUs, string limiteReservas, string limiteTiempo, string numeroCPUs, string numeroReservas, string numeroTiempo, string nombre, string apellidos, string rol, string telefono, string edad){
	string cad;
	string nombreFichero;

	nombreFichero = "usuarios.txt";
	fstream fusuarios(nombreFichero.c_str(), fstream::in | fstream::out | fstream::app);
	if(fusuarios){
		fusuarios << correo + "," + DNI + "," + password + "," + limiteCPUs + "," + limiteReservas + "," + limiteTiempo + "," + numeroCPUs + "," + numeroReservas + "," + numeroTiempo + "," + nombre + "," + apellidos + "," + rol + "," + telefono + "," + edad + "\n";
		fusuarios.close();
		return true;
	}
	else{
		return false;
	}
}

//Recorre un fichero para buscar un usuario con el correo introducido
bool Usuario::getDatosByEmail(string correo){
	string email;
	string limCPUs, limReservas, limTiempo, numCPUs, numReservas, numTiempo, tel, edad;
	string cad;

	ifstream fusuarios("usuarios.txt");
	if(!fusuarios)
		exit(-1);

	getline(fusuarios, email, ',');

	while (!fusuarios.eof()){
		if((correo == email)){
			correo_ = email;
			getline(fusuarios, DNI_, ',');
			getline(fusuarios, password_, ',');
			getline(fusuarios, limCPUs, ',');
			limiteCPUs_ = stoi(limCPUs);
			getline(fusuarios, limReservas , ',');
			limiteReservas_ = stoi(limReservas);
			getline(fusuarios, limTiempo, ',');
			limiteTiempo_ = stof(limTiempo);
			getline(fusuarios, numCPUs, ',');
			numeroCPUs_ = stoi(numCPUs);
			getline(fusuarios, numReservas, ',');
			numeroReservas_ = stoi(numReservas);
			getline(fusuarios, numTiempo, ',');
			numeroTiempo_ = stof(numTiempo);
			getline(fusuarios, nombre_, ',');
			getline(fusuarios, apellidos_, ',');
			getline(fusuarios, rol_, ',');
			getline(fusuarios, tel, ',');
			telefono_ = stoi(tel);
			getline(fusuarios, edad, '\n');
			edad_ = stoi(edad);
			fusuarios.close();
			return true;
		}
		getline(fusuarios, cad, '\n');
		getline(fusuarios, email, ',');
	}
	fusuarios.close();
	return false;
}

//Comprueba que no sobrepasa los limites del usuario con nuevos valores
bool Usuario::comprobarLimites(Usuario us, int numeroCPUs, int numeroDias){
	int limiteCPUsUsuario, limiteReservasUsuario, limiteTiempoUsuario, numeroCPUsUsuario, numeroReservasUsuario, numeroTiempoUsuario;

	limiteCPUsUsuario = us.getLimiteCPUs();
	limiteReservasUsuario = us.getLimiteReservas();
	limiteTiempoUsuario = us.getLimiteTiempo();
	numeroCPUsUsuario = us.getNumeroCPUs();
	numeroReservasUsuario = us.getNumeroReservas();
	numeroTiempoUsuario = us.getNumeroTiempo();

	if(limiteCPUsUsuario>=(numeroCPUsUsuario+numeroCPUs)){
		if(limiteReservasUsuario>=(numeroReservasUsuario+1)){
			if(limiteTiempoUsuario>=(numeroTiempoUsuario+numeroDias)){
				return true;
			}
			else{
				cout << "\tSe ha sobrepasado el limite de tiempo que el usuario puede reservar." << endl << endl;
				return false;
			}
		}
		else{
			cout << "\tSe ha sobrepasado el limite de reservas que el usuario puede realizar." << endl << endl;
			return false;
		}
	}
	else{
		cout << "\tSe ha sobrepasado el limite de CPUs que el usuario puede reservar." << endl << endl;
		return false;
	}
}
