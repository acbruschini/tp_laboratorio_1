/*
 * bruschini.c
 *
 *  ACTUALIZADO 17 ABRIL 2020
 *      Author: Ariel
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int getString(char cadena[], int len);
static int getFloat(float* pResultado);
static int getInt(int* pResultado);
static int getNombre(char* pResultado, int longitud);
static int getDescripcion(char* pResultado, int longitud);
static int getDni(char* pResultado, int longitud);
static int getMail(char* pResultado, int longitud);
static int getCuit(char* pResultado, int longitud);
static int isInt (char pArray[], int len);
static int isFloat (char pArray[]);
static int isNombre(char* cadena,int longitud);
static int isDescripcion(char* cadena,int longitud);
static int isDNI(char* cadena,int longitud);
static int isMail(char* cadena,int longitud);
static int isCuit(char* cadena,int longitud);


/** \brief ENTRADA Pide al usuario un numero ENTERO
 * \param pResultado Puntero donde va el numero ya validado
 * \return int -1 si hay error, 0 si salio bien
 *
 */
static int getString(char cadena[], int len)
{
	int retorno = -1;
	char bufferString[4096];

	if (cadena != NULL && len > 0)
	{
		#ifdef __unix__
		__fpurge(stdin);
		#else
			fflush(stdin);
		#endif // __unix

		if (fgets(bufferString,sizeof(bufferString),stdin) != NULL)
		{
			if (bufferString[strlen(bufferString)-1] == '\n') // PREGUNTO SI EXISTE EL ENTER
			{
				bufferString[strlen(bufferString)-1] = '\0'; // SI EXISTE LO REEMPLAZO CON EL \0
			}

			if (strlen(bufferString) <= len)
			{
				strncpy(cadena,bufferString,len);
				retorno = 0;
			}
		}


	}

	return retorno;
}

/**
 * \brief Verifica si la cadena ingresada es flotante
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero flotante y -1 (ERROR) si no
 *
 */
static int getFloat(float* pResultado)
{
    int retorno=-1;
    char buffer[64];

    if(pResultado != NULL)
    {
    	if(getString(buffer,sizeof(buffer))==0 && isFloat(buffer))
    	{
			*pResultado = atof(buffer);
			retorno = 0;
		}
    }
    return retorno;
}

/** \brief ENTRADA Pide al usuario un numero ENTERO
 * \param pResultado Puntero donde va el numero ya validado
 * \return int -1 si hay error, 0 si salio bien
 *
 */
static int getInt(int* pResultado)
{
	int retorno = -1;
	char bufferString[50]; // hardcodeado

	if (pResultado != NULL)
	{

		if (getString(bufferString, sizeof(bufferString)) == 0 && isInt (bufferString,sizeof(bufferString)) == 1) // Si myGets esta OK, y IsInt == 1 (porque 1 es verdadero y se puede convertir)
		{
			*pResultado = atoi(bufferString);
			retorno = 0;
		}

	}

	return retorno;
}

/**
 * \brief Obtiene un string valido como nombre
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero flotante y -1 (ERROR) si no
 *
 */
static int getNombre(char* pResultado, int longitud)
{
    int retorno=-1;
    char buffer[4096];

    if(pResultado != NULL)
    {
    	if(	getString(buffer,sizeof(buffer))==0 &&
    		isNombre(buffer,sizeof(buffer)) &&
			strnlen(buffer,sizeof(buffer))<longitud)
    	{
    		strncpy(pResultado,buffer,longitud);
			retorno = 0;
		}
    }
    return retorno;
}
/**
 * \brief Obtiene un string valido como descripcion
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero flotante y -1 (ERROR) si no
 *
 */
static int getDescripcion(char* pResultado, int longitud)
{
    int retorno=-1;
    char buffer[4096];

    if(pResultado != NULL)
    {
    	if(	getString(buffer,sizeof(buffer))==0 &&
    		isDescripcion(buffer,sizeof(buffer)) &&
			strnlen(buffer,sizeof(buffer))<longitud)
    	{
    		strncpy(pResultado,buffer,longitud);
			retorno = 0;
		}
    }
    return retorno;
}

/**
 * \brief Obtiene un string valido como DNI
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero flotante y -1 (ERROR) si no
 *
 */
