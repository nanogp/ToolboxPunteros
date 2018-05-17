#include "EstructuraDepende.h"
#include "General.h"
#include "Menu.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void eDepende_initHardcode(eDepende listado[])
{                            /*nombre, numero, ID, FK, estado*/
	listado[0] = (eDepende){{"De Jose Luis"}, 12345, 101, 11, OCUPADO};
	listado[1] = (eDepende){{"De Bobby Fisher uno"}, 12345, 102, 12, OCUPADO};
	listado[2] = (eDepende){{"De Bobby Fisher dos"}, 12345, 103, 12, OCUPADO};
	listado[3] = (eDepende){{"De Bobby Fisher tres"}, 12345, 104, 12, OCUPADO};
	listado[4] = (eDepende){{"Depende de Donia Rosa uno"}, 12345, 105, 13, OCUPADO};
	listado[5] = (eDepende){{"Depende de Donia Rosa dos"}, 12345, 106, 13, OCUPADO};
	listado[6] = (eDepende){{"Este es Mengano"}, 12345, 107, 14, OCUPADO};
	eDepende_ordenar(listado, DEPENDE_CANT_MAX, DEPENDE_ORDEN);
}

void eDepende_init(eDepende listado[], int limite)
{
	int i;
	for(i=0 ; i<limite ; i++)
	{
		listado[i].estado= LIBRE;
		listado[i].idDepende= 0;
	}
}

int eDepende_buscarLugarLibre(eDepende listado[], int limite)
{
	int retorno = -1;
	int i;

	for(i=0 ; i<limite ; i++)
	{
		if(listado[i].estado == LIBRE)
		{
			retorno = i;
			break;
		}
	}
	return retorno;
}

int eDepende_siguienteId(eDepende listado[], int limite)
{
	int retorno = 0;
	int i;

	for(i=0; i<limite; i++)
	{
		if(listado[i].estado == OCUPADO)
		{
			if(listado[i].idDepende > retorno)
			{
				 retorno = listado[i].idDepende;
			}
		}
	}
	return retorno+1;
}

int eDepende_buscarPorId(eDepende listado[], int limite, int id)
{
	int retorno = -1;
	int i;

	for(i=0 ; i<limite ; i++)
	{
		if(listado[i].estado == OCUPADO && listado[i].idDepende == id)
		{
			retorno = i;
			break;
		}
	}
	return retorno;
}

int eDepende_pedirIdYBuscar(eDepende listado[], int limite)
{
	int retorno;
	int id;

	do
	{
		eDepende_mostrarListado(listado, limite);
		id = pedirIntValido(DEPENDE_MSJ_INGRESE_ID, DEPENDE_MSJ_REINGRESE_ID, DEPENDE_ID_MIN, DEPENDE_ID_MAX);
		retorno = eDepende_buscarPorId(listado, limite, id);
		if(retorno < 0)
		{
			imprimirEnPantalla(DEPENDE_MSJ_ID_NO_EXISTE);
		}
	}
	while(retorno < 0);

	return retorno;
}

int eDepende_estaVacio(eDepende listado[], int limite)
{
	int retorno = 1;
	int i;

	for(i=0 ; i<limite ; i++)
	{
		if(listado[i].estado == OCUPADO)
		{
			retorno = 0;
			break;//con el primer ocupado ya se que no esta vacio
		}
	}
	return retorno;
}

void eDepende_mostrarUno(eDepende registro)
{
	 printf(DEPENDE_MASCARA_MOSTRAR_UNO, registro.idDepende, registro.idGenerica, registro.nombre, registro.numero);

}

void eDepende_mostrarListado(eDepende listado[], int limite)
{
	int i;
	int contadorMostrados = 0;

	if(eDepende_estaVacio(listado, limite) == 1)
	{
		imprimirEnPantalla(DEPENDE_MSJ_LISTA_VACIA);
	}
	else
	{
		imprimirEnPantalla(DEPENDE_CABECERA_LISTADO);
		for(i=0; i<limite; i++)
		{
			if(listado[i].estado==OCUPADO)
			{
				eDepende_mostrarUno(listado[i]);
				contadorMostrados++;

				if(contadorMostrados%20 == 0)
				{
					//cada 20 registros hago una pausa
					ejecutarEnConsola(HACER_PAUSA);
					imprimirEnPantalla(DEPENDE_CABECERA_LISTADO);
				}
			}

		}
	}
}

