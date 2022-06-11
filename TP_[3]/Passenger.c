#include "passenger.h"


Passenger* Passenger_new()
{
	Passenger* passenger;

	passenger = (Passenger*) malloc (sizeof(Passenger));


		return passenger;
}


Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* apellidoStr,char* precioStr,char* codigoStr,char* tipoPasajeroStr,char* estadoStr)
{
	int passengerType;
	int passengerStatus;
	Passenger* passenger = Passenger_new();

	passengerType = ComparePassengerType(tipoPasajeroStr);
	passengerStatus = ComparePassengerStatus(estadoStr);

	if(idStr != NULL && nombreStr != NULL && apellidoStr != NULL && precioStr != NULL && codigoStr != NULL && tipoPasajeroStr != NULL && estadoStr != NULL && passenger != NULL)
	{
		Passenger_setId(passenger, atoi(idStr));
		Passenger_setNombre(passenger, nombreStr);
		Passenger_setApellido(passenger, apellidoStr);
		Passenger_setPrecio(passenger, atof(precioStr));
		Passenger_setCodigoVuelo(passenger, codigoStr);
		Passenger_setTipoPasajero(passenger, passengerType);
		Passenger_setEstado(passenger, passengerStatus);

	}
	return passenger;
}

void Passenger_delete(Passenger* this)
{
	if(this != NULL)
	{
		free(this);
	}
}
int Passenger_setId(Passenger* this,int id)
{
	int rtn = -1;

	if(this != NULL && id>0)
	{
		this->id = id;
		rtn = 0;
	}

	return rtn;
}


int Passenger_getId(Passenger* this,int* id)
{

	int rtn = -1;

	if(this != NULL && id>0)
	{
		*id = this->id;
		rtn = 0;
	}

	return rtn;
}

int Passenger_setNombre(Passenger* this,char* nombre)
{
	int rtn = -1;

	if(this != NULL &&  nombre != NULL)
	{
		strcpy(this->nombre, nombre);
		rtn = 0;
	}

	return rtn;
}

int Passenger_getNombre(Passenger* this,char* nombre)
{
	int rtn = -1;

	if(this != NULL && nombre != NULL)
	{
		strcpy(nombre,this->nombre);
		rtn = 0;
	}

	return rtn;
}

int Passenger_setApellido(Passenger* this,char* apellido)
{
	int rtn = -1;

	if(this != NULL && apellido != NULL)
	{
		strcpy(this->apellido, apellido);
		rtn = 0;
	}
	return rtn;

}
int Passenger_getApellido(Passenger* this,char* apellido)
{
	int rtn = -1;

		if(this != NULL && apellido != NULL)
		{
			strcpy(apellido,this->apellido);
			rtn = 0;
		}

		return rtn;
}

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int rtn = -1;

		if(this != NULL && codigoVuelo != NULL)
		{
			strcpy(this->codigoVuelo, codigoVuelo);
			rtn = 0;
		}

		return rtn;
}

int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int rtn = -1;

		if(this != NULL && codigoVuelo != NULL )
		{
			strcpy(codigoVuelo, this->codigoVuelo);
			rtn = 0;
		}

		return rtn;
}

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero)
{
	int rtn = -1;

	if (this != NULL && (tipoPasajero >= 1 || tipoPasajero <= 4) )
	{
		this->tipoPasajero = tipoPasajero;
		rtn = 0;
	}

	return rtn;
}
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero)
{
	int rtn = -1;

	if (this != NULL)
	{
		*tipoPasajero = this->tipoPasajero;
		rtn = 0;
	}

	return rtn;
}



int Passenger_setPrecio(Passenger* this,float precio)
{
	int rtn = -1;

	if(this != NULL && precio > 0)
	{
		this->precio = precio;
		rtn = 0;
	}

	return rtn;
}

int Passenger_getPrecio(Passenger* this,float* precio)
{
	int rtn = -1;

	if(this != NULL && precio > 0)
	{
		*precio = this-> precio;
		rtn = 0;
	}

	return rtn;
}

int Passenger_setEstado(Passenger* this, int estado)
{
	int rtn = -1;

	if(this != NULL && (estado >= 1 || estado <= 3))
	{
		this->isEmpty = estado;
		rtn = 0;
	}
	return rtn;
}

int Passenger_getEstado(Passenger* this, int* estado)
{
	int rtn = -1;

	if(this != NULL && (*estado >= 1 || *estado <= 3))
	{
		*estado = this ->isEmpty;
		rtn = 0;
	}
	return rtn;
}

