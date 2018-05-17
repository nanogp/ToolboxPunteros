#include "Propietario.h"
#include "General.h"
#include "Menu.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ePropietario_initHardcode(ePropietario listadoPropietarios[])
{                            /*nombre, numero, ID, estado*/
	listadoPropietarios[0] = (ePropietario){{"Jose Luis tiene 1"}, 12345, 11, OCUPADO};
	listadoPropietarios[1] = (ePropietario){{"Bobby Fisher tiene 3"}, 12345, 12, OCUPADO};
	listadoPropietarios[2] = (ePropietario){{"Donia Rosa tiene 2"}, 12345, 13, OCUPADO};
	listadoPropietarios[3] = (ePropietario){{"Fulano tiene Mengano"}, 12345, 14, OCUPADO};
	listadoPropietarios[4] = (ePropietario){{"Roque sin Penia tiene 0"}, 12345, 15, OCUPADO};
	ePropietario_ordenar(listadoPropietarios, PROPIETARIO_CANT_MAX, PROPIETARIO_ORDEN);
}

void ePropietario_init(ePropietario listadoPropietarios[], int listadoPropietarios)
{
	int i;
	for(i=0 ; i<listadoPropietarios ; i++)
	{
		listadoPropietarios[i].estado= LIBRE;
		listadoPropietarios[i].idPropietario= 0;
	}
}

int ePropietario_buscarLugarLibre(ePropietario listadoPropietarios[], int listadoPropietarios)
{
	int retorno = -1;
	int i;

	for(i=0 ; i<listadoPropietarios ; i++)
	{
		if(listadoPropietarios[i].estado == LIBRE)
		{
			retorno = i;
			break;
		}
	}
	return retorno;
}

int ePropietario_siguienteId(ePropietario listadoPropietarios[], int listadoPropietarios)
{
	int retorno = 0;
	int i;

	for(i=0; i<listadoPropietarios; i++)
	{
		if(listadoPropietarios[i].estado == OCUPADO)
		{
			if(listadoPropietarios[i].idPropietario > retorno)
			{
				 retorno = listadoPropietarios[i].idPropietario;
			}
		}
	}
	return retorno+1;
}

int ePropietario_buscarPorId(ePropietario listadoPropietarios[], int listadoPropietarios, int id)
{
	int retorno = -1;
	int i;

	for(i=0 ; i<listadoPropietarios ; i++)
	{
		if(listadoPropietarios[i].estado == OCUPADO && listadoPropietarios[i].idPropietario == id)
		{
			retorno = i;
			break;
		}
	}
	return retorno;
}

int ePropietario_pedirIdYBuscar(ePropietario listadoPropietarios[], int listadoPropietarios)
{
	int retorno;
	int id;

	do
	{
		ePropietario_mostrarListado(listadoPropietarios, listadoPropietarios);
		id = pedirIntValido(PROPIETARIO_MSJ_INGRESE_ID, PROPIETARIO_MSJ_REINGRESE_ID, PROPIETARIO_ID_MIN, PROPIETARIO_ID_MAX);
		retorno = ePropietario_buscarPorId(listadoPropietarios, listadoPropietarios, id);
		if(retorno < 0)
		{
			imprimirEnPantalla(PROPIETARIO_MSJ_ID_NO_EXISTE);
		}
	}
	while(retorno < 0);

	return retorno;
}

int ePropietario_buscarPorNombre(ePropietario listadoPropietarios[], int listadoPropietarios, char nombre[])
{
	int retorno = -1;
	int i;

	for(i=0 ; i<listadoPropietarios ; i++)
	{
		if(listadoPropietarios[i].estado == OCUPADO && strcmpi(listadoPropietarios[i].nombre, nombre) == 0)
		{
			retorno = i;
			break;
		}
	}
	return retorno;
}

int ePropietario_pedirNombreYBuscar(ePropietario listadoPropietarios[], int listadoPropietarios)
{
	int retorno;
	char nombre[PROPIETARIO_LARGO_NOMBRE];

	do
	{
		ePropietario_mostrarListado(listadoPropietarios, listadoPropietarios);
		ePropietario_pedirNombre(nombre);
		retorno = ePropietario_buscarPorNombre(listadoPropietarios, listadoPropietarios, nombre);
		if(retorno < 0)
		{
			imprimirEnPantalla(PROPIETARIO_MSJ_NOMBRE_NO_EXISTE);
		}
	}
	while(retorno < 0);

	return retorno;
}

