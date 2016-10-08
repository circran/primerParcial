#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "lib.h"
//{"En curso","Solucionado","No Solucionado","FALLA 3G","FALLATA LTE","FALLA EQUIPO"};
#define enCurso 0
#define solucionado 1
#define noSolucionado 2
#define falla3g 3
#define fallaLTE 4
#define fallaEquipo 5
/** \brief Muestra un menu, solicita opcion y la valida. Retorna la opcion.
 *
 * \param -
 * \param -
 * \return retorna la opcion elegida por el usuario ya validada.
 *
 */
int menu(void)
{
    int opcion;
    system("cls");
    printf("1- ALTA ABONADO\n");
    printf("2- MODIFICAR ABONADO\n");
    printf("3- BAJA DE ABONADO\n");
    printf("4- NUEVA LLAMADA\n");
    printf("5- FIN DE LLAMADA\n");
    printf("6- INFORMES\n");
    printf("7- Salir\n");

    scanf("%d",&opcion);
    while(!validarNumero(opcion,1,7))
    {
        printf("\nError.. Reingrese: ");
        scanf("%d",&opcion);
    }

    return opcion;
}

/** \brief valida que el numero que recibe este entre los limites.
 *
 * \param recibe el numero a validar.
 * \param recibe el limite inferior
 * \param recibe el limite superior
 * \return retorna 0 si el numero no esta dentro de los limites o 1 si lo esta.
 */