static int getDni(char* pResultado, int longitud)
{
    int retorno=-1;
    char buffer[4096];

    if(pResultado != NULL)
    {
    	if(	getString(buffer,sizeof(buffer))==0 &&
    		isDNI(buffer,sizeof(buffer)) &&
			strnlen(buffer,sizeof(buffer))<longitud)
    	{
    		strncpy(pResultado,buffer,longitud);
			retorno = 0;
		}
    }
    return retorno;
}

/**
 * \brief Obtiene un string valido como DNI
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero flotante y -1 (ERROR) si no
 *
 */
static int getMail(char* pResultado, int longitud)
{
    int retorno=-1;
    char buffer[4096];

    if(pResultado != NULL)
    {
    	if(	getString(buffer,sizeof(buffer))==0 &&
    		isMail(buffer,sizeof(buffer)) &&
			strnlen(buffer,sizeof(buffer))<longitud)
    	{
    		strncpy(pResultado,buffer,longitud);
			retorno = 0;
		}
    }
    return retorno;
}

/**
 * \brief Obtiene un string valido como DNI
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero flotante y -1 (ERROR) si no
 *
 */
static int getCuit(char* pResultado, int longitud)
{
    int retorno=-1;
    char buffer[4096];

    if(pResultado != NULL)
    {
    	if(	getString(buffer,sizeof(buffer))==0 &&
    		isCuit(buffer,sizeof(buffer)) &&
			strnlen(buffer,sizeof(buffer))<longitud)
    	{
    		strncpy(pResultado,buffer,longitud);
			retorno = 0;
		}
    }
    return retorno;
}


/** \brief VALIDACION Chequea si un string puede ser convertido a INT
 * \param pArray String a chequear
 * \return 1 si se puede convertir, 0 si no y -1 si hubo error
 */
static int isInt (char pArray[], int len)
{
    int retorno=-1;
	int i;
	//int contadorPuntos=0;
	if(pArray != NULL)
	{
		retorno = 1;
		for(i=0;i<len && pArray[i]!='\0';i++)
		{
			if(pArray[i]<'0' || pArray[i]>'9') // SI NO SON NUMEROS
			{

				if (pArray[i] == '-' || pArray[i] == '+') // PERO SI NO SON NUMERO Y ES UN -
				{
					if (i != 0) // SI ES UN MENOS Y ESTA EN LA POSICION 0 ESTA OK.
					{
						retorno = 0;
					}
				}
				else
				{
				retorno = 0;
				}
			}

		}
	}

    return retorno;
}

/** \brief VALIDACION Chequea si un string puede ser convertido a FLOAT
 * \param pArray String a chequear
 * \return 1 si se puede convertir, 0 si no y -1 si hubo error
 *
 */
static int isFloat (char pArray[])
{
    int retorno = -1;
	int i;
	int contadorPuntos=0;
	if (pArray != NULL)
	{
		retorno = 1;
		for(i=0;pArray[i]!='\0';i++)
		{
			if(pArray[i]<'0' || pArray[i]>'9')
			{
				// no estoy en el rango de los numeros
				if(pArray[i]=='.') // es un punto
				{
					contadorPuntos++;
					if(contadorPuntos>1)
					{
						// encontre un segundo punto, doy error
						retorno=0;
						break;
					}
				}
				else
				{
					//Hay algo que no es un punto ni numero
					if(i==0)
					{
						// me pongo a ver que onda con el caracter
						if(pArray[i]!='+' && pArray[i]!='-')
						{
							retorno=0;
							break;
						}
					}
					else
					{
						retorno=0;
						break;
					}
				}
			}
		}
	}
	else
	{
		retorno = -1;
	}
    return retorno;
}

/**
 * \brief Verifica si la cadena ingresada es un nombre valido
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es valida y 0 (falso) si no lo es
 *
 */
