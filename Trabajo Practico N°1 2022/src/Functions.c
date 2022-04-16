
#ifndef FUNCTIONS_C_
#define FUNCTIONS_C_

#include <stdio.h>
#include <stdlib.h>
#include "Validations.h"
#include "Functions.h"

int ValidateFirstOption(float distance, float latamPrices, float aerolineasPrices)
{
	int rtn=0;
	if(distance > 0 && (latamPrices > 0 || aerolineasPrices > 0))
	{
		rtn =1;
	}
	return rtn;
}

int EnterDistance(float* distance, int* checkUpdatedData)
{
	system("cls");
	float enteredDistance;
	int rtn = 0;
	enteredDistance = EnterNumberFloat("Ingrese Kilometraje:  ", "Error,Ingrese un kilometraje valido\n ", 0);
	if(enteredDistance > 0)
	{
		*distance = enteredDistance;
		rtn = 1;
	}
	*checkUpdatedData = 0;
	return rtn;

}

int SetFlightPrices(float* latamPrices, float* aerolineasPrices, int* checkUpdatedData)
{
	float enteredPrice;
	int option;
	int rtn = 0;
	int flagMsg = 0;

	do
	{
		system("cls");

		if(flagMsg == 1)
		{
			printf("Se cargo correctamente el precio \n");
		}
		printf("1. Aerolineas\n2.Latam\n0.Salir\n");
		option = EnterNumberInt("Ingrese una opcion: ", "Seleccione una empresa valida\n" , 2, 0);

		switch (option)
		{
			case 1:
				enteredPrice = EnterNumberFloat("Ingrese el precio del vuelo: ", "Ingrese un precio valido\n", 0);
				if(enteredPrice > 0)
				{
					*aerolineasPrices = enteredPrice;
					flagMsg = 1;
					rtn = 1;
				}

				break;
			case 2:
				enteredPrice = EnterNumberFloat("Ingrese el precio del vuelo: ", "Ingrese un precio valido\n ", 0);
				if(enteredPrice > 0)
				{
					*latamPrices = enteredPrice;
					flagMsg = 1;
					rtn = 1;
				}
				break;

			case 0 :
				break;
		}

	}while(option != 0);
	*checkUpdatedData = 0;
	return rtn;

}

int CalculateFlightPrices(int* checkUpdatedData, float* distance, float* latamPrices, float* aerolineasPrices, float* debitLatamCalculation, float* debitAerolineasCalculation,
						  float* creditLatamCalculation, float* creditAerolineasCalculation, float* bitcoinLatamPrice,float* bitcoinAerolineasPrice,
						  float* pricePerLatamKilometer, float* pricePerAerolineasKilometer, float* pricesDiference)
{
		system("cls");
		float bitcoin = 4776548.08;
		int rtn = 0;
		*debitLatamCalculation = *latamPrices - (*latamPrices * .10);
		*debitAerolineasCalculation = *aerolineasPrices - (*aerolineasPrices * .10);
		*creditLatamCalculation = *latamPrices + (*latamPrices * .25);
		*creditAerolineasCalculation = *aerolineasPrices + (*aerolineasPrices * .25);
		*bitcoinLatamPrice =  *latamPrices / bitcoin;
		*bitcoinAerolineasPrice =  *aerolineasPrices / bitcoin;
		*pricePerLatamKilometer = *latamPrices / *distance;
		*pricePerAerolineasKilometer = *aerolineasPrices / * distance;
		if(*latamPrices > *aerolineasPrices)
		{
			*pricesDiference =  *latamPrices -  *aerolineasPrices;
		}
		else
		{
			*pricesDiference =  *aerolineasPrices -  *latamPrices;
		}
		rtn = 1;
		*checkUpdatedData = 1;

		return rtn;
	}

void InformarResultados (float distance, float latamPrices, float aerolineasPrices, float debitLatamCalculation, float debitAerolineasCalculation,
						 float creditLatamCalculation, float creditAerolineasCalculation, float bitcoinLatamPrice,float bitcoinAerolineasPrice,
						 float pricePerLatamKilometer, float pricePerAerolineasKilometer, float pricesDiference)
{

	system("cls");
	if(aerolineasPrices <= 0)
	{
		printf("No se ingreso un monto para calcular costos de la empresa Aerolineas\n\n");
	}
	else
	{
		printf("Kms Ingresado: %.2f\n\n",distance);
		printf("Precio Aerolineas: $ %.2f\n", aerolineasPrices);
		printf("a) Precio con tarjeta de debito: $ %.2f\n",debitAerolineasCalculation);
		printf("b) Precio con tarjeta de credito: $ %.2f\n",creditAerolineasCalculation);
		printf("c) Precio pagando con bitcoin: %f BTC\n",bitcoinAerolineasPrice);
		printf("d) Mostrar precio unitario: $ %.2f\n\n",pricePerAerolineasKilometer);
	}
	if(latamPrices <= 0)
	{
		printf("No se ingreso un monto para calcular costos de la empresa Latam\n\n");
	}
	else
	{
		printf("Precio Latam: $ %2.f\n",latamPrices);
		printf("a) Precio con tarjeta de debito: $ %.2f\n",debitLatamCalculation);
		printf("b) Precio con tarjeta de credito: $ %.2f\n",creditLatamCalculation);
		printf("c) Precio pagando con bitcoin: %f BTC\n",bitcoinLatamPrice);
		printf("d) Mostrar precio unitario: $ %.2f\n\n",pricePerLatamKilometer);
	}

		printf("La diferencia de precio es: $ %.2f\n\n",pricesDiference);


}



#endif /* FUNCTIONS_C_ */
