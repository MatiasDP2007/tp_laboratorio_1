

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

typedef struct
{
	int id;
	char name[51];
	char lastName[51];
	float price;
	char flycode[51];
	int typePassenger;
	int isEmpty;
	int statusFlight;
} sPassenger;

typedef struct
{
	int idType;
	char description [51];

}sPassengerType;

typedef struct
{
	int idStatus;
	char description [51];
}sStatusFlight;

/// @brief Inicializa la lista de pasajeros
///
/// @param list
/// @param len
/// @return
int initPassengers(sPassenger* list, int len);

/// @brief Valida que se haya ingresado al menos un pasajero
///
/// @param list
/// @param len
/// @return
int passengerStatus(sPassenger* list, int len);

/// @brief Muestra la lista de tipos de vuelo que hay(Hardcodeados)
///
/// @param type
/// @param len
void displayTypes(sPassengerType* type , int len);

/// @brief Muestra la lista de tipos de Estado de vuelo que hay
///
/// @param status
/// @param len
void displayStatusFlight(sStatusFlight* status, int len);

/// @brief Imprime la lista de pasajeros
///
/// @param passenger
/// @param len
/// @param type
/// @param typeLen
/// @param status
/// @param statusLen
void printPassengers(sPassenger* passenger,int len, sPassengerType* type,int typeLen, sStatusFlight* status, int statusLen);

/// @brief matchea la llave primaria de la estructura del los tipos de estado de vuelo con la llame foraña de la estructura de pasajeros
///
/// @param passenger
/// @param type
/// @param typeLen
/// @param status
/// @param statusLen
void matchFlightStatus(sPassenger passenger, sPassengerType* type,int typeLen, sStatusFlight* status, int statusLen);

/// @brief Muestra un solo pasajero
///
/// @param passenger
/// @param typeLen
/// @param type
/// @param status
void DisplayOnePassenger(sPassenger passenger,int typeLen, sPassengerType* type, sStatusFlight status);

/// @brief Toma los datos que ingresa el usuario y se los pasa a la funcion addPassenger para agragarlo a una estructura
///
/// @param passenger
/// @param len
/// @param passengerType
/// @param typeLen
/// @param id
/// @param statusFlight
/// @param statusLen
/// @return
int dataEntry(sPassenger* passenger,int len, sPassengerType* passengerType, int typeLen,int* id, sStatusFlight* statusFlight, int statusLen);

/// @brief recibe por parametro los datos ingresados por el usuario y los carga en el array
///
/// @param passenger
/// @param len
/// @param id
/// @param name
/// @param lastName
/// @param price
/// @param typePassenger
/// @param flycode
/// @param flightStatus
/// @return
int addPassenger(sPassenger* passenger,int len, int id,char name[],char
		lastName[],float price,int typePassenger, char flycode[],int flightStatus);

/// @brief recibe como parametro un numero ingresado y se encarga de buscarlo en la lista de albumes para devolver en que indice se encuentra
///
/// @param passenger
/// @param len
/// @param id
/// @return
int findPassengerById (sPassenger* passenger, int len, int id);

/// @brief
///
/// @param muestra los Id cargados, Toma el id del album que esta buscando, se lo envia al a funcion findPassengerById
/// @param len
/// @param id
/// @param type
/// @param typeLen
/// @param statusFlight
/// @param statusLen
/// @return
int searchForId(sPassenger* passenger, int len, int *id, sPassengerType* type, int typeLen, sStatusFlight* statusFlight, int statusLen);

/// @brief Realiza una baja logica del sistema
///
/// @param passenger
/// @param len
/// @param id
/// @return
int removePassenger (sPassenger* passenger, int len, int id);

/// @brief abre un submenu el cual permite ingresar que campo vas a modificar
///
/// @param passenger
/// @param len
/// @param id
/// @param type
/// @param typeLen
/// @param status
/// @param statusLen
/// @return
int modifyPassenger(sPassenger* passenger, int len, int id, sPassengerType* type, int typeLen, sStatusFlight* status, int statusLen);

/// @brief modifica el nombre en el id ingresado
///
/// @param passenger
/// @param len
/// @param index
/// @return
int modifyName(sPassenger* passenger, int len, int index);

/// @brief modifica el apellido en el id ingresado
///
/// @param passenger
/// @param len
/// @param index
/// @return
int modifyLastName(sPassenger* passenger, int len, int index);

/// @brief modifica el precio en el id ingresado
///
/// @param passenger
/// @param len
/// @param index
/// @return
int modifyPrice(sPassenger* passenger, int len, int index);

/// @brief modifica el tipo de pasajero en el id ingresado
///
/// @param passenger
/// @param len
/// @param index
/// @param type
/// @param typeLen
/// @return
int modifyPassengerType(sPassenger* passenger, int len, int index, sPassengerType* type, int typeLen);

/// @brief modifica el estado del vuelo en el id ingresado
///
/// @param passenger
/// @param len
/// @param index
/// @param status
/// @param statusLen
/// @return
int modifyStatusFlight(sPassenger* passenger, int len, int index,sStatusFlight* status, int statusLen);

/// @brief modifica el codigo del vuelo del id ingresado
///
/// @param passenger
/// @param len
/// @param index
/// @return
int modifyFlightCode(sPassenger* passenger, int len, int index);


/// @brief submenu en el cual tiene las funciones principales para el menu de listado
///
/// @param passenger
/// @param len
/// @param type
/// @param typeLen
/// @param status
/// @param statusLen
/// @return
int reportSubMenu(sPassenger* passenger, int len, sPassengerType* type, int typeLen, sStatusFlight* status, int statusLen);

/// @brief abre un submenu para ingresar el tipo de listado
///
/// @return
int OrderMenu(void);

/// @brief contiene las funciones del ordenamiento por apellido
///
/// @param passenger
/// @param len
/// @param order
/// @return
int sortPassengers(sPassenger* passenger, int len, int order);

/// @brief ordena la lista por apellido de manera ascendente
///
/// @param passenger
/// @param len
/// @return
int SortListByLastNameAsc(sPassenger* passenger, int len);

/// @brief ordena la lista por apellido de manera descendente
///
/// @param passenger
/// @param len
/// @return
int SortListByLastNameDes(sPassenger* passenger, int len);

/// @brief Realiza los calculos y muestra el listado
///
/// @param passenger
/// @param len
/// @return
int CalculateFlightPrices(sPassenger* passenger, int len);

/// @brief ocontiene las funciones del ordenamiento por apellido
///
/// @param passenger
/// @param len
/// @param order
/// @return
int sortPassengersByCode(sPassenger* passenger, int len, int order);

/// @brief ordena la lista por codigo de vuelo de manera ascendente
///
/// @param passenger
/// @param len
/// @return
int SortListByFlyCodeAsc(sPassenger* passenger, int len);

/// @brief ordena la lista por codigo de vuelo de manera descendente
///
/// @param passenger
/// @param len
/// @return
int SortListByFlyCodeDes(sPassenger* passenger, int len);
#endif /* ARRAYPASSENGER_H_ */

