#pragma once
#ifndef PROPIETARIO_H_INCLUDED
#define PROPIETARIO_H_INCLUDED

#include "General.h"
#include "Menu.h"

//limites
#define PROPIETARIO_CANT_MAX 10
#define PROPIETARIO_LARGO_NOMBRE 50
#define PROPIETARIO_LARGO_DIRECCION 100
#define PROPIETARIO_LARGO_TARJETA 20
#define PROPIETARIO_ID_MIN 1
#define PROPIETARIO_ID_MAX 1000000

//titulos
#define PROPIETARIO_ALTA_TITULO DEFINIR_MACRO_STRING(ALTA DE PROPIETARIO)
#define PROPIETARIO_MODIFICACION_TITULO DEFINIR_MACRO_STRING(MODIFICACION DE PROPIETARIO)
#define PROPIETARIO_BAJA_TITULO DEFINIR_MACRO_STRING(BAJA DE PROPIETARIO)
#define PROPIETARIO_LISTADO_TITULO DEFINIR_MACRO_STRING(LISTADO DE PROPIETARIOS)

//mensajes
#define PROPIETARIO_MSJ_INGRESE_ID DEFINIR_MACRO_STRING(\n\nIngrese el ID de Propietario: \0)
#define PROPIETARIO_MSJ_REINGRESE_ID DEFINIR_MACRO_STRING(\nEl ID debe ser un numero mayor que cero. Reingrese un ID valido: \0)
#define PROPIETARIO_MSJ_ID_NO_EXISTE DEFINIR_MACRO_STRING(\nEl ID de Propietario ingresado no existe)
#define PROPIETARIO_MSJ_LISTA_VACIA DEFINIR_MACRO_STRING(\n\nLa lista de Propietarios esta vacia o todos los registros se dieron de baja)
#define PROPIETARIO_MSJ_NO_MAS_LUGAR DEFINIR_MACRO_STRING(\nNo hay mas lugares disponibles para altas de Propietario)
#define PROPIETARIO_MSJ_INGRESE_NOMBRE DEFINIR_MACRO_STRING(\nIngrese Nombre y Apellido: \0)
#define PROPIETARIO_MSJ_REINGRESE_NOMBRE DEFINIR_MACRO_STRING(\nNombre muy largo. Reingrese por favor: \0)
#define PROPIETARIO_MSJ_INGRESE_DIRECCION DEFINIR_MACRO_STRING(\nIngrese direccion: \0)
#define PROPIETARIO_MSJ_REINGRESE_DIRECCION DEFINIR_MACRO_STRING(\nDireccion muy larga. Reingrese por favor: \0)
#define PROPIETARIO_MSJ_INGRESE_TARJETA DEFINIR_MACRO_STRING(\nIngrese numero de tarjeta: \0)
#define PROPIETARIO_MSJ_REINGRESE_TARJETA DEFINIR_MACRO_STRING(\nNumero de tarjeta no valido. Reingrese por favor: \0)
#define PROPIETARIO_MSJ_ALTA_OK DEFINIR_MACRO_STRING(\nEl Propietario se dio de alta)
#define PROPIETARIO_MSJ_CONFIRMAR_BAJA DEFINIR_MACRO_STRING(Confirma que desea dar de baja dicho Propietario?)
#define PROPIETARIO_MSJ_BAJA_OK DEFINIR_MACRO_STRING(\nEl Propietario se dio de baja)
#define PROPIETARIO_MSJ_REGISTRO_ACTUAL DEFINIR_MACRO_STRING(\n\nPropietario actual: \0)
#define PROPIETARIO_MSJ_REGISTRO_MODIFICADO DEFINIR_MACRO_STRING(\n\nPropietario modificado: \0)
#define PROPIETARIO_MSJ_MODIFICACION_OK DEFINIR_MACRO_STRING(\nEl Propietario se modifico)

//listados
#define PROPIETARIO_MOSTRAR_UNO_MASCARA DEFINIR_MACRO_STRING(\n%d - %-10s - %-10s - %-20s)
#define PROPIETARIO_MOSTRAR_UNO_CABECERA DEFINIR_MACRO_STRING(\nID - NOMBRE - DIRECCION - TARJETA)

//orden
#define PROPIETARIO_ORDEN_NOMBRE DEFINIR_MACRO_STRING(nombreAsc)
#define PROPIETARIO_ORDEN_ID DEFINIR_MACRO_STRING(idAsc)

//menus
#define PROPIETARIO_MENU_MODIFICAR_UNO_TITULO DEFINIR_MACRO_STRING(Que desea modificar?)
#define PROPIETARIO_MENU_MODIFICAR_UNO_CANT 2
#define PROPIETARIO_MENU_MODIFICAR_UNO_DETALLE1 DEFINIR_MACRO_STRING(1. Tarjeta de credito)
#define PROPIETARIO_MENU_MODIFICAR_UNO_DETALLE0 DEFINIR_MACRO_STRING(0. Cancelar)



typedef struct
{
    char nombre[PROPIETARIO_LARGO_NOMBRE];
    char direccion[PROPIETARIO_LARGO_DIRECCION];
    char tarjeta[PROPIETARIO_LARGO_TARJETA];
    //------------
    int idPropietario;
    int estado;
}ePropietario;

void ePropietario_initHardcode(ePropietario listadoPropietarios[]);
void ePropietario_init(ePropietario listadoPropietarios[], int limitePropietarios);
int ePropietario_buscarLugarLibre(ePropietario listadoPropietarios[], int limitePropietarios);
int ePropietario_siguienteId(ePropietario listadoPropietarios[], int limitePropietarios);
int ePropietario_buscarPorId(ePropietario listadoPropietarios[], int limitePropietarios, int idPropietario);
int ePropietario_pedirIdYBuscar(ePropietario listado[], int limitePropietarios);
int ePropietario_estaVacio(ePropietario listadoPropietarios[], int limitePropietarios);
int ePropietario_informarListadoVacio(ePropietario listadoPropietarios[], int limitePropietarios);

void ePropietario_pedirNombre(char retorno[]);
void ePropietario_pedirDireccion(char retorno[]);
void ePropietario_pedirTarjeta(char retorno[]);
ePropietario ePropietario_pedirIngreso(ePropietario listadoPropietarios[], int limitePropietarios);
void ePropietario_mostrarUno(ePropietario propietario);
void ePropietario_mostrarListado(ePropietario listadoPropietarios[], int limitePropietarios);
void ePropietario_alta(ePropietario listadoPropietarios[], int limitePropietarios);
void ePropietario_modificacion(ePropietario listadoPropietarios[], int limitePropietarios);
int ePropietario_baja(ePropietario listadoPropietarios[], int limitePropietarios);
void ePropietario_ordenar(ePropietario listado[], int limitePropietarios, char orden[]);

#endif // PROPIETARIO_H_INCLUDED