int validarNumero(int numero,int limInf, int limSup)
{
    int validacion = 0;

    if(numero >= limInf && numero <= limSup)
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
void inicializarArrayAbonados(eAbonado abonados[],int lengthAbonado)
{
    int i;
    for(i=0;i<lengthAbonado;i++)
    {
        abonados[i].idAbonado = 0;
    }
}

/** \brief carga el valor 0 en el id de cada indice.
 *
 * \param abonado recibe el array.
 * \param recibe el tamanio del array.
 * \return -
 *
 */
void inicializarArrayLlamadas(eLlamada llamadas[],int lengthLlamadas)
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
int obtenerIndiceLibreAbonado(eAbonado abonados[],int lengthAbonados)
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
void getString(char string[],char texto[],char textoError[],int lim)
{
    char aux[400];
    printf("\n%s",texto);
    fflush(stdin);
    gets(aux);
    while(strlen(aux) > lim)
    {
        printf("\n%s", textoError);
        fflush(stdin);
        gets(aux);
    }
    strcpy(string,aux);

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
long int obtenerTelefono(char texto[],char textoError[],int limInf,int limSup)
{
    long int numero;

    printf("\n%s", texto);
    scanf("%ld", &numero);
    while(!validarNumero(numero,limInf,limSup))
    {
        printf("\n%s", textoError);
        fflush(stdin);
        scanf("%ld", &numero);
    }
    return numero;
}

int generarId(eAbonado abonados[],int lengthAbonados,int limInf)
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


void altaAbonado(eAbonado abonados[],int lengthAbonados)
{

    int index;
    /**< Obtiene el primer indice donde encuentra cargado como id del producto el valor 0 */
    index = obtenerIndiceLibreAbonado(abonados,lengthAbonados);

    abonados[index].idAbonado = generarId(abonados,lengthAbonados,1000);

    /**< Solicita el Nombre del abonado y valida su tamanio */
    getString(abonados[index].nombre,"Ingrese el nombre del abonado: ","Error. Reingrese: ",30);

    /**< Solicita el Apellido del abonado y valida su tamanio */
    getString(abonados[index].apellido,"Ingrese el apellido del abonado: ","Error. Reingrese: ",30);

    /**< Solicita el telefono del abonado y lo valida. */
    abonados[index].telefono = obtenerTelefono("Ingrese el telefono: ","El telefono es invalido, reingrese: ",00000000,99999999);

}

/**
 * Obtiene el indice que coincide con el id pasado por parametro.
 * @param abonados el array se pasa como parametro.
 * @param id el id a ser buscado en el array.
 * @return el indice en donde se encuentra el id que coincide
 */
int buscarAbonadoPorId(eAbonado abonados[],int lengthAbonados,int id)
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
    int opcion;
    printf("\n1- Nombre\n");
    printf("2- Apellido\n");
    printf("3- Telefono\n");

    fflush(stdin);
    scanf("%d",&opcion);
    while(!validarNumero(opcion,1,3))
    {
        printf("\nError.. Reingrese: ");
        fflush(stdin);
        scanf("%d",&opcion);
    }

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
int obtenerNumero(char texto[], char textoError[], int limInf, int limSup)
{
    int numero;

    printf("\n%s", texto);
    fflush(stdin);
    scanf("%d", &numero);
    while(!validarNumero(numero,limInf,limSup))
    {
        printf("\n%s", textoError);
        fflush(stdin);
        scanf("%d", &numero);
    }
    return numero;
}

/** \brief Solicita el id del abonado que se quiere modificar y solicita lo que se desee modificar
 *
 * \param abonados recibe el array con la lista de todos los abonados
 * \param lengthAbonados recibe el tamanio del arrayAbonados
 * \return -
 *
 */

void modificarAbonado(eAbonado abonados[],int lengthAbonado)
{
    int id, index,opcion;


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
        mostrarAbonado(abonados,lengthAbonado,index);

        printf("\nQue desea modificar de este abonado? :\n");
        opcion = menuModificar();
        switch(opcion)
        {
        case 1:

            /**< Solicita el Nombre del abonado y valida su tamanio */
            getString(abonados[index].nombre,"Ingrese el nombre del abonado: ","Error. Reingrese: ",30);;
            break;

        case 2:

            /**< Solicita el Apellido del abonado y valida su tamanio */
            getString(abonados[index].apellido,"Ingrese el apellido del abonado: ","Error. Reingrese: ",30);
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

void borrarAbonado(eAbonado abonados[],int lengthAbonados)
{
    int id, indice;
    char baja;

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
        mostrarAbonado(abonados,lengthAbonados,indice);

        printf("\nEsta seguro que desea borrar a este abonado?s/n :");
        fflush(stdin);
        baja = tolower(getchar());
        if(baja == 's')
        {

            abonados[indice].idAbonado = 0;
            printf("\n\nAbonado borrado\n\n");
        }
        else
        {
            printf("\n\nAccion cancelada por el usuario\n\n");
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

void mostrarAbonado(eAbonado abonados[],int lengthAbonados,int indice)
{
    printf("Nombre y Apellido\tTelefono\n\n");
    printf("%s %s %25ld\n",abonados[indice].nombre, abonados[indice].apellido, abonados[indice].telefono);
}

/** \brief muestra una lista con los abonados y solicita el id, luego solicita el motivo apartir de un menu.
 *
 * \param recibe la lista de llamadas
 * \param
 * \return
 *
 */

void nuevaLlamada(eLlamada llamadas[],eAbonado abonados[],int lengthLlamadas,int lengthAbonados)
{
    int index,auxFalla,id;
    /**< Obtiene el primer indice donde encuentra cargado como id del producto el valor 0 */
    index = obtenerIndiceLibreLlamada(llamadas,lengthLlamadas);

    mostrarAbonados(abonados,lengthAbonados);

    printf("\n\nIngrese el id del abonado: ");
    fflush(stdin);
    scanf("%d", &id);

    if(buscarAbonadoPorId(abonados,lengthAbonados,id) == -1)
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
        scanf("%d", &auxFalla);
        while(!validarNumero(auxFalla,1,3))
        {
            printf("\nError. Ingrese opcion valida: ");
            fflush(stdin);
            scanf("%d", &auxFalla);
        }
        switch(auxFalla)
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

        llamadas[index].idAbonado = id;
        llamadas[index].tiempo = 0;
        strcpy(llamadas[index].estado,"EN CURSO");

    }


}
/**
 * Obtiene el primer indice libre del array.
 * \param recibe el array como parametro
 * \param recibe el tamanio del array
 * \return el primer indice disponible
 */
int obtenerIndiceLibreLlamada(eLlamada llamadas[],int lengthLlamada)
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
void mostrarAbonados(eAbonado abonados[],int lengthAbonados)
{
    int i;

    printf("ID   Nombre y Apellido\t          Telefono\n\n");
    for(i=0;i<lengthAbonados;i++)
    {
        if(abonados[i].idAbonado != 0)
        {
            printf("%d   %-5s %-5s %25ld\n",abonados[i].idAbonado,abonados[i].nombre, abonados[i].apellido, abonados[i].telefono);
        }
    }
    printf("\n\n");
}

void finalizarLlamada(eLlamada llamadas[],eAbonado abonados[],int lengthLlamadas, int lengthAbonados)
{
    int indice,i,auxEstado;
    for(i=0;i<lengthLlamadas;i++)
    {
        if(strcmp(llamadas[i].estado,"EN CURSO") == 0)
        {
            indice = i;
        }
    }

    mostrarLlamada(llamadas,abonados,lengthLlamadas,lengthAbonados,indice);
    llamadas[indice].tiempo = obtenerNumero("Ingrese el tiempo insumido: ","Error, ingrese valido: ",1,999);

    printf("\n\nIngrese el motivo del llamado: ");

        printf("\n1-EN CURSO");
        printf("\n2-SOLUCIONADO");
        printf("\n3-NO SOLUCIONADO\n");
        scanf("%d", &auxEstado);
        while(!validarNumero(auxEstado,1,3))
        {
            printf("\nError. Ingrese opcion valida: ");
            fflush(stdin);
            scanf("%d", &auxEstado);
        }
        switch(auxEstado)
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
        printf("\n\n\n\t\tLlamada finalizada con exito!\n\n\n");
        system("pause");

}

/** \brief Muestra los datos del abonado cargado en el indice que recibe
 *
 * \param recibe el array con todos los abonados
 * \param recibe el tamanio del array
 * \param recibe el indice del abonado del que se quieren ver los datos
 *
 */

void mostrarLlamada(eLlamada llamadas[],eAbonado abonados[],int lengthLlamadas,int lengthAbonados,int iLlamada)
{
    int iAbonado;

    iAbonado = buscarAbonadoPorId(abonados,lengthAbonados,llamadas[iLlamada].idAbonado);

    printf("ID    Nombre/Apellido   Telefono    Motivo    Estado  Tiempo\n\n");
    printf("%d |%s %s  |%5ld    ", abonados[iAbonado].idAbonado, abonados[iAbonado].nombre,abonados[iAbonado].apellido,abonados[iAbonado].telefono);
    printf("|%-8s  |%-8s  |%5d \n", llamadas[iLlamada].motivo,llamadas[iLlamada].estado,llamadas[iLlamada].tiempo);
}

/** \brief Muestra un menu, solicita opcion y la valida. Retorna la opcion.
 *
 * \param -
 * \param -
 * \return retorna la opcion elegida por el usuario ya validada.
 *
 */
void informes(eAbonado abonados[],eLlamada llamadas[],int lengthAbonados, int lengthLlamadas)
{
    int opcion;


        printf("\n1- Abonado con mas reclamos");
        printf("\n2-Reclamos mas realizado");
        printf("\n3-Reclamo con mas demora\n");
        scanf("%d", &opcion);
        while(!validarNumero(opcion,1,3))
        {
            printf("\nError. Ingrese opcion valida: ");
            fflush(stdin);
            scanf("%d", &opcion);
        }
        switch(opcion)
        {
        case 1:


            break;

        case 2:

            break;

        case 3:

            break;
        }
}

/*void abonadoMasReclamos(eLlamada llamadas[],int lengthLlamadas)
{
    int i,max;
    int flag = 0;

    for(i=0;i<lengthLlamadas;i++)
    {
        if(llamadas[i].idAbonado != 0 &&)
    }

}*/
