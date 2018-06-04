#include "Padre.h"
#include <stdio.h>
#include <string.h>

//init
void ePadre_initHardcode(ePadre* listadoPadres)
{
    //                           nombre,Pais,ID,estado
    char paises[][20] = {"Argentina","Brasil","EEUU"};
    char nombres[][20] = {"Peso","Real","Dolar"};
    int dni[] = {111,222,333};
    int reservas[] = {1,2,3};

    for(int i = 0; i<3 ; i++)
    {
        strcpy(&((listadoPadres+i)->pais), (paises+i));
        strcpy(&((listadoPadres+i)->nombre), (nombres+i));
        (listadoPadres+i)->dni = *(dni+i);
        (listadoPadres+i)->reservas = *(reservas+i);
        (listadoPadres+i)->idPadre = i+1;
        (listadoPadres+i)->estado = OCUPADO;
    }

}

int ePadre_init(ePadre* listadoPadres, int limitePadres)
{
    int retorno = -1;
    int i;

    if(listadoPadres != NULL && limitePadres > 0)
    {
        retorno = 0;
        for(i=0 ; i<limitePadres ; i++)
        {
            (listadoPadres+i)->estado= LIBRE;
            (listadoPadres+i)->idPadre= 0;
        }
    }
    return retorno;
}

