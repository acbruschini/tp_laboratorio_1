#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"


/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/
#define MENUPRINCIPAL_LEN 11



int main()
{

	/*
	Employee* pArrayEmployee[100];
	int idAux, horasTrabajadasAux, sueldoAux;
	char nombreAux[NOMBRE_LEN];

	pArrayEmployee[0] = employee_new();
	employee_setId(pArrayEmployee[0], 56);
	employee_setNombre(pArrayEmployee[0], "Ariel");
	employee_setHorasTrabajadas(pArrayEmployee[0], 100);
	employee_setSueldo(pArrayEmployee[0], 500000);

	employee_getId(pArrayEmployee[0], &idAux);
	employee_getHorasTrabajadas(pArrayEmployee[0], &horasTrabajadasAux);
	employee_getNombre(pArrayEmployee[0], nombreAux);
	employee_getSueldo(pArrayEmployee[0], &sueldoAux);


	printf ("Puntero %p: ID %d - Nombre %s - Horas Trabajadas %d - Sueldo %d",pArrayEmployee[0],idAux,nombreAux,horasTrabajadasAux,sueldoAux);
	*/
	setbuf(stdout, NULL);
    char menuPrincipal[MENUPRINCIPAL_LEN][300] = {
    			"ABM DE ALTA, BAJA Y MODIFICACION DE EMPLEADOS",
    			"Cargar los datos de los empleados desde el archivo data.csv (modo texto).",
    			"Cargar los datos de los empleados desde el archivo data.csv (modo binario)",
    			"Alta de empleado",
    			"Modificar datos de empleado",
    			"Baja de empleado",
				"Listar empleados",
				"Ordenar empleados",
				"Guardar los datos de los empleados en el archivo data.csv (modo texto).",
				"Guardar los datos de los empleados en el archivo data.csv (modo binario).",
				"Salir"
    			};

	int opcionElegida = 0;
	int idProximo = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();

    do{
    	opcionElegida = menu(menuPrincipal,MENUPRINCIPAL_LEN);
        switch(opcionElegida)
        {
            case 1:

            	if (ll_len(listaEmpleados) == 0)
            	{
					if(!controller_loadFromText("data.csv",listaEmpleados, &idProximo))
					{
						printf ("\nSE IMPORTO CORRECTAMENTE EL ARCHIVO CON %d EMPLEADOS",ll_len(listaEmpleados));
						//printf ("\nDEBUG: idProximo = %d",idProximo);
					}
            	}else if(utn_isConfirmacion("\nAVISO IMPORTANTE: Ya tiene Empleados cargados en memoria. Desea reemplazarlos por obtenidos en el archivo?\n(S o N): ", "\nERROR\n", "S", "N", 10))
            	{
					ll_clear(listaEmpleados);
					if(!controller_loadFromText("data.csv",listaEmpleados, &idProximo))
					{
						printf ("\nSE IMPORTO CORRECTAMENTE EL ARCHIVO CON %d EMPLEADOS",ll_len(listaEmpleados));
						//printf ("\nDEBUG: idProximo = %d",idProximo);
					}
            	}
               	break;

            case 2:

            	if (ll_len(listaEmpleados) == 0)
            	{
					if(!controller_loadFromBinary("data.bin",listaEmpleados, &idProximo))
					{
						printf ("\nSE IMPORTO CORRECTAMENTE EL ARCHIVO CON %d EMPLEADOS",ll_len(listaEmpleados));
						//printf ("\nDEBUG: idProximo = %d",idProximo);
					}
            	}else if(utn_isConfirmacion("\nAVISO IMPORTANTE: Ya tiene Empleados cargados en memoria. Desea reemplazarlos por obtenidos en el archivo?\n(S o N): ", "\nERROR\n", "S", "N", 10))
            	{
					ll_clear(listaEmpleados);
					if(!controller_loadFromBinary("data.bin",listaEmpleados, &idProximo))
					{
						printf ("\nSE IMPORTO CORRECTAMENTE EL ARCHIVO CON %d EMPLEADOS",ll_len(listaEmpleados));
						//printf ("\nDEBUG: idProximo = %d",idProximo);
					}
            	}
               	break;
            case 3:

            	if (listaEmpleados != NULL && !controller_addEmployee(listaEmpleados, &idProximo))
            	{
            		printf ("\nEL EMPLEADO SE AGREGO EXITOSAMENTE");
            	}
            	else
            	{
            		printf ("\nNO SE AGREGO NINGUN EMPLEADO");
            	}
            	break;

            case 4:

            	if(ll_len(listaEmpleados) == 0)
            	{
            		printf ("\nLA LISTA DE EMPLEADOS ESTA VACIA");
            	}
            	else
            	{
            		controller_ListEmployee(listaEmpleados);
            		if(!controller_editEmployee(listaEmpleados))
            		{
            			printf ("\nEL EMPLEADO SE MODIFICO EXITOSAMENTE");
            		}
            		else
            		{
            			printf ("\nNO SE PUDO MODIFICAR EL EMPLEADO");
            		}
            	}
            	break;

            case 5:

            	if(ll_len(listaEmpleados) == 0)
				{
					printf ("\nLA LISTA DE EMPLEADOS ESTA VACIA");
				}
				else if (!controller_ListEmployee(listaEmpleados) && !controller_removeEmployee(listaEmpleados,idProximo))
				{
					printf ("\nLA BAJA SE REALIZO EXISTOSAMENTE");
				}
            	break;

            case 6:

            	if(ll_len(listaEmpleados) == 0)
            	{
            		printf ("\nLA LISTA DE EMPLEADOS ESTA VACIA");
            	}
            	else if (controller_ListEmployee(listaEmpleados) == -1)
            	{
            		printf ("\nNO SE PUDO IMPRIMIR LA LISTA.");
            	}
            	break;

            case 7:

            	if(ll_len(listaEmpleados) == 0)
				{
					printf ("\nLA LISTA DE EMPLEADOS ESTA VACIA");
				}
				else if (controller_sortEmployee(listaEmpleados) == -1)
				{
					printf ("\nNO SE PUDO IMPRIMIR LA LISTA.");
				}
				else
				{
					printf ("\nSE ORDENO CORRECTAMENTE");
				}
				break;
            case 8:

            	if(ll_len(listaEmpleados) == 0)
				{
					printf ("\nLA LISTA DE EMPLEADOS ESTA VACIA");
				}
				else if (controller_saveAsText("data2.csv", listaEmpleados) == -1)
				{
					printf ("\nNO SE PUDO EXPORTAR LA LISTA EN MODO CSV");
				}
				else
				{
					printf ("\nSE EXPORTO CORRECTAMENTE LA LISTA EN MODO TEXTO EN CVS");
				}
				break;

            case 9:
            	if(ll_len(listaEmpleados) == 0)
				{
					printf ("\nLA LISTA DE EMPLEADOS ESTA VACIA");
				}
				else if (controller_saveAsBinary("data.bin", listaEmpleados) == -1)
				{
					printf ("\nNO SE PUDO EXPORTAR LA LISTA EN MODO BINARIO");
				}
				else
				{
					printf ("\nSE EXPORTO CORRECTAMENTE LA LISTA EN MODO BINARIO");
				}
				break;

            case 10:

            	break;

        }
    }while(opcionElegida != 10);
    return 0;
}