void displayTypes(PassengerType* type, int len)
{
		printf("TIPO DE VUELO\n\n");
		for(int i = 0; i< len; i ++)
		{
			printf("%d- %s\n",type[i].idType, type[i].descripcion);
		}
}

void displayStatusFlight(PassengerStatus* status, int len)
{
		printf("ESTADO DEL VUELO\n\n");
		for(int i = 0; i< len; i ++)
		{
			printf("%d- %s\n",status[i].idStatus, status[i].descripcion);
		}
}

int ComparePassengerType(char* typeStr)
{
	int passengerType;
	if(strcmp(typeStr,"FirstClass") == 0)
		{
		passengerType =1;
		}
		else if(strcmp(typeStr,"ExecutiveClass") == 0)
		{
			passengerType = 2;
		}
		else if(strcmp(typeStr,"EconomyClass") == 0)
		{
			passengerType = 3;
		}
	return passengerType;
}

void changeType(int type, char* typeStr)
{
	if(type == 1)
	{
		strcpy(typeStr,"FirstClass");
	}
	else if(type == 2)
	{
		strcpy(typeStr,"ExecutiveClass");
	}
	else
	{
		strcpy(typeStr,"EconomyClass");
	}

}

void changeFlightStatus(int statusFlight, char* statusFlightStr)
{

		if(statusFlight == 1)
		{
			strcpy(statusFlightStr,"Aterrizado");
		}
		else if(statusFlight == 2)
		{
			strcpy(statusFlightStr,"En Horario");
		}
		else if(statusFlight == 3)
		{
			strcpy(statusFlightStr,"En Vuelo");
		}
		else
		{
			strcpy(statusFlightStr,"Demorado");
		}
}

int ComparePassengerStatus(char* statusStr)
{
	int passengerStatus;
		if(strcmp(statusStr,"Aterrizado") == 0)
			{
			passengerStatus =1;
			}
			else if(strcmp(statusStr,"En Horario") == 0)
			{
				passengerStatus = 2;
			}
			else if(strcmp(statusStr,"En Vuelo") == 0)
			{
				passengerStatus =3;
			}
			else if(strcmp(statusStr,"Demorado") == 0)
			{
				passengerStatus =4;
			}
	return passengerStatus;
}

void Passenger_print(LinkedList* pArrayPassenger, PassengerType*type,int typeLen, PassengerStatus* flightStatus, int flightLen)
{
	Passenger* pPassenger = NULL;
	int id;
	char name[100];
	char lastName[100];
	float price;
	char flyCode[100];
	int typePassenger;
	int statusFlight;
	if(pArrayPassenger != NULL)
	{
		for(int i = 0; i < ll_len(pArrayPassenger) ; i++)
		{

			pPassenger = ll_get(pArrayPassenger, i);


			if(pPassenger != NULL &&
					   Passenger_getId(pPassenger,&id) == 0 &&
					   Passenger_getNombre(pPassenger, name) == 0 &&
					   Passenger_getApellido(pPassenger, lastName) == 0 &&
					   Passenger_getPrecio(pPassenger, &price) == 0 &&
					   Passenger_getCodigoVuelo(pPassenger, flyCode) == 0 &&
					   Passenger_getTipoPasajero(pPassenger, &typePassenger) == 0 &&
					   Passenger_getEstado(pPassenger, &statusFlight) == 0 )
			{

						for(int j = 0; j < typeLen ; j ++)
						{
							if(typePassenger== type[j].idType)
							{
								for(int k = 0; k< flightLen;k ++)
								{

										if(statusFlight == flightStatus[k].idStatus)
										{
											printf("%4d 	%25s 		%25s 			$%-10.2f 		%20s 	%20s 	%20s \n",id , name, lastName, price, flyCode, type[j].descripcion, flightStatus[k].descripcion);
										}
								}
							}
						}
				}
		}
	}
}

