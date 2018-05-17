#include "General.h"
#include "Automovil.h"
#include "Menu.h"
#include <stdio.h>
#include <string.h>

void eAutomovil_initHardcode(eAutomovil listadoAutomoviles[])
{
    //                              marca,patente,ID,FK,estado
    listadoAutomoviles[0] = (eAutomovil){1,"AAA",1,2,OCUPADO};
    listadoAutomoviles[1] = (eAutomovil){3,"CCC",2,1,OCUPADO};
    listadoAutomoviles[2] = (eAutomovil){3,"DDD",3,2,OCUPADO};
    listadoAutomoviles[3] = (eAutomovil){2,"BBB",4,1,OCUPADO};
    listadoAutomoviles[4] = (eAutomovil){2,"ZZZ",5,3,OCUPADO};
    listadoAutomoviles[5] = (eAutomovil){3,"III",6,3,OCUPADO};
    listadoAutomoviles[6] = (eAutomovil){3,"HHH",7,4,OCUPADO};
    listadoAutomoviles[7] = (eAutomovil){4,"EEE",8,1,OCUPADO};
    listadoAutomoviles[8] = (eAutomovil){3,"FFF",9,4,OCUPADO};
    listadoAutomoviles[9] = (eAutomovil){1,"GGG",10,3,OCUPADO};
}

void eAutomovil_init(eAutomovil listadoAutomoviles[], int limiteAutomoviles)
{
	int i;
	for(i=0 ; i<limiteAutomoviles ; i++)
	{
		listadoAutomoviles[i].estado= LIBRE;
		listadoAutomoviles[i].idAutomovil= 0;
	}
}

int eAutomovil_buscarLugarLibre(eAutomovil listadoAutomoviles[], int limiteAutomoviles)
{
	int retorno = -1;
	int i;

	for(i=0 ; i<limiteAutomoviles ; i++)
	{
		if(listadoAutomoviles[i].estado == LIBRE)
		{
			retorno = i;
			break;
		}
	}
	return retorno;
}

int eAutomovil_siguienteId(eAutomovil listadoAutomoviles[], int limiteAutomoviles)
{
	int retorno = 0;
	int i;

	for(i=0; i<limiteAutomoviles; i++)
	{
		if(listadoAutomoviles[i].estado == OCUPADO)
		{
			if(listadoAutomoviles[i].idAutomovil > retorno)
			{
				 retorno = listadoAutomoviles[i].idAutomovil;
			}
		}
	}
	return retorno+1;
}

int eAutomovil_estaVacio(eAutomovil listadoAutomoviles[], int limiteAutomoviles)
{
	int retorno = 1;
	int i;

	for(i=0 ; i<limiteAutomoviles ; i++)
	{
		if(listadoAutomoviles[i].estado == OCUPADO)
		{
			retorno = 0;
			break;//con el primer ocupado ya se que no esta vacio
		}
	}
	return retorno;
}

int eAutomovil_informarListadoVacio(eAutomovil listadoAutomoviles[], int limiteAutomoviles)
{
    int retorno;

    retorno = eAutomovil_estaVacio(listadoAutomoviles, limiteAutomoviles);
    if(retorno == 1)
    {
        imprimirEnPantalla(PROPIETARIO_MSJ_LISTA_VACIA);
    }
    return retorno;
}

int eAutomovil_buscarPorId(eAutomovil listadoAutomoviles[], int limiteAutomoviles, int idAutomovil)
{
	int retorno = -1;
	int i;

	for(i=0 ; i<limiteAutomoviles ; i++)
	{
		if(listadoAutomoviles[i].estado == OCUPADO && listadoAutomoviles[i].idAutomovil == idAutomovil)
		{
			retorno = i;
			break;
		}
	}
	return retorno;
}

