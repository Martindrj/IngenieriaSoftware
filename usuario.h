/*
 * Usuario.h
 *
 *  Created on: 6 dic. 2021
 *      Author: Martin del Rio
 */

#ifndef USUARIO_H_
#define USUARIO_H_

#include <iostream>
#include <string>

using namespace std;

class Usuario{
private:
	string correo_;
	string DNI_;
	string password_;
	int limiteCPUs_;
	int limiteReservas_;
	int limiteTiempo_;
	int numeroCPUs_;
	int numeroReservas_;
	int numeroTiempo_;
	string nombre_;
	string apellidos_;
	string rol_;
	int telefono_;
	int edad_;

public:
	Usuario();
	Usuario(string correo, string DNI, string password, int limiteCPUs, int limiteReservas, int limiteTiempo, int numeroCPUs = 0, int numeroReservas = 0, int numeroTiempo = 0, string nombre = "", string apellidos = "", string rol = "", int telefono = 0, int edad = 0);

	//Muestra por pantalla los datos personales del usuario
	void mostrarDatosPersonales();
	//Muestra por pantalla los datos del usuario
	void mostrarDatos(string correo);
	//Permite crear un nuevo usuario y lo almacena en el fichero de usuarios
	bool setDatos(string correo, string DNI, string password, string limiteCPUs, string limiteReservas, string limiteTiempo, string numeroCPUs, string numeroReservas, string numeroTiempo, string nombre, string apellidos, string rol, string telefono, string edad);
	//Recorre un fichero para buscar un usuario con el correo introducido
	bool getDatosByEmail(string correo);
	//Comprueba que no sobrepasa los limites del usuario con nuevos valores
	bool comprobarLimites(Usuario us, int numeroCPUs, int numeroDias);
	
	//Funciones setters
	inline void setCorreo(string correo){correo_ = correo;};
	inline void setDNI(string DNI){DNI_ = DNI;};
	inline void setPassword(string password){password_ = password;};
	inline void setLimiteCPUs(int limiteCPUs){limiteCPUs_ = limiteCPUs;};
	inline void setLimiteReservas(int limiteReservas){limiteReservas_ = limiteReservas;};
	inline void setLimiteTiempo(int limiteTiempo){limiteTiempo_ = limiteTiempo;};
	inline void setNumeroCPUs(int numeroCPUs){numeroCPUs_ = numeroCPUs;};
	inline void setNumeroReservas(int numeroReservas){numeroReservas_ = numeroReservas;};
	inline void setNumeroTiempo(int numeroTiempo){numeroTiempo_ = numeroTiempo;};
	inline void setNombre(string nombre){nombre_ = nombre;};
	inline void setApellidos(string apellidos){apellidos_ = apellidos;};
	inline void setRol(string rol){rol_ = rol;};
	inline void setTelefono(int telefono){telefono_ = telefono;};
	inline void setEdad(int edad){edad_ = edad;};

	//Funciones getters
	inline string getCorreo()const{return correo_;};
	inline string getDNI()const{return DNI_;};
	inline string getPassword()const{return password_;};
	inline int getLimiteCPUs()const{return limiteCPUs_;};
	inline int getLimiteReservas()const{return limiteReservas_;};
	inline int getLimiteTiempo()const{return limiteTiempo_;};
	inline int getNumeroCPUs()const{return numeroCPUs_;};
	inline int getNumeroReservas()const{return numeroReservas_;};
	inline int getNumeroTiempo()const{return numeroTiempo_;};
	inline string getNombre()const{return nombre_;};
	inline string getApellidos()const{return apellidos_;};
	inline string getRol()const{return rol_;};
	inline int getTelefono()const{return telefono_;};
	inline int getEdad()const{return edad_;};
};

#endif /* USUARIO_H_ */
