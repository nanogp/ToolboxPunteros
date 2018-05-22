#pragma once
#ifndef PADRE_H_INCLUDED
#define PADRE_H_INCLUDED

#include "General.h"
#include "Menu.h"

//LIMITES
#define PADRE_CANT_MAX 10
#define PADRE_LARGO_NOMBRE 10
#define PADRE_LARGO_PAIS 10
#define PADRE_DNI_MIN 1
#define PADRE_DNI_MAX 100000000
#define PADRE_ID_MIN 1
#define PADRE_ID_MAX 1000000
#define PADRE_LARGO_RESERVAS 10

//CONSTANTES
#define PADRE_K_A 1
#define PADRE_K_B 2
#define PADRE_K_OTROS 3
#define PADRE_K_TXT_A "Oro"
#define PADRE_K_TXT_B "Petroleo"
#define PADRE_K_TXT_OTROS "Otros"

//TITULOS
#define PADRE_ALTA_TITULO "ALTA DE PADRE"
#define PADRE_BAJA_TITULO "BAJA DE PADRE"
#define PADRE_MODIFICACION_TITULO "MODIFICACION DE PADRE"
#define PADRE_LISTADO_TITULO "LISTADO DE PADRES"

//MENSAJES ERROR
#define PADRE_MSJ_ID_NO_EXISTE "\nEl ID de Padre ingresado no existe"
#define PADRE_MSJ_LISTA_VACIA "\n\nLa lista de Padres esta vacia o todos los registros se dieron de baja"
#define PADRE_MSJ_NO_MAS_LUGAR "\nNo hay mas lugares disponibles para altas de Padre"

//MENSAJES INFO
#define PADRE_MSJ_CONFIRMAR_BAJA "Confirma que desea dar de baja dicho Padre?"
#define PADRE_MSJ_ALTA_OK "\nEl Padre se dio de alta"
#define PADRE_MSJ_BAJA_OK "\nEl Padre se dio de baja"
#define PADRE_MSJ_MODIFICACION_OK "\nEl Padre se modifico"
#define PADRE_MSJ_REGISTRO_ACTUAL "\n\nPadre actual: \0"
#define PADRE_MSJ_REGISTRO_MODIFICADO "\n\nPadre modificado: \0"

//MENSAJES INPUT
#define PADRE_MSJ_INGRESE_ID "\n\nIngrese el ID de Padre: \0"
#define PADRE_MSJ_REINGRESE_ID "\nEl ID debe ser un numero mayor que cero. Reingrese un ID valido: \0"
#define PADRE_MSJ_INGRESE_NOMBRE "\nIngrese Nombre Padre: \0"
#define PADRE_MSJ_REINGRESE_NOMBRE "\nNombre muy largo. Reingrese por favor: \0"
#define PADRE_MSJ_INGRESE_PAIS "\nIngrese Pais: \0"
#define PADRE_MSJ_REINGRESE_PAIS "\nPais muy largo. Reingrese por favor: \0"
#define PADRE_MSJ_INGRESE_DNI "\nIngrese Dni: \0"
#define PADRE_MSJ_REINGRESE_DNI "\nDni no valido. Reingrese por favor: \0"

//LISTADOS
#define PADRE_MOSTRAR_UNO_MASCARA DEFINIR_MACRO_STRING(\n%d - %-10s - %-10s - %-10d - %-10s)
#define PADRE_MOSTRAR_UNO_CABECERA "\nID - NOMBRE - PAIS - DNI - RESERVAS"

//ORDEN
#define PADRE_ORDEN_NOMBRE "nombreAsc"
#define PADRE_ORDEN_ID "idAsc"

//MENUS
#define PADRE_MENU_MODIFICAR_UNO_TITULO "Que desea modificar?"
#define PADRE_MENU_MODIFICAR_UNO_CANT 6
#define PADRE_MENU_MODIFICAR_UNO_DETALLE1 "1. Nombre"
#define PADRE_MENU_MODIFICAR_UNO_DETALLE2 "2. Pais"
#define PADRE_MENU_MODIFICAR_UNO_DETALLE3 "3. Dni"
#define PADRE_MENU_MODIFICAR_UNO_DETALLE4 "4. Reservas"
#define PADRE_MENU_MODIFICAR_UNO_DETALLE5 "5. "
#define PADRE_MENU_MODIFICAR_UNO_DETALLE6 "6. "
#define PADRE_MENU_MODIFICAR_UNO_DETALLE7 "7. "
#define PADRE_MENU_MODIFICAR_UNO_DETALLE8 "8. "
#define PADRE_MENU_MODIFICAR_UNO_DETALLE9 "9. Finalizar modificacion"
#define PADRE_MENU_MODIFICAR_UNO_DETALLE0 "0. Cancelar"

#define PADRE_MENU_RESERVAS_TITULO "Que tipo de const?"
#define PADRE_MENU_RESERVAS_CANT 3
#define PADRE_MENU_RESERVAS_DETALLE1 "1. Oro"
#define PADRE_MENU_RESERVAS_DETALLE2 "2. Petroleo"
#define PADRE_MENU_RESERVAS_DETALLE3 "3. Otros"
#define PADRE_MENU_RESERVAS_DETALLE4 "4. "
#define PADRE_MENU_RESERVAS_DETALLE5 "5. "
#define PADRE_MENU_RESERVAS_DETALLE6 "6. "
#define PADRE_MENU_RESERVAS_DETALLE7 "7. "
#define PADRE_MENU_RESERVAS_DETALLE8 "8. "
#define PADRE_MENU_RESERVAS_DETALLE9 "9. "


typedef struct
{
    char nombre[PADRE_LARGO_NOMBRE];
    char pais[PADRE_LARGO_PAIS];
    int dni;
    int reservas;
    //-------------------------
    int idPadre;
    int estado;
}ePadre;

//init
void ePadre_initHardcode(ePadre* listadoPadres);
int ePadre_init(ePadre* listadoPadres, int limitePadres);

//busqueda
int ePadre_buscarLugarLibre(ePadre* listadoPadres, int limitePadres);
int ePadre_siguienteId(ePadre* listadoPadres, int limitePadres);
int ePadre_estaVacio(ePadre* listadoPadres, int limitePadres);
int ePadre_informarListadoVacio(ePadre* listadoPadres, int limitePadres);
int ePadre_buscarPorId(ePadre* listadoPadres, int limitePadres, int idPadre);
int ePadre_pedirIdYBuscar(ePadre* listadoPadres, int limitePadres);

//input
int ePadre_pedirId();
int ePadre_pedirDni();
int ePadre_pedirDni();
void ePadre_pedirNombre(char* retorno);
void ePadre_pedirPais(char* retorno);
int ePadre_pedirReservas();
char* ePadre_convertirCodEnTexto(int codigo);
ePadre ePadre_pedirIngreso(ePadre* listadoPadres, int limitePadres);

//listado
int ePadre_mostrarUno(ePadre* propietario);
int ePadre_mostrarListado(ePadre* listadoPadres, int limitePadres);

//gestion
int ePadre_alta(ePadre* listadoPadres, int limitePadres);
int ePadre_modificacion(ePadre* listadoPadres, int limitePadres);
int ePadre_baja(ePadre* listadoPadres, int limitePadres);
int ePadre_ordenar(ePadre* listado, int limitePadres, char* orden);

#endif // PADRE_H_INCLUDED