void One_PassengerPrint(LinkedList* pArrayPassenger, PassengerType*type,int typeLen, PassengerStatus* flightStatus, int flightLen, int index)
{
	Passenger* pPassenger = NULL;
	int id;
		char name[100];
		char lastName[100];
		float price;
		char flyCode[100];
		int typePassenger;
		int statusFlight;

		if(pArrayPassenger != NULL)
		{
			pPassenger = ll_get(pArrayPassenger, index);
		}
		if(pPassenger != NULL &&
	   Passenger_getId(pPassenger,&id) == 0 &&
	   Passenger_getNombre(pPassenger, name) == 0 &&
	   Passenger_getApellido(pPassenger, lastName) == 0 &&
	   Passenger_getPrecio(pPassenger, &price) == 0 &&
	   Passenger_getCodigoVuelo(pPassenger, flyCode) == 0 &&
	   Passenger_getTipoPasajero(pPassenger, &typePassenger) == 0 &&
	   Passenger_getEstado(pPassenger, &statusFlight) == 0 )
		{

					for(int j = 0; j < typeLen ; j ++)
					{
						if(typePassenger== type[j].idType)
						{
							for(int k = 0; k< flightLen;k ++)
							{

									if(statusFlight == flightStatus[k].idStatus)
									{
										printf("%4d 	%25s 		%25s 			$%-10.2f 		%20s 	%20s 	%20s \n",id , name, lastName, price, flyCode, type[j].descripcion, flightStatus[k].descripcion);
									}
							}
						}
					}
			}
}
int increaseId(char* path)
{
	FILE* pIdFile = NULL;
	int idAux;

	pIdFile = fopen(path, "rb");

		if(pIdFile !=NULL)
		{
			fread(&idAux,sizeof(int),1,pIdFile);
			idAux ++;
		}
		fclose(pIdFile);

	pIdFile = fopen(path, "wb");
		if(pIdFile != NULL)
		{
			fwrite(&idAux,sizeof(int),1,pIdFile);
		}
		fclose(pIdFile);
	return idAux;
}

int id_Max(char* path)
{
		FILE* pFile = NULL;
		pFile = fopen(path,"r");
		int idAux;
			if(pFile !=NULL)
		{
			fread(&idAux,sizeof(int),1,pFile);
		}
		fclose(pFile);

	return idAux;
}


int Passenger_searchForId(LinkedList* pArrayListPassenger, int id)
{
	Passenger* pPassenger = NULL;
	int idAux;
	int returnedIndex;

if(pArrayListPassenger != NULL)
{
	for(int i= 0; i < ll_len(pArrayListPassenger); i++)
	{
		pPassenger = ll_get(pArrayListPassenger,i);
		if(pPassenger != NULL && Passenger_getId(pPassenger, &idAux) == 0 && id == idAux)
		{
			returnedIndex = i;
		}
	}
}
	return returnedIndex;
}
Passenger* getPassenger(LinkedList* pArrayListPassenger, PassengerType* passengerType, int typeLen, PassengerStatus* flightStatus, int flightLen)
{
	int index;
	int idMax;
	int id;


	Passenger* pPassenger = NULL;
	Passenger* rtn = NULL;

		idMax =id_Max("idFile.bin");
		Passenger_print(pArrayListPassenger, passengerType, typeLen, flightStatus, flightLen);
		id = EnterNumberInt("Ingrese el Id de un pasajero: ", "Error, ingrese un Id valido: ", idMax , 1);
		index =Passenger_searchForId(pArrayListPassenger, id);
		pPassenger = ll_get(pArrayListPassenger,  index);


		printf("index %d\n",index);

		if(pPassenger != NULL && pPassenger->id  == id)
		{
			rtn = pPassenger;
		}
		else
		{
			rtn = NULL;
		}


	return rtn;
}


Passenger* addPassenger(PassengerType* passengerType, int typeLen, PassengerStatus* flightStatus, int flightLen)
{
	Passenger* pPassenger;
	char id[130];
	char name[130];
	char lastName[130];
	char price[130];
	char flyCode[130];
	char typePassenger[130];
	char statusFlight[130];

	int idAux;
	float priceAux;
	int typeAux;
	int statusAux;

	idAux = increaseId("idFile.bin");
	printf("ID Del pasajero: %d\n",idAux);
	EnterString("Ingrese el nombre del pasajero: ", name);
	system("cls");
	EnterString("Ingrese el apellido del pasajero: ", lastName);
	system("cls");
	priceAux = EnterNumberFloat("Ingrese el precio del vuelo: ", "Error, ha ingresado un precio invalido: ",0);
	system("cls");
	displayTypes(passengerType, typeLen);
	typeAux = EnterNumberInt("Ingrese la clase del pasajero: ", "Error, ingrese una opcion valida (1-3): ", 3, 1);
	system("cls");
	EnterStringWithNumbers("Ingrese el codigo de vuelo del pasajero: ", flyCode);
	system("cls");
	displayStatusFlight(flightStatus, flightLen);
	statusAux = EnterNumberInt("Ingrese el estado del vuelo: ", "Error, ingrese una opcion valida (1-4): ", 4, 1);


	itoa(idAux,id,10);
	itoa(priceAux,price,10);
	changeFlightStatus(statusAux, statusFlight);
	changeType(typeAux, typePassenger);


	NormalizeStringToUpper(flyCode);
	pPassenger =  Passenger_newParametros(id, name, lastName, price, flyCode, typePassenger, statusFlight);

	return pPassenger;
}

