/*
 * utn.c
 *
 *  Created on: 7 abr. 2020
 *      Author: Ariel
 */

#include <stdio.h>
#include <stdlib.h>

/** \brief Pide al usuario un numero ENTERO
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
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);
			fflush (stdin);
			scanf("%d",&bufferInt);
			if(bufferInt >= minimo && bufferInt <= maximo)
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

/** \brief Pide al usuario un numero FLOTANTE
 * \param pResultado Puntero donde va el numero
 * \param mensaje Mensaje al usuario antes de pedir el numero
 * \param mensajeError Mensaje al usuario si el numero es incorrecto
 * \param minimo Minimo de numero a ingresar
 * \param maximo Maximo de numero a ingresar
 * \param reintentos Cantidad de Reintentos
 * \return int -1 si hay error, 0 si salio bien
 *
 */
int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos)
{
	int retorno = -1;
	float bufferFloat;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);
			fflush (stdin);
			scanf("%f",&bufferFloat);
			if(bufferFloat >= minimo && bufferFloat <= maximo)
			{
				*pResultado = bufferFloat;
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

/** \brief Pide al usuario un CHARACTER
 * \param pResultado Puntero donde va el caracter
 * \param mensaje Mensaje al usuario antes de pedir el caracter
 * \param mensajeError Mensaje al usuario si el character es incorrecto
 * \param minimo Minimo de caracter a ingresar
 * \param maximo Maximo de caracter a ingresar
 * \param reintentos Cantidad de Reintentos
 * \return int -1 si hay error, 0 si salio bien
 *
 */
int utn_getCaracter(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos)
{
	int retorno = -1;
	char bufferChar;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);
			fflush (stdin);
			scanf("%c",&bufferChar);
			if(bufferChar >= minimo && bufferChar <= maximo )
			{
				*pResultado = bufferChar;
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

/** \brief Suma dos numeros float
 * \param pResultado Puntero donde va el resultado
 * \param num Float del numero A
 * \param num Float del numero B
 * \return int -1 si hay error, 0 si salio bien
 *
 */
float sumFloats(float* pResultado,float numA, float numB)
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

/** \brief Resta dos numeros float
 * \param pResultado Puntero donde va el resultado
 * \param num Float del numero A
 * \param num Float del numero B
 * \return int -1 si hay error, 0 si salio bien
 *
 */
float subFloats(float* pResultado,float numA, float numB)
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
/** \brief Multiplica dos numeros float
 * \param pResultado Puntero donde va el resultado
 * \param num Float del numero A
 * \param num Float del numero B
 * \return int -1 si hay error, 0 si salio bien
 *
 */
float mulFloats(float* pResultado,float numA, float numB)
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

/** \brief Divide dos numeros float
 * \param pResultado Puntero donde va el resultado
 * \param num Float del numero A
 * \param num Float del numero B
 * \return int -1 si hay error, 0 si salio bien
 *
 */
float divFloats(float* pResultado,float numA, float numB)
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

/** \brief Calcula el factorial de un Float
 * \param pResultado Puntero donde va el resultado
 * \param num Float del numero a calcular
 * \return int -1 si hay error, 0 si salio bien
 *
 */
float factFloats(float* pResultado,float num)
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
