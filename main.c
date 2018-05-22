//AGREGAR AL PROYECTO ARCHIVOS DE CLASES
#include <stdio.h>
#include <stdlib.h>
#include "d:\github\ToolboxPunteros\General.h"
#include "d:\github\ToolboxPunteros\Menu.h"
#include "d:\github\ToolboxPunteros\Padre.h"

#define MENU_MAIN_TITULO "MENU GENERICO"
#define MENU_MAIN_CANT 12
#define MENU_MAIN_DETALLE1  "1. Alta Padre"
#define MENU_MAIN_DETALLE2  "2. Modificacion Padre"
#define MENU_MAIN_DETALLE3  "3. Baja Padre"
#define MENU_MAIN_DETALLE4  "4. Listado Padres"
#define MENU_MAIN_DETALLE5  "5. Alta Hijo"
#define MENU_MAIN_DETALLE6  "6. Modificacion Hijo"
#define MENU_MAIN_DETALLE7  "7. Baja Hijo"
#define MENU_MAIN_DETALLE8  "8. Listado Hijos"
#define MENU_MAIN_DETALLE9  "9. Listado Padre Y Sus Hijos"
#define MENU_MAIN_DETALLE10 "10. Listado Estadistica Padre"
#define MENU_MAIN_DETALLE11 "11. Baja Padre Y Sus Hijos"
#define MENU_MAIN_DETALLE0  "0. Salir Del Programa"

int main()
{
    eMenu menuPrincipal = {/*cantidad de opciones*/MENU_MAIN_CANT,
                            /*codigos*/{1,2,3,4,5,6,7,8,9,10,11,0},
                            /*descripciones*/{MENU_MAIN_DETALLE1,MENU_MAIN_DETALLE2,MENU_MAIN_DETALLE3,MENU_MAIN_DETALLE4,MENU_MAIN_DETALLE5,MENU_MAIN_DETALLE6,MENU_MAIN_DETALLE7,MENU_MAIN_DETALLE8,MENU_MAIN_DETALLE9,MENU_MAIN_DETALLE10,MENU_MAIN_DETALLE11,MENU_MAIN_DETALLE0},
                            /*titulo del menu*/{MENU_MAIN_TITULO}};
    int opcion;
    char salirDelPrograma = 'N';

    //ARRAYS DE ESTRUCTURAS
    ePadre listadoPadres[PADRE_CANT_MAX] = {};
    //eHijo listadoHijos[HIJO_CANT_MAX] = {};

    //INCIALIZAR
    //ePadre_init(listadoPadres, PADRE_CANT_MAX);
    //eHijo_init(listadoHijos, HIJO_CANT_MAX);

    //CARGAR DATOS POR HARDCODE PARA DEBUG
    ePadre_initHardcode(listadoPadres);
    //eHijo_initHardcode(listadoHijos);

    do
    {
        ejecutarEnConsola(LIMPIAR_PANTALLA);
        opcion = pedirOpcion(&menuPrincipal);
        switch(opcion)
        {
            case 1:
                ePadre_alta(listadoPadres, PADRE_CANT_MAX);
                break;
            case 2:
                ePadre_modificacion(listadoPadres, PADRE_CANT_MAX);
                break;
            case 3:
                ePadre_baja(listadoPadres, PADRE_CANT_MAX);
                break;
            case 4:
                ePadre_mostrarListado(listadoPadres, PADRE_CANT_MAX);pausa();
                break;
            case 5:
                //eHijo_alta(listadoHijos, HIJO_CANT_MAX);
                imprimirTitulo(menuPrincipal.descripciones[opcion-1]);pausa();
                break;
            case 6:
                //eHijo_modificacion(listadoHijos, HIJO_CANT_MAX);
                imprimirTitulo(menuPrincipal.descripciones[opcion-1]);pausa();
                break;
            case 7:
                //eHijo_baja(listadoHijos, HIJO_CANT_MAX);
                imprimirTitulo(menuPrincipal.descripciones[opcion-1]);pausa();
                break;
            case 8:
                imprimirTitulo(menuPrincipal.descripciones[opcion-1]);pausa();
                break;
            case 9:
                imprimirTitulo(menuPrincipal.descripciones[opcion-1]);pausa();
                break;
            case 10:
                imprimirTitulo(menuPrincipal.descripciones[opcion-1]);pausa();
                break;
            case 11:
                imprimirTitulo(menuPrincipal.descripciones[opcion-1]);pausa();
                break;
            case 0:
                salirDelPrograma = pedirConfirmacion("Confirma que desea salir del programa?");
                break;
        }

    }
    while(salirDelPrograma == 'N');
    return 0;
}