int ePropietario_estaVacio(ePropietario listadoPropietarios[], int listadoPropietarios)
{
	int retorno = 1;
	int i;

	for(i=0 ; i<listadoPropietarios ; i++)
	{
		if(listadoPropietarios[i].estado == OCUPADO)
		{
			retorno = 0;
			break;//con el primer ocupado ya se que no esta vacio
		}
	}
	return retorno;
}

void ePropietario_mostrarUno(ePropietario registro)
{
	 printf(PROPIETARIO_MASCARA_MOSTRAR_UNO, registro.idPropietario, registro.nombre, registro.numero);

}

void ePropietario_mostrarListado(ePropietario listadoPropietarios[], int listadoPropietarios)
{
	int i;
	int contadorMostrados = 0;

	if(ePropietario_estaVacio(listadoPropietarios, listadoPropietarios) == 1)
	{
		imprimirEnPantalla(PROPIETARIO_MSJ_LISTA_VACIA);
	}
	else
	{
		imprimirEnPantalla(PROPIETARIO_CABECERA_LISTADO);
		for(i=0; i<listadoPropietarios; i++)
		{
			if(listadoPropietarios[i].estado==OCUPADO)
			{
				ePropietario_mostrarUno(listadoPropietarios[i]);
				contadorMostrados++;

				if(contadorMostrados%20 == 0)
				{
					//cada 20 registros hago una pausa
					ejecutarEnConsola(HACER_PAUSA);
					imprimirEnPantalla(PROPIETARIO_CABECERA_LISTADO);
				}
			}

		}
	}
}

void ePropietario_listar(ePropietario listadoPropietarios[], int listadoPropietarios)
{
	ejecutarEnConsola(LIMPIAR_PANTALLA);
	imprimirTitulo(PROPIETARIO_TITULO_LISTA);

	ePropietario_mostrarListado(listadoPropietarios, listadoPropietarios);

	ejecutarEnConsola(HACER_PAUSA);
}

void ePropietario_pedirNombre(char retorno[])
{
	pedirStringValido(retorno, PROPIETARIO_MSJ_INGRESE_NOMBRE, PROPIETARIO_MSJ_REINGRESE_NOMBRE, PROPIETARIO_LARGO_NOMBRE);
}

int ePropietario_pedirNumero()
{
	return pedirIntValido(PROPIETARIO_MSJ_INGRESE_NUMERO, PROPIETARIO_MSJ_REINGRESE_NUMERO, PROPIETARIO_NUMERO_MIN, PROPIETARIO_NUMERO_MAX);
}

ePropietario ePropietario_pedirIngreso(ePropietario listadoPropietarios[], int listadoPropietarios)
{
	ePropietario retorno;

	retorno.idPropietario = ePropietario_siguienteId(listadoPropietarios, listadoPropietarios);

	ePropietario_pedirNombre((char *)&(retorno.nombre));

	retorno.numero = ePropietario_pedirNumero();

	retorno.estado = OCUPADO;

	return retorno;
}

void ePropietario_alta(ePropietario listadoPropietarios[], int listadoPropietarios)
{
	ePropietario registro;
	char confirmacion;
	int posicion;

	posicion = ePropietario_buscarLugarLibre(listadoPropietarios, listadoPropietarios);
	if(posicion < 0)
	{
		imprimirEnPantalla(PROPIETARIO_MSJ_NO_MAS_LUGAR);
	}
	else
	{
		ejecutarEnConsola(LIMPIAR_PANTALLA);
		imprimirTitulo(PROPIETARIO_TITULO_ALTA);
		imprimirEnPantalla(PROPIETARIO_CABECERA_LISTADO);

		registro = ePropietario_pedirIngreso(listadoPropietarios, listadoPropietarios);
		ePropietario_mostrarUno(registro);

		confirmacion = pedirConfirmacion(MSJ_CONFIRMA_CORRECTOS);

		if(confirmacion == 'S')
		{
			listadoPropietarios[posicion] = registro;
			ePropietario_ordenar(listadoPropietarios, listadoPropietarios, PROPIETARIO_ORDEN);
			imprimirEnPantalla(PROPIETARIO_MSJ_ALTA_OK);
		}
		else
		{
			imprimirEnPantalla(MSJ_CANCELO_GESTION);
		}
	}
	ejecutarEnConsola(HACER_PAUSA);
}