//busqueda
int ePadre_buscarLugarLibre(ePadre* listadoPadres, int limitePadres)
{
    int retorno = -1;
    int i;

    if(listadoPadres != NULL && limitePadres > 0)
    {
        retorno = -2;
        for(i=0 ; i<limitePadres ; i++)
        {
            if((listadoPadres+i)->estado == LIBRE)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int ePadre_siguienteId(ePadre* listadoPadres, int limitePadres)
{
    int retorno = -1;
    int i;

    if(listadoPadres != NULL && limitePadres > 0)
    {
        retorno = 0;
        for(i=0; i<limitePadres; i++)
        {
            if((listadoPadres+i)->estado == OCUPADO)
            {
                if((listadoPadres+i)->idPadre > retorno)
                {
                     retorno = (listadoPadres+i)->idPadre + 1;
                }
            }
        }
    }
    return retorno;
}

int ePadre_estaVacio(ePadre* listadoPadres, int limitePadres)
{
    int retorno = -1;
    int i;

    if(listadoPadres != NULL && limitePadres > 0)
    {
        retorno = 1;
        for(i=0 ; i<limitePadres ; i++)
        {
            if((listadoPadres+i)->estado == OCUPADO)
            {
                retorno = 0;
                break;//con el primer ocupado ya se que no esta vacio
            }
        }
    }
    return retorno;
}

int ePadre_informarListadoVacio(ePadre* listadoPadres, int limitePadres)
{
    int retorno;

    if(listadoPadres != NULL && limitePadres > 0)
    {
        retorno = ePadre_estaVacio(listadoPadres, limitePadres);
        if(retorno == 1)
        {
            imprimirEnPantalla(PADRE_MSJ_LISTA_VACIA);
        }
    }
    return retorno;
}

int ePadre_buscarPorId(ePadre* listadoPadres, int limitePadres, int idPadre)
{
    int retorno = -1;
    int i;

    if(listadoPadres != NULL && limitePadres > 0)
    {
        retorno = -2;
        for(i=0 ; i<limitePadres ; i++)
        {
            if((listadoPadres+i)->estado == OCUPADO && (listadoPadres+i)->idPadre == idPadre)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int ePadre_pedirIdYBuscar(ePadre* listadoPadres, int limitePadres)
{
    int retorno;
    int idPadre;

    do
    {
        ePadre_mostrarListado(listadoPadres, limitePadres);
        idPadre = ePadre_pedirId();
        retorno = ePadre_buscarPorId(listadoPadres, limitePadres, idPadre);
        if(retorno < 0)
        {
            imprimirEnPantalla(PADRE_MSJ_ID_NO_EXISTE);
            pausa();
        }
    }
    while(retorno < 0);

    return retorno;
}

//input
int ePadre_pedirId()
{
    return pedirIntValido(PADRE_MSJ_INGRESE_ID, PADRE_MSJ_REINGRESE_ID, PADRE_ID_MIN, PADRE_ID_MAX);
}

int ePadre_pedirDni()
{
    return pedirIntValido(PADRE_MSJ_INGRESE_DNI, PADRE_MSJ_REINGRESE_DNI, PADRE_DNI_MIN, PADRE_DNI_MAX);
}

void ePadre_pedirNombre(char* retorno)
{
    pedirStringValido(retorno, PADRE_MSJ_INGRESE_NOMBRE, PADRE_MSJ_REINGRESE_NOMBRE, PADRE_LARGO_NOMBRE);
}

void ePadre_pedirPais(char* retorno)
{
    pedirStringValido(retorno, PADRE_MSJ_INGRESE_PAIS, PADRE_MSJ_REINGRESE_PAIS, PADRE_LARGO_PAIS);
}

int ePadre_pedirReservas()
{
    eMenu menuConst = {/*cantidad de opciones*/PADRE_MENU_RESERVAS_CANT,
                            /*codigos*/{PADRE_K_A, PADRE_K_B, PADRE_K_OTROS},
                            /*descripciones*/{PADRE_MENU_RESERVAS_DETALLE1, PADRE_MENU_RESERVAS_DETALLE2, PADRE_MENU_RESERVAS_DETALLE3},
                            /*titulo del menu*/{PADRE_MENU_RESERVAS_TITULO}};
    int retorno;

    retorno = pedirOpcion(&menuConst);

    return retorno;
}

void ePadre_convertirCodEnTexto(int codigo, char* texto)
{
    switch(codigo)
    {
        case PADRE_K_A:
            strcpy(texto, PADRE_K_TXT_A);
            break;
        case PADRE_K_B:
            strcpy(texto, PADRE_K_TXT_B);
            break;
        case PADRE_K_OTROS:
            strcpy(texto, PADRE_K_TXT_OTROS);
            break;
    }
}

ePadre ePadre_pedirIngreso(ePadre* listadoPadres, int limitePadres)
{
    ePadre retorno;

    retorno.idPadre = ePadre_siguienteId(listadoPadres, limitePadres);

    ePadre_pedirNombre((char *)&(retorno.nombre));

    ePadre_pedirPais((char *)&(retorno.pais));

    retorno.dni = ePadre_pedirDni();

    retorno.reservas = ePadre_pedirReservas();

    retorno.estado = OCUPADO;

    return retorno;
}

//listado
int ePadre_mostrarUno(ePadre* padre)
{
    int retorno = -1;
    char textoReservas[PADRE_LARGO_RESERVAS] = {};
    ePadre_convertirCodEnTexto(padre->reservas, textoReservas);

    printf("%s\n",*textoReservas);pausa();

     if(padre != NULL)
     {
        retorno = 0;
        printf(PADRE_MOSTRAR_UNO_MASCARA, padre->idPadre, padre->nombre, padre->pais, padre->dni, textoReservas);
     }
     return retorno;
}

int ePadre_mostrarListado(ePadre* listadoPadres, int limitePadres)
{
    int retorno = -1;
    int i;

    if(listadoPadres != NULL && limitePadres > 0)
    {
        retorno = 0;
        limpiarPantallaYMostrarTitulo(PADRE_LISTADO_TITULO);

        if(ePadre_informarListadoVacio(listadoPadres, limitePadres) == 0)
        {
            imprimirEnPantalla(PADRE_MOSTRAR_UNO_CABECERA);

            for(i=0 ; i<limitePadres ; i++)
            {
                if((listadoPadres+i)->estado == OCUPADO)
                {
                    ePadre_mostrarUno(listadoPadres+i);
                }
            }
        }
    }
    return retorno;
}

int ePadre_alta(ePadre* listadoPadres, int limitePadres)
{
    int retorno = -1;
    ePadre registro;
    char confirmacion;
    int posicion;

    if(listadoPadres != NULL && limitePadres > 0)
    {
        retorno = 0;
        limpiarPantallaYMostrarTitulo(PADRE_ALTA_TITULO);

        posicion = ePadre_buscarLugarLibre(listadoPadres, limitePadres);
        if(posicion < -1)
        {
            imprimirEnPantalla(PADRE_MSJ_NO_MAS_LUGAR);
        }
        else if(posicion < 0)
        {
            retorno = posicion;
        }
        else
        {
            registro = ePadre_pedirIngreso(listadoPadres, limitePadres);

            imprimirEnPantalla(PADRE_MOSTRAR_UNO_CABECERA);
            ePadre_mostrarUno(&registro);

            confirmacion = pedirConfirmacion(MSJ_CONFIRMA_CORRECTOS);

            if(confirmacion == 'S')
            {
                *(listadoPadres+posicion) = registro;
                ePadre_ordenar(listadoPadres, limitePadres, PADRE_ORDEN_NOMBRE);
                imprimirEnPantalla(PADRE_MSJ_ALTA_OK);
            }
            else
            {
                imprimirEnPantalla(MSJ_CANCELO_GESTION);
            }
        }
        pausa();
    }
    return retorno;
}

int ePadre_modificarUno(ePadre* registro)
{
    int retorno = -1;
    eMenu menuModificar = {/*cantidad de opciones*/PADRE_MENU_MODIFICAR_UNO_CANT,
                            /*codigos*/{1,2,3,4,9,0},
                            /*descripciones*/{PADRE_MENU_MODIFICAR_UNO_DETALLE1,PADRE_MENU_MODIFICAR_UNO_DETALLE2,PADRE_MENU_MODIFICAR_UNO_DETALLE3,PADRE_MENU_MODIFICAR_UNO_DETALLE4,PADRE_MENU_MODIFICAR_UNO_DETALLE9,PADRE_MENU_MODIFICAR_UNO_DETALLE0},
                            /*titulo del menu*/{PADRE_MENU_MODIFICAR_UNO_TITULO}};
    int opcion;
    char finalizar = 'N';

    if(registro != NULL)
    {
        retorno = 1;
        do
        {
            limpiarPantallaYMostrarTitulo(MSJ_MODIFICANDO_REGISTRO);
            imprimirEnPantalla(MSJ_DATOS_A_MODIFICAR);

            imprimirEnPantalla(PADRE_MOSTRAR_UNO_CABECERA);
            ePadre_mostrarUno(registro);
            saltoDeLinea();

            opcion = pedirOpcion(&menuModificar);
            switch(opcion)
            {
                case 1:
                    ePadre_pedirNombre((char *)&registro->nombre);
                    break;
                case 2:
                    ePadre_pedirPais((char *)&registro->pais);
                    break;
                case 3:
                    registro->dni = ePadre_pedirDni();
                    break;
                case 4:
                    registro->reservas = ePadre_pedirReservas();
                    break;
                case 5:
                    break;
                case 6:
                    break;
                case 7:
                    break;
                case 8:
                    break;
                case 9:
                    finalizar = 'S';
                    break;
                case 0:
                    finalizar = 'S';
                    retorno = 0;
                    break;
            }
        }
        while(finalizar == 'N');
    }
    return retorno;
}

int ePadre_modificacion(ePadre* listadoPadres, int limitePadres)
{
    ePadre registro;
    char confirmacion;
    int posicion;
    int huboCambios;

    ejecutarEnConsola(LIMPIAR_PANTALLA);
    imprimirTitulo(PADRE_MODIFICACION_TITULO);

    if(ePadre_estaVacio(listadoPadres, limitePadres) == 1)
    {
        imprimirEnPantalla(PADRE_MSJ_LISTA_VACIA);
    }
    else
    {
        posicion = ePadre_pedirIdYBuscar(listadoPadres, limitePadres);
        //traigo el registro del id elegido para no pisar directo sobre el listadoPadres
        registro = listadoPadres[posicion];

        huboCambios = ePadre_modificarUno(&registro);
        if(huboCambios == 1)
        {
            /*if(aca se pregunta si hubo cambios que requieran reprocesar)
            {
                se recalcularian promedios por ej->
            }*/

            ejecutarEnConsola(LIMPIAR_PANTALLA);
            imprimirTitulo(PADRE_MODIFICACION_TITULO);

            imprimirEnPantalla(PADRE_MSJ_REGISTRO_ACTUAL);
            imprimirEnPantalla(PADRE_MOSTRAR_UNO_CABECERA);
            ePadre_mostrarUno(listadoPadres+posicion);

            imprimirEnPantalla(PADRE_MSJ_REGISTRO_MODIFICADO);
            imprimirEnPantalla(PADRE_MOSTRAR_UNO_CABECERA);
            ePadre_mostrarUno(&registro);

            saltoDeLinea();
            confirmacion = pedirConfirmacion(MSJ_CONFIRMA_CORRECTOS);
        }
        else
        {
            confirmacion = 'N';
        }

        if(confirmacion == 'S')
        {
            listadoPadres[posicion] = registro;
            ePadre_ordenar(listadoPadres, limitePadres, PADRE_ORDEN_ID);


            imprimirEnPantalla(PADRE_MSJ_MODIFICACION_OK);
        }
        else
        {
            imprimirEnPantalla(MSJ_CANCELO_GESTION);
        }
    }

    ejecutarEnConsola(HACER_PAUSA);
}

int ePadre_baja(ePadre* listadoPadres, int limitePadres)
{
    char confirmacion;
    int posicion;
    int idPadre;

    ejecutarEnConsola(LIMPIAR_PANTALLA);
    imprimirTitulo(PADRE_BAJA_TITULO);

    if(ePadre_estaVacio(listadoPadres, limitePadres) == 1)
    {
        imprimirEnPantalla(PADRE_MSJ_LISTA_VACIA);
    }
    else
    {
        ejecutarEnConsola(LIMPIAR_PANTALLA);
        imprimirTitulo(PADRE_BAJA_TITULO);

        posicion = ePadre_pedirIdYBuscar(listadoPadres, limitePadres);

        imprimirEnPantalla(PADRE_MOSTRAR_UNO_CABECERA);
        ePadre_mostrarUno(listadoPadres+posicion);

        confirmacion = pedirConfirmacion(PADRE_MSJ_CONFIRMAR_BAJA);

        if(confirmacion == 'S')
        {
            idPadre = (listadoPadres+posicion)->idPadre;
            (listadoPadres+posicion)->estado = LIBRE;
            imprimirEnPantalla(PADRE_MSJ_BAJA_OK);
        }
        else
        {
            imprimirEnPantalla(MSJ_CANCELO_GESTION);
        }
    }

    ejecutarEnConsola(HACER_PAUSA);
    return idPadre;
}



int ePadre_ordenar(ePadre* listadoPadres, int limitePadres, char* orden)
{
    int retorno = -1;
    int i;
    int j;
    ePadre aux;

    if(listadoPadres != NULL && limitePadres > 0)
    {
        retorno = 0;
        if(strcmp(orden, "idAsc") == 0)
        {
            for(i=0 ; i<limitePadres-1 ; i++)
            {
                for(j=i+1 ; j<limitePadres ; j++)
                {
                    if((listadoPadres+i)->idPadre > (listadoPadres+j)->idPadre)
                    {
                        aux = *(listadoPadres+i);
                        *(listadoPadres+i) = *(listadoPadres+j);
                        *(listadoPadres+j) = aux;
                    }
                }
            }
        }
        else if(strcmp(orden, "idDesc") == 0)
        {
            for(i=0 ; i<limitePadres-1 ; i++)
            {
                for(j=i+1 ; j<limitePadres ; j++)
                {
                    if((listadoPadres+i)->idPadre < (listadoPadres+j)->idPadre)
                    {
                        aux = *(listadoPadres+i);
                        *(listadoPadres+i) = *(listadoPadres+j);
                        *(listadoPadres+j) = aux;
                    }
                }
            }
        }
        else if(strcmp(orden, "nombreAsc") == 0)
        {
            for(i=0 ; i<limitePadres-1 ; i++)
            {
                for(j=i+1 ; j<limitePadres ; j++)
                {
                    if(strcmpi((listadoPadres+i)->nombre, (listadoPadres+j)->nombre) > 0)
                    {
                        aux = *(listadoPadres+i);
                        *(listadoPadres+i) = *(listadoPadres+j);
                        *(listadoPadres+j) = aux;
                    }
                }
            }
        }
        else if(strcmp(orden, "nombreDesc") == 0)
        {
            for(i=0 ; i<limitePadres-1 ; i++)
            {
                for(j=i+1 ; j<limitePadres ; j++)
                {
                    if(strcmpi((listadoPadres+i)->nombre, (listadoPadres+j)->nombre) < 0)
                    {
                        aux = *(listadoPadres+i);
                        *(listadoPadres+i) = *(listadoPadres+j);
                        *(listadoPadres+j) = aux;
                    }
                }
            }
        }
        else if(strcmp(orden, "kAsc") == 0)
        {
            for(i=0 ; i<limitePadres-1 ; i++)
            {
                for(j=i+1 ; j<limitePadres ; j++)
                {
                    if(strcmpi((listadoPadres+i)->reservas, (listadoPadres+j)->reservas) > 0)
                    {
                        aux = *(listadoPadres+i);
                        *(listadoPadres+i) = *(listadoPadres+j);
                        *(listadoPadres+j) = aux;
                    }
                }
            }
        }
        else if(strcmp(orden, "kDesc") == 0)
        {
            for(i=0 ; i<limitePadres-1 ; i++)
            {
                for(j=i+1 ; j<limitePadres ; j++)
                {
                    if(strcmpi((listadoPadres+i)->reservas, (listadoPadres+j)->reservas) < 0)
                    {
                        aux = *(listadoPadres+i);
                        *(listadoPadres+i) = *(listadoPadres+j);
                        *(listadoPadres+j) = aux;
                    }
                }
            }
        }
    }
    return retorno;
}
