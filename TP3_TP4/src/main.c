#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#define MENUPRINCIPAL_LEN 12



int main()
{

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
				"Informes",
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
				else if (controller_reportsEmployee(listaEmpleados) == -1)
				{
					printf ("\nNO SE PUDO IMPRIMIR LA LISTA.");
				}

				break;

            case 9:
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

            case 10:

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

        }
    }while(opcionElegida != 11);
    return 0;
}

