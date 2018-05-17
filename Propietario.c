#include "Propietario.h"
#include <stdio.h>
#include <string.h>

void ePropietario_initHardcode(ePropietario listadoPropietarios[])
{
    //                                      nombre,direccion,tarjeta,ID,estado
    listadoPropietarios[0] = (ePropietario){"Juan","mitre","111-111",1,OCUPADO};
    listadoPropietarios[1] = (ePropietario){"Luis","urquiza","222-222",2,OCUPADO};
    listadoPropietarios[2] = (ePropietario){"Maria","belgrano","333-333",3,OCUPADO};
    listadoPropietarios[3] = (ePropietario){"Jose","alsina","444-444",4,OCUPADO};
}

void ePropietario_init(ePropietario listadoPropietarios[], int limitePropietarios)
{
	int i;
	for(i=0 ; i<limitePropietarios ; i++)
	{
		listadoPropietarios[i].estado= LIBRE;
		listadoPropietarios[i].idPropietario= 0;
	}
}

int ePropietario_buscarLugarLibre(ePropietario listadoPropietarios[], int limitePropietarios)
{
	int retorno = -1;
	int i;

	for(i=0 ; i<limitePropietarios ; i++)
	{
		if(listadoPropietarios[i].estado == LIBRE)
		{
			retorno = i;
			break;
		}
	}
	return retorno;
}

