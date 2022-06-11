#include "parser.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
		Passenger* pPassenger;
		int rtn = -1;
		char id[130];
		char name[130];
		char lastName[130];
		char price[130];
		char flyCode[130];
		char typePassenger[130];
		char statusFlight[130];
		int validatedId;
		int validatedName;
	//	int validatedLastName;
		int validatedPrice;
		int validatedFlyCode;
		int validatedTypePassenger;
		int validatedStatusFlight;

		if(pFile !=NULL && pArrayListPassenger != NULL)
		{

				fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,name,lastName,price,flyCode,typePassenger,statusFlight);
				do{

				fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,name,lastName,price,flyCode,typePassenger,statusFlight);
				validatedId = ValidateNumberIntWithoutRestriction(id);
				validatedName = ValidateString(name);
			//	validatedLastName = ValidateString(lastName);
				validatedPrice =ValidateNumberFloat(price, 0);
				validatedFlyCode = ValidateStringWithNumbers(flyCode);
				validatedTypePassenger = ValidateString(typePassenger);
				validatedStatusFlight = ValidateString(statusFlight);

			//	printf("%5s 		%25s  		%25s  		$%-20s 	%20s 	%20s  	%20s \n", id, name, lastName, price, flyCode, typePassenger, statusFlight);

					if(validatedId != -1 && validatedName != -1   && validatedPrice != -1  &&
					   validatedFlyCode != -1 && validatedTypePassenger != -1  && validatedStatusFlight != -1) //Se valida que la lista no venga con un error previo
					{

						pPassenger = Passenger_newParametros(id, name, lastName, price, flyCode, typePassenger, statusFlight);

							if(pPassenger != NULL)
							{
								ll_add(pArrayListPassenger, pPassenger);
								rtn = 0;
							}
					}

				}while(feof (pFile) == 0);
		}

	    return rtn;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{

	Passenger* pPassenger = NULL;
		int rtn = -1;

		if(pArrayListPassenger != NULL && pFile !=NULL)
		{
			do
			{
				pPassenger = Passenger_new();
				if(pPassenger != NULL)
					{
					if(fread(pPassenger,sizeof(Passenger),1,pFile)== 1)
					{
						ll_add(pArrayListPassenger, pPassenger);
						rtn = 0;
					}
				}
			}while(!feof(pFile));

		}
	    return rtn;
}

int generateIdFile(char* path)
{
	FILE* pGenerateId;
	int mainId = 1000;
	int flagRetorno = -1;
	pGenerateId = fopen(path,"wb");
	if(pGenerateId != NULL)
	{
		fwrite(&mainId,sizeof(int),1,pGenerateId);
		flagRetorno = 0;
	}
	fclose(pGenerateId);
	return flagRetorno;
}

int SaveTextList(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int rtn = -1;
	Passenger* pPassenger = NULL;
	int id;
	char name[100];
	char lastName[100];
	float price;
	char flyCode[100];
	int typePassenger;
	int statusFlight;

	char idAux[50];
	char priceAux[100];
	char typeAux[100];
	char statusAux[100];
	fprintf(pFile,"id,name,lastName,price,flycode,typePassenger,statusFlight\n");
						for(int i=0; i<ll_len(pArrayListPassenger); i ++)
						{
							pPassenger = ll_get(pArrayListPassenger, i);
							if(pPassenger != NULL &&
								   Passenger_getId(pPassenger,&id) == 0 &&
								   Passenger_getNombre(pPassenger, name) == 0 &&
								   Passenger_getApellido(pPassenger, lastName) == 0 &&
								   Passenger_getPrecio(pPassenger, &price) == 0 &&
								   Passenger_getCodigoVuelo(pPassenger, flyCode) == 0 &&
								   Passenger_getTipoPasajero(pPassenger, &typePassenger) == 0 &&
								   Passenger_getEstado(pPassenger, &statusFlight) == 0 )
									{
										{
												itoa(id,idAux,10);
												itoa(price,priceAux,10);
												changeFlightStatus(statusFlight, statusAux);
												changeType(typePassenger, typeAux);
												fprintf(pFile,"%s,%s,%s,%s,%s,%s,%s\n",idAux,name,lastName,priceAux,flyCode,typeAux,statusAux);
												rtn = 0;
										}

									}

							}
						fclose(pFile);
						return rtn;
}

int SaveBinaryList(FILE* pFile , LinkedList* pArrayListPassenger, char* path)
{
		int rtn = -1;
		Passenger* pPassenger = NULL;

		if(pArrayListPassenger != NULL)
		{
				if(pFile !=NULL)
				{
						for(int i = 0; i<ll_len(pArrayListPassenger); i++)
						{
								pPassenger = ll_get(pArrayListPassenger,i);
								if(pPassenger !=NULL)
								{
									fwrite(pPassenger,sizeof(Passenger),1,pFile);
									rtn = 0;
								}
						}
				}
			}
		return rtn;
}
int CheckSavedData(LinkedList* pArrayListPassenger, int flagSave)
{
	int option;
	int rtn = -1;
	if(flagSave != 0)
		{
			printf("No se guardaron los cambios. ¿Desea salir?\n1-SI\n2-NO\n");
			option=EnterNumberInt("Selecciona una opcion: ", "\nError, selecciona una opcion valida\n", 2,1);
			switch(option)
			{
			case 1:
				ll_deleteLinkedList(pArrayListPassenger);
				rtn = -1;
			break;

			case 2:
				rtn = 0;
				break;
			}

		}
	return rtn;
}
