/*
 * Employee.c
 *
 *  Created on: May 4, 2020
 *      Author: Ariel Bruschini
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "utn.h"
#include "LinkedList.h"
#include "Employee.h"

static int employee_isNombre(char* cadena,int longitud);

/** \brief Reserava un espacio en memoria de tama�o Employee
 * \return El puntero donde lo reservo (Exito) o NULL (Error)
 *
 */
Employee* employee_new()
{
	Employee* pEmployeeAux = NULL;
	pEmployeeAux = (Employee*) malloc(sizeof(Employee));
	return pEmployeeAux;
}
/** \brief Agrega un Employee con los parametros.
 * \param IDSTR string del id NOMBRESTR string del nombre HORASTRABAJADASSTR string de las horastrabajadas SUELDOSTR string del sueldo
 * \return El puntero donde lo creo (Exito) o NULL (Error)
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
	Employee* pEmployeeAux = NULL;
	pEmployeeAux = employee_new();

	if (idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL && pEmployeeAux != NULL )
	{
		if(!employee_setNombre(pEmployeeAux, nombreStr) &&
		!employee_setId(pEmployeeAux, atoi(idStr)) &&
		!employee_setHorasTrabajadas(pEmployeeAux, atoi(horasTrabajadasStr)) &&
		!employee_setSueldo(pEmployeeAux, atoi(sueldoStr)))
		{

		}
		else
		{
			free (pEmployeeAux);
			pEmployeeAux = NULL;
		}
	}

	return pEmployeeAux;
}
/** \brief Libera un espacio en memoria de tama�o Employee
 * \return 0 (exito) o -1 (Error)
 *
 */
int employee_delete(Employee* this)
{
	int retorno = -1;
	if (this != NULL)
	{
		free(this);
		retorno = 0;
	}
	return retorno;
}
/** \brief SET el ID (tipo int) de un Employee
 * \param this el puntero donde se encuentra el tipo de dato empleado y ID el int a setear
 * \return 0 (Exito) o -1 (Error)
 *
 */
int employee_setId(Employee* this,int id)
{
	int retorno = -1;
	if (this != NULL && id >= 0)
	{
		this->id = id;
		retorno = 0;
	}
		return retorno;

}
/** \brief GET el ID (tipo int) de un Employee
 * \param this el puntero donde se encuentra el tipo de dato empleado y ID puntero de la variable donde lo deja.
 * \return 0 (Exito) o -1 (Error)
 *
 */
int employee_getId(Employee* this,int* id)
{
	int retorno = -1;
	if (this != NULL && id != NULL)
	{
		*id = this->id;
		retorno = 0;
	}
	return retorno;
}
/** \brief SET el Nombre (tipo char) de un Employee
 * \param this el puntero donde se encuentra el tipo de dato empleado, nombre char del nombre
 * \return 0 (Exito) o -1 (Error)
 *
 */
int employee_setNombre(Employee* this,char* nombre)
{
	int retorno = -1;
	if (this != NULL && nombre != NULL && employee_isNombre(nombre, sizeof(nombre)) )
	{
		strncpy(this->nombre,nombre,NOMBRE_LEN);
		retorno = 0;
	}
	return retorno;
}
/** \brief GET el Nombre (tipo char) de un Employee
 * \param this el puntero donde se encuentra el tipo de dato empleado, nombre puntero a la variable donde lo va a dejar
 * \return 0 (Exito) o -1 (Error)
 *
 */
int employee_getNombre(Employee* this,char* nombre)
{
	int retorno = -1;
	if (this != NULL && nombre != NULL)
	{
		strcpy(nombre,this->nombre);
		retorno = 0;
	}
	return retorno;
}
/** \brief SET el HORAS TRABAJADAS (tipo int) de un Employee
 * \param this el puntero donde se encuentra el tipo de dato empleado y HORASTRABAJADAS el int a setear
 * \return 0 (Exito) o -1 (Error)
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int retorno = -1;
	if (this != NULL && horasTrabajadas >= 0)
	{
		this->horasTrabajadas = horasTrabajadas;
		retorno = 0;
	}
	return retorno;
}
/** \brief GET el HORASTRABAJADAS (tipo int) de un Employee
 * \param this el puntero donde se encuentra el tipo de dato empleado y HORASTRABAJADAS puntero de la variable donde lo deja.
 * \return 0 (Exito) o -1 (Error)
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int retorno = -1;
	if (this != NULL && horasTrabajadas != NULL)
	{
		*horasTrabajadas = this->horasTrabajadas;
		retorno = 0;
	}
	return retorno;
}
/** \brief SET el SUELDO (tipo int) de un Employee
 * \param this el puntero donde se encuentra el tipo de dato empleado y SUELDO el int a setear
 * \return 0 (Exito) o -1 (Error)
 *
 */
int employee_setSueldo(Employee* this,int sueldo)
{
	int retorno = -1;
	if (this != NULL && sueldo >= 0)
	{
		this->sueldo = sueldo;
		retorno = 0;
	}
	return retorno;
}
/** \brief GET el SUELDO (tipo int) de un Employee
 * \param this el puntero donde se encuentra el tipo de dato empleado y SUELDO puntero de la variable donde lo deja.
 * \return 0 (Exito) o -1 (Error)
 *
 */
