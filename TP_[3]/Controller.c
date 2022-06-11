#include "Controller.h"

void controller_Menu()
{
	printf("1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).\n"
	    			"2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).\n"
	    			"3. Alta de pasajero\n"
	    			"4. Modificar datos de pasajero\n"
	    			"5. Baja de pasajero\n"
	    			"6. Listar pasajeros\n"
	    			"7. Ordenar pasajeros\n"
	    			"8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto)\n"
	    			"9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).\n"
	    			"10. Salir\n\n");
}

int controller_CheckListStatus(LinkedList* pArrayListPassenger)
{

	int status = -1;
	if(ll_isEmpty(pArrayListPassenger) == 0 )
	{
		status = 0;
	}
	return status;
}


/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger, int OverWriteData)
{
	FILE* pFile = NULL;
	int rtn = -1;


	pFile = fopen(path,"r");

	if(pFile != NULL)
	{
		if(OverWriteData == 1)
		{
			rtn = parser_PassengerFromText(pFile, pArrayListPassenger);

		}
		system("cls");
		if(rtn == 0)
		{

			printf("Se cargo la lista correctamente\n\n");
		}
		else
		{
			printf("Ya se cargo la lista previamente\n");
		}
	}

	fclose(pFile);
    return rtn;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger, int OverWriteData)
{
		FILE* pFile;
		int rtn = -1 ;


		pFile = fopen(path,"rb");
		if(pFile != NULL)
		{
			if(OverWriteData == 1)
			{
				rtn  = parser_PassengerFromBinary(pFile, pArrayListPassenger);
			}
			system("cls");
			if (rtn == 0)
			{

				printf("Se cargo la lista de binaria de manera correcta\n\n");
			}else
			{
				printf("Ya se cargo la lista previamente\n\n");
			}
		}
		fclose(pFile);


    return 1;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger, PassengerType* type, int typeLen,PassengerStatus* status, int statusLen)
{
	Passenger* pPassenger;
		if(pArrayListPassenger != NULL)
		{
			system("cls");
			if(controller_overWriteData(pArrayListPassenger) == 0)
			{
				printf("Se ha cancelado la operacion\n\n");
			}
			else
			{
				pPassenger = addPassenger(type, typeLen, status, statusLen);
				system("cls");
				if(pPassenger != NULL)
				{

					if(ll_add(pArrayListPassenger, pPassenger) == 0)
					{
						printf("Se cargo al pasajero de manera correcta\n\n");
					}
					else
					{
						printf("Ocurrio un error al cargar al pasajero\n\n");
					}
				}
			}

		}

    return 1;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger, PassengerType* passengerType, int typeLen, PassengerStatus* flightStatus, int flightLen)
{
	int rtn;
	Passenger* pPassenger= NULL;

	if(pArrayListPassenger != NULL)
	{
		pPassenger= getPassenger(pArrayListPassenger, passengerType, typeLen, flightStatus, flightLen);

		if(pPassenger != NULL)
		{
			system("cls");
			rtn = editPassenger(passengerType, typeLen, flightStatus, flightLen, pPassenger);
			system("cls");
			if(rtn == 0)
			{
				printf("Se edito al pasajero de manera correcta\n\n");
			}
			else if(rtn == -1)
			{
				printf("Se cancelo la operacion \n\n");
			}
		}else
		{
			printf("No se encontro al pasajero en la base de datos \n\n");
		}
	}




    return 1;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger, PassengerType* passengerType, int typeLen, PassengerStatus* flightStatus, int flightLen)
{
	int rtn;
	int index;
		Passenger* pPassenger= NULL;
		if(pArrayListPassenger != NULL)
			{
				pPassenger= getPassenger(pArrayListPassenger, passengerType, typeLen, flightStatus, flightLen);
				if(pPassenger != NULL)
						{
							system("cls");
							index = ll_indexOf(pArrayListPassenger, pPassenger);
							rtn = removePassenger(pArrayListPassenger,passengerType, typeLen, flightStatus, flightLen, pPassenger ,index);
							system("cls");
							if(rtn == 0)
							{
								printf("Se elimino al pasajero de manera correcta\n\n");
							}
							else if(rtn == -1)
							{
								printf("Se cancelo la operacion \n\n");
							}
						}else
						{
							printf("No se encontro al pasajero en la base de datos \n\n");
						}
					}
    return 1;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int  controller_ListPassenger(LinkedList* pArrayListPassenger,PassengerType* type, int typeLen, PassengerStatus* flightStatus, int flightLen)
{

	int flagRetorno = -1;


	if(pArrayListPassenger != NULL)
	{
				  Passenger_print(pArrayListPassenger, type, typeLen, flightStatus, flightLen);
				  flagRetorno = 0;
	}
    return flagRetorno;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	int rtn;

	rtn = SortPassengersMenu(pArrayListPassenger);
	system("cls");
	if(rtn == 0)
	{
		printf("Se ordeno la lista de manera correcta\n\n");
	}
	else if(rtn == 1)
	{
		printf("Se ha cancelado la operacion\n\n");
	}
	else
	{
		printf("Ocurrio un error al ordenar la lista\n\n");
	}
    return 1;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	FILE* pFile = NULL;
	int rtn = -1;



		if(pArrayListPassenger != NULL)
		{
				pFile = fopen(path,"w");

				if(pFile != NULL)
				{
					rtn = SaveTextList(pFile, pArrayListPassenger);
					if(rtn ==  0)
					{
						printf("Se guardo lista correctamente\n\n");
					}
					else
					{
						printf("Ocurrio un error al guardar la lista\n\n");
					}
				}
		}
					fclose(pFile);
	    return rtn;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	FILE* pFile = NULL;
	int rtn = -1;

	pFile = fopen(path,"wb");
	   if(pFile != NULL)
	   {
		 rtn =  SaveBinaryList(pFile, pArrayListPassenger, path);

		 if(rtn != -1)
		 {
			 printf("Se guardo la lista de manera corecta\n\n");
		 }
		 else
		 {
			 printf("Ocurrio un error al guardar la lista\n\n");
		 }
	   }

	   return 1;
}

int controller_exit(LinkedList* pArrayListPassenger, int flagSave)
{

	int rtn = -1;
	rtn = CheckSavedData(pArrayListPassenger, flagSave);
	system("cls");
	if(rtn == 0)
	{
		printf("Se ha cancelado la operacion\n\n");
	}
	else
	{
		rtn = 10;
	}
	return rtn;
}

int controller_overWriteData(LinkedList* pArrayListPassenger)
{
		int flagRetorno;
		int option;
		if(ll_isEmpty(pArrayListPassenger) == 1)
		{
			printf("No se cargo la lista previamente\n¿Estas seguro que quieres dar el alta a un empleado?\nPuede que los datos se sobrescriban\n1-Continuar\n2-Volver al menu\n ");
			option=EnterNumberInt("Selecciona una opcion: ", "\nError, selecciona una opcion valida\n", 2,1);
			switch(option)
			{
			case 1:
				flagRetorno =-1;
				break;
			case 2:
				flagRetorno = 0;
			}
		}
		return flagRetorno;
	}

int controller_overWriteText(LinkedList* pArrayListPassenger)
{
	int option;
	int flagRetorno = 0;
	printf("Estas a punto de sobrescribir los datos sobre la lista que ha cargado, ¿Deseas continuar?\n1-Continuar\n2-Volver al menu principal\n");
	option=EnterNumberInt("Selecciona una opcion: ", "\nError, selecciona una opcion valida\n", 2,1);
		switch(option)
		{
		case 1:
		  if(controller_saveAsText("data.csv", pArrayListPassenger) == 0)
		  {
			  flagRetorno = 1;
			  printf("\nSe guardo correctamente el archivo\n\n");
		  }
		  break;


		case 2:
		break;
		}
		return flagRetorno;
}
int controller_overWriteBin(LinkedList* pArrayListPassenger)
{
	int option;
	int rtn = 0;
	printf("Estas a punto de sobrescribir los datos de la lista que se ha cargado, ¿Deseas continuar?\n1-CONTINUAR\n2-SALIR\n");
	option=EnterNumberInt("Selecciona una opcion: ", "\nError, selecciona una opcion valida\n", 2,1);
	   switch(option)
	  {
	  case 1:
		 if(controller_saveAsBinary("data.bin", pArrayListPassenger) == 0)
		 {
			 rtn = -1;
			  printf("\nSe guardo correctamente el archivo\n\n");
		 }
	  break;
	  case 2:
		  break;
	  }
	   return rtn;
}