void eDepende_listar(eDepende listado[], int limite)
{
	ejecutarEnConsola(LIMPIAR_PANTALLA);
	imprimirTitulo(DEPENDE_TITULO_LISTA);

	eDepende_mostrarListado(listado, limite);

	ejecutarEnConsola(HACER_PAUSA);
}

void eDepende_mostrarListadoPorIdGenerica(eDepende listado[], int limite, int idGenerica)
{
	int i;

	for(i=0 ; i<limite ; i++)
	{
		if(listado[i].estado == OCUPADO && listado[i].idGenerica == idGenerica)
		{
			eDepende_mostrarUno(listado[i]);
		}
	}
}


void eDepende_pedirIdGenericaYListar(eDepende listadoDepende[], int limiteDepende, eGenerica listadoGenerica[], int limiteGenerica)
{
	int idGenerica;
	int posicionGenerica;

	do
	{
		ejecutarEnConsola(LIMPIAR_PANTALLA);
		imprimirTitulo(DEPENDE_TITULO_LISTA_POR_ID_GENERICA); //titulo durante ingreso de ID

		eGenerica_mostrarListado(listadoGenerica, limiteGenerica);
		idGenerica = eGenerica_buscarPorId(listadoGenerica, limiteGenerica, idGenerica);
		posicionGenerica = eGenerica_buscarPorId(listadoGenerica, limiteGenerica, idGenerica);
		if(posicionGenerica < 0)
		{
			imprimirEnPantalla(GENERICA_MSJ_ID_NO_EXISTE);
		}
	}
	while(posicionGenerica < 0);

	ejecutarEnConsola(LIMPIAR_PANTALLA);
	imprimirTitulo(DEPENDE_TITULO_LISTA_POR_ID_GENERICA);//titulo para listar

	imprimirEnPantalla(GENERICA_CABECERA_LISTADO);
	eGenerica_mostrarUno(listadoGenerica[posicionGenerica]);
	imprimirEnPantalla(DEPENDE_CABECERA_LISTADO);
	eDepende_mostrarListadoPorIdGenerica(listadoDepende, limiteDepende, idGenerica);

	ejecutarEnConsola(HACER_PAUSA);
}

void eDepende_pedirNombre(char retorno[])
{
	pedirStringValido(retorno, DEPENDE_MSJ_INGRESE_NOMBRE, DEPENDE_MSJ_REINGRESE_NOMBRE, DEPENDE_LARGO_NOMBRE);
}

int eDepende_pedirNumero()
{
	return pedirIntValido(DEPENDE_MSJ_INGRESE_NUMERO, DEPENDE_MSJ_REINGRESE_NUMERO, DEPENDE_NUMERO_MIN, DEPENDE_NUMERO_MAX);
}

eDepende eDepende_pedirIngreso(eDepende listado[], int limite)
{
	eDepende retorno;

	retorno.idDepende = eDepende_siguienteId(listado, limite);

	eDepende_pedirNombre((char *)&(retorno.nombre));

	retorno.numero = eDepende_pedirNumero();

	retorno.estado = OCUPADO;

	return retorno;
}

void eDepende_alta(eDepende listadoDepende[], int limiteDepende, eGenerica listadoGenerica[], int limiteGenerica)
{
	eDepende registro;
	char confirmacion;
	int posicion;

	posicion = eDepende_buscarLugarLibre(listadoDepende, limiteDepende);
	if(posicion < 0)
	{
		imprimirEnPantalla(DEPENDE_MSJ_NO_MAS_LUGAR);
	}
	else
	{
		ejecutarEnConsola(LIMPIAR_PANTALLA);
		imprimirTitulo(DEPENDE_TITULO_ALTA);
		registro = eDepende_pedirIngreso(listadoDepende, limiteDepende);
		eDepende_mostrarUno(registro);

		confirmacion = pedirConfirmacion(MSJ_CONFIRMA_CORRECTOS);

		if(confirmacion == 'S')
		{
			listadoDepende[posicion] = registro;
			eDepende_ordenar(listadoDepende, limiteDepende, DEPENDE_ORDEN);
			imprimirEnPantalla(DEPENDE_MSJ_ALTA_OK);
		}
		else
		{
			imprimirEnPantalla(MSJ_CANCELO_GESTION);
		}
	}
	ejecutarEnConsola(HACER_PAUSA);
}

