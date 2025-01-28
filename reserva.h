/*
 * Reserva.h
 *
 *  Created on: 10 dic. 2021
 *      Author: Martin del Rio
 */

#ifndef RESERVA_H_
#define RESERVA_H_

#include <iostream>
#include <string>
#include <fstream>
#include "maquina.h"
#include "usuario.h"

using namespace std;

class Reserva{
private:
	int IDmaquina_;
	int ID_;
	string usuario_;
	int numeroCPUs_;
	int diaInicio_;
	int mesInicio_;
	int anioInicio_;
	int diaFin_;
	int mesFin_;
	int anioFin_;
	int numeroDias_;

public:
	Reserva();
	Reserva(int IDmaquina, int ID, string usuario, int numeroCPUs, int diaInicio, int mesInicio, int anioInicio, int diaFin, int mesFin, int anioFin, int numeroDias);

	//Muestra por pantalla los datos de la reserva
	void mostrarDatos(int ID);
	//Permite crear una nueva reserva y la almacena en el fichero de reservas
	bool setDatos(int IDmaquina, int ID, string usuario, int numeroCPUs, int diaInicio, int mesInicio, int anioInicio, int diaFin, int mesFin, int anioFin, int numeroDias);
	//Recorre un fichero para buscar una reserva con el ID introducido
	bool getDatosByID(int ID);
	//Realiza una reserva, pide al usuario el ID de la maquina, el numero de CPUs a reservar y la fecha de inicio-fin de la reserva con la cantidad de dias que son.
	//Comprueba los limites del usuario y de la maquina
	//Comprueba que la fecha sea posterior a la del sistema
	bool realizarReserva(Usuario us, Maquina maq);

	//Funciones setters
	inline void setIDMaquina(int IDmaquina){IDmaquina_ = IDmaquina;};
	inline void setID(int id){ID_ = id;};
	inline void setUsuario(int usuario){usuario_ = usuario;};
	inline void setnNumeroCPUs(int numeroCPUs){numeroCPUs_ = numeroCPUs;};
	inline void setDiaInicio(int diaInicio){diaInicio_ = diaInicio;};
	inline void setMesInicio(int mesInicio){mesInicio_ = mesInicio;};
	inline void setAnioInicio(int anioInicio){anioInicio_ = anioInicio;};
	inline void setDiaF(int diaFin){diaFin_ = diaFin;};
	inline void setMesF(int mesFin){mesFin_ = mesFin;};
	inline void setAnioF(int anioFin){anioFin_ = anioFin;};
	inline void setNumeroDias(int numeroDias){numeroDias_ = numeroDias;};

	//Funciones getters
	inline int getIDMaquina()const{return IDmaquina_;};
	inline int getID()const{return ID_;};
	inline string getUsuario()const{return usuario_;};
	inline int getNumeroCPUs()const{return numeroCPUs_;};
	inline int getDiaInicio()const{return diaInicio_;};
	inline int getMesInicio()const{return mesInicio_;};
	inline int getAnioInicio()const{return anioInicio_;};
	inline int getDiaF()const{return diaFin_;};
	inline int getMesF()const{return mesFin_;};
	inline int getAnioF()const{return anioFin_;};
	inline int getNumeroDias()const{return numeroDias_;};
};

#endif /* RESERVA_H_ */
