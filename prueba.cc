#include "maquina.h"
#include "usuario.h"
#include "reserva.h"
#include <iostream>
#include <fstream>
#include "gtest/gtest.h"

TEST(Maquina, Constructor){
	Maquina maq;

	EXPECT_EQ(0, maq.getID());
	EXPECT_EQ(0, maq.getTipoCluster());
	EXPECT_EQ(0, maq.getLimiteCPUs());
	EXPECT_EQ(0, maq.getNumeroCPUs());
}

TEST(Maquina, SetDatos){
	Maquina maq;
	for(int i=20; i<22; i++){
	EXPECT_TRUE(maq.setDatos(i, 2, i, i-10));
	}
}

TEST(Maquina, GetDatosByID){
	Maquina maq;
	for(int i=1; i<12; i++){
	EXPECT_TRUE(maq.getDatosByID(i));
	}
	for(int j=13; j<16; j++)
	EXPECT_FALSE(maq.getDatosByID(j));
}

TEST(Maquina, ComprobarLimites){
	Maquina maq;
	EXPECT_TRUE(maq.getDatosByID(2));
	for(int i=1; i<=4; i++){
		EXPECT_TRUE(maq.comprobarLimites(maq, i));
	}
	for(int i=5; i<=7; i++){
		EXPECT_FALSE(maq.comprobarLimites(maq, i));
	}
}

TEST(Usuario, SetDatos){
	Usuario us;
	for(int i=0; i<3; i++){
		EXPECT_TRUE(us.setDatos("correo","DNI","password","limiteCPUs","limiteReservas","limiteTiempo","numeroCPUs","numeroReservas","numeroTiempo","nombre","apellidos","rol","telefono","edad"));
	}
}

TEST(Usuario, GetDatosByEmail){
	Usuario us;
	EXPECT_TRUE(us.getDatosByEmail("i02rijim"));
	EXPECT_TRUE(us.getDatosByEmail("i02ahbak"));
	EXPECT_FALSE(us.getDatosByEmail("a"));
}

TEST(Usuario, ComprobarLimites){
	Usuario us;
	EXPECT_TRUE(us.getDatosByEmail("i02rijim"));
	for(int i=1; i<=5; i++){
		EXPECT_TRUE(us.comprobarLimites(us, i, i));
	}
	for(int i=6; i<=8; i++){
		EXPECT_FALSE(us.comprobarLimites(us, i, i));
	}
}

TEST(Reserva, SetDatos){
	Reserva reserva;
	EXPECT_FALSE(reserva.setDatos(5, 30, "a", 0, 1, 2, 2021, 2, 3, 2021, 1));
}

TEST(Reserva, RealizarReserva){
	Usuario us;
	Maquina maq;
	Reserva reserva;

	us.getDatosByEmail("i02ahbak");
	maq.getDatosByID(5);

	EXPECT_FALSE(reserva.realizarReserva(us, maq));
}
