#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "lib.h"

#define ABONADOS 10
#define LLAMADAS 10

int main()
{
    eAbonado arrayAbonados[ABONADOS];
    eLlamada arrayLlamadas[LLAMADAS];
    int opcion;

    inicializarArrayAbonados(arrayAbonados,ABONADOS);
    inicializarArrayLlamadas(arrayLlamadas,LLAMADAS);

    do
    {
        opcion = menu();
        switch(opcion)
        {
        case 1://ALTA ABONADO

            altaAbonado(arrayAbonados,ABONADOS);
            break;

        case 2://MODIFICAR ABONADO

            modificarAbonado(arrayAbonados,ABONADOS);
            break;

        case 3://BAJA DE ABONADO

            borrarAbonado(arrayAbonados,ABONADOS);
            break;

        case 4://NUEVA LLAMADA

            nuevaLlamada(arrayLlamadas,arrayAbonados,LLAMADAS,ABONADOS);
            break;

        case 5://FIN DE LLAMADA

            finalizarLlamada(arrayLlamadas,arrayAbonados,LLAMADAS,ABONADOS);
            break;

        case 6://INFORMAR
            informes(arrayAbonados,arrayLlamadas,ABONADOS,LLAMADAS);
            break;
        }

    }while(opcion != 7);
    return 0;
}
