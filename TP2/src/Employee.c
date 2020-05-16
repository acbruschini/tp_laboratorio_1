#include "Employee.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

/**
 * \brief Imprime los datos de UN Empleado
 * \param pElemento Puntero al empleado que se busca imprimir
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int printEmployee(Employee* pElemento)
{
	int retorno=-1;
	if(pElemento != NULL && pElemento->isEmpty == 0)
	{
		retorno=0;
		printf("\nID: %d - NAME: %s - LASTNAME: %s - SECTOR: %d - SALARY: %.2f",pElemento->id,pElemento->name,pElemento->lastName,pElemento->sector,pElemento->salary);
	}
	return retorno;
}

/**
 * \brief Imprime el array de Empleados
 * \param array Array de empleados a ser Impreso
 * \param limite Limite del array de Empleados
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int printEmployees(Employee* array,int limite)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0)
	{
		respuesta = 0;
		for(i=0;i<limite;i++)
		{
			printEmployee(&array[i]);
		}
	}
	return respuesta;
}

/**
 * \brief Inicializa el array
 * \param array Array de Empleados
 * \param limite Limite del array de Empleados
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int initEmployees(Employee* array,int limite)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0)
	{
		respuesta = 0;
		for(i=0;i<limite;i++)
		{
			array[i].isEmpty = 1;
		}
	}
	return respuesta;
}

/**
 * \brief Da de alta un Empleado en una posicion del array
 * \param array Array de Empleados a ser actualizado
 * \param limite Limite del array de Empleados
 * \param indice Posicion a ser actualizada
 * \param id Identificador a ser asignado al Empleado
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int addEmployees(Employee* array,int limite, int indice, int* id)
{
	int respuesta = -1;
	Employee bufferCliente;

	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && id != NULL)
	{
		if(	!utn_getDescripcion(bufferCliente.name, NAME_LEN, "\nEmployee Name:\n", "\nERROR\n", 2) &&
			!utn_getDescripcion(bufferCliente.lastName, LASTNAME_LEN, "\nEmployee Last Name:\n", "\nERROR\n", 2) &&
			!utn_getNumero(&bufferCliente.sector,"\nEmployee Sector:\n","\nERROR\n",1,10,2) &&
			!utn_getNumeroFlotante(&bufferCliente.salary,"\nEmployee Salary:\n","\nERROR\n",0,150000,2))
		{
			respuesta = 0;
			bufferCliente.id = *id;
			bufferCliente.isEmpty = 0;
			array[indice] = bufferCliente;
			(*id)++;
		}
	}
	return respuesta;
}

/**
 * \brief Actualiza los datos de un cliente en una posicion del array
 * \param array Array de clientes a ser actualizado
 * \param limite Limite del array de clientes
 * \param indice Posicion a ser actualizada
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int modifyEmployee(Employee* array,int limite, int indice)
{
	int respuesta = -1;
	Employee bufferCliente;

	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && array[indice].isEmpty == 0)
	{
		if(	!utn_getDescripcion(bufferCliente.name, NAME_LEN, "\nEmployee Name:\n", "\nERROR\n", 2) &&
			!utn_getDescripcion(bufferCliente.lastName, LASTNAME_LEN, "\nEmployee Last Name:\n", "\nERROR\n", 2) &&
			!utn_getNumero(&bufferCliente.sector,"\nEmployee Sector:\n","\nERROR\n",1,10,2) &&
			!utn_getNumeroFlotante(&bufferCliente.salary,"\nEmployee Salary:\n","\nERROR\n",0,150000,2))
		{
			respuesta = 0;
			bufferCliente.id = array[indice].id;
			bufferCliente.isEmpty = 0;
			array[indice] = bufferCliente;
		}
	}
	return respuesta;
}

/**
 * \brief Actualiza una posicion del array
 * \param array Array de clientes a ser actualizado
 * \param limite Limite del array de clientes
 * \param indice Posicion a ser actualizada
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int removeEmployee(Employee* array,int limite, int indice)
{
	int respuesta = -1;
	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && array[indice].isEmpty == 0)
	{
		array[indice].isEmpty = 1;
		respuesta = 0;
	}
	return respuesta;
}


/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param array cliente Array de cliente
* \param limite int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int findEmployeedById(Employee array[], int limite, int valorBuscado)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0 && valorBuscado >= 0)
	{
		for(i=0;i<limite;i++)
		{
			if(array[i].id == valorBuscado)
			{
				respuesta = i;
				break;
			}
		}
	}
	return respuesta;
}

/**
 * \brief Buscar primer posicion vacia
 * \param array Array de clientes
 * \param limite Limite del array de clientes
 * \return Retorna el incice de la posicion vacia y -1 (ERROR)
 *
 */
int getEmptyIndex(Employee* array,int limite)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0)
	{
		for(i=0;i<limite;i++)
		{
			if(array[i].isEmpty == 1)
			{
				respuesta = i;
				break;
			}
		}
	}
	return respuesta;
}

/**
 * \brief Ordenar el array de clientes por nombre
 * \param array Array de clientes
 * \param limite Limite del array de clientes
 * \return Retorna el incice de la posicion vacia y -1 (ERROR)
 *
 */