int employee_getSueldo(Employee* this,int* sueldo)
{
	int retorno = -1;
	if (this != NULL && sueldo != NULL)
	{
		*sueldo = this->sueldo;
		retorno = 0;
	}
	return retorno;
}
/** \brief Trae el index de una lista en donde encuentra el ID del empleado
 * \param this el puntero donde se encuentra el tipo de dato empleado y ID a buscar.
 * \return Retorna el id (Exito), -2 (No econtro) -1 (Error)
 *
 */
int employee_getIndexById(LinkedList* listaEmpleados,int idBuscar)
{
	int retorno = -1;
	Employee* pEmployeeAux;
	int i;
	if (listaEmpleados != NULL && idBuscar >= 0)
	{
		retorno = -2;
		for (i=0;i<ll_len(listaEmpleados);i++)
		{
			pEmployeeAux = ll_get(listaEmpleados,i);
			if (pEmployeeAux->id == idBuscar)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

/** \brief Ordena por sueldo
 * \param pElement y pElement2
 * \return Retorna el 1 (primero mayor que el segundo), -1 (segundo mayor que el primero), 0 (iguales)
 *
 */
int employee_sortBySueldo(void* pElement1, void* pElement2)
{
	int retorno = -2;
	Employee * pE1 = pElement1;
	Employee * pE2 = pElement2;

	if (pElement1 != NULL && pElement2 != NULL)
	{
		retorno = 0;
		if (pE1->sueldo > pE2->sueldo)
		{
			retorno = 1;
		}
		else if (pE1->sueldo < pE2->sueldo)
		{
			retorno = -1;
		}
	}
	return retorno;
}

/** \brief Ordena por sueldo
 * \param pElement y pElement2
 * \return Retorna el 1 (primero mayor que el segundo), -1 (segundo mayor que el primero), 0 (iguales)
 *
 */
int employee_sortByHorasTrabajadas(void* pElement1, void* pElement2)
{
	int retorno = -2;
	Employee * pE1 = pElement1;
	Employee * pE2 = pElement2;

	if (pElement1 != NULL && pElement2 != NULL)
	{
		retorno = 0;
		if (pE1->horasTrabajadas > pE2->horasTrabajadas)
		{
			retorno = 1;
		}
		else if (pE1->horasTrabajadas < pE2->horasTrabajadas)
		{
			retorno = -1;
		}
	}
	return retorno;
}

/** \brief Ordena por sueldo
 * \param pElement y pElement2
 * \return Retorna el 1 (primero mayor que el segundo), -1 (segundo mayor que el primero), 0 (iguales)
 *
 */
int employee_sortByNombre(void* pElement1, void* pElement2)
{
	int retorno = -2;
	Employee * pE1 = pElement1;
	Employee * pE2 = pElement2;

	if (pElement1 != NULL && pElement2 != NULL)
	{
		retorno = 0;
		if (strcmp(pE1->nombre,pE2->nombre) > 0)
		{
			retorno = 1;
		}
		else if (strcmp(pE1->nombre,pE2->nombre) < 0)
		{
			retorno = -1;
		}
	}
	return retorno;
}
/** \brief IMPRIMIR UN ELEMENTO EMPLOYEE
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int employee_print(void* pElement)
{
    int returnAux =-1;
    Employee* pEmployee = pElement;
    if (pElement != NULL)
    {
    	printf("\nID: %d - Nombre: %s - Horas Trabajadas: %d - Sueldo: %d",pEmployee->id,pEmployee->nombre,pEmployee->horasTrabajadas,pEmployee->sueldo);
    	returnAux = 0;
    }
    return returnAux;
}

/** \brief Criterio Sueldo Mayor a 3000
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int employee_isSueldoMayor30000(void* pElement)
{
    int returnAux =-1;
    Employee* pEmployee = pElement;
    if (pElement != NULL)
    {
    	returnAux = 0;
    	if (pEmployee->sueldo > 30000)
    	{
    		returnAux = 1;
    	}
    }
    return returnAux;
}

/** \brief Criterio Sueldo Mayor a 3000
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int employee_isHorasTrabajadasMayorA8(void* pElement)
{
    int returnAux =-1;
    Employee* pEmployee = pElement;
    if (pElement != NULL)
    {
    	returnAux = 0;
    	if (pEmployee->horasTrabajadas >= 8)
    	{
    		returnAux = 1;
    	}
    }
    return returnAux;
}

/** \brief Criterio Sueldo Mayor a 3000
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int employee_getSueldoEnHorasMayorA120(void* pElement)
{
    int returnAux =-1;
    Employee* pEmployee = pElement;
    if (pElement != NULL)
    {
    	returnAux = 0;
    	if (pEmployee->horasTrabajadas >= 120)
    	{
    		returnAux = pEmployee->sueldo;
    	}
    }
    return returnAux;
}
/** \brief Criterio Sueldo Mayor a 3000
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int employee_isSueldoMayorA60000(void* pElement)
{
    int returnAux =-1;
    Employee* pEmployee = pElement;
    if (pElement != NULL)
    {
    	returnAux = 0;
    	if (pEmployee->sueldo > 60000)
    	{
    		returnAux = 1;
    	}
    }
    return returnAux;
}
/// FUNC DE VERIFICACIONES

/**
 * \brief Verifica si la cadena ingresada es un nombre valido
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es valida y 0 (falso) si no lo es
 *
 */
static int employee_isNombre(char* cadena,int longitud)
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