int eAutomovil_pedirIdYBuscar(eAutomovil listadoAutomoviles[], int limiteAutomoviles)
{
	int retorno;
	int idAutomovil;

	do
	{
		eAutomovil_mostrarListado(listadoAutomoviles, limiteAutomoviles);
		idAutomovil = pedirIntValido(AUTOMOVIL_MSJ_INGRESE_ID, AUTOMOVIL_MSJ_REINGRESE_ID, AUTOMOVIL_ID_MIN, AUTOMOVIL_ID_MAX);
		retorno = eAutomovil_buscarPorId(listadoAutomoviles, limiteAutomoviles, idAutomovil);
		if(retorno < 0)
		{
			imprimirEnPantalla(AUTOMOVIL_MSJ_ID_NO_EXISTE);
			pausa();
		}
	}
	while(retorno < 0);

	return retorno;
}

void eAutomovil_convertirCodMarcaEnTexto(int codMarca, char textoMarca[])
{
    switch(codMarca)
    {
        case ALPHA_ROMEO:
            strcpy(textoMarca, MSJ_ALPHA_ROMEO);
            break;
        case FERRARI:
            strcpy(textoMarca, MSJ_FERRARI);
            break;
        case AUDI:
            strcpy(textoMarca, MSJ_AUDI);
            break;
        case OTROS:
            strcpy(textoMarca, MSJ_OTROS);
            break;
    }
}

int eAutomovil_informarExisteIdPropietario(eAutomovil listadoAutomoviles[], int limiteAutomoviles, int idPropietario)
{
	int retorno = 0;
	int i;

	for(i=0 ; i<limiteAutomoviles ; i++)
	{
		if(listadoAutomoviles[i].estado == OCUPADO && listadoAutomoviles[i].idPropietario == idPropietario)
		{
			retorno = 1;
			break;//con el primer ocupado ya se que existe al menos uno
		}
	}

	if(retorno == 0)
    {
        imprimirEnPantalla(AUTOMOVIL_MSJ_NO_EXISTEN_ID_PROPIETARIO);
    }
	return retorno;
}