int ePropietario_siguienteId(ePropietario listadoPropietarios[], int limitePropietarios)
{
	int retorno = 0;
	int i;

	for(i=0; i<limitePropietarios; i++)
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

int ePropietario_estaVacio(ePropietario listadoPropietarios[], int limitePropietarios)
{
	int retorno = 1;
	int i;

	for(i=0 ; i<limitePropietarios ; i++)
	{
		if(listadoPropietarios[i].estado == OCUPADO)
		{
			retorno = 0;
			break;//con el primer ocupado ya se que no esta vacio
		}
	}
	return retorno;
}

int ePropietario_informarListadoVacio(ePropietario listadoPropietarios[], int limitePropietarios)
{
    int retorno;

    retorno = ePropietario_estaVacio(listadoPropietarios, limitePropietarios);
    if(retorno == 1)
    {
        imprimirEnPantalla(PROPIETARIO_MSJ_LISTA_VACIA);
    }
    return retorno;
}

int ePropietario_buscarPorId(ePropietario listadoPropietarios[], int limitePropietarios, int idPropietario)
{
	int retorno = -1;
	int i;

	for(i=0 ; i<limitePropietarios ; i++)
	{
		if(listadoPropietarios[i].estado == OCUPADO && listadoPropietarios[i].idPropietario == idPropietario)
		{
			retorno = i;
			break;
		}
	}
	return retorno;
}

void ePropietario_pedirNombre(char retorno[])
{
	pedirStringValido(retorno, PROPIETARIO_MSJ_INGRESE_NOMBRE, PROPIETARIO_MSJ_REINGRESE_NOMBRE, PROPIETARIO_LARGO_NOMBRE);
}

void ePropietario_pedirDireccion(char retorno[])
{
	pedirStringValido(retorno, PROPIETARIO_MSJ_INGRESE_DIRECCION, PROPIETARIO_MSJ_REINGRESE_DIRECCION, PROPIETARIO_LARGO_DIRECCION);
}

void ePropietario_pedirTarjeta(char retorno[])
{
	pedirStringValido(retorno, PROPIETARIO_MSJ_INGRESE_TARJETA, PROPIETARIO_MSJ_REINGRESE_TARJETA, PROPIETARIO_LARGO_TARJETA);
}

ePropietario ePropietario_pedirIngreso(ePropietario listadoPropietarios[], int limitePropietarios)
{
	ePropietario retorno;

	retorno.idPropietario = ePropietario_siguienteId(listadoPropietarios, limitePropietarios);

	ePropietario_pedirNombre((char *)&(retorno.nombre));

	ePropietario_pedirDireccion((char *)&(retorno.direccion));

	ePropietario_pedirTarjeta((char *)&(retorno.tarjeta));

	retorno.estado = OCUPADO;

	return retorno;
}


void ePropietario_mostrarUno(ePropietario propietario)
{
	 printf(PROPIETARIO_MOSTRAR_UNO_MASCARA, propietario.idPropietario, propietario.nombre, propietario.direccion, propietario.tarjeta);
}

void ePropietario_mostrarListado(ePropietario listadoPropietarios[], int limitePropietarios)
{
    int i;

    limpiarPantallaYMostrarTitulo(PROPIETARIO_LISTADO_TITULO);

    if(ePropietario_informarListadoVacio(listadoPropietarios, limitePropietarios) == 0)
    {
        imprimirEnPantalla(PROPIETARIO_MOSTRAR_UNO_CABECERA);

        for(i=0 ; i<limitePropietarios ; i++)
        {
            if(listadoPropietarios[i].estado == OCUPADO)
            {
                ePropietario_mostrarUno(listadoPropietarios[i]);
            }
        }
    }
}

void ePropietario_alta(ePropietario listadoPropietarios[], int limitePropietarios)
{
	ePropietario registro;
	char confirmacion;
	int posicion;

    limpiarPantalla();
    imprimirTitulo(PROPIETARIO_ALTA_TITULO);

	posicion = ePropietario_buscarLugarLibre(listadoPropietarios, limitePropietarios);
	if(posicion < 0)
	{
		imprimirEnPantalla(PROPIETARIO_MSJ_NO_MAS_LUGAR);
	}
	else
	{
		registro = ePropietario_pedirIngreso(listadoPropietarios, limitePropietarios);

		imprimirEnPantalla(PROPIETARIO_MOSTRAR_UNO_CABECERA);
		ePropietario_mostrarUno(registro);

		confirmacion = pedirConfirmacion(MSJ_CONFIRMA_CORRECTOS);

		if(confirmacion == 'S')
		{
			listadoPropietarios[posicion] = registro;
			ePropietario_ordenar(listadoPropietarios, limitePropietarios, PROPIETARIO_ORDEN_NOMBRE);
			imprimirEnPantalla(PROPIETARIO_MSJ_ALTA_OK);
		}
		else
		{
			imprimirEnPantalla(MSJ_CANCELO_GESTION);
		}
	}
	pausa();
}

void ePropietario_ordenar(ePropietario listado[], int limitePropietarios, char orden[])
{
	int i;
	int j;
	ePropietario aux;

	if(strcmp(orden, "idAsc") == 0)
	{
		for(i=0 ; i<limitePropietarios-1 ; i++)
		{
			for(j=i+1 ; j<limitePropietarios ; j++)
			{
				if(listado[i].idPropietario > listado[j].idPropietario)
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
		for(i=0 ; i<limitePropietarios-1 ; i++)
		{
			for(j=i+1 ; j<limitePropietarios ; j++)
			{
				if(listado[i].idPropietario < listado[j].idPropietario)
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
		for(i=0 ; i<limitePropietarios-1 ; i++)
		{
			for(j=i+1 ; j<limitePropietarios ; j++)
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
		for(i=0 ; i<limitePropietarios-1 ; i++)
		{
			for(j=i+1 ; j<limitePropietarios ; j++)
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

int ePropietario_modificarUno(ePropietario registro[])
{
	 eMenu menuModificar = {/*cantidad de opciones*/PROPIETARIO_MENU_MODIFICAR_UNO_CANT,
							/*codigos*/{1,0},
							/*descripciones*/{PROPIETARIO_MENU_MODIFICAR_UNO_DETALLE1,PROPIETARIO_MENU_MODIFICAR_UNO_DETALLE0},
							/*titulo del menu*/{PROPIETARIO_MENU_MODIFICAR_UNO_TITULO}};
	int opcion;
	int huboCambios = 1;

	ejecutarEnConsola(LIMPIAR_PANTALLA);
	imprimirTitulo(MSJ_MODIFICANDO_REGISTRO);
	imprimirEnPantalla(MSJ_DATOS_A_MODIFICAR);
    imprimirEnPantalla(PROPIETARIO_MOSTRAR_UNO_CABECERA);

	ePropietario_mostrarUno(*registro);

	opcion = pedirOpcion(menuModificar);
	switch(opcion)
	{
		case 1:
			ePropietario_pedirTarjeta((char *)&registro->tarjeta);
			break;
		case 0:
		    huboCambios = 0;
			break;
	}
	return huboCambios;
}

int ePropietario_pedirIdYBuscar(ePropietario listadoPropietarios[], int limitePropietarios)
{
	int retorno;
	int idPropietario;

	do
	{
		ePropietario_mostrarListado(listadoPropietarios, limitePropietarios);
		idPropietario = pedirIntValido(PROPIETARIO_MSJ_INGRESE_ID, PROPIETARIO_MSJ_REINGRESE_ID, PROPIETARIO_ID_MIN, PROPIETARIO_ID_MAX);
		retorno = ePropietario_buscarPorId(listadoPropietarios, limitePropietarios, idPropietario);
		if(retorno < 0)
		{
			imprimirEnPantalla(PROPIETARIO_MSJ_ID_NO_EXISTE);
			pausa();
		}
	}
	while(retorno < 0);

	return retorno;
}

void ePropietario_modificacion(ePropietario listadoPropietarios[], int limitePropietarios)
{
	ePropietario registro;
	char confirmacion;
	int posicion;
	int huboCambios;

	ejecutarEnConsola(LIMPIAR_PANTALLA);
	imprimirTitulo(PROPIETARIO_MODIFICACION_TITULO);

	if(ePropietario_estaVacio(listadoPropietarios, limitePropietarios) == 1)
	{
		imprimirEnPantalla(PROPIETARIO_MSJ_LISTA_VACIA);
	}
	else
	{
		posicion = ePropietario_pedirIdYBuscar(listadoPropietarios, limitePropietarios);
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
            imprimirTitulo(PROPIETARIO_MODIFICACION_TITULO);

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
            ePropietario_ordenar(listadoPropietarios, limitePropietarios, PROPIETARIO_ORDEN_ID);


			imprimirEnPantalla(PROPIETARIO_MSJ_MODIFICACION_OK);
		}
		else
		{
			imprimirEnPantalla(MSJ_CANCELO_GESTION);
		}
	}

	ejecutarEnConsola(HACER_PAUSA);
}

int ePropietario_baja(ePropietario listadoPropietarios[], int limitePropietarios)
{
	char confirmacion;
	int posicion;
	int idPropietario;

	ejecutarEnConsola(LIMPIAR_PANTALLA);
	imprimirTitulo(PROPIETARIO_BAJA_TITULO);

	if(ePropietario_estaVacio(listadoPropietarios, limitePropietarios) == 1)
	{
		imprimirEnPantalla(PROPIETARIO_MSJ_LISTA_VACIA);
	}
	else
	{
		ejecutarEnConsola(LIMPIAR_PANTALLA);
		imprimirTitulo(PROPIETARIO_BAJA_TITULO);

		posicion = ePropietario_pedirIdYBuscar(listadoPropietarios, limitePropietarios);

		imprimirEnPantalla(PROPIETARIO_MOSTRAR_UNO_CABECERA);
		ePropietario_mostrarUno(listadoPropietarios[posicion]);

		confirmacion = pedirConfirmacion(PROPIETARIO_MSJ_CONFIRMAR_BAJA);

		if(confirmacion == 'S')
		{
			idPropietario = listadoPropietarios[posicion].idPropietario;
			listadoPropietarios[posicion].estado = LIBRE;
			imprimirEnPantalla(PROPIETARIO_MSJ_BAJA_OK);
		}
		else
		{
			imprimirEnPantalla(MSJ_CANCELO_GESTION);
		}
	}

	ejecutarEnConsola(HACER_PAUSA);
	return idPropietario;
}
