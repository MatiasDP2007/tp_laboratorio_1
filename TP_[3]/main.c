#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#define TYPE_LEN 3
#define FLIGHT_LEN 4

int main()
{
PassengerType type [TYPE_LEN]= {{1,"FirstClass"},{2,"ExecutiveClass"},{3,"EconomyClass"}};
PassengerStatus flightStatus[FLIGHT_LEN]= {{1,"Aterrizado"},{2,"En Horario"},{3,"En Vuelo"},{4,"Demorado"}};

	setbuf(stdout,NULL);
    int option = 0;
    int flagSave = -1;
    int overWriteData = 1;
    int checkSave = -1;

    // Llamado a funcion que genera el archivo del ID
/*  if(generateIdFile("idFile.bin") == 0)
    {
    	printf("Se creo y cargo id en lista binaria");
    }*/
    LinkedList* listaPasajeros = ll_newLinkedList();
    do{
    			controller_Menu();

    			option = EnterNumberInt("Ingrese una opcion: ", "Error, Ingrese una opcion valida: ", 10, 1);

    			while((option != 1 && option != 2  && option != 3 && option != 10 )&& controller_CheckListStatus(listaPasajeros) != 0)
    			{
    				system("cls");
    				printf("Primero debera cargar un pasajero para poder utilizar todas las funciones\n\n");
    				controller_Menu();
    				option = EnterNumberInt("Ingrese una opcion: ", "Error, Ingrese una opcion valida: ", 10, 1);
    			}
        switch(option)
        {
            case 1:
					checkSave =controller_loadFromText("data.csv",listaPasajeros,overWriteData);
					overWriteData = -1;
					break;
            case 2:
            		checkSave =controller_loadFromBinary("data.bin", listaPasajeros,overWriteData);
            		overWriteData = -1;
            		break;
            case 3:
            		checkSave =controller_addPassenger(listaPasajeros, type, TYPE_LEN, flightStatus, FLIGHT_LEN);
					break;

            case 4:
					controller_editPassenger(listaPasajeros, type, TYPE_LEN, flightStatus, FLIGHT_LEN);
					break;

            case 5:
            		controller_removePassenger(listaPasajeros, type, TYPE_LEN, flightStatus, FLIGHT_LEN);
            		break;

            case 6:
            		controller_ListPassenger(listaPasajeros,type,TYPE_LEN,flightStatus,FLIGHT_LEN);
            		break;
            case 7:
            		controller_sortPassenger(listaPasajeros);
            		break;
            case 8:
            		if(checkSave == 0)
            		{
            			flagSave = controller_overWriteText(listaPasajeros);

            		}
            		else
            		{
            			controller_saveAsText("data.csv", listaPasajeros);
            			flagSave = 1;
            		}

            		break;
            case 9:
            		if(checkSave == 0)
            		{
					flagSave = controller_overWriteBin(listaPasajeros);
					}
            		else
            		{
            			controller_saveAsBinary("data.bin", listaPasajeros);
            			flagSave = 1;
            		}
            		break;

            case 10:
					if(ll_len(listaPasajeros) != 0 && flagSave != 1)
					{
						option =controller_exit(listaPasajeros, flagSave);
						break;
					}



        }
    }while(option != 10);
    return 0;
}