int editPassenger( PassengerType* passengerType, int typeLen, PassengerStatus* flightStatus, int flightLen, Passenger* pPassenger)
{
	int rtn = -1;
	int option ;
	char auxChar[120];
	float auxFloat;
	int auxInt;


		printf("\n1-Nombre\n2-Apellido\n3-Precio\n4-Codigo de vuelo\n5-Clase del pasajero\n6-Estado del vuelo\n0-Salir\n");
		option = EnterNumberInt("Ingrese que desea modificar: "	,"\nError, verifique que la opcion ingresada sea valida(6-0)\n",6, 0);

		switch(option)
		{
		case 1:
						EnterString("Ingrese el nombre del usuario a modificar: ", auxChar);
						Passenger_setNombre(pPassenger, auxChar);
						rtn = 0;
						break;
		case 2:
						EnterString("Ingrese el apellido del usuario a modificar: ", auxChar);
						Passenger_setApellido(pPassenger, auxChar);
						rtn = 0;
						break;
		case 3:
						auxFloat=	EnterNumberFloat("Ingrese el precio a modificar: ", "Error, ingrese un precio valido: ", 0);
						Passenger_setPrecio(pPassenger, auxFloat);
						rtn = 0;
						break;
		case 4:
						EnterStringWithNumbers("Ingrese el codigo de vuelo a modificar: ", auxChar);
						NormalizeStringToUpper(auxChar);
						Passenger_setCodigoVuelo(pPassenger, auxChar);
						rtn = 0;
						break;
		case 5:
						displayTypes(passengerType, typeLen);
						auxInt = EnterNumberInt("Ingrese tipo de pasajero: ", "Error ingrese un tipo de pasajero valido (1-3) ", 3, 1);
						Passenger_setTipoPasajero(pPassenger, auxInt);
						rtn = 0;
						break;
		case 6:
						displayStatusFlight(flightStatus, flightLen);
						auxInt = EnterNumberInt("Ingrese estado del vuelo del pasajero: ", "Error ingrese un estado de vuelo valido (1-4) ", 4, 1);
						Passenger_setEstado(pPassenger, auxInt);
						rtn = 0;
						break;
		case 0:
						break;


		}

	return rtn;
}

int removePassenger(LinkedList* pArrayListPassenger, PassengerType* passengerType, int typeLen, PassengerStatus* flightStatus, int flightLen,Passenger* pPassenger, int index)
{
	int rtn;
	int option;

		One_PassengerPrint(pArrayListPassenger, passengerType, typeLen, flightStatus, flightLen, index);
		printf("Desea eliminar este pasajero?\n1-Si\n2-No\n\n");
		option = EnterNumberInt("Ingrese una opcion; ", "Ingrese una opcion valida (1-2): ", 2,1);
		switch(option)
		{
		case 1:
			ll_remove(pArrayListPassenger, index);
			Passenger_delete(pPassenger);
			rtn = 0;
			break;
		case 2:
			rtn = -1;
			break;
		}

		return rtn;
}

int SortPassengersMenu(LinkedList* pArrayListPassenger)
{
	int rtn = -1;;
	int option;
		printf("Ordenar lista por\n1-ID\n2-Nombre\n3-Apellido\n4-Precio\n0-Volver al menu principal");
		option=EnterNumberInt("\nSeleccione una opcion: ", "\nError, verifique que la opcion sea valida\n", 4, 0);

		switch(option)
		{
		case 1:
				rtn = sortPassengerByIdSubMenu(pArrayListPassenger);
			break;

		case 2:
				rtn =  sortPassengersByNameSubMenu(pArrayListPassenger);
			break;

		case 3:
				rtn = sortPassengersByLastNameSubMenu(pArrayListPassenger);
			break;

		case 4:
				rtn = sortPassengersByPriceSubMenu(pArrayListPassenger);
			break;
		case 0:
				rtn = 1;
		}

	return rtn;
}

