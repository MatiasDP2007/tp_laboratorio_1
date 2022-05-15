#include "validations.h"
#include "ArrayPassenger.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define LOADED 1
#define EMPTY 0


int initPassengers(sPassenger* list, int len)

{
	int rtn = -1;

	for(int i = 0; i < len ; i++)
	{
		list[i].isEmpty = EMPTY;
	}
	rtn = 0;


	return  rtn;
}
int passengerStatus(sPassenger* list, int len)
{
	int rtn = -1;
	for(int i= 0; i < len; i++)
	{
		if(list[i].isEmpty == LOADED)
		{
			rtn = 0;
			break;
		}
	}
	return rtn;
}
void displayTypes(sPassengerType* type, int len)
{
		printf("TIPO DE VUELO\n\n");
		for(int i = 0; i< len; i ++)
		{
			printf("%d- %s\n",type[i].idType, type[i].description);
		}
}
void displayStatusFlight(sStatusFlight* status, int len)
{
		printf("ESTADO DEL VUELO\n\n");
		for(int i = 0; i< len; i ++)
		{
			printf("%d- %s\n",status[i].idStatus, status[i].description);
		}
}
void printPassengers(sPassenger* passenger,int len, sPassengerType* type,int typeLen, sStatusFlight* status, int statusLen)
{
	printf("   ID        	  NOMBRE           APELLIDO   	 	PRECIO 		TIPO DE PASAJERO		ESTADO DEL VUELO		CODIGO DE VUELO\n");
	for(int i=0; i < len; i ++)
	{
		if(passenger[i].isEmpty == LOADED)
		{
			matchFlightStatus(passenger[i], type, typeLen, status, statusLen);

		}
	}
}

void matchFlightStatus(sPassenger passenger, sPassengerType* type,int typeLen, sStatusFlight* status, int statusLen)
{
	for(int i=0; i < statusLen; i ++)
	{
		if(status[i].idStatus == passenger.statusFlight)
		{
			DisplayOnePassenger(passenger, typeLen, type, status[i]);
			break;
		}

	}
}
void DisplayOnePassenger(sPassenger passenger,int typeLen, sPassengerType* type, sStatusFlight status)
{

	for(int i = 0; i < typeLen ; i  ++)
	{
		if(type[i].idType == passenger.typePassenger)
		{
			printf("%5d %18s%18s      $%14.2f		  %14s		%16s	%23s\n",passenger.id, passenger.name, passenger.lastName, passenger.price, type[i].description, status.description, passenger.flycode);
			break;
		}

	}

}

int dataEntry(sPassenger* passenger,int len, sPassengerType* passengerType, int typeLen,int* id, sStatusFlight* statusFlight, int statusLen)
{
	char name[51];
	char lastName[51];
	float price;
	char flycode[51];
	int typePassenger;
	int rtn = -1;
	int idAux = 0;
	int flightStatus;
	idAux = *id;

	for(int i = 0; i<len; i ++)
	{
		if(passenger[i].isEmpty == EMPTY)
		{
			idAux ++;
			EnterString("Ingrese el nombre del pasajero: ", name);
			system("cls");
			EnterString("Ingrese el apellido del pasajero: ", lastName);
			system("cls");
			price = EnterNumberFloat("Ingrese el precio del vuelo: ", "Error, ha ingresado un precio invalido: ",0);
			system("cls");
			displayTypes(passengerType, typeLen);
			typePassenger = EnterNumberInt("Ingrese la clase del pasajero: ", "Error, ingrese una opcion valida (1-4): ", 4, 1);
			system("cls");
			EnterString("Ingrese el codigo de vuelo del pasajero: ", flycode);
			system("cls");
			displayStatusFlight(statusFlight, statusLen);
			flightStatus = EnterNumberInt("Ingrese el estado del vuelo: ", "Error, ingrese una opcion valida (1-3): ", 3, 1);
			rtn = addPassenger(passenger, len, idAux, name,
						lastName, price, typePassenger,  flycode, flightStatus);
			break;
		}
	}
	*id = idAux;


	return rtn;

}
int addPassenger(sPassenger* passenger,int len, int id,char name[],char
		lastName[],float price,int typePassenger, char flycode[],int flightStatus)
{
	int rtn = -1;

	for(int i = 0 ; i < len ; i ++)
	{
		if(passenger[i].isEmpty == EMPTY)
		{
			passenger[i].id = id;
			strcpy(passenger[i].name,name);
			strcpy(passenger[i].lastName,lastName);
			passenger[i].price = price;
			passenger[i].typePassenger = typePassenger;
			strcpy(passenger[i].flycode,flycode);
			passenger[i].isEmpty = LOADED;
			passenger[i].statusFlight = flightStatus;
			rtn = 0;
			break;
		}
	}

	return rtn ;
}

