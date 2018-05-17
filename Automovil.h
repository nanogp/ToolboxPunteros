#pragma once
#ifndef AUTOMOVIL_H_INCLUDED
#define AUTOMOVIL_H_INCLUDED

#include "General.h"
#include "Propietario.h"

//constantes
#define ALPHA_ROMEO 1
#define FERRARI 2
#define AUDI 3
#define OTROS 4

//limites
#define AUTOMOVIL_CANT_MAX 20
#define AUTOMOVIL_LARGO_PATENTE 20
#define AUTOMOVIL_LARGO_MARCA 20
#define AUTOMOVIL_ID_MIN 1
#define AUTOMOVIL_ID_MAX 1000000

//titulos
#define AUTOMOVIL_ALTA_TITULO DEFINIR_MACRO_STRING(INGRESO DE AUTOMOVIL)
#define AUTOMOVIL_MODIFICACION_TITULO DEFINIR_MACRO_STRING(MODIFICACION DE AUTOMOVIL)
#define AUTOMOVIL_BAJA_TITULO DEFINIR_MACRO_STRING(EGRESO DE AUTOMOVIL)
#define AUTOMOVIL_LISTADO_TITULO DEFINIR_MACRO_STRING(LISTADO DE AUTOMOVILES)

//mensajes
#define MSJ_ALPHA_ROMEO DEFINIR_MACRO_STRING(Alfa Romeo)
#define MSJ_FERRARI DEFINIR_MACRO_STRING(Ferrari)
#define MSJ_AUDI DEFINIR_MACRO_STRING(Audi)
#define MSJ_OTROS DEFINIR_MACRO_STRING(Otros)
#define MSJ_CONFIRMA_CORRECTOS DEFINIR_MACRO_STRING(Confirma que los datos ingresados son correctos?)
#define MSJ_CANCELO_GESTION DEFINIR_MACRO_STRING(\nSe cancelo la gestion)
#define AUTOMOVIL_MSJ_LISTA_VACIA DEFINIR_MACRO_STRING(\n\nLa lista de Automoviles esta vacia o todos los registros se dieron de baja)
#define AUTOMOVIL_MSJ_NO_EXISTEN_ID_PROPIETARIO DEFINIR_MACRO_STRING(\n\nNo existen Automoviles para el ID de Automovil ingresado)
#define AUTOMOVIL_MSJ_INGRESE_ID DEFINIR_MACRO_STRING(\n\nIngrese el ID de Automovil: \0)
#define AUTOMOVIL_MSJ_REINGRESE_ID DEFINIR_MACRO_STRING(\nEl ID debe ser un numero mayor que cero. Reingrese un ID valido: \0)
#define AUTOMOVIL_MSJ_ID_NO_EXISTE DEFINIR_MACRO_STRING(\nEl ID de Automovil ingresado no existe)
#define AUTOMOVIL_MSJ_LISTA_VACIA DEFINIR_MACRO_STRING(\n\nLa lista de Automoviles esta vacia o todos los registros se dieron de baja)
#define AUTOMOVIL_MSJ_NO_MAS_LUGAR DEFINIR_MACRO_STRING(\nNo hay mas lugares disponibles para altas de Automovil)
#define AUTOMOVIL_MSJ_INGRESE_PATENTE DEFINIR_MACRO_STRING(\nIngrese numero de patente: \0)
#define AUTOMOVIL_MSJ_REINGRESE_PATENTE DEFINIR_MACRO_STRING(\nNumero de patente muy largo. Reingrese por favor: \0)
#define AUTOMOVIL_MSJ_INGRESE_TARJETA DEFINIR_MACRO_STRING(\nIngrese numero de tarjeta: \0)
#define AUTOMOVIL_MSJ_REINGRESE_TARJETA DEFINIR_MACRO_STRING(\nNumero de tarjeta no valido. Reingrese por favor: \0)
#define AUTOMOVIL_MSJ_ALTA_OK DEFINIR_MACRO_STRING(\nEl Automovil se dio de alta)
#define AUTOMOVIL_MSJ_CONFIRMAR_BAJA DEFINIR_MACRO_STRING(Confirma que desea dar de baja dicho Automovil?)
#define AUTOMOVIL_MSJ_BAJA_OK DEFINIR_MACRO_STRING(\nEl Automovil se dio de baja)

