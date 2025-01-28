/*
 * Reserva.cpp
 *
 *  Created on: 10 dic. 2021
 *      Author: Martin del Rio
 */

#include "reserva.h"

#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include "maquina.h"
#include "usuario.h"

using namespace std;

//Funciones auxiliares para obtener la hora del sistema
int diaActual();
int mesActual();
int anioActual();
bool comprobarFecha(int diaInicio, int mesInicio, int anioInicio);

//Constructor por defecto
Reserva::Reserva(){
	IDmaquina_ = 0;
	ID_ = 0;
	usuario_ = "";
	numeroCPUs_ = 0;
	diaInicio_ = 0;
	mesInicio_ = 0;
	anioInicio_ = 0;
	diaFin_ = 0;
	mesFin_ = 0;
	anioFin_ = 0;
	numeroDias_ = 0;
}

//Constructor con parametros
Reserva::Reserva(int IDmaquina, int ID, string usuario, int numeroCPUs, int diaInicio, int mesInicio, int anioInicio, int diaFin, int mesFin, int anioFin, int numeroDias){
	IDmaquina_ = IDmaquina;
	ID_ = ID;
	numeroCPUs_ = numeroCPUs;
	usuario_ = usuario;
	diaInicio_ = diaInicio;
	mesInicio_ = mesInicio;
	anioInicio_ = anioInicio;
	diaFin_ = diaFin;
	mesFin_ = mesFin;
	anioFin_ = anioFin;
	numeroDias_ = numeroDias;
}

//Muestra por pantalla los datos de la reserva
void Reserva::mostrarDatos(int ID){
	string IDmaquina, id, usuario, numeroCPUs, diaInicio, mesInicio, anioInicio, diaFin, mesFin, anioFin, numeroDias;
	string cad;
	int IDreserva;

	ifstream freservas("reservas.txt");
	if(!freservas)
		exit(-1);

	getline(freservas, IDmaquina, ',');
	getline(freservas, id, ',');

	while (!freservas.eof()){
		IDreserva = stoi(id);

		if((ID == IDreserva)){
			getline(freservas, usuario, ',');
			getline(freservas, numeroCPUs, ',');
			getline(freservas, diaInicio, ',');
			getline(freservas, mesInicio, ',');
			getline(freservas, anioInicio, ',');
			getline(freservas, diaFin, ',');
			getline(freservas, mesFin, ',');
			getline(freservas, anioFin, ',');
			getline(freservas, numeroDias, ',');

			cout << "\t\tID de la maquina: " << IDmaquina << endl;
			cout << "\t\tID de la reserva: " << id << endl;
			cout << "\t\tUsuario: " << usuario << endl;
			cout << "\t\tNumero de CPUs reservadas: " << numeroCPUs << endl;
			cout << "\t\tDia de inicio: " << diaInicio << endl;
			cout << "\t\tMes de incio: " << mesInicio << endl;
			cout << "\t\tAnio de inicio: " << anioInicio << endl;
			cout << "\t\tDia de fin: " << diaFin << endl;
			cout << "\t\tMes de fin: " << mesFin << endl;
			cout << "\t\tAnio de fin: " << anioFin << endl;
			cout << "\t\tNumero de dias: " << numeroDias << endl;

			freservas.close();
		}
		getline(freservas, cad, '\n');
		getline(freservas, IDmaquina, ',');
		getline(freservas, id, ',');

	}
	freservas.close();
}

//Permite crear una nueva reserva y la almacena en el fichero de reservas
bool Reserva::setDatos(int IDmaquina, int ID, string usuario, int numeroCPUs, int diaInicio, int mesInicio, int anioInicio, int diaFin, int mesFin, int anioFin, int numeroDias){
	string idMaquina, id, numCPUs, diaIni, mesIni, anioIni, diaF, mesF, anioF, numDias;
	string nombreFichero;

	idMaquina = to_string(IDmaquina);
	id = to_string(ID);
	numCPUs = to_string(numeroCPUs);
	diaIni = to_string(diaInicio);
	mesIni = to_string(mesInicio);
	anioIni = to_string(anioInicio);
	diaF = to_string(diaFin);
	mesF = to_string(mesFin);
	anioF = to_string(anioFin);
	numDias = to_string(numeroDias);

	nombreFichero = "reservas.txt";
	fstream freservas(nombreFichero.c_str(), fstream::in | fstream::out | fstream::app);
	if(!freservas){
		freservas << idMaquina + "," + id + "," + usuario + "," + numCPUs + "," + diaIni + "," + mesIni + "," + anioIni + "," + diaF + "," + mesF +"," + anioF +"," + numDias +"\n";
		freservas.close();
		return true;
	}
	else{
		return false;
	}
}