static int isNombre(char* cadena,int longitud)
{
	int i=0;
	int retorno = 1;

	if(cadena != NULL && longitud > 0)
	{
		for(i=0 ; cadena[i] != '\0' && i < longitud; i++)
		{
			if((cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ))
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}
/**
 * \brief Verifica si la cadena ingresada es una descripcion valida
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es valida y 0 (falso) si no lo es
 *
 */
static int isDescripcion(char* cadena,int longitud)
{
	int i=0;
	int retorno = 1;

	if(cadena != NULL && longitud > 0)
	{
		for(i=0 ; cadena[i] != '\0' && i < longitud; i++)
		{
			if(cadena[i] != '.' && cadena[i] != ' ' && (cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ) && (cadena[i] < '0' || cadena[i] > '9' ) )
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}
/**
 * \brief Verifica si la cadena ingresada es DNI valido
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es valida,0 (falso) si no lo es, y -1 (ERROR)
 *
 */
static int isDNI(char* cadena,int longitud)
{
	int i=0;
	int retorno = -1;

	if(cadena != NULL && longitud > 0)
	{
		if (strlen(cadena) == 7 || strlen(cadena) == 8)
		{
			retorno = 1;

			for(i=0 ; cadena[i] != '\0' && i < longitud; i++)
			{
				if(cadena[i] < '0' && cadena[i] > '9')
				{
					retorno = 0;
					break;
				}
			}
		}
		else
		{
			retorno = 0;
		}

	}
	return retorno;
}

/**
 * \brief Verifica si la cadena ingresada es DNI valido
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es valida,0 (falso) si no lo es, y -1 (ERROR)
 *
 */
static int isMail(char* cadena,int longitud)
{
	/*
	int i=0;
	int retorno = -1;
	int flagPunto = 0;
	int flagArroba = 0;

	if(cadena != NULL && longitud > 0)
	{
		retorno = 1;
		printf ("la longitud es: %d \n",strlen(cadena));
		for (i=0;cadena[i] != '\0' && i < longitud;i++)
		{
			if (cadena[i] == '@' && flagArroba == 0 && i != 0 && i != strlen(cadena))
			{
				flagArroba = 1;
			}
		}


	}
	printf ("flagarroba fue: %d \n",flagArroba);
	*/
	return 0;
}

/**
 * \brief Verifica si la cadena ingresada es Cuit valido en formato 20-12345678-1
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es valida,0 (falso) si no lo es, y -1 (ERROR)
 *
 */
static int isCuit(char* cadena,int longitud)
{
	int i=0;
	int retorno = -1;

	if(cadena != NULL && longitud > 0)
	{
		if (strlen(cadena) == 13)
		{
			retorno = 1;

			for(i=0 ; cadena[i] != '\0' && i < longitud; i++)
			{

				if((i == 2 || i == 11) && cadena[i] != '-')
				{
					retorno = 0;
					break;
				}
				else
				{

					if(cadena[i] < '0' && cadena[i] > '9')
					{
						retorno = 0;
						break;
					}

				}

			}
		}
		else
		{
			retorno = 0;
		}

	}
	return retorno;
}

/** \brief ENTRADA Pide al usuario un numero ENTERO
 * \param pResultado Puntero donde va el numero
 * \param mensaje Mensaje al usuario antes de pedir el numero
 * \param mensajeError Mensaje al usuario si el numero es incorrecto
 * \param minimo Minimo de numero a ingresar
 * \param maximo Maximo de numero a ingresar
 * \param reintentos Cantidad de Reintentos
 * \return int -1 si hay error, 0 si salio bien
 *
 */
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	int bufferInt;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL)
	{
		do
		{
			printf("%s",mensaje);

			if (getInt (&bufferInt) == 0 && bufferInt >= minimo && bufferInt <= maximo)
			{

					*pResultado = bufferInt;
					retorno = 0;
					break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--;
			}

		}while(reintentos >= 0);
	}
	return retorno;
}

/**
 * \brief Solicita un numero flotante al usuario, luego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param minimo Es el numero maximo a ser aceptado
 * \param maximo Es el minimo minimo a ser aceptado
 * \return Retorna 0 si se obtuvo el numero flotante y -1 si no
 *
 */
int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos)
{
	float bufferFloat;
	int retorno = -1;
	while(reintentos>=0)
	{
		reintentos--;
		printf("%s",mensaje);
		if(getFloat(&bufferFloat) == 0)
		{
			if(bufferFloat >= minimo && bufferFloat <= maximo)
			{
				*pResultado = bufferFloat;
				retorno = 0;
				break;
			}
		}
		printf("%s",mensajeError);
	}
	return retorno;
}

/**
 * \brief Solicita un nombre al usuario, luego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param longitud Es la longitud del array resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param reintentos Cantidad de reintentos
 * \return Retorna 0 si se obtuvo el numero flotante y -1 si no
 *
 */
int utn_getNombre(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos)
{
	char bufferString[4096];
	int retorno = -1;
	while(reintentos>=0)
	{
		reintentos--;
		printf("%s",mensaje);
		if(getNombre(bufferString,sizeof(bufferString)) == 0 && strnlen(bufferString,sizeof(bufferString)) < longitud )
		{
			strncpy(pResultado,bufferString,longitud);
			retorno = 0;
			break;
		}
		printf("%s",mensajeError);
	}
	return retorno;
}
/**
 * \brief Solicita una descripcion al usuario, luego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param longitud Es la longitud del array resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param reintentos Cantidad de reintentos
 * \return Retorna 0 si se obtuvo el numero flotante y -1 si no
 *
 */
int utn_getDescripcion(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos)
{
	char bufferString[4096];
	int retorno = -1;
	while(reintentos>=0)
	{
		reintentos--;
		printf("%s",mensaje);
		if(getDescripcion(bufferString,sizeof(bufferString)) == 0 && strnlen(bufferString,sizeof(bufferString)) < longitud )
		{
			strncpy(pResultado,bufferString,longitud);
			retorno = 0;
			break;
		}
		printf("%s",mensajeError);
	}
	return retorno;
}
/**
 * \brief Solicita un DNI al usuario, luego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param longitud Es la longitud del array resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param reintentos Cantidad de reintentos
 * \return Retorna 0 si se obtuvo el numero flotante y -1 si no
 *
 */
int utn_getDni(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos)
{
	char bufferString[4096];
	int retorno = -1;
	while(reintentos>=0)
	{
		reintentos--;
		printf("%s",mensaje);
		if(getDni(bufferString,sizeof(bufferString)) == 0 && strnlen(bufferString,sizeof(bufferString)) < longitud )
		{
			strncpy(pResultado,bufferString,longitud);
			retorno = 0;
			break;
		}
		printf("%s",mensajeError);
	}
	return retorno;
}

/**
 * \brief Solicita un DNI al usuario, luego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param longitud Es la longitud del array resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param reintentos Cantidad de reintentos
 * \return Retorna 0 si se obtuvo el numero flotante y -1 si no
 *
 */
int utn_getMail(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos)
{
	char bufferString[4096];
	int retorno = -1;
	while(reintentos>=0)
	{
		reintentos--;
		printf("%s",mensaje);
		if(getMail(bufferString,sizeof(bufferString)) == 0 && strnlen(bufferString,sizeof(bufferString)) < longitud )
		{
			strncpy(pResultado,bufferString,longitud);
			retorno = 0;
			break;
		}
		printf("%s",mensajeError);
	}
	return retorno;
}

/**
 * \brief Solicita un DNI al usuario, luego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param longitud Es la longitud del array resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param reintentos Cantidad de reintentos
 * \return Retorna 0 si se obtuvo el numero flotante y -1 si no
 *
 */
int utn_getCuit(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos)
{
	char bufferString[4096];
	int retorno = -1;
	while(reintentos>=0)
	{
		reintentos--;
		printf("%s",mensaje);
		if(getCuit(bufferString,sizeof(bufferString)) == 0 && strnlen(bufferString,sizeof(bufferString)) < longitud )
		{
			strncpy(pResultado,bufferString,longitud);
			retorno = 0;
			break;
		}
		printf("%s",mensajeError);
	}
	return retorno;
}
/**
 * \brief Obtiene una confirmacion entre dos letras
 * \param mensaje Mensaje al usuario antes de pedir la letra
 * \param mensajeError Mensaje al usuario si la letra no es ninguna de las dos
 * \param opcion1 La letra que retornara 1 al confirmar
 * \param opcion2 la letra que retornara 0 al confirmar
 * \param reintentos Cantidad de Reintentos
 * \return Retorna 0 (si se elegio la Opcion1), 1 (si se elegio la opcion2) y -1 (ERROR)
 *
 */
int utn_isConfirmacion(char* mensaje, char* mensajeError, char* opcion1, char* opcion2, int reintentos)
{
	int retorno = -1;
	char buffer[2];

	 if(mensaje != NULL && mensajeError != NULL && opcion1 != NULL && reintentos >= 0)
	    {
			do
			{
				printf("%s",mensaje);
				if(	getString(buffer,sizeof(buffer))==0 &&
					(!strncmp(buffer,opcion1,sizeof(buffer)) || !strncmp(buffer,opcion2,sizeof(buffer))))
				{
					if (!strncmp(buffer,opcion1,sizeof(buffer)))
						{
							retorno = 1;
						}
						else
						{
							retorno = 0;
						}
					break;
				}
				else
				{
					printf("%s",mensajeError);
					reintentos--;
				}
			}while(reintentos >= 0);
	    }
	return retorno;
}
/** \brief MATEMATICA - Suma dos numeros float
 * \param pResultado Puntero donde va el resultado
 * \param num Float del numero A
 * \param num Float del numero B
 * \return int -1 si hay error, 0 si salio bien
 *
 */
float math_sumFloats(float* pResultado,float numA, float numB)
{
	int retorno = -1;
	float buffer = 0;

	if (pResultado != NULL)
	{
		retorno = 0;
		buffer = numA + numB;
		*pResultado = buffer;
	}
	return retorno;
}

/** \brief MATEMATICA - Resta dos numeros float
 * \param pResultado Puntero donde va el resultado
 * \param num Float del numero A
 * \param num Float del numero B
 * \return int -1 si hay error, 0 si salio bien
 *
 */
float math_subFloats(float* pResultado,float numA, float numB)
{
	int retorno = -1;
	float buffer;

	if (pResultado != NULL)
	{
		retorno = 0;
		buffer = numA - numB;
		*pResultado = buffer;
	}
	return retorno;
}

/** \brief MATEMATICA - Multiplica dos numeros float
 * \param pResultado Puntero donde va el resultado
 * \param num Float del numero A
 * \param num Float del numero B
 * \return int -1 si hay error, 0 si salio bien
 *
 */
float math_mulFloats(float* pResultado,float numA, float numB)
{
	int retorno = -1;
	float buffer;

	if (pResultado != NULL)
	{
		retorno = 0;
		buffer = numA * numB;
		*pResultado = buffer;
	}
	return retorno;
}

/** \brief MATEMATICA - Divide dos numeros float
 * \param pResultado Puntero donde va el resultado
 * \param num Float del numero A
 * \param num Float del numero B
 * \return int -1 si hay error, 0 si salio bien
 *
 */
float math_divFloats(float* pResultado,float numA, float numB)
{
	int retorno = -1;
	float buffer;

	if (pResultado != NULL && numB != 0)
	{
		retorno = 0;
		buffer = numA / numB;
		*pResultado = buffer;
	}
	return retorno;
}

/** \brief MATEMATICA - Calcula el factorial de un Float
 * \param pResultado Puntero donde va el resultado
 * \param num Float del numero a calcular
 * \return int -1 si hay error, 0 si salio bien
 *
 */
float math_factFloats(float* pResultado,float num)
{
	int retorno = -1;
	int i;
	int limite = num;
	float buffer = 1;

	if (pResultado != NULL && num >= 0 )
	{
		retorno = 0;

		for (i=0;i<limite;i++)
		{
			buffer = buffer * num;
			num --;
		}
		*pResultado = buffer;
	}
	return retorno;
}


/** \brief Muestra un menu basico
 * \param pArray Array multidimensional (El 0 es el titulo)
 * \param len Cantidad de opciones en el array
 * \return Retorna la opcion elegida entre 1 y el Len
 *
 */
int menu(char pArray[][300],int len)
{

	int i;
	int opcion;

	printf ("\n\n-----------------------------------------------------------------------------\n");
	printf ("%s\n",pArray[0]);
	printf ("-----------------------------------------------------------------------------\n\n");

	for (i=1; i<len ; i++)
	{

		printf ("%d - %s\n",i,pArray[i]);

	}

	printf (" \n-----------------------------------------------------------------------------\n");
	utn_getNumero(&opcion, "Elija una opcion del menu: ", "ERROR - ", 1, len-1, 3);


	return opcion;
}
