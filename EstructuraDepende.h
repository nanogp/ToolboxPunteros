#ifndef DEPENDE_H_INCLUDED
#define DEPENDE_H_INCLUDED

#include "EstructuraGenerica.h"

#define OCUPADO 1
#define LIBRE 0

#define MSJ_CONFIRMA_CORRECTOS DEFINIR_MACRO_STRING(Confirma que los datos ingresados son correctos?)
#define MSJ_CANCELO_GESTION DEFINIR_MACRO_STRING(\nSe cancelo la gestion)

#define DEPENDE_CANT_MAX 10
#define DEPENDE_LARGO_NOMBRE 50
#define DEPENDE_NUMERO_MIN 1
#define DEPENDE_NUMERO_MAX 1000
#define DEPENDE_ID_MIN 1
#define DEPENDE_ID_MAX 1000000
#define DEPENDE_ORDEN DEFINIR_MACRO_STRING(nombreAsc)
#define DEPENDE_TITULO_GESTION DEFINIR_MACRO_STRING(GESTION DE DEPENDE)
#define DEPENDE_TITULO_ALTA DEFINIR_MACRO_STRING(ALTA DE DEPENDE)
#define DEPENDE_TITULO_BAJA DEFINIR_MACRO_STRING(BAJA DE DEPENDE)
#define DEPENDE_TITULO_MODIFICACION DEFINIR_MACRO_STRING(MODIFICACION DE DEPENDE)
#define DEPENDE_TITULO_LISTA DEFINIR_MACRO_STRING(LISTADO DE DEPENDE)
#define DEPENDE_TITULO_LISTA_POR_ID_GENERICA DEFINIR_MACRO_STRING(LISTADO DE DEPENDE POR CADA GENERICA)
#define DEPENDE_MASCARA_MOSTRAR_UNO DEFINIR_MACRO_STRING(\n %-3d - %-2d - %-25s - %-5d)
#define DEPENDE_CABECERA_LISTADO DEFINIR_MACRO_STRING(\n ID  - FK - nombre                    - numero)
#define DEPENDE_MSJ_LISTA_VACIA DEFINIR_MACRO_STRING(\n\nLa lista esta vacia o todos los registros se dieron de baja)
#define DEPENDE_MSJ_NO_MAS_LUGAR DEFINIR_MACRO_STRING(\nNo hay mas lugares disponibles para altas de Depende)
#define DEPENDE_MSJ_INGRESE_ID DEFINIR_MACRO_STRING(\n\nIngrese el ID de Depende: \0)
#define DEPENDE_MSJ_REINGRESE_ID DEFINIR_MACRO_STRING(\nEl ID debe ser un numero mayor que cero. Reingrese un ID valido: \0)
#define DEPENDE_MSJ_ID_NO_EXISTE DEFINIR_MACRO_STRING(\nEl ID de Depende ingresado no existe)
#define DEPENDE_MSJ_NOMBRE_NO_EXISTE DEFINIR_MACRO_STRING(\nEl nombre ingresado no existe)
#define DEPENDE_MSJ_INGRESE_NOMBRE DEFINIR_MACRO_STRING(\nIngrese nombre: \0)
#define DEPENDE_MSJ_REINGRESE_NOMBRE DEFINIR_MACRO_STRING(\nNombre muy largo. Reingrese por favor: \0)
#define DEPENDE_MSJ_INGRESE_NUMERO DEFINIR_MACRO_STRING(\nIngrese numero: \0)
#define DEPENDE_MSJ_REINGRESE_NUMERO DEFINIR_MACRO_STRING(\nNumero no valido. Reingrese por favor: \0)
#define DEPENDE_MSJ_REINTENTAR_GESTION DEFINIR_MACRO_STRING(Desea reintentar la gestion?)
#define DEPENDE_MSJ_ALTA_OK DEFINIR_MACRO_STRING(\nEl Depende se dio de alta)
#define DEPENDE_MSJ_CONFIRMAR_BAJA DEFINIR_MACRO_STRING(Confirma que desea dar de baja dicho Depende?)
#define DEPENDE_MSJ_BAJA_OK DEFINIR_MACRO_STRING(\nEl Depende se dio de baja)
#define DEPENDE_MSJ_REGISTRO_ACTUAL DEFINIR_MACRO_STRING(\nDepende actual: \0)
#define DEPENDE_MSJ_REGISTRO_MODIFICADO DEFINIR_MACRO_STRING(\nDepende modificado: \0)
#define DEPENDE_MSJ_MODIFICACION_OK DEFINIR_MACRO_STRING(\nEl Depende se modifico)
#define DEPENDE_MENU_MODIFICAR_UNO_TITULO DEFINIR_MACRO_STRING(Que desea modificar?)
#define DEPENDE_MENU_MODIFICAR_UNO_CANT 5
#define DEPENDE_MENU_MODIFICAR_UNO_DETALLE1 DEFINIR_MACRO_STRING(1. Nombre)
#define DEPENDE_MENU_MODIFICAR_UNO_DETALLE2 DEFINIR_MACRO_STRING(2. Numero)
#define DEPENDE_MENU_MODIFICAR_UNO_DETALLE3 DEFINIR_MACRO_STRING(3. Edad)
#define DEPENDE_MENU_MODIFICAR_UNO_DETALLE4 DEFINIR_MACRO_STRING(4. Nota)
#define DEPENDE_MENU_MODIFICAR_UNO_DETALLE5 DEFINIR_MACRO_STRING(0. Cancelar)
#define DEPENDE_MENU_GESTION_TITULO DEFINIR_MACRO_STRING(GESTION DE DEPENDE)
#define DEPENDE_MENU_GESTION_CANT 5
#define DEPENDE_MENU_GESTION_DETALLE1 DEFINIR_MACRO_STRING(1. Alta)
#define DEPENDE_MENU_GESTION_DETALLE2 DEFINIR_MACRO_STRING(2. Baja)
#define DEPENDE_MENU_GESTION_DETALLE3 DEFINIR_MACRO_STRING(3. Modificacion)
#define DEPENDE_MENU_GESTION_DETALLE4 DEFINIR_MACRO_STRING(4. Listar)
#define DEPENDE_MENU_GESTION_DETALLE5 DEFINIR_MACRO_STRING(0. Volver al menu principal)

