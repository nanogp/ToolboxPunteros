#ifndef ESTRUCTURAPROPIETARIO_H_INCLUDED
#define ESTRUCTURAPROPIETARIO_H_INCLUDED
#define OCUPADO 1
#define LIBRE 0

#define MSJ_CONFIRMA_CORRECTOS DEFINIR_MACRO_STRING(Confirma que los datos ingresados son correctos?)
#define MSJ_CANCELO_GESTION DEFINIR_MACRO_STRING(\nSe cancelo la gestion)
#define MSJ_MODIFICANDO_REGISTRO DEFINIR_MACRO_STRING(MODIFICANDO REGISTRO)
#define MSJ_DATOS_A_MODIFICAR DEFINIR_MACRO_STRING(\n\nDatos a modificar:\n)

#define PROPIETARIO_CANT_MAX 10
#define PROPIETARIO_LARGO_NOMBRE 50
#define PROPIETARIO_NUMERO_MIN 1
#define PROPIETARIO_NUMERO_MAX 1000
#define PROPIETARIO_ID_MIN 1
#define PROPIETARIO_ID_MAX 1000000
#define PROPIETARIO_ORDEN DEFINIR_MACRO_STRING(nombreAsc)
#define PROPIETARIO_TITULO_GESTION DEFINIR_MACRO_STRING(GESTION DE PROPIETARIO)
#define PROPIETARIO_TITULO_ALTA DEFINIR_MACRO_STRING(ALTA DE PROPIETARIO)
#define PROPIETARIO_TITULO_BAJA DEFINIR_MACRO_STRING(BAJA DE PROPIETARIO)
#define PROPIETARIO_TITULO_MODIFICACION DEFINIR_MACRO_STRING(MODIFICACION DE PROPIETARIO)
#define PROPIETARIO_TITULO_LISTA DEFINIR_MACRO_STRING(LISTADO DE PROPIETARIO)
#define PROPIETARIO_MASCARA_MOSTRAR_UNO DEFINIR_MACRO_STRING(\n %-3d - %-25s - %-5d)
#define PROPIETARIO_CABECERA_LISTADO DEFINIR_MACRO_STRING(\n ID  - nombre                    - numero)
#define PROPIETARIO_MSJ_LISTA_VACIA DEFINIR_MACRO_STRING(\n\nLa lista esta vacia o todos los registros se dieron de baja)
#define PROPIETARIO_MSJ_NO_MAS_LUGAR DEFINIR_MACRO_STRING(\nNo hay mas lugares disponibles para altas de Propietario)
#define PROPIETARIO_MSJ_INGRESE_ID DEFINIR_MACRO_STRING(\n\nIngrese el ID de Propietario: \0)
#define PROPIETARIO_MSJ_REINGRESE_ID DEFINIR_MACRO_STRING(\nEl ID debe ser un numero mayor que cero. Reingrese un ID valido: \0)
#define PROPIETARIO_MSJ_ID_NO_EXISTE DEFINIR_MACRO_STRING(\nEl ID de Propietario ingresado no existe)
#define PROPIETARIO_MSJ_NOMBRE_NO_EXISTE DEFINIR_MACRO_STRING(\nEl nombre ingresado no existe)
#define PROPIETARIO_MSJ_INGRESE_NOMBRE DEFINIR_MACRO_STRING(\nIngrese nombre: \0)
#define PROPIETARIO_MSJ_REINGRESE_NOMBRE DEFINIR_MACRO_STRING(\nNombre muy largo. Reingrese por favor: \0)
#define PROPIETARIO_MSJ_INGRESE_NUMERO DEFINIR_MACRO_STRING(\nIngrese numero: \0)
#define PROPIETARIO_MSJ_REINGRESE_NUMERO DEFINIR_MACRO_STRING(\nNumero no valido. Reingrese por favor: \0)
#define PROPIETARIO_MSJ_REINTENTAR_GESTION DEFINIR_MACRO_STRING(Desea reintentar la gestion?)
#define PROPIETARIO_MSJ_ALTA_OK DEFINIR_MACRO_STRING(\nEl Propietario se dio de alta)
#define PROPIETARIO_MSJ_CONFIRMAR_BAJA DEFINIR_MACRO_STRING(Confirma que desea dar de baja dicho Propietario?)
#define PROPIETARIO_MSJ_BAJA_OK DEFINIR_MACRO_STRING(\nEl Propietario se dio de baja)
#define PROPIETARIO_MSJ_REGISTRO_ACTUAL DEFINIR_MACRO_STRING(\n\nPropietario actual: \0)
#define PROPIETARIO_MSJ_REGISTRO_MODIFICADO DEFINIR_MACRO_STRING(\n\nPropietario modificado: \0)
#define PROPIETARIO_MSJ_MODIFICACION_OK DEFINIR_MACRO_STRING(\nEl Propietario se modifico)
#define PROPIETARIO_MENU_MODIFICAR_UNO_TITULO DEFINIR_MACRO_STRING(Que desea modificar?)
#define PROPIETARIO_MENU_MODIFICAR_UNO_CANT 5
#define PROPIETARIO_MENU_MODIFICAR_UNO_DETALLE1 DEFINIR_MACRO_STRING(1. Nombre)
#define PROPIETARIO_MENU_MODIFICAR_UNO_DETALLE2 DEFINIR_MACRO_STRING(2. Numero)
#define PROPIETARIO_MENU_MODIFICAR_UNO_DETALLE3 DEFINIR_MACRO_STRING(3. Edad)
#define PROPIETARIO_MENU_MODIFICAR_UNO_DETALLE4 DEFINIR_MACRO_STRING(4. Nota)
#define PROPIETARIO_MENU_MODIFICAR_UNO_DETALLE5 DEFINIR_MACRO_STRING(0. Cancelar)
#define PROPIETARIO_MENU_GESTION_TITULO DEFINIR_MACRO_STRING(GESTION DE PROPIETARIO)
#define PROPIETARIO_MENU_GESTION_CANT 5
#define PROPIETARIO_MENU_GESTION_DETALLE1 DEFINIR_MACRO_STRING(1. Alta)
#define PROPIETARIO_MENU_GESTION_DETALLE2 DEFINIR_MACRO_STRING(2. Baja)
#define PROPIETARIO_MENU_GESTION_DETALLE3 DEFINIR_MACRO_STRING(3. Modificacion)
#define PROPIETARIO_MENU_GESTION_DETALLE4 DEFINIR_MACRO_STRING(4. Listar)
#define PROPIETARIO_MENU_GESTION_DETALLE5 DEFINIR_MACRO_STRING(0. Volver al menu principal)