int sortByName(Employee* array,int limite)
{
	int respuesta = -1;
	int flagSwap;
	int i;
	Employee buffer;
	if(array != NULL && limite > 0)
	{
		do
		{
			flagSwap = 0;
			for(i=0;i<limite-1;i++)
			{
				if(array[i].isEmpty || array[i+1].isEmpty)
				{
					continue;
				}
				if(strncmp(array[i].name,array[i+1].name,NAME_LEN) > 0)
				{
					flagSwap = 1;
					buffer = array[i];
					array[i] = array[i+1];
					array[i+1]=buffer;
				}
			}
			limite--;
		}while(flagSwap);
	}
	return respuesta;
}


/**
 * \brief Ordenar el array de clientes por nombre y altura
 * \param array Array de clientes
 * \param limite Limite del array de clientes
 * \return Retorna el incice de la posicion vacia y -1 (ERROR)
 *
 */
int sortByLastnameAndSector(Employee* array,int limite)
{
	int respuesta = -1;
	int flagSwap;
	int i;
	Employee buffer;
	int auxiliarCmp;
	if(array != NULL && limite > 0)
	{
		do
		{
			flagSwap = 0;
			for(i=0;i<limite-1;i++)
			{

				if(array[i].isEmpty || array[i+1].isEmpty)
				{
					continue;
				}
				auxiliarCmp = strncmp(array[i].lastName,array[i+1].lastName,NAME_LEN);
				if(	 auxiliarCmp > 0 ||
					(auxiliarCmp == 0 && array[i].sector > array[i+1].sector) )
				{
					flagSwap = 1;
					buffer = array[i];
					array[i] = array[i+1];
					array[i+1]=buffer;
				}
			}
			limite--;
		}while(flagSwap);
	}
	return respuesta;
}
/**
 * \brief Da de alta FORZADA un Empleado en una posicion del array
 * \param array Array de Empleados a ser actualizado
 * \param limite Limite del array de Empleados
 * \param indice Posicion a ser actualizada
 * \param id Identificador a ser asignado al Empleado
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int forcedAddEmployees(Employee* array,int limite, int indice, int* id, char* name, char* lastname, int sector, float salary)
{
	int respuesta = -1;
	Employee bufferCliente;

	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && id != NULL)
	{

			strncpy(bufferCliente.name,name,NAME_LEN);
			strncpy(bufferCliente.lastName,lastname,LASTNAME_LEN);
			bufferCliente.sector = sector;
			bufferCliente.salary = salary;
			respuesta = 0;
			bufferCliente.id = *id;
			bufferCliente.isEmpty = 0;
			array[indice] = bufferCliente;
			(*id)++;

	}
	return respuesta;
}
/**
 * \brief Obtiene el total de los salarios
 * \param pResultado Variable FLOAT donde deja el resultado del total
 * \param array Array de clientes
 * \param limite Limite del array de Empleados
 * \return Retorna 0 Exito y -1 (ERROR)
 *
 */
int getTotalSalary(float* pResultado, Employee* array,int limite)
{
	int respuesta = -1;
	int i;
	float acumulador = 0;

	if(array != NULL && limite > 0)
	{
		respuesta = 0;
		for (i=0;i<limite;i++)
		{
			if(array[i].isEmpty == 0)
			{
				acumulador += array[i].salary;
			}
		}
		*pResultado = acumulador;
	}

	return respuesta;
}
/**
 * \brief Obtiene el PROMEDIO de los salarios
 * \param pResultado Variable FLOAT donde deja el resultado del promedio
 * \param array Array de Empleados
 * \param limite Limite del array de Empleados
 * \return Retorna 0 Exito y -1 (ERROR)
 *
 */
int getAverageSalary(float* pResultado, Employee* array,int limite)
{
	int respuesta = -1;
	int i;
	float acumulador = 0;
	int contador = 0;

	if(array != NULL && limite > 0)
	{
		respuesta = 0;
		for (i=0;i<limite;i++)
		{
			if(array[i].isEmpty == 0)
			{
				acumulador += array[i].salary;
				contador++;
			}
		}
		if (contador > 0)
		{
		*pResultado = acumulador / contador;
		}
	}

	return respuesta;
}
/**
 * \brief Obtiene cantidad de empleados que superan el promedio
 * \param array Array de Empleados
 * \param limite Limite del array de Empleados
 * \param promedio El dato a testear
 * \return Retorna la cantidad y -1 (ERROR)
 *
 */
int getEmployeesHigherAverage(Employee* array,int limite, float promedio)
{
	int respuesta = -1;
	int i;
	int contador = 0;

	if(array != NULL && limite > 0)
	{
		respuesta = 0;
		for (i=0;i<limite;i++)
		{
			if(array[i].isEmpty == 0 && array[i].salary > promedio)
			{
				contador++;
			}
		}

		respuesta = contador;
	}

	return respuesta;
}
/**
 * \brief Obtiene si el array esta vacio o no
 * \param array Array de Empleados
 * \param limite Limite del array de Empleados
 * \return Retorna 1 si esta vacio y 0 si no esta vacio
 *
 */
int isArrayEmpty(Employee* array,int limite)
{
	int respuesta = 1;
	int i;

	if(array != NULL && limite > 0)
	{

		for (i=0;i<limite;i++)
		{
			if(array[i].isEmpty == 0)
			{
				respuesta = 0;
			}
		}

	}

	return respuesta;
}
