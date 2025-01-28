/*
 * Maquina.h
 *
 *  Created on: 7 dic. 2021
 *      Author: Martin del Rio
 */

#ifndef MAQUINA_H_
#define MAQUINA_H_

#include <iostream>
#include <string>

class Maquina{
private:
	int ID_;
	int tipoCluster_;
	int limiteCPUs_;
	int numeroCPUs_;

public:
	Maquina();
	Maquina(int ID, int tipoCluster, int limiteCPUs, int numeroCPUs);

	//Muestra por pantalla los datos de la maquina
	void mostrarDatos(int ID);
	//Permite crear una nueva maquina y la almacena en el fichero de maquinas
	bool setDatos(int ID, int tipoCluster, int limiteCPUs, int numeroCPUs);
	//Recorre un fichero para buscar una maquina con el ID introducido
	bool getDatosByID(int ID);
	//Comprueba que no sobrepasa los limites de la maquina con nuevos valores
	bool comprobarLimites(Maquina maq, int numeroCPUs);

	//Funciones setters
	inline void setID(int id){ID_ = id;};
	inline void setTipoCluster(int tipoCluster){tipoCluster_ = tipoCluster;};
	inline void setLimiteCPUs(int limiteCPUs){limiteCPUs_ = limiteCPUs;};
	inline void setNumeroCPUs(int numeroCpUs){numeroCPUs_ = numeroCpUs;};

	//Funciones getters
	inline int getID()const{return ID_;};
	inline int getTipoCluster()const{return tipoCluster_;};
	inline int getLimiteCPUs()const{return limiteCPUs_;};
	inline int getNumeroCPUs()const{return numeroCPUs_;};
};

#endif /* MAQUINA_H_ */