int PassengerSortNames(void* elementOne, void* elementTwo)
{
	char auxA[50];
	char auxB[50];
	int rtn;

		Passenger_getNombre(elementOne, auxA);
		Passenger_getNombre(elementTwo, auxB);
		rtn = strcmp(auxA,auxB);

	return rtn;
}
int PassengerSortLastNames(void* elementOne, void* elementTwo)
{
	char auxA[50];
	char auxB[50];
	int rtn;

	Passenger_getApellido(elementOne, auxA);
	Passenger_getApellido(elementTwo, auxB);
	rtn = strcmp(auxA,auxB);

	return rtn;
}

int PassengerSortIds(void* elementOne, void* elementTwo)
{
	int rtn;
	int auxA;
	int auxB;

		Passenger_getId(elementOne, &auxA);
		Passenger_getId(elementTwo, &auxB);

	if(auxA > auxB)
	{
		rtn = 1;
	}
	else if(auxA < auxB)
	{
		rtn = -1;
	}
	else
	{
		rtn = 0;
	}

	return rtn;
}
int PassengerSortPrices(void* elementOne, void* elementTwo)
{
		int rtn;
		float auxA;
		float auxB;

			Passenger_getPrecio(elementOne, &auxA);
			Passenger_getPrecio(elementTwo, &auxB);

		if(auxA > auxB)
		{
			rtn = 1;
		}
		else if(auxA < auxB)
		{
			rtn = -1;
		}
		else
		{
			rtn = 0;
		}

		return rtn;
}

int sortPassengerByIdSubMenu(LinkedList* pArrayListPassenger)
{
	int rtn = -1;
	int option;
				printf("\nOrdenar por ID\n1-De manera ascendente\n2-De manera descendente");
				option=EnterNumberInt("\nSeleccione una opcion: ", "\nError, verifique que la opcion sea valida\n", 2, 1);

				switch (option)
				{
				case 1:
								printf("Esto puede demorar unos segundos...");
								ll_sort(pArrayListPassenger, PassengerSortIds, 1);
								rtn = 0;
								break;

				case 2:
								printf("Esto puede demorar unos segundos...");
								ll_sort(pArrayListPassenger, PassengerSortIds, 2);
								rtn = 0;
								break;

				}
				return rtn;
}

int sortPassengersByNameSubMenu(LinkedList* pArrayListPassenger)
{
	int rtn = -1;
	int option;
			printf("\nOrdenar por nombre\n1-De manera ascendente(A-Z)\n2-De manera descendente(Z-A)");
			option=EnterNumberInt("\nSeleccione una opcion: ", "\nError, verifique que la opcion sea valida\n", 2, 1);

			switch (option)
			{
			case 1:
							printf("Esto puede demorar unos segundos...");
							ll_sort(pArrayListPassenger, PassengerSortNames, 1);
							rtn = 0;
							break;

			case 2:
							printf("Esto puede demorar unos segundos...");
							ll_sort(pArrayListPassenger, PassengerSortNames, 2);
							rtn = 0;
							break;

			}
			return rtn;
}

int sortPassengersByLastNameSubMenu(LinkedList* pArrayListPassenger)
{
	int rtn = -1;
	int option;
			printf("\nOrdenar por apellido\n1-De manera ascendente(A-Z)\n2-De manera descendente(Z-A)");
			option=EnterNumberInt("\nSeleccione una opcion: ", "\nError, verifique que la opcion sea valida\n", 2, 1);

			switch (option)
			{
			case 1:
							printf("Esto puede demorar unos segundos...");
							ll_sort(pArrayListPassenger, PassengerSortLastNames, 1);
							rtn = 0;
							break;

			case 2:
							printf("Esto puede demorar unos segundos...");
							ll_sort(pArrayListPassenger, PassengerSortLastNames, 2);
							rtn = 0;
							break;

			}
			return rtn;
}


int sortPassengersByPriceSubMenu(LinkedList* pArrayListPassenger)
{
	int rtn = -1;
	int option;
				printf("\nOrdenar por precio\n1-De manera ascendente\n2-De manera descendente");
				option=EnterNumberInt("\nSeleccione una opcion: ", "\nError, verifique que la opcion sea valida\n", 2, 1);

				switch (option)
				{
				case 1:
								printf("Esto puede demorar unos segundos...");
								ll_sort(pArrayListPassenger, PassengerSortPrices, 1);
								rtn = 0;
								break;

				case 2:
								printf("Esto puede demorar unos segundos...");
								ll_sort(pArrayListPassenger, PassengerSortPrices, 2);
								rtn = 0;
								break;

				}
				return rtn;
}
