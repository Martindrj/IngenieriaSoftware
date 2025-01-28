/*
 * maquina.cc
 *
 *  Created on: 7 dic. 2021
 *      Author: Martin del Rio
 */

#include "maquina.h"

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//Constructor por defecto
Maquina::Maquina(){
	ID_ = 0;
	tipoCluster_ = 0;
	limiteCPUs_ = 0;
	numeroCPUs_ = 0;
}

//Constructor con parametros
Maquina::Maquina(int ID, int tipoCluster, int limiteCPUs, int numeroCPUs){
	ID_ = ID;
	tipoCluster_ = tipoCluster;
	limiteCPUs_ = limiteCPUs;
	numeroCPUs_ = numeroCPUs;
}

//Muestra por pantalla los datos de la maquina
void Maquina::mostrarDatos(int ID){
	string IDmaquina, tipoCluster, limiteCPUs, numeroCPUs;
	string cad;
	int IDmaq;

	ifstream fmaquinas("maquinas.txt");
	if(!fmaquinas)
		exit(-1);

	getline(fmaquinas, IDmaquina, ',');

	while (!fmaquinas.eof()){
		IDmaq = stoi(IDmaquina);

		if((ID == IDmaq)){
			getline(fmaquinas, tipoCluster, ',');
			getline(fmaquinas, limiteCPUs, ',');
			getline(fmaquinas, numeroCPUs, '\n');

			cout << "\t\t-> ID de la maquina: " << IDmaquina << endl;
			cout << "\t\t-> Tipo del Cluster: " << tipoCluster << endl;
			cout << "\t\t-> Limite de CPUs de la maquina: " << limiteCPUs << endl;
			cout << "\t\t-> Numero de CPUs reservados de la maquina: " << numeroCPUs << endl;

			fmaquinas.close();
		}
		getline(fmaquinas, cad, '\n');
		getline(fmaquinas, IDmaquina, ',');
	}
	fmaquinas.close();
}

//Permite crear una nueva maquina y la almacena en el fichero de maquinas
bool Maquina::setDatos(int ID, int tipoCluster, int limiteCPUs, int numeroCPUs){
	string id, tipoClus, limCPUs, numCPUs;
	string nombreFichero;

	id = to_string(ID);
	tipoClus = to_string(tipoCluster);
	limCPUs = to_string(limiteCPUs);
	numCPUs = to_string(numeroCPUs);

	nombreFichero = "maquinas.txt";
	fstream fmaquinas(nombreFichero.c_str(), fstream::in | fstream::out | fstream::app);
	if(fmaquinas){
		fmaquinas << id + "," + tipoClus + "," + limCPUs + "," + numCPUs + "\n";
		fmaquinas.close();
		return true;
	}
	else{
		return false;
	}

}

//Recorre un fichero para buscar una maquina con el ID introducido
bool Maquina::getDatosByID(int ID){
	string IDmaquina, tipoCluster, limiteCPUs, numeroCPUs;
	int IDmaq;
	string cad;

	ifstream fmaquinas("maquinas.txt");
	if (!fmaquinas)
		exit(-1);

	getline(fmaquinas, IDmaquina, ',');

	while (!fmaquinas.eof()) {
		IDmaq = stoi(IDmaquina);

		if ((ID == IDmaq)) {
			ID_ = IDmaq;
			getline(fmaquinas, tipoCluster, ',');
			tipoCluster_ = stoi(tipoCluster);
			getline(fmaquinas, limiteCPUs, ',');
			limiteCPUs_ = stoi(limiteCPUs);
			getline(fmaquinas, numeroCPUs, '\n');
			numeroCPUs_ = stoi(numeroCPUs);

			fmaquinas.close();
			return true;
		}
		getline(fmaquinas, cad, '\n');
		getline(fmaquinas, IDmaquina, ',');
	}
	fmaquinas.close();
	cout << "\tMaquina no encontrada." << endl;
	return false;
}

//Comprueba que no sobrepasa los limites de la maquina con nuevos valores
bool Maquina::comprobarLimites(Maquina maq, int numeroCPUs){
	int limiteCPUsMaquina, numeroCPUsMaquina;

	limiteCPUsMaquina = maq.getLimiteCPUs();
	numeroCPUsMaquina = maq.getNumeroCPUs();

	if(limiteCPUsMaquina>=(numeroCPUsMaquina+numeroCPUs)){
		return true;
	}
	else{
		cout << "\tSe ha sobrepasado el limite de CPUs que tiene la máquina." << endl;
		return false;
	}
}
