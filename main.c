#include <stdio.h>
#include <stdlib.h>
// Escribe un programa en C para gestionar una lista de contactos
//Utilizamos struct para que nos permita hacer la estructura de datos, este mismo nos permite agrupar variables relacionadas con el mismo nombre
struct Contacto {
    //tenemos la primera que seria la variable de tipo char y la llamaremos nombre tiene una limitacion de 51 caracteres
    char nombre[50];
    //Igualmente hacemos el mismo procedimiento con lo que seria la segunda variable que es de igual tipo char llamada telefono y tiene una limitacion de 21 caracteres
    char telefono[20];
    //Y por ultimo tenemos la tercera variable que es de igualmente tipo char y lleva por nombre correo tiene una limitacion de 51 caracteres
    char correo[50];
};

// Creamos una funcion para que podamos agregar un numero de telefono
//Utilizamos void ya que se utiliza para apuntar a cualquier tipo de datos podemos trabajar con el ya que no necesitamos que nos regrese un valor en especifico
void agregar_Contacto(struct Contacto lista[], int *numContactos) {
    if (*numContactos < 5) { // Limitamos la lista a 5 contactos
//Pedimos lo que seria el nombre del contacto
        printf("Escribe su nombre: ");
        //escaneamos y esto gracias al puntero se va a pasar a la lista
        scanf("%50s", lista[*numContactos].nombre);
        //pedimos el numero y se va a hacer el mismo procedimiento
        printf("Escribe el numero de telefono: ");
        scanf("%20s", lista[*numContactos].telefono);
        //Pedimos el correo y se realiza el mismo procedimiento
        printf("Dame el correo electronico: ");
        scanf("%50s", lista[*numContactos].correo);
        //Aqui decimos que la lista va a ir incrementando
        (*numContactos)++;
        printf("Contacto agregado correctamente.\n");
    } else {
        //Ya que limitamos la lista a 5 contactos cuando esta repase los antes mencionados se va a mandar el siguiente mensaje
        printf("La lista de contactos esta llena.\n");
    }
}

// Función para mostrar todos los contactos
void mostrarContactos(struct Contacto lista[], int numContactos) {
    printf("Lista de contactos:\n");
    //Utilizamos for para repetir el conjunto de instrucciones un numero especifico de veces, como podemos comienza en i es igual a 0 y i va a incrementar cada ves que sea menor a numcontactos
    for (int i = 0; i < numContactos; i++) {
            //i siempre va a incrementar de uno en uno
        printf("Contacto %d:\n", i + 1);
    //Aqui lo que podemos ver que la informacion de nombre se va a sacar de i
        printf("Nombre: %s\n", lista[i].nombre);
        //igualmente en telefono
        printf("Telefono: %s\n", lista[i].telefono);
        //y en correo
        printf("Correo: %s\n", lista[i].correo);
        printf("\n");
    }
}

int main() {
    //Le damos la limitacion a la lista de contactos que seria de 5 contactos
    struct Contacto listaContactos[5];
    //va a comenzar con un numero de contactos igual a 0
    int numContactos = 0;


    //Creamos lo que seria una funcion para las opciones
    int opcion;
    //utilizamos do para crear una ciclo que nos permite elegir las opciones ya que si se cumple las condiciones se ejecutaran si no aparecera que lo intentes de nuevo
    do {
        printf("Menu:\n");
        printf("1 Agregar contacto\n");
        printf("2 Mostrar contactos\n");
        printf("3 Salir\n");
        printf("Elige una opcion: ");
        scanf("%d", &opcion);

//Los switch son para que agregar las funciones que van a tener cada opcion
        switch (opcion) {
            case 1:
                agregar_Contacto(listaContactos, &numContactos);
                break;
            case 2:
                mostrarContactos(listaContactos, numContactos);
                break;
            case 3:
                printf("Chao cabron\n");
                break;
            default:
                printf("Intentalo de nuevo.\n");
        }
        //Si se pasa de las 3 opciones va a aparecer que intentes de nuevo ya quela estamos limitando
    } while (opcion != 3);

    return 0;
}