int findPassengerById (sPassenger* passenger, int len, int id)
{
	int index = -1;

	for(int i= 0; i < len ; i ++)
	{
		if(passenger[i].isEmpty == LOADED && id == passenger[i].id)
		{
				index = i+1;
				break;
		}
	}
	return index;
}

int searchForId(sPassenger* passenger, int len, int *id, sPassengerType* type, int typeLen, sStatusFlight* statusFlight, int statusLen)
{
	int enteredId;
	int index;

	printPassengers(passenger, len, type, typeLen, statusFlight, statusLen);
	enteredId = EnterNumberInt("Ingrese el ID del pasajero: ", "Error, ingrese un ID valido: ", *id, 1);
	index = findPassengerById(passenger, len, enteredId);

	return index;
}

int removePassenger (sPassenger* passenger, int len, int id)
{

	int rtn;
	int option;
	system("cls");

	 if(id == -1)
	{
		rtn = -1;
	}
	else
	{
		option = EnterNumberInt("Realmente desea eliminar al pasajero?\n1- SI\n2- NO",
				"Ingrese una opcion valida (1 o 2)\nRealmente desea eliminar al pasajero?\n1- SI\n2- NO", 2, 1);
		switch(option)
		{
			case 1:
				for(int i = 0; i < len ; i ++)
				{
					if(id == passenger[i].id)
					{
						passenger[i].isEmpty = EMPTY;
						rtn = 0;
						break;
					}

				}
				break;
			case 2:
				rtn = 1;
			break;

		}
	}

	return rtn;
}

int modifyPassenger(sPassenger* passenger, int len, int id, sPassengerType* type, int typeLen, sStatusFlight* status, int statusLen)
{
	int rtn = 0;
	int option;
	if(id != -1)
	{
		printf("1-Nombre\n2-Apellido\n3-Precio\n4-Tipo de pasajero\n5-Estado del vuelo\n6-Codigo de vuelo\n0-Salir\n\n");
			option = EnterNumberInt("Seleccione una opcion a modificar: ",
							"Ingrese una opcion valida (0 a 6)", 6, 0);
			switch(option)
			{
			case 1:
					rtn = modifyName(passenger, len, id);
					break;
			case 2:
					rtn = modifyLastName(passenger, len, id);
					break;
			case 3:
					rtn = modifyPrice(passenger, len, id);
					break;
			case 4:
					rtn = modifyPassengerType(passenger, len, id, type, typeLen);
					break;
			case 5:
					rtn = modifyStatusFlight(passenger, len, id, status, statusLen);
					break;
			case 6:
					rtn =  modifyFlightCode(passenger, len, id);
					break;
			case 0:
				rtn = 2;
				break;

			}
	}else
	{
		rtn = -1;
	}


	return rtn;
}