void eAutomovil_ordenar(eAutomovil listado[], int limiteAutomoviles, char orden[])
{
	int i;
	int j;
	eAutomovil aux;

	if(strcmp(orden, "idAsc") == 0)
	{
		for(i=0 ; i<limiteAutomoviles-1 ; i++)
		{
			for(j=i+1 ; j<limiteAutomoviles ; j++)
			{
				if(listado[i].idAutomovil > listado[j].idAutomovil)
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
		for(i=0 ; i<limiteAutomoviles-1 ; i++)
		{
			for(j=i+1 ; j<limiteAutomoviles ; j++)
			{
				if(listado[i].idAutomovil < listado[j].idAutomovil)
				{
					aux = listado[i];
					listado[i] = listado[j];
					listado[j] = aux;
				}
			}
		}
	}
	else if(strcmp(orden, "marcaAsc") == 0)
	{
		for(i=0 ; i<limiteAutomoviles-1 ; i++)
		{
			for(j=i+1 ; j<limiteAutomoviles ; j++)
			{
				if(listado[i].marca > listado[j].marca)
				{
					aux = listado[i];
					listado[i] = listado[j];
					listado[j] = aux;
				}
			}
		}
	}
	else if(strcmp(orden, "marcaDesc") == 0)
	{
		for(i=0 ; i<limiteAutomoviles-1 ; i++)
		{
			for(j=i+1 ; j<limiteAutomoviles ; j++)
			{
				if(listado[i].marca < listado[j].marca)
				{
					aux = listado[i];
					listado[i] = listado[j];
					listado[j] = aux;
				}
			}
		}
	}
	else if(strcmp(orden, "patenteAsc") == 0)
	{
		for(i=0 ; i<limiteAutomoviles-1 ; i++)
		{
			for(j=i+1 ; j<limiteAutomoviles ; j++)
			{
				if(strcmpi(listado[i].patente, listado[j].patente) > 0)
				{
					aux = listado[i];
					listado[i] = listado[j];
					listado[j] = aux;
				}
			}
		}
	}
	else if(strcmp(orden, "patenteDesc") == 0)
	{
		for(i=0 ; i<limiteAutomoviles-1 ; i++)
		{
			for(j=i+1 ; j<limiteAutomoviles ; j++)
			{
				if(strcmpi(listado[i].patente, listado[j].patente) < 0)
				{
					aux = listado[i];
					listado[i] = listado[j];
					listado[j] = aux;
				}
			}
		}
	}
}

int eAutomovil_pedirMarca()
{
    eMenu menuMarca = {/*cantidad de opciones*/AUTOMOVIL_MENU_MARCA_CANT,
                            /*codigos*/{ALPHA_ROMEO, FERRARI, AUDI, OTROS},
                            /*descripciones*/{MSJ_MENU_ALPHA_ROMEO, MSJ_MENU_FERRARI, MSJ_MENU_AUDI, MSJ_MENU_OTROS},
                            /*titulo del menu*/{AUTOMOVIL_MENU_MARCA_TITULO}};
    int retorno;

	retorno = pedirOpcion(menuMarca);

	return retorno;
}

void eAutomovil_pedirPatente(char retorno[])
{
	pedirStringValido(retorno, AUTOMOVIL_MSJ_INGRESE_PATENTE, AUTOMOVIL_MSJ_REINGRESE_PATENTE, AUTOMOVIL_LARGO_PATENTE);
}

eAutomovil eAutomovil_pedirIngreso(eAutomovil listadoAutomoviles[], int limiteAutomoviles, ePropietario listadoPropietarios[], int limitePropietarios)
{
	eAutomovil retorno;

	retorno.idAutomovil = eAutomovil_siguienteId(listadoAutomoviles, limiteAutomoviles);

	retorno.idPropietario = listadoPropietarios[ePropietario_pedirIdYBuscar(listadoPropietarios, limitePropietarios)].idPropietario;

	retorno.marca = eAutomovil_pedirMarca();

	eAutomovil_pedirPatente((char *)&(retorno.patente));

	retorno.estado = OCUPADO;

	return retorno;
}


void eAutomovil_mostrarUno(eAutomovil automovil)
{
	 char textoMarca[AUTOMOVIL_LARGO_MARCA];

	 eAutomovil_convertirCodMarcaEnTexto(automovil.marca, textoMarca);
	 printf(AUTOMOVIL_MOSTRAR_UNO_MASCARA, automovil.idAutomovil, textoMarca, automovil.patente);
}

void eAutomovil_mostrarListado(eAutomovil listadoAutomoviles[], int limiteAutomoviles)
{
    int i;

    limpiarPantallaYMostrarTitulo(AUTOMOVIL_LISTADO_TITULO);

    if(eAutomovil_informarListadoVacio(listadoAutomoviles, limiteAutomoviles) == 0)
    {
        imprimirEnPantalla(AUTOMOVIL_MOSTRAR_UNO_CABECERA);

        for(i=0 ; i<limiteAutomoviles ; i++)
        {
            if(listadoAutomoviles[i].estado == OCUPADO)
            {
                eAutomovil_mostrarUno(listadoAutomoviles[i]);
            }
        }
    }
}

void eAutomovil_alta(eAutomovil listadoAutomoviles[], int limiteAutomoviles, ePropietario listadoPropietarios[], int limitePropietarios)
{
	eAutomovil registro;
	char confirmacion;
	int posicion;

    limpiarPantalla();
    imprimirTitulo(AUTOMOVIL_ALTA_TITULO);

	posicion = eAutomovil_buscarLugarLibre(listadoAutomoviles, limiteAutomoviles);
	if(posicion < 0)
	{
		imprimirEnPantalla(AUTOMOVIL_MSJ_NO_MAS_LUGAR);
	}
	else
	{
		registro = eAutomovil_pedirIngreso(listadoAutomoviles, limiteAutomoviles, listadoPropietarios, limitePropietarios);

		imprimirEnPantalla(AUTOMOVIL_MOSTRAR_UNO_CABECERA);
		eAutomovil_mostrarUno(registro);

		confirmacion = pedirConfirmacion(MSJ_CONFIRMA_CORRECTOS);

		if(confirmacion == 'S')
		{
			listadoAutomoviles[posicion] = registro;
			eAutomovil_ordenar(listadoAutomoviles, limiteAutomoviles, AUTOMOVIL_ORDEN_PATENTE);
			imprimirEnPantalla(AUTOMOVIL_MSJ_ALTA_OK);
		}
		else
		{
			imprimirEnPantalla(MSJ_CANCELO_GESTION);
		}
	}
	pausa();
}

void eAutomovil_baja(eAutomovil listadoAutomoviles[], int limiteAutomoviles, ePropietario listadoPropietarios[], int limitePropietarios)
{
	char confirmacion;
	int posicionAutomovil;
	int posicionPropietario;
	ePropietario propietario;

	ejecutarEnConsola(LIMPIAR_PANTALLA);
	imprimirTitulo(AUTOMOVIL_BAJA_TITULO);

	if(eAutomovil_estaVacio(listadoAutomoviles, limiteAutomoviles) == 1)
	{
		imprimirEnPantalla(AUTOMOVIL_MSJ_LISTA_VACIA);
	}
	else
	{
		ejecutarEnConsola(LIMPIAR_PANTALLA);
		imprimirTitulo(AUTOMOVIL_BAJA_TITULO);

		posicionAutomovil = eAutomovil_pedirIdYBuscar(listadoAutomoviles, limiteAutomoviles);

		imprimirEnPantalla(AUTOMOVIL_MOSTRAR_UNO_CABECERA);
		eAutomovil_mostrarUno(listadoAutomoviles[posicionAutomovil]);

		confirmacion = pedirConfirmacion(AUTOMOVIL_MSJ_CONFIRMAR_BAJA);

		if(confirmacion == 'S')
		{
		    posicionPropietario = ePropietario_buscarPorId(listadoPropietarios, limitePropietarios, listadoAutomoviles[posicionAutomovil].idPropietario);
            propietario = listadoPropietarios[posicionPropietario];
			emitirTicket(listadoAutomoviles[posicionAutomovil], propietario);
			listadoAutomoviles[posicionAutomovil].estado = LIBRE;
		}
		else
		{
			imprimirEnPantalla(MSJ_CANCELO_GESTION);
		}
	}

	pausa();
}

int devolverHorasEstadia()
{
    int horas;

    srand(time(NULL));

    horas = (rand()%24)+1;

    return horas ;

};

int calcularValorEstadia(eAutomovil automovil, int horasEstadia)
{
    int retorno;
    int valorHora;

    switch(automovil.marca)
    {
        case ALPHA_ROMEO:
            valorHora = 150;
            break;
        case FERRARI:
            valorHora = 175;
            break;
        case AUDI:
            valorHora = 200;
            break;
        case OTROS:
            valorHora = 250;
            break;
    }

    retorno = valorHora * horasEstadia;

    return retorno;
}

void emitirTicket(eAutomovil automovil, ePropietario propietario)
{
    int valorEstadia;
    char textoMarca[AUTOMOVIL_LARGO_MARCA];

    valorEstadia = calcularValorEstadia(automovil, devolverHorasEstadia());
    eAutomovil_convertirCodMarcaEnTexto(automovil.marca, textoMarca);

    limpiarPantalla();
    imprimirTitulo(AUTOMOVIL_BAJA_TITULO);

    imprimirEnPantalla("\nPROPIETARIO - PATENTE - MARCA - VALOR ESTADIA ($)");
    printf("\n%-5s - %-5s - %-5s - $%-4d", propietario.nombre, automovil.patente, textoMarca, valorEstadia);
}
