/*
 ============================================================================
 Name        : TP_[2].c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "validations.h"
#include "ArrayPassenger.h"
#define LEN 10
#define TYPE_LEN 4
#define STATUS_LEN 3

int main(void) {

setbuf(stdout,NULL);

int option;
int passengerId = 3;
int returnedId;
int status;
int flg;

int forcedflag = 1;
char forcedName [51]= "Jose";
char forcedLastName [51]= "Perez";
float forcedPrice = 1500.3;
char forcedFlyCode [51]= "zaqwd";
int forcedClass = 3;
int forcedStatusFlight = 3;

sPassenger passenger[LEN] = {{1,"Matias","Di Pino",2000,"axza",4,1,2},
							{2,"Pepe", "Zaragoza",1500.34,"zwsde",3,1,1},
							{3,"Ricardo","Aliendo",40021.2,"aeuch",2,1,3}};
sPassengerType passengerType[TYPE_LEN] = {{1,"Clase Turista"},{2,"Clase Premium"},{3,"Clase Ejecutiva"},{4,"Primera Clase"}};
sStatusFlight statusFlight[STATUS_LEN]  = {{1,"En Tiempo"},{2,"Demorado"},{3,"Cancelado"}};
/*if(initPassengers(passenger, LEN)!=0)
{
	printf("Tamaño de lista invalido\n");
}*/

do
{

	printf("-----------------------------\n1- Alta\n"
		   "2- Modificacion\n"
		   "3- Baja\n"
		   "4- Informar\n"
		   "5- Carga Forzada\n-----------------------------\n\n");

	option = EnterNumberInt("Ingrese una opcion: ", "Ingrese una opcion valida (0-5): ", 5, 0);

	status = passengerStatus(passenger, LEN);
	while( (option != 0 && option != 1 && option != 5) && status != 0)
	{
		printf("Para poder utilizar todas las funciones debe cargar al menos a un pasajero\n");
		option = EnterNumberInt("Ingrese una opcion valida (1 o 0): ", "Ingrese una opcion valida (1 o 0): ", 5, 0);
	}

	switch (option)
	{
	case 1:

		if(dataEntry(passenger, LEN, passengerType, TYPE_LEN, &passengerId, statusFlight, STATUS_LEN)== 0)
		{
			printf("Se cargo correctamente al pasajero\n");
		}
		else
		{
			printf("La lista de pasajeros esta llena, debera eliminar al menos a un pasajero\n");
		}
		break;
	case 2:

		returnedId = searchForId(passenger, LEN, &passengerId, passengerType, TYPE_LEN, statusFlight, STATUS_LEN);
		flg = modifyPassenger(passenger, LEN, returnedId, passengerType, TYPE_LEN, statusFlight, STATUS_LEN);
		if(flg == -1)
		{
			printf("Ya se ha dado de baja ese pasajero\n");
			break;
		}

		 if (flg == 1)
		{
			printf("Se ha modificado correctamente al pasajero\n");
			break;
		}
		else
		{
			printf("Se ha cancelado la operacion\n");

		}


				 break;

	case 3:

		returnedId = searchForId(passenger, LEN, &passengerId, passengerType, TYPE_LEN, statusFlight, STATUS_LEN);
		flg = removePassenger(passenger, LEN, returnedId);
		if(flg == -1)
		{
			printf("Ya se ha dado de baja ese pasajero\n");
			break;
		}

		 if (flg == 0)
		{
			printf("Se ha eliminado correctamente al pasajero\n");
			break;
		}
		else
		{
			printf("Se ha cancelado la operacion\n");

		}
		break;
	case 4:
		flg=reportSubMenu(passenger, LEN, passengerType, TYPE_LEN, statusFlight, STATUS_LEN);
			if(flg==1)
			{
				printf("Se ordeno la lista por apellido de manera ascendente\n");
				break;
			}
			if(flg==0)
			{
				printf("Se ordeno la lista por apellido de manera descendente\n");
				break;
			}
			if(flg== 2)
			{
				break;
			}
			if (flg == 3)
			{
				printf("Se ordeno la lista por codigo de vuelo de manera ascendente\n");
			}

			if (flg == 4)
			{
				printf("Se ordeno la lista por codigo de vuelo de manera descendente\n");
			}
			break;

	case 5:
			passengerId = passengerId + 1;
			if(forcedflag)
			{
				addPassenger(passenger, LEN, passengerId, forcedName, forcedLastName, forcedPrice, forcedClass, forcedFlyCode, forcedStatusFlight);
				printf("Se cargo de manera forzada\n");
				forcedflag = 0;
			}
			else
			{
				printf("Ya se cargo de manera forzada previamente\n");
			}

			break;

	}

}while (option != 0 );

	return EXIT_SUCCESS;
}
