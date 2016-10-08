typedef struct
{
    int idAbonado;
    long int telefono;
    char nombre[30];
    char apellido[30];
}eAbonado;

typedef struct
{
    int idAbonado;
    int tiempo;
    char estado[10];
    char motivo[10];
}eLlamada;


int menu(void);
int validarNumero(int,int,int);
int obtenerNumero(char[],char[],int,int);
void inicializarArrayAbonados(eAbonado[],int);
void inicializarArrayLlamadas(eLlamada[],int);
int obtenerIndiceLibreAbonado(eAbonado[],int);
int obtenerIndiceLibreLlamada(eLlamada[],int);
void getString(char[],char[],char[],int);
long int obtenerTelefono(char[],char[],int,int);
int generarId(eAbonado[],int,int);
void altaAbonado(eAbonado[],int);
int buscarAbonadoPorId(eAbonado[],int,int);
int menuModificar(void);
void modificarAbonado(eAbonado[],int);
void borrarAbonado(eAbonado[],int);
void mostrarAbonado(eAbonado[],int,int);
void mostrarAbonados(eAbonado[],int);

void nuevaLlamada(eLlamada[],eAbonado[],int,int);
void finalizarLlamada(eLlamada[],eAbonado[],int,int);
void mostrarLlamada(eLlamada[],eAbonado[],int,int,int);

void informes(eAbonado[],eLlamada[],int,int);
