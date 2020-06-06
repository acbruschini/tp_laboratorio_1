#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "LinkedList.h"
#include "Employee.h"

int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);
/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee, int* idProximo)
{
    int retorno = -1;
    if (path != NULL && pArrayListEmployee != NULL && idProximo != NULL)
    {
    	FILE* pFile = fopen(path,"r");
    	*idProximo = parser_EmployeeFromText(pFile, pArrayListEmployee);
    	retorno = 0;
    }
	return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee, int* idProximo)
{
	int retorno = -1;
	Employee buffer;
	Employee* pEmployeeAux;
	char idAux[128];
	char horasTrabajadasAux[128];
	char sueldoAux[128];

	if(pArrayListEmployee != NULL && idProximo != NULL)
	{

		if(	!utn_getNombre(buffer.nombre, NOMBRE_LEN, "\nNombre del Empleado:\n", "\nERROR\n", 2) &&
			!utn_getNumero(&buffer.horasTrabajadas,"\nHoras Trabajadas:\n","\nERROR\n",0,10000,2) &&
			!utn_getNumero(&buffer.sueldo,"\nSueldo:\n","\nERROR\n",0,9000000,2))
		{
			snprintf(idAux,sizeof(idAux),"%d",*idProximo);
			snprintf(horasTrabajadasAux,sizeof(horasTrabajadasAux),"%d",buffer.horasTrabajadas);
			snprintf(sueldoAux,sizeof(sueldoAux),"%d",buffer.sueldo);
			pEmployeeAux = employee_newParametros(idAux, buffer.nombre, horasTrabajadasAux, sueldoAux);

			if(pEmployeeAux != NULL )
			{
				ll_add(pArrayListEmployee, pEmployeeAux);
				retorno = 0;
				*idProximo = *idProximo+1;
			}
		}
	}
	return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee, int idProximo)
{
    int retorno = -1;
    int idABorrar;
    Employee* pEmployeeAux;

    if (pArrayListEmployee != NULL)
    {
    	if(!utn_getNumero(&idABorrar, "\n\nINGRESE EL ID DEL EMPLEADO A BORRAR: ", "\nERROR\n", 0, idProximo, 3))
    	{
    		idABorrar =	employee_getIndexById(pArrayListEmployee, idABorrar);
    		pEmployeeAux = ll_get(pArrayListEmployee, idABorrar);
    		if(idABorrar >= 0 && !employee_delete(pEmployeeAux) && !ll_remove(pArrayListEmployee, idABorrar))
    		{
    			retorno = 0;
    		}
    	}
    }
	return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int i;
    //int idAux, horasTrabajadasAux, sueldoAux;
    //char nombreAux[NOMBRE_LEN];
    Employee* pEmployeeAux;

    if (pArrayListEmployee !=  NULL)
    {
    	retorno = 0;
    	for(i=0;i<ll_len(pArrayListEmployee);i++)
    	{
    		pEmployeeAux = ll_get(pArrayListEmployee, i);
    		printf("\nIndice: %d - ID: %d - Nombre: %s - Horas Trabajadas: %d - Sueldo: %d",i,pEmployeeAux->id,pEmployeeAux->nombre,pEmployeeAux->horasTrabajadas,pEmployeeAux->sueldo);
    	}
    }
	return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