void eDepende_baja(eDepende listadoDepende[], int limiteDepende, eGenerica listadoGenerica[], int limiteGenerica)
{
	char confirmacion;
	int posicion;

	ejecutarEnConsola(LIMPIAR_PANTALLA);
	imprimirTitulo(DEPENDE_TITULO_BAJA);

	if(eDepende_estaVacio(listadoDepende, limiteDepende) == 1)
	{
		imprimirEnPantalla(DEPENDE_MSJ_LISTA_VACIA);
	}
	else
	{
		posicion = eDepende_pedirIdYBuscar(listadoDepende, limiteDepende);

		ejecutarEnConsola(LIMPIAR_PANTALLA);
		imprimirTitulo(DEPENDE_TITULO_BAJA);

		eDepende_mostrarUno(listadoDepende[posicion]);

		confirmacion = pedirConfirmacion(DEPENDE_MSJ_CONFIRMAR_BAJA);

		if(confirmacion == 'S')
		{
			listadoDepende[posicion].estado = LIBRE;
			imprimirEnPantalla(DEPENDE_MSJ_BAJA_OK);
		}
		else
		{
			imprimirEnPantalla(MSJ_CANCELO_GESTION);
		}
	}

	ejecutarEnConsola(HACER_PAUSA);
}

int eDepende_modificarUno(eDepende registro[])
{
	eMenu menuModificar = {/*cantidad de opciones*/DEPENDE_MENU_MODIFICAR_UNO_CANT,
							/*codigos*/{1,2,3,4,0},
							/*descripciones*/{DEPENDE_MENU_MODIFICAR_UNO_DETALLE1,DEPENDE_MENU_MODIFICAR_UNO_DETALLE2,DEPENDE_MENU_MODIFICAR_UNO_DETALLE3,DEPENDE_MENU_MODIFICAR_UNO_DETALLE4,DEPENDE_MENU_MODIFICAR_UNO_DETALLE5},
							/*titulo del menu*/{DEPENDE_MENU_MODIFICAR_UNO_TITULO}};
	int opcion;
	int huboCambios = 1;

	ejecutarEnConsola(LIMPIAR_PANTALLA);
	imprimirTitulo("MODIFICANDO REGISTRO");
	imprimirEnPantalla("\nDatos a modificar:");
	eDepende_mostrarUno(*registro);

	opcion = pedirOpcion(menuModificar);
	switch(opcion)
	{
		case 1:
			eDepende_pedirNombre((char *)&registro->nombre);
			break;
		case 2:
			registro->numero = eDepende_pedirNumero();
			break;
		case 3:
			//registro->idDepende;
			break;
		case 4:
			//registro->campoN;
			break;
		case 0:
		    huboCambios = 0;
			break;
	}
	return huboCambios;
}