int modifyName(sPassenger* passenger, int len, int index)
{
	int rtn = 0;
	for(int i = 0; i<len; i ++)
	{
		if(index == passenger[i].id && passenger[i].isEmpty == LOADED)
		{
			EnterString("Ingrese el nombre del pasajero: ", passenger[i].name);
			rtn = 1;
			break;
		}
	}
	return rtn;
}
int modifyLastName(sPassenger* passenger, int len, int index)
{
	int rtn = 0;
	for(int i = 0; i<len; i ++)
	{
		if(index == passenger[i].id && passenger[i].isEmpty == LOADED)
		{
			EnterString("Ingrese el apellido del pasajero: ", passenger[i].lastName);
			rtn = 1;
			break;
		}
	}
	return rtn;
}
int modifyPrice(sPassenger* passenger, int len, int index)
{
	int rtn = 0;
	for(int i = 0; i<len; i ++)
	{
		if(index == passenger[i].id && passenger[i].isEmpty == LOADED)
		{
			passenger[i].price = EnterNumberFloat("Ingrese el nuevo precio del vuelo: ", "Error, ingrese un precio valido: ", 0);
			rtn = 1;
			break;
		}

	}

	return rtn;
}
int modifyPassengerType(sPassenger* passenger, int len, int index, sPassengerType* type, int typeLen)
{
	int rtn = 0;
	displayTypes(type, typeLen);
	for(int i = 0; i<len; i ++)
	{
		if(index == passenger[i].id && passenger[i].isEmpty == LOADED)
		{
			passenger[i].typePassenger = EnterNumberInt("Ingrese el tipo de pasajero: ","Error, ingrese un tipo de pasajero valido (1-4): ", 4, 1);
			rtn = 1;
			break;
		}
	}
	return rtn;
}
int modifyStatusFlight(sPassenger* passenger, int len, int index, sStatusFlight* status, int statusLen)
{
	displayStatusFlight(status, statusLen);
	int rtn = 0;
	for(int i = 0; i<len; i ++)
	{
		if(index == passenger[i].id && passenger[i].isEmpty == LOADED)
		{
			passenger[i].statusFlight = EnterNumberInt("Ingrese el estado del vuelo: ","Error, ingrese un estado de vuelo valido (1-3): ", 3, 1);
			rtn = 1;
			break;
		}
	}
	return rtn;

}
int modifyFlightCode(sPassenger* passenger, int len, int index)
{
	int rtn = 0;
		for(int i = 0; i<len; i ++)
		{
			if(index == passenger[i].id && passenger[i].isEmpty == LOADED)
			{
				EnterString("Ingrese el codigo de vuelo del pasajero: ", passenger[i].flycode);
				rtn = 1;
				break;
			}
		}
		return rtn;
}
int reportSubMenu(sPassenger* passenger, int len, sPassengerType* type, int typeLen, sStatusFlight* status, int statusLen)
{
	int option;
	int rtn;
	printf("LISTADO\n\n"
			"1- Listado de los pasajeros ordenados alfabeticamente por Apellido y Tipo de pasajero\n"
			"2- Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio y promedio\n"
			"3- Listado de los pasajeros por Código de vuelo y estados de vuelos ACTIVOS\n"
			"0- Salir\n");

		option = EnterNumberInt("Ingrese una opcion: ", "Error, ingrese una opcion valida (3-0): ", 3, 0);
		system("cls");
		switch(option)
		{
		case 1:
			if(OrderMenu()== 1)
			{
				rtn = sortPassengers(passenger, len, 1);
			}
			else
			{
				rtn = sortPassengers(passenger, len, 0);
			}
			break;

		case 2:
				rtn = CalculateFlightPrices(passenger, len);
			break;
		case 3:
			if(OrderMenu()== 1)
			{
				rtn = sortPassengersByCode(passenger, len, 1);
			}
			else
			{
				rtn = sortPassengersByCode(passenger, len, 0);
			}

			printPassengers(passenger, len, type, typeLen, status, statusLen);
			break;
		case 0:
				rtn = -2;
				break;

		}

		return rtn;
}
int OrderMenu(void)
{
	int option;
	printf("1-Listado ORDENADO de manera ASCENDENTE(A-Z)\n2-Listado ORDENADO de manera DESCENDENTE(Z-A)\n\n");

	option = EnterNumberInt("Ingrese una opcion: ", "Ingrese una opcion valida: ", 2, 1);
	return option;
}
int sortPassengers(sPassenger* passenger, int len, int order)
{

	int rtn = -1;

    	if(order == 1)
    	{

    		rtn = SortListByLastNameAsc(passenger, len);
    	}

    	if(order == 0)
		{

    		rtn = SortListByLastNameDes(passenger, len);
		}
        return rtn;

}
int SortListByLastNameAsc(sPassenger* passenger, int len)
{
	sPassenger aux;
	int flagSort = -1;

	for(int i=0 ; i < len - 1 ; i++)
	{
		  for (int j = i + 1; j < len ; j++)
		   {

				  if(passenger[i].isEmpty == LOADED && strcmp(passenger[i].lastName,passenger[j].lastName) > 0 )
				   {
						aux=passenger[i];
						passenger[i]=passenger[j];
						passenger[j]=aux;
						flagSort = 1;
					}
				  if(passenger[i].isEmpty == LOADED && strcmp(passenger[i].lastName,passenger[j].lastName)==0)
				  {
					   if(passenger[i].typePassenger > passenger[j].typePassenger)
					   {
							aux=passenger[i];
							passenger[i]=passenger[j];
							passenger[j]=aux;
							flagSort = 1;
					   }
				  }
		   }
	}
	return flagSort;
}
int SortListByLastNameDes(sPassenger* passenger, int len)
{
	sPassenger aux;
	int flagSort = -1;
	for(int i=0 ; i < len - 1 ; i++)
	{
		  for (int j = i + 1; j < len ; j++)
		   {

			  if(passenger[i].isEmpty == LOADED && strcmp(passenger[i].lastName,passenger[j].lastName) < 0)
				{
					aux=passenger[i];
					passenger[i]=passenger[j];
					passenger[j]=aux;
					flagSort = 0;
				}
				  if(passenger[i].isEmpty == LOADED && strcmp(passenger[i].lastName,passenger[j].lastName)==0)
				  {
					   if(passenger[i].typePassenger < passenger[j].typePassenger)
					   {
							aux=passenger[i];
							passenger[i]=passenger[j];
							passenger[j]=aux;
							flagSort = 0;
					   }

				  }
			}
		}
	return flagSort;
}