typedef struct
{
    char nombre[PROPIETARIO_LARGO_NOMBRE];
    int numero;
    //------------
    int idPropietario;
    int estado;
}ePropietario;

void ePropietario_initHardcode(ePropietario listado[]);

/** \brief
 *
 * \param listado[] ePropietario
 * \param limite int
 * \return void
 *
 */
void ePropietario_init(ePropietario listado[], int limite);

/** \brief
 *
 * \param listado[] ePropietario
 * \param limite int
 * \return int
 *
 */
int ePropietario_siguienteId(ePropietario listado[], int limite);

/** \brief
 *
 * \param listado[] ePropietario
 * \param limite int
 * \param id int
 * \return int
 *
 */
int ePropietario_buscarPorId(ePropietario listado[], int limite, int id);

/** \brief
 *
 * \param listado[] ePropietario
 * \param limite int
 * \return int
 *
 */
int ePropietario_pedirIdYBuscar(ePropietario listado[], int limite);

/** \brief
 *
 * \param listado[] ePropietario
 * \param limite int
 * \param nombre[] char
 * \return int
 *
 */
int ePropietario_buscarPorNombre(ePropietario listado[], int limite, char nombre[]);

/** \brief
 *
 * \param listado[] ePropietario
 * \param limite int
 * \return int
 *
 */
int ePropietario_pedirNombreYBuscar(ePropietario listado[], int limite);

/** \brief
 *
 * \param listado[] ePropietario
 * \param limite int
 * \return int
 *
 */
int ePropietario_buscarLugarLibre(ePropietario listado[], int limite);

/** \brief
 *
 * \param listado[] ePropietario
 * \param limite int
 * \return int
 *
 */
int ePropietario_estaVacio(ePropietario listado[], int limite);

/** \brief
 *
 * \param registro ePropietario
 * \return void
 *
 */
void ePropietario_mostrarUno(ePropietario registro);

/** \brief
 *
 * \param listado[] ePropietario
 * \param limite int
 * \return void
 *
 */
void ePropietario_mostrarListado(ePropietario listado[], int limite);

/** \brief
 *
 * \param listado[] ePropietario
 * \param limite int
 * \return void
 *
 */
void ePropietario_listar(ePropietario listado[], int limite);

/** \brief
 *
 * \param retorno[] char
 * \return void
 *
 */
void ePropietario_pedirNombre(char retorno[]);

/** \brief
 *
 * \param retorno[] char
 * \return void
 *
 */
int ePropietario_pedirNumero();

/** \brief
 *
 * \param listado[] ePropietario
 * \param limite int
 * \return ePropietario
 *
 */
ePropietario ePropietario_pedirIngreso(ePropietario listado[], int limite);

/** \brief
 *
 * \param listado[] ePropietario
 * \param limite int
 * \return void
 *
 */
void ePropietario_alta(ePropietario listado[], int limite);

/** \brief
 *
 * \param listado[] ePropietario
 * \param limite int
 * \return void
 *
 */
void ePropietario_baja(ePropietario listado[], int limite);

/** \brief
 *
 * \param registro[] ePropietario
 * \return int
 *
 */
int ePropietario_modificarUno(ePropietario registro[]);

/** \brief
 *
 * \param listado[] ePropietario
 * \param limite int
 * \return void
 *
 */
void ePropietario_modificacion(ePropietario listado[], int limite);

/** \brief
 *
 * \param listado[] ePropietario
 * \param limite int
 * \param orden[] char
 * \return void
 *
 */
void ePropietario_ordenar(ePropietario listado[], int limite, char orden[]);

/** \brief
 *
 * \param listado[] ePropietario
 * \param limite int
 * \return void
 *
 */
void ePropietario_gestion(ePropietario listado[], int limite);

#endif // ESTRUCTURAPROPIETARIO_H_INCLUDED