//Recorre un fichero para buscar una reserva con el ID introducido
bool Reserva::getDatosByID(int ID){
	string idMaquina, id, numCPUs, diaIni, mesIni, anioIni, diaF, mesF, anioF, numDias;
	int intid;
	string cad;

	ifstream freservas("reservas.txt");
	if (!freservas)
		exit(-1);

	getline(freservas, idMaquina, ',');
	getline(freservas, id, ',');

	while (!freservas.eof()) {
		intid = stoi(id);

		if ((ID == intid)) {
			IDmaquina_ = stoi(idMaquina);
			ID_ = intid;
			getline(freservas, usuario_, ',');
			getline(freservas, numCPUs, ',');
			numeroCPUs_ = stoi(numCPUs);
			getline(freservas, diaIni, ',');
			diaInicio_ = stoi(diaIni);
			getline(freservas, mesIni, ',');
			mesInicio_ = stoi(mesIni);
			getline(freservas, anioIni, ',');
			anioInicio_ = stoi(anioIni);
			getline(freservas, diaF, ',');
			diaFin_ = stoi(diaF);
			getline(freservas, mesF, ',');
			mesFin_ = stoi(mesF);
			getline(freservas, anioF, ',');
			anioFin_ = stoi(anioF);
			getline(freservas, numDias, ',');
			numeroDias_ = stoi(numDias);

			freservas.close();
			return true;
		}
		getline(freservas, cad, ',');
		getline(freservas, idMaquina, ',');
		getline(freservas, id, ',');
	}
	freservas.close();
	cout << "\tReserva no encontrada." << endl;
	return false;
}

//Realiza una reserva, pide al usuario el ID de la maquina, el numero de CPUs a reservar y la fecha de inicio-fin de la reserva con la cantidad de dias que son.
//Comprueba los limites del usuario y de la maquina
//Comprueba que la fecha sea posterior a la del sistema
bool Reserva::realizarReserva(Usuario us, Maquina maq){
	int numeroCPUs, diaInicio, mesInicio, anioInicio, diaFin, mesFin, anioFin, numeroDias;
	string idMaquina, id, usuario, numCPUs, diaIni, mesIni, anioIni, diaF, mesF, anioF, numDias;
	Reserva reserva;
	string nombreFichero;
	int intid;

	cout << "\t\tIntroduce la cantidad de CPUs a reservar: ";
	cin >> numeroCPUs;
	cout << "\t\tIntroduce el dia de inicio: ";
	cin >> diaInicio;
	cout << "\t\tIntroduce el mes de inicio: ";
	cin >> mesInicio;
	cout << "\t\tIntroduce el anio de inicio: ";
	cin >> anioInicio;
	cout << "\t\tIntroduce el dia de finalizacion: ";
	cin >> diaFin;
	cout << "\t\tIntroduce el mes de finalizacion: ";
	cin >> mesFin;
	cout << "\t\tIntroduce el anio de finalizacion: ";
	cin >> anioFin;
	cout << "\t\tIntroduce el numero de dias que es la reserva(inicio y fin inclusive): ";
	cin >> numeroDias;

	if(us.comprobarLimites(us, numeroCPUs, numeroDias)){
		if(maq.comprobarLimites(maq, numeroCPUs)){
			if(comprobarFecha(diaInicio, mesInicio, anioInicio)){
				nombreFichero = "reservas.txt";
				fstream freservas(nombreFichero.c_str(), fstream::in | fstream::out | fstream::app);
				if (!freservas)
					exit(-1);

				do {
					getline(freservas, idMaquina, ',');
					getline(freservas, id, ',');
					getline(freservas, usuario, ',');
					getline(freservas, numCPUs, ',');
					getline(freservas, diaIni, ',');
					getline(freservas, mesIni, ',');
					getline(freservas, anioIni, ',');
					getline(freservas, diaF, ',');
					getline(freservas, mesF, ',');
					getline(freservas, anioF, ',');
					getline(freservas, numDias, '\n');
				}while(!freservas.eof());

				intid = stoi(id);

				if(reserva.setDatos(maq.getID(), (intid + 1), us.getCorreo(), numeroCPUs, diaInicio, mesInicio, anioInicio, diaFin, mesFin, anioFin, numeroDias)){
					freservas.close();
					return true;
				}
			}
		}
	}
	return false;
}

//Funciones auxiliares para obtener el dia, mes y anio actual del sistema
int diaActual(){
	int num;
    struct tm tstruct;
    char buf[10];

    time_t     now = time(0);
    tstruct = *localtime(&now);

    strftime(buf, sizeof(buf), "%d", &tstruct);

    num = atoi(buf);
    return num;
}

int mesActual(){
	int num;
    struct tm tstruct;
    char buf[10];

    time_t     now = time(0);
    tstruct = *localtime(&now);

    strftime(buf, sizeof(buf), "%m", &tstruct);

    num = atoi(buf);
    return num;
}

int anioActual(){
	int num;
    struct tm tstruct;
    char buf[10];

    time_t     now = time(0);
    tstruct = *localtime(&now);

    strftime(buf, sizeof(buf), "%Y", &tstruct);

    num = atoi(buf);
    return num;
}

//Funcion auxiliar para comprobar que la fecha introducida es posterior a la del sistema
bool comprobarFecha(int diaInicio, int mesInicio, int anioInicio){
	int diaSistema, mesSistema, anioSistema;

	diaSistema = diaActual();
	mesSistema = mesActual();
	anioSistema = anioActual();

	if(anioInicio>=anioSistema){
		if(mesInicio>=mesSistema){
			if(diaInicio>diaSistema){
				return true;
			}
		}
	}
	cout << "\tEl dia introducido es anterior o igual al del sistema." << endl;
	return false;
}
