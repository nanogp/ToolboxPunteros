#include <stdio.h>
#include <stdlib.h>
#include "General.h"
#include "Menu.h"

#define MENU_MAIN_TITULO DEFINIR_MACRO_STRING(MENU GENERICO)
#define MENU_MAIN_CANT 4
#define MENU_MAIN_DETALLE1 DEFINIR_MACRO_STRING(1. Gestionar Persona)
#define MENU_MAIN_DETALLE2 DEFINIR_MACRO_STRING(2. Gestionar Depende)
#define MENU_MAIN_DETALLE3 DEFINIR_MACRO_STRING(3. Gestionar Listados)
#define MENU_MAIN_DETALLE4 DEFINIR_MACRO_STRING(4. )
#define MENU_MAIN_DETALLE5 DEFINIR_MACRO_STRING(5. )
#define MENU_MAIN_DETALLE6 DEFINIR_MACRO_STRING(6. )
#define MENU_MAIN_DETALLE7 DEFINIR_MACRO_STRING(7. )
#define MENU_MAIN_DETALLE8 DEFINIR_MACRO_STRING(8. )
#define MENU_MAIN_DETALLE9 DEFINIR_MACRO_STRING(9. )
#define MENU_MAIN_DETALLE10 DEFINIR_MACRO_STRING(10. )
#define MENU_MAIN_DETALLE0 DEFINIR_MACRO_STRING(0. Salir del programa)

int main()
{
    eMenu menuPrincipal = {/*cantidad de opciones*/MENU_MAIN_CANT,
                            /*codigos*/{1,2,3,0},
                            /*descripciones*/{MENU_MAIN_DETALLE1,MENU_MAIN_DETALLE2,MENU_MAIN_DETALLE3,MENU_MAIN_DETALLE0},
                            /*titulo del menu*/{MENU_MAIN_TITULO}};
    int opcion;
    char salirDelPrograma = 'N';

    //ARRAYS DE ESTRUCTURAS
    //eGenerica listadoGenerica[GENERICA_CANT_MAX] = {};
    //eDepende listadoDepende[DEPENDE_CANT_MAX] = {};

    //INCIALIZAR
    //eGenerica_init(listadoGenerica, GENERICA_CANT_MAX);
    //eDepende_init(listadoDepende, DEPENDE_CANT_MAX);

    //CARGAR DATOS POR HARDCODE PARA DEBUG
    //eGenerica_initHardcode(listadoGenerica);
    //eDepende_initHardcode(listadoDepende);

    do
    {
        ejecutarEnConsola(LIMPIAR_PANTALLA);
        opcion = pedirOpcion(&menuPrincipal);
        switch(opcion)
        {
            case 1:
                //eGenerica_gestion(listadoGenerica, GENERICA_CANT_MAX);
                imprimirTitulo(menuPrincipal.descripciones[opcion-1]);pausa();
                break;
            case 2:
                //eDepende_gestion(listadoDepende, DEPENDE_CANT_MAX, listadoGenerica, GENERICA_CANT_MAX);
                imprimirTitulo(menuPrincipal.descripciones[opcion-1]);pausa();
                break;
            case 3:
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