int CalculateFlightPrices(sPassenger* passenger, int len)
{
	float totalAmount = 0;
	float averagePrice = 0;
	int count = 0;
	int passengerCount=0;
	for(int i = 0; i < len ; i++)
	{
		if(passenger[i].isEmpty == LOADED)
		{
			totalAmount  += passenger[i].price;
			count ++;
		}
	}

	averagePrice = totalAmount / count ;

	for(int i = 0; i < len ; i++)
	{
		if(passenger[i].price > averagePrice && passenger[i].isEmpty == LOADED)
		{
			passengerCount++;
		}
	}

	printf("La suma total del precio de los pasajes es %.2f\n",totalAmount);
	printf("El promedio del precio de los pasajes es %.2f\n",averagePrice);
	if(passengerCount == 0)
	{
		printf("No hay pasajeros que superen el precio promedio por pasaje\n");
	}
	else
	{
		printf("La cantidad de pasajeros que superen el precio promedio por pasaje es/son: %d\n",passengerCount);
	}
	return 2;
}

int sortPassengersByCode(sPassenger* passenger, int len, int order)
{
	int rtn = -1;

	    	if(order == 1)
	    	{

	    		rtn = SortListByFlyCodeAsc(passenger, len);
	    	}

	    	if(order == 0)
			{

	    		rtn = SortListByFlyCodeDes(passenger, len);
			}
	        return rtn;
}

int SortListByFlyCodeAsc(sPassenger* passenger, int len)
{
	sPassenger aux;
		int flagSort = -1;

		for(int i=0 ; i < len - 1 ; i++)
		{
			  for (int j = i + 1; j < len ; j++)
			   {

					  if(passenger[i].isEmpty == LOADED && strcmp(passenger[i].flycode,passenger[j].flycode) > 0 && passenger[i].statusFlight != 3)
					   {
							aux=passenger[i];
							passenger[i]=passenger[j];
							passenger[j]=aux;
							flagSort =  3;
						}
			   }
		}
return flagSort;
}

int SortListByFlyCodeDes(sPassenger* passenger, int len)
{
	sPassenger aux;
			int flagSort = -1;

			for(int i=0 ; i < len - 1 ; i++)
			{
				  for (int j = i + 1; j < len ; j++)
				   {

						  if(passenger[i].isEmpty == LOADED && strcmp(passenger[i].flycode,passenger[j].flycode) < 0  && passenger[i].statusFlight != 3 )
						   {
								aux=passenger[i];
								passenger[i]=passenger[j];
								passenger[j]=aux;
								flagSort =  4;
							}
				   }
			}
	return flagSort;
}