void ePropietario_baja(ePropietario listadoPropietarios[], int listadoPropietarios)
{
	char confirmacion;
	int posicion;

	ejecutarEnConsola(LIMPIAR_PANTALLA);
	imprimirTitulo(PROPIETARIO_TITULO_BAJA);

	if(ePropietario_estaVacio(listadoPropietarios, listadoPropietarios) == 1)
	{
		imprimirEnPantalla(PROPIETARIO_MSJ_LISTA_VACIA);
	}
	else
	{
		ejecutarEnConsola(LIMPIAR_PANTALLA);
		imprimirTitulo(PROPIETARIO_TITULO_BAJA);

		posicion = ePropietario_pedirIdYBuscar(listadoPropietarios, listadoPropietarios);

		imprimirEnPantalla(PROPIETARIO_CABECERA_LISTADO);
		ePropietario_mostrarUno(listadoPropietarios[posicion]);

		confirmacion = pedirConfirmacion(PROPIETARIO_MSJ_CONFIRMAR_BAJA);

		if(confirmacion == 'S')
		{
			listadoPropietarios[posicion].estado = LIBRE;
			imprimirEnPantalla(PROPIETARIO_MSJ_BAJA_OK);
		}
		else
		{
			imprimirEnPantalla(MSJ_CANCELO_GESTION);
		}
	}

	ejecutarEnConsola(HACER_PAUSA);
}

