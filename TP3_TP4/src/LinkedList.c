#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "../inc/LinkedList.h"
#include "LinkedList.h"

static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brif Creak un uevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
	LinkedList* this;
	this = (LinkedList *)malloc(sizeof(LinkedList));
	if(this != NULL)
	{
		this->size=0;
		this->pFirstNode = NULL;
	}
	return this;

}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL){
        returnAux = this->size;
    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* pNode = NULL;
    int i;

    if (this != NULL && ll_len(this) > 0 && nodeIndex >= 0 && nodeIndex < ll_len(this))
    {
    	pNode = this->pFirstNode; // Siempre arranco del firstNode para ir saltando
    	for (i = 0;i<nodeIndex;i++) // Si es menor lo tomo como nuevo punto de partida.
    	{
    		pNode = pNode->pNextNode;
    	}
    }
	return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    //int sizeAux;
    Node* pNewNode = NULL;
    Node* pNodeAux;

    if (this != NULL && nodeIndex <= ll_len(this))
    {
    	pNewNode = (Node*) malloc(sizeof(Node));
		if (pNewNode != NULL)
		{
			pNewNode->pElement = pElement;
			this->size++;

			if(nodeIndex == 0)
			{
				pNewNode->pNextNode = this->pFirstNode;
				this->pFirstNode = pNewNode;

			} else if (nodeIndex == ll_len(this))
			{
				pNewNode->pNextNode = NULL; // apuntar el next de este a NULL
				pNodeAux = getNode(this,nodeIndex-1);
				pNodeAux->pNextNode = pNewNode; // poner el puntero del nuevo nodo en Next del anterior
			}
			else
			{
    			// Agarro el NextNode del anterior a mi y lo grabo en mi nextNode.
    			pNodeAux = getNode(this,nodeIndex-1);
    			pNewNode->pNextNode = pNodeAux->pNextNode;
    			pNodeAux->pNextNode = pNewNode; // Grabo mi puntero en el NextNode del Anterior.
			}
		}
    	returnAux = 0;
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if (this != NULL)
    {
    	addNode(this,ll_len(this),pElement);
    	returnAux = 0;
    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* pNodeAux = NULL;

    if (this != NULL && index >= 0 && index < ll_len(this))
    {
    	pNodeAux = getNode(this,index);
    	if (pNodeAux != NULL)
    	{
    		returnAux = pNodeAux->pElement;
    	}
    }

    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* pNodeAux = NULL;
    if (this != NULL && index >= 0 && index < ll_len(this))
    {
    	pNodeAux = getNode(this,index);
    	pNodeAux->pElement = pElement;
    	returnAux = 0;
    }
    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* pNodeRemove;
    Node* pNodeAux;

    if (this != NULL && index >= 0 && index < ll_len(this))
    {
    	pNodeRemove = getNode(this,index);

    	if (index == ll_len(this)-1 && ll_len(this) > 1) // Si el que quiero borrar es EL ULTIMO Y la ista es mas grande que 1 solo elemento
		{
			// Agarro el nodo anterior al borrado y el nextNode lo pongo en Null
			pNodeAux = getNode(this,index-1);
			pNodeAux->pNextNode = NULL;
		}
		else if (index == 0) // si el quiero borrar es el primero y ademas la lista tiene un solo elemento
		{
			// Agarro el nodo anterior al borrado y el nextNode lo pongo en Null
			this->pFirstNode = pNodeRemove->pNextNode;
		}
		else
		{
			// Agarro el nodo anterior al borrado y le pongo MI nextnode
			pNodeAux = getNode(this,index-1);
			pNodeAux->pNextNode = pNodeRemove->pNextNode;

		}
		//free(pNodeRemove->pElement);
		free(pNodeRemove);
		this->size--;
		returnAux = 0;
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int i;
    int len = ll_len(this);
    if (this != NULL)
    {
    	for (i = 0; i<len;i++)
    	{
    		ll_remove(this,0);
    	}
    	returnAux = 0;

    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if (this != NULL && !ll_clear(this))
    {
    	free(this);
    	returnAux = 0;
    }
    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int i;
    Node* pNodeAux;

    if (this != NULL)
    {
    	for (i=0;i<ll_len(this);i++)
    	{
    		pNodeAux = getNode(this,i);
    		if (pNodeAux->pElement == pElement)
    		{
    			returnAux = i;
    			break;
    		}
    	}
    }
    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    if (this != NULL)
    {
    	if (this->size == 0)
    	{
    		returnAux = 1;
    	}
    	else
    	{
    		returnAux = 0;
    	}

    }
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
    if (this != NULL && index >= 0 && index <= ll_len(this))
    {
    	if(!addNode(this,index,pElement))
    	{
    		returnAux = 0;
    	}
    }
    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;

    if (this != NULL && index >= 0 && index < ll_len(this))
    {
    	returnAux = ll_get(this,index);
    	ll_remove(this, index);

    }

    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int i;
    if (this != NULL)
    {
    	returnAux = 0;
    	for (i=0;i<ll_len(this);i++)
    	{
    		if(ll_get(this,i) == pElement)
    		{
    			returnAux = 1;
    			break;
    		}
    	}

    }
    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int i;
    void* pElementAux = NULL;


    //if (this != NULL && this2 != NULL && ll_len(this2) <= ll_len(this)) //PORQUE NO TESTEA BIEN?
    if (this != NULL && this2 != NULL)
    {
    	if(ll_len(this2) <= ll_len(this))
    	{
    		returnAux = 1;
			for (i=0;i<ll_len(this2);i++)
			{
				pElementAux = ll_get(this2,i);
				if(!ll_contains(this,pElementAux))
				{
					returnAux = 0;
					break;
				}
			}
    	}
    	else
    	{
    		returnAux = 0;
    	}
    }

    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    void* pElement = NULL;

    int i;

    if(this!=NULL && from >= 0 && from <= ll_len(this) && to > from && to <= ll_len(this))
    {
    	cloneArray = ll_newLinkedList();
    	if (cloneArray != NULL)
    	{
			for (i = from; i<to ;i++)
			{
				pElement = ll_get(this, i);
				ll_add(cloneArray, pElement);
			}
    	}
    }

    return cloneArray;
}

/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;

    if(this != NULL)
    {
    	cloneArray = ll_subList(this, 0, ll_len(this));
    }

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
    int flagSwap;
    int i;
    int limite = ll_len(this);

    void* pElementA;
    void* pElementB;

    if(this != NULL && pFunc != NULL && (order == 0 || order == 1))
    {
    	do
    	{
    		flagSwap = 0;
    		for(i=0;i<limite-1;i++)
			{
				pElementA = ll_get(this,i);
				pElementB = ll_get(this, i+1);

				if((pFunc(pElementA,pElementB) == -1 && order == 0) || (pFunc(pElementA,pElementB) == 1 && order == 1))
				{
					flagSwap = 1;
					ll_set(this, i, pElementB);
					ll_set(this, i+1, pElementA);
				}
			}
			limite--;
     	}while(flagSwap);
    	returnAux = 0;
    }
    return returnAux;
}
/** \brief Mapea con una funcion los elementos del LinkedList
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_map(LinkedList* this, int (*pFunc)(void*))
{
    int returnAux =-1;
    int i;
    void* pElement;
    if (this != NULL)
    {
    	returnAux = 0;
    	for (i=0;i<ll_len(this);i++)
    	{
    		pElement = ll_get(this,i);
    		pFunc(pElement);
    	}
    }
    return returnAux;

}
/** \brief Filtra los elementos segun pFunc y devuelve una lista nueva.
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
LinkedList* ll_filter(LinkedList* this, int (*pFunc)(void*))
{
    int i;
    void* pElement;
    LinkedList* listaFiltrada = NULL;
    if (this != NULL)
    {
    	listaFiltrada = ll_newLinkedList();
    	if(listaFiltrada != NULL)
    	{
			for (i=0;i<ll_len(this);i++)
			{
				pElement = ll_get(this,i);
				if(pFunc(pElement))
				{
					ll_add(listaFiltrada, pElement);
				}
			}
    	}
    }
    return listaFiltrada;
}
/** \brief Filtra los elementos segun pFunc y devuelve una lista nueva.
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_reduceAdding(LinkedList* this, int (*pFunc)(void*))
{
    int retorno = -1;
    void* pElement = NULL;
    int adding = 0;
    int value = 0;
	int i;

    if (this != NULL)
    {
    	retorno = 0;
    	for (i = 0; i<ll_len(this);i++)
    	{
    		pElement = ll_get(this,i);
    		value = pFunc(pElement);

    		if (pElement != NULL && pFunc(pElement) != 0)
    		{
    			adding += value;
    		}
    	}
    	retorno = adding;
    }
    return retorno;
}