//listados
#define AUTOMOVIL_MOSTRAR_UNO_MASCARA DEFINIR_MACRO_STRING(\n%-3d - %-10s - %-20s)
#define AUTOMOVIL_MOSTRAR_UNO_CABECERA DEFINIR_MACRO_STRING(\nID - MARCA - PATENTE)

//orden
#define AUTOMOVIL_ORDEN_PATENTE DEFINIR_MACRO_STRING(patenteAsc)

//menus
#define AUTOMOVIL_MENU_MARCA_TITULO DEFINIR_MACRO_STRING(Que marca es?)
#define AUTOMOVIL_MENU_MARCA_CANT 4
#define MSJ_MENU_ALPHA_ROMEO DEFINIR_MACRO_STRING(1. Alfa Romeo)
#define MSJ_MENU_FERRARI DEFINIR_MACRO_STRING(2. Ferrari)
#define MSJ_MENU_AUDI DEFINIR_MACRO_STRING(3. Audi)
#define MSJ_MENU_OTROS DEFINIR_MACRO_STRING(4. Otros)

typedef struct
{
    int marca;
    char patente[AUTOMOVIL_LARGO_PATENTE];
    //------------
	int idAutomovil;
    int idPropietario;
    int estado;
}eAutomovil;

void eAutomovil_initHardcode(eAutomovil listadoAutomoviles[]);
void eAutomovil_init(eAutomovil listadoAutomoviles[], int limiteAutomoviles);
int eAutomovil_buscarLugarLibre(eAutomovil listadoAutomoviles[], int limiteAutomoviles);
int eAutomovil_siguienteId(eAutomovil listadoAutomoviles[], int limiteAutomoviles);
int eAutomovil_buscarPorId(eAutomovil listadoAutomoviles[], int limiteAutomoviles, int idAutomovil);
int eAutomovil_pedirIdYBuscar(eAutomovil listado[], int limiteAutomoviles);
int eAutomovil_estaVacio(eAutomovil listadoAutomoviles[], int limiteAutomoviles);
int eAutomovil_informarListadoVacio(eAutomovil listadoAutomoviles[], int limiteAutomoviles);
void eAutomovil_convertirCodMarcaEnTexto(int codMarca, char textoMarca[]);
int eAutomovil_informarExisteIdAutomovil(eAutomovil listadoAutomoviles[], int limiteAutomoviles, int idAutomovil);
void eAutomovil_ordenar(eAutomovil listado[], int limiteAutomoviles, char orden[]);

int eAutomovil_pedirMarca();
void eAutomovil_pedirPatente(char retorno[]);
eAutomovil eAutomovil_pedirIngreso(eAutomovil listadoAutomoviles[], int limiteAutomoviles, ePropietario listadoPropietarios[], int limitePropietarios);
void eAutomovil_mostrarUno(eAutomovil automovil);
void eAutomovil_mostrarListado(eAutomovil listadoAutomoviles[], int limiteAutomoviles);
void eAutomovil_alta(eAutomovil listadoAutomoviles[], int limiteAutomoviles, ePropietario listadoPropietarios[], int limitePropietarios);
void eAutomovil_baja(eAutomovil listadoAutomoviles[], int limiteAutomoviles, ePropietario listadoPropietarios[], int limitePropietarios);
int devolverHorasEstadia();
void emitirTicket(eAutomovil automovil, ePropietario propietario);

#endif //AUTOMOVIL_H_INCLUDED
