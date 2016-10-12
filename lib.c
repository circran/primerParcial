#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "lib.h"

/** \brief Muestra un menu, solicita opcion y la valida. Retorna la opcion.
 *
 * \param -
 * \param -
 * \return retorna la opcion elegida por el usuario ya validada.
 *
 */
int menu(void)
{
    char auxOpcion[256];
    int opcion;

    system("cls");
    printf("    MENU PRINCIPAL\n\n");
    printf("1- ALTA ABONADO\n");
    printf("2- MODIFICAR ABONADO\n");
    printf("3- BAJA DE ABONADO\n");
    printf("4- NUEVA LLAMADA\n");
    printf("5- FIN DE LLAMADA\n");
    printf("6- INFORMES\n");
    printf("7- Salir\n");

    fflush(stdin);
    scanf("%s",auxOpcion);
    while(validarNumero(auxOpcion,1,7))
    {
        printf("\nError.. Reingrese: ");
        fflush(stdin);
        scanf("%s",auxOpcion);
    }

    opcion = atoi(auxOpcion);


    return opcion;
}

/** \brief valida que el numero que recibe este entre los limites.
 *
 * \param recibe el numero a validar.
 * \param recibe el limite inferior
 * \param recibe el limite superior
 * \return retorna 0 si el numero no esta dentro de los limites o 1 si lo esta.
 */
int validarNumero(char* auxStr,int limInf, int limSup)
{
    int auxNumero, i, validacion = 0;

    for(i=0;auxStr[i] != '\0';i++)
    {
        if(auxStr[i] < '0' || auxStr[i] > '9')
        {
            validacion = 1;
            break;
        }
    }

    auxNumero = atoi(auxStr);

    if(auxNumero < limInf || auxNumero > limSup)
    {
        validacion = 1;
    }

    return validacion;
}


/** \brief carga el valor 0 en el id de cada indice.
 *
 * \param abonado recibe el array
 * \param recibe el tamanio del array.
 * \return -
 *
 */
void inicializarArrayAbonados(eAbonado* abonados,int lengthAbonado)
{
    int i;
    for(i=0;i<lengthAbonado;i++)
    {
        abonados[i].idAbonado = 0;
        abonados[i].contLlamas = 0;
    }
}

/** \brief carga el valor 0 en el id de cada indice.
 *
 * \param abonado recibe el array.
 * \param recibe el tamanio del array.
 * \return -
 *
 */
void inicializarArrayLlamadas(eLlamada* llamadas,int lengthLlamadas)
{
    int i;
    for(i=0;i<lengthLlamadas;i++)
    {
        llamadas[i].idAbonado = 0;
    }
}

/**
 * Obtiene el primer indice libre del array.
 * \param recibe el array como parametro
 * \param recibe el tamanio del array
 * \return el primer indice disponible
 */
