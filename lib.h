typedef struct
{
    int idAbonado;
    long int telefono;
    char nombre[30];
    char apellido[30];
    int contLlamas;
}eAbonado;

typedef struct
{
    int idAbonado;
    int tiempo;
    char estado[16];
    char motivo[16];
}eLlamada;



int validarNumero(char*,int,int);
//char validarEntero(char*);
int obtenerNumero(char*,char*,int,int);
void getString(char*,char*,char*,int);
void formatoNombre(char*);
int soloLetras(char*);
int menu(void);
int menuModificar(void);
long int obtenerTelefono(char*,char*,int,int);

void inicializarArrayAbonados(eAbonado*,int);
int obtenerIndiceLibreAbonado(eAbonado*,int);
int generarId(eAbonado*,int,int);
void altaAbonado(eAbonado*,int);
int buscarAbonadoPorId(eAbonado*,int,int);
void modificarAbonado(eAbonado*,int);
void borrarAbonado(eAbonado*,int);
void mostrarAbonado(eAbonado*,int,int);
void mostrarAbonados(eAbonado*,int);


void inicializarArrayLlamadas(eLlamada*,int);
int obtenerIndiceLibreLlamada(eLlamada*,int);
void nuevaLlamada(eLlamada*,eAbonado*,int,int);
void finalizarLlamada(eLlamada*,eAbonado*,int,int);
void mostrarLlamada(eLlamada*,eAbonado*,int,int,int);
void llamadasEnCurso(eLlamada*,eAbonado*,int,int);

void informes(eAbonado*,eLlamada*,int,int);
void abonadoMasReclamos(eLlamada*,eAbonado*,int,int);
void reclamoMasRealizado(eLlamada*,int);
void reclamoConMasDemora(eLlamada*,int);