void eDepende_modificacion(eDepende listado[], int limite)
{
	eDepende registro;
	char confirmacion;
	int posicion;
	int huboCambios;

	ejecutarEnConsola(LIMPIAR_PANTALLA);
	imprimirTitulo(DEPENDE_TITULO_MODIFICACION);

	if(eDepende_estaVacio(listado, limite) == 1)
	{
		imprimirEnPantalla(DEPENDE_MSJ_LISTA_VACIA);
	}
	else
	{
		posicion = eDepende_pedirIdYBuscar(listado, limite);
		//traigo el registro del id elegido para no pisar directo sobre el listado
		registro = listado[posicion];

		huboCambios = eDepende_modificarUno(&registro);
		if(huboCambios == 1)
    	{
			/*if(aca se pregunta si hubo cambios que requieran reprocesar)
			{
				se recalcularian promedios por ej.
			}*/

			ejecutarEnConsola(LIMPIAR_PANTALLA);
			imprimirTitulo(DEPENDE_TITULO_MODIFICACION);

			imprimirEnPantalla(DEPENDE_MSJ_REGISTRO_ACTUAL);
			eDepende_mostrarUno(listado[posicion]);

			imprimirEnPantalla(DEPENDE_MSJ_REGISTRO_MODIFICADO);
			eDepende_mostrarUno(registro);

			confirmacion = pedirConfirmacion(MSJ_CONFIRMA_CORRECTOS);
		}
		else
		{
			confirmacion = 'N';
		}

		if(confirmacion == 'S')
		{
			listado[posicion] = registro;
    		eDepende_ordenar(listado, limite, DEPENDE_ORDEN);

			imprimirEnPantalla(DEPENDE_MSJ_MODIFICACION_OK);
		}
		else
		{
			imprimirEnPantalla(MSJ_CANCELO_GESTION);
		}
	}

	ejecutarEnConsola(HACER_PAUSA);
}

void eDepende_ordenar(eDepende listado[], int limite, char orden[])
{
	int i;
	int j;
	eDepende aux;

	if(strcmp(orden, "idAsc") == 0)
	{
		for(i=0 ; i<limite-1 ; i++)
		{
			for(j=i+1 ; j<limite ; j++)
			{
				if(listado[i].idDepende > listado[j].idDepende)
				{
					aux = listado[i];
					listado[i] = listado[j];
					listado[j] = aux;
				}
			}
		}
	}
	else if(strcmp(orden, "idDesc") == 0)
	{
		for(i=0 ; i<limite-1 ; i++)
		{
			for(j=i+1 ; j<limite ; j++)
			{
				if(listado[i].idDepende < listado[j].idDepende)
				{
					aux = listado[i];
					listado[i] = listado[j];
					listado[j] = aux;
				}
			}
		}
	}
	else if(strcmp(orden, "nombreAsc") == 0)
	{
		for(i=0 ; i<limite-1 ; i++)
		{
			for(j=i+1 ; j<limite ; j++)
			{
				if(strcmpi(listado[i].nombre, listado[j].nombre) > 0)
				{
					aux = listado[i];
					listado[i] = listado[j];
					listado[j] = aux;
				}
			}
		}
	}
	else if(strcmp(orden, "nombreDesc") == 0)
	{
		for(i=0 ; i<limite-1 ; i++)
		{
			for(j=i+1 ; j<limite ; j++)
			{
				if(strcmpi(listado[i].nombre, listado[j].nombre) < 0)
				{
					aux = listado[i];
					listado[i] = listado[j];
					listado[j] = aux;
				}
			}
		}
	}
}

void eDepende_gestion(eDepende listadoDepende[], int limiteDepende, eGenerica listadoGenerica[], int limiteGenerica)
{
	eMenu menuGestion = {/*cantidad de opciones*/DEPENDE_MENU_GESTION_CANT,
						/*codigos*/{1,2,3,4,0},
						/*descripciones*/{DEPENDE_MENU_GESTION_DETALLE1,DEPENDE_MENU_GESTION_DETALLE2,DEPENDE_MENU_GESTION_DETALLE3,DEPENDE_MENU_GESTION_DETALLE4,DEPENDE_MENU_GESTION_DETALLE5},
						/*titulo del menu*/{DEPENDE_MENU_GESTION_TITULO}};
	int opcion;
	char volverAlMain = 'N';

	do
	{
		ejecutarEnConsola(LIMPIAR_PANTALLA);
		opcion = pedirOpcion(menuGestion);
		switch(opcion)
		{
			case 1:
				eDepende_alta(listadoDepende, limiteDepende, listadoGenerica, limiteGenerica);
				break;
			case 2:
				eDepende_baja(listadoDepende, limiteDepende, listadoGenerica, limiteGenerica);
				break;
			case 3:
				eDepende_modificacion(listadoDepende, limiteDepende);
				break;
			case 4:
				eDepende_listar(listadoDepende, limiteDepende);
				break;
			case 0:
				volverAlMain = 'S';
				break;
		}
	}
	while(volverAlMain == 'N');
}
