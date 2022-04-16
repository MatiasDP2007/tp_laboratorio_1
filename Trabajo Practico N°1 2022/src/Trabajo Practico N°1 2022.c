/*
 ============================================================================
 Name        : Trabajo Practico N°1
 Author      : Di Pino Matias
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
Una agencia de viaje necesita calcular costos para sus vuelos de Latam y Aerolíneas Argentinas
para ofrecerlos a sus clientes.
Se deberá ingresar por cada vuelo los km totales y el precio total del mismo.
El objetivo de la aplicación es mostrar las diferentes opciones de pagos a sus clientes.

 */

#include <stdio.h>
#include <stdlib.h>
#include "Validations.h"
#include "Functions.h"
int main(void)
{
	setbuf(stdout,NULL);
	int option;
	int checkUpdatedData= 0;
	float distance = 0;
	float latamPrices = 0;
	float aerolineasPrices = 0;
	float debitLatamCalculation = 0;
	float debitAerolineasCalculation = 0;
	float creditLatamCalculation = 0;
	float creditAerolineasCalculation = 0;
	float bitcoinLatamPrice = 0;
	float bitcoinAerolineasPrice = 0;
	float pricePerLatamKilometer = 0;
	float pricePerAerolineasKilometer = 0;
	float pricesDiference = 0;



	do
	{
		printf("1. Ingresar Kilometros: ( km= %.2f)\n",distance);
		printf("2. Ingresar Precio de Vuelos: (Aerolineas=%.2f, Latam=%.2f)\n",aerolineasPrices,latamPrices);
		printf(	"3. Calcular todos los costos\n"
				"4. Informar Resultados\n"
				"5. Carga forzada de datos\n"
				"6. Salir\n"
				);


		option = EnterNumberInt("Ingrese una opcion: ","Error, seleccione una opcion valida\n",6,1);
		while((ValidateFirstOption(distance, latamPrices, aerolineasPrices) != 1) && option != 1 && option != 2  && option != 5 && option != 6 )
		{
			printf("Debe ingresar al menos una distancia y un precio para poder utilizar todas las funciones...\n");
			option = EnterNumberInt("Ingrese una opcion: ","Error, seleccione una opcion valida\n",6,1);
		}
		switch(option)
		{

			case 1:

					if(EnterDistance(&distance, &checkUpdatedData)==1)
					{
						printf("Se cargo correctamente el kilometraje\n\n");
					}
					else
					{
						printf("Ocurrio un error al cargar el kilometraje\n\n");
					}

					break;

			case 2:

				if(SetFlightPrices(&latamPrices, &aerolineasPrices, &checkUpdatedData)==1)
				{
					printf("Se guardaron los precios correctamente\n\n");
				}
				else
				{
					printf("Se cancelo la operacion\n\n");
				}

				break;

			case 3:
				if(CalculateFlightPrices(&checkUpdatedData,&distance, &latamPrices, &aerolineasPrices, &debitLatamCalculation, &debitAerolineasCalculation,
				   &creditLatamCalculation, &creditAerolineasCalculation, &bitcoinLatamPrice, &bitcoinAerolineasPrice, &pricePerLatamKilometer,
				   &pricePerAerolineasKilometer, &pricesDiference) == 1)
				{
					printf("Se calcularon correctamente los precios\n\n");
				}
				break;

			case 4:
					if(checkUpdatedData != 0)
					{
					InformarResultados(distance, latamPrices, aerolineasPrices, debitLatamCalculation, debitAerolineasCalculation,
										   creditLatamCalculation, creditAerolineasCalculation, bitcoinLatamPrice, bitcoinAerolineasPrice, pricePerLatamKilometer,
										   pricePerAerolineasKilometer, pricesDiference);

					}
					else
					{
						printf("Debe cargar los datos para mostrar los resultados\n\n");
					}


				break;

			case 5:
				distance = 7090;
				aerolineasPrices=162965;
				latamPrices = 159339;
				if(CalculateFlightPrices(&checkUpdatedData,&distance, &latamPrices, &aerolineasPrices, &debitLatamCalculation, &debitAerolineasCalculation,
			   &creditLatamCalculation, &creditAerolineasCalculation, &bitcoinLatamPrice, &bitcoinAerolineasPrice, &pricePerLatamKilometer,
			   &pricePerAerolineasKilometer, &pricesDiference) == 1 )
				{
					InformarResultados(distance, latamPrices, aerolineasPrices, debitLatamCalculation, debitAerolineasCalculation,
									   creditLatamCalculation, creditAerolineasCalculation, bitcoinLatamPrice, bitcoinAerolineasPrice, pricePerLatamKilometer,
									   pricePerAerolineasKilometer, pricesDiference);

				}
					break;

		}

	}while(option != 6);


	return EXIT_SUCCESS;
}