int ePropietario_modificarUno(ePropietario registro[])
{
	eMenu menuModificar = {/*cantidad de opciones*/PROPIETARIO_MENU_MODIFICAR_UNO_CANT,
							/*codigos*/{1,2,3,4,0},
							/*descripciones*/{PROPIETARIO_MENU_MODIFICAR_UNO_DETALLE1,PROPIETARIO_MENU_MODIFICAR_UNO_DETALLE2,PROPIETARIO_MENU_MODIFICAR_UNO_DETALLE3,PROPIETARIO_MENU_MODIFICAR_UNO_DETALLE4,PROPIETARIO_MENU_MODIFICAR_UNO_DETALLE5},
							/*titulo del menu*/{PROPIETARIO_MENU_MODIFICAR_UNO_TITULO}};
	int opcion;
	int huboCambios = 1;

	ejecutarEnConsola(LIMPIAR_PANTALLA);
	imprimirTitulo(MSJ_MODIFICANDO_REGISTRO);
	imprimirEnPantalla(MSJ_DATOS_A_MODIFICAR);
    imprimirEnPantalla(PROPIETARIO_CABECERA_LISTADO);

	ePropietario_mostrarUno(*registro);

	opcion = pedirOpcion(menuModificar);
	switch(opcion)
	{
		case 1:
			ePropietario_pedirNombre((char *)&registro->nombre);
			break;
		case 2:
			registro->numero = ePropietario_pedirNumero();
			break;
		case 3:
			//registro->idPropietario;
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

void ePropietario_modificacion(ePropietario listadoPropietarios[], int listadoPropietarios)
{
	ePropietario registro;
	char confirmacion;
	int posicion;
	int huboCambios;

	ejecutarEnConsola(LIMPIAR_PANTALLA);
	imprimirTitulo(PROPIETARIO_TITULO_MODIFICACION);

	if(ePropietario_estaVacio(listadoPropietarios, listadoPropietarios) == 1)
	{
		imprimirEnPantalla(PROPIETARIO_MSJ_LISTA_VACIA);
	}
	else
	{
		posicion = ePropietario_pedirIdYBuscar(listadoPropietarios, listadoPropietarios);
		//traigo el registro del id elegido para no pisar directo sobre el listadoPropietarios
		registro = listadoPropietarios[posicion];

		huboCambios = ePropietario_modificarUno(&registro);
		if(huboCambios == 1)
        {
            /*if(aca se pregunta si hubo cambios que requieran reprocesar)
            {
                se recalcularian promedios por ej.
            }*/

            ejecutarEnConsola(LIMPIAR_PANTALLA);
            imprimirTitulo(PROPIETARIO_TITULO_MODIFICACION);

            imprimirEnPantalla(PROPIETARIO_MSJ_REGISTRO_ACTUAL);
            ePropietario_mostrarUno(listadoPropietarios[posicion]);

            imprimirEnPantalla(PROPIETARIO_MSJ_REGISTRO_MODIFICADO);
            ePropietario_mostrarUno(registro);

            confirmacion = pedirConfirmacion(MSJ_CONFIRMA_CORRECTOS);
        }
        else
        {
            confirmacion = 'N';
        }

		if(confirmacion == 'S')
		{
			listadoPropietarios[posicion] = registro;
            ePropietario_ordenar(listadoPropietarios, listadoPropietarios, PROPIETARIO_ORDEN);


			imprimirEnPantalla(PROPIETARIO_MSJ_MODIFICACION_OK);
		}
		else
		{
			imprimirEnPantalla(MSJ_CANCELO_GESTION);
		}
	}

	ejecutarEnConsola(HACER_PAUSA);
}

void ePropietario_ordenar(ePropietario listadoPropietarios[], int listadoPropietarios, char orden[])
{
	int i;
	int j;
	ePropietario aux;

	if(strcmp(orden, "idAsc") == 0)
	{
		for(i=0 ; i<listadoPropietarios-1 ; i++)
		{
			for(j=i+1 ; j<listadoPropietarios ; j++)
			{
				if(listadoPropietarios[i].idPropietario > listadoPropietarios[j].idPropietario)
				{
					aux = listadoPropietarios[i];
					listadoPropietarios[i] = listadoPropietarios[j];
					listadoPropietarios[j] = aux;
				}
			}
		}
	}
	else if(strcmp(orden, "idDesc") == 0)
	{
		for(i=0 ; i<listadoPropietarios-1 ; i++)
		{
			for(j=i+1 ; j<listadoPropietarios ; j++)
			{
				if(listadoPropietarios[i].idPropietario < listadoPropietarios[j].idPropietario)
				{
					aux = listadoPropietarios[i];
					listadoPropietarios[i] = listadoPropietarios[j];
					listadoPropietarios[j] = aux;
				}
			}
		}
	}
	else if(strcmp(orden, "nombreAsc") == 0)
	{
		for(i=0 ; i<listadoPropietarios-1 ; i++)
		{
			for(j=i+1 ; j<listadoPropietarios ; j++)
			{
				if(strcmpi(listadoPropietarios[i].nombre, listadoPropietarios[j].nombre) > 0)
				{
					aux = listadoPropietarios[i];
					listadoPropietarios[i] = listadoPropietarios[j];
					listadoPropietarios[j] = aux;
				}
			}
		}
	}
	else if(strcmp(orden, "nombreDesc") == 0)
	{
		for(i=0 ; i<listadoPropietarios-1 ; i++)
		{
			for(j=i+1 ; j<listadoPropietarios ; j++)
			{
				if(strcmpi(listadoPropietarios[i].nombre, listadoPropietarios[j].nombre) < 0)
				{
					aux = listadoPropietarios[i];
					listadoPropietarios[i] = listadoPropietarios[j];
					listadoPropietarios[j] = aux;
				}
			}
		}
	}
}

void ePropietario_gestion(ePropietario listadoPropietarios[], int listadoPropietarios)
{
	eMenu menuGestion = {/*cantidad de opciones*/PROPIETARIO_MENU_GESTION_CANT,
						/*codigos*/{1,2,3,4,0},
						/*descripciones*/{PROPIETARIO_MENU_GESTION_DETALLE1,PROPIETARIO_MENU_GESTION_DETALLE2,PROPIETARIO_MENU_GESTION_DETALLE3,PROPIETARIO_MENU_GESTION_DETALLE4,PROPIETARIO_MENU_GESTION_DETALLE5},
						/*titulo del menu*/{PROPIETARIO_MENU_GESTION_TITULO}};
	int opcion;
	char volverAlMain = 'N';

	do
	{
		ejecutarEnConsola(LIMPIAR_PANTALLA);
		opcion = pedirOpcion(menuGestion);
		switch(opcion)
		{
			case 1:
				ePropietario_alta(listadoPropietarios, listadoPropietarios);
				break;
			case 2:
				ePropietario_baja(listadoPropietarios, listadoPropietarios);
				break;
			case 3:
				ePropietario_modificacion(listadoPropietarios, listadoPropietarios);
				break;
			case 4:
				ePropietario_listar(listadoPropietarios, listadoPropietarios);
				break;
			case 0:
				volverAlMain = 'S';
				break;
		}
	}
	while(volverAlMain == 'N');
}

