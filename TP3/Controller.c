#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "LinkedList.h"
#include "Employee.h"
#define MENUSORT_LEN 4

int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);
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
    	fclose(pFile);
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
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee, int* idProximo)
{
    int retorno = -1;
    if (path != NULL && pArrayListEmployee != NULL && idProximo != NULL)
    {
    	FILE* pFile = fopen(path,"rb");
    	*idProximo = parser_EmployeeFromBinary(pFile, pArrayListEmployee);
    	fclose(pFile);
    	retorno = 0;
    }
	return retorno;
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
    int retorno = -1;
    int idAModificar;
    int IndexAModificar;
    Employee* pEmployee = NULL;
    char nombreAux[NOMBRE_LEN];
    int horasTrabajadasAux;
    int sueldoAux;

    if(pArrayListEmployee != NULL)
    {
    	if(!utn_getNumero(&idAModificar, "\n\nINGRESE EL ID DEL CLIENTE A MODIFICAR: ", "\nERROR\n", 0, ll_len(pArrayListEmployee)-1, 3))
    	{
    		IndexAModificar = employee_getIndexById(pArrayListEmployee, idAModificar);
    		pEmployee = ll_get(pArrayListEmployee,IndexAModificar);
    		if(!utn_getNombre(nombreAux, NOMBRE_LEN, "\nINGRESE EL NUEVO NOMBRE DEL EMPLEADO:\n", "\nERROR\n", 3) &&
    		   !utn_getNumero(&horasTrabajadasAux, "\nINGRESE LAS NUEVAS HORAS TRABAJADAS:\n", "\nERROR\n", 0, 99999, 3) &&
			   !utn_getNumero(&sueldoAux, "\nINGRESE EL NUEVO SUELDO:\n", "\nERROR\n", 0, 9999999, 3))
    		{
    			if(!employee_setNombre(pEmployee, nombreAux) &&
    				!employee_setHorasTrabajadas(pEmployee, horasTrabajadasAux) &&
					!employee_setSueldo(pEmployee, sueldoAux))
    			{
    				retorno = 0;
    			}
    		}
    	}
    }
	return retorno;
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
    		printf("\nID: %d - Nombre: %s - Horas Trabajadas: %d - Sueldo: %d",pEmployeeAux->id,pEmployeeAux->nombre,pEmployeeAux->horasTrabajadas,pEmployeeAux->sueldo);

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
    int retorno = -1;
    int menuSortOpcion;
    char menuSort[MENUSORT_LEN][300] = {
    			"Por que criterio quiere organizar?",
    			"Ordenar por Nombre",
				"Ordenar por Horas Trabajadas",
				"Ordenar por Sueldo"
    			};

    if(pArrayListEmployee != NULL)
    {

		menuSortOpcion = menu(menuSort,MENUSORT_LEN);

        switch(menuSortOpcion)
        {
            case 1:
            	ll_sort(pArrayListEmployee, employee_sortByNombre, 0);
            	break;
            case 2:
            	ll_sort(pArrayListEmployee, employee_sortByHorasTrabajadas, 0);
            	break;
            case 3:
            	ll_sort(pArrayListEmployee, employee_sortBySueldo, 0);
            	break;
        }

    	//ll_sort(pArrayListEmployee, employee_sortBySueldo, 0);
    	retorno = 0;
    }

	return retorno;
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
    int retorno = -1;
    int i;
    Employee* pEmployeeAux;
    int idAux;
    int horasTrabajadasAux;
    int sueldoAux;
    char nombreAux[NOMBRE_LEN];

    if (path != NULL && pArrayListEmployee)
    {
    	FILE* pFile = fopen(path,"w");
    	if (pFile != NULL)
    	{
    		for (i=0;i<ll_len(pArrayListEmployee);i++)
    		{
    			pEmployeeAux = ll_get(pArrayListEmployee, i);
    			if(pEmployeeAux != NULL &&
    				!employee_getId(pEmployeeAux, &idAux) &&
					!employee_getHorasTrabajadas(pEmployeeAux, &horasTrabajadasAux) &&
					!employee_getSueldo(pEmployeeAux, &sueldoAux) &&
					!employee_getNombre(pEmployeeAux, nombreAux))
    			{
    				//printf(" DEBUG - %d,%s,%d,%d\n",idAux,nombreAux,horasTrabajadasAux,sueldoAux);
    				fprintf(pFile,"%d,%s,%d,%d\n",idAux,nombreAux,horasTrabajadasAux,sueldoAux);
    			}
    		}
    		fclose(pFile);
    	}
    	retorno = 0;
    }
	return retorno;
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
    int retorno = -1;
    int i;
    Employee* pEmployeeAux;

    if (path != NULL && pArrayListEmployee != NULL)
    {
    	FILE* pFile = fopen(path,"wb");
    	if (pFile != NULL)
    	{
    		for(i=0; i<ll_len(pArrayListEmployee); i++)
    		{
    			pEmployeeAux = ll_get(pArrayListEmployee,i);
				if(pEmployeeAux != NULL){
					fwrite(pEmployeeAux,sizeof(Employee),1,pFile);
				}
    		}
    		fclose(pFile);
    		retorno = i;
    	}
    }

	return retorno;
}