int obtenerIndiceLibreAbonado(eAbonado* abonados,int lengthAbonados)
{
    int i;
    int indice;
    for(i=0;i<lengthAbonados;i++)
    {
        if(abonados[i].idAbonado == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

/** \brief solicita un string, valida su tamanio y lo carga en string.
 *
 * \param texto recibe lo que va a leer el usario
 * \param recibe el array donde guardar el string
 * \param recibe por parametro el limite del array
 * \return retorna 0 si el texto supera el limite o 1 si se cargo correctamente
 *
 */
void getString(char* string,char* texto,char* textoError,int lim)
{
    char auxStr[400];

    printf("\n%s",texto);
    fflush(stdin);
    gets(auxStr);

    while(!soloLetras(auxStr)|| strlen(auxStr) > lim)
    {
        printf("\n%s", textoError);
        fflush(stdin);
        gets(auxStr);
    }
    strcpy(string,auxStr);

}
/** \brief Recibe un puntero con un nombre, lo pasa a miniscula y la primer letra a mayuscula
 *
 * \param str recibe el puntero con el nombre
 * \param
 * \return
 *
 */

void formatoNombre(char* str)
{
    strlwr(str);
    str[0] = toupper(str[0]);
}

/** \brief recibe un texto y verifica que solo contenga letras
 *
 * \param str recibe el puntero con el texto
 * \param
 * \return
 *
 */
int soloLetras(char* str)
{
    int i,validacion = 1;

    for(i=0;str[i]!='\0';i++)
    {
        if((str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
        {
            validacion = 0;
            break;
        }
    }
    return validacion;
}
/** \brief Solicita un long int y valida que este dentro de los limites
 *
 * \param recibe el texto para solicitar al usuario
 * \param recibe el texto para mostrar al usuario en caso de error.
 * \param limInf recibe el limite inferior por parametro
 * \param limSup recibe el limite superior por parametro
 * \return retorna el numero luego de ser validado
 *
 */
long int obtenerTelefono(char* texto,char* textoError,int limInf,int limSup)
{
    long int numero;
    char auxNumero[256];

    printf("\n%s", texto);
    fflush(stdin);
    scanf("%s", auxNumero);

    while(validarNumero(auxNumero,limInf,limSup))
    {
        printf("\n%s", textoError);
        fflush(stdin);
        scanf("%s", auxNumero);
    }

    numero = atoi(auxNumero);
    return numero;
}
/** \brief Busca el ultimo id y genera el siguiendo, o si es el primer id lo genera a partir de un limite minimo
 *
 * \param recibe el array de abonado y su longitud
 * \param recibe el limite inferior a partir del cual se generan los id
 * \return retorna el id generado
 *
 */

int generarId(eAbonado* abonados,int lengthAbonados,int limInf)
{
    int max,i,id;
    int flag = 0;

    for(i=0;i<lengthAbonados;i++)
    {
        if(abonados[i].idAbonado != 0)
        {
            max = abonados[i].idAbonado;
            flag = 1;
        }
    }

    if(flag == 0)
    {
        id = limInf + 1;
    }
    if(flag == 1)
    {
        id = max + 1;
    }

    return id;
}

/** \brief Busca el primer array libre y solicita todos los datos para luego de verificarlos cargarlos
 *
 * \param recibe el array de abonados
 * \param recibe la longitud del array
 * \return -
 *
 */

void altaAbonado(eAbonado* abonados,int lengthAbonados)
{

    int index;
    /**< Obtiene el primer indice donde encuentra cargado como id del producto el valor 0 */
    index = obtenerIndiceLibreAbonado(abonados,lengthAbonados);

    abonados[index].idAbonado = generarId(abonados,lengthAbonados,1000);

    /**< Solicita el Nombre del abonado y valida su tamanio */
    getString(abonados[index].nombre,"Ingrese el nombre del abonado: ","Error. Reingrese: ",30);
    formatoNombre(abonados[index].nombre);

    /**< Solicita el Apellido del abonado y valida su tamanio */
    getString(abonados[index].apellido,"Ingrese el apellido del abonado: ","Error. Reingrese: ",30);
    formatoNombre(abonados[index].apellido);

    /**< Solicita el telefono del abonado y lo valida. */
    abonados[index].telefono = obtenerTelefono("Ingrese el telefono: ","El telefono es invalido, reingrese: ",10000000,99999999);

}

/**
 * Obtiene el indice que coincide con el id pasado por parametro.
 * @param abonados el array se pasa como parametro.
 * @param id el id a ser buscado en el array.
 * @return el indice en donde se encuentra el id que coincide
 */
int buscarAbonadoPorId(eAbonado* abonados,int lengthAbonados,int id)
{
    int i;
    int indice = -1;
    for(i=0;i<lengthAbonados;i++)
    {
        if(abonados[i].idAbonado == id)
        {
            indice = i;
        }
    }
    return indice;
}

/** \brief Muestra un menu, solicita opcion y la valida. Retorna la opcion.
 *
 * \param -
 * \param -
 * \return retorna la opcion elegida por el usuario ya validada.
 *
 */
int menuModificar(void)
{
    char auxOpcion[256];
    int opcion;

    printf("\n1- Nombre\n");
    printf("2- Apellido\n");
    printf("3- Telefono\n");

    fflush(stdin);
    scanf("%s", auxOpcion);
    while(validarNumero(auxOpcion,1,3))
    {
        printf("\nError.. Reingrese: ");
        fflush(stdin);
        scanf("%s", auxOpcion);
    }
    opcion = atoi(auxOpcion);

    return opcion;
}
/** \brief Solicita un entero y valida que este dentro de los limites
 *
 * \param recibe el texto para solicitar al usuario
 * \param recibe el texto para mostrar al usuario en caso de error.
 * \param limInf recibe el limite inferior por parametro
 * \param limSup recibe el limite superior por parametro
 * \return retorna el numero luego de ser validado
 *
 */
int obtenerNumero(char* texto, char* textoError, int limInf, int limSup)
{
    int numero;
    char auxNumero[256];

    printf("\n%s", texto);
    fflush(stdin);
    scanf("%s", auxNumero);
    while(validarNumero(auxNumero,limInf,limSup))
    {
        printf("\n%s", textoError);
        fflush(stdin);
        scanf("%s", auxNumero);
    }

    numero = atoi(auxNumero);

    return numero;
}

/** \brief Solicita el id del abonado que se quiere modificar y solicita lo que se desee modificar
 *
 * \param abonados recibe el array con la lista de todos los abonados
 * \param lengthAbonados recibe el tamanio del arrayAbonados
 * \return -
 *
 */

void modificarAbonado(eAbonado* abonados,int lengthAbonado)
{
    int id, index,opcion;


    mostrarAbonados(abonados,lengthAbonado);

    printf("\nIngrese el id del Abonado: ");
    fflush(stdin);
    scanf("%d", &id);

    index = buscarAbonadoPorId(abonados,lengthAbonado,id);
    if(index == -1)
    {
        printf("\nNo existe un abonado con ese id\n\n ");
        system("pause");
    }

    else
    {
        system("cls");
        mostrarAbonado(abonados,lengthAbonado,index);

        printf("\n\nQue desea modificar de este abonado? :\n");
        opcion = menuModificar();
        switch(opcion)
        {
        case 1:

            /**< Solicita el Nombre del abonado y valida su tamanio */
            getString(abonados[index].nombre,"Ingrese el nombre del abonado: ","Error. Reingrese: ",30);
            formatoNombre(abonados[index].nombre);
            break;

        case 2:

            /**< Solicita el Apellido del abonado y valida su tamanio */
            getString(abonados[index].apellido,"Ingrese el apellido del abonado: ","Error. Reingrese: ",30);
            formatoNombre(abonados[index].apellido);
            break;

        case 3:

            /**< Solicita el telefono del abonado y lo valida. */
            abonados[index].telefono = obtenerTelefono("Ingrese el telefono: ","El telefono es invalido, reingrese: ",00000000,99999999);
            break;

        }
        system("cls");
        printf("\n\t\tModificacion realizada con exito!\n\n\n");
        system("pause");
    }
}
/** \brief solicita el id de un abonado y luego lo borra o no, dependiendo que se seleccione
 *
 * \param recibe el array de abonados
 * \param recibe la longitud del array
 * \return -
 *
 */

void borrarAbonado(eAbonado* abonados,int lengthAbonados)
{
    int id, indice;
    char baja[256];

    mostrarAbonados(abonados,lengthAbonados);

    printf("\nIngrese el id del abonado: ");
    fflush(stdin);
    scanf("%d", &id);
    indice = buscarAbonadoPorId(abonados,lengthAbonados,id);
    if(indice == -1)
    {
        printf("\nNo existe un abonado con ese id\n\n ");
        system("pause");
    }

    else
    {
        system("cls");
        mostrarAbonado(abonados,lengthAbonados,indice);

        getString(baja,"\nEsta seguro que desea borrar este abonado?s/n: ","Ingrese 's' o 'n': ",1);
        baja[0] = tolower(baja[0]);

        if(baja[0] == 's' && soloLetras(baja) == 1)
        {

            abonados[indice].idAbonado = 0;
            printf("\n\nAbonado borrado\n\n");
        }
        else
        {
            printf("\n\nEl usuario no fue borrado\n\n");
        }
        system("pause");
    }
}
/** \brief Muestra los datos del abonado cargado en el indice que recibe
 *
 * \param recibe el array con todos los abonados
 * \param recibe el tamanio del array
 * \param recibe el indice del abonado del que se quieren ver los datos
 *
 */

void mostrarAbonado(eAbonado* abonados,int lengthAbonados,int indice)
{
    printf("|ID     |Apellido\t |Nombre          |Telefono\n");
    printf("-----------------------------------------------------\n");
    printf("|%d   |%-15s |%-15s |%-17ld\n",abonados[indice].idAbonado,abonados[indice].apellido, abonados[indice].nombre, abonados[indice].telefono);
}

/** \brief muestra una lista con los abonados y solicita el id, luego solicita el motivo apartir de un menu.
 *
 * \param recibe la lista de llamadas
 * \param
 * \return
 *
 */

void nuevaLlamada(eLlamada* llamadas,eAbonado* abonados,int lengthLlamadas,int lengthAbonados)
{
    int index,falla,auxIdAbonado,indiceAbonado;
    char auxFalla[256];
    /**< Obtiene el primer indice donde encuentra cargado como id del producto el valor 0 */
    index = obtenerIndiceLibreLlamada(llamadas,lengthLlamadas);

    mostrarAbonados(abonados,lengthAbonados);
    printf("\nIngrese el id del abonado: ");
    fflush(stdin);
    scanf("%d", &auxIdAbonado);
    indiceAbonado = buscarAbonadoPorId(abonados,lengthAbonados,auxIdAbonado);
    if(indiceAbonado == -1)
    {
        printf("\nNo existe un abonado con ese id\n\n ");
        system("pause");
    }
    else
    {
        printf("\n\nIngrese el motivo del llamado: ");

        printf("\n1-FALLA 3G");
        printf("\n2-FALLA LTE");
        printf("\n3-FALLA EQUIPO\n");
        scanf("%s", auxFalla);
        while(validarNumero(auxFalla,1,3))
        {
            printf("\nError. Ingrese opcion valida: ");
            fflush(stdin);
            scanf("%s", auxFalla);
        }
        falla = atoi(auxFalla);

        switch(falla)
        {
        case 1:
            strcpy(llamadas[index].motivo,"FALLA 3G");
            break;

        case 2:
            strcpy(llamadas[index].motivo,"FALLA LTE");
            break;

        case 3:
            strcpy(llamadas[index].motivo,"FALLA EQUIPO");
            break;
        }

        llamadas[index].idAbonado = auxIdAbonado;
        llamadas[index].tiempo = 0;
        abonados[indiceAbonado].contLlamas++;
        strcpy(llamadas[index].estado,"EN CURSO");

    }


}
/**
 * Obtiene el primer indice libre del array.
 * \param recibe el array como parametro
 * \param recibe el tamanio del array
 * \return el primer indice disponible
 */
int obtenerIndiceLibreLlamada(eLlamada* llamadas,int lengthLlamada)
{
    int i;
    int indice;
    for(i=0;i<lengthLlamada;i++)
    {
        if(llamadas[i].idAbonado == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}
 /** \brief Muestra los datos de los abonados cargados
  *
  * \param abonados recibe el array con los datos de los abonados
  * \param lenghtAbnados recibe el tamanio del array
  * \return -
  *
  */
void mostrarAbonados(eAbonado* abonados,int lengthAbonados)
{
    int i;

    printf("|ID     |Apellido\t |Nombre          |Telefono\n");
    printf("-----------------------------------------------------\n");
    for(i=0;i<lengthAbonados;i++)
    {
        if(abonados[i].idAbonado != 0)
        {

            printf("|%d   |%-15s |%-15s |%-17ld\n",abonados[i].idAbonado,abonados[i].apellido, abonados[i].nombre, abonados[i].telefono);
        }
    }
    printf("\n\n");
}
/** \brief recorre el array de llamadas buscando la llamada en curso, pide el tiempo insumido y el estado de esta
 *
 * \param recibe los array de llamadas y de abonados
 * \param recibe la longitud de estos array-
 * \return -
 *
 */
void finalizarLlamada(eLlamada* llamadas,eAbonado* abonados,int lengthLlamadas, int lengthAbonados)
{
    int indice = -1,i,estado;
    char auxEstado[256];

    for(i=0;i<lengthLlamadas;i++)
    {
        if(strcmp(llamadas[i].estado,"EN CURSO") == 0)
        {
            indice = i;
        }
    }
    if(indice == -1)
    {
        printf("\n\n\t\tNo hay llamadas en curso\n\n\n");
        system("pause");
    }
    else
    {

        mostrarLlamada(llamadas,abonados,lengthLlamadas,lengthAbonados,indice);
        llamadas[indice].tiempo = obtenerNumero("Ingrese el tiempo insumido: ","Error, ingrese valido: ",1,999);
        printf("%s %s %d",llamadas[0].estado,llamadas[0].motivo, llamadas[0].tiempo);
        printf("\n\nIngrese el estado del llamado: ");

            printf("\n1-EN CURSO");
            printf("\n2-SOLUCIONADO");
            printf("\n3-NO SOLUCIONADO\n");
            scanf("%s", auxEstado);
            while(validarNumero(auxEstado,1,3))
            {
                printf("\nError. Ingrese opcion valida: ");
                fflush(stdin);
                scanf("%s", auxEstado);
            }

            estado = atoi(auxEstado);
            printf("%s %s %d",llamadas[0].estado,llamadas[0].motivo, llamadas[0].tiempo);
            switch(estado)
            {
            case 1:
                strcpy(llamadas[indice].estado,"EN CURSO");
                break;

            case 2:
                strcpy(llamadas[indice].estado,"SOLUCIONADO");
                break;

            case 3:
                strcpy(llamadas[indice].estado,"NO SOLUCIONADO");
                break;
            }

            system("cls");
            printf("%s %s %d",llamadas[0].estado,llamadas[0].motivo, llamadas[0].tiempo);
            printf("\n\n\n\t\tLlamada finalizada con exito!\n\n\n");
            system("pause");
    }

}

/** \brief Muestra los datos del abonado cargado en el indice que recibe
 *
 * \param recibe el array con todos los abonados
 * \param recibe el tamanio del array
 * \param recibe el indice del abonado del que se quieren ver los datos
 *
 */

void mostrarLlamada(eLlamada* llamadas,eAbonado* abonados,int lengthLlamadas,int lengthAbonados,int indiceLlamada)
{
    int indiceAbonado;

    indiceAbonado = buscarAbonadoPorId(abonados,lengthAbonados,llamadas[indiceLlamada].idAbonado);

    printf("|ID     |Apellido\t |Nombre          |Telefono     |Motivo     |Estado    |Tiempo\n");
    printf("---------------------------------------------------------------------------------------\n");
    printf("|%d   |%-15s |%-15s |%-13ld",abonados[indiceAbonado].idAbonado,abonados[indiceAbonado].apellido, abonados[indiceAbonado].nombre, abonados[indiceAbonado].telefono);
    printf("|%-8s  |%-8s  |%5d \n", llamadas[indiceLlamada].motivo,llamadas[indiceLlamada].estado,llamadas[indiceLlamada].tiempo);
}

/** \brief Muestra un menu, solicita opcion y la valida. Retorna la opcion.
 *
 * \param recibe los arrays de llamadas y de abonados
 * \param redibe la longitud de estos arrays
 * \return -
 *
 */
void informes(eAbonado* abonados,eLlamada* llamadas,int lengthAbonados, int lengthLlamadas)
{
    int opcion;
    char auxOpcion[256];

        system("cls");
        printf("      MENU INFORMES\n");
        printf("\n1- ABONADO CON MAS RECLAMOS");
        printf("\n2- RECLAMO MAS REALIZADO");
        printf("\n3- RECLAMO CON MAS DEMORA\n");
        scanf("%s", auxOpcion);
        while(validarNumero(auxOpcion,1,3))
        {
            printf("\nError. Ingrese opcion valida: ");
            fflush(stdin);
            scanf("%s", auxOpcion);
        }
        opcion = atoi(auxOpcion);

        switch(opcion)
        {
        case 1:

            abonadoMasReclamos(llamadas,abonados,lengthLlamadas,lengthAbonados);
            break;

        case 2:
            reclamoMasRealizado(llamadas,lengthLlamadas);
            break;

        case 3:
            reclamoConMasDemora(llamadas,lengthLlamadas);
            break;
        }
}
/** \brief genera y muestra un informe del abonado que realizo mas reclamos
 *
 * \param recibe el array de llamadas y de abonados
 * \param lengthLlamadas y lengthAbonados recibe el tamaño de los array
 * \return -
 *
 */

void abonadoMasReclamos(eLlamada* llamadas,eAbonado* abonados, int lengthLlamadas, int lengthAbonados)
{
    int i,max,indiceAbonado;
    int flag = 0;

    for(i=0;i<lengthAbonados;i++)
    {
        if(max < abonados[i].contLlamas || flag == 0)
        {
            max = abonados[i].contLlamas;
            indiceAbonado = i;
            flag = 1;
        }
    }
    system("cls");
    if(max == 0)
    {
        printf("\n\n\tNo se realizo ninguna llamada\n\n\n");
    }
    else
    {
        printf("El abonado con mas reclamos hizo %d llamada/s y es: \n\n\n",abonados[indiceAbonado].contLlamas);
        mostrarAbonado(abonados,lengthAbonados,indiceAbonado);
        printf("\n\n\n");
    }
    system("pause");

}


void reclamoMasRealizado(eLlamada* llamadas, int lengthLlamadas)
{
    int i,falla3G,fallaEquipo,fallaLTE;
    int flag = 0;

    for(i=0;i<lengthLlamadas;i++)
    {
        if(flag == 0)
        {
            falla3G = 0;
            fallaLTE = 0;
            fallaEquipo =0;
            flag = 1;
        }

        if(stricmp(llamadas[i].motivo,"FALLA 3G") == 0)
        {
            falla3G++;
        }
        if(stricmp(llamadas[i].motivo,"FALLA LTE") == 0)
        {
            fallaLTE++;
        }
        if(stricmp(llamadas[i].motivo,"FALLA EQUIPO") == 0)
        {
            fallaEquipo++;
        }
    }

    if(falla3G >= fallaLTE && falla3G >= fallaEquipo)
    {
        printf("La mayor cantidad de reclamos son %d por FALLA 3G\n",falla3G);
    }
    if(fallaLTE >= falla3G && fallaLTE >= fallaEquipo)
    {
        printf("La mayor cantidad de reclamos son %d por FALLA LTE\n",fallaLTE);
    }
    if(fallaEquipo >= falla3G && fallaEquipo >= fallaLTE)
    {
        printf("La mayor cantidad de reclamos son %d por FALLA EQUIPO\n",fallaEquipo);
    }

    printf("\n\n\n");
    system("pause");
}

/** \brief Recorre las llamadas, saca promedio del tiempo de cada falla y muestra el mayor
 *
 * \param llamadas recibe el array de llamadas
 * \param lengthLlamadas recibe la longitud del array
 * \return -
 *
 */
void reclamoConMasDemora(eLlamada* llamadas,int lengthLlamadas)
{
    int i,falla3G,fallaEquipo,fallaLTE;
    int cont3G,contEquipo,contLTE;
    int flag = 0;

    for(i=0;i<lengthLlamadas;i++)
    {
        if(flag == 0)
        {
            falla3G = 0;
            fallaLTE = 0;
            fallaEquipo = 0;
            cont3G = 0;
            contLTE = 0;
            contEquipo = 0;
            flag = 1;
        }
        if(stricmp(llamadas[i].motivo,"FALLA 3G") == 0)
        {
            falla3G = falla3G + llamadas[i].tiempo;
            cont3G++;
        }
        if(stricmp(llamadas[i].motivo,"FALLA LTE") == 0)
        {
            fallaLTE = fallaLTE + llamadas[i].tiempo;
            contLTE++;
        }
        if(stricmp(llamadas[i].motivo,"FALLA EQUIPO") == 0)
        {
            fallaEquipo = fallaEquipo + llamadas[i].tiempo;
            contEquipo++;
        }
    }
    printf("%s %s %d",llamadas[0].estado,llamadas[0].motivo, llamadas[0].tiempo);
    if(cont3G != 0)
    {
        falla3G = falla3G / cont3G;
    }
    if(contLTE != 0)
    {
        fallaLTE = fallaLTE / contLTE;
    }
    if(contEquipo != 0)
    {
        fallaEquipo = fallaEquipo / contEquipo;
    }
    if((cont3G == 0 && contLTE == 0) && contEquipo == 0)
    {
        printf("\n\n\tNo se realizaron llamados.");
    }

    else
    {
        if(falla3G >= fallaLTE && falla3G >= fallaEquipo)
        {
            printf("El promedio mas alto en demora lo tiene FALLA 3G con %dmin.\n",falla3G);
        }
        if(fallaLTE >= falla3G && fallaLTE >= fallaEquipo)
        {
            printf("El promedio mas alto en demora lo tiene FALLA LTE con %dmin.\n",fallaLTE);
        }
        if(fallaEquipo >= falla3G && fallaEquipo >= fallaLTE)
        {
            printf("El promedio mas alto en demora lo tiene FALLA EQUIPO con %dmin.\n",fallaEquipo);
        }
    }
    printf("\n\n\n");
    system("pause");
}