typedef struct
{
    char nombre[DEPENDE_LARGO_NOMBRE];
    int numero;
    //------------
	int idDepende;
    int idGenerica;
    int estado;
}eDepende;

void eDepende_initHardcode(eDepende listado[]);

/** \brief
 *
 * \param listado[] eDepende
 * \param limite int
 * \return void
 *
 */
void eDepende_init(eDepende listado[], int limite);

/** \brief
 *
 * \param listado[] eDepende
 * \param limite int
 * \return int
 *
 */
int eDepende_siguienteId(eDepende listado[], int limite);

/** \brief
 *
 * \param listado[] eDepende
 * \param limite int
 * \param id int
 * \return int
 *
 */
int eDepende_buscarPorId(eDepende listado[], int limite, int id);

/** \brief
 *
 * \param listado[] eDepende
 * \param limite int
 * \return int
 *
 */
int eDepende_pedirIdYBuscar(eDepende listado[], int limite);

/** \brief
 *
 * \param listado[] eDepende
 * \param limite int
 * \param nombre[] char
 * \return int
 *
 */
int eDepende_buscarPorNombre(eDepende listado[], int limite, char nombre[]);

/** \brief
 *
 * \param listado[] eDepende
 * \param limite int
 * \return int
 *
 */
int eDepende_pedirNombreYBuscar(eDepende listado[], int limite);

/** \brief
 *
 * \param listado[] eDepende
 * \param limite int
 * \return int
 *
 */
int eDepende_buscarLugarLibre(eDepende listado[], int limite);

/** \brief
 *
 * \param listado[] eDepende
 * \param limite int
 * \return int
 *
 */
int eDepende_estaVacio(eDepende listado[], int limite);

/** \brief
 *
 * \param registro eDepende
 * \return void
 *
 */
void eDepende_mostrarUno(eDepende registro);

/** \brief
 *
 * \param listado[] eDepende
 * \param limite int
 * \return void
 *
 */
void eDepende_mostrarListado(eDepende listado[], int limite);

/** \brief
 *
 * \param listado[] eDepende
 * \param limite int
 * \return void
 *
 */
void eDepende_listar(eDepende listado[], int limite);

/** \brief
 *
 * \param listado[] eDepende
 * \param limite int
 * \param idGenerica int
 * \return void
 *
 */
void eDepende_mostrarListadoPorIdGenerica(eDepende listado[], int limite, int idGenerica);

/** \brief
 *
 * \param listadoDepende[] eDepende
 * \param limiteDepende int
 * \param listadoGenerica[] eGenerica
 * \param limiteGenerica int
 * \return void
 *
 */
void eDepende_pedirIdGenericaYListar(eDepende listadoDepende[], int limiteDepende, eGenerica listadoGenerica[], int limiteGenerica);

/** \brief
 *
 * \param retorno[] char
 * \return void
 *
 */
void eDepende_pedirNombre(char retorno[]);

/** \brief
 *
 * \param retorno[] char
 * \return void
 *
 */
int eDepende_pedirNumero();

/** \brief
 *
 * \param listado[] eDepende
 * \param limite int
 * \return eDepende
 *
 */
eDepende eDepende_pedirIngreso(eDepende listado[], int limite);

/** \brief
 *
 * \param listadoDepende[] eDepende
 * \param limiteDepende int
 * \param listadoGenerica[] eGenerica
 * \param limiteGenerica int
 * \return void
 *
 */
void eDepende_alta(eDepende listadoDepende[], int limiteDepende, eGenerica listadoGenerica[], int limiteGenerica);

/** \brief
 *
 * \param listadoDepende[] eDepende
 * \param limiteDepende int
 * \param listadoGenerica[] eGenerica
 * \param limiteGenerica int
 * \return void
 *
 */
void eDepende_baja(eDepende listadoDepende[], int limiteDepende, eGenerica listadoGenerica[], int limiteGenerica);

/** \brief
 *
 * \param registro[] eDepende
 * \return int
 *
 */
int eDepende_modificarUno(eDepende registro[]);

/** \brief
 *
 * \param listado[] eDepende
 * \param limite int
 * \return void
 *
 */
void eDepende_modificacion(eDepende listado[], int limite);

/** \brief
 *
 * \param listado[] eDepende
 * \param limite int
 * \param orden[] char
 * \return void
 *
 */
void eDepende_ordenar(eDepende listado[], int limite, char orden[]);

/** \brief
 *
 * \param listado[] eDepende
 * \param limite int
 * \return void
 *
 */
void eDepende_gestion(eDepende listadoDepende[], int limiteDepende, eGenerica listadoGenerica[], int limiteGenerica);


#endif // DEPENDE_H_INCLUDED
